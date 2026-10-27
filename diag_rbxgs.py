import sys, time
sys.path.insert(0,".")
from pathlib import Path
from roc import libs, match
client="2008-06"
recipe="rbxgs"
r=libs.RECIPES[recipe]
src=libs._case_path(libs.LIBS/r["src"])
listed=r.get("files")
globs=(listed if isinstance(listed,str) else " ".join(listed)).split()
files=sorted(p.relative_to(src).as_posix() for g in globs for p in src.glob(g) if not p.name.startswith("roc_"))
print("files", len(files), flush=True)
for rel in files:
    t=time.time()
    try:
        obj=match.compile_text(client, libs.source_for(recipe, rel, None, 21022, "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"))
        print(f"{rel}: OK {round(time.time()-t,1)}s", flush=True)
    except Exception as e:
        print(f"{rel}: FAIL {round(time.time()-t,1)}s {str(e)[:200]}", flush=True)
print("done", flush=True)
