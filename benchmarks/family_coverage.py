"""Report whole-section family coverage and verified-source status."""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import families, match


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--client", required=True)
    ap.add_argument("--unit", required=True)
    args = ap.parse_args()
    root = Path(__file__).resolve().parents[1] / "work" / args.client
    scores = json.loads((root / "scores.json").read_text())
    rows = []
    for line in (root / "functions.jsonl").read_text(errors="replace").splitlines():
        row = json.loads(line)
        if row.get("kind", "code") == "code" and row.get("unit") == args.unit:
            rows.append(row)

    def disasm(row):
        code, _, _ = match.target(args.client, row["addr"])
        return match.disasm(code, int(row["addr"], 16))

    groups = list(families.representatives(rows, disasm))
    exact = {row["addr"] for row in rows if scores.get(row["addr"]) == 100}
    verified_families = 0
    family_members = 0
    exact_family_members = 0
    for _key, _rep, members in groups:
        if any(row["addr"] in exact for row in members):
            verified_families += 1
            family_members += len(members)
            exact_family_members += sum(row["addr"] in exact for row in members)
    result = {
        "client": args.client,
        "unit": args.unit,
        "functions": len(rows),
        "exact": len(exact),
        "unmatched": len(rows) - len(exact),
        "families": len(groups),
        "family_members": sum(len(members) for _k, _r, members in groups),
        "verified_families": verified_families,
        "members_in_verified_families": family_members,
        "exact_in_verified_families": exact_family_members,
        "family_coverage_pct": round(100 * family_members / len(rows), 2) if rows else 0,
    }
    print(json.dumps(result, sort_keys=True))


if __name__ == "__main__":
    main()
