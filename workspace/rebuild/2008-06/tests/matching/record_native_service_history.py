"""Verify change-history service lookup and creation with original shared_ptr codegen."""
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
pre = out / 'service-history-preprocess'
pre.mkdir(exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
source = root / 'rebuild/2008-06/native-classes/ServiceChangeHistory.cpp'
pre_flags = [x for x in common if x != '/c'] + ['/DSERVICE_HISTORY_FIND_ONLY', '/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
text = (pre / 'ServiceChangeHistory.i').read_text(errors='replace')
needle = 'template<class T> class shared_ptr\n{\nprivate:'
assert text.count(needle) == 1
# An empty explicit destructor still destroys shared_count; noinline preserves the original call boundary.
text = text.replace(needle, 'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr() {}\nprivate:', 1)
profile = out / 'ServiceChangeHistoryProfile.cpp'
profile.write_text(text)
obj = out / 'ServiceChangeHistoryProfile.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
create_obj = out / 'ServiceChangeHistoryCreate.obj'
create_flags = common + ['/DSERVICE_HISTORY_CREATE_ONLY', '/Fo' + str(create_obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', create_flags, out)
assert code == 0, log
rows = []
for object_path, address, prefix, required in [
    (obj, '00452a00', '??$find@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@', [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VChangeHistoryService', 0x44f360), ('?findServiceByClassName@ServiceProvider@', 0x572a90), ('??1?$shared_ptr@VInstance@RBX@@', 0x600660)]),
    (create_obj, '00453000', '??$create@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@', [('??$find@VChangeHistoryService@', 0x452a00), ('??$create@VChangeHistoryService@RBX@@@?$Creatable@', 0x4150d0), ('??$doGetClassIndex@VChangeHistoryService', 0x44f360), ('?setParent@Instance@', 0x55a8f0)]),
    (create_obj, '004150d0', '??$create@VChangeHistoryService@RBX@@@?$Creatable@', [('??0ChangeHistoryService@RBX@@', 0x58ab90), ('??$?0VChangeHistoryService@RBX@@VDeleter@', 0x415020)]),
    (obj, '0044f360', '??$doGetClassIndex@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@', [('?newIndex@ServiceProvider@', 0x572690)]),
]:
    raw = object_path.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body)-4 and kind == 20:
            edges[symbols[symbol][0]] = hex(int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0])
    for symbol, dest in required:
        assert any(k.startswith(symbol) and v == hex(dest) for k, v in edges.items()), (address, symbol, edges)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': edges})

raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$doDeclare@$1?sChangeHistoryService'))
target, targetrefs, _ = match.target('2008-06', '004137a0')
assert match.exact_match(target, targetrefs, body, refs)
start, index = definitions[name]
section = sections[index]
expected = {'??_C@': 0x948df8, '?declare@Name@RBX@@': 0x553f90,
            '?$S2@': 0x96cc14, '?name@': 0x96cc10}
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (0x4137a0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected), found
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert pe.get_data(0x948df8 - pe.OPTIONAL_HEADER.ImageBase, 21) == b'ChangeHistoryService\0'
rows.append({'address': '004137a0', 'symbol': name, 'size': len(body), 'data_and_call_targets': found})
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getClassName@?$FactoryProduct@VChangeHistoryService'))
target, targetrefs, _ = match.target('2008-06', '00587c80')
assert match.exact_match(target, targetrefs, body, refs)
assert struct.unpack('<I', pe.get_data(0x8318b4-pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x587c80
start, index = definitions[name]
section = sections[index]
expected = {'?flag@': 0x96cc2c, '??$callDoDeclare@': 0x413a50,
            '?call_once@boost@@': 0x557330, '??$doDeclare@': 0x4137a0}
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (0x587c80 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected), found
rows.append({'address': '00587c80', 'symbol': name, 'size': len(body),
             'original_vtable_slot': '0x8318b4', 'data_and_call_targets': found})
callback_name, callback_body, callback_refs = next(x for x in match.coff_functions(raw)
    if x[0].startswith('??$callDoDeclare@$1?sChangeHistoryService'))
callback_target, callback_targetrefs, _ = match.target('2008-06', '00413a50')
assert match.exact_match(callback_target, callback_targetrefs, callback_body, callback_refs)
callback_start, callback_index = definitions[callback_name]
callback_section = sections[callback_index]
callback_edges = []
for i in range(callback_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, callback_section[5] + 10*i)
    offset -= callback_start
    if kind == 20 and 0 <= offset < len(callback_body)-3:
        dest = (0x413a50 + offset + 4 + struct.unpack_from('<i', callback_target, offset)[0]) & 0xffffffff
        callback_edges.append((symbols[symbol][0], dest))
assert len(callback_edges) == 1 and callback_edges[0][0].startswith('??$doDeclare@') and callback_edges[0][1] == 0x4137a0
declare_name, declare_body, declare_refs = next(x for x in match.coff_functions(raw)
    if x[0].startswith('??$declare@$1?sChangeHistoryService'))
assert match.exact_match(target, targetrefs, declare_body, declare_refs)
rows.append({'address': '00413a50', 'symbol': callback_name, 'size': len(callback_body),
             'direct_target': '0x4137a0', 'inline_declare_symbol': declare_name})

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'find_object_sha256': sha(obj), 'create_object_sha256': sha(create_obj),
           'preprocess_flags': pre_flags, 'find_flags': flags, 'create_flags': create_flags, 'methods': rows,
           'scope': 'Inactive compiler-profile trial. Find and create require separate profiles; COMDAT selection, factory, service-cache globals, live ownership and ABI remain unverified.'}
(root / 'work/2008-06/shared-layouts/service-history-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS change-history service lookup, creation and class-index targets')
