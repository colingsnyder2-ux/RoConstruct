import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeTiltQuadrantTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'tilt-quadrant-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
workspace=out/'workspace-model-vector-include/v8datamodel/Workspace.h'; w=workspace.read_text(); assert 'findTopInstance(Instance*' in w; (overlay/'Workspace.h').write_text(w)
obj=out/'NativeTiltQuadrantTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/fp:fast','/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?toYAxisQuadrant@Math@',0x5dea60,[('?getColumn@Matrix3@',0x513240),('_floor',0x6a1bb0),('__ftol2_sse',0x6a17f0),('?zLookDirection@CoordinateFrame@G3D@@',0x828b60),('?nativeTiltOffset@',0x83db50),('?nativeTiltScale@',0x826e6c),('?nativeTiltSectorScale@',0x83db48)])]:
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
for addr,value in [(0x828b60,-1.0),(0x83db50,7.0685834884643555),(0x826e6c,4.0)]: assert struct.unpack('<f',pe.get_data(addr-baseaddr,4))[0]==value
assert struct.unpack('<d',pe.get_data(0x83db48-baseaddr,8))[0]==0.15915495087284556
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Model tool target layout and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'workspace_header_sha256':sha(workspace),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/tilt-quadrant-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS tilt quadrant and bindings')

