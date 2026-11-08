"""Verify original SurfaceTool lifetime in an isolated typed profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeGrabToolTrial.cpp';header=root/'rebuild/2008-06/tests/NativeGrabToolTrial.h';obj=out/'NativeGrabToolTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('??0GrabTool@',0x63fba0,[('??0MouseCommand@',0x6159f0),('__imp_??0?$basic_string@',0x802458),('??_7GrabTool@RBX@@6BINamed',0x84a454),('??_7GrabTool@RBX@@6BIRenderable',0x84a43c)]),('??1GrabTool@',0x63fb40,[('??1MouseCommand@',0x615780),('__imp_??1?$basic_string@',0x802468)]),('??_GGrabTool@',0x63fc00,[('??1GrabTool@',0x63fb40),('??3@',0x6a067a)]),('?getCursorName@GrabTool@',0x617e40,[]),('?newMouseCommand@?$TToolVerb@VGrabTool',0x5c7750,[('??0GrabTool@',0x63fba0),('??2@',0x6a0920)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs)
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
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0]
for suffix,address,slots in [('INamed',0x84a454,16),('IRenderable',0x84a43c,5)]:
 v=next(k for k in defs if k.startswith('??_7GrabTool@') and suffix in k);start,section=defs[v];assert (sections[section][3]-start)//4==slots;assert pe.get_string_at_rva(rd(rd(address-4)+12)+8-image)==b'.?AVGrabTool@RBX@@'
assert rd(0x84a454+48)==0x63fc00 and rd(0x84a454+60)==0x617e40
assert pe.get_string_at_rva(0x833850-image)==b'ArrowCursor' and any(v=='0x833850' for v in rows[0]['bindings'].values())
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'GrabTool constructor, destructor, factory and RTTI verified; full virtuals, ABI and runtime unproven.','size':'0x38','methods':rows,'source_sha256':sha(src),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/grab-tool-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS GrabTool lifetime and factory')
