"""Check native RakPeer BitStream RPC and original vtable slot."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-bitstream-rpc-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerBitStreamRPC.cpp'
obj = out / 'RakPeerBitStreamRPC.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?RPC@RakPeer@@UAE_NPBDPBVBitStream'))
target, targetrefs, _ = match.target('2008-06', '004bcf30')
assert match.exact_match(target, targetrefs, body, refs) and len(body) == 188
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x8264ac + 23 * 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x4bcf30
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', Path(__file__)]
receipt = {'scope': 'BitStream RPC byte and vtable slot check only; raw RPC target, complete network ABI and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'symbol': name, 'address': '0x4bcf30', 'size': len(body), 'original_vtable_slot': 23}
(root / 'work/2008-06/shared-layouts/rakpeer-bitstream-rpc-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native RakPeer BitStream RPC 188 bytes, original vtable slot')
