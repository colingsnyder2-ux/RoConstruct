import os,runpy,sys
os.environ.update(BPENTRY="00400040",ROC_IE_ALLOW="1")
sys.argv=["crashsite.py","work/donorfree-route/run/dbg/RobloxDbg.exe","work/donorfree-route/run/dbg/dbg.map","30"]
runpy.run_path("work/donorfree-route/auto/header_debug.py",run_name="__main__")

