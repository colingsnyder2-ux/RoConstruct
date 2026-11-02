"""Verify original Instance callbacks and their actual vtable slots."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/InstanceBaseCallbacks.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeInstanceBaseCallbacks.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
rows = []
for slot, address, prefix in [
    (1, '0055af90', '?setName@Instance@RBX@@'),
    (2, '0068e880', '?askAddChild@Instance@RBX@@'),
    (3, '0068e880', '?askSetParent@Instance@RBX@@'),
    (7, '0070bdf0', '?onChildAdded@Instance@RBX@@'),
    (8, '0070bdf0', '?onChildRemoving@Instance@RBX@@'),
    (9, '0070bdf0', '?onChildRemoved@Instance@RBX@@'),
    (10, '0047d410', '?onLastChildRemoved@Instance@RBX@@'),
    (12, '00458e90', '?onServiceProvider@Instance@RBX@@'),
    (15, '00557490', '?onChildChanged@Instance@RBX@@'),
]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    # 0082d884 is Instance's own primary vtable; 008318bc is ChangeHistoryService.
    original = struct.unpack('<I', pe.get_data(0x82d884 + slot*4 - base, 4))[0]
    assert original == int(address, 16), (slot, hex(original), address)
    if slot == 15:
        ins = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, int(address, 16)))
        assert any(i.mnemonic == 'mov' and i.op_str == 'eax, dword ptr [eax + 0x3c]' for i in ins)
    row = {'slot': slot, 'address': address, 'symbol': name, 'size': len(body)}
    if slot == 1:
        sections, symbols, definitions, _ = match._coff_data_index(raw)
        start, section = definitions[name]
        table = sections[section]
        bindings = {}
        for i in range(table[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
            offset -= start
            if 0 <= offset < len(body) - 3:
                value = struct.unpack_from('<I', target, offset)[0]
                if kind == 20:
                    value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                bindings[symbols[symbol][0]] = value
        for prefix, value in [('?desc_Name@Instance@RBX@@', 0x973d54), ('?raisePropertyChanged@Instance@RBX@@', 0x40db00), ('__imp_??$?9', 0x8023d8), ('__imp_??4', 0x80240c)]:
            assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
        row['bindings'] = {k: hex(v) for k, v in bindings.items()}
    rows.append(row)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj),
           'flags': flags, 'callbacks': rows,
           'scope': 'Inactive source. Original base callbacks are explicitly empty/false where specified; class ABI, remaining virtuals and runtime remain unproven.'}
(root / 'work/2008-06/shared-layouts/instance-callbacks-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original Instance base callbacks and vtable slots')
