"""Paired DeepSeek history ablation on a fixed, source-hidden corpus.

Run from the repository root: python benchmarks/history.py
"""
import argparse
import json
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, metrics, providers, refsource, setup, worker


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--session", default="history-ablation-20261008")
    parser.add_argument("--keep", nargs="+", type=int, default=[2, 0])
    parser.add_argument("--repeats", type=int, default=2)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--auto-preset", action="store_true")
    parser.add_argument("--workers", type=int, choices=range(1, 65), default=4, metavar="1-64")
    parser.add_argument("--no-resume", action="store_true")
    parser.add_argument("--reasoning", action="store_true")
    parser.add_argument("--compact-rules", action="store_true")
    parser.add_argument("--binary-only", action="store_true")
    parser.add_argument("--temperature", type=float)
    parser.add_argument("--strategy", choices=["direct", "structured", "reference"], default="direct")
    args = parser.parse_args()
    corpus = json.loads(benchmark.HIDDEN.read_text())
    corpus = [row for row in corpus if row["client"] == "2007-08"]
    if not corpus:
        raise SystemExit("No 2007-08 hidden targets; generate the hidden corpus first.")
    gate = providers.CloudGate(args.workers)
    startup = time.monotonic()
    setup.compilers()
    if refsource.TREE.is_dir():
        refsource.build_index(log=lambda line: None)
    startup = time.monotonic() - startup
    print("Compiler/source warmup: %.3fs" % startup, flush=True)
    for repeat in range(args.repeats):
        for keep in args.keep:
            session = "%s-k%d-r%d" % (args.session, keep, repeat + 1)
            options = {"allow_cloud": True, "thinking": "disabled",
                       "gate": gate,
                       "compact_rules": args.compact_rules, "binary_only": args.binary_only}
            if keep >= 0:
                options["history_keep_last"] = keep
            if args.temperature is not None:
                options["temperature"] = args.temperature

            def run(target):
                target_options = dict(options)
                if args.reasoning and target["size"] > 48:
                    target_options.update(thinking="enabled", max_tokens=8192)
                rounds = worker.resolve_rounds(target, "auto" if args.auto_preset else args.rounds,
                                              "deepseek:deepseek-flash")
                benchmark.run_local([target], ["deepseek:deepseek-flash"], rounds=rounds,
                                    resume=not args.no_resume, session=session, strategies=(args.strategy,),
                                    provider_options=target_options,
                                    log=lambda line: print(line, flush=True)
                                    if line.startswith("  deepseek:") else None)

            print("%s: %d targets" % (session, len(corpus)), flush=True)
            started = time.monotonic()
            with ThreadPoolExecutor(max_workers=args.workers) as pool:
                list(pool.map(run, corpus))
            elapsed = time.monotonic() - started
            metrics.record(session, event="benchmark_batch", workers=args.workers,
                           targets=len(corpus), rounds="auto" if args.auto_preset else args.rounds,
                           startup_seconds=round(startup, 3),
                           resume=not args.no_resume, seconds=round(elapsed, 3))
            print("%s: %dw batch %.3fs%s" % (session, args.workers, elapsed,
                  " (may include resumed jobs)" if not args.no_resume else ""), flush=True)


if __name__ == "__main__":
    main()
