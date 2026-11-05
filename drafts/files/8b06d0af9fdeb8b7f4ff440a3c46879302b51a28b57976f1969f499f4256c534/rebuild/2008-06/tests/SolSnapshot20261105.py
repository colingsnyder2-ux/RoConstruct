import sys,json,hashlib,traceback
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
import os
os.environ['ROC_INTEGRATOR_PRIVATE']='1'
from roc import rebuild, integration
bundle=ROOT/'research/native-units.json'
bundle_units=json.loads(bundle.read_text(encoding='utf-8'))
units=bundle_units['../rbxgs/Client/App']
original_adopted_path=integration.adopted_path
adoptions={}
def scoped_adopted_path(tree,name,workspace=None):
 path=original_adopted_path(tree,name,workspace)
 key=Path(name).name
 if path.exists() or key not in units:return path
 text=units[key]
 if not isinstance(text,str):return path
 target=OUT/'adopted'/key
 target.parent.mkdir(parents=True,exist_ok=True)
 target.write_text(text,encoding='utf-8',newline='')
 adoptions[str(path)]={'materialized':str(target),'sha256':hashlib.sha256(target.read_bytes()).hexdigest(),'key':key}
 (OUT/'adoptions.json').write_text(json.dumps({'bundle_sha256':hashlib.sha256(bundle.read_bytes()).hexdigest(),'paths':adoptions},indent=2)+'\n',encoding='utf-8')
 return target
integration.adopted_path=scoped_adopted_path
OUT=ROOT/'work/2008-06/shared-layouts/sol-snapshot-20261105'
from roc import libs
recipe=libs.RECIPES['xtp-11.2.2-shared-mfc-internals-rtm']
recipe['preinclude']=list(recipe.get('preinclude',[]))+[str(OUT/'XtpCompatibility.h')]
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
  if name in ('player',) or (name in results and results[name].get('linked') and results[name].get('test_exit')==0): continue
  prior=ROOT/'rebuild/2008-06/out'/specs[name]['name']/'report.json'
  if name=='xtp' and prior.exists():
   recorded=json.loads(prior.read_text())
   if recorded.get('linked') and recorded.get('test_exit')==0:
    results[name]=recorded;save('module-results.json',results);continue
  print('BUILD',name,flush=True)
  result=rebuild.build_module('2008-06',name)
  results[name]=result;save('module-results.json',results)
  if not result.get('linked') or result.get('test_exit')!=0: raise RuntimeError('canonical module failed: '+name)
 print('BUILD player',flush=True)
 results['player']=rebuild.build_module('2008-06','player');save('module-results.json',results)
except Exception as error:
 save('blocker.json',{'error':str(error),'traceback':traceback.format_exc(),'completed':list(results)})
 raise





