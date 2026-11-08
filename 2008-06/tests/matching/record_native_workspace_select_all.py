"""Verify original Workspace::selectAll method and typed call targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeWorkspaceSelectAllTrial.cpp';obj=out/'NativeWorkspaceSelectAllTrial.obj'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?selectAll@Workspace@'));address=0x5a3e10;target,targetrefs,_=match.target('2008-06','005a3e10');assert match.exact_match(target,targetrefs,body,refs)
start,section=definitions[name];table=sections[section];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings.setdefault(symbols[sym][0],value)
for token,value in [('?createService@?$ServiceClient@VSelection',0x581cc0),('?clearSelection@Selection@',0x5675d0),('?numChildren@Instance@',0x48ae20),('??_R0?AVIRenderable@',0x939f70),('??_R0?AVInstance@',0x92907c),('___RTDynamicCast',0x6a17c6),('?getLocked@PartInstance@',0x59a040),('?addToSelection@Selection@',0x567420)]:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive method; full Workspace/Part layouts and runtime ABI remain unproven.','address':'0x5a3e10','size':len(body),'exact':True,'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'workspace_overlay_sha256':sha(out/'workspace-model-vector-include/v8datamodel/Workspace.h'),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/workspace-select-all-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Workspace::selectAll and typed bindings')
