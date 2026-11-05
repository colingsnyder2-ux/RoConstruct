import sys,json,hashlib,struct,capstone
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match
out=root/'work/2008-06/shared-layouts/sol-mega-cleanup-20261105';base,image=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
inputs=json.loads((root/'work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/inputs.json').read_text());results=[];errors=[]
original=bytes(image[0x590390-base:0x590390-base+52])
for filename,expected in inputs.items():
 p=Path(filename)
 if p.suffix.lower() not in ('.obj','.lib'):continue
 raw=p.read_bytes();digest=hashlib.sha256(raw).hexdigest();assert digest==expected,(filename,digest)
 members=[]
 if raw[:8]==b'!<arch>\n':
  off=8
  while off+60<=len(raw):
   size=int(raw[off+48:off+58]);members.append((raw[off:off+16].decode(errors='replace').strip(),off+60,raw[off+60:off+60+size]));off+=60+size+(size&1)
 else:members=[('',0,raw)]
 for member,offset,data in members:
  if data[:2]!=b'\x4c\x01':continue
  try: funcs=match.coff_functions(data)
  except Exception as e:errors.append([filename,member,str(e)]);continue
  for sym,body,refs in funcs:
   if len(body)!=52 or not match.exact_match(original,[],body,refs):continue
   secs,syms,defs,starts=match._coff_data_index(data);v,s=defs[sym];sec=secs[s];rel=[]
   for i in range(sec[7]):
    ro,idx,kind=struct.unpack_from('<IIH',data,sec[5]+i*10)
    if v<=ro<v+len(body):rel.append(dict(offset=ro-v,symbol=syms[idx][0],kind=kind))
   results.append(dict(path=filename,input_sha256=digest,member=member,archive_offset=offset,member_sha256=hashlib.sha256(data).hexdigest(),symbol=sym,body_hex=body.hex(),relocations=rel,byte_exact=body==original))
asm={}
for va,size in [(0x590390,52),(0x590550,111),(0x405e10,13),(0x415000,31),(0x41e880,128),(0x48ee50,31),(0x60e700,118),(0x60ef30,354)]:
 asm[hex(va)]=[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes(image[va-base:va-base+size]),va)]
(out/'helper-providers.json').write_text(json.dumps(dict(original_sha256=hashlib.sha256((root/'clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),inputs_count=len(inputs),target='00590390',original_hex=original.hex(),providers=results,errors=errors,original_disassembly=asm),indent=2))
print(json.dumps(dict(providers=results,errors=errors),indent=2))
