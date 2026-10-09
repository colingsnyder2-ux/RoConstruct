"""Run one model arm against a frozen holdout manifest."""
import argparse
import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--model", required=True)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--strategy", choices=("direct", "structured"), default="direct")
    parser.add_argument("--session", default="holdout-" + time.strftime("%Y%m%d-%H%M%S"))
    parser.add_argument("--allow-cloud", action="store_true")
    args = parser.parse_args()
    rows = json.loads(args.manifest.read_text(encoding="utf-8"))
    print("Holdout: %d targets, model=%s, strategy=%s, session=%s" %
          (len(rows), args.model, args.strategy, args.session))
    benchmark.run_local(rows, [args.model], rounds=args.rounds, session=args.session,
                        strategies=(args.strategy,), provider_options={
                            "allow_cloud": args.allow_cloud})


if __name__ == "__main__":
    main()
