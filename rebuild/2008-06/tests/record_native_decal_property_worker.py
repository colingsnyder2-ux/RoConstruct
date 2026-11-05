import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insertdecal-worker';work.mkdir(exist_ok=True);src=root/'rebuild/2008-06/tests/NativeDecalPropertyWorker.cpp';obj=work/'DecalPropertyWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('??__E?prop_Texture@Decal@',0x7f4190,[('?setTexture@Decal@',0x598610),('?getTexture@Decal@',0x4e5bb0),('?prop_Texture@Decal@',0x975f14),('??$?0P8Decal@',0x598100),('??__F?prop_Texture@',0x7fdb60),('_atexit',0x6a17af)]),('??$?0P8Decal@',0x598100,[('??$getset@P8Decal@',0x597910),('?classDescriptor@',0x598020),('??0?$TypedPropertyDescriptor@',0x5978a0),('??_7?$PropDescriptor@',0x8325a0)]),('?getTexture@Decal@',0x4e5bb0,[]),('??__F?prop_Texture@Decal@',0x7fdb60,[('?prop_Texture@Decal@',0x975f14),('??_7Descriptor@',0x80b730)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;bindings=rows[0]['bindings'];assert any(k.startswith('??_C@') and pe.get_string_at_rva(int(v,16)-image)==b'Texture' for k,v in bindings.items());assert any(k.startswith('??_C@') and pe.get_string_at_rva(int(v,16)-image)==b'Appearance' for k,v in bindings.items())
key=next(k for k in defs if k.startswith('?prop_Texture@Decal@'));offset,index=defs[key];assert sections[index][3]-offset==28
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive real Texture property descriptor, constructor/getter/init/dtor match bytes and selected targets; static initialization order, complete reflection lifetime and runtime ABI remain unproven.','object_size':28,'original_address':'0x975f14','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/decal-property-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Decal property initializer, constructor, getter and destructor')
