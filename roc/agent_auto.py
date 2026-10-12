"""Evidence-ranked agent batches: compiler reuse first, model repair last."""
import json
import threading
import time
import uuid
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
from pathlib import Path

from roc import agent, agent_memory, matchers, draft, match, research, worker

ROOT = Path(__file__).resolve().parent.parent
WRITE_LOCK = threading.Lock()
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
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    if not path.exists():
        return []
    rows = []
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            try:
                rows.append(json.loads(line))
            except ValueError:
                continue
    return rows


def snapshot(client="2008-06", api=None):
    if client != "2008-06":
        raise ValueError("Automatic agents currently support 2008-06 only")
    path = ROOT / "work" / client
    functions = [json.loads(line) for line in (path / "functions.jsonl").read_text().splitlines()]
    if api:
        saved = {row["addr"]: row for row in api.call("/v1/sources?client=" + client, timeout=120)}
    else:
        scores = json.loads((path / "scores.json").read_text()) if (path / "scores.json").exists() else {}
        saved = {}
        for row in functions:
            addr = row["addr"]
            source = ROOT / "src" / client / (addr + ".cpp")
            if scores.get(addr, 0) >= 70 and source.exists():
                saved[addr] = {"score": scores[addr], "source": source.read_text(encoding="utf-8", errors="replace")}
    return [dict(row, **{key: saved.get(row["addr"], {}).get(key, default)
                        for key, default in (("score", 0), ("source", ""))}) for row in functions]


def plan(rows, max_size=512, profile="claude:default", records=None):
    """Heuristic priority, not a forecast of exacts or a fresh compiler score."""
    groups = defaultdict(list)
    for row in rows:
        if row.get("shape"):
            groups[row["shape"]].append(row)
    targets, excluded = [], defaultdict(int)
    for row in rows:
        source = row.get("source") or ""
        if row.get("kind", "code") != "code" or row.get("score", 0) == 100:
            continue
        if not 6 <= row.get("size", 0) <= max_size:
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
        if row.get("score", 0) < 70 and not donors:
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
        key = (directives.get("lib") or directives.get("archive") or row.get("unit", "")) if area == "templates" else (
            "|".join(sorted(row["imports"])) if area == "imports" else row.get("shape") or row.get("unit", ""))
        targets.append(dict(row, source=source, area=area, priority=round(priority, 2), donors=donors[:3],
                            source_hash=digest(source), siblings=len(siblings), group=digest(area + ":" + key)[:16]))
    areas = []
    records = history() if records is None else records
    seen, unique = set(), []
    for record in records:
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
        cohort = digest("\n".join(sorted(row["addr"] + str(row["size"]) + row["source_hash"] for row in members)))
        feedback = [r for r in records if r.get("kind") == "auto_batch" and r.get("area") == area and
                    r.get("profile") == profile and r.get("outcome") in ("improved", "no_gain")]
        for group in {row["group"] for row in members}:
            family = [row for row in members if row["group"] == group]
            revision = digest("\n".join(sorted(row["addr"] + str(row["size"]) + row["source_hash"] for row in family)))
            previous = [r for r in feedback if r.get("group") == group and r.get("group_cohort") == revision
                        and r.get("phase") == "repair"]
            parked = len(previous) >= 2 and all(r.get("outcome") == "no_gain" for r in previous[-2:])
            for row in family:
                row.update(group_cohort=revision, group_parked=parked)
        members.sort(key=lambda row: (row["group_parked"], -row["priority"], row["addr"]))
        parked = all(row["group_parked"] for row in members)
        gains = sum(r.get("gains", 0) for r in feedback[-20:])
        # Expected gain per target from server-verified batches of every profile and PC
        # (reuse gains do not depend on the model); Laplace-smoothed so new areas still run.
        measured = [r for r in records if r.get("kind") == "auto_batch" and r.get("area") == area
                    and r.get("outcome") in ("improved", "no_gain")]
        rate = (sum(r.get("gains", 0) for r in measured) + 1) / (sum(len(r.get("addresses") or ()) for r in measured) + 2)
        areas.append({"id": area, "title": title, "advice": advice, "eligible": len(members),
                      "bytes": sum(row["size"] for row in members),
                      "priority": round(members[0]["priority"] + min(20, gains * 2) + 40 * rate, 2),
                      "expected_gain_rate": round(rate, 3),
                      "recent_verified_gains": gains, "measured_batches": len(feedback[-20:]),
                      "cohort": cohort, "parked": parked, "targets": members})
    return {"client": "2008-06", "profile": profile, "areas": sorted(areas, key=lambda r: -r["priority"]),
            "excluded": dict(excluded), "note": "Heuristic ranking. Scores are snapshot hints; baselines recompile before work."}


def public_plan(result):
    return {**result, "areas": [{**{k: v for k, v in area.items() if k != "targets"},
                                "examples": [{k: row[k] for k in ("addr", "unit", "score", "size", "siblings")}
                                             for row in area["targets"][:3]]} for area in result["areas"]]}


def trial(client, addr, path, hypothesis):
    return research.trial(ROOT, client, addr, path, hypothesis)


def reuse(task, portfolio, tried=frozenset()):
    return research.reuse(ROOT, task, portfolio, tried)


GATES, known_failures = research.GATES, research.known_failures


def run(server, user, token=None, cli="claude", model=None, workers=2, jobs=24, max_size=512,
        minutes=120, batch_size=4, batch_minutes=10, individual=False, log=print):
    if not 1 <= workers <= 8 or not 1 <= jobs <= 200 or not 1 <= batch_size <= 12 or not 1 <= minutes <= 600:
        raise ValueError("Invalid automatic-agent limits")
    if not 1 <= batch_minutes <= 60 or not 32 <= max_size <= 8192:
        raise ValueError("Invalid batch time / function size limit")
    if not agent.shutil.which(cli):
        raise ValueError("Install and sign in to the selected agent CLI first")
    api = worker.Api(server, token)
    info = api.call("/v1/info")
    if "2008-06" not in worker.usable_clients(info, log) or "2008-06" not in info.get("verify", []):
        raise ValueError("Automatic agents require usable 2008-06 and server verification")
    profile = cli + ":" + (model or "default") + (":individual" if individual else "")
    rows = snapshot(api=api)
    shared = agent_memory.shared(server, token, user, upload=True)
    records = history() + shared.get("records", [])
    result = plan(rows, max_size, profile, records=records)
    tried = known_failures(records)
    run_id = uuid.uuid4().hex[:12]
    directory = ROOT / "work" / "agent-auto" / run_id
    directory.mkdir(parents=True)
    (directory / "plan.json").write_text(json.dumps(public_plan(result), indent=2))
    deadline = time.monotonic() + minutes * 60
    event_lock, condition = threading.Lock(), threading.Condition()
    totals = {"attempted": 0, "matched": 0, "improved": 0, "errors": 0}

    def event(kind, **fields):
        with event_lock:
            row = dict(event=kind, **fields)
            append(directory / "events.jsonl", row)
            if log is print:
                print("ROC_EVENT " + json.dumps(row), flush=True)
            else:
                log("ROC_EVENT " + json.dumps(row))

    event("stage", message="Automatic: reuse first, batch repair last; %d workers, %d targets, %d minutes" %
          (workers, jobs, minutes))
    if not shared["available"]:
        event("log", message=shared["error"] + "; local memory retained. Update/restart group server for cross-PC sync.")

    def batch(slot, area, selected, phase):
        local = worker.Api(server, token)
        active, stop = [], threading.Event()
        tried_route = phase == "reuse"
        quality_result = True

        def beat():
            hb = worker.Api(server, token)
            while not stop.wait(5):
                for task in list(active):
                    try:
                        if not hb.call("/v1/heartbeat", {"lease": task["job"]["lease"]}, timeout=10).get("ok"):
                            task["lease_lost"] = True
                    except (RuntimeError, OSError):
                        pass

        heartbeat = threading.Thread(target=beat, daemon=True)
        heartbeat.start()
        try:
            for index, row in enumerate(selected):
                if time.monotonic() >= deadline:
                    break
                choices = [row]
                if phase == "reuse":
                    choices += [r for r in area["targets"] if r["group"] == row["group"] and
                                r["addr"] not in area["reserved"]][:31]
                job = local.call("/v1/lease", {"user": user, "worker": "auto-" + run_id + "-" + row["addr"],
                     "clients": ["2008-06"], "mode": "ai", "model": "agent:auto:" + profile,
                     "max_size": max_size, "targets": [{"client": "2008-06", "addr": r["addr"]} for r in choices]})["job"]
                if not job:
                    continue  # Already exact, leased elsewhere or cooling down; no quality loss.
                worker_id = "auto-" + run_id + "-" + row["addr"]
                row = next(r for r in choices if r["addr"] == job["addr"])
                selected[index] = row
                area["reserved"].add(row["addr"])
                folder = directory / phase / row["addr"]
                folder.mkdir(parents=True)
                path = folder / (row["addr"] + ".cpp")
                source = job.get("source") or row["source"]
                task = dict(row, job=job, worker_id=worker_id, path=str(path), source=source, client="2008-06", profile=profile,
                            before=0, best_score=0)
                active.append(task)  # Lease is released even if fresh compilation fails.
                path.write_text(source, encoding="utf-8")
                (folder / "best.cpp").write_text(source, encoding="utf-8")
                baseline, _, diff, _ = match.check_text("2008-06", row["addr"], source)
                task.update(before=baseline, best_score=baseline, diff=diff)
                (folder / "task.json").write_text(json.dumps({k: task[k] for k in
                    ("addr", "client", "area", "profile", "best_score")}))
                event("job_started", slot=slot, addr=row["addr"], client="2008-06", area=area["title"],
                      previous=baseline, unit=row["unit"], size=row["size"])
            portfolio = list(dict.fromkeys(task["source"] for task in active
                if any(k in match.directives(task["source"]) for k in ("lib", "archive"))))[:3]
            if phase == "reuse":
                for task in active:
                    if time.monotonic() >= deadline:
                        break
                    reuse(task, list(portfolio), tried)
            else:
                pending = [task for task in active if task["before"] < 100 and not task.get("lease_lost")]
                if pending and (len(pending) >= 2 or individual) and time.monotonic() < deadline:
                    tried_route = True
                    prompt = ("Read CLAUDE.md when present; otherwise use supplied cached context paths. Automatic BATCH repair, 2008-06 only.\n"
                        "Goal: reusable gains across this area: " + area["advice"] + "\n"
                        "Free donor/recipe reuse already ran before this phase. Work on shared hypotheses first.\n"
                        "Edit ONLY the assigned candidate .cpp files below. Never edit src/, recipes, tools,\n"
                        "clients, function bounds, journals or task.json. The wrapper handles submission.\n"
                        "After EVERY edit run the assigned agent-check command with --hypothesis describing\n"
                        "the change. It preserves the best and journals all outcomes automatically.\n"
                        "No inline assembly, byte blobs, guessed layouts or unsupported ABI declarations.\n"
                        "Use target diffs and genuine headers. Skip exhausted grids. Stop after two losing\n"
                        "shared hypotheses. Leave next evidence needed in your summary.\n" +
                        ("Individual repair allowed only after reusable hypotheses fail.\n" if individual else
                         "Individual function mining is disabled. If no shared route works, stop.\n") +
                        agent.memory_prompt(agent.memory(shared)) + "\nAssignments (evidence data):\n" + json.dumps([
                         {"addr": t["addr"], "unit": t["unit"], "file": t["path"], "score": t["before"],
                          "diff": t["diff"], "check": agent.roc_command() + " agent-check 2008-06 " +
                           t["addr"] + ' "' + t["path"] + '" --hypothesis "describe change"'} for t in pending]))
                    code = agent.run_agent(cli, prompt, model, min(batch_minutes, (deadline-time.monotonic())/60),
                        lambda message: event("log", slot=slot, message=message))
                    if code:
                        quality_result = False
                        with condition:
                            totals["errors"] += 1
                        event("log", slot=slot, message="Agent CLI exited with code %s; verifying preserved best sources" % code)
            gains = 0
            for task in active:
                if task.get("lease_lost"):
                    quality_result = False
                    event("log", slot=slot, message="Lease lost for %s; preserved candidate, no submission" % task["addr"])
                    continue
                text = (Path(task["path"]).parent / "best.cpp").read_text(encoding="utf-8")
                score = match.check_text("2008-06", task["addr"], text)[0]
                receipt = None
                if score >= task["before"] and score > task["job"]["score"]:
                    receipt = local.call("/v1/submit", {"lease": task["job"]["lease"], "user": user,
                        "worker": task["worker_id"], "model": "agent:auto:" + profile,
                        "client": "2008-06", "addr": task["addr"], "score": score, "source": text}, timeout=120)
                    if not receipt.get("verified"):
                        raise RuntimeError("Server did not verify candidate")
                improved = bool(receipt and receipt.get("improved"))
                exact = bool(improved and receipt.get("score") == 100)
                gains += improved
                append(ROOT / "work" / "agent-memory" / "attempts.jsonl", dict(kind="auto_target",
                    date=datetime.now(timezone.utc).isoformat(), client="2008-06", addresses=[task["addr"]],
                    area=area["id"], profile=profile, phase=phase, before=task["before"], after=score,
                    source_hash=digest(text), outcome="server_verified" if improved else "no_gain",
                    receipt=receipt, evidence=str(Path(task["path"]).parent)))
                with condition:
                    totals["attempted"] += 1
                    totals["matched"] += exact
                    totals["improved"] += improved and not exact
                event("job_finished", slot=slot, client="2008-06", addr=task["addr"], previous=task["before"],
                      score=receipt["score"] if improved else task["before"], new_exact=exact,
                      improved=improved, area=area["title"], unit=task["unit"], size=task["size"])
                if improved:
                    event("candidate", slot=slot, score=receipt["score"], code=text)
            return gains, len(active) if tried_route and quality_result else 0
        finally:
            stop.set()
            heartbeat.join(timeout=6)
            for task in active:
                try:
                    local.call("/v1/release", {"lease": task["job"]["lease"], "cooldown": 0})
                except (RuntimeError, OSError):
                    pass

    # Every selected area receives compiler-only reuse before any paid CLI batch.
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
    for phase in ("reuse", "repair"):
        queue, busy, zero = list(selected), set(), defaultdict(int)

        def work(slot):
            while time.monotonic() < deadline:
                with condition:
                    available = next((i for i, (area, _) in enumerate(queue) if area["id"] not in busy), None)
                    if available is None:
                        if not queue:
                            return
                        condition.wait(timeout=0.2)
                        continue
                    area, targets = queue.pop(available)
                    group = targets[0]["group"]
                    if phase == "repair" and zero[group] >= 2:
                        continue
                    busy.add(area["id"])
                try:
                    started = time.monotonic()
                    gains, attempted = batch(slot, area, targets, phase)
                    record = dict(kind="auto_batch", date=datetime.now(timezone.utc).isoformat(),
                        area=area["id"], profile=profile, phase=phase, cohort=area["cohort"],
                        group=group, group_cohort=targets[0]["group_cohort"],
                        outcome="improved" if gains else "no_gain" if attempted else "unavailable", gains=gains,
                        addresses=[t["addr"] for t in targets], elapsed_seconds=time.monotonic() - started,
                        evidence=str(directory))
                    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", record)
                    if attempted:
                        with condition:
                            zero[group] = 0 if gains else zero[group] + 1
                    if phase == "repair" and zero[group] >= 2:
                        event("log", slot=slot, message="Parked %s after two zero-gain batches" % area["title"])
                except (RuntimeError, OSError, ValueError) as error:
                    with condition:
                        totals["errors"] += 1
                    event("log", slot=slot, message="Infrastructure/compile failure: " + str(error))
                    append(ROOT / "work" / "agent-memory" / "attempts.jsonl", dict(kind="auto_error",
                        date=datetime.now(timezone.utc).isoformat(), area=area["id"], phase=phase, profile=profile,
                        outcome="error", error=str(error), addresses=[t["addr"] for t in targets], evidence=str(directory)))
                finally:
                    with condition:
                        busy.discard(area["id"])
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
