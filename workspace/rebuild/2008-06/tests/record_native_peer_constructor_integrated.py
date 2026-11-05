"""Check integrated native Peer constructor against the original."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/peer-constructor-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/PeerConstructor.cpp'
obj = out / 'PeerConstructor.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/I' + str(root / 'tools/rbxgs/Client/Network'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0Peer@Network@RBX@@'))
address = 0x4b4640
target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
table = sections[index]
bindings = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
    offset -= start
    if kind == 20 and 0 <= offset < len(target) - 3:
        value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[symbol][0]] = hex(value)
for prefix, value in [('??0Instance@RBX@@', '0x55b7e0'), ('?classDescriptor@', '0x49ea10'), ('??0PluginInterface@@', '0x49ed30'), ('??2@YAPAXI@Z', '0x6a0920'), ('??0CodeProfiler@', '0x5c43a0'), ('??0RakPeer@@', '0x4c18d0')]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/Replicator.h', root / 'rebuild/2008-06/native-headers/ProfiledRakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', Path(__file__)]
receipt = {'scope': 'Native Peer constructor byte match and selected target bindings; scoped_ptr mutability inferred, complete network ABI/runtime unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'symbol': name, 'address': hex(address), 'size': len(body), 'bindings': bindings}
(root / 'work/2008-06/shared-layouts/peer-constructor-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Peer constructor 364 bytes and selected targets')
