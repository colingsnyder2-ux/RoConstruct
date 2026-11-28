import os,runpy,sys
os.environ.update(ROC_IE_ALLOW="1",SECOND_CHANCE_ONLY="1",PEEK="esp,00d33ae0,00c56560")
sys.argv=["boost_patch_debug.py","work/donorfree-route/run/dbg/RobloxMfcTrial.exe","work/donorfree-route/linkexp_mfcprobe/test.map","35"]
runpy.run_path("work/donorfree-route/auto/boost_patch_debug.py",run_name="__main__")

