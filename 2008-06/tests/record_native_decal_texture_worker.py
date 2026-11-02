import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insertdecal-texture-worker';overlay=work/'v8tree';overlay.mkdir(parents=True,exist_ok=True);header=root/'rebuild/2008-06/native-headers/v8tree/Instance.h';data=header.read_text();assert data.count('void raisePropertyChanged(const Reflection::PropertyDescriptor&);')==1;(overlay/'Instance.h').write_text(data)
src=root/'rebuild/2008-06/tests/NativeDecalTextureWorker.cpp';obj=work/'DecalTextureWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?setTexture@Decal@'));target,targetrefs,_=match.target('2008-06','00598610');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x598610+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?raisePropertyChanged@Instance@',0x40db00),('?prop_Texture@Decal@',0x975f14)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive Decal::setTexture matches bytes and targets; descriptor data and runtime ownership unproven.','address':'0x598610','size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'header_sha256':sha(header),'overlay_sha256':sha(overlay/'Instance.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/decal-texture-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Decal texture setter and targets')
