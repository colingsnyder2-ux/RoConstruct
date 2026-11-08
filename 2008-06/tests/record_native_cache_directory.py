"""Verify getCacheDirectory in an isolated native layout."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeCacheDirectoryTrial.cpp'
layout = root / 'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeCacheDirectoryTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getCacheDirectory@FileSystem@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005a7ea0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'?GetIntegrity@VistaAPIs@RBX@@': 0x5a7780,
            '__imp__CLSIDFromString@8': 0x804134, '__imp__CreateDirectoryA@8': 0x8022b4,
            '__imp__SHGetFolderPathAndSubDirA@24': 0x802af4, '__imp__LoadLibraryA@4': 0x8021cc,
            '__imp__GetProcAddress@8': 0x8021c0, '__imp__FreeLibrary@4': 0x8021a0}
start, index = definitions[name]
section = sections[index]
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x5a7ea0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected), found
related = []
for prefix, address in [('?getUserAppDataDirectory@FileSystem@RBX@@', '005a7ac0'),
                        ('?GetIntegrity@VistaAPIs@RBX@@', '005a7780')]:
    symbol, related_body, related_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    related_target, related_targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(related_target, related_targetrefs, related_body, related_refs), symbol
    related.append({'address': address, 'symbol': symbol, 'size': len(related_body)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '005a7ea0', 'size': len(body), 'targets': found,
           'related_bodies': related,
           'scope': 'Inactive trial. Vista API layout, exact integrity helper, imports, exception metadata and runtime ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/content-cache-directory-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider getCacheDirectory and selected targets')
