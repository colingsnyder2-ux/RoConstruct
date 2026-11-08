import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativePartDragLifetimeTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'grab-methods-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
workspace=out/'workspace-model-vector-include/v8datamodel/Workspace.h'; w=workspace.read_text(); assert 'findTopInstance(Instance*' in w; (overlay/'Workspace.h').write_text(w)
mouse=root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h'; m=mouse.read_text(); needle='PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3&);'; assert m.count(needle)==1; (overlay/'MouseCommand.h').write_text(m.replace(needle,'PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3& = ignoreVector3);'))
drag=root/'tools/rbxgs/Client/App/include/tool/DragTool.h'; d=drag.read_text(); needle='const UIEvent& uiEvent, Workspace* workspace);';assert d.count(needle)==1;(overlay.parent/'tool').mkdir(parents=True,exist_ok=True);(overlay.parent/'tool/DragTool.h').write_text(d.replace(needle,'const UIEvent& uiEvent, Workspace* workspace, boost::shared_ptr<Instance>);'))
obj=out/'NativePartDragLifetimeTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('??0PartDragTool@',0x665f20,[('??0MouseCommand@',0x6159f0),('??0RunDragger@',0x66c900),('??0MegaDragger@',0x60e540),('??_7PartDragTool@RBX@@6BINamed',0x84cbb4),('??_7PartDragTool@RBX@@6BIRenderable',0x84cb9c)]),('??1PartDragTool@',0x665bd0,[('??1RunDragger@',0x66c400),('??1MegaDragger@',0x60e700),('??1MouseCommand@',0x615780)]),('??_GPartDragTool@',0x665cc0,[('??1PartDragTool@',0x665bd0)]),('?getCursorName@PartDragTool@',0x665c90,[('??_C@_0BB@',0x84cbf4),('??_C@_0L@',0x843a60)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,sec=defs[name];table=sections[sec];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
import pefile
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));baseaddr=pe.OPTIONAL_HEADER.ImageBase;rd=lambda va:struct.unpack('<I',pe.get_data(va-baseaddr,4))[0];assert rd(0x84cbb4+0x30)==0x665cc0 and rd(0x84cbb4+0x3c)==0x665c90;assert pe.get_string_at_rva(rd(rd(0x84cbb0)+12)-baseaddr+8)==b'.?AVPartDragTool@RBX@@'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'PartDragTool candidate constructor/destructor/deleting destructor and size match; shared_ptr member pointee, full vtable and runtime ABI unproven.','size':'0x44','methods':rows,'source_sha256':sha(src),'header_sha256':sha(root/'rebuild/2008-06/native-headers/tool/PartDragTool.h'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/part-drag-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS PartDrag ctor/dtor/deleting dtor and RTTI')
