"""Resolve missing document action slots to original RTTI and recovered source."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match
receipt=root/'work/2008-06/shared-layouts/document-initialize-trial.json'
proof=json.loads(receipt.read_text());obj=root/'rebuild/2008-06/out/native-layouts/NativeDocumentInitializeTrial.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(obj)==proof['object_sha256']
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase
read=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0]
rows=[]
for name,vtable,address in [('CopyVerb',0x80e960,0x415800),('PasteVerb',0x80e934,0x415510),('InsertObject',0x80f204,0x41f680),('InsertService',0x80f22c,0x41f3c0),('InsertDecal',0x80f15c,0x41f040)]:
 symbol=next(k for k in definitions if k.startswith('??_7'+name+'@@'));start,section=definitions[symbol];table=sections[section]
 slots=[]
 for i in range(table[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
  if offset>=0 and symbols[index][0].startswith('?doIt@'+name+'@@'):slots.append(offset)
 assert slots==[16] and read(vtable+slots[0])==address,(name,slots)
 descriptor=read(read(vtable-4)+12);assert pe.get_string_at_rva(descriptor+8-base)==('.?AV'+name+'@@').encode()
 source=root/('src/2008-06/%08x.cpp'%address);source_text=source.read_text(errors='replace');target,targetrefs,_=match.target('2008-06','%08x'%address)
 rows.append({'class':name,'vtable':hex(vtable),'slot':16,'address':hex(address),'size':len(target),'source':str(source.relative_to(root)),'source_sha256':sha(source),'roc_lib':next((x for x in source_text.splitlines() if x.startswith('// roc-lib:')),None)})
result={'scope':'Original vtable and source inventory only; action ABI, callee bindings, live integration and runtime unproven.','constructor_receipt_sha256':sha(receipt),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'actions':rows}
(root/'work/2008-06/shared-layouts/document-action-targets.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS five original document action slots, RTTI and source pointers')
