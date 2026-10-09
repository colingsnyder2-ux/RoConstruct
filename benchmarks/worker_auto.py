"""Compare automatic worker policy against a fixed two-round source-hidden control."""
import argparse
import hashlib
import json
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, match, metrics, providers, refsource, setup, worker


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--model", default="deepseek:deepseek-flash")
    parser.add_argument("--session", default="worker-policy-" + time.strftime("%Y%m%d-%H%M%S"))
    parser.add_argument("--repeats", type=int, default=2)
    parser.add_argument("--max-cloud-cost", type=float, default=1)
    parser.add_argument("--allow-cloud", action="store_true")
    args = parser.parse_args()
    corpus = json.loads(args.manifest.read_text(encoding="utf-8"))
    digest = hashlib.sha256(json.dumps(corpus, sort_keys=True).encode()).hexdigest()
    budget = providers.CloudBudget(requests=200, tokens=1000000, cost=args.max_cloud_cost)
    workers = worker.resolve_workers("auto", args.model)
    gate = providers.CloudGate(workers)
    setup.compilers()
    if refsource.TREE.is_dir():
        refsource.build_index(log=lambda _: None)
    for repeat in range(args.repeats):
        for arm in (("automatic", "control") if repeat % 2 == 0 else ("control", "automatic")):
            session = "%s-%s-r%d" % (args.session, arm, repeat + 1)
            metrics.record(session, event="benchmark_start", corpus_sha256=digest,
                           model=args.model, workers=workers, arm=arm, targets=len(corpus))

            def run(target):
                row = match._functions(target["client"])[target["addr"]]
                thinking, effort = worker.auto_reasoning(row, "auto", "auto", args.model)
                options = dict(allow_cloud=args.allow_cloud, budget=budget, gate=gate,
                               thinking=thinking, reasoning_effort=effort, seed=42,
                               max_tokens=worker.resolve_output_tokens(row, "auto") if arm == "automatic" else 2048)
                if arm == "automatic" and args.model.startswith("deepseek:"):
                    options["source_hint_max_size"] = 128
                benchmark.run_local([target], [args.model],
                                    rounds=worker.resolve_rounds(row, "auto", args.model) if arm == "automatic" else 2,
                                    session=session, provider_options=options, log=lambda _: None)

            started = time.monotonic()
            with ThreadPoolExecutor(max_workers=workers) as pool:
                list(pool.map(run, corpus))
            elapsed = time.monotonic() - started
            metrics.record(session, event="benchmark_batch", seconds=round(elapsed, 3))
            rows = []
            for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
                try:
                    rows.append(json.loads(line))
                except ValueError:
                    continue
            rows = [row for row in rows if row.get("session") == session and row.get("event") == "job"]
            print(json.dumps(dict(session=session, jobs=len(rows), exact=sum(row["score"] == 100 for row in rows),
                                  compiling=sum(row["compile_ok"] > 0 for row in rows),
                                  tokens=sum(row["input_tokens"] + row["output_tokens"] for row in rows),
                                  failures=sum(bool(row.get("failure")) for row in rows), seconds=round(elapsed, 3))), flush=True)


if __name__ == "__main__":
    main()
