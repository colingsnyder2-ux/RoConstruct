import sys,json,struct,hashlib,subprocess,re,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
out=root/'rebuild/2008-06/out/native-layouts';work=out/'workspace-integrated-frozen-worker';work.mkdir(exist_ok=True);prior=out/'worker-writer-near/full-probe';proof=root/'work/2008-06/shared-layouts';frozen=json.loads((proof/'workspace-writer-near-full-worker-probe.json').read_text());life=json.loads((proof/'workspace-lifetime-integrated.json').read_text());prof=json.loads((proof/'profiling-integrated.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for receipt in [life,prof]:
 for path,digest in receipt['sources'].items():
  if '/tests/' not in path.replace('\\','/'): assert sha(root/path)==digest,('changed source',path)
objects=[]
for receipt,name in [(life,'WorkspaceLifetime'),(prof,'Profiling')]:
 src=root/('rebuild/2008-06/native-classes/'+name+'.cpp');obj=work/(name+'.obj');flags=[x for x in receipt['flags'] if not x.startswith('/Fo') and not x.endswith(name+'.cpp')]+['/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work);(work/(name+'.log')).write_text(log);assert c==0,log;objects.append(obj)
raw=objects[0].read_bytes();rows=[]
for pre,a in [('??0Workspace@RBX@@',0x5a4d90),('??1Workspace@RBX@@',0x5a28c0)]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%a);exact=match.exact_match(t,tr,b,r);rows.append({'symbol':n,'address':hex(a),'size':len(b),'exact':exact});assert exact
keep={r['symbol'] for r in rows};candidate=work/'native-workspace-lifetime.obj';candidate.write_bytes(rebuild.strip_symbols(raw,keep=keep));old=None
for i,(path,digest) in enumerate(frozen['snapshot_objects'].items()):
 p=prior/('%03d'%i)/Path(path).name;assert p.exists() and sha(p)==digest,('stale frozen',path)
 if path.replace('\\','/').endswith('workspace-source-probe/WorkspaceWithoutDefault.obj'):old=p
assert old;oldraw=old.read_bytes();olddefs=rebuild.coff_externals(oldraw);drop={k for k,v in olddefs.items() if v and (k.startswith('??0Workspace@RBX@@') or k.startswith('??1Workspace@RBX@@'))};assert drop==keep,(drop,keep);oldfiltered=work/'donor-no-lifetime.obj';oldfiltered.write_bytes(rebuild.strip_symbols(oldraw,drop=drop))
live_archive=out/'document-swap-link-trial/RbxgsAppWithoutInstanceOrPartDragStub.lib';provider=json.loads((proof/'document-swap-provider-trial.json').read_text());assert sha(live_archive)==provider['filtered_archive_sha256'];archive=work/'actual-frozen.lib';shutil.copyfile(live_archive,archive);assert sha(archive)==provider['filtered_archive_sha256'];newarchive=work/'donor-no-profiling.lib';c,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:Profiling.obj','/OUT:'+str(newarchive),str(archive)],work);assert c==0,log

def link(name,change):
 args=[]
 for line in (prior/'baseline.rsp').read_text().splitlines():
  arg=line.strip().strip(chr(34))
  if not arg:continue
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  elif change and arg==str(old):arg=str(oldfiltered)
  elif arg==str(live_archive):arg=str(newarchive if change else archive)
  args.append(arg)
 if change:args.extend([str(candidate),str(objects[1])])
 rsp=work/(name+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');c,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/(name+'.log')).write_text(log);errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)];return c,errors
bc,be=link('baseline',False);cc,ce=link('candidate',True);record={'scope':'Frozen diagnostic only, native profiler constructor nonexact; not runtime safe, do not execute.','baseline_exit':bc,'baseline_errors':be,'candidate_exit':cc,'candidate_errors':ce,'new_errors':[e for e in ce if e not in set(be)],'workspace_methods':rows,'native_workspace_sha256':sha(objects[0]),'native_profiler_sha256':sha(objects[1]),'candidate_filtered_sha256':sha(candidate),'old_filtered_sha256':sha(oldfiltered),'filtered_archive_sha256':sha(newarchive),'frozen_archive_sha256':sha(archive),'observer_sha256':sha(Path(__file__))};(proof/'workspace-integrated-frozen-worker.json').write_text(json.dumps(record,indent=2)+'\n');print('BASE',bc,len(be),'CANDIDATE',cc,len(ce));print('\n'.join(record['new_errors']))
