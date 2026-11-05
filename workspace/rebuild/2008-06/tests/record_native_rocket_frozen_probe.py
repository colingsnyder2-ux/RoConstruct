import hashlib,json,re,shutil,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'rocket-frozen-probe';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'document-swap-provider-trial.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();mapping={};snapshot={}
for index,path in enumerate(base['objects']):
 source=root/path;target=work/('%03d'%index)/source.name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);mapping[str(source).lower()]=str(target);snapshot[path]=sha(target)
archive=out/'document-swap-link-trial/RbxgsAppWithoutInstance.lib';archive_copy=work/'RbxgsAppWithoutInstance.lib';shutil.copyfile(archive,archive_copy);mapping[str(archive).lower()]=str(archive_copy)
r=out/'rocket-worker';s=out/'worker-slingshot';files=[r/'NativeRocketWorkerTrial.obj',r/'NativeRocketPrototypeWorkerTrial.obj',r/'NativeRocketLaunchWorkerTrial.obj',s/'NativeSlingshotWorkerTrial.obj',s/'NativeSlingshotMethodsWorkerTrial.obj',s/'NativeSlingshotLaunchWorkerTrial.obj',s/'NativeShootWorkerTrial.obj',s/'NativeSlingshotPelletWorkerTrial.obj'];rp=json.loads((proof/'rocket-worker-trial.json').read_text());rl=json.loads((proof/'rocket-launch-worker-trial.json').read_text());sp=json.loads((proof/'slingshot-worker-trial.json').read_text());sm=json.loads((proof/'slingshot-methods-worker-trial.json').read_text());sh=json.loads((proof/'shoot-worker-trial.json').read_text());pp=json.loads((proof/'slingshot-pellet-worker-trial.json').read_text());deps=json.loads((proof/'slingshot-dependencies-worker-trial.json').read_text());files += [root/x['object'] for x in deps['objects']];expected=[rp['objects'][0]['object_sha256'],rp['objects'][1]['object_sha256'],rl['object_sha256'],sp['object_sha256'],sm['objects'][0]['object_sha256'],sm['objects'][1]['object_sha256'],sh['object_sha256'],pp['object_sha256']]+[x['object_sha256'] for x in deps['objects']];copies=[]
for i,(source,checksum) in enumerate(zip(files,expected)):
 assert sha(source)==checksum,('stale candidate',source);target=work/'candidate'/('%02d'%i)/source.name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);assert sha(target)==checksum;copies.append(target)
libs={}
for arg in base['link_flags']:
 p=Path(arg)
 if p.suffix.lower()=='.lib' and p.exists() and str(p).lower()!=str(archive).lower():libs[str(p)]=sha(p)
def link(name,extra):
 args=[]
 for arg in base['link_flags']:
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  else:arg=mapping.get(arg.lower(),arg)
  args.append(arg)
 rsp=work/(name+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args+list(map(str,extra)))+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);assert 'fatal error LNK1104' not in log,log[-1500:];(work/(name+'.log')).write_text(log);return code,[line for line in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',line)]
a,ea=link('baseline',[]);b,eb=link('candidate',copies);assert all(sha(Path(p))==h for p,h in libs.items()),'library changed between links';receipt={'scope':'Frozen copied-object diagnostic; never run. Baseline objects copied from current disk, not guaranteed to match old receipt. Noncopied library hashes checked before/after both links; layout and runtime ABI unproven.','baseline_exit':a,'baseline_errors':ea,'candidate_exit':b,'candidate_errors':eb,'snapshot_objects':snapshot,'snapshot_archive_sha256':sha(archive_copy),'noncopied_libraries':libs,'candidate_hashes':{str(p.relative_to(root)):h for p,h in zip(files,expected)},'observer_sha256':sha(Path(__file__))};(proof/'rocket-frozen-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('Rocket frozen probe: baseline',len(ea),'candidate',len(eb));before=set(ea);print('\n'.join(x for x in eb if x not in before)[:2000])
