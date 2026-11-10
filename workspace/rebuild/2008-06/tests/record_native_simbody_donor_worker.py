import sys,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/simbody-donor-worker';over=out/'v8kernel';over.mkdir(parents=True,exist_ok=True);donor=root/'tools/rbxgs/Client/App/include/v8kernel/SimBody.h';s=donor.read_text();a='Body *body;\n\t\t\tbool dirty;';b='G3D::Vector3 torque;';c='SimBody(RBX::Body* body);';assert s.count(a)==s.count(b)==s.count(c)==1;s=s.replace(a,'Body *body;\n            float dt;\n\t\t\tbool dirty;').replace(b,b+'\n            G3D::Vector3 unknownVector9c;\n            G3D::Vector3 unknownVectorA8;').replace(c,'SimBody(RBX::Body* body) throw();');(over/'SimBody.h').write_text(s)
src=root/'rebuild/2008-06/tests/NativeSimBodyDonorWorker.cpp';obj=out/'NativeSimBodyDonorWorker.obj';inc=[out,root/'rebuild/2008-06/native-headers']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK'];defs=libs.RECIPES['rbxgs']['defines'].split();flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(i) for i in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();functions=match.coff_functions(raw);sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for pre,addr in [('??0SimBody@RBX@@',0x658ae0),('??1SimBody@RBX@@',0x47d410)]:
 name,body,refs=next(x for x in functions if x[0].startswith(pre));target,tr,_=match.target('2008-06','%08x'%addr);assert match.exact_match(target,tr,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(addr+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
 rows.append({'symbol':name,'address':hex(addr),'size':len(body),'bindings':bindings})
assert rows[0]['bindings']['??0CoordinateFrame@G3D@@QAE@XZ']=='0x4782d0' and rows[0]['bindings']['??0Velocity@RBX@@QAE@XZ']=='0x614170'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Isolated donor class with observed 2008 dt and two zero-initialized vectors added. No type-name aliases used. Both lifetimes byte-identical and constructor selected call edges recorded; vector purposes unknown, destructor is empty so weak layout proof. No runtime integration.','size':'0xb4','dt':'0x4','pv':'0xc','force':'0x84','unknownVector9c':'0x9c','unknownVectorA8':'0xa8','methods':rows,'donor_sha256':sha(donor),'override_sha256':sha(over/'SimBody.h'),'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/simbody-donor-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS donor SimBody 0xb4 ctor/dtor, timestep +4, selected call bindings')
