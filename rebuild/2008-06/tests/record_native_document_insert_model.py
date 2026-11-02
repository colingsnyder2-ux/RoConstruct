"""Verify original CRobloxDoc insert-model handler under the MFC conversion profile."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
pre = out / 'insert-model-preprocess'
pre.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/DocumentInsertModel.cpp'
header = root / 'rebuild/2008-06/native-headers/CRobloxDoc.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
pre_flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre_flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
text = (pre / 'DocumentInsertModel.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert text.count(needle) == 1
profile = pre / 'DocumentInsertModelProfile.cpp'
profile.write_text(text.replace(needle, '__declspec(noinline) ' + needle))
obj = out / 'NativeDocumentInsertModelProfile.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_455c30@CRobloxDoc'))
target, targetrefs, _ = match.target('2008-06', '00455c30')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
mfc_lib = root / 'rebuild/2008-06/out/p6/mfc90.lib'
mfc_ordinals = {}
for _, member in libs.archive_members(mfc_lib):
    if len(member) < 20 or member[:4] != b'\0\0\xff\xff':
        continue
    ordinal = struct.unpack_from('<H', member, 16)[0]
    mfc_ordinals[ordinal] = member[20:].split(b'\0', 1)[0].decode('ascii')
imports = {entry.address: (entry.name.decode('ascii') if entry.name else mfc_ordinals[entry.ordinal])
           for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports
           if entry.name or (dll.dll.lower() == b'mfc90.dll' and entry.ordinal in mfc_ordinals)}
expected = {'??0CFileDialog@@': 0x6a0e72, '?DoModal@CFileDialog@@': 0x6a0e6c,
            '?GetPathName@CFileDialog@@': 0x6a0e66, '?loadFile@CRobloxDoc@@': 0x455a20,
            '??1CFileDialog@@': 0x6a0e5a, '??_C@': 0x817f08}
start, index = definitions[name]
section = sections[index]
found, api = {}, []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x455c30 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
    if symbol.startswith('__imp_'):
        assert symbol[6:] == imports[value], (symbol, imports[value])
        api.append(imports[value])
assert set(found) == set(expected) and len(api) == 7
assert pe.get_string_at_rva(0x817f08-pe.OPTIONAL_HEADER.ImageBase) == b'lua'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'header_sha256': sha(header), 'observer_sha256': sha(Path(__file__)),
           'mfc_import_lib_sha256': sha(mfc_lib),
           'object_sha256': sha(obj), 'preprocess_flags': pre_flags, 'flags': flags,
           'address': '00455c30', 'size': len(body), 'targets': found, 'imports': api,
           'scope': 'Inactive compiler profile; loadFile, MFC ownership, Doc ABI and runtime remain unproven.'}
(root / 'work/2008-06/shared-layouts/document-insert-model-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Doc insert-model body, calls and imports')
