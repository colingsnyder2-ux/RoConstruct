"""Verify GUID registry mutex methods against the original executable."""
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
source = root / 'rebuild/2008-06/native-classes/GuidRegistryMutex.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/guid-item-working-probe.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('GuidItem.cpp')]
obj = out / 'NativeGuidRegistryMutex.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
rows = []
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
for address, prefix in [('00563090', '?lock@GuidRegistryMutex'), ('005630e0', '?unlock@GuidRegistryMutex')]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = definitions[name]
    section = sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(body) - 3:
            continue
        candidate = symbols[symbol][0]
        if candidate.startswith('__imp__'):
            original = imports[struct.unpack_from('<I', target, offset)[0]]
            assert candidate.split('@')[0] == '__imp__' + original, (address, candidate, original)
            calls.append({'offset': offset, 'import': original})
    assert len(calls) == (4 if address == '00563090' else 2)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'imports': calls})
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0GuidRegistryMutex@'))
target, targetrefs, _ = match.target('2008-06', '00563070')
assert match.exact_match(target, targetrefs, body, refs)
start, index = definitions[name]
section = sections[index]
direct = []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        direct.append((symbols[symbol][0], 0x563070 + offset + 4 + struct.unpack_from('<i', target, offset)[0]))
assert len(direct) == 1 and direct[0][0].startswith('?newGuidRegistryCriticalSection@') and direct[0][1] == 0x594c10
rows.append({'address': '00563070', 'symbol': name, 'size': len(body), 'direct_target': '0x594c10'})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'methods': rows,
           'scope': 'Inactive diagnostic. Import targets checked; registry identity and runtime semantics remain unproven.'}
(root / 'work/2008-06/shared-layouts/guid-registry-mutex-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original GUID registry mutex methods')
