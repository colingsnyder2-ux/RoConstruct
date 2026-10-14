"""Evidence-ranked agent batches: compiler reuse first, model repair last."""
import json
import os
import random
import threading
import time
import uuid
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
from pathlib import Path

from roc import agent, agent_memory, matchers, draft, match, research, telemetry, worker, clients, setup

ROOT = Path(__file__).resolve().parent.parent
WRITE_LOCK = threading.Lock()
CLAIM_LOCK = threading.Lock()
AREAS = {
    "family": ("Family reuse", "Compile verified same-shape donors; propagate only literal-safe variants."),
    "templates": ("Authentic templates / library sources", "Replay real vendor sources and observed types; settle imports/prelude first."),
    "imports": ("Imported calls", "Compare target IAT calls with source declarations; propagate proven import fixes."),
    "layout": ("ABI / allocation / constants", "Derive sizes and argument carriers from target bytes; reuse proven fixes."),
    "repair": ("Other near-misses", "Inspect fresh diffs; try one reusable hypothesis, park register-only dead ends."),
}


digest = research.digest


append = research.append


def history():
    return [agent_memory.campaign_context(row) for row in
            research.journal_records(ROOT / "work" / "agent-memory" / "attempts.jsonl")]


def snapshot(client="2008-06", api=None):
    with agent_memory.planning_lock():
        return _snapshot(client, api)


def _snapshot(client="2008-06", api=None):
    if client not in match.clients.load():
        raise ValueError("Unknown client: " + client)
    path = ROOT / "work" / client
    with (path / "functions.jsonl").open(encoding="utf-8") as stream:
        functions = []
        for line in stream:
            if not line.strip():
                continue
            row = json.loads(line)
            # Planning uses bounded evidence; full metadata stays in functions.jsonl.
            for key in ("relocs", "data_refs", "external_calls", "siblings", "calls", "branches"):
                row.pop(key, None)
            for key, value in row.items():
                if isinstance(value, list):
                    row[key] = value[:4 if key in ("callers", "call_targets") else 8]
            functions.append(row)
    if api:
        saved, donor_counts = {}, Counter()
        shapes = {row["addr"]: row.get("shape") for row in functions}
        after = ""
        while True:
            rows = api.call("/v1/source-page?client=%s&after=%s&limit=1000" % (client, after), timeout=120)
            if not rows:
                break
            for row in rows:
                shape = shapes.get(row["addr"])
                # Three real donors per shape suffice; exact bodies dominate the corpus.
                if row["score"] == 100 and (not shape or donor_counts[shape] >= 3):
                    saved[row["addr"]] = {"score": 100, "source_directives": match.directives(row["source"])}
                else:
                    saved[row["addr"]] = row
                    if row["score"] == 100:
                        donor_counts[shape] += 1
            cursor = rows[-1]["addr"]
            if cursor <= after:
                raise ValueError("Source page did not advance; update group server")
            after = cursor

    else:
        scores = json.loads((path / "scores.json").read_text()) if (path / "scores.json").exists() else {}
        saved = {}
        for row in functions:
            addr = row["addr"]
            source = ROOT / "src" / client / (addr + ".cpp")
            if source.exists():
                saved[addr] = {"score": scores[addr], "source": source.read_text(encoding="utf-8", errors="replace")}
    return [dict(row, **{key: saved.get(row["addr"], {}).get(key, default)
                        for key, default in (("score", 0), ("source", ""), ("source_directives", {}))}) for row in functions]


def plan(rows, max_size=512, profile="claude:default", records=None, client="2008-06", min_score=70):
    """Heuristic priority, not a forecast of exacts or a fresh compiler score."""
    groups = defaultdict(list)
    from roc import libs
    versions = libs.recipe_versions()
    functions = {row["addr"]: row for row in rows}
    for row in rows:
        if row.get("shape"):
            groups[row["shape"]].append(row)
    targets, excluded = [], defaultdict(int)
    for row in rows:
        source = row.get("source") or ""
        if row.get("kind", "code") != "code" or row.get("score", 0) == 100:
            continue
        if row.get("size", 0) < 6 or (max_size and row["size"] > max_size):
            excluded["outside size limit"] += 1
            continue
        siblings = groups.get(row.get("shape"), [])
        donors = [item for item in siblings if item.get("score") == 100 and item.get("source")]
        if not source or not (draft.clean_repair_context(source).strip() or
                              any(key in match.directives(source) for key in ("lib", "archive"))):
            if donors:
                source = donors[0]["source"]  # A real donor seed, always checked against this target.
            else:
                excluded["no usable source; individual mining deferred"] += 1
                continue
        if row.get("score", 0) < min_score and not donors:
            excluded["low similarity; needs stronger source evidence"] += 1
            continue
        directives = match.directives(source)
        if donors:
            area, priority = "family", 100
        elif "lib" in directives or "archive" in directives:
            area, priority = "templates", 85
        elif row.get("imports"):
            area, priority = "imports", 80
        elif row.get("stack_args") or row.get("this_reads") or row.get("constants"):
            area, priority = "layout", 65
        else:
            area, priority = "repair", 40
        priority += min(10, len(siblings)) + (row["score"] - 70) / 3 - row["size"] / 128
        if 95 <= row["score"] < 100:
            priority += 20
        key = (directives.get("lib") or directives.get("archive") or row.get("unit", "")) if area == "templates" else (
            "|".join(sorted(row["imports"])) if area == "imports" else row.get("shape") or row.get("unit", ""))
        recipe = (directives.get("lib") or directives.get("archive") or "").split()
        behavior_evidence = agent.function_evidence(row, functions)
        evidence_hash = digest(source + (versions.get(recipe[0], "") if recipe else "") +
                               json.dumps(behavior_evidence, sort_keys=True))
        targets.append(dict(row, source=source, area=area, priority=round(priority, 2), donors=donors[:3], evidence_hash=evidence_hash,
                            behavior_evidence=behavior_evidence,
                            source_hash=digest(source), siblings=len(siblings), client=client, group=digest(client + ":" + area + ":" + key)[:16]))
    areas = []
    records = history() if records is None else records
    seen, unique = set(), []
    for record in records:
        if record.get("client", "2008-06") != client:
            continue
        key = (record.get("date"), record.get("phase"), record.get("group"), record.get("area"), record.get("profile"))
        if record.get("kind") == "auto_batch" and record.get("date"):
            if key in seen:
                continue
            seen.add(key)
        unique.append(record)
    records = unique
    for area, (title, advice) in AREAS.items():
        members = sorted((row for row in targets if row["area"] == area), key=lambda r: (-r["priority"], r["addr"]))
        if not members:
            continue
        cohort = digest("\n".join(sorted(row["addr"] + str(row["size"]) + row["evidence_hash"] for row in members)))
        feedback = [r for r in records if r.get("kind") == "auto_batch" and r.get("area") == area and
                    r.get("profile") == profile and r.get("outcome") in ("improved", "no_gain")]
        for group in {row["group"] for row in members}:
            family = [row for row in members if row["group"] == group]
            revision = digest("\n".join(sorted(row["addr"] + str(row["size"]) + row["evidence_hash"] for row in family)))
            previous = [r for r in feedback if r.get("group") == group and r.get("group_cohort") == revision
                        and r.get("phase") == "repair"]
            exhausted = [r for r in records if r.get("kind") == "auto_batch" and r.get("group") == group
                         and r.get("group_cohort") == revision and r.get("exhausted")]
            parked = bool(exhausted) or (len(previous) >= 2 and all(r.get("outcome") == "no_gain" for r in previous[-2:]))
            for row in family:
                target_parked = any(r.get("kind") == "auto_target" and r.get("phase") == "repair" and
                    r.get("repair_attempted") and r.get("outcome") == "no_gain" and
                    row["addr"] in (r.get("addresses") or []) and r.get("evidence_hash") == row["evidence_hash"]
                    for r in records)
                row.update(group_cohort=revision, group_parked=parked or target_parked)
        members.sort(key=lambda row: (row["group_parked"], -row["priority"], row["addr"]))
        parked = all(row["group_parked"] for row in members)
        gains = sum(r.get("gains", 0) for r in feedback[-20:])
        # Expected gain per target from server-verified batches of every profile and PC
        # (reuse gains do not depend on the model); Laplace-smoothed so new areas still run.
        measured = [r for r in records if r.get("kind") == "auto_batch" and r.get("area") == area
                    and r.get("outcome") in ("improved", "no_gain")]
        rate = (sum(r.get("gains", 0) for r in measured) + 1) / (sum(len(r.get("addresses") or ()) for r in measured) + 2)
        timed = [r for r in measured if r.get("elapsed_seconds", 0) > 0 and "exacts_gained" in r][-20:]
        exact_rate = 60 * sum(r["exacts_gained"] for r in timed) / max(60, sum(r["elapsed_seconds"] for r in timed))
        areas.append({"id": area, "client": client, "title": title, "advice": advice, "eligible": len(members),
                      "bytes": sum(row["size"] for row in members),
                      "priority": round(members[0]["priority"] + min(20, gains * 2) + 40 * rate, 2),
                      "expected_gain_rate": round(rate, 3),
                      "verified_exacts_per_minute": round(exact_rate, 3),
                      "recent_verified_gains": gains, "measured_batches": len(feedback[-20:]),
                      "cohort": cohort, "parked": parked, "targets": members})
    return {"client": client, "profile": profile, "areas": sorted(areas, key=lambda r: (-r["verified_exacts_per_minute"], -r["priority"])),
            "excluded": dict(excluded), "note": "Heuristic ranking. Scores are snapshot hints; baselines recompile before work."}


def portfolio(names, max_size=512, profile="claude:default", records=None, api=None, min_score=70):
    """Rank each client independently, then share one target and time budget."""
    results = [plan(snapshot(client=name, api=api), max_size, profile, records, client=name, min_score=min_score) for name in names]
    excluded = Counter()
    for result in results:
        excluded.update(result["excluded"])
    return {"client": names[0] if len(names) == 1 else "all", "clients": list(names), "profile": profile,
            "areas": sorted((area for result in results for area in result["areas"]),
                            key=lambda area: (-area["verified_exacts_per_minute"], -area["priority"])),
            "excluded": dict(excluded), "note": "Baselines recompile before work."}


def public_plan(result):
    return {**result, "areas": [{**{k: v for k, v in area.items() if k != "targets"},
                                "examples": [{k: row[k] for k in ("addr", "unit", "score", "size", "siblings")}
                                             for row in area["targets"][:3]]} for area in result["areas"]]}


def trial(client, addr, path, hypothesis):
    return research.trial(ROOT, client, addr, path, hypothesis)


def reuse(task, portfolio, tried=frozenset(), swept=frozenset()):
    return research.reuse(ROOT, task, portfolio, tried, swept)


GATES, known_failures = research.GATES, research.known_failures


STRATEGIES = (
    "Use fresh target diffs; repair proven constants, allocation sizes and argument sizes.",
    "Inspect vendor build preludes, import declarations and authentic template types. Skip exhausted compiler grids.",
    "Propagate verified sibling fixes; inspect evaluation order and floating-point codegen only where diffs prove it.",
)


def library_family(library):
    from roc import libs
    if library in libs.NAMES or library.startswith("Category:"):
        return library
    name = library.lower()
    for prefix, family in (("xtp", "XTP (Codejock)"), ("g3d", "G3D"), ("ogre", "Ogre"),
                           ("boost", "boost"), ("raknet", "RakNet"), ("lua", "Lua"),
                           ("scintilla", "Scintilla"), ("mfc", "MFC"), ("atl", "ATL"),
                           ("jpeg", "libjpeg"), ("libpng", "libpng"), ("zlib", "zlib"),
                           ("wildmagic", "Wild Magic")):
        if name.startswith(prefix):
            return family
    return library


def attributed_families(rows):
    """RTTI and exact rebuild anchors; matching neighbours are hints, not proof."""
    from roc import libs
    ordered = sorted(rows, key=lambda row: row["addr"])
    labels, anchors = {}, {}
    for row in ordered:
        label = libs.library_of(row.get("unit", ""))
        recipe = (row.get("source_directives") or match.directives(row.get("source") or "")).get("lib", "").split()
        family = library_family(libs.RECIPES[recipe[0]]["src"]) if recipe and recipe[0] in libs.RECIPES else label
        if row.get("score") == 100 and recipe and family in libs.NAMES + ["libjpeg", "libpng", "zlib", "Wild Magic"] and (row.get("size", 0) >= 64 or family == label):
            label = family
            anchors[row["addr"]] = family
        labels[row["addr"]] = label
    before, left = None, {}
    for row in ordered:
        left[row["addr"]] = before
        before = anchors.get(row["addr"], before)
    after = None
    for row in reversed(ordered):
        addr = row["addr"]
        if labels[addr] == "Unlabeled (no RTTI nearby)" and left[addr] and left[addr] == after:
            labels[addr] = after
        after = anchors.get(addr, after)
    return labels


def library_campaigns(rows, client, records):
    """Offer source-backed libraries and broad evidence-ranked repair categories."""
    from roc import libs
    versions = libs.recipe_versions()
    groups = defaultdict(list)
    attributed = attributed_families(rows)
    assigned = set()
    for row in rows:
        recipe = (row.get("source_directives") or match.directives(row.get("source") or "")).get("lib", "").split()
        if recipe and recipe[0] in libs.RECIPES and row.get("kind", "code") == "code":
            library = libs.RECIPES[recipe[0]]["src"]
            if client == "2008-06" and library.startswith("wildmagic"):
                continue  # Proven misattribution; see CLAUDE.md.
            if not library.startswith("../"):  # Client source-tree recipes are not vendor libraries.
                groups[library].append(dict(row, recipe=recipe[0]))
                assigned.add(row["addr"])
    for row in rows:
        family = attributed[row["addr"]]
        if row["addr"] not in assigned and family not in (
                libs.OTHER, "Unlabeled (no RTTI nearby)", "Roblox engine (RBX)") and row.get("kind", "code") == "code":
            if client == "2008-06" and family == "Wild Magic":
                continue
            groups[family].append(dict(row, recipe="", attribution="RTTI or matched neighbours"))
            assigned.add(row["addr"])
    categories = [row for row in rows if row["addr"] not in assigned and not (row.get("source_directives") or match.directives(row.get("source") or "")).get("lib")]
    for area in plan(categories, max_size=0, records=[], client=client)["areas"]:
        groups["Category: " + area["title"]].extend(dict(row, recipe="") for row in area["targets"])
    campaigns = []
    functions = {row["addr"]: row for row in rows}  # all scores, so matched neighbours show as read-only
    for library, members in groups.items():
        targets = [dict(row, behavior_evidence=agent.function_evidence(row, functions),
                        baseline_hash=digest(row.get("source") or ""),
                        target_revision=digest(json.dumps({k: v for k, v in row.items() if k != "source"}, sort_keys=True) +
                                               versions.get(row["recipe"], "")))
                   for row in members if row.get("score", 0) < 100]
        for row in targets:
            trials = [r for r in records if r.get("kind") == "trial" and r.get("client") == client and
                      row["addr"] in (r.get("addresses") or []) and
                      ((r.get("baseline_hash", r.get("source_hash")) == row["baseline_hash"] and
                        r.get("target_revision", row["target_revision"]) == row["target_revision"]) or
                       r.get("source_hash") == row["baseline_hash"])]
            row["trial_visits"] = len(trials)
            row["recently_tried"] = any(r.get("date") and not r.get("validation_failed") and
                '#import, #using, #include "file"' not in r.get("error", "") and
                (datetime.now(timezone.utc) - datetime.fromisoformat(r["date"]).replace(tzinfo=timezone.utc)).total_seconds() < 600
                for r in trials)
        targets = [row for row in targets if not row["recently_tried"]]
        targets.sort(key=lambda row: (row["trial_visits"], -row.get("size", 0)))
        if not targets:
            continue
        revision = digest("\n".join(sorted(row["addr"] + str(row.get("score", 0)) +
                                          digest(row.get("source") or "") + versions.get(row["recipe"], "") for row in targets)))
        previous = [r for r in records if r.get("kind") == "library_campaign" and
                    r.get("client") == client and r.get("library") == library and r.get("cohort") == revision]
        available = []
        for strategy in range(len(STRATEGIES)):
            trials = [r for r in previous if r.get("profile") == "library-strategy-%d" % strategy and
                      r.get("outcome") in ("improved", "no_gain")]
            if trials and trials[-1]["outcome"] == "no_gain" and trials[-1].get("tested_hypotheses", 0) >= 2:
                continue
            available.append((len(trials), strategy))
        if not available:
            continue
        timed = [r for r in records if r.get("kind") == "library_campaign" and r.get("client") == client
                 and r.get("library") == library and r.get("elapsed_seconds", 0) > 0 and "exacts_gained" in r][-20:]
        exact_rate = 60 * sum(r["exacts_gained"] for r in timed) / max(60, sum(r["elapsed_seconds"] for r in timed))
        family = library_family(library)
        campaigns.append(dict(client=client, library=library, family=family, revision=revision,
                              family_visits=sum(r.get("client") == client and r.get("kind") == "library_campaign" and
                                                library_family(r.get("library", "")) == family for r in records),
                              strategy=min(available)[1], visits=sum(r.get("client") == client and
                                  r.get("library") == library and r.get("kind") == "library_campaign"
                                  for r in records), targets=targets,
                              verified_exacts_per_minute=exact_rate,
                              exact=sum(row.get("score") == 100 for row in members),
                              recipes=sorted({row["recipe"] for row in members if row["recipe"]})))
    return sorted(campaigns, key=lambda c: (c["visits"], -len(c["targets"]), c["library"]))


def choose_campaign(candidates):
    """Rotate across least-tried libraries without score or gain-rate bias."""
    families = defaultdict(list)
    for campaign in candidates:
        families[(campaign.get("client"), campaign.get("family", library_family(campaign["library"])))].append(campaign)
    visits = {key: max(c.get("family_visits", c["visits"]) for c in group) for key, group in families.items()}
    family = random.choice([key for key in families if visits[key] == min(visits.values())])
    pool = families[family]
    return random.choice([c for c in pool if c["visits"] == min(item["visits"] for item in pool)])


def campaign_results(campaign_id, records):
    rows = [r for r in records if r.get("campaign_id") == campaign_id]
    gains = {}
    for row in rows:
        receipt = row.get("receipt") or {}
        if receipt.get("verified") and receipt.get("improved"):
            score = receipt.get("stored", receipt.get("score", row.get("after", 0)))
            for addr in row.get("addresses", []):
                gains[addr] = max(gains.get(addr, 0), score)
    hypotheses = {r["hypothesis"] for r in rows if r.get("kind") in ("trial", "research_run") and
                  r.get("hypothesis") and r.get("outcome") in ("no_gain", "compile_failed") and not r.get("duplicate")
                  and not r.get("validation_failed") and '#import, #using, #include "file"' not in r.get("error", "")}
    return gains, len(hypotheses)


def pull_sources(server, token, client, log):
    """Make a new contributor PC usable without overwriting local agent edits."""
    api = worker.Api(server, token)
    info = api.call("/v1/info")
    names = sorted(info["clients"]) if client == "all" else [client or "2008-06"]
    for name in names:
        if name not in info["clients"]:
            raise ValueError("Unknown selected client")
        worker.pull_files(server, name, token, force=False, log=log)


def prepare_clients(client, log):
    """Fetch/analyze target clients once before concurrent campaigns begin."""
    from roc import analyze
    registered = clients.load()
    names = sorted(registered) if client == "all" else [client or "2008-06"]
    for name in names:
        entry = registered.get(name)
        if not entry:
            raise ValueError("Unknown selected client: " + name)
        if clients.status(name, entry) != "ok":
            log("Automatic setup: fetching %s client binary." % name)
            if not clients.ensure(name):
                raise SystemExit("Automatic setup needs %s. Run: roc client-fetch %s" % (name, name))
        build = entry.get("compiler_build")
        if build and build not in setup.compilers():
            log("Automatic setup: installing %s." % setup.NAMES.get(build, "required compiler"))
            setup.install_compilers(only=[build], assume_yes=True)
            if build not in setup.compilers():
                raise SystemExit("Automatic setup needs %s. Run: install.cmd" % setup.NAMES.get(build, "the required compiler"))
        functions = ROOT / "work" / name / "functions.jsonl"
        if not functions.exists():
            log("Automatic setup: analyzing %s." % name)
            analyze.analyze(name, clients.exe_path(name, entry))


def materialize_campaign_sources(campaign):
    """Seed only this campaign's missing files; never bulk-download a new PC."""
    folder = ROOT / "src" / campaign["client"]
    written = 0
    for row in campaign["targets"]:
        source = row.get("source") or ""
        path = folder / (row["addr"] + ".cpp")
        if source and not path.exists():
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(source, encoding="utf-8")
            written += 1
    return written


def sourceable(recipe):
    """True when this PC has the recipe's vendor tree or can download it (XTP/MFC trees are not downloadable)."""
    from roc import libs
    r = libs.RECIPES[recipe]
    here = (r.get("generate") or "url" in r or libs._case_path(libs.LIBS / r["src"]).exists()
            or libs.bundle_has(r["src"]))
    return bool(here) and all(sourceable(dep) for dep in r.get("needs", []))


def campaign_packet(campaign, folder, server, user):
    """Ready source copies and commands; no model-side setup or discovery required."""
    for row in campaign["targets"]:
        path = folder / row["addr"] / (row["addr"] + ".cpp")
        path.parent.mkdir(parents=True, exist_ok=True)
        if row.get("source"):
            path.write_text(row["source"], encoding="utf-8")
        row["needs_source"] = not bool(row.get("source"))
        row["behavior_evidence"] = row.get("behavior_evidence") or agent.function_evidence(
            row, {item["addr"]: item for item in campaign["targets"]})
        (path.parent / "task.json").write_text(json.dumps(dict(client=campaign["client"], addr=row["addr"],
            area="campaign", profile="library-strategy-%d" % campaign.get("strategy", 0),
            best_score=row.get("score", 0), campaign_id=folder.name,
            baseline_hash=row.get("baseline_hash", digest(row.get("source") or "")),
            target_revision=row.get("target_revision", ""))))
        row["file"] = str(path)
        row["check"] = '%s agent-check %s %s "%s" --hypothesis "describe change"' % (
            agent.roc_command(), campaign["client"], row["addr"], path)
        row["submit"] = '%s submit %s %s --file "%s" --server "%s" --user "%s"' % (
            agent.roc_command(), campaign["client"], row["addr"], path, server, user)
    campaign["research_commands"] = {
        "list": agent.roc_command() + " research list",
        "plan": agent.roc_command() + " research plan NAME",
        "pilot": agent.roc_command() + ' research run NAME --client ' + campaign['client'] + ' --limit 1 --campaign-id ' + folder.name + ' --server "' + server + '"',
        "background": agent.roc_command() + ' research run NAME --client ' + campaign['client'] + ' --background --campaign-id ' + folder.name + ' --server "' + server + '"',
        "status": agent.roc_command() + " research status NAME --client " + campaign["client"],
        "resume": "Rerun the same background command; journals skip completed trials.",
    }
    (folder / "campaign.json").write_text(json.dumps(campaign, indent=2), encoding="utf-8")


def finalize_campaign(campaign, server, user, token, log):
    """Submit preserved best candidates even if the agent omitted submission commands."""
    errors = []
    for row in campaign["targets"]:
        path = Path(row["file"])
        best = path.parent / "best.cpp"
        if not best.exists() and not path.exists():
            continue
        candidates = []
        for candidate in (best, path):
            if candidate.exists():
                text = candidate.read_text(encoding="utf-8")
                try:
                    candidates.append((match.check_text(campaign["client"], row["addr"], text)[0], text))
                except match.CompileError as error:
                    log("Final candidate %s does not compile: %s" % (candidate, error))
        if not candidates:
            errors.append(dict(addr=row["addr"], error="No compiling candidate"))
            continue
        source = max(candidates, key=lambda item: item[0])[1]
        destination = path.parent / "submission" / path.name
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(source, encoding="utf-8")
        (destination.parent / "task.json").write_text((path.parent / "task.json").read_text(encoding="utf-8"), encoding="utf-8")
        try:
            worker.submit_files(server, user, campaign["client"], [row["addr"]], token, log=log, file=destination)
        except (RuntimeError, OSError) as error:
            errors.append(dict(addr=row["addr"], error=str(error)))
            log("Final submission failed for %s: %s" % (row["addr"], error))
    return errors


def library_cycle(server, user, token, cli, model, minutes, log, client, slot=None, claimed=None, claim_lock=None):
    if not 1 <= minutes <= 600:
        raise ValueError("Minutes must be 1-600")
    log("Selecting campaign: unfinished libraries first; categories when no fresh library remains.")
    api = worker.Api(server, token)
    info = api.call("/v1/info")
    requested = sorted(info["clients"]) if client == "all" else [client or "2008-06"]
    if any(name not in info["clients"] for name in requested):
        raise ValueError("Unknown selected client")
    eligible = [name for name in requested if name in info.get("verify", [])]
    names = worker.usable_clients({**info, "clients": {name: info["clients"][name] for name in eligible}}, log)
    if not names:
        raise ValueError("No selected clients are usable locally and verified by the server")
    shared = agent_memory.shared(server, token, user, upload=True)
    records = history() + shared.get("records", [])
    # Shared memory can contain the same local trial; count each campaign once.
    records = list({json.dumps(r, sort_keys=True): r for r in records}.values())
    choices = [campaign for name in names for campaign in library_campaigns(snapshot(name, api), name, records)]
    if not choices:
        log("No fresh library campaign available; falling back to ranked repair batches.")
        return None
    choices = [c for c in choices if all(sourceable(r) for r in c["recipes"])]
    if not choices:
        log("No library campaign has its vendor source on this PC; falling back to ranked repair batches.")
        return None
    choices = [c for c in choices if not c["library"].startswith("Category:")] or choices
    with (claim_lock or CLAIM_LOCK):
        # Libraries another loop or PC started recently and has not finished: pick something else.
        now = datetime.now(timezone.utc)
        rows = history() + shared.get("records", [])
        done = {(r.get("client"), r.get("library")): r["date"] for r in rows
                if r.get("kind") == "library_campaign" and r.get("date")}
        busy = {(r.get("client"), r.get("library")) for r in rows if r.get("kind") == "library_claim" and r.get("date")
                and (now - datetime.fromisoformat(r["date"])).total_seconds() < r.get("elapsed_seconds", minutes * 60)
                and done.get((r.get("client"), r.get("library")), "") < r["date"]}
        busy |= claimed or set()
        busy_families = {(name, library_family(library)) for name, library in busy}
        pool = [c for c in choices if (c["client"], c["family"]) not in busy_families]
        if not pool:
            log("All eligible campaigns are busy; waiting for a free library.")
            return dict(attempted=0, matched=0, improved=0, errors=0)
        campaign = choose_campaign(pool)
        if claimed is not None:
            claimed.add((campaign["client"], campaign["library"]))
        append(ROOT / "work" / "agent-memory" / "attempts.jsonl",
               dict(kind="library_claim", date=now.isoformat(), client=campaign["client"], library=campaign["library"],
                    elapsed_seconds=minutes * 60))
    try:
        agent_memory.shared(server, token, user, upload=True)  # let other PCs see the claim now
    except (RuntimeError, OSError):
        pass
    selected = campaign["client"]
    seeded = materialize_campaign_sources(campaign)
    folder = ROOT / "work" / "agent-campaigns" / uuid.uuid4().hex[:12]
    folder.mkdir(parents=True)
    campaign_packet(campaign, folder, server, user)
    log("Automatic campaign: %s · %s · %d open, %d exact attributed functions · strategy %d" %
        (selected, campaign["library"], len(campaign["targets"]), campaign["exact"], campaign["strategy"] + 1))
    if seeded:
        log("Campaign sources: %d missing files added locally." % seeded)
    brief = slot is not None and slot % 2 == 0
    prompt = (("Read CLAUDE.md and docs/AGENT_GUIDE.md. Client: %s. Library/category: %s.\n"
        "Use evidence in %s. Run commands as `%s <command>`. Submit improvements to %s as %s.\n"
        "Follow target order: least-tried evidence first, biggest unresolved functions next; no near-miss priority.\n"
        "One hypothesis, small pilot, then fan out winners.\n"
        "Search relevant research/log.jsonl and prior trials; no unchanged rejected grids.\n"
        "Use research/recipes.json grid/fanout; generated units through libs.add_unit.\n"
        "No unrelated infrastructure edits; no subagents. Stop after two losing hypotheses.\n"
        "Keep best sources; record trials; no asm, byte blobs, guessed layouts, or edits under clients/tools.\n"
        "Work up to %d minutes, then report wins and blockers.\n" %
        (selected, campaign["library"], folder / "campaign.json", agent.roc_command(), server, user, minutes) +
        agent.memory_prompt(agent.memory(shared), selected, campaign["library"])) if brief else
        ("Read CLAUDE.md and docs/AGENT_GUIDE.md. Experimental automatic research campaign.\n"
        "Finish as many unresolved functions in this library/category as evidence permits, across all sizes.\n"
        "Follow target order: least-tried evidence first, biggest unresolved functions next, including low-score non-exacts; no near-miss priority.\n"
        "Choose the most promising subcategory, targets and experiments yourself from the campaign evidence.\n"
        "The suggested strategy is a starting point; replace it when a different route has stronger evidence.\n"
        "Use one coherent campaign; do not spawn subagents or unrelated workers.\n"
        "Client: %s. Library/category: %s. Observed recipes: %s.\n" %
        (selected, campaign["library"], ", ".join(campaign["recipes"])) +
        "Server: %s. Contributor: %s. Use these explicitly for submissions.\n" % (server, user) +
        "Run commands as: " + agent.roc_command() + " <command>.\n"
        "Repository file map: CLI dispatch is roc.py; compiler/scorer is roc/match.py;\n"
        "library recipes are roc/libs.py; research runner is roc/research.py.\n"
        "There is no roc/cli.py or roc/compiler.py. Never invent a file path: first locate it with `rg --files`,\n"
        "then verify it with `Test-Path` before `Get-Content`. On PowerShell, find filename globs with\n"
        "`rg --files -g '00411*.cpp' src/2008-06`; do not pass `src/2008-06/00411*.cpp` as an rg path.\n"
        "Use `Get-Content -LiteralPath <verified-path> -ErrorAction Stop`. For Python, use a quoted raw Path\n"
        "such as `Path(r'work/agent-campaigns/.../campaign.json')`; never construct multiline `-c` code with shell escapes.\n"
        "Strategy: " + STRATEGIES[campaign["strategy"]] + "\n"
        "Read research/log.jsonl, lessons and prior trials before experimenting. Identify exact vendor version,\n"
        "build prelude/import context and observed template types. Inspect mismatches, propose one hypothesis,\n"
        "pilot it on representative sources, then fan out winning configurations across the whole family.\n"
        "Do not merely replay generic flags or sweep unchanged recipes. Require new evidence for rejected variants.\n"
        "Prefer compiler-only research grid/fanout recipes; record experiments in research/recipes.json.\n"
        "You may create reusable helper scripts under work/agent-tools/ and suggest them through shared memory;\n"
        "never hand-edit tools/ or clients/.\n"
        "Generated authentic units must go through libs.add_unit. Never hand-edit tools/ or clients/.\n"
        "You may edit research/recipes.json, evidence-backed recipes in roc/libs.py, src/ for this client,\n"
        "this campaign folder and append-only work/agent-memory/attempts.jsonl. No unrelated infrastructure edits.\n"
        "Preserve best sources; restore losing edits. No inline assembly, byte blobs or guessed layouts.\n"
        "Submit only improvements; server re-verification is required. Other workers may inspect the same targets; keep working and let the server retain the best verified source.\n"
        "After two losing hypotheses, try a different evidence-backed route or explain missing evidence and stop.\n"
        "Work up to %d minutes. End with receipts, rejected variants and next experiment.\n" % minutes +
        "Campaign evidence file: " + str(folder / "campaign.json") + "\n" +
        agent.memory_prompt(agent.memory(shared), selected, campaign["library"])))
    # Weak models read the memory JSON above as the whole message and wait for a task: restate it last.
    prompt += ("\nSetup already complete. Target files and check/submit commands are in campaign.json. "
               "Use those copies; needs_source targets require authentic source recovery first. "
               "Targets sort by least-tried current evidence, then largest size. Move past exhausted functions. "
               "Use agent-check for every experiment so trials are journaled. "
               "Do not run config, pull, client-fetch or analyze again. "
               "Research grid/fanout execution is available via `research run NAME`; NAME is a recipe key, "
               "not an operation. Read research_commands in campaign.json. Pilot one source first. "
               "For long runs use --background, check `research status NAME` once, then do independent work. "
               "Never wait in polling loops. Append memory via agent_memory.append_record, not raw file writes.\n")
    prompt += ("\n\nTASK (start now, do not wait for more input): improve unresolved %s functions in %s.\n"
               "First step: read %s, pick the first target, and use its journaled check command after preparing source. CLI: %s.\n" %
               (selected, campaign["library"], folder / "campaign.json", agent.roc_command()))
    log("Prompt mode: %s." % ("simple" if brief else "evidence-rich"))
    output_path = folder / "agent-output.jsonl"
    output_tail = []

    def output(message):
        message = str(message)
        append(output_path, dict(date=datetime.now(timezone.utc).isoformat(), message=message))
        output_tail.append(message[-2000:])
        del output_tail[:-6]
        row = dict(event="log", message=str(message))
        if slot is not None:
            row["slot"] = slot
        if log is print and os.environ.get("ROC_GUI_EVENTS"):
            print("ROC_EVENT " + json.dumps(row), flush=True)
        else:
            log(message)

    baseline = {row["addr"]: row.get("score", 0) for row in snapshot(selected, api)}
    baseline.update({row["addr"]: row.get("score", 0) for row in campaign["targets"]})
    reported = dict(baseline)
    benchmark_stop = threading.Event()
    started = time.monotonic()

    def benchmark():
        latest = worker.Api(server, token)
        try:
            scores = {row["addr"]: row.get("score", 0) for row in
                      latest.call("/v1/sources?scores=1&client=" + selected, timeout=120)}
        except (RuntimeError, OSError):
            scores = {}
        observed = {addr: score for addr, score in scores.items() if score > baseline.get(addr, 100)}
        gains, _ = campaign_results(folder.name, history())
        for addr, score in gains.items():
            if score <= reported.get(addr, 100):
                continue
            result = dict(event="job_finished", client=selected, addr=addr,
                          previous=reported[addr], score=score, new_exact=score == 100,
                          server_gains=True, slot=slot if slot is not None else 0)
            if slot is not None:
                result["slot"] = slot
            if log is print and os.environ.get("ROC_GUI_EVENTS"):
                print("ROC_EVENT " + json.dumps(result), flush=True)
            else:
                log("%s %s %s%% → %s%% · server verified%s" %
                    (selected, addr, reported[addr], score, " exact" if score == 100 else ""))
            reported[addr] = score
        exact = sum(score == 100 for score in gains.values())
        improved = len(gains) - exact
        row = dict(event="benchmark", workers=1, completed=len(gains), per_minute=round(
            len(gains) * 60 / max(time.monotonic() - started, 1), 1), matched=exact,
            improved=improved, errors=0, campaign_receipts=True, observed_server_gains=len(observed))
        if slot is not None:
            row["slot"] = slot
        if log is print and os.environ.get("ROC_GUI_EVENTS"):
            print("ROC_EVENT " + json.dumps(row), flush=True)
        else:
            log("Campaign benchmark: %d campaign receipts · %d exact · %d improved" %
                (len(gains), exact, improved))

    def benchmark_loop():
        while not benchmark_stop.wait(300):
            benchmark()

    ticker = threading.Thread(target=benchmark_loop, daemon=True)
    ticker.start()
    run_error = None
    try:
        code = agent.run_agent(cli, prompt, model, minutes, output, goal=True)
    except (RuntimeError, OSError) as error:
        run_error = str(error)
        code = 1
        output("Agent execution failed: " + run_error)
    finally:
        benchmark_stop.set()
        ticker.join(timeout=2)
    finalization_errors = finalize_campaign(campaign, server, user, token, output)
    benchmark()
    after = {row["addr"]: row for row in api.call("/v1/sources?scores=1&client=" + selected, timeout=120)}
    observed = [row for addr, row in after.items() if row.get("score", 0) > baseline.get(addr, 100)]
    gains, tested = campaign_results(folder.name, history())
    campaign_records = [r for r in history() if r.get("campaign_id") == folder.name]
    trial_count = sum(r.get("kind") in ("trial", "research_run") for r in campaign_records)
    elapsed = time.monotonic() - started
    stop_reason = ("agent_exception" if run_error else "agent_exit_error" if code else
                   "verified_gains" if gains else "hypotheses_exhausted" if tested >= 2 else
                   "no_recorded_trials" if not trial_count else "insufficient_completed_hypotheses")
    record = dict(kind="library_campaign", date=datetime.now(timezone.utc).isoformat(), client=selected,
                  library=campaign["library"], cohort=campaign["revision"], profile="library-strategy-%d" % campaign["strategy"],
                  outcome="error" if code else "improved" if gains else "no_gain" if tested >= 2 else "incomplete",
                  gains=len(gains), addresses=list(gains), evidence=str(folder), tested_hypotheses=tested,
                  observed_server_gains=len(observed), attribution="campaign receipts")
    record.update(stop_reason=stop_reason, agent_exit_code=code, agent_error=run_error,
                  trials_recorded=trial_count, agent_output=str(output_path), agent_output_tail=output_tail,
                  finalization_errors=finalization_errors,
                  time_budget_seconds=minutes * 60, budget_elapsed=elapsed >= minutes * 60)
    record.update(exacts_gained=sum(score == 100 for score in gains.values()),
                  elapsed_seconds=elapsed)
    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", record)
    (folder / "summary.json").write_text(json.dumps(record, indent=2), encoding="utf-8")
    agent_memory.shared(server, token, user, upload=True)
    log("Library campaign finished: %d receipt-backed gains; %d server gains observed; %s" %
        (len(gains), len(observed), record["outcome"]))
    if code == agent.RUNTIME_FAILED:
        raise SystemExit(agent.RUNTIME_FAILED)
    return dict(attempted=len(campaign["targets"]), matched=sum(score == 100 for score in gains.values()),
                improved=sum(score < 100 for score in gains.values()), errors=int(bool(code or finalization_errors)))


def run(server, user, token=None, cli="claude", model=None, workers=2, jobs=24, max_size=512,
        minutes=120, batch_size=4, batch_minutes=30, individual=False, log=print, client=None, continuous=False):
    strategy = 0
    failures = 0
    while True:
        try:
            totals = run_cycle(server, user, token, cli, model, workers, jobs, max_size, minutes,
                               batch_size, batch_minutes, individual, log, client, strategy)
        except (RuntimeError, OSError) as error:
            if not continuous:
                raise
            failures += 1
            if failures >= 3:
                raise
            log("Infrastructure failure; retrying in 30 seconds: " + str(error))
            time.sleep(30)
            continue
        if totals.get("runtime_failed"):
            raise SystemExit(agent.RUNTIME_FAILED)
        if not continuous:
            return totals
        failures = failures + 1 if totals["errors"] else 0
        if failures >= 3:
            raise RuntimeError("Three consecutive failed agent cycles; fix failure before restarting")
        if not totals["matched"] and not totals["improved"]:
            strategy = (strategy + 1) % len(STRATEGIES)
            log("No verified gains; next strategy: " + STRATEGIES[strategy])
        log("Continuous agent: refreshing targets and shared memory; Stop ends this run.")
        time.sleep(30 if not totals["attempted"] or totals["errors"] else 5)


def run_cycle(server, user, token=None, cli="claude", model=None, workers=2, jobs=24, max_size=512,
              minutes=120, batch_size=4, batch_minutes=30, individual=False, log=print, client=None, strategy=0):
    if not 1 <= workers <= 8 or not 1 <= jobs <= 200 or not 1 <= batch_size <= 12 or not 1 <= minutes <= 600:
        raise ValueError("Invalid automatic-agent limits")
    if not 1 <= batch_minutes <= 120 or (max_size != 0 and not 32 <= max_size <= 8192):
        raise ValueError("Invalid batch time / function size limit")
    if not agent.shutil.which(cli):
        raise ValueError("Install and sign in to the selected agent CLI first")
    api = worker.Api(server, token)
    info = api.call("/v1/info")
    registered = info.get("clients", {})
    client = client or "2008-06"
    if client and client != "all" and client not in registered:
        raise ValueError("Unknown server client: " + client)
    requested = [client] if client and client != "all" else sorted(registered)
    eligible = [name for name in requested if name in info.get("verify", [])]
    have = worker.usable_clients({**info, "clients": {name: registered[name] for name in eligible}}, log)
    if not have:
        raise ValueError("No selected clients are usable locally and verified by the server")
    profile = cli + ":" + (model or "default") + (":individual" if individual else "")
    if strategy:
        profile += ":strategy-%d" % strategy
    shared = agent_memory.shared(server, token, user, upload=True)
    records = history() + shared.get("records", [])
    result = portfolio(have, max_size, profile, records=records, api=api)
    tried = {name: known_failures([r for r in records if r.get("client", "2008-06") == name]) for name in have}
    swept = {name: research.gate_sweeps([r for r in records if r.get("client", "2008-06") == name]) for name in have}
    run_id = uuid.uuid4().hex[:12]
    directory = ROOT / "work" / "agent-auto" / run_id
    directory.mkdir(parents=True)
    (directory / "plan.json").write_text(json.dumps(public_plan(result), indent=2))
    deadline = time.monotonic() + minutes * 60
    event_lock, condition = threading.Lock(), threading.Condition()
    totals = {"attempted": 0, "matched": 0, "improved": 0, "errors": 0}
    manual_targets = set()
    model_unavailable = threading.Event()

    def event(kind, **fields):
        with event_lock:
            row = dict(event=kind, **fields)
            append(directory / "events.jsonl", row)
            if log is print:
                print("ROC_EVENT " + json.dumps(row), flush=True)
            else:
                log("ROC_EVENT " + json.dumps(row))

    event("stage", message="Automatic: agent repair first, free compiler checks last; %d workers, %d targets, %d minutes" %
          (workers, jobs, minutes))
    if not shared["available"]:
        event("log", message=shared["error"] + "; local memory retained. Update/restart group server for cross-PC sync.")

    def batch(slot, area, selected, phase):
        client = area["client"]
        local = worker.Api(server, token)
        active = []
        tried_route = phase == "reuse"
        quality_result = True
        skip_reason = "no_lease"

        try:
            for index, row in enumerate(selected):
                if time.monotonic() >= deadline:
                    break
                choices = [row]
                if phase == "reuse":
                    choices += [r for r in area["targets"] if r["group"] == row["group"] and
                                r["addr"] not in area["reserved"]][:31]
                job = local.call("/v1/lease", {"user": user, "worker": "auto-" + run_id + "-" + client + "-" + row["addr"],
                     "clients": [client], "mode": "ai", "model": "agent:auto:" + profile,
                     "max_size": max_size, "targets": [{"client": client, "addr": r["addr"]} for r in choices]})["job"]
                if not job:
                    continue  # No unresolved candidate in this selection.
                if job.get("client", client) != client or job["addr"] not in {r["addr"] for r in choices}:
                    local.call("/v1/release", {"lease": job["lease"], "cooldown": 0})
                    raise RuntimeError("Server leased a target outside the selected client/batch")
                worker_id = "auto-" + run_id + "-" + client + "-" + row["addr"]
                row = next(r for r in choices if r["addr"] == job["addr"])
                selected[index] = row
                area["reserved"].add(row["addr"])
                folder = directory / phase / client / row["addr"]
                folder.mkdir(parents=True)
                path = folder / (row["addr"] + ".cpp")
                source = job.get("source") or row["source"]
                task = dict(row, job=job, worker_id=worker_id, path=str(path), source=source, client=client, profile=profile,
                            before=0, best_score=0)
                active.append(task)
                path.write_text(source, encoding="utf-8")
                (folder / "best.cpp").write_text(source, encoding="utf-8")
                baseline, _, diff, _ = match.check_text(client, row["addr"], source)
                task.update(before=baseline, best_score=baseline, diff=diff)
                (folder / "task.json").write_text(json.dumps({k: task[k] for k in
                    ("addr", "client", "area", "profile", "best_score")}))
                event("job_started", slot=slot, addr=row["addr"], client=client, area=area["title"],
                      previous=baseline, unit=row["unit"], size=row["size"])
            portfolio = list(dict.fromkeys(task["source"] for task in active
                if any(k in match.directives(task["source"]) for k in ("lib", "archive"))))[:3]
            if phase == "reuse":
                event("stage", slot=slot, message="Compiler reuse · %s · %d targets (free, after agent repair)" % (area["title"], len(active)))
                for task in active:
                    if time.monotonic() >= deadline:
                        break
                    reuse(task, list(portfolio), tried[client], swept[client])
            else:
                pending = [task for task in active if task["before"] < 100]
                allow_individual = individual
                if len(pending) == 1 and not individual and pending[0]["size"] >= 64:
                    with condition:
                        if not manual_targets:
                            manual_targets.add((client, pending[0]["addr"]))
                            allow_individual = True
                if pending and (len(pending) >= 2 or allow_individual) and time.monotonic() < deadline:
                    tried_route = True
                    event("stage", slot=slot, message="Model repair · %s · %d targets · %s" % (area["title"], len(pending), cli))
                    assignments = [{"addr": t["addr"], "unit": t["unit"], "file": t["path"], "score": t["before"],
                                    "behavior_evidence": t.get("behavior_evidence", {}),
                                    "check": agent.roc_command() + " agent-check " + client + " " + t["addr"] +
                                     ' "' + t["path"] + '" --hypothesis "describe change"'} for t in pending]
                    brief = (slot + strategy) % 2 == 0
                    prompt = (("Read CLAUDE.md. Assigned client: " + client + ". Closest proven mismatches first.\n"
                        "Shared hypothesis first; inspect supplied diffs, pilot, propagate winners.\n"
                        "Edit only assigned files. Run its agent-check after every edit; wrapper submits best result.\n"
                        "Stop after two losing ideas. No asm, byte blobs, guessed layouts, or unrelated edits.\n" +
                        ("Individual function mining allowed: infer behavior from evidence, test one source change at a time.\n" if allow_individual else
                         "Individual function mining disabled; stop when no shared route works.\n") +
                        agent.memory_prompt(agent.memory(shared), client) + "Assignments:\n" + json.dumps([
                         {**assignment, "diff": t["diff"]} for assignment, t in zip(assignments, pending)])) if brief else
                        ("Read CLAUDE.md when present; otherwise use supplied cached context paths. Automatic BATCH repair.\n"
                        "Assigned client: " + client + ". This run selection overrides the default client focus in CLAUDE.md.\n"
                        "Goal: reusable gains across this area: " + area["advice"] + "\n"
                        "Current strategy: " + STRATEGIES[strategy] + "\n"
                        "Work on shared hypotheses first.\n"
                        "Edit ONLY the assigned candidate .cpp files below. Never edit src/, recipes, tools,\n"
                        "clients, function bounds, journals or task.json. The wrapper handles submission.\n"
                        "After EVERY edit run the assigned agent-check command with --hypothesis describing\n"
                        "the change. It preserves the best and journals all outcomes automatically.\n"
                        "No inline assembly, byte blobs, guessed layouts or unsupported ABI declarations.\n"
                        "Use target diffs and genuine headers. Skip exhausted grids. Stop after two losing\n"
                        "shared hypotheses. Leave next evidence needed in your summary.\n" +
                        ("Individual function mining allowed: infer behavior from evidence, test one source change at a time.\n" if allow_individual else
                         "Individual function mining is disabled. If no shared route works, stop.\n") +
                        agent.memory_prompt(agent.memory(shared), client) + "\nAssignments (evidence data):\n" + json.dumps([
                         {**assignment, "diff": t["diff"]} for assignment, t in zip(assignments, pending)])))
                    prompt += ("\n\nTASK (start now, do not wait for more input): edit the assigned .cpp files above "
                               "to match their targets; run each one's check command after every edit.\n")
                    event("log", slot=slot, message="Prompt mode: %s." % ("simple" if brief else "evidence-rich"))
                    code = agent.run_agent(cli, prompt, model, min(batch_minutes, (deadline-time.monotonic())/60),
                        lambda message: event("log", slot=slot, message=message))
                    if code:
                        quality_result = False
                        skip_reason = "cli_error"
                        model_unavailable.set()
                        with condition:
                            totals["errors"] += 1
                            if code == agent.RUNTIME_FAILED:
                                totals["runtime_failed"] = True
                        event("log", slot=slot, message="Agent CLI exited with code %s; verifying preserved best sources" % code)
                elif active:
                    skip_reason = "no_eligible_repair"
            gains, exacts = 0, 0
            for task in active:
                text = (Path(task["path"]).parent / "best.cpp").read_text(encoding="utf-8")
                score = match.check_text(client, task["addr"], text)[0]
                receipt = None
                if score >= task["before"] and score > task["job"]["score"]:
                    receipt = local.call("/v1/submit", {"lease": task["job"]["lease"], "user": user,
                        "worker": task["worker_id"], "model": "agent:auto:" + profile,
                        "client": client, "addr": task["addr"], "score": score, "source": text}, timeout=120)
                    if not receipt.get("verified"):
                        raise RuntimeError("Server did not verify candidate")
                improved = bool(receipt and receipt.get("improved"))
                exact = bool(improved and receipt.get("score") == 100)
                gains += improved
                exacts += exact
                if phase == "reuse" or tried_route:
                    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", dict(kind="auto_target",
                    date=datetime.now(timezone.utc).isoformat(), client=client, addresses=[task["addr"]],
                    area=area["id"], profile=profile, phase=phase, before=task["before"], after=score,
                    evidence_hash=task["evidence_hash"], baseline_hash=digest(task["source"]),
                    repair_attempted=phase == "repair" and tried_route and quality_result,
                    source_hash=digest(text), outcome="server_verified" if improved else "no_gain",
                    receipt=receipt, evidence=str(Path(task["path"]).parent)))
                telemetry.begin(dict(client=client, addr=task["addr"], unit=task["unit"],
                    score=task["before"], source=task["source"]), "agent:auto:" + profile, run_id)
                telemetry.candidate(text, score)
                telemetry.finish(receipt["score"] if improved else task["before"], None, [])
                with condition:
                    totals["attempted"] += 1
                    totals["matched"] += exact
                    totals["improved"] += improved and not exact
                event("job_finished", slot=slot, client=client, addr=task["addr"], previous=task["before"],
                      score=receipt["score"] if improved else task["before"], new_exact=exact,
                      improved=improved, area=area["title"], unit=task["unit"], size=task["size"])
                if improved:
                    event("candidate", slot=slot, score=receipt["score"], code=text)
            return gains, len(active) if tried_route and quality_result else 0, exacts, None if tried_route and quality_result and active else skip_reason
        finally:
            for task in active:  # free the server claims so other parallel agents can take these
                try:
                    local.call("/v1/release", {"lease": task["job"]["lease"], "cooldown": 0})
                except (worker.ApiFailure, OSError, ValueError):
                    pass

    # Every selected area gets agent repair first, then compiler-only reuse.
    selected, remaining = [], jobs
    areas = [area for area in result["areas"] if not area["parked"]]
    for area in areas:
        # Two bounded shards of the strongest areas before weaker opportunities.
        families = defaultdict(list)
        for row in area["targets"]:
            if not row["group_parked"]:
                families[row["group"]].append(row)
        shards = 0
        for family in families.values():
            for offset in range(0, len(family), batch_size):
                if not remaining or shards == 2:
                    break
                targets = family[offset:offset + min(batch_size, remaining)]
                selected.append((area, targets))
                remaining -= len(targets)
                shards += 1
            if not remaining or shards == 2:
                break
        area["reserved"] = {row["addr"] for chosen_area, rows in selected if chosen_area is area for row in rows}
    for phase in ("repair", "reuse"):  # model first; free compiler-only reuse last, never before the agent starts
        event("stage", message="%s phase · %d batches" % ("Free compiler checks" if phase == "reuse" else "Agent repair", len(selected)))
        queue, busy, zero = list(selected), set(), defaultdict(int)

        def work(slot):
            while time.monotonic() < deadline:
                if phase == "repair" and model_unavailable.is_set():
                    return
                with condition:
                    available = next((i for i, (area, _) in enumerate(queue) if (area["client"], area["id"]) not in busy), None)
                    if available is None:
                        if not queue:
                            return
                        condition.wait(timeout=0.2)
                        continue
                    area, targets = queue.pop(available)
                    group = targets[0]["group"]
                    if phase == "repair" and len(targets) == 1 and not individual and (
                            targets[0]["size"] < 64 or manual_targets):
                        continue  # No model route: avoid leasing/rechecking the unchanged singleton.
                    if phase == "repair" and zero[group] >= 1:
                        continue
                    busy.add((area["client"], area["id"]))
                try:
                    started = time.monotonic()
                    gains, attempted, exacts, skip_reason = batch(slot, area, targets, phase)
                    record = dict(kind="auto_batch", date=datetime.now(timezone.utc).isoformat(),
                        client=area["client"], area=area["id"], profile=profile, phase=phase, cohort=area["cohort"],
                        group=group, group_cohort=targets[0]["group_cohort"],
                        outcome="improved" if gains else "no_gain" if attempted else "error" if skip_reason == "cli_error" else "deferred" if skip_reason == "no_eligible_repair" else "unavailable", gains=gains,
                        skip_reason=skip_reason,
                        exacts_gained=exacts, exhausted=phase == "repair" and bool(attempted) and not gains,
                        addresses=[t["addr"] for t in targets], elapsed_seconds=time.monotonic() - started,
                        evidence=str(directory))
                    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", record)
                    if attempted:
                        with condition:
                            zero[group] = 0 if gains else zero[group] + 1
                    if phase == "repair" and zero[group] >= 1:
                        event("log", slot=slot, message="Parked %s after exhausted repair batch; new evidence required" % area["title"])
                except (RuntimeError, OSError, ValueError) as error:
                    with condition:
                        totals["errors"] += 1
                    event("log", slot=slot, message="Infrastructure/compile failure: " + str(error))
                    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", dict(kind="auto_error",
                        date=datetime.now(timezone.utc).isoformat(), client=area["client"], area=area["id"], phase=phase, profile=profile,
                        outcome="error", error=str(error), addresses=[t["addr"] for t in targets], evidence=str(directory)))
                finally:
                    with condition:
                        busy.discard((area["client"], area["id"]))
                        condition.notify_all()
            event("slot_stopped", slot=slot)

        with ThreadPoolExecutor(max_workers=workers) as pool:
            list(pool.map(work, range(workers)))
    (directory / "summary.json").write_text(json.dumps(totals, indent=2))
    synced = agent_memory.shared(server, token, user, upload=True)
    if not synced["available"]:
        event("log", message=synced["error"] + "; attempts queued locally for next sync")
    event("stage", message="Automatic complete: %d new verified exacts, %d partial gains, %d errors; %s" %
          (totals["matched"], totals["improved"], totals["errors"], directory))
    return totals
