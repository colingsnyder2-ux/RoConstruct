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
parser.add_argument("--sky-assets", type=Path, default=Path("C:/Users/colin/OneDrive/Desktop/June 22 (0.3.809.0)/content/sky"))
args = parser.parse_args()
plugin = args.plugin.resolve() if args.plugin else out / "rggl.dll"
if not plugin.is_file():
    raise SystemExit("Pass the original 2008-06 rggl.dll path.")
if plugin != out / plugin.name:
    shutil.copy2(plugin, out / plugin.name)
base = ROOT / "rebuild/2008-06/out"
assets = out / "assets"
assets.mkdir(exist_ok=True)
for name in ("sun.jpg", "moon.jpg", "sun-rays.jpg", *("null_plainsky512_" + side + ".jpg" for side in ("fr", "bk", "lf", "rt", "up", "dn"))):
    source = args.sky_assets / name.replace("_fr.jpg", "_ft.jpg")
    shutil.copy2(source, assets / name)
from PIL import Image, ImageDraw, ImageFont
panel = Image.new("RGBA", (600, 136), (12, 24, 38, 220))
draw = ImageDraw.Draw(panel)
draw.rounded_rectangle((0, 0, 599, 135), radius=12, outline=(100, 190, 185), width=2)
font = ImageFont.truetype("C:/Windows/Fonts/segoeui.ttf", 18)
title = ImageFont.truetype("C:/Windows/Fonts/segoeuib.ttf", 25)
draw.text((20, 12), "CASTLE ISLAND / RBX OGRE", font=title, fill=(238, 225, 193))
draw.text((20, 50), "DRAG orbit   WHEEL zoom   SPACE auto orbit", font=font, fill="white")
draw.text((20, 78), "D day cycle   T +3 hours   S shadows   W wireframe", font=font, fill="white")
draw.text((20, 106), "H HUD   R camera reset   ESC exit", font=font, fill=(120, 215, 195))
panel.save(assets / "castle_hud.png")
spec = rebuild.load_module("2008-06", "ogre-native-rbx-trial")
includes = [ROOT / p for p in (
    "tools/libs/ogre-1.4.5/ogrenew/OgreMain/include",
    "rebuild/2008-06/native-headers",
    "tools/rbxgs/Client/Rendering/g3d/include",
    "tools/rbxgs/Client/boost_1_34_1/src")]
libs = [base / rebuild.load_module("2008-06", p)["name"] / "linked/linked.lib"
        for p in ("ogre-real-provider-1112", "g3d-gl", "g3d", "boost", "zlib-winapi")]
libs = [p for p in libs if p.is_file()]
libs += [base / "importlibs/rgmain.lib", "msvcprt.lib", ROOT / "tools/openrbx/3rdparty/Microsoft DirectX SDK (November 2007)/Lib/x86/dxguid.lib"]
os.chdir(out)
result = rebuild.link_test("2008-06", "ogre_demo", libs, includes=includes,
    defines="WIN32 NDEBUG _MBCS _CRT_SECURE_NO_WARNINGS BOOST_ALL_NO_LIB",
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
