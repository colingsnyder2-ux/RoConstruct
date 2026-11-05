"""Verify five original surface-tool factories and destructors."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeDropperActionTrial.cpp';header=root/'rebuild/2008-06/native-headers/v8datamodel/ToolsPart.h';obj=out/'NativeDropperActionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));overlay=out/'dropper-action-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);h=header.read_text()
for typ in ('FillTool','DropperTool','ModelSetPrimaryPartTool'):
 old=typ+'(Workspace*);';assert h.count(old)==1;h=h.replace(old,typ+'(Workspace* workspace) : Named<PartTool, s'+typ+'>(workspace) {}')
h=h.replace('BrickColor get() const;', 'BrickColor get() const { return color; }').replace('void set(const BrickColor&);','void set(const BrickColor& value) { if (color != value) { color = value; raise(value); } }');(overlay/'ToolsPart.h').write_text(h);flags.insert(0,'/I'+str(overlay.parent))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];rows=[]
for prefix,address,expected in [('?onMouseDown@DropperTool@',0x5b6530,[('?getPart@MouseCommand@',0x615d90),('?color@FillTool@',0x976fc0),('??$create@VSoundService@Soundscape@',0x5807b0),('?playSound@SoundService@',0x5bd820),('?raise@?$Notifier@VFillToolColor@',0x430e10)])]:
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
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Inactive factory/lifetime and RTTI checks; derived methods and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'base_header_sha256':sha(src.parent/'NativePartToolTrial.cpp'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/dropper-action-trial.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS Dropper action')
