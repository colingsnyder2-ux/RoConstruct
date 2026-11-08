"""Verify original history startup event and virtual callback bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match

exe = root / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe))
base = pe.OPTIONAL_HEADER.ImageBase
u32 = lambda address: struct.unpack('<I', pe.get_data(address - base, 4))[0]
string = lambda address: pe.get_string_at_rva(address - base).decode('ascii')
dis = Cs(CS_ARCH_X86, CS_MODE_32)

table = 0x8318bc
locator = u32(table - 4)
assert string(u32(locator + 12) + 8) == '.?AVChangeHistoryService@RBX@@'
events = [
    ('DescendantAdded', 0x973e40, 0x7f2b50, 0x82da04, 0x587240, 16, 0x58b870),
    ('DescendantRemoving', 0x973ca0, 0x7f2b70, 0x82da14, 0x587280, 17, 0x58b970),
    ('ItemChanged', 0x9751b0, 0x7f3440, 0x830430, 0x587290, 18, 0x58ba70),
]
start, _, _ = match.target('2008-06', '0058c620')
calls = {int(i.op_str, 16) for i in dis.disasm(start, 0x58c620)
         if i.mnemonic == 'call' and i.op_str.startswith('0x')}
assert {0x58bf20, 0x4a27e0, 0x58c2c0, 0x58bf80, 0x4a3340, 0x588fb0} <= calls
rows = []
for name, storage, initializer, name_address, thunk, slot, callback in events:
    assert string(name_address) == name
    code, _, _ = match.target('2008-06', '%08x' % initializer)
    assert struct.pack('<I', storage) in code and struct.pack('<I', name_address) in code
    assert struct.pack('<I', storage) in start and struct.pack('<I', thunk) in start
    thunk_bytes, _, _ = match.target('2008-06', '%08x' % thunk)
    assert thunk_bytes == bytes((0x8b, 0x01, 0xff, 0x60, slot * 4))
    assert u32(table + 4 * slot) == callback
    rows.append(dict(name=name, storage=hex(storage), initializer=hex(initializer),
                     callback_thunk=hex(thunk), vtable_slot=slot, callback=hex(callback)))

receipt = {
    'original_sha256': hashlib.sha256(exe.read_bytes()).hexdigest(),
    'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
    'startup': '0x58c620', 'service_vtable': hex(table), 'events': rows,
    'scope': 'Original PE evidence only. Signal types, context ownership, callback bodies and runtime integration remain unverified.',
}
(root / 'work/2008-06/shared-layouts/history-start-abi.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS history startup original event names, storage, callback thunks and virtual slots')
