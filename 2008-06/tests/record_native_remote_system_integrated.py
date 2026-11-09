"""Check the 2008 RemoteSystemStruct size against integrated headers."""
import hashlib, json, re, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/remote-system-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/tests/NativeRemoteSystemSize.cpp'
obj = out / 'RemoteSystemSize.obj'
donor = root / 'tools/openrbx/3rdparty/RakNet30/Source'
flags.insert(next(i for i, x in enumerate(flags) if x.startswith('/I')) + 1, '/I' + str(donor))
flags += ['/I' + str(root / 'tools/openrbx/util'), '/d1reportSingleClassLayoutRemoteSystemStruct', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
for offset, name in [(0x18, 'reliabilityLayer'), (0x7e0, 'weInitiatedTheConnection'), (0x7e4, 'pingAndClockDifferential'), (0x848, 'connectMode')]:
    assert re.search(r'^\s*' + str(offset) + r'\s*\|.*\b' + name + r'\b', log, re.M), name
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/RakPeer.h', root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', Path(__file__)]
receipt = {'scope': 'Size and selected offsets only; lifetime, complete ABI and runtime need separate proof.', 'size': '0x850', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags}
(root / 'work/2008-06/shared-layouts/remote-system-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native RemoteSystemStruct size and selected offsets')
