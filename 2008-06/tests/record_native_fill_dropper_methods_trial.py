"""Verify five original surface-tool factories and destructors."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeFillDropperMethodsTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/ToolsPart.h';obj=out/'NativeFillDropperMethodsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));overlay=out/'fill-dropper-methods-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);h=header.read_text()
for typ in ('FillTool','DropperTool','ModelSetPrimaryPartTool'):
 old=typ+'(Workspace*);';assert h.count(old)==1;h=h.replace(old,typ+'(Workspace* workspace) : Named<PartTool, &s'+typ+'>(workspace) {}')
(overlay/'ToolsPart.h').write_text(h);flags.insert(0,'/I'+str(overlay.parent))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];rows=[]
for prefix,address,expected in [('?getCursorName@FillTool@',0x5c73b0,[('__imp_??0?$basic_string@',0x802458)]),('?isSticky@FillTool@',0x5c73e0,[('??2@',0x6a0920),('??0PartTool@',0x5b6390),('??_7FillTool@RBX@@6BINamed',0x83986c),('??_7FillTool@RBX@@6BIRenderable',0x839854)]),('?getCursorName@DropperTool@',0x5c7500,[('__imp_??0?$basic_string@',0x802458)])]:
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
for i,addr,literal in [(0,0x8398ac,b'FillCursor'),(2,0x839934,b'DropperCursor')]:
 assert pe.get_string_at_rva(addr-image)==literal and hex(addr) in rows[i]['bindings'].values()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Inactive factory/lifetime and RTTI checks; derived methods and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'base_header_sha256':sha(src.parent/'NativePartToolTrial.cpp'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/fill-dropper-methods-trial.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS Fill and Dropper cursor/sticky methods')
