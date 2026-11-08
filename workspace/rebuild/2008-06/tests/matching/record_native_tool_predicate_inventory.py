"""Inventory original tool predicates through the StandardVerbs constructor."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
obj=root/'rebuild/2008-06/out/native-layouts/NativeStandardVerbsConstructorTrial.obj';receipt=root/'work/2008-06/shared-layouts/standard-verbs-constructor-trial.json';raw=obj.read_bytes();sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(obj)==json.loads(receipt.read_text())['object_sha256']
sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('??0StandardVerbs@RBX@@'));target,targetrefs,_=match.target('2008-06','005c7ea0');assert match.exact_match(target,targetrefs,body,refs)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0]
start,index=defs[name];section=sections[index];rows=[];canonical=None
for i in range(section[7]):
 off,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
 sym=symbols[symbol][0]
 if not 0<=off<len(body)-3 or not sym.startswith('??_7?$TToolVerb@V'):continue
 tool=sym.split('@')[1][1:];vtable=struct.unpack_from('<I',target,off)[0];address=rd(vtable+12)
 ctor_rtti=pe.get_string_at_rva(rd(rd(vtable-4)+12)+8-base);assert tool.encode() in ctor_rtti,(tool,ctor_rtti)
 pred,predrefs,_=match.target('2008-06',f'{address:08x}');assert len(pred)==44 and predrefs==[30,36]
 descriptor=struct.unpack_from('<I',pred,30)[0];assert pe.get_string_at_rva(descriptor+8-base)==('.?AV'+tool+'@RBX@@').encode()
 assert address+25+struct.unpack_from('<i',pred,21)[0]==0x6a1de2
 normalized=bytearray(pred)
 for pos in [21,30,36]:normalized[pos:pos+4]=b'\0'*4
 if canonical is None:canonical=bytes(normalized)
 assert bytes(normalized)==canonical,tool
 rows.append({'tool':tool,'vtable':hex(vtable),'predicate':hex(address),'type_descriptor':hex(descriptor)})
assert len(rows)==26 and len({x['tool'] for x in rows})==26
result={'methods':rows,'normalized_sha256':hashlib.sha256(canonical).hexdigest(),'source_object_sha256':sha(obj),'constructor_receipt_sha256':sha(receipt),'observer_sha256':sha(Path(__file__)),'scope':'Original binary inventory only; concrete tool layouts, type identity in rebuilt executable, constructors/destructors and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/tool-predicate-inventory.json').write_text(json.dumps(result,indent=2)+'\n')
print('PASS 26 tool predicate slots, type descriptors and normalized bodies')

