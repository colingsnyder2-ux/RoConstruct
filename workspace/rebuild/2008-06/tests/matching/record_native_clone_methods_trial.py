import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeCloneMethodsTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'clone-methods-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
workspace=out/'workspace-model-vector-include/v8datamodel/Workspace.h'; w=workspace.read_text(); assert 'findTopInstance(Instance*' in w; (overlay/'Workspace.h').write_text(w)
mouse=root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h'; m=mouse.read_text(); needle='PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3&);'; assert m.count(needle)==1; (overlay/'MouseCommand.h').write_text(m.replace(needle,'PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3& = ignoreVector3);'))
obj=out/'NativeCloneMethodsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?onMouseIdle@CloneTool@',0x63f710,[('?getUnlockedPartByLocalCharacter@MouseCommand@',0x616000),('??$shared_from@VPartInstance@',0x618a40),('??4shared_count@detail@boost@@',0x4025b0),('?ignoreVector3@MouseCommand@',0x97bee0)]),('?getCursorName@CloneTool@',0x63fd90,[('__imp_??0?$basic_string@',0x802458)])]:
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
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe')); baseaddr=pe.OPTIONAL_HEADER.ImageBase
for addr,value in [(0x84a4a0,b'CloneCursor'),(0x84a4ac,b'CloneOverCursor')]: assert pe.get_string_at_rva(addr-baseaddr)==value and hex(addr) in rows[1]['bindings'].values()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Model tool target layout and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'model_header_sha256':sha(src.parent/'NativeCloneToolTrial.h'),'workspace_header_sha256':sha(workspace),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/clone-methods-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS CloneTool methods and bindings')


