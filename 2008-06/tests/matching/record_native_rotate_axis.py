"""Check the original RotateSelectionVerb axis and its call targets."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeRotateAxisTrial.cpp'
obj = out / 'NativeRotateAxisTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getRotationAxis@RotateSelectionVerb@'))
target, targetrefs, _ = match.target('2008-06', '0057d520')
assert match.exact_match(target, targetrefs, body, refs), (len(body), len(target))
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls[symbols[index][0]] = (0x57d520 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
for prefix, address in [('?matrixRotateY@Math@RBX@@', 0x5de800), ('??0Matrix3@G3D@@', 0x513220)]:
    assert any(k.startswith(prefix) and v == address for k, v in calls.items()), (prefix, calls)
rows = json.loads((root / 'work/2008-06/shared-layouts/axis-command-constructors-trial.json').read_text())['methods']
vtable = int(next(row['vtable'] for row in rows if row['class'] == 'RotateSelectionVerb'), 16)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(vtable + 20 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x57d520
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive axis getter matches; class lifetime, dependencies and runtime ABI remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'address': '0057d520', 'symbol': name, 'size': len(body), 'exact': True, 'vtable': hex(vtable), 'calls': {k: hex(v) for k, v in calls.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/rotate-axis-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native RotateSelectionVerb axis getter')
