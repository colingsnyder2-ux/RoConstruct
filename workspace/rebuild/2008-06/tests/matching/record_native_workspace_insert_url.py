"""Verify native Workspace URL insertion and content-fetch helper."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'content-insert-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceInsertUrlTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/I' + str(root / 'rebuild/2008-06/tests'), '/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'NativeWorkspaceInsertUrlTrial.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert text.count(needle) == 1
text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'NativeWorkspaceInsertUrlProfile.cpp'
profile.write_text(text)
obj = probe / 'NativeWorkspaceInsertUrlProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
checks = [
    ('?insert@CWorkspace@@QAEXVContentId@RBX@@', 0x46bc90, [('??$create@VContentProvider@RBX@@', 0x41eea0), ('?getContent@ContentProvider@RBX@@', 0x561f20), ('?insert@CWorkspace@@QAEXAAV', 0x46b9d0)]),
    ('?Insert@CWorkspace@@', 0x46c920, [('?validateWorkspaceSiteUrl@@', 0x41dcd0), ('?reportWorkspaceSiteError@@', 0x429330), ('?workspaceSiteErrorContext@@', 0x8164f8), ('??0ContentId@RBX@@', 0x4377c0), ('?insert@CWorkspace@@QAEXVContentId@', 0x46bc90), ('__imp_??B?$CSimpleStringT@', 0x803ee0)]),
]
vtables = json.loads((root / 'work/2008-06/shared-layouts/workspace-factory-vtables-trial.json').read_text())['tables']
assert any(slot['symbol'].startswith('?Insert@CWorkspace@@') and int(slot['original_target'], 16) == 0x46c920 for table in vtables for slot in table['slots'])
rows = []
for prefix, address, expected in checks:
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
    for key, value in expected:
        assert any(k.startswith(key) and value in values for k, values in bindings.items()), (key, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}})
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive insertion profile matches; trust dependencies, provider layout, object ownership and live ABI remain unproven. Do not run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'provider_trial_sha256': sha(root / 'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'methods': rows, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/workspace-insert-url-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace insertion and URL helper')
