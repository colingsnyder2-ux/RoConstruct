"""Verify Workspace selection serialization and instance collection."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/CWorkspaceSelection.cpp'
obj = out / 'CWorkspaceSelectionTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('?writeXmlSelection@CWorkspace@@', 0x46b750), ('?collectSelection@@', 0x57e140)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (prefix, len(body), len(target))
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < len(body) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings.setdefault(symbols[index][0], set()).add(value)
    if address == 0x46b750:
        for key, value in [('?newRootElement@SerializerV2@@', 0x591a30), ('??0Lock@DataModel@', 0x411b40), ('??$create@VSelection@RBX@@', 0x421cb0), ('?collectSelection@@', 0x57e140), ('??$for_each@', 0x423ba0), ('??1Lock@DataModel@', 0x5773c0)]:
            assert any(k.startswith(key) and value in values for k, values in bindings.items()), (key, bindings)
        assert bytes.fromhex('8b8604020000') in target
    else:
        assert bytes.fromhex('8b 50 38') in target
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}})
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive selection serializer and collector match; Workspace/Selection layout, XML object ownership and live ABI remain unproven. Do not run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'workspace_header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'selection_header_sha256': sha(root / 'rebuild/2008-06/native-headers/v8datamodel/Selection.h'), 'object_sha256': sha(obj), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-selection-serializer-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native selection serialization and instance collection')
