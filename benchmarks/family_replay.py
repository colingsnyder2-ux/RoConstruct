"""Paired sibling test using verified same-shape family exemplars."""
import argparse
import hashlib
import json
import random
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, families, match, metrics, providers


def metric_source(session, addr):
    try:
        lines = metrics.PATH.read_text(encoding="utf8").splitlines()
    except OSError:
        return None
    for line in lines:
        try:
            row = json.loads(line)
        except ValueError:
            continue
        if row.get("session") != session or row.get("event") != "job" or row.get("addr") != addr:
            continue
        for attempt in row.get("rounds", []):
            if isinstance(attempt, dict) and attempt.get("score") == 100 and attempt.get("source"):
                return attempt["source"]
    return None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--client", default="2007-08")
    parser.add_argument("--unit", default="seg_00770000")
    parser.add_argument("--representative-session", required=True)
    parser.add_argument("--families", type=int, default=5)
    parser.add_argument("--siblings", type=int, default=5)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--max-cloud-requests", type=int, default=60)
    parser.add_argument("--max-cloud-tokens", type=int, default=100000)
    parser.add_argument("--max-cloud-cost", type=float, default=0.50)
    parser.add_argument("--session-prefix", default="family-replay-" + time.strftime("%Y%m%d-%H%M%S"))
    parser.add_argument("--model", default="deepseek:deepseek-flash")
    parser.add_argument("--random-seed", type=int, help="shuffle families/siblings before selection")
    args = parser.parse_args()
    used = set()
    try:
        for line in metrics.PATH.read_text(encoding="utf8").splitlines():
            row = json.loads(line)
            if row.get("event") == "job":
                used.add((row.get("client"), row.get("addr")))
    except (OSError, ValueError):
        pass
    rows = [row for row in benchmark.build_hidden(100000, persist=False)
            if row.get("client") == args.client and row.get("unit") == args.unit]

    def disassemble(row):
        code, _, _ = match.target(args.client, row["addr"])
        return match.disasm(code, int(row["addr"], 16))

    groups = families.representatives(rows, disassemble)
    candidates = []
    for key, representative, members in groups:
        source = metric_source(args.representative_session, representative["addr"])
        if not source:
            continue
        siblings = [row for row in sorted(members, key=lambda row: row["addr"])
                    if row["addr"] != representative["addr"] and
                    (row["client"], row["addr"]) not in used]
        if siblings:
            candidates.append((len(members), key, representative, source, siblings))
    candidates.sort(key=lambda item: (-item[0], item[2]["addr"]))
    if args.random_seed is not None:
        rng = random.Random(args.random_seed)
        rng.shuffle(candidates)
    selected, examples = [], {}
    for _size, key, representative, source, siblings in candidates[:args.families]:
        sibling_rows = list(siblings)
        if args.random_seed is not None:
            random.Random(args.random_seed ^ int(representative["addr"], 16)).shuffle(sibling_rows)
        for row in sibling_rows[:args.siblings]:
            selected.append(row)
            examples[(row["client"], row["addr"])] = (source,)
    args.output.write_text(json.dumps(selected, indent=1) + "\n", encoding="utf8")
    fingerprint = hashlib.sha256(json.dumps(
        [(row["client"], row["addr"]) for row in selected],
        separators=(",", ":")).encode()).hexdigest()
    print("selected %d unseen siblings from %d verified families; sha256=%s" %
          (len(selected), len(candidates), fingerprint))
    if not selected:
        raise SystemExit("no unseen siblings with verified exemplars")
    model = args.model
    is_cloud = providers.is_cloud(model)
    options = {"allow_cloud": is_cloud, "max_tokens": 2048,
               "budget": providers.CloudBudget(args.max_cloud_requests,
                                                 args.max_cloud_tokens,
                                                 args.max_cloud_cost),
               "gate": providers.CloudGate(1), "thinking": "disabled"}
    benchmark.run_local(selected, [model], rounds=args.rounds,
                        session=args.session_prefix + "-direct",
                        strategies=("direct",), provider_options=options)
    benchmark.run_local(selected, [model], rounds=args.rounds,
                        session=args.session_prefix + "-exemplar",
                        strategies=("direct",), provider_options=options,
                        family_examples=examples)


if __name__ == "__main__":
    main()
