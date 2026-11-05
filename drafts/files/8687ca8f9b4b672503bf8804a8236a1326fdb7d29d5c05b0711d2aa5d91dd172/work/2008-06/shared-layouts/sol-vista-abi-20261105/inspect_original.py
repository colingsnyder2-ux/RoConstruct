from pathlib import Path
import pefile,struct,hashlib,json
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
R=Path.cwd(); F=R/'work/2008-06/shared-layouts/sol-vista-abi-20261105'
p=R/'clients/2008-06/Roblox.exe'; raw=p.read_bytes(); assert hashlib.sha256(raw).hexdigest()=='2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe=pefile.PE(data=raw); base=pe.OPTIONAL_HEADER.ImageBase
read=lambda a,n:pe.get_data(a-base,n)
u32=lambda a:struct.unpack('<I',read(a,4))[0]
md=Cs(CS_ARCH_X86,CS_MODE_32)
lines=[]
for a,n in [(0x5a7770,15),(0x5a7780,263),(0x5a7ea0,548),(0x7d30c1,10)]:
 lines.append(f'== {a:08x} {n}')
 lines.extend(f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in md.disasm(read(a,n),a))
fi=struct.unpack('<9I',read(0x8f02fc,36)); lines.append('FuncInfo 008f02fc '+repr([hex(x) for x in fi]))
for i in range(fi[1]):
 a=fi[2]+i*8; prev,action=struct.unpack('<iI',read(a,8));lines.append(f'unwind[{i}] previous={prev} action={action:08x}')
 if action:
  for ins in md.disasm(read(action,48),action):
   lines.append(f'{ins.address:08x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}')
   if ins.mnemonic in ('ret','jmp'):break
for a in [0x83420c,0x834224]:lines.append(f'string {a:08x} '+repr(read(a,40).split(b'\0')[0]))
(F/'original-static.txt').write_text('\n'.join(lines)+'\n')
paths=['clients/2008-06/Roblox.exe','rebuild/2008-06/native-headers/util/FileSystem.h','tools/rbxgs/Client/App/include/util/FileSystem.h','tools/vc2008sp1/Microsoft/Visual C++ for Python/9.0/WinSDK/Include/shlobj.h','work/2008-06/native-check-runs/20261105-135237-9f79a3ac/unit-000/candidate.obj','work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/NativeFileSystemFull.obj','work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib','work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/link.rsp','work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/link.log']
(F/'inputs.json').write_text(json.dumps({p:hashlib.sha256((R/p).read_bytes()).hexdigest() for p in paths},indent=2)+'\n')
print('\n'.join(lines[-24:]))

import sys
sys.path.insert(0,str(R))
from roc import match,libs
obj=R/paths[4]; old=R/paths[5]; archive=R/paths[6]
donor=next(b for n,b in libs.archive_members(archive) if Path(n).name=='FileSystem.obj')
rows=[]
for label,rawobj in [('selected-command-native',obj.read_bytes()),('prior-native',old.read_bytes()),('archive-FileSystem.obj',donor)]:
 for name,body,relocs in match.coff_functions(rawobj):
  if 'VistaAPIs@' in name:
   rows.append(dict(provider=label,symbol=name,size=len(body),body_sha256=hashlib.sha256(body).hexdigest(),relocations=relocs,disassembly=[f'{i.address:x} {i.mnemonic} {i.op_str}' for i in md.disasm(body,0)]))
(F/'object-contracts.json').write_text(json.dumps(rows,indent=2)+'\n')
# Preserve COFF symbol identities separately from relocation offsets.
refs={}
for label,rawobj in [('command-native',obj.read_bytes()),('prior-native',old.read_bytes()),('archive-donor',donor)]:
 secs,syms,defs,starts=match._coff_data_index(rawobj); out={}
 for name,(start,idx) in defs.items():
  if 'VistaAPIs@' not in name:continue
  sec=secs[idx]; end=min([v for v in starts[idx+1] if v>start]+[sec[3]]); rr=[]
  for j in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',rawobj,sec[5]+10*j)
   if start<=off<end:rr.append(dict(offset=off-start,symbol=syms[sym][0],kind=kind))
  out[name]=rr
 refs[label]=out
(F/'provider-refs.json').write_text(json.dumps(refs,indent=2)+'\n')
