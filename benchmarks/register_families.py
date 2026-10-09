"""Preseed server strict family fingerprints without mining jobs."""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import families, match, worker


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--server", required=True)
    ap.add_argument("--client", required=True)
    ap.add_argument("--token")
    ap.add_argument("--batch", type=int, default=500)
    ap.add_argument("--index", type=Path,
                    help="write reusable strict fingerprint index JSONL")
    args = ap.parse_args()
    rows = []
    for addr, row in match._functions(args.client).items():
        code, _, _ = match.target(args.client, addr)
        rows.append({"client": args.client, "addr": addr,
                     "family": families.fingerprint(row, match.disasm(code, int(addr, 16)))})
    index = args.index or (Path("work") / ("family-index-%s.jsonl" % args.client))
    index.parent.mkdir(parents=True, exist_ok=True)
    index.write_text("".join(json.dumps(row, separators=(",", ":")) + "\n" for row in rows),
                     encoding="utf8")
    api = worker.Api(args.server, args.token)
    registered = 0
    for start in range(0, len(rows), args.batch):
        registered += api.call("/v1/families", {"rows": rows[start:start + args.batch]})["registered"]
    print(json.dumps({"client": args.client, "functions": len(rows), "registered": registered,
                      "index": str(index)}))


if __name__ == "__main__":
    main()
