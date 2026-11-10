import subprocess,sys,json
from pathlib import Path
sys.path.insert(0,'.')
r=subprocess.run([sys.executable,'rebuild/2008-06/tests/record_native_function.py','rebuild/2008-06/native-classes/CRobloxViewInit.cpp','work/2008-06/shared-layouts/view-init.json','0045a4a0:?OnInitialUpdate@CRobloxView'],capture_output=True,text=True)
if 'error' in r.stdout.lower() and 'compiled_size' not in r.stdout: print('COMPILE ERROR',r.stdout[-600:]); sys.exit(1)
from roc import match
obj=Path('rebuild/2008-06/out/native-layouts/CRobloxViewInit.obj').read_bytes()
t,rel,_=match.target('2008-06','0045a4a0')
n,b,cr=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('?OnInitialUpdate@CRobloxView'))
mask={o+k for o in list(rel)+list(cr) for k in range(4)}
d=[i for i,(x,y) in enumerate(zip(t,b)) if x!=y and i not in mask]
print(len(b),'bytes; first diff',d[:1],'; diffs in common prefix',len(d))
