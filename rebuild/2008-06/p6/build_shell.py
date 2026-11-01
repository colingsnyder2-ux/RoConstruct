"""Build out/p6/Roblox.exe from RobloxShell.cpp with the period toolchain."""
import shutil, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).parent))
from roc import rebuild
import gen_res

client = "2008-06"
out = rebuild.workspace(client) / "out" / "p6"
out.mkdir(parents=True, exist_ok=True)
tc = rebuild.toolchain()
original = ROOT / "clients" / client
gen_res.generate(str(original / "Roblox.exe"), str(out / "roblox.res"))
shutil.copyfile(rebuild.mfc_import_lib(client), out / "mfc90.lib")
mfc = ROOT / "tools" / "libs" / "mfc-9.0-rtm" / "atlmfc" / "include"
units = {"RobloxShell.obj": Path(__file__).parent / "RobloxShell.cpp",
         "appmodul.obj": mfc.parent / "src" / "mfc" / "appmodul.cpp"}  # 007bca00 WinMain and AfxInitialize, from mfcs90.lib
for obj, source in units.items():
    code, text = rebuild.run(tc, "cl", ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD", "/DWIN32", "/DNDEBUG", "/D_MBCS", "/D_AFXDLL",
                                        "/I" + str(mfc), "/I" + str(source.parent), "/Fo" + obj, str(source)], out)
    print(text[-3000:])
    if code:
        sys.exit(code)
code, text = rebuild.run(tc, "link", ["/nologo", "/SUBSYSTEM:WINDOWS", "/MACHINE:X86", "/MAP:Roblox.map", "/OUT:Roblox.exe",
                                      "/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO", *units, "roblox.res", "mfc90.lib"]
                         + ["user32.lib", "gdi32.lib", "kernel32.lib", "ole32.lib", "oleaut32.lib", "comctl32.lib", "shell32.lib", "advapi32.lib"], out)
print(text[-3000:])
sys.exit(code)
