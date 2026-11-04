"""Check recovered raw RakPeer RPC and original call/vtable targets."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-raw-rpc-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerRawRPC.cpp'
obj = out / 'RakPeerRawRPC.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?RPC@RakPeer@@UAE_NPBD0I'))
address = 0x4c42c0
target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, body, refs) and len(body) == 1665
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x8264ac + 24 * 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == address
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
table = sections[index]
bindings = []
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
    offset -= start
    if 0 <= offset < len(target) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.append({'symbol': symbols[symbol][0], 'target': hex(value), 'kind': kind})
for prefix, value in [('__imp__malloc', '0x8028b0'), ('__alloca_probe', '0x6a1520'), ('__alloca_probe_16', '0x6a1560'), ('?GetIndexFromSystemAddress@RakPeer@@', '0x4bfd30'), ('?RakSleep@@', '0x4d4170')]:
    assert any(x['symbol'].startswith(prefix) and x['target'] == value for x in bindings), (prefix, bindings)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', Path(__file__)]
receipt = {'scope': 'Native raw RPC byte match, vtable slot and selected targets. _malloca behavior follows original; runtime and complete network ABI unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'symbol': name, 'address': hex(address), 'size': len(body), 'original_vtable_slot': 24, 'bindings': bindings}
(root / 'work/2008-06/shared-layouts/rakpeer-raw-rpc-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native raw RPC 1665 bytes, original vtable slot and selected targets')
