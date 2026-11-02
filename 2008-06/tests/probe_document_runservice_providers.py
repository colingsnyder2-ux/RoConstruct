"""Link-only RunService provider probe; incompatible layouts, never execute."""
import hashlib,json,re,struct,subprocess,sys
import pefile
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,match,rebuild
proof=root/'work/2008-06/shared-layouts';out=root/'rebuild/2008-06/out/native-layouts/doc-runservice-provider-probe';out.mkdir(parents=True,exist_ok=True);sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();prior=json.loads((proof/'document-swap-provider-trial.json').read_text());frozen=json.loads((proof/'workspace-writer-near-full-worker-probe.json').read_text());assert frozen['candidate_exit']==0
archive=root/'rebuild/2008-06/out/native-layouts/document-swap-link-trial/RbxgsAppWithoutInstanceOrPartDragStub.lib';assert sha(archive)==prior['filtered_archive_sha256']
for label,file in [('runservice-fresh-current','NativeRunService.obj'),('service-provider-fresh-current','NativeServiceProvider.obj')]:
 r=json.loads((proof/(label+'.json')).read_text());p=root/'rebuild/2008-06/out/native-layouts'/file;assert sha(p)==r['object_sha256']
 for name,digest in r['sources'].items():assert sha(root/name)==digest,name
run=root/'rebuild/2008-06/out/native-layouts/NativeRunService.obj';service=root/'rebuild/2008-06/out/native-layouts/NativeServiceProvider.obj'
# Function sections allow a selective diagnostic without unrelated class bodies.
for label,source,output in [('runservice-fresh-current','RunService.cpp','RunServiceGy.obj'),('service-provider-fresh-current','ServiceProvider.cpp','ServiceProviderGy.obj')]:
 r=json.loads((proof/(label+'.json')).read_text());src=root/'rebuild/2008-06/native-classes'/source
 if source=='RunService.cpp':
  body=src.read_text();start=body.index('void RunService::setRunState(');end=body.index('\n}\n\nvoid RBX::RunService::invalidateRunViews()',start);src=out/'RunServiceMethodOnly.cpp';src.write_text('#include "util/RunStateOwner.h"\nnamespace RBX {\n'+body[start:end]+'\n}\n')
 flags=[x for x in r['flags'] if not x.startswith('/Fo') and not x.endswith(source)]+['/Gy','/Fo'+str(out/output),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
run=out/'RunServiceGy.obj';service=out/'ServiceProviderGy.obj';names=['?setRunState@RunService@RBX@@QAEXW4RunState@2@@Z','??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ'];selected=[]
for obj,name,address in [(run,names[0],0x554da0),(service,names[1],0x4530f0)]:
 data=obj.read_bytes();symbol,body,relocs=next(x for x in match.coff_functions(data) if x[0]==name);target,target_relocs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,target_relocs,body,relocs),(name,len(body),len(target))
for file,name in [(run,names[0]),(service,names[1])]:
 if '--state-only' in sys.argv and name==names[1]:continue
 data=file.read_bytes();assert rebuild.coff_externals(data).get(name);p=out/(file.stem+'-selected.obj')
 if '--exact-find' in sys.argv and name==names[1]:
  find='??$find@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ';p.write_bytes(rebuild.strip_symbols(data,drop={find}));profile=out.parent/'service-runservice-find-probe/ServiceProviderProfile.obj';pr=json.loads((proof/'service-runservice-find-profile.json').read_text());assert sha(profile)==pr['object_sha256'];keep={x['symbol'] for x in pr['methods']};q=out/'RunServiceFindProfile-selected.obj';q.write_bytes(rebuild.strip_symbols(profile.read_bytes(),keep=keep));selected.append(q)
 else:p.write_bytes(data if '--full-service' in sys.argv and name==names[1] else rebuild.strip_symbols(data,keep={name}))
 selected.append(p)
donor=next(data for name,data in libs.archive_members(archive) if str(name)=='RunStateOwner.obj');assert rebuild.coff_externals(donor).get(names[0]);patched=out/'RunStateOwner.obj';patched.write_bytes(rebuild.strip_symbols(donor,drop={names[0]}));clean=out/'filtered.lib';c,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:RunStateOwner.obj','/OUT:'+str(clean),str(archive)],out);assert c==0,log
c,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/OUT:'+str(clean),str(clean),str(patched)],out);assert c==0,log
args=[]
for line in (root/'rebuild/2008-06/out/native-layouts/worker-writer-near/full-probe/candidate.rsp').read_text().splitlines():
 arg=line.strip().strip(chr(34))
 if arg.upper().startswith('/OUT:'):arg='/OUT:candidate.exe'
 elif arg.upper().startswith('/MAP:'):arg='/MAP:candidate.map'
 elif arg.lower()==str(archive).lower():arg=str(clean)
 args.append(arg)
args=[str(x) for x in selected]+args;rsp=out/'candidate.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([x]) for x in args)+'\n');c,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],out);(out/'candidate.log').write_text(log);errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)];maptext=(out/'candidate.map').read_text(errors='replace') if (out/'candidate.map').exists() else '';selection={n:[line.strip() for line in maptext.splitlines() if n in line][:2] for n in names};receipt={'scope':'Link-only mixed native/donor ABI diagnostic. RunService size/ownership incompatible; never run.','exit':c,'errors':errors,'selection':selection,'native_objects':{str(x):sha(x) for x in (run,service)},'source_archive_sha256':sha(archive),'filtered_archive_sha256':sha(clean),'observer_sha256':sha(Path(__file__))}
if c==0:
 pe=pefile.PE(str(out/'candidate.exe'));verified=[]
 for obj,name,address in [(run,names[0],0x554da0),(service,names[1],0x4530f0)]:
  if '--state-only' in sys.argv and name==names[1]:continue
  line=next(line for line in selection[name] if obj.stem+'-selected.obj' in line);m=re.search(r'\s([0-9a-fA-F]{8})\s+f',line);assert m,line;pe_address=int(m[1],16);symbol,body,relocs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0]==name);target,target_relocs,_=match.target('2008-06','%08x'%address);final=pe.get_data(pe_address-pe.OPTIONAL_HEADER.ImageBase,len(body));assert match.exact_match(target,target_relocs,body,relocs) and match.exact_match(body,relocs,final,relocs);verified.append({'symbol':name,'original_address':hex(address),'pe_address':hex(pe_address),'size':len(body)})
 if '--exact-find' in sys.argv:
  profile=out.parent/'service-runservice-find-probe/ServiceProviderProfile.obj';pr=json.loads((proof/'service-runservice-find-profile.json').read_text());assert sha(profile)==pr['object_sha256']
  for method in pr['methods']:
   name=method['symbol'];line=next(line for line in maptext.splitlines() if name in line and 'RunServiceFindProfile-selected.obj' in line and '__unwind' not in line);m=re.search(r'\s([0-9a-fA-F]{8})\s+f',line);assert m,line;pe_address=int(m[1],16);symbol,body,relocs=next(x for x in match.coff_functions(profile.read_bytes()) if x[0]==name);target,target_relocs,_=match.target('2008-06',method['address']);final=pe.get_data(pe_address-pe.OPTIONAL_HEADER.ImageBase,len(body));assert match.exact_match(target,target_relocs,body,relocs) and match.exact_match(body,relocs,final,relocs);verified.append({'symbol':name,'original_address':method['address'],'pe_address':hex(pe_address),'size':len(body)})
  create_address=int(next(x['pe_address'] for x in verified if x['symbol']==names[1]),16);find_name=pr['methods'][0]['symbol'];find_address=int(next(x['pe_address'] for x in verified if x['symbol']==find_name),16);raw=service.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);start,idx=definitions[names[1]];table=sections[idx];edges=[]
  for i in range(table[7]):
   offset,si,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
   if kind==20 and symbols[si][0]==find_name:
    operand=create_address+offset;disp=pe.get_data(operand-pe.OPTIONAL_HEADER.ImageBase,4);edges.append((operand+4+struct.unpack('<i',disp)[0])&0xffffffff)
  assert edges==[find_address],edges;receipt['create_to_find_pe_target']=hex(find_address)
 receipt.update(exe_sha256=sha(out/'candidate.exe'),map_sha256=sha(out/'candidate.map'),selected_masked_matches=verified)
(proof/('doc-runstate-only-probe.json' if '--state-only' in sys.argv else ('doc-runservice-exact-find-probe.json' if '--exact-find' in sys.argv else ('doc-runservice-full-provider-probe.json' if '--full-service' in sys.argv else 'doc-runservice-provider-probe.json')))).write_text(json.dumps(receipt,indent=2)+'\n');print('link',c,'errors',len(errors));print('\n'.join(errors[:12]));print(selection)

