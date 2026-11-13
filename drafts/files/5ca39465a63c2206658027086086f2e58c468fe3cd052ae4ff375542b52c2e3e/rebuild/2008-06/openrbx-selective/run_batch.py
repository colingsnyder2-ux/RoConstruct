"""Run a selective trial and its ownership/runtime gates against a frozen baseline."""
import argparse
import json
import os
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
parser = argparse.ArgumentParser()
parser.add_argument("baseline", type=Path, help="directory with frozen report.json and owned-symbols.json")
parser.add_argument("--fast", action="store_true", help="diagnostic build only; skips ownership scoring and runtime gates")
args = parser.parse_args()
for filename in ("report.json", "owned-symbols.json"):
    if not (args.baseline / filename).is_file():
        parser.error("missing baseline " + filename)
out = ROOT / "rebuild/2008-06/out/RbxgsAppOpenRBXSelective"
if args.baseline.resolve() == out.resolve():
    parser.error("baseline must be a frozen copy outside the trial output directory")
baseline = json.loads((args.baseline / "report.json").read_text())
if not baseline.get("linked") or baseline.get("test_exit") != 0 or not baseline.get("owned_addrs"):
    parser.error("baseline must be a linked, scored, smoke-tested report")
env = os.environ.copy()
if args.fast:
    env["ROC_FAST"] = "1"
else:
    env.pop("ROC_FAST", None)
result = subprocess.run([sys.executable, str(HERE / "run_trial.py")], cwd=ROOT, env=env)
if result.returncode:
    raise SystemExit(result.returncode)
if args.fast:
    print("Diagnostic only: ownership and runtime gates were skipped.")
    raise SystemExit(0)
raise SystemExit(subprocess.call([sys.executable, str(HERE / "verify_trial.py"), str(args.baseline.resolve())], cwd=ROOT))
