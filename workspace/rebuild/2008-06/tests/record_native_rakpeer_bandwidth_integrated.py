"""Check the native RakPeer bandwidth setter and original vtable slot."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-bandwidth-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/RakPeerBandwidth.cpp'
obj = out / 'RakPeerBandwidth.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?SetPerConnectionOutgoingBandwidthLimit@RakPeer@@'))
target, targetrefs, _ = match.target('2008-06', '004bbef0')
assert match.exact_match(target, targetrefs, body, refs)
original = root / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(original)); base = pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I', pe.get_data(0x8264ac + 65 * 4 - base, 4))[0] == 0x4bbef0
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/RakPeerInterface.h', Path(__file__)]
receipt = {'scope': 'Setter bytes and original vtable slot; full vtable target identities and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'symbol': name, 'target': '0x4bbef0', 'size': len(body), 'original_slot': 65}
(root / 'work/2008-06/shared-layouts/rakpeer-bandwidth-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original RakPeer setter and vtable slot 65')
