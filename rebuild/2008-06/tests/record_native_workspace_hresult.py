"""Verify native HRESULT reporting with the original MFC exception type."""
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
probe = out / 'hresult-report-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/WorkspaceHResult.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'WorkspaceHResult.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert text.count(needle) == 1
profile = probe / 'WorkspaceHResultProfile.cpp'
profile.write_text(text.replace(needle, '__declspec(noinline) ' + needle))
obj = probe / 'WorkspaceHResultProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?reportWorkspaceHResult@@'))
target, targetrefs, _ = match.target('2008-06', '00427d80')
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
            value = (0x427d80 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
for prefix, value in [('??0CException@@', 0x6a0f62), ('??_7COleException@@', 0x810384), ('?GetErrorMessage@COleException@@', 0x6a0f74), ('__imp_??B?$CSimpleStringT@', 0x803ee0), ('?reportWorkspaceStatus@@', 0x427c20)]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert pe.get_string_at_rva(0x8103b0 - pe.OPTIONAL_HEADER.ImageBase) == b'HRESULT = %d: %s\n%s(%d)'
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive exact HRESULT reporter; MFC data identity and runtime ownership remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'address': '00427d80', 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/workspace-hresult-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace HRESULT reporter')
