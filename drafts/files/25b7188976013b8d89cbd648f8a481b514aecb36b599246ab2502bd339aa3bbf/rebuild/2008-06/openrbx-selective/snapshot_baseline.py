"""Freeze a fully verified trial as a baseline for the next batch."""
import hashlib
import json
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "rebuild/2008-06/out/RbxgsAppOpenRBXSelective"
if len(sys.argv) != 2:
    raise SystemExit("usage: python snapshot_baseline.py NEW_DIRECTORY")
destination = Path(sys.argv[1]).resolve()
if destination == OUT.resolve() or OUT.resolve() in destination.parents:
    raise SystemExit("Baseline must be outside the trial output directory")
receipt = json.loads((OUT / "batch-verification.json").read_text())
if receipt.get("lost") or not all(receipt.get("milestones", {}).get(k) for k in ("M2", "M4a", "M5")):
    raise SystemExit("Last trial did not pass all required gates")
for name in ("report.json", "owned-symbols.json", "milestones.json"):
    digest = hashlib.sha256((OUT / name).read_bytes()).hexdigest()
    if receipt.get("sha256", {}).get(name) != digest:
        raise SystemExit("Trial output changed since verification: " + name)
destination.mkdir(parents=True, exist_ok=False)
for name in ("report.json", "owned-symbols.json", "milestones.json", "batch-verification.json"):
    shutil.copy2(OUT / name, destination / name)
print("Frozen baseline:", destination)
