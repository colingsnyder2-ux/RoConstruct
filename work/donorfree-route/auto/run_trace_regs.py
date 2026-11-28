import os,runpy,sys
os.environ.update(TRACE_ENTRY="004042e0",TRACE_KEEP="40",SECOND_CHANCE_ONLY="1",ROC_IE_ALLOW="1")
sys.argv=["trace_regs_debug.py","work/donorfree-route/run/dbg/RobloxDbg.exe","work/donorfree-route/run/dbg/dbg.map","50"]
runpy.run_path("work/donorfree-route/auto/trace_regs_debug.py",run_name="__main__")
