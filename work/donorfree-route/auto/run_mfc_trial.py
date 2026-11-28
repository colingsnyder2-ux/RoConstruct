import os,runpy,sys
os.environ.update(ROC_IE_ALLOW="1",SECOND_CHANCE_ONLY="1",PEEK="esp")
sys.argv=["crashsite.py","work/donorfree-route/run/dbg/RobloxMfcTrial.exe","work/donorfree-route/linkexp_mfcprobe/test.map","35"]
runpy.run_path("work/native-client/shortcut/crashsite.py",run_name="__main__")
