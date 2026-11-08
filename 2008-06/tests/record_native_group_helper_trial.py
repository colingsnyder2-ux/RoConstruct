import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'group-helper-probe';overlay=work/'v8datamodel';overlay.mkdir(parents=True,exist_ok=True)
workspace=(root/'rebuild/2008-06/native-headers/v8datamodel/Workspace.h').read_text();needle='static bool showWorldCoord;';assert workspace.count(needle)==1;workspace=workspace.replace(needle,'boost::shared_ptr<ModelInstance> group(std::vector<boost::shared_ptr<Instance> >::const_iterator, std::vector<boost::shared_ptr<Instance> >::const_iterator);\n        '+needle);(overlay/'Workspace.h').write_text(workspace)
src=root/'rebuild/2008-06/experiments/trials/NativeGroupHelperTrial.cpp';obj=out/'NativeGroupHelperTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?group@Workspace@'));target,targetrefs,_=match.target('2008-06','0057ea90');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x57ea90+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('??$create@VModelInstance@',0x414960),('?setParent@Instance@',0x55a8f0),('__imp___invalid_parameter_noinfo',0x802890)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive group helper matches original bytes and call targets. Member owner, name and runtime ABI remain provisional; never run.','address':'0x57ea90','size':len(body),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/group-helper-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS group helper bytes and target bindings')
