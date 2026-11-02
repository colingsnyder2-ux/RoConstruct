import hashlib,json,struct,sys
import pefile
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/insert-service';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];overlay=out/'dialog-overlay';(overlay/'v8tree').mkdir(parents=True,exist_ok=True);service=(root/'rebuild/2008-06/native-headers/v8tree/Service.h').read_text();assert service.count('    static size_t newIndex();')==1;(overlay/'v8tree/Service.h').write_text(service.replace('    static size_t newIndex();','    static Instance* create(Instance*, const Name&);\n    static size_t newIndex();'));(overlay/'StandardVerbs.h').write_text((root/'rebuild/2008-06/native-headers/StandardVerbs.h').read_text());flags.insert(0,'/I'+str(overlay));obj=out/'NativeClassImagesTrial.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(root/'rebuild/2008-06/tests/NativeClassImagesTrial.cpp')],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('??0CClassImages@@',0x413230,[('??0CImageList@@',0x6a0e48),('?LoadBitmapFromResource@CXTPImageManagerIcon@@',0x6bc520),('?Create@CImageList@@',0x6a0e42),('?_ImageList_Add@CComCtlWrapper@@',0x412fc0),('?_ImageList_AddMasked@CComCtlWrapper@@',0x4130d0),('??_7CClassImages@@',0x80e864)]),('??1CClassImages@@',0x412f30,[('??1CImageList@@',0x6a0e2a),('??_7CClassImages@@',0x80e864)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,sec=defs[name];table=sections[sec];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));baseaddr=pe.OPTIONAL_HEADER.ImageBase;u32=lambda va:struct.unpack('<I',pe.get_data(va-baseaddr,4))[0];assert pe.get_string_at_rva(u32(u32(0x80e860)+12)-baseaddr+8)==b'.?AVCClassImages@@'
link=out/'NativeClassImagesLink.obj';link.write_bytes(rebuild.strip_symbols(raw,keep={r['symbol'] for r in rows}))
for row in rows:
 n,b,r=next(x for x in match.coff_functions(link.read_bytes()) if x[0]==row['symbol']);t,tr,_=match.target('2008-06',row['address'][2:].zfill(8));assert match.exact_match(t,tr,b,r)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();src=root/'rebuild/2008-06/tests/NativeClassImagesTrial.cpp';receipt={'scope':'Exact inactive CClassImages constructor/destructor; deleting destructor, vtable selection, image-resource and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'link_object_sha256':sha(link),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/class-images-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS CClassImages constructor/destructor and bindings')
