import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativePartToolNamesTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'surface-flat-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
obj=out/'NativePartToolNamesTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay.parent));flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?getName@?$Named@VPartTool@RBX@@$1?sFillTool', 6059072, [('?flag@', 9934400), ('?callDoDeclare@', 6054064), ('?call_once@boost@@', 5600048), ('?doDeclare@', 6051104)]), ('?doDeclare@?$NativeToolName@VFillTool', 6051104, [('?declare@Name@', 5586832)]), ('?callDoDeclare@?$NativeToolName@VFillTool', 6054064, [('?doDeclare@', 6051104)]), ('?getName@?$Named@VPartTool@RBX@@$1?sDropperTool', 6059424, [('?flag@', 9934404), ('?callDoDeclare@', 6054080), ('?call_once@boost@@', 5600048), ('?doDeclare@', 6051216)]), ('?doDeclare@?$NativeToolName@VDropperTool', 6051216, [('?declare@Name@', 5586832)]), ('?callDoDeclare@?$NativeToolName@VDropperTool', 6054080, [('?doDeclare@', 6051216)]), ('?getName@?$Named@VPartTool@RBX@@$1?sModelSetPrimaryPartTool', 6058432, [('?flag@', 9934408), ('?callDoDeclare@', 6054096), ('?call_once@boost@@', 5600048), ('?doDeclare@', 6051328)]), ('?doDeclare@?$NativeToolName@VModelSetPrimaryPartTool', 6051328, [('?declare@Name@', 5586832)]), ('?callDoDeclare@?$NativeToolName@VModelSetPrimaryPartTool', 6054096, [('?doDeclare@', 6051328)])]:
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
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for i,(address,value) in enumerate([(0x94d24c,b'Fill'),(0x94d254,b'Dropper'),(0x94d25c,b'ModelSetPrimaryPart')]):
 assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase)==value
 assert hex(address) in rows[i*3+1]['bindings'].values()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive FlatTool methods; Surface layout and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/part-tool-names-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS PartTool names and bindings')

