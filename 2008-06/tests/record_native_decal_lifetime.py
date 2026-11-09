"""Verify Decal/Texture constructors and Decal destruction with native layout."""
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
source = root / 'rebuild/2008-06/native-classes/DecalLifetime.cpp'
obj = out / 'NativeDecalLifetime.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
        ('??0Decal@RBX@@', 0x598400, [('??0?$DescribedCreatable@VDecal@RBX@@', 0x598340)]),
        ('??0Texture@RBX@@', 0x598870, [('??0?$DescribedCreatable@VTexture@RBX@@', 0x598790)]),
        ('??1Decal@RBX@@', 0x597d30, [('??1?$FactoryProduct@VDecal@RBX@@VFaceInstance@', 0x597680)]),
        ('??1?$FactoryProduct@VTexture@RBX@@VDecal@', 0x597da0, [('??1Decal@RBX@@', 0x597d30)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (name, len(body), len(target))
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[symbols[index][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
base_source = root / 'rebuild/2008-06/native-classes/DecalBases.cpp'
base_obj = out / 'NativeDecalBases.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(base_obj), str(base_source)], out)
assert code == 0, log
base_raw = base_obj.read_bytes()
base_sections, base_symbols, base_definitions, _ = match._coff_data_index(base_raw)
base_rows = []
for cls, prefix, address, callee, destination in [
        ('Decal', '??0?$DescribedCreatable@VDecal@RBX@@', 0x598340, '??0?$FactoryProduct@VDecal@RBX@@', 0x597550),
        ('Texture', '??0?$DescribedCreatable@VTexture@RBX@@', 0x598790, '??0?$FactoryProduct@VTexture@RBX@@', 0x5985a0),
        ('Decal', '??0?$FactoryProduct@VDecal@RBX@@', 0x597550, '??0FaceInstance@RBX@@', 0x5ef530),
        ('Texture', '??0?$FactoryProduct@VTexture@RBX@@', 0x5985a0, '??0Decal@RBX@@', 0x598400)]:
    name, body, refs = next(x for x in match.coff_functions(base_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (name, len(body), len(target))
    start, section = base_definitions[name]
    table = base_sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', base_raw, table[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[base_symbols[index][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    assert any(k.startswith(callee) and v == destination for k, v in calls.items()), (cls, calls)
    base_rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
for cls, prefix, address, callee, destination in [
        ('Decal', '?getClassName@?$FactoryProduct@VDecal@RBX@@', 0x597d80, '??$doDeclare@$1?sDecal@RBX@@', 0x41de20),
        ('Texture', '?getClassName@?$FactoryProduct@VTexture@RBX@@', 0x597e20, '??$doDeclare@$1?sTexture@RBX@@', 0x41de90),
        ('Decal', '??$doDeclare@$1?sDecal@RBX@@', 0x41de20, '?declare@Name@RBX@@', 0x553f90),
        ('Texture', '??$doDeclare@$1?sTexture@RBX@@', 0x41de90, '?declare@Name@RBX@@', 0x553f90)]:
    name, body, refs = next(x for x in match.coff_functions(base_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (name, len(body), len(target))
    start, section = base_definitions[name]
    table = base_sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', base_raw, table[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[base_symbols[index][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    assert any(k.startswith(callee) and v == destination for k, v in calls.items()), (cls, calls)
    base_rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
for address, value in [(0x598483, 0x832720), (0x5988e8, 0x8328d8)]:
    assert struct.pack('<I', value) in pe.get_data(address - image, 12)
assert struct.unpack('<I', pe.get_data(0x832960 - image, 4))[0] == 0x598950
assert struct.unpack('<I', pe.get_data(0x80f18c + 4 - image, 4))[0] == 0x48ee50
assert struct.unpack('<I', pe.get_data(0x8326c4 + 4 - image, 4))[0] == 0x597d80
assert struct.unpack('<I', pe.get_data(0x832880 + 4 - image, 4))[0] == 0x597e20
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
for address, destination in [(0x598950, 0x598970), (0x598970, 0x597da0)]:
    original, _, _ = match.target('2008-06', '%08x' % address)
    assert any(i.mnemonic in ('call', 'jmp') and i.op_str == hex(destination)
               for i in decoder.disasm(original, address)), (hex(address), hex(destination))
locator = struct.unpack('<I', pe.get_data(0x83255c - 4 - image, 4))[0]
descriptor = struct.unpack('<I', pe.get_data(locator + 12 - image, 4))[0]
assert pe.get_string_at_rva(descriptor + 8 - image).startswith(b'.?AV?$FactoryProduct@VTexture@RBX@@VDecal@')
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive Decal/Texture constructors, base constructor chains and actual original deletion chain match; full virtual identity and runtime ownership remain unproven.', 'source_sha256': sha(source), 'face_header_sha256': sha(root / 'rebuild/2008-06/native-headers/v8datamodel/FaceInstance.h'), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'methods': rows, 'base_source_sha256': sha(base_source), 'base_object_sha256': sha(base_obj), 'base_methods': base_rows, 'texture_deletion': {'control_vtable': '0x80f18c', 'dispose': '0x48ee50', 'object_base_vtable': '0x832960', 'adjustor': '0x598950', 'scalar_delete': '0x598970', 'factory_base_destructor': '0x597da0', 'decal_destructor': '0x597d30'}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/decal-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Decal/Texture constructors and Decal destructor')
