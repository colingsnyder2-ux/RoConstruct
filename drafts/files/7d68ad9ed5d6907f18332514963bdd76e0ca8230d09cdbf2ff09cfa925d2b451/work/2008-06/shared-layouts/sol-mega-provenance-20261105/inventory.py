import json,struct,hashlib,capstone
from pathlib import Path
from roc import match
out=Path('work/2008-06/shared-layouts/sol-mega-provenance-20261105');base,img=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
rows=[json.loads(l) for l in Path('work/2008-06/functions.jsonl').open()];by={}
for f in rows:by.setdefault(f['size'],[]).append(f)
p=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib');r=p.read_bytes();o=8;results=[]
while o+60<=len(r):
 n=int(r[o+48:o+58]);member=r[o:o+16].decode().strip();d=r[o+60:o+60+n];o+=60+n+(n&1)
 if d[:2]!=b'\x4c\x01':continue
 try:fs=match.coff_functions(d)
 except Exception:continue
 for s,b,refs in fs:
  if not ((s.startswith('??0MegaDragger')) or 'convertPVInstancesToParts' in s or 'onMouseMove@AxisMoveTool' in s or s.startswith('?shared_from_this@?$enable_shared_from_this@VInstance') or s.startswith('??$shared_from@VPartInstance') or ('sp_enable_shared_from_this@VInstance' in s and 'VPartInstance@' in s)):continue
  hits=[]
  for f in by.get(len(b),[]):
   va=int(f['addr'],16);orig=bytes(img[va-base:va-base+len(b)])
   if match.exact_match(orig,f.get('relocs',[]),b,refs):hits.append(f)
  secs,syms,defs,starts=match._coff_data_index(d);v,si=defs[s];sec=secs[si];rel=[]
  for j in range(sec[7]):
   ro,idx,k=struct.unpack_from('<IIH',d,sec[5]+j*10)
   if v<=ro<v+len(b):rel.append(dict(offset=ro-v,kind=k,symbol=syms[idx][0]))
  results.append(dict(symbol=s,size=len(b),member=member,member_sha256=hashlib.sha256(d).hexdigest(),body_hex=b.hex(),relocations=rel,hits=hits))
addrs={int(f['addr'],16) for x in results for f in x['hits']};addrs.add(0x41e880)
asm={}
for va in addrs:
 f=next((f for f in rows if int(f['addr'],16)==va),None)
 if f:asm[hex(va)]=[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes(img[va-base:va-base+f['size']]),va)]
receipt=dict(archive_sha256=hashlib.sha256(r).hexdigest(),original_sha256=hashlib.sha256(Path('clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),providers=results,assembly=asm)
(out/'inventory.json').write_text(json.dumps(receipt,indent=2))
for x in results:print(x['symbol'],[f['addr'] for f in x['hits']])
print(json.dumps(asm,indent=2))
