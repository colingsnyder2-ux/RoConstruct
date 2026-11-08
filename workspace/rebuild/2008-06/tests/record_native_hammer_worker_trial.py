import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-hammer';work.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/experiments/trials/NativeHammerWorkerTrial.cpp';header=src.with_suffix('.h');obj=work/'NativeHammerWorkerTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);fs=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?newMouseCommand@?$TToolVerb@VHammerTool',0x5c7920,[('??2@',0x6a0920),('??0MouseCommand@',0x6159f0),('??_7HammerTool@RBX@@6BINamed',0x8399ec),('??_7HammerTool@RBX@@6BIRenderable',0x8399d4)]),('?isChecked@?$TToolVerb@VHammerTool',0x5c7860,[('___RTtypeid',0x6a1de2),('??_R0?AVHammerTool@',0x9509e8)]),('??1HammerTool@',0x63fe00,[('??1MouseCommand@',0x615780)]),('??_GHammerTool@',0x63fe80,[('??1HammerTool@',0x63fe00),('??3@',0x6a067a)])]:
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
assert pe.get_string_at_rva(rd(rd(0x8399ec-4)+12)+8-image)==b'.?AVHammerTool@RBX@@';assert rd(0x8399ec+12*4)==0x63fe80;assert rd(0x8399b8+3*4)==0x5c7860 and rd(0x8399b8+5*4)==0x5c7920
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive 0x24 HammerTool has inlined constructor stores, destructor and deleting destructor byte matches plus RTTI/vtable proof. Other virtual methods, static names, EH metadata and runtime ABI unproven.','size':'0x24','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/hammer-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Hammer constructor, destructor, deleting destructor, factory and checked')
