"""Verify original SurfaceTool lifetime in an isolated typed profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeSurfaceToolTrial.cpp';header=root/'rebuild/2008-06/tests/NativeSurfaceToolTrial.h';obj=out/'NativeSurfaceToolTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('??0SurfaceTool@',0x619de0,[('??0MouseCommand@',0x6159f0),('??_7SurfaceTool@RBX@@6BINamed',0x844104),('??_7SurfaceTool@RBX@@6BIRenderable',0x8440ec),('__imp_??0?$basic_string@',0x802460)]),('??1SurfaceTool@',0x5a0d00,[('__imp_??1?$basic_string@',0x802468),('??1MouseCommand@',0x615780)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs)
 start,section=defs[name];table=sections[section];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.setdefault(symbols[sym][0],value)
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
flat_src=root/'rebuild/2008-06/experiments/trials/NativeFlatToolTrial.cpp';flat_header=root/'rebuild/2008-06/tests/NativeFlatToolTrial.h';flat_obj=out/'NativeFlatToolTrial.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(flat_obj),str(flat_src)],out);assert code==0,log
flat_raw=flat_obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(flat_raw);flat_rows=[]
for prefix,address,expected in [('?newMouseCommand@?$TToolVerb@VFlatTool',0x5c6640,[('??2@',0x6a0920),('??0SurfaceTool@',0x619de0),('??_7FlatTool@RBX@@6BINamed',0x8391bc),('??_7FlatTool@RBX@@6BIRenderable',0x8391a0)]),('??_GFlatTool@',0x5c6790,[('??1SurfaceTool@',0x5a0d00),('??3@',0x6a067a)])]:
 name,body,refs=next(x for x in match.coff_functions(flat_raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs)
 start,section=defs[name];table=sections[section];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',flat_raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.setdefault(symbols[sym][0],value)
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 flat_rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
for suffix,size in [('IRenderable',5),('INamed',17)]:
 name=next(k for k in defs if k.startswith('??_7FlatTool@') and suffix in k);start,section=defs[name];assert sections[section][3]-start==4*size
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive SurfaceTool base lifetime profile; full vtable, derived classes and runtime ABI unproven.','size':'0x48','methods':rows,'flat_methods':flat_rows,'flat_source_sha256':sha(flat_src),'flat_header_sha256':sha(flat_header),'flat_object_sha256':sha(flat_obj),'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/surface-tool-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS SurfaceTool lifetime and FlatTool factory, deleting destructor and bindings')
