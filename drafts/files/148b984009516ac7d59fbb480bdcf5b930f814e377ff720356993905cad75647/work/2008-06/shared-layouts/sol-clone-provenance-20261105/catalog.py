import json,struct,hashlib,capstone
from pathlib import Path
from roc import match
out=Path('work/2008-06/shared-layouts/sol-clone-provenance-20261105');base,img=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
rows=[json.loads(l) for l in Path('work/2008-06/functions.jsonl').open()];idx={f['addr']:f for f in rows}
seeds=['00559250','00591a30','00581d80','00559350','0041ea40']; wanted=set(seeds)
for s in seeds:wanted.update(idx.get(s,{}).get('call_targets',[]))
refs=[]
for f in rows:
 va=int(f['addr'],16);b=bytes(img[va-base:va-base+f['size']])
 if struct.pack('<I',0x80f1c4) in b:
  refs.append(f['addr']);wanted.add(f['addr'])
asm={}
for s in sorted(wanted):
 f=idx.get(s)
 if f:
  va=int(s,16);b=bytes(img[va-base:va-base+f['size']]);asm[s]={'index':f,'sha256':hashlib.sha256(b).hexdigest(),'asm':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(b,va)]}
(out/'original.json').write_text(json.dumps({'creator_literal_functions':refs,'functions':asm},indent=2))
for s in seeds+refs:print(s,'\n'+'\n'.join(asm[s]['asm']))
