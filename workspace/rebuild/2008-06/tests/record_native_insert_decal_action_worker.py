import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insertdecal-action-worker';overlay=work/'v8datamodel';overlay.mkdir(parents=True,exist_ok=True);header=root/'rebuild/2008-06/native-headers/v8datamodel/Selection.h';data=header.read_text();needle='void clearSelection();';assert data.count(needle)==1;data=data.replace(needle,needle+'\n    void setSelection(Instance*);');(overlay/'Selection.h').write_text(data)
src=root/'rebuild/2008-06/tests/NativeInsertDecalActionWorker.cpp';obj=work/'NativeInsertDecalActionWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(work),'/I'+str(root/'tools/rbxgs/Client/App')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?doIt@InsertDecal@@',0x41f040,[('??$create@VContentProvider@',0x41eea0),('?registerImageFile@',0x41dd90),('?setTexture@Decal@',0x598610),('?getTarget@InsertDecal@',0x41ef90),('?setParent@Instance@',0x55a8f0),('??$create@VSelection@',0x4153b0),('?setSelection@Selection@',0x567770),('?recordCameraHistory@',0x58c5c0),('?DoModal@CFileDialog@',0x6a0e6c)]),('?registerImageFile@@',0x41dd90,[('?getMimeType@',0x437d60),('?registerImageContent@',0x55fbc0)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<I',pe.get_data(0x80f15c+16-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x41f040
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive InsertDecal action and file registration helper match bytes and call targets; layout, ownership, MFC runtime, and exception handling unproven. Selection declaration overlay; old noinline std::string/CString profiles.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'selection_header_sha256':sha(header),'overlay_sha256':sha(overlay/'Selection.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/insert-decal-action-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS InsertDecal action and file registration')
