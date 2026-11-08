import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeCollectDragPartsTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'grab-methods-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
workspace=out/'workspace-model-vector-include/v8datamodel/Workspace.h'; w=workspace.read_text(); assert 'findTopInstance(Instance*' in w; (overlay/'Workspace.h').write_text(w)
mouse=root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h'; m=mouse.read_text(); needle='PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3&);'; assert m.count(needle)==1; (overlay/'MouseCommand.h').write_text(m.replace(needle,'PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3& = ignoreVector3);'))
drag=root/'tools/rbxgs/Client/App/include/tool/DragTool.h'; d=drag.read_text(); needle='const UIEvent& uiEvent, Workspace* workspace);';assert d.count(needle)==1;(overlay.parent/'tool').mkdir(parents=True,exist_ok=True);(overlay.parent/'tool/DragTool.h').write_text(d.replace(needle,'const UIEvent& uiEvent, Workspace* workspace, boost::shared_ptr<Instance>);'))
obj=out/'NativeCollectDragPartsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?collectDragParts@RBX@@'));target,targetrefs,_=match.target('2008-06','0060e920');assert match.exact_match(target,targetrefs,body,refs);sections,symbols,defs,_=match._coff_data_index(raw);start,sec=defs[name];table=sections[sec];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(0x60e920+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings[symbols[sym][0]]=value
assert any(k.startswith('?findParts@PartInstance@') and v==0x59c640 for k,v in bindings.items()),bindings
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Drag-part collection loop matches bytes and target. Helper symbol name is provisional, complete ABI/runtime unproven.','address':'0x60e920','size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/collect-drag-parts-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS collect drag parts and native target')
