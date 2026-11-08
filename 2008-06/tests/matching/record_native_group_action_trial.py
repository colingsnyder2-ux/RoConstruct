import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'group-action-probe';overlay=work/'v8datamodel';overlay.mkdir(parents=True,exist_ok=True)
for name in ('Selection.h','Workspace.h'):
 data=(root/'rebuild/2008-06/native-headers/v8datamodel'/name).read_text()
 if name=='Selection.h':
  needle='void clearSelection();'; assert data.count(needle)==1; data=data.replace(needle,needle+'\n    void setSelection(Instance*);')
 else:
  needle='static bool showWorldCoord;';assert data.count(needle)==1;data=data.replace(needle,'boost::shared_ptr<ModelInstance> group(std::vector<boost::shared_ptr<Instance> >::const_iterator, std::vector<boost::shared_ptr<Instance> >::const_iterator);\n        '+needle)
 (overlay/name).write_text(data)
src=root/'rebuild/2008-06/experiments/trials/NativeGroupActionTrial.cpp';obj=out/'NativeGroupActionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(work));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@GroupSelectionVerb@'));target,targetrefs,_=match.target('2008-06','00580c00');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x580c00+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?checkRunPermissions@',0x57d250),('??$create@VSelection@',0x4153b0),('?group@Workspace@',0x57ea90),('?setSelection@Selection@',0x567770),('??$create@VSoundService@',0x4531e0),('?playSound@SoundService@',0x5bd820),('?recordCameraHistory@',0x58c5c0)]:
 assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive group action exact and call targets checked. Group helper name and owner provisional; selection and workspace runtime ABI, lifetimes and virtual ownership unproven.','address':'0x580c00','size':len(body),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/group-action-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS group action bytes and target bindings')
