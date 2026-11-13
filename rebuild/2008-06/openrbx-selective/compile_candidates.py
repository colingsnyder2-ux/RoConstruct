"""Compile donor candidates once with the trial's 2008 recipe and isolated overlay."""
import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild
from roc.native_drafts import lock

parser = argparse.ArgumentParser()
parser.add_argument("sources", type=Path, nargs="+")
parser.add_argument("--out", type=Path, default=ROOT / "work/openrbx-selective-codex/candidate-objects")
args = parser.parse_args()
sources = [path.resolve() for path in args.sources]
if len({path.stem.lower() for path in sources}) != len(sources):
    parser.error("candidate source basenames must be unique")
if any(not path.is_file() for path in sources):
    parser.error("all candidate sources must exist")
spec = rebuild.load_module("2008-06", "rbxgs-app-openrbx-selective")
recipe = libs.RECIPES["rbxgs"]
with lock(ROOT / "work/openrbx-selective-codex/candidate-compile.lock"):
    overlay = rebuild.build_overlay("2008-06", "RbxgsAppOpenRBXProbe", spec.get("overlay"))
    results = rebuild.compile_direct("2008-06", sources, args.out,
        [(libs.LIBS / folder).resolve() for folder in recipe["include"] if folder != "WINSDK"],
        recipe["defines"] + " BOOST_ALL_NO_LIB", "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", overlay=overlay)
failed = False
for name, (ok, message) in results.items():
    print(Path(name).name, "OK" if ok else message)
    failed |= not ok
raise SystemExit(1 if failed else 0)
