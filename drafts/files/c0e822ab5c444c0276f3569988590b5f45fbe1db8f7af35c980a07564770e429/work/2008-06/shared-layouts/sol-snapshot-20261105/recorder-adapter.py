import sys,json,hashlib,runpy
from pathlib import Path
ROOT=Path.cwd();sys.path.insert(0,str(ROOT));sys.path.insert(0,str(ROOT/'rebuild/2008-06/tests'))
from roc import libs
from p6_probe import build_lock,RUNS
OUT=ROOT/'work/2008-06/shared-layouts/sol-snapshot-20261105'
r=libs.RECIPES['rbxgs']
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/D_AFXDLL','/DNDEBUG','/D_MBCS','/DNOMINMAX','/DBOOST_ALL_NO_LIB']
flags+=['/D'+v for v in r['defines'].split()]
flags+=['/I'+str(ROOT/'rebuild/2008-06/native-headers'),'/I'+str(ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags+=['/I'+str((libs.LIBS/v).resolve()) for v in r['include'] if v!='WINSDK']
legacy=ROOT/'work/2008-06/shared-layouts/document-swap-current.json'
writes={ROOT/'work/2008-06/shared-layouts/workspace-insert-candidate.json':OUT/'workspace-insert-candidate.json',ROOT/'work/2008-06/shared-layouts/workspace-site-trust-working.json':OUT/'workspace-site-trust-working.json'}
read=Path.read_text;write=Path.write_text
scripts=[ROOT/'rebuild/2008-06/tests'/n for n in ['record_native_workspace_insert.py','record_native_workspace_site_trust.py']]
if sys.argv[1:]==['site-only']:scripts=scripts[-1:]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
write(OUT/'recorder-adapter-context.json',json.dumps({'adapter_sha256':sha(Path(__file__)),'scripts':{str(p):sha(p) for p in scripts},'flags':flags,'read_mapping':{str(legacy):{'flags':flags}},'write_mapping':{str(a):str(b) for a,b in writes.items()}},indent=2)+'\n')
def scoped_read(self,*args,**kwargs):
 if self.resolve()==legacy.resolve():return json.dumps({'flags':flags})
 return read(self,*args,**kwargs)
def scoped_write(self,*args,**kwargs):return write(writes.get(self.resolve(),self),*args,**kwargs)
with build_lock(RUNS):
 Path.read_text=scoped_read;Path.write_text=scoped_write
 try:
  for script in scripts:
   print('RUN',script,flush=True);runpy.run_path(str(script),run_name='__main__')
 finally:Path.read_text=read;Path.write_text=write

