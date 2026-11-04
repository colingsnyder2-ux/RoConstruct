import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insert-object-target-trial';(work/'v8tree').mkdir(parents=True,exist_ok=True);(work/'v8datamodel').mkdir(parents=True,exist_ok=True)
for rel,needle,replacement in [('v8tree/Instance.h','void setParent(Instance*);','bool canAddChild(const Instance*) const;\n    void setParent(Instance*);'),('v8datamodel/Selection.h','void clearSelection();','void clearSelection();\n    void setSelection(Instance*);')]:
 data=(root/'rebuild/2008-06/native-headers'/rel).read_text();assert data.count(needle)==1;(work/rel).write_text(data.replace(needle,replacement))
src=root/'rebuild/2008-06/tests/NativeInsertObjectTargetTrial.cpp';obj=out/'NativeInsertObjectTargetTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?target@InsertObject@@'));target,targetrefs,_=match.target('2008-06','0041f5f0');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if kind==20 and 0<=off<len(body)-3:bindings[symbols[sym][0]]=(0x41f5f0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
for prefix,address in [('??$create@VSelection@',0x4153b0),('?front@Selection@',0x413c20)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive target helper matches bytes and targets; provisional method name, owner lifetime and runtime ABI unproven.','address':'0x41f5f0','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/insert-object-target-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS InsertObject target bytes and targets')
