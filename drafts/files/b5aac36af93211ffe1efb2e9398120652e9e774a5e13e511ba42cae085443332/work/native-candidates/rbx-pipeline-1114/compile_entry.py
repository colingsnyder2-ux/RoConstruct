"""Compile the native integration entry without executing an unclosed pipeline."""
import json
from pathlib import Path
import sys
import re

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import rebuild

HERE=Path(__file__).resolve().parent
spec=rebuild.load_module("2008-06","ogre-real-provider-1112")
includes=[ROOT/p for p in (
    "rebuild/2008-06/native-headers/viewrbx-ctor-profile",
    "rebuild/2008-06/native-headers/partchunk-profile",
    "rebuild/2008-06/native-headers/part-embedded",
    "rebuild/2008-06/native-headers")]
includes += [ROOT/p for p in spec["layers"][0]["extra_includes"] if ROOT/p not in includes]
result=rebuild.compile_direct("2008-06",[HERE/"Entry.cpp"],HERE/"objects",includes,
    "WIN32 NDEBUG _MBCS BOOST_ALL_NO_LIB",flags="/O2 /GS- /EHsc /MD /fp:fast")
(HERE/"entry-compile.json").write_text(json.dumps(result,indent=2))
print(json.dumps(result,indent=2))
if not all(row[0] for row in result.values()):
    raise SystemExit(1)
provider_names=("DataModelCreate", "DataModelLock", "ViewRbxGfxConstructor2008",
    "RenderSceneViewBase2008", "RenderSceneViewRbxGfx2008", "ViewRbxGfxRender2008",
    "SceneManagerAggregating2008", "PartInstanceLifetime", "AppUnit598PartInstance",
    "PartInstanceCoordinate", "InstanceParent", "AppUnit5ECSurfaces", "AppUnit5F0_2008Surface",
    "ViewNewPartConstructor2008", "PartOutfitChanged2008", "SceneManager2008",
    "InstanceFullName", "InstanceDescendantPropagation")
provider_results={}
provider_objects=[]
for name in provider_names:
    source=ROOT/"rebuild/2008-06/native-classes"/(name+".cpp")
    flags=re.search(r"^// native-flags: (.+)$",source.read_text(),re.M)
    flags=flags.group(1).replace("{headers}",str(ROOT/"rebuild/2008-06/native-headers")) if flags else "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"
    folder=HERE/"providers"/name
    provider_includes=[p for p in includes if p.name not in ("viewrbx-ctor-profile","partchunk-profile","part-embedded")]
    if name in ("InstanceParent","InstanceFullName","InstanceDescendantPropagation"):
        provider_includes.insert(0,HERE/"instance-parent")
    compiled=rebuild.compile_direct("2008-06",[source],folder,provider_includes,
        "WIN32 NDEBUG _MBCS BOOST_ALL_NO_LIB",flags=flags)
    provider_results[name]=compiled
    if all(row[0] for row in compiled.values()):
        provider_objects.append(folder/(name+".obj"))
(HERE/"provider-compile.json").write_text(json.dumps(provider_results,indent=2))
code,output=rebuild.run(rebuild.toolchain(),"lib",["/nologo","/OUT:native-roots.lib"]+
    [str(p) for p in provider_objects],HERE/"objects")
if code:
    raise SystemExit(output)
# /NOENTRY closure probe only: never execute an unreviewed mixed-ABI image.
base=ROOT/"rebuild/2008-06/out"
libraries=[base/rebuild.load_module("2008-06",name)["name"]/"linked/linked.lib"
           for name in ("ogre-real-provider-1112","g3d-gl","g3d","boost","zlib-winapi")]
libraries.insert(0,HERE/"objects/native-roots.lib")
libraries += [base/"importlibs/rgmain.lib"]
code,output=rebuild.run(rebuild.toolchain(),"link",["/nologo","/DLL","/NOENTRY","/MACHINE:X86",
    "/OUT:pipeline-closure.dll","Entry.obj"]+[str(p) for p in libraries]+
    ["kernel32.lib","user32.lib","gdi32.lib","advapi32.lib","shell32.lib","ole32.lib",
     "oleaut32.lib","winmm.lib","ws2_32.lib","opengl32.lib","glu32.lib","msvcprt.lib"]+
    ["/NODEFAULTLIB:"+name for name in rebuild.VENDOR_AUTOLINK],HERE/"objects")
(HERE/"link.log").write_text(output)
closure={"linked":code==0,"unresolved":sorted(set(rebuild.unresolved_symbols(output))),"ran":False,
         "compile_failures":[name for name,compiled in provider_results.items() if any(not row[0] for row in compiled.values())],
         "reason":"Native-only closure probe; donor App library excluded because its ABI is different."}
(HERE/"closure.json").write_text(json.dumps(closure,indent=2))
print(json.dumps(closure,indent=2))
raise SystemExit(0 if code==0 else 1)
