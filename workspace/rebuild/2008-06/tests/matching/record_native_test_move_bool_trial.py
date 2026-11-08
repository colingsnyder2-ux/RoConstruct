"""Verify bool collision test body and caller binding."""
import hashlib, json, struct, sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeTestMoveBoolTrial.cpp';obj=out/'NativeTestMoveBoolTrial.obj'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/fp:fast','/Fo'+str(obj),str(source)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?testMove@RBX@@'));address=0x610130;target,targetrefs,_=match.target('2008-06','00610130');print('exact',match.exact_match(target,targetrefs,body,refs),'candidate',len(body),'target',len(target)); assert match.exact_match(target,targetrefs,body,refs)
start,section=definitions[name];table=sections[section];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings[symbols[sym][0]]=value
for token,value in [('?computeExtents@Dragger@',0x610070),('__real@bc23d70a',0x843760),('__real@3c23d70a',0x82748c),('?intersectingOthers@ContactManager@',0x60dc10)]:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
caller=out/'NativeSubdivideMoveTrial.obj';externals=rebuild.coff_externals(caller.read_bytes());assert name in externals and not externals[name],name
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive bool-return candidate matches bytes and existing subdivide caller symbol; original source return type, collision ABI and runtime remain unproven.','address':'0x610130','size':len(body),'exact':True,'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'caller_object_sha256':sha(caller),'source_sha256':sha(source),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags+['/fp:fast']};(root/'work/2008-06/shared-layouts/test-move-bool-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS bool testMove bytes, targets and caller symbol')
