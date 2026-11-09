import sys,json,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
work=root/'rebuild/2008-06/out/native-layouts/rakpeer-update-fieldoverlay-worker';obj=work/'RakPeer.obj';raw=obj.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address in [('?RunUpdateCycle@RakPeer@@MAE',0x4c5290),('??0RemoteSystemStruct@RakPeer@@',0x4bb5d0),('??1RemoteSystemStruct@RakPeer@@',0x4bb620)]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%address);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=secs[idx];bindings=[]
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   v=struct.unpack_from('<I',t,off)[0]
   if kind==20:v=(address+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings.append({'offset':hex(off),'symbol':syms[sym][0],'target':hex(v),'kind':kind})
 rows.append({'address':hex(address),'symbol':n,'size':len(b),'exact':True,'bindings':bindings})
 print(hex(address),'relocations',len(bindings));
 if address==0x4c5290:
  assert any(x['symbol'].startswith('?RecvFrom@SocketLayer@@') and x['target']=='0x4ce6b0' for x in bindings)
for row in rows[1:]:print(row['address'],row['bindings'])
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated copy of genuine ReliabilityLayer.h with existing simulator members present under _RELEASE; method byte checks, relocation mappings only. Full ReliabilityLayer constructor/destructor, peer ABI, final linked target identity and runtime unproven.','methods':rows,'candidate_object_sha256':sha(obj),'overlay_header_sha256':sha(work/'ReliabilityLayer.h'),'rakpeer_header_sha256':sha(root/'rebuild/2008-06/native-headers/RakPeer.h'),'donor_source_sha256':sha(root/'tools/openrbx/3rdparty/RakNet30/Source/RakPeer.cpp'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/rakpeer-update-abi-evidence-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')
