"""Verify original GUID registry initialization and direct targets."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/GuidRegistryInitialize.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/guid-item-working-probe.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('GuidItem.cpp')]
obj = out / 'NativeGuidRegistryInitialize.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?initializeGuidRegistry@'))
target, targetrefs, _ = match.target('2008-06', '0049a040')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
expected = {'??2@': 0x6a0920, '??0GuidRegistry@': 0x499d60, '?guidRegistry@': 0x9705e8}
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body) - 3:
        continue
    symbol = symbols[symbol][0]
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (0x49a040 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '0049a040',
           'size': len(body), 'targets': found,
           'scope': 'Inactive diagnostic. Registry constructor, data ownership and runtime ABI unproven.'}
(root / 'work/2008-06/shared-layouts/guid-registry-initialize-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original GUID registry initializer and targets')
