"""Bounded paired source-hidden search; checkpoint candidates and arm summaries."""
import argparse
import hashlib
import json
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from roc import benchmark, metrics, providers, setup


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--session", required=True)
    parser.add_argument("--workers", type=int, choices=range(1, 65), default=32)
    parser.add_argument("--rounds", type=int, default=4)
    parser.add_argument("--repeats", type=int, default=3)
    parser.add_argument("--max-cost", type=float, default=30)
    parser.add_argument("--max-tokens", type=int, default=30000000)
    parser.add_argument("--max-requests", type=int, default=10000)
    parser.add_argument("--model", default="deepseek:deepseek-flash")
    parser.add_argument("--limit", type=int, help="run only first N manifest targets")
    args = parser.parse_args()
    rows = json.loads(args.manifest.read_text(encoding="utf-8"))
    if args.limit is not None:
        if args.limit < 1:
            parser.error("limit must be positive")
        rows = rows[:args.limit]
    keys = [(row["client"], row["addr"]) for row in rows]
    if len(set(keys)) != len(keys) or not rows:
        parser.error("manifest must contain unique targets")
    if min(args.rounds, args.repeats, args.max_cost, args.max_tokens, args.max_requests) <= 0:
        parser.error("rounds, repeats and budget caps must be positive")
    root = Path("work/mass-search") / args.session
    root.mkdir(parents=True, exist_ok=False)
    fingerprint = hashlib.sha256(args.manifest.read_bytes()).hexdigest()
    cloud = providers.is_cloud(args.model)
    budget = providers.CloudBudget(args.max_requests, args.max_tokens, args.max_cost)
    gate = providers.CloudGate(args.workers if cloud else 1)
    if cloud:
        providers.generate(args.model, "Reply OK.", options={
            "allow_cloud": True, "max_tokens": 1, "thinking": "disabled",
            "budget": budget, "gate": gate})
    setup.compilers()
    report = {"manifest": str(args.manifest), "sha256": fingerprint,
              "configuration": vars(args) | {"manifest": str(args.manifest)}, "arms": []}
    (root / "manifest.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")
    for repeat in range(args.repeats):
        # Alternate order to reduce time/provider-load bias.
        for strategy in (("direct", "structured") if repeat % 2 == 0 else ("structured", "direct")):
            session = "%s-%s-r%d" % (args.session, strategy, repeat + 1)
            options = {"allow_cloud": True, "thinking": "disabled", "budget": budget,
                       "gate": gate, "diverse_candidates": 3, "seed": repeat + 1}
            metrics.record(session, event="benchmark_start", targets=len(rows),
                           corpus_sha256=fingerprint, strategy=strategy, workers=args.workers,
                           rounds=args.rounds, diverse_candidates=3, model=args.model)
            started = time.monotonic()

            def run(target):
                benchmark.run_local([target], [args.model], rounds=args.rounds,
                                    session=session, strategies=(strategy,), provider_options=options,
                                    candidate_dir=root / session,
                                    log=lambda line: print(line, flush=True)
                                    if line.startswith("  " + args.model + "/") else None)

            print("Starting %s: %d targets" % (session, len(rows)), flush=True)
            with ThreadPoolExecutor(max_workers=args.workers) as pool:
                list(pool.map(run, rows))
            records = []
            with metrics.PATH.open(encoding="utf-8") as stream:
                for line in stream:
                    try:
                        row = json.loads(line)
                    except ValueError:
                        continue
                    if row.get("session") == session and row.get("event") == "job":
                        records.append(row)
            arm = {"session": session, "jobs": len(records),
                   "exact": sum(row["score"] == 100 for row in records),
                   "compilable": sum(row.get("compile_ok", 0) > 0 for row in records),
                   "failures": sum(bool(row.get("failure")) for row in records),
                   "seconds": round(time.monotonic() - started, 2)}
            report["arms"].append(arm)
            report["usage"] = {"requests": budget.requests, "tokens": budget.tokens, "cost": budget.cost}
            (root / "report.json").write_text(json.dumps(report, indent=1), encoding="utf-8")
            print(json.dumps(arm), flush=True)
            if any("cloud_budget" in str(row.get("failure")) or "limit reached" in str(row.get("failure"))
                   or "circuit is open" in str(row.get("failure")) for row in records):
                print("Budget/provider stop; checkpoints preserved.", flush=True)
                return


if __name__ == "__main__":
    main()
