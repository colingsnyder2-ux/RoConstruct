"""Verify active-document globals and original startup/cleanup code."""
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
source = root / 'rebuild/2008-06/native-classes/ActiveDocumentData.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/pane-callbacks-working-probe.json').read_text())
obj = out / 'NativeActiveDocumentData.obj'
flags = previous['flags'] + ['/c', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {
    '??__EactiveDocViews': ('007ee720', {'?activeDocViews@@': 0x96c23c, '??0?$_Tree@': 0x64b2a0, '??__FactiveDocViews': 0x7fa090, '_atexit': 0x6a17af}),
    '??__EactiveDocDataModel': ('007ee750', {'??__FactiveDocDataModel': 0x7fa050, '_atexit': 0x6a17af}),
    '??__FactiveDocViews': ('007fa090', {'?activeDocViews@@': 0x96c23c, '??1?$_Tree@': 0x64b230}),
    '??__FactiveDocDataModel': ('007fa050', {'?activeDocDataModel@@': 0x96c260}),
}
rows = []
for prefix, (address, edges) in expected.items():
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = definitions[name]
    section = sections[index]
    found = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3:
            continue
        symbol = symbols[symbol][0]
        for key, wanted in edges.items():
            if symbol.startswith(key):
                value = struct.unpack_from('<I', target, offset)[0]
                if kind == 20:
                    value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                assert value == wanted, (address, symbol, hex(value), hex(wanted))
                found[key] = hex(value)
    assert set(found) == set(edges), (address, found)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'targets': found})
transition_target, transition_refs, _ = match.target('2008-06', '00405aa0')
transition_source = root / 'rebuild/2008-06/native-classes/ActiveDocument.cpp'
transition_obj = out / 'NativeActiveDocument.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags[:-2] + ['/Fo' + str(transition_obj), str(transition_source)], out)
assert code == 0, log
transition_name, transition_body, transition_candidate_refs = next(
    row for row in match.coff_functions(transition_obj.read_bytes()) if row[0].startswith('?setActiveDocument@@'))
assert match.exact_match(transition_target, transition_refs, transition_body, transition_candidate_refs)
transition = {'address': '00405aa0', 'symbol': transition_name, 'size': len(transition_body),
              'relocation_normalized_exact': True}
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
assert pe.get_data(0x96c238-base, 4) == bytes(4)
assert pe.get_data(0x96c25c-base, 8) == bytes(8)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'methods': rows, 'transition': transition,
           'zero_globals': ['0096c238', '0096c25c', '0096c260'],
           'scope': 'Inactive diagnostic. Global storage initializers and cleanup match; cross-module ownership and startup order remain unproven.'}
(root / 'work/2008-06/shared-layouts/active-document-data-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS active-document data initialization and cleanup')
