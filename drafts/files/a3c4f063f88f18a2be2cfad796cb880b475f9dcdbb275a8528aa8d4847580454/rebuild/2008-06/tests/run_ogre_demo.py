"""Build/run a one-frame demo using the existing native Ogre trial library."""
import json
import os
from pathlib import Path
import shutil
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild

os.chdir(ROOT)
out = ROOT / "rebuild/2008-06/out/tests/ogre_demo"
out.mkdir(parents=True, exist_ok=True)
plugin = Path(sys.argv[1]).resolve() if len(sys.argv) > 1 else ROOT / "clients/2008-06/rggl.dll"
if not plugin.is_file():
    raise SystemExit("Pass the original 2008-06 rggl.dll path.")
shutil.copy2(plugin, out / plugin.name)
base = ROOT / "rebuild/2008-06/out"
spec = rebuild.load_module("2008-06", "ogre-native-rbx-trial")
includes = [ROOT / p for p in spec["layers"][0]["extra_includes"]]
libs = [base / rebuild.load_module("2008-06", p)["name"] / "linked/linked.lib"
        for p in ("ogre-native-rbx-trial", "g3d", "boost", "zlib-winapi")]
libs = [p for p in libs if p.is_file()]
libs += [base / "importlibs/rgmain.lib", "msvcprt.lib", ROOT / "tools/openrbx/3rdparty/Microsoft DirectX SDK (November 2007)/Lib/x86/dxguid.lib"]
result = rebuild.link_test("2008-06", "ogre_demo", libs, includes=includes,
    run_args=[str(out / plugin.name), "--smoke"], run_dlls=["rgmain.dll"])
(out / "report.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result, indent=2))
raise SystemExit(0 if result.get("exit") == 0 else 1)
