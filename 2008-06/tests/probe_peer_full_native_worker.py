"""Frozen mixed-ABI diagnostic; never execute output."""
import hashlib,json,re,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'peer-full-native-worker';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
specs=[('peer-constructor','PeerConstructor.obj'),('peer-lifetime','PeerLifetime.obj'),('peer-update','PeerUpdate.obj'),('profiled-rakpeer','ProfiledRakPeer.obj'),('rakpeer-bandwidth','RakPeerBandwidth.obj'),('rakpeer-lifetime','RakPeerLifetime.obj')];objects=[];hashes={}
for key,filename in specs:
 receipt=json.loads((proof/(key+'-integrated.json')).read_text());src=out/(key+'-integrated')/filename;assert sha(src)==receipt['object_sha256'],key;dst=work/filename;dst.write_bytes(src.read_bytes());objects.append(dst);hashes[key]=sha(dst)
archive_inputs=[(out/'replicator-rebuild-worker/patched.lib','Replicator.obj',('??0Peer@Network@RBX@@','??1Peer@Network@RBX@@')),(root/'rebuild/2008-06/out/RakNet/linked/linked.lib','RakPeer.obj',('??0RakPeer@@','??1RakPeer@@','?SetPerConnectionOutgoingBandwidthLimit@RakPeer@@'))];replacement={};removed={}
for idx,(archive,member,prefixes) in enumerate(archive_inputs):
 name,raw=next((str(n),b) for n,b in libs.archive_members(archive) if str(n).replace('\\','/').split('/')[-1].lower()==member.lower());defs=rebuild.coff_externals(raw);drop={s for s,v in defs.items() if v and any(s.startswith(x) for x in prefixes)};assert len(drop)==len(prefixes),(name,drop)
 patched=work/('%d_'%idx+member);patched.write_bytes(rebuild.strip_symbols(raw,drop=drop));before={n for n,b,r in match.coff_functions(raw)};after={n for n,b,r in match.coff_functions(patched.read_bytes())};lost=before-after
 assert all(n in drop or any(n.startswith('__ehhandler$'+x) or n.startswith('__unwindfunclet$'+x) for x in drop) for n in lost),lost
 newarchive=work/('%d.lib'%idx);code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:'+name,'/OUT:'+str(newarchive),str(archive),str(patched)],work);assert code==0,log;replacement[str(archive).lower()]=str(newarchive);removed[member]={'source_sha256':sha(archive),'member_sha256':hashlib.sha256(raw).hexdigest(),'patched_sha256':sha(patched),'archive_sha256':sha(newarchive),'symbols':sorted(drop),'removed_functions':sorted(lost)}
args=[]
for line in (out/'replicator-rebuild-worker/probe.rsp').read_text().splitlines():
 arg=line.strip().strip(chr(34))
 if arg.upper().startswith('/OUT:'):arg='/OUT:'+str(work/'probe.exe')
 elif arg.upper().startswith('/MAP:'):arg='/MAP:'+str(work/'probe.map')
 elif arg.endswith('peer-update-workspace-worker/PeerUpdate.obj') or arg.replace('\\','/').endswith('/peer-update-workspace-worker/PeerUpdate.obj'):continue
 else:arg=replacement.get(arg.lower(),arg)
 args.append(arg)
args+=list(map(str,objects));rsp=work/'probe.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/'probe.log').write_text(log)
errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)];data={'scope':'Frozen mixed ABI diagnostic only. Do not execute; full vtables, targets, native profiler and writer unproven.','objects':hashes,'archive_replacements':removed,'exit':code,'errors':errors};(proof/'peer-full-native-worker.json').write_text(json.dumps(data,indent=2)+'\n');print('link',code,'errors',len(errors));print('\n'.join(errors[:15]))
