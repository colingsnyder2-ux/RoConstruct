"""Check native RakPeer lifetime against 2008 release code."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-lifetime-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerLifetime.cpp'
header = root / 'rebuild/2008-06/native-headers/RakPeer.h'
obj = out / 'RakPeerLifetime.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/I' + str(root / 'tools/rbxgs/Client/Network'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('??0RakPeer@@', 0x4c18d0), ('??1RakPeer@@', 0x4c4d50)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    start, index = definitions[name]
    table = sections[index]
    bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        offset -= start
        if 0 <= offset < len(target) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[symbol][0]] = hex(value)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs), 'bindings': bindings})
assert all(row['exact'] for row in rows), rows
assert any(k.startswith('??0BitStream@RakNet@@') and v == '0x4a5090' for k, v in rows[0]['bindings'].items())
assert any(k.startswith('__imp__CloseHandle') and v == '0x802234' for k, v in rows[1]['bindings'].items())
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Native source ctor/dtor match with selected bindings; full RakPeer ABI, vtable and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in (source, header, header.parent / 'RakPeerInterface.h', header.parent / 'ReliabilityLayer.h', Path(__file__))}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/rakpeer-lifetime-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS RakPeer constructor 566 bytes, destructor 353 bytes, selected bindings')
