"""Check original ResizeTool and AxisMoveTool construction and destruction."""
import hashlib, json, struct
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
exe = root / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe)); base = pe.OPTIONAL_HEADER.ImageBase
read = lambda a: struct.unpack('<I', pe.get_data(a - base, 4))[0]
md = Cs(CS_ARCH_X86, CS_MODE_32)
def instructions(address, size=256):
    out = []
    for ins in md.disasm(pe.get_data(address - base, size), address):
        out.append(ins)
        if ins.mnemonic == 'ret': break
    return out

def call(ins, address):
    return any(i.mnemonic == 'call' and i.op_str == hex(address) for i in ins)
rows = []
for name, factory, size, ctor, vtable, destructor, offsets in [
    ('ResizeTool', 0x5c6450, 0x48, 0x5c62f0, 0x839124, 0x5c6340, [0x24]),
    ('AxisMoveTool', 0x5c6510, 0x74, 0x640560, 0x84a5ac, 0x640620, [0x20, 0x24, 0x48]),
]:
    f, c, d = instructions(factory), instructions(ctor), instructions(destructor)
    assert any(i.mnemonic == 'push' and i.op_str == hex(size) for i in f)
    assert call(f, ctor)
    assert any(i.mnemonic == 'mov' and hex(vtable) in i.op_str for i in c)
    descriptor = read(read(vtable - 4) + 12)
    assert pe.get_string_at_rva(descriptor + 8 - base) == ('.?AV' + name + '@RBX@@').encode()
    deleting = read(vtable + 12 * 4)
    assert call(instructions(deleting, 96), destructor)
    assert call(d, 0x615780)
    for offset in offsets:
        assert any('[esi + ' + hex(offset) + ']' in i.op_str for i in d)
        assert any('[esi + ' + hex(offset) + ']' in i.op_str for i in c)
    rows.append(dict(tool=name, factory=hex(factory), size=hex(size), constructor=hex(ctor), vtable=hex(vtable), deleting_destructor=hex(deleting), destructor=hex(destructor), lifetime_offsets=[hex(x) for x in offsets], base_destructor='0x615780'))
result = dict(original_exe_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(), tools=rows, scope='Original binary lifetime evidence only. Full member types, rebuilt ABI and runtime behavior remain unproven.')
out = root / 'work/2008-06/shared-layouts/tool-lifetime-evidence.json'
out.write_text(json.dumps(result, indent=2) + '\n')
print('PASS original factories, RTTI, constructors and destructors for', ', '.join(x['tool'] for x in rows))
