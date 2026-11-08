import hashlib,json,re,shutil,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import libs,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-grab-factory/full-probe';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'document-swap-provider-trial.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();mapping={};snapshot={}
for index,path in enumerate(base['objects']):
 source=root/path; target=work/('%03d'%index)/source.name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);mapping[str(source).lower()]=str(target);snapshot[path]=sha(target)
archive=out/'document-swap-link-trial/RbxgsAppWithoutInstance.lib';archive_copy=work/'baseline.lib';shutil.copyfile(archive,archive_copy);mapping[str(archive).lower()]=str(archive_copy)
member=next(data for name,data in libs.archive_members(archive_copy) if str(name)=='glue_link_stubs.obj');symbol='?onMouseMove@PartDragTool@RBX@@UAEXABVUIEvent@2@@Z';assert rebuild.coff_externals(member).get(symbol) is True
patched=work/'glue_link_stubs.obj';patched.write_bytes(rebuild.strip_symbols(member,drop={symbol}));assert rebuild.coff_externals(patched.read_bytes()).get(symbol) is False
candidate_archive=work/'candidate.lib';code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:glue_link_stubs.obj','/OUT:'+str(candidate_archive),str(archive_copy)],work);assert code==0,log
code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/OUT:'+str(candidate_archive),str(candidate_archive),str(patched)],work);assert code==0,log
pairs=[('NativeGrabToolTrial','grab-tool-lifetime-trial'),('NativeGrabMethodsTrial','grab-methods-trial'),('NativeGrabNameTrial','grab-name-trial'),('NativeGroupDragLifetimeTrial','group-drag-lifetime-trial'),('NativeGroupDragMethodsTrial','group-drag-methods-trial'),('NativeGroupDragNameTrial','group-drag-name-trial'),('NativePartDragLifetimeTrial','part-drag-lifetime-trial'),('NativePartDragMethodsTrial','part-drag-methods-trial'),('NativePartDragNameTrial','part-drag-name-trial'),('NativeCollectDragPartsTrial','collect-drag-parts-trial')];objects=[]
for name,receipt in pairs:
 p=out/(name+'.obj');expected=json.loads((proof/(receipt+'.json')).read_text())['object_sha256'];assert sha(p)==expected,('stale',str(p));target=work/(name+'.obj');shutil.copyfile(p,target);objects.append(target)
factory=out/'worker-grab-factory/verified/NativeDragFactoryWorkerTrial.obj';assert sha(factory)==json.loads((proof/'drag-factory-worker-trial.json').read_text())['object_sha256'];target=work/factory.name;shutil.copyfile(factory,target);objects.append(target)
def link(name,extra):
 args=[]
 for arg in base['link_flags']:
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  else:
   arg=mapping.get(arg.lower(),arg)
   if name=='candidate' and arg.lower()==str(archive_copy).lower():arg=str(candidate_archive)
  args.append(arg)
 rsp=work/(name+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in args+list(map(str,extra)))+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);assert 'fatal error LNK1104' not in log,log[-2000:];(work/(name+'.log')).write_text(log);errors=[line for line in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',line)];return code,errors
bc,be=link('baseline',[]);cc,ce=link('candidate',objects);receipt={'scope':'Copied frozen objects and archive; incompatible ABI diagnostic only, never run. Snapshot is not a full source rebuild or runtime proof.','baseline_exit':bc,'baseline_errors':be,'candidate_exit':cc,'candidate_errors':ce,'snapshot_objects':snapshot,'baseline_archive_sha256':sha(archive_copy),'candidate_archive_sha256':sha(candidate_archive),'removed_stub':symbol,'candidate_hashes':{p.name:sha(p) for p in objects},'observer_sha256':sha(Path(__file__))};(proof/'drag-factory-worker-full-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('BASELINE',bc,len(be),'CANDIDATE',cc,len(ce));print('\n'.join(x for x in ce if x not in set(be)))
