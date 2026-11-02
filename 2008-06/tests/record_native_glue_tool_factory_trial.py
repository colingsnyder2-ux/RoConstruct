import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeGlueToolFactoryTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'surface-flat-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
obj=out/'NativeGlueToolFactoryTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay.parent));flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?newMouseCommand@?$TToolVerb@VGlueTool',0x5c67b0,[('??2@',0x6a0920),('??0SurfaceTool@',0x619de0),('??_7GlueTool@RBX@@6BINamed',0x839244),('??_7GlueTool@RBX@@6BIRenderable',0x83922c)]),('?getName@?$Named@VSurfaceTool@RBX@@$1?sGlueTool',0x5c6820,[('?flag@',0x979650),('?callDoDeclare@',0x5c60f0),('?call_once@boost@@',0x557330),('?doDeclare@',0x5c56e0)]),('?doDeclare@?$NativeToolName@VGlueTool',0x5c56e0,[('?declare@Name@',0x553f90)]),('?callDoDeclare@?$NativeToolName@VGlueTool',0x5c60f0,[('?doDeclare@',0x5c56e0)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target))
 start,section=defs[name];table=sections[section];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.setdefault(symbols[sym][0],value)
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
import pefile
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert pe.get_string_at_rva(0x95aefc-pe.OPTIONAL_HEADER.ImageBase)==b'Glue';assert any(v==hex(0x95aefc) for v in rows[2]['bindings'].values())
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive GlueTool methods; Surface layout and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/glue-tool-factory-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS GlueTool name method and bindings')

