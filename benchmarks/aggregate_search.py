"""Aggregate completed mass-search arms into per-target winners."""
import argparse
import json
from pathlib import Path


def aggregate(root):
    jobs = {}
    for path in root.glob("**/*.json"):
        if path.name in ("report.json", "manifest.json", "verified-exacts.json"):
            continue
        try:
            row = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            continue
        if not isinstance(row, dict) or "client" not in row or "addr" not in row or "score" not in row:
            continue
        key = row["client"], row["addr"]
        jobs.setdefault(key, []).append({"score": row["score"], "strategy": row.get("strategy"),
                                         "session": row.get("session"), "source": str(path.with_suffix(".cpp"))})
    winners = []
    for (client, addr), rows in sorted(jobs.items()):
        winner = max(rows, key=lambda row: row["score"])
        winners.append({"client": client, "addr": addr, "best_score": winner["score"],
                        "winner": winner, "trials": len(rows),
                        "exact_trials": sum(row["score"] == 100 for row in rows)})
    return winners


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    rows = aggregate(args.root)
    args.output.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print("targets=%d exact=%d trials=%d" % (len(rows), sum(row["best_score"] == 100 for row in rows),
                                               sum(row["trials"] for row in rows)))


if __name__ == "__main__":
    main()
