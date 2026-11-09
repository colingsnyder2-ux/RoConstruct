"""Verify original Doc loadFile body under original library call boundaries."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
pre = out / 'load-file-preprocess'
pre.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/DocumentLoadFile.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
pre_flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre_flags += ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
text = (pre / 'DocumentLoadFile.i').read_text(errors='replace')
for needle in ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
               'const _Elem * c_str() const', 'ContentId(const char* id)'):
    assert text.count(needle) == 1
    text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = pre / 'DocumentLoadFileProfile.cpp'
profile.write_text(text)
obj = out / 'NativeDocumentLoadFileProfile.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?loadFile@CRobloxDoc'))
target, targetrefs, _ = match.target('2008-06', '00455a20')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
mfc_lib = root / 'rebuild/2008-06/out/p6/mfc90.lib'
mfc = {}
for _, member in libs.archive_members(mfc_lib):
    if len(member) >= 20 and member[:4] == b'\0\0\xff\xff':
        mfc[struct.unpack_from('<H', member, 16)[0]] = member[20:].split(b'\0', 1)[0].decode('ascii')
imports = {entry.address: (entry.name.decode('ascii') if entry.name else mfc[entry.ordinal])
           for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports
           if entry.name or (dll.dll.lower() == b'mfc90.dll' and entry.ordinal in mfc)}
expected = {'__chkstk': 0x6a1520, '?isUrl@ContentProvider@': 0x55bd10,
            '??0ContentId@RBX@@QAE@PBD': 0x4377c0, '?getDataModel@CRobloxDoc@@': 0x403040,
            '??$create@VContentProvider@RBX@@@ServiceProvider@': 0x41eea0, '?getFile@ContentProvider@': 0x561e30,
            '??0CFile@@': 0x6a13b8, '?Read@CFile@@': 0x6a13b2,
            '??1CFile@@': 0x6a13ac, '?loadFromString@CRobloxDoc@@': 0x454ac0}
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
        value = (0x455a20 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
    if symbol.startswith('__imp_'):
        assert symbol[6:] == imports[value], (symbol, imports.get(value))
        api.append(imports[value])
assert set(found) == set(expected) and len(api) == 13, (found, api)
ctor_name, ctor_body, ctor_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0ContentId@RBX@@QAE@PBD'))
ctor_target, ctor_targetrefs, _ = match.target('2008-06', '004377c0')
assert match.exact_match(ctor_target, ctor_targetrefs, ctor_body, ctor_refs)
# Original service factory allocates 0x19c and calls a constructor whose RTTI
# explicitly names ContentProvider. Donor headers currently model a singleton.
dis = Cs(CS_ARCH_X86, CS_MODE_32)
factory, _, _ = match.target('2008-06', '0041e5d0')
factory_ins = list(dis.disasm(factory, 0x41e5d0))
assert any(i.mnemonic == 'push' and i.op_str == '0x19c' for i in factory_ins)
assert any(i.mnemonic == 'call' and i.op_str == '0x562c30' for i in factory_ins)
create, _, _ = match.target('2008-06', '0041eea0')
create_calls = {int(i.op_str, 16) for i in dis.disasm(create, 0x41eea0)
                if i.mnemonic == 'call' and i.op_str.startswith('0x')}
assert {0x41ed60, 0x41e5d0, 0x41e050, 0x55a8f0} <= create_calls
provider_ctor, _, _ = match.target('2008-06', '00562c30')
assert any(i.mnemonic == 'mov' and i.op_str == 'dword ptr [esi], 0x82df6c'
           for i in dis.disasm(provider_ctor, 0x562c30))
read32 = lambda address: struct.unpack('<I', pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase, 4))[0]
locator = read32(0x82df6c - 4)
assert pe.get_string_at_rva(read32(locator + 12) + 8 - pe.OPTIONAL_HEADER.ImageBase) == b'.?AVContentProvider@RBX@@'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root/'rebuild/2008-06/native-headers/CRobloxDoc.h', root/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h',
         root/'tools/rbxgs/Client/App/include/util/ContentProvider.h', mfc_lib, Path(__file__)]
receipt = {'inputs': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj),
           'preprocess_flags': pre_flags, 'flags': flags, 'address': '00455a20', 'size': len(body),
           'targets': found, 'imports': api, 'content_id_constructor': {'address': '004377c0', 'size': len(ctor_body)},
           'provider_service': {'create': '0041eea0', 'factory': '0041e5d0', 'allocation_size': '0x19c',
                                'constructor': '00562c30', 'vtable': '0x82df6c', 'rtti': 'RBX::ContentProvider'},
           'scope': 'Inactive diagnostic; provider service identity, ContentId destructor, Doc runtime ABI and cross-module ownership remain unproven.'}
(root/'work/2008-06/shared-layouts/document-load-file-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS Doc loadFile body, calls, imports and ContentId constructor')
