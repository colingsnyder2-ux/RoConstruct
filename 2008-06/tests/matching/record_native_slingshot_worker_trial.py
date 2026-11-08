import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-slingshot';work.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/experiments/trials/NativeSlingshotWorkerTrial.cpp';header=src.with_suffix('.h');obj=work/'NativeSlingshotWorkerTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);fs=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('??0ShootTool@',0x63e850,[('??0MouseCommand@',0x6159f0),('??_7ShootTool@RBX@@6BINamed',0x84a364),('??_7ShootTool@RBX@@6BIRenderable',0x84a348)]),('??1ShootTool@',0x5c79d0,[('??1MouseCommand@',0x615780)]),('??_GSlingshotTool@',0x5c7af0,[('??1ShootTool@',0x5c79d0),('??3@',0x6a067a)]),('?newMouseCommand@?$TToolVerb@VSlingshotTool',0x5c7b10,[('??0ShootTool@',0x63e850),('??_7SlingshotTool@RBX@@6BINamed',0x839a64),('??_7SlingshotTool@RBX@@6BIRenderable',0x839a4c)]),('?isChecked@?$TToolVerb@VSlingshotTool',0x5c7a50,[('___RTtypeid',0x6a1de2),('??_R0?AVSlingshotTool@',0x950a94)])]:
 name,body,refs=next(x for x in fs if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(name,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0]
for vt,expected in [(0x839a64,b'.?AVSlingshotTool@RBX@@'),(0x84a364,b'.?AVShootTool@RBX@@')]:assert pe.get_string_at_rva(rd(rd(vt-4)+12)+8-image)==expected
assert rd(0x839a64+12*4)==0x5c7af0;assert rd(0x839a30+3*4)==0x5c7a50 and rd(0x839a30+5*4)==0x5c7b10
col=rd(0x839a64-4);hierarchy=rd(col+16);n=rd(hierarchy+8);array=rd(hierarchy+12);bases=[pe.get_string_at_rva(rd(rd(array+i*4))+8-image).decode() for i in range(n)];assert any('?$Named@VShootTool@' in x for x in bases) and '.?AVShootTool@RBX@@' in bases and '.?AVMouseCommand@RBX@@' in bases
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive 0x30 Slingshot and ShootTool ctor, base destructor, derived deleting destructor, factory and checked match original bytes, calls and RTTI. Projectile type, extra virtual declarations, full object lifetime and runtime ABI unproven.','size':'0x30','rtti_bases':bases,'methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/slingshot-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Slingshot constructor, destructor, factory and checked')
