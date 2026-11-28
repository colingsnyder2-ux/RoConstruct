import os,runpy,sys
os.environ.update(ROC_IE_ALLOW="1",PEEK="esp")
sys.argv=["native_debug.py","work/donorfree-route/run/dbg/RobloxNativeTrial.exe","work/donorfree-route/linkexp_nativeprobe/test.map","40"]
runpy.run_path("work/donorfree-route/auto/native_debug.py",run_name="__main__")

