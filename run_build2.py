import sys, time
sys.path.insert(0,".")
from pathlib import Path
import roc.match as match
orig=match.compile_text
def logged(client, source, cl=None, flags=None):
    print("compile", (source[:80] if isinstance(source,str) else source), flush=True)
    return orig(client, source, cl, flags)
match.compile_text=logged
from roc import rebuild
print("start", flush=True)
try:
    rep=rebuild.build_module("2008-06","rbxgs-app",log=print)
    print("RESULT linked", rep["linked"], "test", rep["test_exit"], "unresolved", len(rep.get("unresolved",[])), flush=True)
except Exception as e:
    print("EXCEPTION", repr(e), flush=True)
