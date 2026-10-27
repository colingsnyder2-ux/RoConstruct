import sys, time
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
ov=rebuild.build_overlay(client, spec["name"], spec.get("overlay"))
out=Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/test-glue-diag")
out.mkdir(parents=True, exist_ok=True)
for src in sources:
    t=time.time()
    try:
        res=rebuild.compile_direct(client, [src], out, includes, defines, layer["flags"], cl=21022, overlay=ov)
        ok=list(res.values())[0][0]
        if not ok and layer.get("fallback_cl"):
            res2=rebuild.compile_direct(client, [src], out, includes, defines, layer["flags"], cl=layer["fallback_cl"], overlay=ov)
            ok=list(res2.values())[0][0]
            err=list(res2.values())[0][1]
        else:
            err=list(res.values())[0][1]
        print(f"{src.name}: {'OK' if ok else 'FAIL'} {round(time.time()-t,1)}s", flush=True)
        if not ok:
            print(err[:300], flush=True)
    except Exception as e:
        print(f"{src.name}: EXCEPTION {e}", flush=True)
print("done", flush=True)
