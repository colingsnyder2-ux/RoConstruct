import sys,json,struct,hashlib,shutil,re,subprocess
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
out=root/'rebuild/2008-06/out/native-layouts';work=out/'workspace-ctor-swap-worker';work.mkdir(exist_ok=True);prior=out/'worker-writer-near/full-probe';proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'workspace-writer-near-full-worker-probe.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
source=out/'NativeWorkspaceSharedLifetime.cpp';s=source.read_text();before='CodeProfiler(const char* name);\n\tchar data[0xc040];';after='CodeProfiler(const char* name);\n\tvirtual ~CodeProfiler();\n\tchar data[0xc03c];';assert s.count(before)==1;s=s.replace(before,after,1)
before='template<class Class, class Event> class Notifier {\npublic:\n\tNotifier();\n\tvirtual ~Notifier();\n\tchar pad[0x1c];\n};';after='template<class Class, class Event> class Listener;\nstruct RaiseRange;\ntemplate<class Class, class Event> class __declspec(novtable) Notifier {\n    std::vector<Listener<Class, Event>*> listeners;\n    RaiseRange* raiseRange;\npublic:\n    Notifier();\n    virtual ~Notifier() {}\n    virtual void onAddListener(Listener<Class, Event>*) const {}\n    virtual void onRemoveListener(Listener<Class, Event>*) const {}\n};';assert s.count(before)==1;s=s.replace(before,after,1);src=work/'WorkspaceLifetime.cpp';src.write_text(s);obj=work/'WorkspaceLifetime.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work);assert c==0,log
raw=obj.read_bytes();rows=[];secs,syms,defs,_=match._coff_data_index(raw)
for prefix,a in [('??0Workspace@RBX@@',0x5a4d90),('??1Workspace@RBX@@',0x5a28c0)]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%a);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=secs[idx];binding={}
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start
  if kind==20 and 0<=off<len(b)-3:
   value=(a+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff;binding.setdefault(syms[sym][0],set()).add(value)
 rows.append({'symbol':n,'address':hex(a),'size':len(b),'bindings':{k:[hex(v) for v in sorted(x)] for k,x in binding.items()}})
ctor=rows[0]['symbol'];assert len([k for k,v in rebuild.coff_externals(raw).items() if v and k.startswith('??0Workspace@RBX@@')])==1
for pre,address in [('??0?$DescribedNonCreatable@VWorkspace@',0x5a4280),('??0VerbContainer@',0x583460),('??0IMovingManager@',0x614dc0),('??0?$Notifier@VWorkspace@',0x5e9ec0),('?createHopper@',0x45db40),('??2@YAPAXI@Z',0x6a0920),('??0CodeProfiler@',0x5c43a0),('?setName@Instance@',0x55af90)]:assert any(k.startswith(pre) and address in vals for k,vals in binding.items()) if False else any(k.startswith(pre) and hex(address) in vals for k,vals in rows[0]['bindings'].items()),(pre,rows[0])
paths={};old=None
for index,path in enumerate(base['snapshot_objects']):
 p=prior/('%03d'%index)/Path(path).name
 assert p.exists() and sha(p)==base['snapshot_objects'][path],('stale frozen',path)
 paths[str(root/path).lower()]=str(p)
 if path.replace('\\','/').endswith('workspace-source-probe/WorkspaceWithoutDefault.obj'):old=p
assert old
oldraw=old.read_bytes();olds=[k for k,v in rebuild.coff_externals(oldraw).items() if v and k.startswith('??0Workspace@RBX@@')];assert olds==[ctor],olds
oldfiltered=work/'donor-no-ctor.obj';oldfiltered.write_bytes(rebuild.strip_symbols(oldraw,drop={ctor}));candidate=work/'candidate-ctor-only.obj';candidate.write_bytes(rebuild.strip_symbols(raw,keep={ctor}));assert rebuild.coff_externals(candidate.read_bytes()).get(ctor) and not rebuild.coff_externals(oldfiltered.read_bytes()).get(ctor)
archive=out/'document-swap-link-trial/RbxgsAppWithoutInstance.lib';frozen_archive=prior/'baseline.lib';assert frozen_archive.exists();paths[str(archive).lower()]=str(frozen_archive)
def link(name,replace):
 args=[]
 for arg in [line.strip().strip(chr(34)) for line in (prior/'baseline.rsp').read_text().splitlines() if line.strip()]:
  if arg.upper().startswith('/OUT:'):arg='/OUT:'+name+'.exe'
  elif arg.upper().startswith('/MAP:'):arg='/MAP:'+name+'.map'
  else:arg=paths.get(arg.lower(),arg)
  if replace and arg==str(old):arg=str(oldfiltered)
  args.append(arg)
 if replace:args.append(str(candidate))
 rsp=work/(name+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');c,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/(name+'.log')).write_text(log);errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)];return c,errors
bc,be=link('baseline',False);cc,ce=link('candidate',True);record={'scope':'ISOLATED LINK DIAGNOSTIC ONLY: ctor based on provisional placeholder class definitions; no runtime or ABI safety established. Do not run. Original expected direct target mapping is not final linked target resolution.','baseline_exit':bc,'baseline_errors':be,'candidate_exit':cc,'candidate_errors':ce,'new_errors':[e for e in ce if e not in set(be)],'methods':rows,'frozen_archive_sha256':sha(frozen_archive),'old_object_sha256':sha(old),'old_filtered_sha256':sha(oldfiltered),'candidate_original_sha256':sha(obj),'candidate_filtered_sha256':sha(candidate),'source_sha256':sha(src),'observer_sha256':sha(Path(__file__))};(proof/'workspace-ctor-swap-worker.json').write_text(json.dumps(record,indent=2)+'\n');print('BASE',bc,len(be),'CANDIDATE',cc,len(ce));print('\n'.join(record['new_errors']))
