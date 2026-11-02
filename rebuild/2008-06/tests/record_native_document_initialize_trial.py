"""Verify initializeCommands in an isolated native layout."""
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
source = root / 'rebuild/2008-06/tests/NativeDocumentInitializeTrial.cpp'
layout = root / 'rebuild/2008-06/native-headers/CRobloxDoc.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeDocumentInitializeTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?initializeCommands@CRobloxDoc@@'))
target, targetrefs, _ = match.target('2008-06', '00451b60')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'?createNativeWorkspace@@': 0x450370, '?getDataModel@CWorkspace@@': 0x46a940,
            '?getWorkspace@CWorkspace@@': 0x46a970, '??0Lock@DataModel@RBX@@': 0x411b40,
            '??1Lock@DataModel@RBX@@': 0x5773c0, '??0StandardVerbs@RBX@@': 0x5c7ea0,
            '??1StandardVerbs@RBX@@': 0x450450, '?bindExisting@CRobloxDoc@@': 0x451a10,
            '?bindOwned@CRobloxDoc@@': 0x451a60, '?lookup@Name@RBX@@': 0x554290,
            '??_7ReportAbuseVerb@@': 0x8172e0, '??_7FixedCameraCommand@RBX@@': 0x817c00,
            '??_7InsertTexture@@': 0x817324}
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
        value = (0x451b60 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected), found
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00451b60', 'size': len(body), 'targets': found,
           'scope': 'Inactive trial. Inactive trial. Referenced command vtables, constructors, class layouts, workspace factory, exception handling and ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/document-initialize-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider initializeCommands and selected targets')
