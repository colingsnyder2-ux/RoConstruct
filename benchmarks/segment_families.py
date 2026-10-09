"""Freeze repeated opcode-shape representatives for a client/segment."""
import argparse
import hashlib
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, families, match


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--client", required=True)
    parser.add_argument("--unit", default="seg_00770000")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--minimum", type=int, default=2)
    args = parser.parse_args()
    rows = [row for row in benchmark.build_hidden(100000, persist=False)
            if row.get("client") == args.client and row.get("unit") == args.unit]

    def disassemble(row):
        code, _, _ = match.target(args.client, row["addr"])
        return match.disasm(code, int(row["addr"], 16))

    grouped = families.representatives(rows, disassemble, args.minimum)
    selected = []
    for key, representative, members in grouped:
        selected.append({**representative, "family_size": len(members),
                         "family_shape": list(key[1])})
    args.output.write_text(json.dumps(selected, indent=1) + "\n", encoding="utf-8")
    fingerprint = hashlib.sha256(json.dumps(
        [(row["client"], row["addr"]) for row in selected],
        separators=(",", ":")).encode()).hexdigest()
    print("%s: %d functions, %d repeated families, %d representatives, sha256=%s" %
          (args.client, len(rows), len(grouped), len(selected), fingerprint))


if __name__ == "__main__":
    main()
