"""Paired DeepSeek history ablation on a fixed, source-hidden corpus.

Run from the repository root: python benchmarks/history.py
"""
import argparse
import json
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, providers


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--session", default="history-ablation-20261008")
    parser.add_argument("--keep", nargs="+", type=int, default=[2, 0])
    parser.add_argument("--repeats", type=int, default=2)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--reasoning", action="store_true")
    parser.add_argument("--compact-rules", action="store_true")
    parser.add_argument("--strategy", choices=["direct", "structured", "reference"], default="direct")
    args = parser.parse_args()
    corpus = json.loads(benchmark.HIDDEN.read_text())
    corpus = [row for row in corpus if row["client"] == "2007-08"]
    if not corpus:
        raise SystemExit("No 2007-08 hidden targets; generate the hidden corpus first.")
    gate = providers.CloudGate(4)
    for repeat in range(args.repeats):
        for keep in args.keep:
            session = "%s-k%d-r%d" % (args.session, keep, repeat + 1)
            options = {"allow_cloud": True, "thinking": "disabled",
                       "gate": gate,
                       "compact_rules": args.compact_rules}
            if keep >= 0:
                options["history_keep_last"] = keep

            def run(target):
                target_options = dict(options)
                if args.reasoning and target["size"] > 48:
                    target_options.update(thinking="enabled", max_tokens=8192)
                benchmark.run_local([target], ["deepseek:deepseek-flash"], rounds=args.rounds,
                                    resume=True, session=session, strategies=(args.strategy,),
                                    provider_options=target_options,
                                    log=lambda line: print(line, flush=True)
                                    if line.startswith("  deepseek:") else None)

            print("%s: %d targets" % (session, len(corpus)), flush=True)
            with ThreadPoolExecutor(max_workers=4) as pool:
                list(pool.map(run, corpus))


if __name__ == "__main__":
    main()
