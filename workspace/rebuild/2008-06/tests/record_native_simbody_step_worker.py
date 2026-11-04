import sys,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/simbody-step-worker';(out/'v8kernel').mkdir(parents=True,exist_ok=True);(out/'util').mkdir(exist_ok=True)
donor=root/'tools/rbxgs/Client/App/include/v8kernel/SimBody.h';s=donor.read_text().replace('Body *body;\n\t\t\tbool dirty;','Body *body;\n            float dt;\n\t\t\tbool dirty;').replace('G3D::Vector3 torque;','G3D::Vector3 torque;\n            G3D::Vector3 impulse;\n            G3D::Vector3 angularImpulse;').replace('void step(float dt);','void step();');(out/'v8kernel/SimBody.h').write_text(s)
q=(root/'tools/rbxgs/Client/App/include/util/Quaternion.h').read_text();assert q.count('void normalize();')==1;q=q.replace('void normalize();','void normalize() { *this *= 1.0f / magnitude(); }');(out/'util/Quaternion.h').write_text(q)
mined=root/'src/2008-06/00658fb0.cpp';body=mined.read_text().split('void SimBody::step(){',1)[1].rsplit('}',2)[0];source='#include "v8kernel/SimBody.h"\nnamespace RBX {\nG3D::Vector3 computeRotVel(const G3D::Matrix3&,const G3D::Vector3&,const G3D::Vector3&);\nvoid SimBody::step(){'+body+'}\n}\n';src=out/'SimBodyStepCandidate.cpp';src.write_text(source);obj=out/'SimBodyStepCandidate.obj';inc=[out,root/'rebuild/2008-06/native-headers']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK'];defs=libs.RECIPES['rbxgs']['defines'].split();flags=['/nologo','/c','/O2','/GS-','/EHsc','/MD','/fp:fast','/Fo'+str(obj)]+['/I'+str(i) for i in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?step@SimBody@RBX@@'));target,tr,_=match.target('2008-06','00658fb0');exact=match.exact_match(target,tr,body,refs);sections,symbols,defs,_=match._coff_data_index(raw);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3 and len(body)==len(target):
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x658fb0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=hex(value)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Server-matched source body adapted to isolated donor headers; synthetic mined type declarations replaced by donor header overlays. Exact check masks relocations; if nonexact no bindings can be inferred.','original':'0x658fb0','exact':exact,'candidate_size':len(body),'target_size':len(target),'bindings_if_same_size':bindings,'mined_sha256':sha(mined),'candidate_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/simbody-step-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
for prefix,address in [('?update@SimBody@RBX@@AAEXXZ',0x658d20),('?computeRotVel@RBX@@',0x658920),('??DQuaternion@RBX@@',0x658a30),('?toRotationMatrix@Quaternion@RBX@@',0x5dd6d0)]:assert any(k.startswith(prefix) and v==hex(address) for k,v in bindings.items()),(prefix,bindings)
assert exact
print('PASS step bytes and four original call targets; target identities inferred from typed candidate')
