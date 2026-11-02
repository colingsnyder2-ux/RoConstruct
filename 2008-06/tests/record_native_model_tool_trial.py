"""Verify original SurfaceTool lifetime in an isolated typed profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeModelToolTrial.cpp';header=root/'rebuild/2008-06/tests/NativeModelToolTrial.h';obj=out/'NativeModelToolTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('??0ModelTool@',0x63de80,[('??0MouseCommand@',0x6159f0),('??_7ModelTool@RBX@@6BINamed',0x84a2e4),('??_7ModelTool@RBX@@6BIRenderable',0x84a2c8)]),('??1ModelTool@',0x5c79d0,[('??1MouseCommand@',0x615780)])]:
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
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive ModelTool lifetime; shared ABI and runtime unproven.','size':'0x24','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/model-tool-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS ModelTool constructor, destructor and bindings')
