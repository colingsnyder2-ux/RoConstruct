import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeFillColorTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/ToolsPart.h';obj=out/'NativeFillColorTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address in [('??__E?color@FillTool@',0x7f51f0),('??__F?color@FillTool@',0x7fe2d0),('??_GFillToolColor@',0x5b6460),('??0?$Notifier@VFillToolColor@',0x5e9ec0)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target))
 start,section=defs[name];table=sections[section];bindings=[]
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.append((symbols[sym][0],value))
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':[(k,hex(v)) for k,v in bindings]})
expected=[[("?color@FillTool@",0x976fa0),("?color@FillTool@",0x976fc0),("??0?$Notifier@VFillToolColor@",0x5e9ec0),("??__F?color@FillTool@",0x7fe2d0),("??_7FillToolColor@",0x835890),("_atexit",0x6a17af)],[("?color@FillTool@",0x976fa4),("?color@FillTool@",0x976fb0),("?color@FillTool@",0x976fb4),("?color@FillTool@",0x976fb8),("??3@",0x6a067a)],[("??3@",0x6a067a)],[("??2@",0x6a0920)]]
for row,checks in zip(rows,expected):
 for token,value in checks: assert any(k.startswith(token) and v==hex(value) for k,v in row['bindings']),(token,row)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];v=0x835890;assert pe.get_string_at_rva(rd(rd(v-4)+12)+8-image)==b'.?AVFillToolColor@RBX@@';assert rd(v)==0x5b6460
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Original global initializer, destructor, deleting destructor, Notifier constructor, RTTI and static data offsets match; shared runtime ABI and cross-object identity unproven.','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/fill-color-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS FillTool color global construction, destruction and RTTI')
