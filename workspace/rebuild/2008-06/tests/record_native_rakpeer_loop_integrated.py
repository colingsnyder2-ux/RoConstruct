"""Check native RakPeer network loop and original virtual dispatch."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-loop-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerNetworkLoop.cpp'
obj = out / 'RakPeerNetworkLoop.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if 'UpdateNetworkLoop@@' in x[0])
address = 0x4bc090
target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, body, refs)
assert bytes.fromhex('8b 82 14 01 00 00 8b ce ff d0') in body
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
table = sections[index]
bindings = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[symbol][0]] = hex(value)
for prefix, value in [('__imp__CreateWaitableTimerA', '0x80224c'), ('__imp__SetWaitableTimer', '0x802248'), ('?RakSleep@@', '0x4d4170')]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', Path(__file__)]
receipt = {'scope': 'Original loop byte match and selected imports; native network ABI, final target selection and runtime unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'symbol': name, 'address': hex(address), 'size': len(body), 'bindings': bindings}
(root / 'work/2008-06/shared-layouts/rakpeer-loop-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS RakPeer loop 142 bytes, virtual dispatch and selected calls')
