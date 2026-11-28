import os,runpy,sys
os.environ.update(ROC_IE_ALLOW="1",SECOND_CHANCE_ONLY="1",PEEK="esp")
sys.argv=["mfc_patch_debug.py","work/donorfree-route/run/dbg/RobloxDbg.exe","work/donorfree-route/run/dbg/dbg.map","40"]
runpy.run_path("work/donorfree-route/auto/mfc_patch_debug.py",run_name="__main__")
