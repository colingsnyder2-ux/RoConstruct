import sys
sys.path.insert(0,".")
from pathlib import Path
from roc import rebuild, libs
client="2008-06"
spec=rebuild.load_module(client,"rbxgs-app")
layer=[l for l in spec["layers"] if l["name"]=="glue"][0]
recipe=libs.RECIPES[layer["includes_from_recipe"]] if layer.get("includes_from_recipe") else {"include":[]}
includes=[(libs.LIBS/i).resolve() for i in recipe.get("include",[]) if i!="WINSDK"] + [(Path(i)).resolve() for i in layer.get("extra_includes",[])]
defines=libs.RECIPES[layer["defines_from_recipe"]]["defines"] if layer.get("defines_from_recipe") else layer.get("defines","")
defines=(defines+" "+layer.get("extra_defines","")).strip()
sources=[]
for g in layer["files"].split():
    for p in sorted(Path(layer["dir"]).glob(g)):
        if not p.name.startswith("roc_") and p.name not in layer.get("exclude",[]):
            sources.append(p)
sources=[(Path("C:/Users/colin/RoConstruct")/s if not s.is_absolute() else s) for s in sources]
ov=rebuild.build_overlay(client, spec["name"], spec.get("overlay"))
out=Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/test-glue-full")
out.mkdir(parents=True, exist_ok=True)
res=rebuild.compile_direct(client, sources, out, includes, defines, layer["flags"], cl=21022, overlay=ov)
print("first errors:", len(res))
if layer.get("fallback_cl"):
    failed=[Path(k) for k,(ok,_) in res.items() if not ok]
    print("failed count", len(failed))
    res2=rebuild.compile_direct(client, failed, out, includes, defines, layer["flags"], cl=layer["fallback_cl"], overlay=ov)
    print("fallback errors:", len(res2))
    for k,v in res2.items():
        if not v[0]:
            print("FAIL", Path(k).name)
            print(v[1][:500])
print("stubs obj exists:", (out/"glue_link_stubs.obj").exists(), (out/"glue_asm_stubs.obj").exists())
