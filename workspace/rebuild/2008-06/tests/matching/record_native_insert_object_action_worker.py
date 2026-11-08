import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'insert-object-worker2';(work/'v8tree').mkdir(parents=True,exist_ok=True);(work/'v8datamodel').mkdir(parents=True,exist_ok=True)
for rel,needle,replacement in [('v8tree/Instance.h','void setParent(Instance*);','bool canAddChild(const Instance*) const;\n    void setParent(Instance*);'),('v8datamodel/Selection.h','void clearSelection();','void clearSelection();\n    void setSelection(Instance*);')]:
 data=(root/'rebuild/2008-06/native-headers'/rel).read_text();assert data.count(needle)==1;(work/rel).write_text(data.replace(needle,replacement))
src=root/'rebuild/2008-06/tests/NativeInsertObjectActionWorker.cpp';obj=work/'NativeInsertObjectActionWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(work),'/I'+str(root/'tools/rbxgs/Client/App')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?target@InsertObject@@',0x41f5f0,[('??$create@VSelection@',0x4153b0),('?front@Selection@',0x413c20)]),('?doIt@InsertObject@@',0x41f680,[('?target@InsertObject@@',0x41f5f0),('??0runtime_error@std@@',0x409d50),('??$shared_from@',0x618a40),('??0CInsertObjectDialog@@',0x41fe00),('?DoModal@CDialog@@',0x6a084e),('?canAddChild@Instance@',0x41f340),('?getClassNameStr@Instance@',0x41f2b0),('?format@G3D@@',0x509b10),('?setParent@Instance@',0x55a8f0),('??$create@VSelection@',0x4153b0),('?setSelection@Selection@',0x567770),('?recordCameraHistory@',0x58c5c0),('??1CInsertObjectDialog@@',0x41ff40),('__TI2?AVruntime_error@std@@',0x8d1bc8)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;assert struct.unpack('<I',pe.get_data(0x80f204+16-image,4))[0]==0x41f680
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive InsertObject target and action match bytes, selected call targets, exception type and vtable slot. Native dialog, instance lifetime and runtime ABI remain unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'instance_overlay_sha256':sha(work/'v8tree/Instance.h'),'selection_overlay_sha256':sha(work/'v8datamodel/Selection.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/insert-object-action-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS InsertObject target and action bytes and bindings')
