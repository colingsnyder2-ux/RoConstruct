"""Isolated frozen Peer::Update swap, not executable or full ABI proof."""
import hashlib,json,re,struct,subprocess,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'peer-update-workspace-worker';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';prior=out/'workspace-profiler-name-worker';base=out/'workspace-profiler-callers-worker/replaced.lib'
baseproof=json.loads((proof/'workspace-profiler-name-worker.json').read_text());record=json.loads((proof/'profiling-integrated.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(base)==baseproof['archive_sha256']
src=root/'rebuild/2008-06/native-classes/PeerUpdate.cpp';obj=work/'PeerUpdate.obj';flags=[x for x in record['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags+=['/I'+str(root/'tools/rbxgs/Client/Network/raknet30/Source'),'/I'+str(root/'tools/rbxgs/Client/Network')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?Update@Peer@Network@RBX@@'));target,tr,_=match.target('2008-06','0070bdf0');assert body==target==bytes.fromhex('c20400') and match.exact_match(target,tr,body,refs)
p=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=p.OPTIONAL_HEADER.ImageBase;assert struct.unpack('<I',p.get_data(0x8248a8-image,4))[0]==0x70bdf0
members=[b for n,b in libs.archive_members(base) if str(n)=='Replicator.obj'];assert len(members)==1;raw=members[0];symbol=name;assert rebuild.coff_externals(raw).get(symbol);patched=work/'Replicator.obj';patched.write_bytes(rebuild.strip_symbols(raw,drop={symbol}));assert not rebuild.coff_externals(patched.read_bytes()).get(symbol)
archive=work/'patched.lib';code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:Replicator.obj','/OUT:'+str(archive),str(base),str(patched)],work);assert code==0,log
args=[]
for line in (prior/'candidate.rsp').read_text().splitlines():
 arg=line.strip().strip(chr(34))
 if arg.upper().startswith('/OUT:'):arg='/OUT:'+str(work/'probe.exe')
 elif arg.upper().startswith('/MAP:'):arg='/MAP:'+str(work/'probe.map')
 elif arg.lower()==str(base).lower():arg=str(archive)
 args.append(arg)
args.append(str(obj));rsp=work/'probe.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/'probe.log').write_text(log)
errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)];result={'scope':'Mixed ABI frozen diagnostic only; never execute. Original Peer Update verified, class layout and runtime not proven.','source_sha256':sha(src),'object_sha256':sha(obj),'donor_member_sha256':hashlib.sha256(raw).hexdigest(),'patched_member_sha256':sha(patched),'archive_sha256':sha(archive),'baseline_errors':baseproof['candidate_errors'],'errors':errors,'exit':code};(proof/'peer-update-workspace-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('baseline',len(baseproof['candidate_errors']),'candidate',len(errors));print('\n'.join(errors))
