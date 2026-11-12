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
sources = {
    "gui/ScoreHud.cpp": {
        "??0ScoreHud@RBX@@QAE@PBVServiceProvider@1@@Z": "00652510",
        "?render2d@ScoreHud@RBX@@MAEXPAVAdorn@2@@Z": "00656430",
    },
    "v8xml/SerializerSelected.cpp": {
        "?resolveIDREF@ArchiveBinder@@QAE_NUIDREFBinding@1@@Z": "00592180",
        "?processID@ArchiveBinder@@UAE_NPBVXmlNameValuePair@@PAVInstance@RBX@@@Z": "005930c0",
    },
    "v8datamodel/PVInstanceSelected.cpp": {
        "?computeTopPVController@PVInstance@RBX@@ABE?AV?$ReferenceCountedPointer@VController@RBX@@@G3D@@XZ": "00609690",
    },
    "script/ScriptContextSelected.cpp": {
        "?addScript@ScriptContext@RBX@@QAEXPAVScript@2@@Z": "005b06c0",
    },
    "util/NormalIdSelected.cpp": {
        "?normalIdToVector3Internal@RBX@@YA?AVVector3@G3D@@W4NormalId@1@@Z": "005ec240",
        "?Vector3ToNormalId@RBX@@YA?AW4NormalId@1@ABVVector3@G3D@@@Z": "005ec290",
        "?normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@1@@Z": "005ec570",
        "?normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@1@@Z": "005ec800",
    },
    "v8datamodel/ToolSelected.cpp": {
        "?readProperty@Tool@RBX@@EAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z": "005fd3e0",
    },
    "v8datamodel/AccoutrementSelected.cpp": {
        "?readProperty@Accoutrement@RBX@@MAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z": "005b0840",
    },
    "v8datamodel/LocakBackpackSelected.cpp": {
        "?removeBackpackItem@LocalBackpack@RBX@@AAEXPAVBackpackItem@2@@Z": "005fbc80",
    },
    "v8kernel/KernelSelected.cpp": {
        "?deletePoint@Kernel@RBX@@QAEXPAVPoint@2@@Z": "005fb3c0",
    },
}
source_root = ROOT / "rebuild/2008-06/openrbx-selective"
result = rebuild.compile_direct(client, [source_root / f for f in sources], out / "selective-source",
    [(libs.LIBS / i).resolve() for i in recipe["include"] if i != "WINSDK"],
    recipe["defines"] + " BOOST_ALL_NO_LIB", "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", overlay=overlay)
if not all(ok for ok, _ in result.values()):
    raise RuntimeError(str(result))
path = verified / "swaps.json"
swaps = json.loads(path.read_text())
for file, targets in sources.items():
    obj = out / "selective-source" / (Path(file).stem + ".obj")
    rows = rebuild.pair_object(client, obj.read_bytes(), set(targets))
    keep = {s: a[0] for s, _, a in rows if len(a) == 1 and targets.get(s) == a[0]}
    if keep != targets:
        raise RuntimeError("Selected functions no longer match their targets: " + file)
    obj_name = "selective_" + obj.name
    shutil.copy2(obj, verified / obj_name)
    swaps["swaps"].append({"obj": obj_name, "recipe": "rbxgs", "file": file, "keep": keep})
path.write_text(json.dumps(swaps, indent=1) + "\n")
# Module scoring must not trigger unrelated global progress reporting.
rebuild.progress = lambda *args, **kwargs: None
sys.argv = ["roc.py", "rebuild", client, "module", module, "--no-notify"]
runpy.run_path(str(ROOT / "roc.py"), run_name="__main__")
