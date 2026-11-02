"""Verify native workspace save methods and original dependencies."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'save-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/CWorkspaceSave.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'CWorkspaceSave.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert text.count(needle) == 1
text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'CWorkspaceSaveProfile.cpp'
profile.write_text(text)
obj = probe / 'CWorkspaceSaveProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
vtables = json.loads((root / 'work/2008-06/shared-layouts/workspace-factory-vtables-trial.json').read_text())['tables']
rows = []
for method, address, writer in [('SaveToFile', 0x46c780, 0x46ab90), ('SaveSelectionToFile', 0x46b8d0, 0x46b750)]:
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
            bindings[symbols[index][0]] = value
    for key, value in [('??0Lock@DataModel@', 0x411b40), ('??1Lock@DataModel@', 0x5773c0), ('?writeXml', writer), ('?write@CWorkspace@@', 0x46b860), ('__imp_??B?$CSimpleStringT@', 0x803ee0)]:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (method, key, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive native methods match; XML writer signatures, ownership, class lifetime and live ABI remain unproven. Do not run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'methods': rows, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/workspace-save-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace save methods and original call bindings')
