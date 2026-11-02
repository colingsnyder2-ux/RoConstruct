"""Verify native VARIANT-to-Value conversion and typed Value constructors."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'lua-args-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/LuaArgs.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'LuaArgs.i').read_text(errors='replace')
for needle in ('Value(const ValueType& value)', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );', 'const _Elem * c_str() const'):
    assert text.count(needle) == 1
    text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'LuaArgsProfile.cpp'
profile.write_text(text)
obj = probe / 'LuaArgsProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = match.coff_functions(raw)
checks = [('?push@LuaArgs@@', '0042db20'), ('??$?0M@Value@Reflection@RBX@@', '0042d200'), ('??$?0_N@Value@Reflection@RBX@@', '0042d240'), ('??$?0H@Value@Reflection@RBX@@', '0042d280'), ('??$?0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Value@Reflection@RBX@@', '004175d0'), ('?push_back@?$vector@VValue@Reflection@RBX@@', '0042daa0')]
rows = []
for prefix, address in checks:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (prefix, len(body), len(target))
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'exact': True})
name, body, refs = next(x for x in functions if x[0].startswith('?push@LuaArgs@@'))
target, _, _ = match.target('2008-06', '0042db20')
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x42db20 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, value in [('??$?0M@Value@', 0x42d200), ('??$?0_N@Value@', 0x42d240), ('??$?0H@Value@', 0x42d280), ('?push_back@?$vector@VValue@', 0x42daa0), ('__imp_??B?$CSimpleStringT@', 0x803ee0), ('?format@G3D@@', 0x509b10)]:
    assert any(k.startswith(prefix) and value in values for k, values in bindings.items()), (prefix, bindings)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive conversion and selected Value constructors match. Complete Value lifetime, type data identity and live ABI remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'lua_args_header_sha256': sha(root / 'rebuild/2008-06/native-headers/LuaArgs.h'), 'value_header_sha256': sha(root / 'rebuild/2008-06/native-headers/reflection/type.h'), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'methods': rows, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/lua-args-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native LuaArgs conversion and Value constructors')
