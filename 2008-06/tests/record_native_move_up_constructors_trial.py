import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeMoveUpConstructorsTrial.cpp';obj=out/'NativeMoveUpConstructorsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rows=[]
for cls,address,label,vtable,value in [('MoveUpPlateVerb',0x5c5400,'SelectionUpPlate',0x83902c,0.4),('MoveUpBrickVerb',0x5c5490,'SelectionUpBrick',0x839044,1.2)]:
 name,body,refs=next(x for x in functions if x[0].startswith('??0'+cls+'@'));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   result=struct.unpack_from('<I',target,off)[0]
   if kind==20:result=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=result
 assert any(k.startswith('??0EditSelectionVerb@') and v==0x57e730 for k,v in bindings.items()),bindings
 assert any(k.startswith('??_7'+cls+'@') and v==vtable for k,v in bindings.items()),bindings
 assert any(k.startswith('??_7MoveUpSelectionVerb@') and v==0x839014 for k,v in bindings.items()),bindings
 assert any(k.startswith('??_C@') and pe.get_string_at_rva(v-image)==label.encode() for k,v in bindings.items()),bindings
 assert struct.unpack('<I',pe.get_data(vtable+16-image,4))[0]==0x581630
 assert any(k.startswith('__real@') and pe.get_data(v-image,4)==struct.pack('<f',value) for k,v in bindings.items()),bindings
 rows.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vtable),'bindings':{k:hex(v) for k,v in bindings.items()}})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive constructors and vtable doIt target match; destructor, lifetime and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/move-up-constructors-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS move-up constructor bytes, base calls and vtables')
