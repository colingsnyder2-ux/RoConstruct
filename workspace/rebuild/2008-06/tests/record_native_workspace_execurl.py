"""Verify the inactive native ExecUrlScript profile and call bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'execurl-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/tests/NativeWorkspaceExecUrlTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/I' + str(root / 'rebuild/2008-06/tests'), '/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'NativeWorkspaceExecUrlTrial.i').read_text(errors='replace')
for needle in ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );', 'const _Elem * c_str() const'):
    assert text.count(needle) == 1
    text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'NativeWorkspaceExecUrlProfile.cpp'
profile.write_text(text)
obj = probe / 'NativeWorkspaceExecUrlProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?ExecUrlScript@CWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '0046c430')
assert match.exact_match(target, targetrefs, body, refs), (len(body), len(target))
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x46c430 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, value in [('??$create@VContentProvider@RBX@@', 0x41eea0), ('?getContent@ContentProvider@RBX@@', 0x561f20), ('??$copy_impl@', 0x451300), ('?execScript@CWorkspace@@', 0x46b230), ('?reportWorkspaceSiteError@@', 0x429330), ('?workspaceSiteErrorContext@@', 0x8164f8), ('__imp_??B?$CSimpleStringT@', 0x803ee0), ('__imp_?c_str@', 0x802464)]:
    assert any(k.startswith(prefix) and value in values for k, values in bindings.items()), (prefix, bindings)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive exact method; ContentProvider shared layout, class lifetimes and live ownership remain unproven. Do not run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'provider_trial_sha256': sha(root / 'rebuild/2008-06/tests/NativeContentProviderTrial.cpp'), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'symbol': name, 'address': '0046c430', 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/workspace-execurl-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ExecUrlScript and original call bindings')
