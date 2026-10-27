import sys, time
sys.path.insert(0,".")
from roc import rebuild
print("start", flush=True)
try:
    rep=rebuild.build_module("2008-06","rbxgs-app",log=print)
    print("RESULT", rep, flush=True)
except Exception as e:
    print("EXCEPTION", repr(e), flush=True)
