"""Link out/p6/Roblox.exe: MFC client, RTM appmodul.cpp, original resources, and
the player's engine libraries, read from a finished player build."""
import shutil, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import rebuild
import gen_res

client = "2008-06"
SNAPSHOT = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(r"C:\Users\colin\RoConstruct\rebuild\2008-06\out")
out = rebuild.workspace(client) / "out" / "p6"
out.mkdir(parents=True, exist_ok=True)
tc = rebuild.toolchain()
gen_res.generate(str(ROOT / "clients" / client / "Roblox.exe"), str(out / "roblox.res"))
shutil.copyfile(rebuild.mfc_import_lib(client), out / "mfc90.lib")
mfc = ROOT / "tools" / "libs" / "mfc-9.0-rtm" / "atlmfc" / "include"
spec = rebuild.load_module(client, "player")

libs, pending = [SNAPSHOT / spec["name"] / "linked" / "linked.lib"], list(spec["depends"])
while pending:
    dep = rebuild.load_module(client, pending.pop(0))
    lib = SNAPSHOT / dep["name"] / "linked" / "linked.lib"
    if lib not in libs:
        libs.append(lib)
        pending += dep.get("depends", [])
libs.append(SNAPSHOT / "XTP" / "linked" / "linked.lib")
libs += [rebuild.dll_import_lib(client, dll) for dll in spec["import_dlls"]]

# Same overlay-first include order the player test compiles with.
overlay = SNAPSHOT / spec["name"] / "overlay"
tree = ROOT / "tools" / "rbxgs" / "Client"
includes = []
for item in spec["test_includes"]:
    path = rebuild._spec_path(client, item)
    if path.is_relative_to(tree) and (overlay / path.relative_to(tree)).exists():
        includes.append(overlay / path.relative_to(tree))
    includes.append(path)

xtp = ROOT / "tools" / "libs" / "xtp-11.2.2" / "Source"
mfc_flags = ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD", "/DWIN32", "/DNDEBUG", "/D_MBCS", "/D_AFXDLL", "/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK",
             "/I" + str(mfc), "/I" + str(xtp)]
units = [("RobloxShell.obj", HERE / "RobloxShell.cpp", mfc_flags + ["/I" + str(HERE)]),
         ("appmodul.obj", mfc.parent / "src" / "mfc" / "appmodul.cpp", mfc_flags + ["/I" + str(mfc.parent / "src" / "mfc")]),  # WinMain, AfxInitialize
         ("P6Engine.obj", HERE / "P6Engine.cpp", ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD"] + ["/D" + d for d in spec["test_defines"].split()]
          + ["/I" + str(HERE)] + ["/I" + str(i) for i in includes])]
# P6Data.cpp shares the player engine layer's headers, defines and overlay.
from roc import libs as recipes
engine = spec["layers"][0]
recipe = recipes.RECIPES[engine["includes_from_recipe"]]
data_includes = [(recipes.LIBS / i).resolve() for i in recipe["include"] if i != "WINSDK"] + [(ROOT / i).resolve() for i in engine["extra_includes"]]
data_defines = (recipes.RECIPES[engine["defines_from_recipe"]]["defines"] + " " + engine["extra_defines"]).strip()
built = rebuild.compile_direct(client, [HERE / "P6Data.cpp"], out, data_includes, data_defines, engine["flags"],
                               overlay=rebuild.build_overlay(client, spec["name"], spec["overlay"]))
for ok, message in built.values():
    print(message[-2500:] if message else "")
    if not ok:
        sys.exit(1)

for obj, source, flags in units:
    code, text = rebuild.run(tc, "cl", flags + ["/Fo" + obj, str(source)], out)
    print(text[-2500:])
    if code:
        sys.exit(code)
system = ["kernel32", "user32", "gdi32", "advapi32", "shell32", "ole32", "oleaut32", "comdlg32", "comctl32", "ws2_32", "winmm",
          "opengl32", "glu32", "imagehlp", "version", "wininet", "dbghelp", "psapi"]
code, text = rebuild.run(tc, "link", ["/nologo", "/SUBSYSTEM:WINDOWS", "/MACHINE:X86", "/MAP:Roblox.map", "/OUT:Roblox.exe",
                                      "/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO"] + [u[0] for u in units] + ["P6Data.obj", "roblox.res", "mfc90.lib"]
                         + [str(l) for l in libs] + [s + ".lib" for s in system]
                         + ["/NODEFAULTLIB:" + l for l in rebuild.VENDOR_AUTOLINK], out)
print(text[-3500:])
sys.exit(code)
