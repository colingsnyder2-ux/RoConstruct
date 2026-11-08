import sys,struct,hashlib,json
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/part-layout-worker';base=work/'PartContentBodyWorker.cpp';s=base.read_text();s=s.replace('float elapsed;', 'float dt;').replace('SimBody(RBX::Body* body);','SimBody(RBX::Body* body) throw();');s+='\nnamespace RBX { SimBody::SimBody(Body* b) throw():body(b),dt(0.0f),dirty(1),constantForceY(0.0f),force(G3D::Vector3::zero()),torque(G3D::Vector3::zero()),extraVec1(G3D::Vector3::zero()),extraVec2(G3D::Vector3::zero()) {} SimBody::~SimBody() {} }\n';src=work/'SimBodyLifetimeWorker.cpp';src.write_text(s);obj=work/'SimBodyLifetimeWorker.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();funcs=match.coff_functions(raw)
for p,a in [('??0SimBody@RBX@@',0x658ae0),('??1SimBody@RBX@@',0x47d410)]:
 n,b,r=next(x for x in funcs if x[0].startswith(p));t,tr,_=match.target('2008-06','%08x'%a);print(p,len(b),len(t),match.exact_match(t,tr,b,r))
sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address in [('??0SimBody@RBX@@',0x658ae0),('??1SimBody@RBX@@',0x47d410)]:
 name,body,refs=next(x for x in funcs if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':bindings})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated hypothesis. Constructor and destructor byte matches establish lifetime and sizes; vector names and purpose remain unknown, dt name supported by historical experimental generator but not independently verified. Relocations are recorded, not by themselves proof of callee identity. Do not promote.', 'size':'0xb4','body':'0x0','dt_candidate':'0x4','dirty':'0x8','pv':'0xc','qOrientation':'0x54','angMomentum':'0x64','momentRecip':'0x70','massRecip':'0x7c (not initialized)','constantForceY':'0x80','force':'0x84','torque':'0x90','unknown_vector_1':'0x9c','unknown_vector_2':'0xa8','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/simbody-lifetime-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(rows,indent=2))
