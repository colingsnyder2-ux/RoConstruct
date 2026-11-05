import hashlib,json,re,shutil,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-hammer/full-probe';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'document-swap-provider-trial.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();mapping={};snapshot={}
for index,path in enumerate(base['objects']):
 source=root/path;target=work/('%03d'%index)/source.name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);mapping[str(source).lower()]=str(target);snapshot[path]=sha(target)
archive=out/'document-swap-link-trial/RbxgsAppWithoutInstance.lib';archive_copy=work/'baseline.lib';shutil.copyfile(archive,archive_copy);mapping[str(archive).lower()]=str(archive_copy)
pairs=[('NativeHammerWorkerTrial.obj',json.loads((proof/'hammer-worker-trial.json').read_text())['object_sha256'])]+[(Path(x['object']).name,x['object_sha256']) for x in json.loads((proof/'hammer-methods-worker-trial.json').read_text())['objects']];objects=[]
for name,expected in pairs:
 p=out/'worker-hammer'/name;assert sha(p)==expected,('stale',p);target=work/name;shutil.copyfile(p,target);objects.append(target)
def link(name,extra):
 args=[]
 for arg in base['link_flags']:
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  else:arg=mapping.get(arg.lower(),arg)
  args.append(arg)
 rsp=work/(name+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in args+list(map(str,extra)))+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);assert 'fatal error LNK1104' not in log,log[-2000:];(work/(name+'.log')).write_text(log);errors=[line for line in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',line)];return code,errors
bc,be=link('baseline',[]);cc,ce=link('candidate',objects);receipt={'scope':'Copied frozen objects and archive; incompatible ABI diagnostic only, never run. Not a full source rebuild or runtime proof.','baseline_exit':bc,'baseline_errors':be,'candidate_exit':cc,'candidate_errors':ce,'snapshot_objects':snapshot,'archive_sha256':sha(archive_copy),'candidate_hashes':{p.name:sha(p) for p in objects},'observer_sha256':sha(Path(__file__))};(proof/'hammer-worker-full-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('BASELINE',bc,len(be),'CANDIDATE',cc,len(ce));print('\n'.join(x for x in ce if x not in set(be)))
