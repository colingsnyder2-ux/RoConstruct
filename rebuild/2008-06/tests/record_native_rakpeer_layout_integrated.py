"""Check 2008 RakPeer size with the native release-layout header."""
import hashlib, json, re, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/rakpeer-native-layout'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/tests/NativeProfiledRakPeerSizeWorker.cpp'
header = root / 'rebuild/2008-06/native-headers/RakPeer.h'
obj = out / 'RakPeerSize.obj'
flags += ['/I' + str(root / 'tools/rbxgs/Client/Network/raknet30/Source'), '/I' + str(root / 'tools/rbxgs/Client/Network'), '/d1reportSingleClassLayoutRakPeer', '/Fo' + str(obj), str(source)]
assert '/D_RELEASE' in flags
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
for offset, name in [(0x730, 'maxOutgoingBPS'), (0x738, '_maxSendBPS'), (0x740, '_minExtraPing'),
                     (0x742, '_extraPingVariance'), (0x744, 'rsacrypt'),
                     (0x900, 'networkIDManager')]:
    assert re.search(r'^\s*' + str(offset) + r'\s*\|.*\b' + name + r'\b', log, re.M), name
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
for slot, name, address in [(65, 'SetPerConnectionOutgoingBandwidthLimit', 0x4bbef0),
                            (69, 'RunUpdateCycle', 0x4c5290)]:
    assert re.search(r'^\s*' + str(slot) + r'\s*\|\s*&RakPeer::' + name + r'\b', log, re.M), name
    assert struct.unpack('<I', pe.get_data(0x8264ac + slot * 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == address
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Release-profile sizeof assertion and original ctor offset evidence only; full RakPeer ABI and lifetime byte matches remain unproven.', 'size': '0x908', 'sources': {str(p.relative_to(root)): sha(p) for p in (source, header, header.parent / 'RakPeerInterface.h', Path(__file__))}, 'object_sha256': sha(obj), 'flags': flags}
(root / 'work/2008-06/shared-layouts/rakpeer-native-layout.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native RakPeer release size 0x908')
