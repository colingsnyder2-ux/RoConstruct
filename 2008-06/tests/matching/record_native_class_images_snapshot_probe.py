import hashlib,json,re,shutil,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'class-images-snapshot';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'document-swap-provider-trial.json').read_text());trial=json.loads((proof/'class-images-trial.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();mapping={};snapshot={}
for index,path in enumerate(base['objects']):
 source=root/path; target=work/('%03d'%index)/source.name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);mapping[str(source).lower()]=str(target);snapshot[path]=sha(target)
archive=out/'document-swap-link-trial/RbxgsAppWithoutInstance.lib';archive_copy=work/'RbxgsAppWithoutInstance.lib';shutil.copyfile(archive,archive_copy);mapping[str(archive).lower()]=str(archive_copy)
objs=[root/'rebuild/2008-06/out/insert-service/NativeClassImagesLink.obj']
assert sha(objs[0])==trial['link_object_sha256']

def link(name,extra):
 args=[]
 for arg in base['link_flags']:
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  else:arg=mapping.get(arg.lower(),arg)
  args.append(arg)
 code,log=rebuild.run(rebuild.toolchain(21022),'link',args+list(map(str,extra)),work);assert 'fatal error LNK1104' not in log,log[-2000:];(work/(name+'.log')).write_text(log);errors=[line for line in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',line)];return code,errors
a,ea=link('baseline',[]);b,eb=link('clipboard',objs);assert a==1120 and b==1120,(a,b);receipt={'scope':'Same copied objects and donor archive used for both incompatible ABI diagnostic links; never run. Snapshot is not a full source rebuild or runtime ABI proof.','baseline_exit':a,'baseline_errors':ea,'candidate_exit':b,'candidate_errors':eb,'snapshot_objects':snapshot,'snapshot_archive_sha256':sha(archive_copy),'candidate_hashes':{str(p.relative_to(root)):sha(p) for p in objs},'observer_sha256':sha(Path(__file__))};(proof/'class-images-snapshot-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('ClassImages snapshot: baseline',len(ea),'candidate',len(eb))
