import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/body-mass-state-worker';s=(root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp').read_text();old='static int getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }';s=s.replace(old,'static int getNextStateIndex();');marker='Body::Body()\n';defs=['int Body::getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }','inline int Body::getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }','__forceinline int Body::getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }'];target,refs,_=match.target('2008-06','006149c0');rows=[]
for i,d in enumerate(defs):
 src=work/('outofclass%d.cpp'%i);obj=work/('outofclass%d.obj'%i);src.write_text(s.replace(marker,d+'\n'+marker));flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work)
 if c:print(i,'compile fail',log[-500:],flush=True);continue
 n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Body@RBX@@'));exact=match.exact_match(target,refs,b,r);rows.append({'variant':i,'size':len(b),'exact':exact});print(rows[-1],flush=True)
 if exact:break
(work/'outofclass-results.json').write_text(json.dumps(rows,indent=2))
import struct,hashlib
obj=work/'outofclass0.obj';raw=obj.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);results=[]
for address,prefix,expected in [(0x6149c0,'??0Body@RBX@@',[('??0CoordinateFrame@',0x4782d0),('?identity@Matrix3@',0x513e20),('??0Matrix3@',0x513220),('?p@?1??getNextStateIndex@',0x95a898),('??0Velocity@',0x614170),('??2@YAPAXI@Z',0x6a0920),('??0SimBody@',0x658ae0)]),(0x614ac0,'??1Body@RBX@@',[('?setParent@Body@',0x6148b0),('??1SimBody@',0x47d410),('??3@YAXPAX@Z',0x6a067a),('?alignedFree@System@G3D@@',0x507d20)])]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%address);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=secs[idx];bindings={}
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   value=struct.unpack_from('<I',t,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings[syms[sym][0]]=value
 for k,v in expected: assert any(x.startswith(k) and a==v for x,a in bindings.items()),(k,bindings)
 results.append({'address':hex(address),'size':len(b),'symbol':n,'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()}})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();record={'scope':'Isolated hypothesis: Body prefix fields and SimBody shape are provisional; never promote or run from byte match alone.','methods':results,'base_sha256':sha(root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp'),'generated_source_sha256':sha(work/'outofclass0.cpp'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/body-outofclass-ctor-worker.json').write_text(json.dumps(record,indent=2)+'\n');print('PASS Body ctor/dtor bytes and selected bindings')
