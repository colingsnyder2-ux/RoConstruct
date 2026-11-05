import sys,re,importlib.util,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[4]
sys.path.insert(0,str(ROOT))
from roc import rebuild,libs
sp=importlib.util.spec_from_file_location("native_runner",ROOT/"rebuild/2008-06/tests/native_check_runner.py")
r=importlib.util.module_from_spec(sp);sp.loader.exec_module(r)
spec=rebuild.load_module("2008-06","player")
base=ROOT/"rebuild/2008-06";here=base/"p6"
snapshot=rebuild.workspace("2008-06")/"out"
overlay=snapshot/spec["name"]/"overlay";tree=ROOT/"tools/rbxgs/Client"
includes=[]
for item in spec["test_includes"]:
 path=rebuild._spec_path("2008-06",item)
 if path.is_relative_to(tree) and (overlay/path.relative_to(tree)).exists():includes.append(overlay/path.relative_to(tree))
 includes.append(path)
engine=spec["layers"][0]
defines=(libs.RECIPES[engine["defines_from_recipe"]]["defines"]+" "+engine["extra_defines"]).strip()
headers=base/"native-headers";mfc=ROOT/"tools/libs/mfc-9.0-rtm/atlmfc/include";xtp=ROOT/"tools/libs/xtp-11.2.2/Source"
def flags(source):
 pinned=re.search(r"^// native-flags: (.*)$",source.read_text(encoding="utf-8-sig"),re.M)
 if pinned:
  return ["/nologo","/c"]+pinned[1].replace("{headers}",str(headers)).split()+["/DBOOST_ALL_NO_LIB","/D_XTP_STATICLINK","/D_XTPLIB_NOAUTOLINK"]+["/D"+d for d in defines.split()]+["/I"+str(i) for i in [headers,mfc,xtp]+includes]
 return ["/nologo","/c","/O2","/GS-","/EHsc","/MD","/DWIN32","/DNDEBUG","/D_MBCS","/D_AFXDLL","/D_XTP_STATICLINK","/D_XTPLIB_NOAUTOLINK","/I"+str(mfc),"/I"+str(xtp)]+["/D"+d for d in defines.split()]+["/I"+str(i) for i in [headers,here]+includes]
r.compiler_flags=flags
r.main()
