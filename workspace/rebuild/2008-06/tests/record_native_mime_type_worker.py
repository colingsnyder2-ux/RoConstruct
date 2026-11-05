import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insertdecal-mime-worker';work.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/tests/NativeMimeTypeWorker.cpp';obj=work/'MimeWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?getMimeType@'));target,targetrefs,_=match.target('2008-06','00437d60');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x437d60+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?resolveFormat@GImage@',0x50edb0),('?declare@Name@',0x553f90),('?getNullName@Name@',0x554270)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase
for value in ('image/jpeg','image/bmp','image/vnd.microsoft.icon','image/png'):assert any(k.startswith('??_C@') and pe.get_string_at_rva(v-image)==value.encode() for k,v in bindings.items()),value
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive MIME type helper matches bytes, calls and string literals; switch table and runtime ABI unproven.','address':'0x437d60','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/mime-type-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS MIME helper bytes and targets')
