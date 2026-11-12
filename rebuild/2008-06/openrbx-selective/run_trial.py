"""Build the selective trial using the proven ports trial as its verified baseline."""
import json
import runpy
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild

client = "2008-06"
module = "rbxgs-app-openrbx-selective"
spec = rebuild.load_module(client, module)
out = rebuild.workspace(client) / "out" / spec["name"]
baseline = rebuild.workspace(client) / "out" / "RbxgsAppOpenRBXPorts" / "verified"
if not (baseline / "swaps.json").exists():
    raise RuntimeError("Build the proven RbxgsAppOpenRBXPorts baseline first")
verified = out / "verified"
shutil.copytree(baseline, verified, dirs_exist_ok=True)
# Keep the trial reproducible when rerun after a failed candidate.
for path in verified.glob("selective_*.obj"):
    path.unlink()
overlay = rebuild.build_overlay(client, spec["name"], spec.get("overlay"))
recipe = libs.RECIPES["rbxgs"]
source = ROOT / "rebuild/2008-06/openrbx-selective/gui/ScoreHud.cpp"
result = rebuild.compile_direct(client, [source], out / "selective-source",
    [(libs.LIBS / i).resolve() for i in recipe["include"] if i != "WINSDK"],
    recipe["defines"] + " BOOST_ALL_NO_LIB", "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", overlay=overlay)
if not all(ok for ok, _ in result.values()):
    raise RuntimeError(str(result))
obj = out / "selective-source/ScoreHud.obj"
targets = {
    "??0ScoreHud@RBX@@QAE@PBVServiceProvider@1@@Z": "00652510",
    "?render2d@ScoreHud@RBX@@MAEXPAVAdorn@2@@Z": "00656430",
}
rows = rebuild.pair_object(client, obj.read_bytes(), set(targets))
keep = {s: a[0] for s, _, a in rows if len(a) == 1 and targets.get(s) == a[0]}
if keep != targets:
    raise RuntimeError("Selected ScoreHud functions no longer match their targets")
shutil.copy2(obj, verified / "selective_ScoreHud.obj")
path = verified / "swaps.json"
swaps = json.loads(path.read_text())
swaps["swaps"].append({"obj": "selective_ScoreHud.obj", "recipe": "rbxgs", "file": "gui/ScoreHud.cpp", "keep": keep})
path.write_text(json.dumps(swaps, indent=1) + "\n")
# Module scoring must not trigger unrelated global progress reporting.
rebuild.progress = lambda *args, **kwargs: None
sys.argv = ["roc.py", "rebuild", client, "module", module, "--no-notify"]
runpy.run_path(str(ROOT / "roc.py"), run_name="__main__")
