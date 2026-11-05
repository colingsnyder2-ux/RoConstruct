"""Check native ProfiledRakPeer override, deletion and vtable slots."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/profiled-rakpeer-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/tests/NativeProfiledRakPeerIntegrated.cpp'
obj = out / 'ProfiledRakPeer.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/Ob0', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('?RunUpdateCycle@ProfiledRakPeer@@', 0x4aaee0), ('??_GProfiledRakPeer@@', 0x4ab830)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    start, index = definitions[name]
    table = sections[index]
    bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        offset -= start
        if kind == 20 and 0 <= offset < len(target) - 3:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[symbol][0]] = hex(value)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': match.exact_match(target, targetrefs, body, refs), 'bindings': bindings})
assert all(row['exact'] for row in rows), rows
for prefix, address in [('??0Mark@Profiling@RBX@@', '0x5c3f80'), ('?RunUpdateCycle@RakPeer@@', '0x4c5290'), ('??1Mark@Profiling@RBX@@', '0x5c42d0')]:
    assert any(k.startswith(prefix) and v == address for k, v in rows[0]['bindings'].items()), rows[0]
value, index = definitions['??_7ProfiledRakPeer@@6B@']
table = sections[index]
slots = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
    if offset >= value and (offset - value) % 4 == 0:
        slots[(offset - value) // 4] = symbols[symbol][0]
assert len(slots) == 70 and slots[65].startswith('?SetPerConnectionOutgoingBandwidthLimit@RakPeer@@') and slots[69].startswith('?RunUpdateCycle@ProfiledRakPeer@@'), slots
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
for slot, address in [(65, 0x4bbef0), (69, 0x4aaee0)]:
    assert struct.unpack('<I', pe.get_data(0x8245cc + slot * 4 - base, 4))[0] == address
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-classes/ProfiledRakPeer.cpp', root / 'rebuild/2008-06/native-headers/ProfiledRakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', root / 'rebuild/2008-06/native-headers/util/Profiling.h', Path(__file__)]
receipt = {'scope': 'Derived size, override, deleting destructor and two vtable slots; inherited slot targets, full ABI and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows, 'vtable_slot_count': len(slots), 'vtable_slots': {str(k): slots[k] for k in (65, 69)}}
(root / 'work/2008-06/shared-layouts/profiled-rakpeer-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ProfiledRakPeer size, override, destructor and vtable slots')
