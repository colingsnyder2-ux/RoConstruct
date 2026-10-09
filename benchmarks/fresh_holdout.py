"""Freeze deterministic, never-used benchmark targets before model generation."""
import argparse
import hashlib
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, metrics


def used_targets(metrics_path):
    used = set()
    try:
        for line in metrics_path.read_text(encoding="utf-8").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("event") == "job":
                used.add((row.get("client"), row.get("addr")))
    except OSError:
        pass
    return used


def select(count, metrics_path=metrics.PATH):
    used = used_targets(metrics_path)
    groups = defaultdict(list)
    for row in benchmark.build_hidden(100000, persist=False):
        key = (row.get("client"), row.get("addr"))
        if key in used or row.get("source_present"):
            continue
        groups[(row["client"], row["bucket"])].append(row)
    for rows in groups.values():
        rows.sort(key=lambda row: hashlib.sha256(
            (row["client"] + row["addr"]).encode()).hexdigest())
    selected = []
    keys = sorted(groups)
    while len(selected) < count and keys:
        progressed = False
        for key in keys:
            if groups[key] and len(selected) < count:
                selected.append(groups[key].pop(0))
                progressed = True
        if not progressed:
            break
    return selected


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--count", type=int, default=100)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--metrics", type=Path, default=metrics.PATH)
    args = parser.parse_args()
    if args.count < 1:
        raise SystemExit("count must be positive")
    rows = select(args.count, args.metrics)
    if len(rows) != args.count:
        raise SystemExit("only %d unseen targets available" % len(rows))
    args.output.write_text(json.dumps(rows, indent=1) + "\n", encoding="utf-8")
    fingerprint = hashlib.sha256(json.dumps(
        [(row["client"], row["addr"]) for row in rows], separators=(",", ":")).encode()).hexdigest()
    print("froze %d unseen targets; sha256=%s" % (len(rows), fingerprint))


if __name__ == "__main__":
    main()
