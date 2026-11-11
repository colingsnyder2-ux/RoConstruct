#!/usr/bin/env python3
"""Build deterministic native-bulk manifest after Connector ABI provider repair."""
import argparse
import json
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--differs", required=True)
    ap.add_argument("--closure", required=True)
    ap.add_argument("--output", required=True)
    ap.add_argument("--root", default="rebuild/2008-06/native-classes")
    args = ap.parse_args()
    raw = json.loads(Path(args.differs).read_text())
    rows = raw.get("rows", raw) if isinstance(raw, dict) else raw
    names = set()
    for row in rows:
        declared = row.get("declared", "")
        if declared.startswith("Connector::"):
            names.update(row.get("sources", []))
    root = Path(args.root)
    sources, missing = [], []
    for name in sorted(names):
        path = root / (name + ".cpp")
        if path.is_file():
            sources.append(path.as_posix())
        else:
            missing.append(name)
    if missing:
        raise SystemExit("missing native sources: " + ", ".join(missing))
    out = {
        "client": "2008-06",
        "families": [{
            "name": "connector-provider-reproof",
            "sources": sources,
            "evidence": [args.closure],
        }],
        "metadata": {
            "reason": "target-proved six-slot RBX::Connector provider",
            "vftable_rows": sum(1 for r in rows if r.get("declared", "").startswith("Connector::")),
            "source_count": len(sources),
        },
    }
    Path(args.output).write_text(json.dumps(out, indent=2) + "\n")
    print("connector reproof sources=%d vftable_rows=%d" % (
        len(sources), out["metadata"]["vftable_rows"]))


if __name__ == "__main__":
    main()
