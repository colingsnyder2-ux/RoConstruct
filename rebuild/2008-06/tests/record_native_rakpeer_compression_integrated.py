"""Check recovered RakPeer compression ratios and original vtable slots."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-compression-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerCompression.cpp'
obj = out / 'RakPeerCompression.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/fp:fast', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
rows = []
for prefix, address, slot in [('?GetCompressionRatio@RakPeer@@', 0x4bbd90, 56), ('?GetDecompressionRatio@RakPeer@@', 0x4bbdd0, 57)]:
    name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs)
    assert struct.unpack('<I', pe.get_data(0x8264ac + slot * 4 - base, 4))[0] == address
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'vtable_slot': slot})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', Path(__file__)]
receipt = {'scope': 'Two native methods and original vtable slots only; full RakPeer ABI/runtime unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/rakpeer-compression-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native RakPeer compression ratios and vtable slots 56/57')
