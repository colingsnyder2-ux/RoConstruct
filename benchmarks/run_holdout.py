"""Run one model arm against a frozen holdout manifest."""
import argparse
import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, metrics, providers


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--model", required=True)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--strategy", choices=("auto", "direct", "structured"), default="direct")
    parser.add_argument("--session", default="holdout-" + time.strftime("%Y%m%d-%H%M%S"))
    parser.add_argument("--allow-cloud", action="store_true")
    parser.add_argument("--max-tokens", type=int,
                        help="output token budget per generation round (default: size-based ladder)")
    parser.add_argument("--seed", type=int,
                        help="sampling seed, recorded per job (best-effort per provider)")
    parser.add_argument("--thinking", choices=("auto", "enabled", "disabled"),
                        default="auto",
                        help="reasoning mode; auto disables thinking only for tiny targets")
    parser.add_argument("--max-cloud-requests", type=int, default=150)
    parser.add_argument("--max-cloud-tokens", type=int, default=250000)
    parser.add_argument("--max-cloud-cost", type=float)
    args = parser.parse_args()
    rows = json.loads(args.manifest.read_text(encoding="utf-8"))
    if providers.is_cloud(args.model) and args.allow_cloud and args.max_cloud_cost is None:
        raise SystemExit("cloud holdout requires --max-cloud-cost")
    budget = providers.CloudBudget(args.max_cloud_requests, args.max_cloud_tokens,
                                   args.max_cloud_cost)
    gate = providers.CloudGate(1)
    if providers.is_cloud(args.model) and args.allow_cloud:
        try:
            providers.generate(args.model, "Reply OK.", options={
                "allow_cloud": True, "max_tokens": 1, "budget": budget, "gate": gate})
        except Exception as error:
            raise SystemExit("cloud preflight failed: %s" % error)
    provider_options = {"allow_cloud": args.allow_cloud, "budget": budget, "gate": gate}
    if args.max_tokens:
        provider_options["max_tokens"] = args.max_tokens
    if args.seed is not None:
        provider_options["seed"] = args.seed
    if args.thinking != "auto":
        provider_options["thinking"] = args.thinking
    print("Holdout: %d targets, model=%s, strategy=%s, session=%s, rounds=%d, max_tokens=%s, seed=%s, thinking=%s" %
          (len(rows), args.model, args.strategy, args.session, args.rounds,
           args.max_tokens or "size-ladder", args.seed, args.thinking))
    metrics.record(args.session, event="benchmark_start", manifest=str(args.manifest),
                   model=args.model, strategy=args.strategy, rounds=args.rounds,
                   max_tokens=args.max_tokens, seed=args.seed, thinking=args.thinking,
                   targets=len(rows),
                   cloud_tokens_cap=args.max_cloud_tokens,
                   cloud_requests_cap=args.max_cloud_requests,
                   max_cloud_cost=args.max_cloud_cost)
    benchmark.run_local(rows, [args.model], rounds=args.rounds, session=args.session,
                        strategies=(args.strategy,), provider_options=provider_options)


if __name__ == "__main__":
    main()
