"""Verify CContent original COM factory, destruction and RTTI bases."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeContentFactoryTrial.cpp'
obj = out / 'NativeContentFactoryTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
    ('?CreateInstance@?$CComObject@VCContent@@', 0x46ac90, [('??2@YAPAXI@Z', 0x6a0920), ('__imp_??0?$basic_stringstream@', 0x802428), ('??_7?$CComObject@VCContent@@@ATL@@6B?$ISupportErrorInfoImpl', 0x80eabc), ('??_7?$CComObject@VCContent@@@ATL@@6B?$IDispatchImpl', 0x80ea98), ('?_pAtlModule@ATL@@', 0x96c268)]),
    ('??_G?$CComObject@VCContent@@', 0x416950, [('??_7?$CComObject@VCContent@@@ATL@@6B?$ISupportErrorInfoImpl', 0x80eabc), ('??_7?$CComObject@VCContent@@@ATL@@6B?$IDispatchImpl', 0x80ea98), ('__imp_??_D?$basic_stringstream@', 0x80242c), ('??3@YAXPAX@Z', 0x6a067a)]),
    ('?QueryInterface@?$CComObject@VCContent@@@ATL@@UAG', 0x416900, [('?_entries@', 0x80ead0), ('?AtlInternalQueryInterface@ATL@@', 0x402280)]),
    ('?QueryInterface@?$CComObject@VCContent@@@ATL@@W3', 0x416920, [('?QueryInterface@?$CComObject@VCContent@@@ATL@@UAG', 0x416900)]),
]:
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
            bindings[symbols[index][0]] = value
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
u32 = lambda address: struct.unpack('<I', pe.get_data(address - image, 4))[0]
locators = [u32(0x80eabc - 4), u32(0x80ea98 - 4)]
assert [u32(locator + 4) for locator in locators] == [0, 4]
for locator in locators:
    descriptor = u32(locator + 12)
    assert pe.get_string_at_rva(descriptor + 8 - image) == b'.?AV?$CComObject@VCContent@@@ATL@@'
hierarchy = u32(locators[0] + 16)
count, array = u32(hierarchy + 8), u32(hierarchy + 12)
bases = []
for i in range(count):
    descriptor = u32(array + 4 * i)
    name = pe.get_string_at_rva(u32(descriptor) + 8 - image).decode('ascii')
    bases.append({'type': name, 'offset': u32(descriptor + 8)})
assert any(x['type'] == '.?AVCContent@@' and x['offset'] == 0 for x in bases)
assert any(x['type'] == '.?AUIContent@@' and x['offset'] == 4 for x in bases)
assert any(x['type'].startswith('.?AV?$CComObjectRootEx@') and x['offset'] == 8 for x in bases)
map_name, (map_start, map_section) = next((name, value) for name, value in definitions.items() if name.startswith('?_entries@') and 'CContent' in name)
map_table = sections[map_section]
candidate = bytearray(raw[map_table[4] + map_start:map_table[4] + map_start + 48])
original = pe.get_data(0x80ead0 - image, 48)
guid_rows = []
for i in range(map_table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, map_table[5] + 10 * i)
    offset -= map_start
    if 0 <= offset < 48:
        assert kind == 6 and offset in (0, 12, 24)
        symbol = symbols[index][0]
        guid_offset, guid_section = definitions[symbol]
        data = raw[sections[guid_section][4] + guid_offset:][:16]
        original_address = struct.unpack_from('<I', original, offset)[0]
        assert data == pe.get_data(original_address - image, 16)
        candidate[offset:offset + 4] = original[offset:offset + 4]
        guid_rows.append({'symbol': symbol, 'address': hex(original_address), 'bytes': data.hex()})
assert len(guid_rows) == 3 and candidate == original
vtable_rows = []
local_functions = {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
for label, original_address, slot_count in [('ISupportErrorInfoImpl', 0x80eabc, 5), ('IDispatchImpl', 0x80ea98, 8)]:
    name, (start, section) = next((name, value) for name, value in definitions.items() if name.startswith('??_7?$CComObject@VCContent@@') and label in name)
    table = sections[section]
    slots = []
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < slot_count * 4:
            assert kind == 6 and offset % 4 == 0
            symbol = symbols[index][0]
            original_target = u32(original_address + offset)
            exact = None
            if symbol in local_functions:
                body, refs = local_functions[symbol]
                target, targetrefs, _ = match.target('2008-06', '%08x' % original_target)
                exact = match.exact_match(target, targetrefs, body, refs)
                assert exact, (symbol, hex(original_target))
            slots.append({'offset': hex(offset), 'symbol': symbol, 'original_target': hex(original_target), 'local_body_exact': exact})
    assert sorted(int(slot['offset'], 16) for slot in slots) == list(range(0, slot_count * 4, 4))
    vtable_rows.append({'symbol': name, 'original_address': hex(original_address), 'slots': slots})
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive native CContent factory, destructor and COM map match. COM data ownership, complete vtables and runtime behavior remain unproven.', 'observer_sha256': sha(Path(__file__)), 'source_sha256': sha(source), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CContent.h'), 'object_sha256': sha(obj), 'allocation_size': '0x94', 'stream_offset': '0xc', 'bases': bases, 'methods': rows, 'flags': flags}
receipt['com_map'] = {'symbol': map_name, 'address': '0x80ead0', 'size': 48, 'guid_entries': guid_rows, 'entry_offsets': [4, 4, 0], 'exact': True}
receipt['vtables'] = vtable_rows
(root / 'work/2008-06/shared-layouts/content-factory-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS CContent factory, deleting destructor and original RTTI')
