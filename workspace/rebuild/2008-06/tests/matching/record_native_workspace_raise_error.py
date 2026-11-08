"""Verify native Workspace error construction, reporting and exception throw."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/WorkspaceRaiseError.cpp'
obj = out / 'NativeWorkspaceRaiseError.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?raiseWorkspaceError@@'))
target, targetrefs, _ = match.target('2008-06', '0046ad70')
assert match.exact_match(target, targetrefs, body, refs)
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x46ad70 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
for prefix, value in [('??2@YAPAXI@Z', 0x6a0920), ('??0CException@@', 0x6a0f62), ('??_7COleException@@', 0x810384), ('?AtlReportError@ATL@@', 0x4290b0), ('__CxxThrowException@8', 0x6a158c), ('_GUID_NULL', 0x8501ec)]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
assert bytes.fromhex('01 40 00 80') in target
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive exact Workspace error throw; exception RTTI/data and live ownership remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'address': '0046ad70', 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-raise-error-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace exception throw')
