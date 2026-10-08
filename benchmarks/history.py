"""Paired DeepSeek history ablation on a fixed, source-hidden corpus.

Run from the repository root: python benchmarks/history.py
"""
import argparse
import hashlib
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
    parser.add_argument("--corpus", type=Path, default=benchmark.HIDDEN)
    parser.add_argument("--client", default="2007-08")
    parser.add_argument("--max-size", type=int)
    parser.add_argument("--model", default="deepseek:deepseek-flash")
    parser.add_argument("--keep", nargs="+", type=int, default=[2, 0])
    parser.add_argument("--repeats", type=int, default=2)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--auto-preset", action="store_true")
    parser.add_argument("--workers", type=int, choices=range(1, 65), default=4, metavar="1-64")
    parser.add_argument("--no-resume", action="store_true")
    parser.add_argument("--reasoning", action="store_true")
    parser.add_argument("--compact-rules", action="store_true")
    parser.add_argument("--binary-only", action="store_true")
    parser.add_argument("--source-hint-max-size", type=int)
    parser.add_argument("--temperature", type=float)
    parser.add_argument("--max-tokens", type=int)
    parser.add_argument("--minimal-layout", action="store_true")
    parser.add_argument("--reset-truncated", action="store_true")
    parser.add_argument("--diverse-candidates", type=int)
    parser.add_argument("--strategy", choices=["direct", "structured", "reference"], default="direct")
    args = parser.parse_args()
    corpus = json.loads(args.corpus.read_text())
    corpus = [row for row in corpus if row["client"] == args.client]
    if args.max_size is not None:
        corpus = [row for row in corpus if row["size"] <= args.max_size]
    if not corpus:
        raise SystemExit("No %s hidden targets; generate the hidden corpus first." % args.client)
    corpus_sha256 = hashlib.sha256(json.dumps(corpus, sort_keys=True).encode()).hexdigest()
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
                       "compact_rules": args.compact_rules, "binary_only": args.binary_only,
                       "minimal_layout": args.minimal_layout, "reset_truncated": args.reset_truncated}
            if args.diverse_candidates is not None:
                options["diverse_candidates"] = args.diverse_candidates
            if keep >= 0:
                options["history_keep_last"] = keep
            if args.temperature is not None:
                options["temperature"] = args.temperature
            if args.max_tokens is not None:
                options["max_tokens"] = args.max_tokens
            if args.source_hint_max_size is not None:
                options["source_hint_max_size"] = args.source_hint_max_size

            def run(target):
                target_options = dict(options)
                if args.reasoning and target["size"] > 48:
                    target_options.update(thinking="enabled", max_tokens=8192)
                rounds = worker.resolve_rounds(target, "auto" if args.auto_preset else args.rounds,
                                              args.model)
                benchmark.run_local([target], [args.model], rounds=rounds,
                                    resume=not args.no_resume, session=session, strategies=(args.strategy,),
                                    provider_options=target_options,
                                    log=lambda line: print(line, flush=True)
                                    if line.startswith("  deepseek:") else None)

            print("%s: %d targets" % (session, len(corpus)), flush=True)
            configuration = {key: value for key, value in options.items() if key != "gate"}
            configuration.update(strategy=args.strategy, reasoning=args.reasoning,
                                 rounds="auto" if args.auto_preset else args.rounds,
                                 client=args.client, model=args.model, max_size=args.max_size)
            metrics.record(session, event="benchmark_start", corpus_sha256=corpus_sha256,
                           configuration=configuration, workers=args.workers,
                           targets=len(corpus), resume=not args.no_resume)
            started = time.monotonic()
            with ThreadPoolExecutor(max_workers=args.workers) as pool:
                list(pool.map(run, corpus))
            elapsed = time.monotonic() - started
            metrics.record(session, event="benchmark_batch", workers=args.workers,
                           targets=len(corpus), rounds="auto" if args.auto_preset else args.rounds,
                           startup_seconds=round(startup, 3),
                           corpus_sha256=corpus_sha256, configuration=configuration,
                           resume=not args.no_resume, seconds=round(elapsed, 3))
            print("%s: %dw batch %.3fs%s" % (session, args.workers, elapsed,
                  " (may include resumed jobs)" if not args.no_resume else ""), flush=True)


if __name__ == "__main__":
    main()
