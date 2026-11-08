import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeCloneDownTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'clone-down-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
workspace=out/'workspace-model-vector-include/v8datamodel/Workspace.h'; w=workspace.read_text(); assert 'findTopInstance(Instance*' in w; (overlay/'Workspace.h').write_text(w)
mouse=root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h'; m=mouse.read_text(); needle='PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3&);'; assert m.count(needle)==1; (overlay/'MouseCommand.h').write_text(m.replace(needle,'PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3& = ignoreVector3);'))
instance=root/'rebuild/2008-06/native-headers/v8tree/Instance.h'; text=instance.read_text();needle='    Instance();';assert text.count(needle)==1;(overlay.parent/'v8tree').mkdir(parents=True,exist_ok=True);(overlay.parent/'v8tree/Instance.h').write_text(text.replace(needle,'    boost::shared_ptr<Instance> clone();\n'+needle))
obj=out/'NativeCloneDownTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?onMouseDown@CloneTool@',0x63ff50,[('?getCoordinateFrame@PartInstance@',0x598cb0),('?clone@Instance@',0x559350),('?insertInstances@RootInstance@',0x5911d0),('??0PartDragTool@',0x665f20),('??$static_pointer_cast@',0x5a1680),('??0?$vector@',0x4293d0),('?push_back@?$vector@',0x420110),('??$create@VSoundService@Soundscape@',0x5807b0),('?playSound@SoundService@',0x5bd820),('??2@',0x6a0920),('??1?$vector@',0x5a2fe0)])]:
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
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<I',pe.get_data(0x84a4dc+4-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x63ff50
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Model tool target layout and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'instance_header_sha256':sha(instance),'instance_overlay_sha256':sha(overlay.parent/'v8tree/Instance.h'),'drag_header_sha256':sha(src.parent/'NativePartDragToolTrial.h'),'model_header_sha256':sha(src.parent/'NativeCloneToolTrial.h'),'workspace_header_sha256':sha(workspace),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/clone-down-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS CloneTool down and bindings')


