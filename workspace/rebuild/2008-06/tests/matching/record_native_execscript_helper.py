"""Verify native CWorkspace script helper and its original call bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'execscript-helper-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/CWorkspaceExecScriptHelper.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'CWorkspaceExecScriptHelper.i').read_text(errors='replace')
needle = 'const _Elem * c_str() const'
assert text.count(needle) == 1
text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'CWorkspaceExecScriptHelperProfile.cpp'
profile.write_text(text)
obj = probe / 'CWorkspaceExecScriptHelperProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?execScript@CWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '0046b230')
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
            value = (0x46b230 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
expected = [('?checkSite@', 0x403b60), ('??0Lock@DataModel@', 0x411b40), ('??0LuaArgs@@', 0x4293d0), ('?push@LuaArgs@@', 0x42db20), ('?getDataModel@CWorkspace@@', 0x46a940), ('??$create@VScriptContext@', 0x42dfd0), ('?executeInNewThread@ScriptContext@', 0x5b0480), ('?makeSafeArray@@', 0x4165e0), ('??1Lock@DataModel@', 0x5773c0), ('?reportWorkspaceSiteError@@', 0x429330), ('?workspaceSiteErrorContext@@', 0x8164f8)]
for prefix, value in expected:
    assert any(k.startswith(prefix) and value in values for k, values in bindings.items()), (prefix, bindings)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive matching helper. LuaArgs conversion, SAFEARRAY builder, class lifetime and live ownership remain unproven; do not run.', 'observer_sha256': sha(Path(__file__)), 'source_sha256': sha(source), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CWorkspace.h'), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'address': '0046b230', 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/workspace-execscript-helper-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ExecScript helper and original call bindings')
