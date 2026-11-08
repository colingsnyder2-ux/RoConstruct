"""Read original Humanoid state factory allocations and constructor RTTI."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
ROOT=Path(__file__).resolve().parents[4];sys.path.insert(0,str(ROOT))
from roc import match
exe=ROOT/'work/2008-06/original-p4-reference/Roblox.exe';pe=pefile.PE(str(exe));base=pe.OPTIONAL_HEADER.ImageBase
u32=lambda va:struct.unpack('<I',pe.get_data(va-base,4))[0]
target,_,_=match.target('2008-06','00643660');assert pe.get_data(0x643660-base,len(target))==target
assert bytes.fromhex('83f80b0f87') in target
jump=struct.unpack_from('<12I',target,0x314);md=Cs(CS_ARCH_X86,CS_MODE_32)
expected=[('FallingDown',0xa0,0x666e30),('GettingUp',0xa8,0x667e20),('Jumping',0xa8,0x667c40),('Freefall',0xc0,0x667810),('Flying',0xa8,0x6674b0),('Landed',0xcc,0x643550),('Running',0xcc,0x666ac0),('RunningNoPhysics',0x114,0x667370),('StrafingNoPhysics',0x114,0x667210),('Climbing',0xcc,0x6435a0),('Seated',0xa0,0x667010),('Dead',0xa0,0x666d30)]
rows=[]
for i,(name,size,ctor) in enumerate(expected):
 instructions=list(md.disasm(pe.get_data(jump[i]-base,16),jump[i]));assert instructions[0].mnemonic=='push' and int(instructions[0].op_str,0)==size
 assert instructions[1].mnemonic=='call' and int(instructions[1].op_str,16)==0x6a0920
 start=0x643945 if i==6 else jump[i]+0x1c
 code=list(md.disasm(pe.get_data(start-base,32),start));assert any(x.mnemonic=='call' and x.op_str==hex(ctor) for x in code),(i,[x.op_str for x in code])
 body,_,_=match.target('2008-06',f'{ctor:08x}');vtable=None
 for ins in md.disasm(body,ctor):
  if ins.mnemonic=='mov' and ins.op_str.startswith('dword ptr [esi], 0x84'):
   vtable=int(ins.op_str.split(', ')[1],16);break
 assert vtable is not None
 locator=u32(vtable-4);type_desc=u32(locator+12);rtti=pe.get_string_at_rva(type_desc+8-base).decode('ascii')
 assert rtti=='.?AV'+name+'@HUMAN@RBX@@',(i,rtti)
 rows.append(dict(case=i,name=name,size=size,case_address=hex(jump[i]),constructor=hex(ctor),vtable=hex(vtable),rtti=rtti))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),original_sha256=sha(exe),observer_sha256=sha(Path(__file__)),factory='00643660',states=rows,scope='Original factory jump table, allocation sizes, constructor targets and constructor-assigned RTTI only; no class member layout or runtime swap claim.')
(ROOT/'work/2008-06/shared-layouts/humanoid-factory-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: 12 factory cases, allocation sizes and constructor RTTI')
