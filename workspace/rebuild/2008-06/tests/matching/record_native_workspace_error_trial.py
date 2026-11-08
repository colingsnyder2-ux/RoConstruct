"""Check the inactive workspace error wrapper and its original GUID data."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceErrorTrial.cpp'
obj = out / 'NativeWorkspaceErrorTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?reportWorkspaceSiteError@@'))
target, target_refs, _ = match.target('2008-06', '00429330')
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
            value = (0x429330 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
for prefix, address in [('?reportWorkspaceStatus@@', 0x427c20), ('?AtlReportError@ATL@@', 0x4290b0), ('_GUID_NULL', 0x8501ec)]:
    assert any(k.startswith(prefix) and v == address for k, v in bindings.items()), (prefix, bindings)
guid_offset, guid_section = definitions['?workspaceSiteErrorContext@@3U_GUID@@B']
guid = raw[sections[guid_section][4] + guid_offset:][:16]
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert guid == pe.get_data(0x8164f8 - pe.OPTIONAL_HEADER.ImageBase, 16)
receipt = {
    'scope': 'Inactive wrapper and GUID match; helper implementations, identity and live ABI unproven.',
    'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
    'object_sha256': hashlib.sha256(raw).hexdigest(),
    'address': '00429330', 'size': len(body), 'relocation_normalized_exact': True,
    'bindings': {k: hex(v) for k, v in bindings.items()},
    'guid_address': '008164f8', 'guid_bytes': guid.hex(), 'flags': flags,
}
(root / 'work/2008-06/shared-layouts/workspace-error-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS 00429330 and workspace GUID; helper runtime ABI remains unproven')
