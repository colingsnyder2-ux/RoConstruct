"""Profile the original ATL ANSI error helper using the vendor header."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeAtlErrorCoreTrial.cpp'
obj = out / 'NativeAtlErrorCoreTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?AtlReportError@ATL@@'))
target, target_refs, _ = match.target('2008-06', '004290b0')
assert match.exact_match(target, target_refs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x4290b0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, address in [('__imp__lstrlenA@4', 0x8021b8), ('?AtlA2WHelper@@', 0x401760), ('?AtlSetErrorInfo@ATL@@', 0x428ae0), ('?_AtlVerifyStackAvailable@', 0x402610), ('?Allocate@', 0x402f50)]:
    assert any(k.startswith(prefix) and v == {address} for k, v in bindings.items()), (prefix, bindings)
receipt = {'scope': 'Inactive original ATL ANSI error helper matches; helper implementations and runtime ABI remain unproven.', 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'vendor_header_sha256': hashlib.sha256((root / 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlcom.h').read_bytes()).hexdigest(), 'address': '004290b0', 'size': len(body), 'relocation_normalized_exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/atl-error-core-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS 004290b0 and selected call targets')
