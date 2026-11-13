"""Refresh the historical 142-file opportunity ranking against a frozen baseline."""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
parser = argparse.ArgumentParser()
parser.add_argument("baseline", type=Path)
parser.add_argument("--output", type=Path)
args = parser.parse_args()
report = json.loads((args.baseline / "report.json").read_text())
if not report.get("linked") or report.get("test_exit") != 0 or not report.get("owned_addrs"):
    raise SystemExit("Baseline must be linked, scored and smoke-tested")
owned = set(report["owned_addrs"])
rank = json.loads((ROOT / "rebuild/2008-06/out/RbxgsAppOpenRBXPorts/ranking.json").read_text())
rows = []
union = set()
for item in rank:
    missing = set(item["unowned"]) - owned
    union.update(missing)
    errors = item["error_count"]
    rows.append({"file": item["file"], "unowned_candidates": len(missing), "original_errors": errors,
                 "estimated_value_per_error": round(len(missing) / max(1, errors), 3)})
rows.sort(key=lambda row: (-row["estimated_value_per_error"], row["file"]))
result = {"scope": "historical 142 files; shared templates and object membership inflate estimates; not guaranteed gains",
          "baseline_owned": len(owned), "distinct_unowned_candidates": len(union), "files": rows}
if args.output:
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({key: result[key] for key in ("scope", "baseline_owned", "distinct_unowned_candidates")}, indent=2))
for row in rows[:15]:
    print(row["file"], row["unowned_candidates"], "/", row["original_errors"], "=", row["estimated_value_per_error"])
