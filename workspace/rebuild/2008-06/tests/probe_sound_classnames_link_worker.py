import json,sys,hashlib,shutil,re
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts/sound-classnames-link-worker';out.mkdir(parents=True,exist_ok=True);base=json.loads((root/'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json').read_text());extra=json.loads((root/'work/2008-06/shared-layouts/sound-native-instance-worker.json').read_text());classreceipt=json.loads((root/'work/2008-06/shared-layouts/sound-classnames-worker.json').read_text());nameobj=root/'rebuild/2008-06/out/native-layouts/sound-classnames-worker/NativeSoundClassNamesWorker.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(nameobj)==classreceipt['object_sha256']
paths=[]
for arg in base['flags']:
 if not arg.startswith('/') and Path(arg).is_file() and Path(arg).suffix.lower() in ('.obj','.lib'):paths.append(Path(arg))
paths += [Path(p) for p in extra['objects']];copies={}
for i,p in enumerate(paths):
 assert p.is_file(),p
 if str(p) in extra['objects']:assert sha(p)==extra['objects'][str(p)],p
 q=out/('%03d_'%i+p.name);shutil.copy2(p,q);assert sha(p)==sha(q);copies[str(p).lower()]=str(q)
q=out/'native-classnames.obj';shutil.copy2(nameobj,q);assert sha(q)==classreceipt['object_sha256'];args=[]
for a in base['flags']:
 if a.startswith('/OUT:'):a='/OUT:baseline.exe'
 elif a.startswith('/MAP:'):a='/MAP:baseline.map'
 else:a=copies.get(a.lower(),a)
 args.append(a)
args += [copies[str(Path(p)).lower()] for p in extra['objects']]
def link(label,more):
 a=[('/OUT:'+label+'.exe') if x.startswith('/OUT:') else ('/MAP:'+label+'.map') if x.startswith('/MAP:') else x for x in args]+more
 code,log=rebuild.run(rebuild.toolchain(21022),'link',a,out);(out/(label+'.log')).write_text(log,encoding='utf8');return code,[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)',x)]
bc,be=link('baseline',[]);cc,ce=link('candidate',[str(q)]);old=set(be);new=set(ce);result={'scope':'Frozen mixed-ABI diagnostic; must never run. All comparison inputs frozen together. No P4 or runtime validation.','baseline_exit':bc,'candidate_exit':cc,'baseline_lines':len(be),'candidate_lines':len(ce),'removed_errors':sorted(old-new),'new_errors':sorted(new-old),'target_class_symbols':[x['symbol'] for x in classreceipt['symbols']],'candidate_sha256':sha(q),'snapshot_sha256':{str(Path(k).name):sha(Path(v)) for k,v in copies.items()},'baseline_receipt_sha256':sha(root/'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json'),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-classnames-link-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('baseline',bc,len(be),'candidate',cc,len(ce));print('REMOVED',*result['removed_errors'],sep='\n');print('NEW',*result['new_errors'],sep='\n')
