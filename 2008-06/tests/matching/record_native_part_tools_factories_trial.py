"""Verify five original surface-tool factories and destructors."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativePartToolsFactoriesTrial.cpp';header=root/'rebuild/2008-06/native-headers/v8datamodel/ToolsPart.h';obj=out/'NativePartToolsFactoriesTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));overlay=out/'part-tools-factory-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);h=header.read_text()
for typ in ('FillTool','DropperTool','ModelSetPrimaryPartTool'):
 old=typ+'(Workspace*);';assert h.count(old)==1;h=h.replace(old,typ+'(Workspace* workspace) : Named<PartTool, s'+typ+'>(workspace) {}')
(overlay/'ToolsPart.h').write_text(h);flags.insert(0,'/I'+str(overlay.parent))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];rows=[]
for tool,address in [('FillTool',0x5c7460),('DropperTool',0x5c7530),('ModelSetPrimaryPartTool',0x5c7150)]:
 for prefix,target_address in [('?newMouseCommand@?$TToolVerb@V'+tool,address),('??_G'+tool+'@',0x5c7af0)]:
  name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%target_address);assert match.exact_match(target,targetrefs,body,refs),(tool,prefix)
  start,section=defs[name];table=sections[section];bindings={}
  for i in range(table[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
   if not 0<=off<len(body)-3:continue
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(target_address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings.setdefault(symbols[sym][0],value)
  expected=[('??2@',0x6a0920),('??0PartTool@',0x5b6390)] if target_address==address else [('??1PartTool@',0x5c79d0),('??3@',0x6a067a)]
  for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(tool,token,bindings)
  if target_address==address:
   candidates=[(k,v) for k,v in bindings.items() if k.startswith('??_7'+tool+'@')];assert len(candidates)==2
   for sym,v in candidates:
    col=rd(v-4);desc=rd(col+12);assert pe.get_string_at_rva(desc+8-image)==('.?AV'+tool+'@RBX@@').encode()
    start,section=defs[sym];size=(sections[section][3]-start)//4;assert size==(16 if 'INamed' in sym else 5)
    if 'INamed' in sym:assert rd(v+48)==0x5c7af0
  rows.append({'tool':tool,'address':hex(target_address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Inactive factory/lifetime and RTTI checks; derived methods and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'base_header_sha256':sha(src.parent/'NativePartToolTrial.cpp'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/part-tools-factories-trial.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS three PartTool factories, destructors, RTTI and vtable sizes')
