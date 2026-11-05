import sys,json,hashlib,traceback
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
import os
os.environ['ROC_INTEGRATOR_PRIVATE']='1'
from roc import rebuild
OUT=ROOT/'work/2008-06/shared-layouts/sol-snapshot-20261105'
order=[]; specs={}
def visit(name):
 if name in specs:return
 spec=rebuild.load_module('2008-06',name); specs[name]=spec
 for dep in spec.get('refresh_dependencies',[])+spec.get('depends',[]):visit(dep)
 order.append(name)
visit('player');visit('xtp')
def save(name,value): (OUT/name).write_text(json.dumps(value,indent=2,default=str)+'\n',encoding='utf-8')
save('dependency-plan.json',{'order':order,'specs':specs,'hashes':{n:hashlib.sha256((ROOT/'rebuild/2008-06/modules'/ (n+'.json')).read_bytes()).hexdigest() for n in order}})
print(order,flush=True)
results=json.loads((OUT/'module-results.json').read_text()) if (OUT/'module-results.json').exists() else {}
try:
 # player performs its declared refreshes; build prerequisites first via their canonical functions.
 for name in order:
  if name in ('player',) or name in results: continue
  print('BUILD',name,flush=True)
  result=rebuild.build_module('2008-06',name)
  results[name]=result;save('module-results.json',results)
  if not result.get('linked') or result.get('test_exit')!=0: raise RuntimeError('canonical module failed: '+name)
 print('BUILD player',flush=True)
 results['player']=rebuild.build_module('2008-06','player');save('module-results.json',results)
except Exception as error:
 save('blocker.json',{'error':str(error),'traceback':traceback.format_exc(),'completed':list(results)})
 raise

