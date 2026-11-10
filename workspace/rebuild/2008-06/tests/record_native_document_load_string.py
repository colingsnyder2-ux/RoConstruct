"""Verify Doc script loading and original adjacent catch continuation."""
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
pre = out / 'load-string-preprocess'
pre.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/DocumentLoadFromString.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
pre_flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre_flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
text = (pre / 'DocumentLoadFromString.i').read_text(errors='replace')
needle = 'const _Elem * c_str() const'
assert text.count(needle) == 1
profile = pre / 'DocumentLoadFromStringProfile.cpp'
profile.write_text(text.replace(needle, '__declspec(noinline) ' + needle))
obj = out / 'NativeDocumentLoadFromStringProfile.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo'+str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?loadFromString@CRobloxDoc'))
target, targetrefs, _ = match.target('2008-06', '00454ac0')
assert len(target) == 385 and len(body) == 459
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
full = pe.get_data(0x454ac0-pe.OPTIONAL_HEADER.ImageBase, len(body))
extra = [x-0x454ac0 for x in match._base_relocs('2008-06') if 0x454ac0+len(target) <= x < 0x454ac0+len(body)]
assert extra == [0x189, 0x1b2], extra
assert 0x454ac0 + len(body) <= 0x454c90
assert match.exact_match(full, targetrefs + extra, body, refs)
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'?getDataModel@CRobloxDoc@@': 0x403040, '??0Lock@DataModel@': 0x411b40,
            '??2@': 0x6a0920, '??$create@VScriptContext@': 0x42dfd0,
            '?executeInNewThread@ScriptContext@': 0x5b0480, '??1?$vector@VValue@': 0x42d630,
            '??3@': 0x6a067a, '??1Lock@DataModel@': 0x5773c0,
            '??_C@': 0x817ee8, '$LN14': 0x454c4e}
start, index = definitions[name]
section = sections[index]
found, api = {}, []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', full, offset)[0]
    if kind == 20:
        value = (0x454ac0 + offset + 4 + struct.unpack_from('<i', full, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
    if symbol.startswith('__imp_'):
        assert symbol[6:] == imports[value], (symbol, imports.get(value))
        api.append(imports[value])
assert set(found) == set(expected) and len(api) == 3, (found, api)
assert pe.get_string_at_rva(0x817ee8-pe.OPTIONAL_HEADER.ImageBase) == b'Doc script'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root/'rebuild/2008-06/native-headers/CRobloxDoc.h', root/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h',
         root/'rebuild/2008-06/native-headers/script/ScriptContext.h', Path(__file__)]
receipt = {'inputs': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj),
           'preprocess_flags': pre_flags, 'flags': flags, 'address': '00454ac0', 'analyzed_size': len(target),
           'observed_body_and_catch_size': len(body), 'targets': found, 'imports': api,
           'scope': 'Inactive diagnostic. Original adjacent catch continuation verified; exception metadata, script service ownership and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/document-load-string-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS Doc loadFromString and adjacent catch continuation')
