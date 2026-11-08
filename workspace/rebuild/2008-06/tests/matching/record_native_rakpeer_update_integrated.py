import sys,json,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
w=root/'rebuild/2008-06/out/native-layouts/rakpeer-update-integrated';w.mkdir(parents=True,exist_ok=True);donor=root/'tools/openrbx/3rdparty/RakNet30/Source';src=root/'rebuild/2008-06/native-classes/RakPeerUpdate.cpp'
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];i=next(i for i,x in enumerate(flags) if x.startswith('/I'));flags[i+1:i+1]=['/I'+str(donor),'/I'+str(root/'tools/openrbx/util'),'/I'+str(root/'tools/rbxgs/Client/Network')];obj=w/'RakPeerUpdate.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],w);(w/'compile.log').write_text(log);print('compile',c);print('\n'.join(x for x in log.splitlines() if 'error C' in x)[:3500]);rows=[]
if not c:
 n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?RunUpdateCycle@RakPeer@@'));t,tr,_=match.target('2008-06','004c5290');rows.append({'symbol':n,'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)});print(rows)
import struct
raw=obj.read_bytes();sec,sy,defs,_=match._coff_data_index(raw);result=[]
for prefix,addr,expected in [('?RunUpdateCycle@RakPeer@@MAE',0x4c5290,[('?RecvFrom@SocketLayer@@',0x4ce6b0),('?Update@ReliabilityLayer@@',0x4d3610),('?AllocPacket@@YAPAUPacket@@IPAE',0x4bb5b0)]),('?AllocPacket@@YAPAUPacket@@I@Z',0x4bb580,[]),('?AllocPacket@@YAPAUPacket@@IPAE@Z',0x4bb5b0,[])]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%addr);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=sec[idx];bindings=[]
 for i in range(tab[7]):
  off,k,typ=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   v=struct.unpack_from('<I',t,off)[0]
   if typ==20:v=(addr+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings.append({'offset':hex(off),'symbol':sy[k][0],'target':hex(v),'kind':typ})
 for key,val in expected:assert any(x['symbol'].startswith(key) and x['target']==hex(val) for x in bindings),(key,bindings)
 result.append({'address':hex(addr),'symbol':n,'size':len(b),'exact':True,'bindings':bindings})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Integrated native OpenRBX method and two real helpers; not yet runtime selected. 139 original relocation target mappings do not prove final linked provider identity or complete runtime ABI.','methods':result,'source_sha256':sha(src),'donor_sha256':sha(donor/'RakPeer.cpp'),'object_sha256':sha(obj),'rakpeer_header_sha256':sha(root/'rebuild/2008-06/native-headers/RakPeer.h'),'rakpeer_interface_sha256':sha(root/'rebuild/2008-06/native-headers/RakPeerInterface.h'),'reliability_header_sha256':sha(root/'rebuild/2008-06/native-headers/ReliabilityLayer.h'),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/rakpeer-update-integrated.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS update, two AllocPacket helpers, selected targets')
