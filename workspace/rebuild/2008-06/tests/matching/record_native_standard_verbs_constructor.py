"""Verify StandardVerbs constructor in an isolated native layout."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeStandardVerbsConstructorTrial.cpp'
layout = root / 'rebuild/2008-06/native-headers/StandardVerbs.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeStandardVerbsConstructorTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0StandardVerbs@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005c7ea0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'??0DeleteBase@RBX@@': 0x57e8d0, '??0RunStateVerb@RBX@@': 0x57e330,
            '??0EditSelectionVerb@RBX@@': 0x57e730, '??0GroupSelectionVerb@RBX@@': 0x57e7e0,
            '??_7PlayDeleteSelectionVerb@RBX@@': 0x838f2c, '??_7DeleteSelectionVerb@RBX@@': 0x80e978,
            '??_7RunCommand@RBX@@': 0x83905c, '??_7?$TToolVerb@VArrowTool@RBX@@': 0x8390c8}
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
        value = (0x5c7ea0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected), found
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '005c7ea0', 'size': len(body), 'targets': found,
           'scope': 'Inactive trial. Referenced command vtables, constructors, class layouts, workspace factory, exception handling and ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/standard-verbs-constructor-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider StandardVerbs constructor and selected targets')
