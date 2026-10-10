"""Pilot branches from verified config wins, with conditional full-scale exact sweeps."""
import argparse
import functools
import json
import os
import random
import re
import time
from collections import defaultdict
from contextlib import contextmanager
from pathlib import Path

from benchmarks.followup_pilots import HANDOFF, OLD, live
from benchmarks.match_campaign import Campaign, digest
from roc import clients, fingerprint, libs, match

ROOT = Path("work/library-branches-20261010")
FOLLOWUP = Path("work/followup-pilots-20261010")


def reserved_shapes():
    # Read the other agent's current registry; never invoke its experiments.
    from benchmarks.re_pilot import TEMPLATE_FAMILIES
    exemplars = HANDOFF + [(v[0], v[1]) for v in TEMPLATE_FAMILIES.values()]
    return {match._functions(c).get(a, {}).get("shape") for c, a in exemplars} - {None, ""}


def winning_sources(settings_only=False, combination_only=False):
    sources = {}
    counts = defaultdict(set)
    logs = [(ROOT, "library-settings")] if settings_only else [(OLD, "configuration"), (FOLLOWUP, "config-cross"), (FOLLOWUP, "config-unseen")]
    if combination_only:
        logs = [(ROOT, "settings-combination"), (ROOT, "combo-transfer")]
    for root, stage in logs:
        path = root / (stage + ".jsonl")
        if not path.exists():
            continue
        for line in path.read_text(encoding="utf-8").splitlines():
            row = json.loads(line)
            for w in [row.get("winner", {})] + row.get("winners", []):
                s = w.get("submission", {})
                if w.get("client") == "2009-12" or not (s.get("verified") and s.get("score") == 100 and s.get("improved")):
                    continue
                p = w.get("candidate_path")
                if not p or not Path(p).exists():
                    continue
                source = Path(p).read_text(encoding="utf-8")
                sha = digest(source)
                sources[sha] = source
                counts[sha].add((w["client"], w["addr"]))
    return [(sources[k], len(v)) for k, v in sorted(counts.items(), key=lambda x: (-len(x[1]), x[0]))]


def late_sources():
    sources, counts = {}, defaultdict(set)
    for stage in ("late-spillover", "combo-spillover"):
        path = ROOT / (stage + ".jsonl")
        if not path.exists():
            continue
        for row in map(json.loads, path.read_text(encoding="utf-8").splitlines()):
            for w in row.get("winners", []):
                submission, candidate = w.get("submission", {}), w.get("candidate_path")
                if w.get("client") == "2009-12" or not (submission.get("verified") and submission.get("score") == 100 and submission.get("improved")) or not candidate or not Path(candidate).exists():
                    continue
                source = Path(candidate).read_text(encoding="utf-8")
                sha = digest(source)
                sources[sha] = source
                counts[sha].add((w["client"], w["addr"]))
    return [(sources[k], len(v)) for k, v in sorted(counts.items(), key=lambda x: (-len(x[1]), x[0]))]


def codegen_sources():
    sources, counts = {}, defaultdict(set)
    path = ROOT / "combo-codegen.jsonl"
    if not path.exists():
        return []
    for row in map(json.loads, path.read_text(encoding="utf-8").splitlines()):
        for w in row.get("winners", []):
            s, candidate = w.get("submission", {}), w.get("candidate_path")
            if w.get("client") == "2009-12" or not (s.get("verified") and s.get("score") == 100 and s.get("improved")) or not candidate or not Path(candidate).exists():
                continue
            source = Path(candidate).read_text(encoding="utf-8")
            sha = digest(source)
            sources[sha] = source
            counts[sha].add((w["client"], w["addr"]))
    return [(sources[k], len(v)) for k, v in sorted(counts.items(), key=lambda x: (-len(x[1]), x[0]))]


def variants(source):
    """Single-setting hypotheses. Keep source, compiler, CRT, and ABI unchanged."""
    d = match.directives(source)
    flags = d["flags"].split()
    for group, option, reason in [(["/Oy", "/Oy-"], "/Oy-", "frame-pointer preservation"),
                                  (["/EHsc", "/EHa"], "/EHsc", "C++ exception handling"),
                                  (["/GS-", "/GS"], "/GS", "security-cookie generation"),
                                  (["/Ob0", "/Ob1", "/Ob2"], "/Ob2", "inline expansion")]:
        if option in flags:
            continue
        settings = " ".join([v for v in flags if v not in group] + [option])
        candidate = re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: " + settings, source)
        if candidate != source:
            yield reason, candidate


def combination(source):
    flags = match.directives(source)["flags"].split()
    settings = " ".join([v for v in flags if v not in ("/GS-", "/GS", "/EHsc", "/EHa")] + ["/GS", "/EHsc"])
    return re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: " + settings, source)


def numeric_variants(source):
    flags = match.directives(source)["flags"].split()
    for group, option in [(["/Oi", "/Oi-"], "/Oi"), (["/Oi", "/Oi-"], "/Oi-"),
                          (["/fp:fast", "/fp:precise", "/fp:strict"], "/fp:fast")]:
        if option in flags:
            continue
        settings = " ".join([v for v in flags if v not in group] + [option])
        yield "numeric/intrinsic code generation: " + option, re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: " + settings, source)


def optimization_variants(source):
    flags = match.directives(source)["flags"].split()
    for group, option in [(["/O1", "/O2", "/Ox", "/Od"], "/O1"),
                          (["/Os", "/Ot"], "/Os"), (["/Os", "/Ot"], "/Ot"),
                          (["/GF", "/GF-"], "/GF-")]:
        if option in flags:
            continue
        settings = " ".join([v for v in flags if v not in group] + [option])
        yield "optimization/string pooling: " + option, re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: " + settings, source)


def untested_files(campaign):
    """Expand proven builds to installed files with unresolved named-class evidence."""
    scores = live(campaign)
    excluded = reserved_shapes()
    units = defaultdict(int)
    for client in campaign.info["clients"]:
        for addr, row in match._functions(client).items():
            if row.get("kind") == "code" and row.get("shape") not in excluded and scores[client].get(addr, {}).get("score", 0) < 100:
                units[row.get("unit", "")] += 1
    tested, pins = set(), {}
    for stage in ("settings-combination", "combo-transfer"):
        manifest = ROOT / (stage + "-manifest.json")
        if not manifest.exists():
            continue
        saved = json.loads(manifest.read_text(encoding="utf-8"))
        for group in saved if isinstance(saved, list) else saved["groups"]:
            d = match.directives(group["source"])
            recipe, _, path = d["lib"].partition(" ")
            tested.add(((recipe, d["cl"], d["flags"], d["lang"]), path.replace("\\", "/")))
    for source, wins in winning_sources(combination_only=True):
        d = match.directives(source)
        recipe, _, path = d["lib"].partition(" ")
        pin = (recipe, d["cl"], d["flags"], d["lang"])
        tested.add((pin, path.replace("\\", "/")))
        pins.setdefault(pin, source)
    sources = []
    for pin, source in pins.items():
        recipe = pin[0]
        spec = libs.RECIPES[recipe]
        folder = libs._case_path(libs.LIBS / spec["src"])
        for path in libs.files_of(spec, folder):
            path = path.replace("\\", "/")
            support = units.get("C" + Path(path).stem, 0)
            if not support or (pin, path) in tested:
                continue
            candidate = re.sub(r"(?m)^//\s*roc-lib:.*$", "// roc-lib: " + recipe + " " + path, source)
            sources.append((candidate, support))
    return sources


def recipe_variants(source):
    d = match.directives(source)
    recipe, _, path = d["lib"].partition(" ")
    for name, spec in libs.RECIPES.items():
        if name == recipe or not name.startswith("xtp-") or not name.endswith("shared-mfc"):
            continue
        folder = libs._case_path(libs.LIBS / spec["src"])
        if not folder.is_dir() or not (folder / path).is_file():
            continue  # Only installed, existing same-path source; no discovery downloads.
        yield "installed neighboring XTP recipe: " + name, re.sub(r"(?m)^//\s*roc-lib:.*$", "// roc-lib: " + name + " " + path, source)


@functools.lru_cache(maxsize=128)
def unit_hash(recipe, path, build):
    return digest(libs.unit(recipe, path, build))


def compile_shared(client, source):
    """Only fully pinned library directives may share objects across clients."""
    d = match.directives(source)
    if not all(k in d for k in ("cl", "flags", "lang", "lib")) or "archive" in d:
        return match.compile_text(client, source), False
    recipe, _, path = d["lib"].partition(" ")
    key = digest(source + "\0" + unit_hash(recipe, path, int(d["cl"])))
    folder = ROOT / "objects"
    folder.mkdir(parents=True, exist_ok=True)
    p = folder / (key + ".obj")
    if p.exists():
        return p.read_bytes(), True
    obj = match.compile_text(client, source)
    temp = p.with_suffix(".%d.tmp" % os.getpid())
    temp.write_bytes(obj)
    temp.replace(p)
    return obj, False


def build_manifest(campaign, stage):
    path = ROOT / (stage + "-manifest.json")
    if path.exists():
        saved = json.loads(path.read_text(encoding="utf-8"))
        if isinstance(saved, list):
            return saved
        return [dict(p, rows=saved["targets"][p["client"]]) for p in saved["groups"]]
    scores = live(campaign)
    reserved = reserved_shapes()
    plans = []
    sources = codegen_sources() if stage == "codegen-transfer" else (late_sources() if stage == "late-transfer" else winning_sources(settings_only=stage == "variant-spillover",
                              combination_only=stage in ("combo-spillover", "late-spillover", "recipe-neighbor", "numeric-settings", "combo-codegen", "combo-optimization", "small-code"))
    )
    if stage in ("combo-newfiles", "combo-newfiles-diverse"):
        sources = untested_files(campaign)
        if stage == "combo-newfiles-diverse":
            previous_path = ROOT / "combo-newfiles-manifest.json"
            prior = json.loads(previous_path.read_text(encoding="utf-8"))["groups"][:12]
            sampled = {match.directives(p["source"])["lib"].partition(" ")[2] for p in prior}
            sources = [(s, n) for s, n in sources if match.directives(s)["lib"].partition(" ")[2] not in sampled]
    spillover = stage in ("spillover", "variant-spillover", "combo-spillover", "late-spillover")
    proven = set()
    tested = set()
    if stage == "proven-settings":
        for r in campaign.previous("library-settings"):
            tested.add(r["key"])
            if any(w.get("submission", {}).get("verified") and w["submission"].get("score") == 100
                   and w["submission"].get("improved") for w in r["winners"]):
                proven.add(r["hypothesis"])
    if stage == "combo-transfer":
        previous_path = ROOT / "settings-combination-manifest.json"
        if previous_path.exists():
            saved = json.loads(previous_path.read_text(encoding="utf-8"))
            groups = saved if isinstance(saved, list) else saved["groups"]
            tested.update(digest(p["client"] + p["source"]) for p in groups)
    elif stage == "late-spillover":
        for r in campaign.previous("combo-spillover"):
            tested.add(r["key"])
    successful_bases = {r["baseline_sha256"] for r in campaign.previous("library-settings")
                        if any(w.get("submission", {}).get("improved") for w in r["winners"])}
    targets = {}
    created = set()
    for client in campaign.info["clients"]:
        targets[client] = [a for a, r in match._functions(client).items()
                           if r.get("kind") == "code" and ((stage == "small-code" and 1 <= r.get("size", 0) < 8) or (stage != "small-code" and r.get("size", 0) >= 8))
                           and r.get("shape") not in reserved
                           and scores[client].get(a, {}).get("score", 0) < 100
                           and (stage in ("combo-codegen", "combo-optimization", "combo-newfiles", "combo-newfiles-diverse", "late-transfer", "codegen-transfer", "small-code") or (not r.get("unit", "").startswith("CXT") if spillover else r.get("unit", "").startswith("CXT")))]
    for source, wins in sources:
        if stage == "settings-combination" and digest(source) not in successful_bases:
            continue
        hypotheses = [("verified codegen source transfer", source)] if stage == "codegen-transfer" else (([("late verified spillover source transfer", source)] if stage == "late-transfer" else (([("tiny code target under proven combined build", source)] if stage == "small-code" else ([("unnamed and non-CXT library spillover", source)] if spillover else list(variants(source)))))))
        if stage in ("settings-combination", "combo-transfer"):
            hypotheses = [("combined proven cookie and exception options", combination(source))]
        elif stage == "native-build":
            hypotheses = [("receiving client's registered compiler build", source)]
        elif stage == "recipe-neighbor":
            hypotheses = list(recipe_variants(source))
        elif stage == "numeric-settings":
            hypotheses = list(numeric_variants(source))
        elif stage == "combo-optimization":
            hypotheses = list(optimization_variants(source))
        elif stage in ("combo-newfiles", "combo-newfiles-diverse"):
            hypotheses = [("installed untested file under proven build; rank is unresolved named-class count", source)]
        if stage == "proven-settings":
            hypotheses = [(reason, s) for reason, s in hypotheses if reason in proven]
        for reason, candidate in hypotheses:
            for client in campaign.info["clients"]:
                actual_candidate = candidate
                if stage == "native-build":
                    build = clients.load()[client]["compiler_build"]
                    if int(match.directives(source)["cl"]) == build:
                        continue
                    actual_candidate = re.sub(r"(?m)^//\s*roc-cl:.*$", "// roc-cl: " + str(build), source)
                key = digest(client + actual_candidate)
                if key in tested or key in created:
                    continue
                rows = targets[client]
                if rows:
                    created.add(key)
                    plans.append(dict(client=client, source=actual_candidate, baseline_source=source,
                                      hypothesis=reason, donor_wins=wins, rows=rows))
    # Seeded discovery among strongest proven forms, with multiple clients/sources.
    random.Random(20261012).shuffle(plans)
    strong, remainder = [], []
    seen_sources, seen_clients = set(), set()
    for p in sorted(plans, key=lambda r: -r["donor_wins"]):
        sha = digest(p["source"])
        if len(strong) < 12 and (sha not in seen_sources or p["client"] not in seen_clients):
            strong.append(p)
            seen_sources.add(sha); seen_clients.add(p["client"])
        else:
            remainder.append(p)
    plans = strong + remainder
    if stage == "combo-newfiles-diverse":
        selected = {}
        for p in sorted(plans, key=lambda r: -r["donor_wins"]):
            file = match.directives(p["source"])["lib"].partition(" ")[2]
            if file not in selected and len(selected) < 12:
                selected[file] = digest(p["source"])
        selected_sources = set(selected.values())
        plans = [p for p in plans if digest(p["source"]) in selected_sources] + [p for p in plans if digest(p["source"]) not in selected_sources]
    path.write_text(json.dumps(dict(targets=targets, groups=[{k: v for k, v in p.items() if k != "rows"} for p in plans])), encoding="utf-8")
    campaign.record("design", dict(stage=stage, groups=len(plans), seed=20261012,
                                   reserved_shapes=len(reserved), sources=len(sources),
                                   pilot_cohorts=12, scale_threshold=10, cost=0))
    return plans


def sweep(campaign, stage, plans, limit):
    done = {r["key"] for r in campaign.previous(stage)}
    scores = live(campaign)
    reserved = reserved_shapes()
    for group in plans[:limit]:
        client, source = group["client"], group["source"]
        key = digest(client + source)
        if client not in campaign.info["clients"] or key in done:
            continue
        result = dict(client=client, key=key, hypothesis=group["hypothesis"],
                      source_sha256=digest(source), baseline_sha256=digest(group["baseline_source"]),
                      donor_wins=group["donor_wins"], winners=[], cost=0)
        started = time.monotonic()
        try:
            target = fingerprint.Target(client)
            target.index = defaultdict(list)
            for a in group["rows"]:
                row = match._functions(client)[a]
                if scores[client].get(a, {}).get("score", 0) < 100 and row.get("shape") not in reserved:
                    target.index[row["size"]].append(a)
            result["targets"] = sum(map(len, target.index.values()))
            obj, cached = compile_shared(client, source)
            result.update(object_cached=cached, object_sha256=digest(obj.hex()))
            found = target.match_obj(obj, source)
            # Settings pilots distinguish genuinely new variant gains from baseline wins.
            if stage in ("library-settings", "proven-settings", "settings-combination", "combo-transfer", "native-build", "recipe-neighbor", "numeric-settings", "combo-codegen", "combo-optimization", "late-transfer", "codegen-transfer", "small-code") and found:
                base_obj, _ = compile_shared(client, group["baseline_source"])
                baseline_target = fingerprint.Target(client)
                baseline_target.index = defaultdict(list)
                for a in found:
                    baseline_target.index[match._functions(client)[a]["size"]].append(a)
                baseline_matches = baseline_target.match_obj(base_obj, group["baseline_source"])
                result["baseline_already_matches"] = list(baseline_matches)
                found = {a: v for a, v in found.items() if a not in baseline_matches}
            for a in found:
                winner = campaign.submit_exact(stage, client, a, source)
                result["winners"].append(winner)
                if winner.get("already_exact") or winner.get("submission", {}).get("score") == 100:
                    scores[client][a] = dict(score=100)
            result["rejection"] = "" if result["winners"] else "no new exact byte/data match"
        except (RuntimeError, ValueError, OSError, SystemExit) as e:
            result["error"] = str(e)[-600:]
        result["seconds"] = round(time.monotonic() - started, 3)
        campaign.record(stage, result)
        done.add(key)
        print(stage, client, result.get("targets"), len(result["winners"]), result["seconds"], flush=True)


@contextmanager
def stage_lock(stage):
    ROOT.mkdir(parents=True, exist_ok=True)
    with (ROOT / (stage + ".lock")).open("a+b") as stream:
        stream.seek(0)
        if os.name == "nt":
            import msvcrt
            msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl
            fcntl.flock(stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        yield


def run(args):
    campaign = Campaign(str(ROOT), "http://127.0.0.1:8765")
    plans = build_manifest(campaign, args.stage)
    sweep(campaign, args.stage, plans, args.pilot)
    rows = campaign.previous(args.stage)
    pilot_keys = {digest(p["client"] + p["source"]) for p in plans[:args.pilot]}
    pilot_rows = [r for r in rows if r["key"] in pilot_keys]
    wins = {(w["client"], w["addr"]) for r in pilot_rows for w in r["winners"]
            if w.get("submission", {}).get("verified") and w["submission"].get("score") == 100
            and w["submission"].get("improved")}
    decision = dict(stage=args.stage, pilot_groups=args.pilot, completed=len({r["key"] for r in pilot_rows}), new_exact=len(wins),
                    threshold=10, scale=bool(args.scale_if_wins and len(wins) >= 10), cost=0)
    campaign.record("decisions", decision)
    print("PILOT", json.dumps(decision), flush=True)
    if decision["scale"]:
        sweep(campaign, args.stage, plans, len(plans))
    elif args.scale_if_wins and len(wins) >= 2:
        successful = {r["source_sha256"] for r in rows
                      if any(w.get("submission", {}).get("improved") for w in r["winners"])}
        selected = [p for p in plans if digest(p["source"]) in successful]
        campaign.record("decisions", dict(stage=args.stage, selective_scale=True,
                                          successful_forms=len(successful), groups=len(selected), cost=0))
        sweep(campaign, args.stage, selected, len(selected))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("stage", choices=["spillover", "library-settings", "variant-spillover", "proven-settings", "settings-combination", "combo-transfer", "combo-spillover", "native-build", "late-spillover", "recipe-neighbor", "numeric-settings", "combo-codegen", "combo-optimization", "combo-newfiles", "combo-newfiles-diverse", "late-transfer", "codegen-transfer", "small-code"])
    ap.add_argument("--pilot", type=int, default=12)
    ap.add_argument("--scale-if-wins", action="store_true")
    args = ap.parse_args()
    with stage_lock(args.stage):
        run(args)


if __name__ == "__main__":
    main()
