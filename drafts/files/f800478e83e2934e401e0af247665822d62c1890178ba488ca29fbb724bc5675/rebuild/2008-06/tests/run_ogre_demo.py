"""Build, smoke-test, optionally open the recovered-renderer castle demo."""
import argparse
import json
import os
from pathlib import Path
import shutil
import sys
import subprocess

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild

os.chdir(ROOT)
out = ROOT / "rebuild/2008-06/out/tests/ogre_demo"
out.mkdir(parents=True, exist_ok=True)
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("plugin", nargs="?", type=Path)
parser.add_argument("--open", action="store_true", help="Open the interactive demo after its smoke test")
args = parser.parse_args()
plugin = args.plugin.resolve() if args.plugin else out / "rggl.dll"
if not plugin.is_file():
    raise SystemExit("Pass the original 2008-06 rggl.dll path.")
if plugin != out / plugin.name:
    shutil.copy2(plugin, out / plugin.name)
base = ROOT / "rebuild/2008-06/out"
spec = rebuild.load_module("2008-06", "ogre-native-rbx-trial")
includes = [ROOT / p for p in (
    "tools/libs/ogre-1.4.5/ogrenew/OgreMain/include",
    "rebuild/2008-06/native-headers",
    "tools/rbxgs/Client/Rendering/g3d/include",
    "tools/rbxgs/Client/boost_1_34_1/src")]
libs = [base / rebuild.load_module("2008-06", p)["name"] / "linked/linked.lib"
        for p in ("ogre-native-rbx-trial", "g3d", "boost", "zlib-winapi")]
libs = [p for p in libs if p.is_file()]
libs += [base / "importlibs/rgmain.lib", "msvcprt.lib", ROOT / "tools/openrbx/3rdparty/Microsoft DirectX SDK (November 2007)/Lib/x86/dxguid.lib"]
os.chdir(out)
result = rebuild.link_test("2008-06", "ogre_demo", libs, includes=includes,
    run_args=[str(out / plugin.name), "--smoke"], run_dlls=["rgmain.dll"])
(out / "report.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result, indent=2))
if result.get("exit") == 0:
    from PIL import Image
    with Image.open(out / "castle_island.png") as frame:
        if len(frame.getcolors(frame.width * frame.height)) < 20:
            raise SystemExit("Smoke frame is blank or missing geometry.")
    if args.open:
        with (out / "interactive.log").open("w") as log:
            subprocess.Popen([str(out / "ogre_demo.exe"), str(out / plugin.name)],
                             cwd=out, stdout=log, stderr=subprocess.STDOUT)
raise SystemExit(0 if result.get("exit") == 0 else 1)
