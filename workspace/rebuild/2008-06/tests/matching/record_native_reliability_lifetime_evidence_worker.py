import sys,json,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
w=root/'rebuild/2008-06/out/native-layouts/rakpeer-update-fieldoverlay-worker';p=w/'ReliabilityLayer.obj';raw=p.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);rows=[]
for pre,a,expected in [('??0ReliabilityLayer@@',0x4d25d0,[('??0BitStream@',0x4a50c0),('??0DataBlockEncryptor@@',0x4d5980),('?InitializeVariables@ReliabilityLayer@@',0x4cea10)]),('??1ReliabilityLayer@@',0x4d3b40,[('?FreeThreadSafeMemory@ReliabilityLayer@@',0x4d2780),('??1BitStream@',0x4a51a0),('??1DataBlockEncryptor@@',0x47d410)])]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%a);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=secs[idx];bindings={}
 for i in range(tab[7]):
  o,k,typ=struct.unpack_from('<IIH',raw,tab[5]+i*10);o-=start
  if typ==20 and 0<=o<len(b)-3:bindings[syms[k][0]]=(a+o+4+struct.unpack_from('<i',t,o)[0])&0xffffffff
 for key,val in expected:assert any(k.startswith(key) and v==val for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(a),'symbol':n,'size':len(b),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()}})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();out={'scope':'Isolated field and ctor guard adaptation only. No full method/runtime ABI claim.','remote_size':'0x850','remote_ctor':'0x4bb5d0','remote_dtor':'0x4bb620','methods':rows,'source_sha256':sha(w/'ReliabilityLayer.cpp'),'header_sha256':sha(w/'ReliabilityLayer.h'),'object_sha256':sha(p),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/reliability-overlay-lifetime-worker.json').write_text(json.dumps(out,indent=2)+'\n');print('PASS ReliabilityLayer ctor, dtor, selected call targets')
