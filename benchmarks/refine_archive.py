"""Reverify and refine a frozen snapshot of archived matching candidates."""
import argparse
import hashlib
import json
import time
from pathlib import Path

from roc import match, mutate


def select(root, minimum):
    best = {}
    for path in sorted(root.glob("**/*.json")):
        try:
            row = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            continue
        if not isinstance(row, dict) or "source_sha256" not in row:
            continue
        score = row.get("score", row.get("after", 0))
        if score < minimum:
            continue
        source = path.with_suffix(".cpp").read_text(encoding="utf-8")
        if hashlib.sha256(source.encode()).hexdigest() != row["source_sha256"]:
            raise ValueError("candidate hash mismatch: %s" % path)
        key = row["client"], row["addr"]
        row["score"] = score
        if key not in best or score > best[key][0]["score"]:
            best[key] = row, source, path
    return sorted(best.values(), key=lambda item: (-item[0]["score"], item[0]["client"], item[0]["addr"]))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--minimum", type=int, default=85)
    parser.add_argument("--limit", type=int, default=150)
    parser.add_argument("--unguided", action="store_true")
    args = parser.parse_args()
    selected = select(args.archive, args.minimum)[:args.limit]
    args.output.mkdir(parents=True, exist_ok=False)
    report = []
    for row, source, path in selected:
        client, addr, flags = row["client"], row["addr"], row.get("compiler_flags")
        started = time.monotonic()
        before = match.check_text(client, addr, source, flags)[0]
        result = mutate.improve(client, addr, source, flags, guided=not args.unguided, permute=True)
        trials = list(result.mutations)
        if before < result[0] < 100:
            chained = mutate.improve(client, addr, result[1], flags, guided=not args.unguided, permute=True)
            trials.extend(chained.mutations)
            if chained[0] > result[0]:
                result = chained
        after = match.check_text(client, addr, result[1], flags)[0]
        output = args.output / client
        output.mkdir(exist_ok=True)
        output.joinpath(addr + ".cpp").write_text(result[1], encoding="utf-8")
        record = {"client": client, "addr": addr, "archive_score": row["score"],
                  "before": before, "after": after, "source": str(path.resolve()),
                  "compiler_flags": flags, "mutations": trials,
                  "source_sha256": hashlib.sha256(result[1].encode()).hexdigest(),
                  "seconds": round(time.monotonic() - started, 2)}
        output.joinpath(addr + ".json").write_text(json.dumps(record, indent=1), encoding="utf-8")
        report.append(record)
        args.output.joinpath("report.json").write_text(json.dumps(report, indent=1), encoding="utf-8")
        print("%s %s %d -> %d (%d trials)" % (client, addr, before, after, len(trials)), flush=True)
    print("Verified %d exacts; %d improvements" % (
        sum(row["after"] == 100 for row in report),
        sum(row["after"] > row["before"] for row in report)), flush=True)


if __name__ == "__main__":
    main()
