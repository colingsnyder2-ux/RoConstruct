"""Paired real-compiler replay of saved, source-hidden candidates.

Run: python benchmarks/repairs.py --corpus benchmarks/holdout-2007-08.json
No model calls or server submissions; both arms start from identical C++.
"""
import argparse
import hashlib
import json
import sys
import time
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import clients, match, metrics, mutate


def candidates(corpus, metrics_path, model=None):
    targets = {(row["client"], row["addr"]): row for row in corpus}
    selected = {}
    for line in metrics_path.read_text(encoding="utf-8-sig").splitlines():
        if not line.lstrip().startswith("{"):
            continue
        try:
            row = json.loads(line)
        except ValueError:
            continue
        key = (row.get("client"), row.get("addr"))
        if row.get("event") != "job" or key not in targets or (model and row.get("model") != model):
            continue
        possible = [attempt for attempt in row.get("rounds", [])
                    if isinstance(attempt, dict) and isinstance(attempt.get("round"), int)
                    and attempt.get("code") and not attempt.get("compile_error")
                    and attempt.get("source") and attempt.get("score", 0) < 100]
        if not possible:
            continue
        best = max(possible, key=lambda attempt: attempt.get("score", 0))
        selected[key] = {**targets[key], "source": best["source"],
                         "model": row.get("model"), "candidate_score": best.get("score", 0),
                         "generation_cost": row.get("estimated_cost"),
                         "flags": row.get("compiler_flags")}
    return [selected[key] for key in sorted(selected)]


def run(rows, session):
    results = {"existing": [], "guided": []}
    setup = clients.load()
    for row in rows:
        client, addr, source = row["client"], row["addr"], row["source"]
        flags = row.get("flags") or setup[client].get("flags")
        try:
            initial = match.check_text(client, addr, source, flags)[0]
        except match.CompileError:
            continue
        key = (client, addr)
        arms = (("guided", True), ("existing", False)) if int(hashlib.sha256((client + addr).encode()).hexdigest(), 16) & 1 \
            else (("existing", False), ("guided", True))
        for name, guided in arms:
            match.compile_text.cache_clear()
            started = time.monotonic()
            improved = mutate.improve(client, addr, source, flags, guided=guided)
            elapsed = round(time.monotonic() - started, 3)
            record = {"client": client, "addr": addr, "bucket": row["bucket"],
                      "model": row["model"], "initial": initial,
                      "candidate_sha256": hashlib.sha256(source.encode()).hexdigest(),
                      "final": improved[0], "conversion": initial < 100 and improved[0] == 100,
                      "tries": improved[2], "mutations": improved.mutations,
                      "seconds": elapsed,
                      "mutation_seconds": round(sum(item["seconds"] for item in improved.mutations), 3),
                      "generation_cost": row.get("generation_cost")}
            results[name].append(record)
            metrics.record(session, event="repair_replay", arm=name, **record)
    return results


def report(results):
    for arm, rows in results.items():
        conversions = [row for row in rows if row["conversion"]]
        classes = Counter(item["category"] for row in rows for item in row["mutations"])
        wins = Counter(item["category"] for row in rows for item in row["mutations"] if item.get("exact"))
        unproductive = sum(item.get("score", 0) <= row["initial"] for row in rows for item in row["mutations"])
        costs = [row["generation_cost"] for row in rows]
        total_cost = sum(costs) if costs and all(value is not None for value in costs) else None
        print("%s: %d candidates, %d initial exact, %d mutator conversions, %d final exact; "
              "%d attempts, %.3fs mutation time, %.3fs total replay; tokens +0, estimated generation cost %s" %
              (arm, len(rows), sum(row["initial"] == 100 for row in rows), len(conversions),
               sum(row["final"] == 100 for row in rows), sum(row["tries"] for row in rows),
               sum(row["mutation_seconds"] for row in rows), sum(row["seconds"] for row in rows),
               "unknown" if total_cost is None else "$%.6f (%s/exact)" %
               (total_cost, "unknown" if not sum(row["final"] == 100 for row in rows) else
                "%.6f" % (total_cost / sum(row["final"] == 100 for row in rows)))))
        print("  attempts by category: %s; exact mutations: %s" % (dict(classes), dict(wins)))
        print("  attempts without score gain: %d" % unproductive)
        for bucket in ("tiny", "medium", "large"):
            sized = [row for row in rows if row["bucket"] == bucket]
            if sized:
                print("  %s: %d candidates, %d conversions, %d attempts, %.3fs mutation time" %
                      (bucket, len(sized), sum(row["conversion"] for row in sized),
                       sum(row["tries"] for row in sized),
                       sum(row["mutation_seconds"] for row in sized)))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--corpus", type=Path, default=Path("benchmarks/holdout-2007-08.json"))
    parser.add_argument("--metrics", type=Path, default=metrics.PATH)
    parser.add_argument("--model")
    parser.add_argument("--session", default="repair-paired-" + time.strftime("%Y%m%d-%H%M%S"))
    args = parser.parse_args()
    corpus = json.loads(args.corpus.read_text(encoding="utf-8"))
    rows = candidates(corpus, args.metrics, args.model)
    if not rows:
        raise SystemExit("No saved compilable non-exact candidates found for corpus.")
    fingerprint = hashlib.sha256(json.dumps(
        [(row["client"], row["addr"], hashlib.sha256(row["source"].encode()).hexdigest())
         for row in rows], separators=(",", ":")).encode()).hexdigest()
    metrics.record(args.session, event="benchmark_start", corpus_sha256=fingerprint,
                   targets=len(rows), model=args.model, mutation_arms=["existing", "guided"])
    print("Paired repair-only replay: %d identical candidates across %d clients; zero model calls." %
          (len(rows), len({row["client"] for row in rows})))
    started = time.monotonic()
    results = run(rows, args.session)
    metrics.record(args.session, event="benchmark_end", corpus_sha256=fingerprint,
                   targets=len(rows), seconds=round(time.monotonic() - started, 3))
    report(results)


if __name__ == "__main__":
    main()
