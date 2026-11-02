"""Cross-check Workspace camera base against original RTTI, constructor and destructor."""
import hashlib, json, sys
from pathlib import Path
import capstone
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match
exe = root / 'work/2008-06/original-p4-reference/Roblox.exe'
rtti = root / 'work/2008-06/shared-layouts/workspace-selection-rtti.json'
info = json.loads(rtti.read_text())['classes']['.?AVWorkspace@RBX@@']
camera = [b for b in info['tables'][0]['hierarchy']['bases'] if b['type'] == '.?AVICameraOwner@RBX@@']
assert len(camera) == 1 and camera[0]['member_displacement'] == 0x288
vtables = {t['subobject_offset']: int(t['vtable'],16) for t in info['tables']}
assert vtables[0x288] == 0x833998
expected = {offset: vtables[offset] for offset in (0,0x10,0x14,0x20,0x24,0x44,0x64,0x84,0xa4,0xc4,0x130,0x1a0,0x288,0x2e8,0x340,0x344,0x364,0x384)}
md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
md.detail = True
rows = []
for address in ('005a4d90','005a28c0'):
    body, _, _ = match.target('2008-06', address)
    writes = {}
    for ins in md.disasm(body, int(address,16)):
        ops = ins.operands
        if ins.mnemonic != 'mov' or len(ops) != 2 or ops[0].type != capstone.x86.X86_OP_MEM or ops[1].type != capstone.x86.X86_OP_IMM: continue
        offset, value = ops[0].mem.disp, ops[1].imm & 0xffffffff
        if ops[0].mem.base == capstone.x86.X86_REG_ESI and expected.get(offset) == value:
            writes[offset] = {'address':hex(ins.address),'vtable':hex(value)}
    assert set(writes) == set(expected), (address, writes)
    rows.append({'address':address,'size':len(body),'sha256':hashlib.sha256(body).hexdigest(),'writes':{hex(k):v for k,v in writes.items()}})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'original_sha256':sha(exe),'rtti_receipt_sha256':sha(rtti),'observer_sha256':sha(Path(__file__)),'camera_base':camera[0],'methods':rows,'scope':'Original Workspace RTTI offsets confirmed by both original constructor and destructor vtable stores; full native C++ hierarchy and member lifetime remain unproven.'}
(root / 'work/2008-06/shared-layouts/workspace-camera-layout-evidence.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS Workspace RTTI: 18 base offsets including camera +0x288 verified in constructor and destructor')
