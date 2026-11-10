"""Check ExecScript against real headers, original bindings and typelib."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
overlay = out / 'execscript-probe'
overlay.mkdir(exist_ok=True)
header = root / 'rebuild/2008-06/native-headers/CWorkspace.h'
source = root / 'rebuild/2008-06/native-classes/CWorkspaceExecScript.cpp'
obj = overlay / 'NativeExecScriptMismatch.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?ExecScript@CWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '0046c230')
assert len(body) == 580 and len(target) == 511 and not match.exact_match(target, targetrefs, body, refs)
pre_flags = [x for x in flags if x != '/c' and not x.startswith('/Fo') and x != str(source)] + ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, overlay)
assert code == 0, log
profile_text = (overlay / 'CWorkspaceExecScript.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert profile_text.count(needle) == 1
    profile_text = profile_text.replace(needle, '__declspec(noinline) ' + needle)
profile = overlay / 'NativeExecScriptProfile.cpp'
profile.write_text(profile_text)
profile_obj = overlay / 'NativeExecScriptProfile.obj'
profile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(profile_obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', profile_flags, overlay)
assert code == 0, log
profile_raw = profile_obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(profile_raw)
profile_name, profile_body, profile_refs = next(x for x in match.coff_functions(profile_raw) if x[0].startswith('?ExecScript@CWorkspace@@'))
assert match.exact_match(target, targetrefs, profile_body, profile_refs)
start, section = definitions[profile_name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', profile_raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(profile_body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x46c230 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
for prefix, value in [('?isUrl@ContentProvider@RBX@@', 0x55bd10), ('?execScript@CWorkspace@@', 0x46b230), ('__imp_??B?$CSimpleStringT@', 0x803ee0), ('__imp_?c_str@', 0x802464)]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
typelib = root / 'work/2008-06/shared-layouts/original-typelib.json'
typelib_data = json.loads(typelib.read_text())
original = root / 'work/2008-06/original-p4-reference/Roblox.exe'
assert typelib_data['original_sha256'] == hashlib.sha256(original.read_bytes()).hexdigest()
types = typelib_data['types']['IWorkspace']['methods']
result_type = {'vt': 26, 'element': {'vt': 27, 'element': {'vt': 12}}}
for method in ('ExecScript', 'ExecUrlScript'):
    row = next(row for row in types if row['names'][0] == method)
    assert row['parameters'][-1]['type'] == result_type
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports if entry.name}
assert imports[0x802908] == b'SafeArrayCreate'
helper, _, _ = match.target('2008-06', '0046b230')
convert, _, _ = match.target('2008-06', '004165e0')
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
helper_ins = {i.address: (i.mnemonic, i.op_str) for i in decoder.disasm(helper, 0x46b230)}
convert_ins = {i.address: (i.mnemonic, i.op_str) for i in decoder.disasm(convert, 0x4165e0)}
assert helper_ins[0x46b3fe] == ('call', '0x4165e0')
assert helper_ins[0x46b406] == ('mov', 'dword ptr [esi], eax')
assert convert_ins[0x416611] == ('push', '0xc')
assert convert_ins[0x41661f] == ('call', 'dword ptr [0x802908]')
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive native-header profile; helper implementation, class lifetime and live ABI remain unproven. Do not run.', 'observer_sha256': sha(Path(__file__)), 'source_sha256': sha(source), 'header_sha256': sha(header), 'object_sha256': sha(obj), 'address': '0046c230', 'symbol': name, 'candidate_size': len(body), 'original_size': len(target), 'exact': False, 'flags': flags}
receipt['profile'] = {'scope': 'Exact body and selected call targets; SAFEARRAY result supported by original typelib and helper conversion path.', 'object_sha256': sha(profile_obj), 'profile_sha256': sha(profile), 'size': len(profile_body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}, 'flags': profile_flags, 'typelib_sha256': sha(typelib), 'result_type': result_type, 'helper_result_conversion': '0x4165e0', 'safearray_create_import': '0x802908'}
(root / 'work/2008-06/shared-layouts/workspace-execscript-port-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ExecScript profile and SAFEARRAY result proof')
