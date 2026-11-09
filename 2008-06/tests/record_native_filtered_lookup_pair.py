"""Compare original filtered-selection provider lookup pair, including type-specific bindings."""
import hashlib,json,struct,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
rows=[];bodies=[]
for address,flag,callback,index in [(0x57fd20,0x9753c4,0x57dda0,0x57d800),(0x57fdd0,0x9753c8,0x57ddb0,0x57d860)]:
 body,relocs,_=match.target('2008-06',f'{address:08x}');assert len(body)==174
 assert struct.unpack_from('<I',body,25)[0]==flag and struct.unpack_from('<I',body,30)[0]==callback
 calls=[int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(body,address) if i.mnemonic=='call' and i.op_str.startswith('0x')]
 assert calls==[0x557330,index,0x4124c0],calls
 normalized=bytearray(body)
 for off in relocs:
  normalized[off:off+4]=b'\0'*4
 for off in [0x25,0x2d,0x69]:normalized[off:off+4]=b'\0'*4
 rows.append({'address':hex(address),'flag':hex(flag),'callback':hex(callback),'index':hex(index),'calls':[hex(x) for x in calls]});bodies.append(bytes(normalized))
assert bodies[0]==bodies[1]
(root/'work/2008-06/shared-layouts/filtered-lookup-pair.json').write_text(json.dumps({'methods':rows,'normalized_sha256':hashlib.sha256(bodies[0]).hexdigest(),'observer_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'scope':'Original binary comparison only. Shared native source and exception lifetime remain unproven; no link or runtime promotion.'},indent=2)+'\n')
print('PASS two original filtered-selection lookups share normalized body and typed index bindings')
