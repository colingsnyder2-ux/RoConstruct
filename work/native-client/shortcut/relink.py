"""Shortcut relink: chosen12 objects + real glue objects + zero stubs for what is still undefined; then run crashsite."""
import json,subprocess,sys,os
from pathlib import Path
H=Path('work/native-client/shortcut')
subprocess.run([sys.executable,str(H/'mkstub.py'),str(H)],check=True)
objs=json.load(open(H/'chosen12.json'))+[(H/o).resolve().as_posix() for o in json.load(open(H/'glue.json'))]+[(H/'stubs.obj').resolve().as_posix()]
json.dump({'selected':[{'object':c} for c in objs]},open(H/'receipt-final.json','w'))
env=dict(os.environ,ROC_ENGINE_ABI='1',ROC_LINK_RES=os.path.normpath(str((H/'Roblox2008.res').resolve())),
 ROC_LINK_EXTRA=Path('work/native-client/link/selected-engine-cumulative.json').resolve().as_posix()+';'+(H/'receipt-final.json').resolve().as_posix())
subprocess.run([sys.executable,'work/native-client/linkprobe.py'],env=env,capture_output=True)
p=json.load(open('work/native-client/link/probe.json'));print('link',p['link_exit_code'],len(p['unresolved']),len(p['duplicates']),flush=True)
L=Path('work/native-client/link').resolve()
subprocess.run([sys.executable,str(H/'crashsite.py'),str(L/'Roblox2008.exe'),str(L/'Roblox2008.map'),'20'])
