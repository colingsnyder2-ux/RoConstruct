"""Compiler-gated deterministic family-source propagation replay."""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import auto, benchmark, families, match, metrics


def source_for(session, addr):
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
    ap = argparse.ArgumentParser()
    ap.add_argument("--client", required=True)
    ap.add_argument("--unit", required=True)
    ap.add_argument("--representative-session", required=True)
    ap.add_argument("--output", type=Path, required=True)
    ap.add_argument("--recursive", action="store_true", help="propagate newly exact siblings, max depth 3")
    args = ap.parse_args()
    rows = [r for r in benchmark.build_hidden(100000, persist=False)
            if r.get("client") == args.client and r.get("unit") == args.unit]

    def disassemble(row):
        code, _, _ = match.target(args.client, row["addr"])
        return match.disasm(code, int(row["addr"], 16))

    totals = {"families": 0, "verified_families": 0, "siblings": 0,
              "rewritten": 0, "compiled": 0, "exact": 0, "conversions": 0}
    details = []
    for key, representative, members in families.representatives(rows, disassemble):
        source = source_for(args.representative_session, representative["addr"])
        totals["families"] += 1
        if not source:
            continue
        totals["verified_families"] += 1
        family = {"representative": representative["addr"], "members": 0,
                  "rewritten": 0, "compiled": 0, "exact": 0}
        pending = [row for row in members if row["addr"] != representative["addr"]]
        totals["siblings"] += len(pending)
        family["members"] += len(pending)
        exemplars, depth = [source], {}
        for pass_no in range(1, 4 if args.recursive else 2):
            next_pending = []
            for row in pending:
                code, _, _ = match.target(args.client, row["addr"])
                asm = match.disasm(code, int(row["addr"], 16))
                candidate = next((auto.family_propagate(asm, ex) for ex in exemplars
                                  if auto.family_propagate(asm, ex)), None)
                if not candidate:
                    next_pending.append(row)
                    continue
                totals["rewritten"] += 1
                family["rewritten"] += 1
                try:
                    score, _, _, _ = match.check_text(args.client, row["addr"], candidate)
                except match.CompileError:
                    next_pending.append(row)
                    continue
                totals["compiled"] += 1
                family["compiled"] += 1
                if score == 100:
                    totals["exact"] += 1
                    family["exact"] += 1
                    totals["conversions"] += 1
                    depth[row["addr"]] = pass_no
                    exemplars.append(candidate)
                else:
                    next_pending.append(row)
            pending = next_pending
            if not args.recursive or len(pending) == 0:
                break
        family["propagation_depth"] = depth
        details.append(family)
    result = {"client": args.client, "unit": args.unit, "session": args.representative_session,
              "totals": totals, "families": details}
    args.output.write_text(json.dumps(result, indent=1) + "\n", encoding="utf8")
    print(json.dumps(totals, sort_keys=True))


if __name__ == "__main__":
    main()
