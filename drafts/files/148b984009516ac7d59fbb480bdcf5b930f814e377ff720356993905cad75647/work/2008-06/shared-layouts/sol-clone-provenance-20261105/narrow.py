import json,hashlib
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
p=Path('work/2008-06/shared-layouts/sol-clone-provenance-20261105');d=json.loads((p/'coff-catalog.json').read_text()); md=Cs(CS_ARCH_X86,CS_MODE_32)
keep=[x for x in d['providers'] if x['symbol'].startswith('?clone@Instance') or x['symbol'].startswith('?onMouseMove@Axis') or x['symbol'].startswith('?create@?$Abstract') or x['symbol'].startswith('?create@Creator@?$FactoryProduct@VPartInstance')]
for x in keep:
 x['asm']=[f'{i.address:04x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes.fromhex(x['body_hex']),0)]
 if x['symbol'].startswith('?clone@Instance'):print(x['member_sha256'],'\n'+'\n'.join(x['asm'][:33]))
d['providers']=keep;(p/'coff-catalog.json').write_text(json.dumps(d,indent=2))
