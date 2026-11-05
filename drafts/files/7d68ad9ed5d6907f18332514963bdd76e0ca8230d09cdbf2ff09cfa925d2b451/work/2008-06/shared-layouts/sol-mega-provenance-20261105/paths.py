import json,struct,hashlib,capstone
from pathlib import Path
from roc import match
out=Path('work/2008-06/shared-layouts/sol-mega-provenance-20261105');base,img=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
rows=[json.loads(l) for l in Path('work/2008-06/functions.jsonl').open()];idx={f['addr']:f for f in rows};seeds=['0060e540','0060e630','0060e920','0060e450','00411ad0','004a2070','0041e880'];chosen=set(seeds)
for s in seeds:chosen.update(idx.get(s,{}).get('callers',[]))
for s in ['0060e920']:chosen.update(idx.get(s,{}).get('call_targets',[]))
asm={}
for s in sorted(chosen):
 f=idx.get(s)
 if not f:continue
 va=int(s,16);asm[s]=dict(index=f,asm=[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes(img[va-base:va-base+f['size']]),va)])
# Inventory all indexed functions containing literal Part-example vtable bytes; instruction interpretation retained for review.
needle=struct.pack('<I',0x80f1cc);stores=[]
for f in rows:
 va=int(f['addr'],16);b=bytes(img[va-base:va-base+f['size']])
 if needle in b:stores.append(dict(address=f['addr'],callers=f.get('callers',[]),instructions=[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(b,va) if '0x80f1cc' in i.op_str]))
(out/'paths.json').write_text(json.dumps(dict(paths=asm,part_vtable_literal_functions=stores),indent=2))
for s in seeds:print(s,'callers',idx.get(s,{}).get('callers'), 'calls',idx.get(s,{}).get('call_targets'))
print('stores',stores)
for s in ['0060e920','00411ad0','004a2070']:print(s, '\n'.join(asm.get(s,{}).get('asm',[])))
