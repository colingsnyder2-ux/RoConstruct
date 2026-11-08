"""Verify Workspace COM Write methods against original factory and writer calls."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceWriteTrial.cpp'
obj = out / 'NativeWorkspaceWriteTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
vtables = json.loads((root / 'work/2008-06/shared-layouts/workspace-factory-vtables-trial.json').read_text())['tables']
rows = []
for method, address, root_target in [('Write', 0x46bd70, 0x46ab90), ('WriteSelection', 0x46bfd0, 0x46b750)]:
    prefix = '?' + method + '@CWorkspace@@'
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (method, len(body), len(target))
    assert any(slot['symbol'].startswith(prefix) and int(slot['original_target'], 16) == address for table in vtables for slot in table['slots'])
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
    for key, value in [('?CreateInstance@?$CComObject@VCContent@@', 0x46ac90), ('?writeXml', root_target), ('?write@CWorkspace@@', 0x46b860), ('?reportWorkspaceHResult@@', 0x427d80), ('?raiseWorkspaceError@@', 0x46ad70), ('?reportWorkspaceSiteError@@', 0x429330), ('?workspaceSiteErrorContext@@', 0x8164f8)]:
        assert any(k.startswith(key) and value in values for k, values in bindings.items()), (method, key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}})
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive exact COM Write methods. XML writer, COM map identity, error helpers and live lifetime remain unproven. Do not run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'workspace_header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'content_header_sha256': sha(root / 'rebuild/2008-06/native-headers/CContent.h'), 'object_sha256': sha(obj), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-write-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace COM Write methods')
