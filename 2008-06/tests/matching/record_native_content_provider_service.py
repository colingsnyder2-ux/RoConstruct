"""Verify isolated native ContentProvider lookup and factory profiles."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
pre = out/'provider-service-pre'
pre.mkdir(exist_ok=True)
source = root/'rebuild/2008-06/experiments/trials/NativeContentProviderServiceTrial.cpp'
layout_source = root/'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
pre_flags = [x for x in common if x != '/c'] + ['/DSERVICE_CONTENT_FIND_ONLY', '/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
text = (pre/'NativeContentProviderServiceTrial.i').read_text(errors='replace')
needle = 'template<class T> class shared_ptr\n{\nprivate:'
assert text.count(needle) == 1
profile = pre/'ProviderFindProfile.cpp'
profile.write_text(text.replace(needle, 'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr() {}\nprivate:', 1))
find_obj = out/'NativeProviderFindProfile.obj'
find_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo'+str(find_obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', find_flags, pre)
assert code == 0, log
create_obj = out/'NativeProviderCreateTrial.obj'
create_flags = common + ['/DSERVICE_CONTENT_CREATE_ONLY', '/Fo'+str(create_obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', create_flags, out)
assert code == 0, log
rows = []
for path, address, prefix, expected in [
    (find_obj, '0041ed60', '??$find@VContentProvider@RBX@@@ServiceProvider@',
     [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VContentProvider', 0x41e050),
      ('?resize@?$vector@', 0x4124c0), ('?call_once@boost@@', 0x557330),
      ('??$doDeclare@$1?sContentProvider', 0x41dfe0), ('?findServiceByClassName@ServiceProvider@', 0x572a90),
      ('??1?$shared_ptr@VInstance@', 0x600660), ('??4shared_count@', 0x4025b0), ('??1?$shared_ptr@VInstance@', 0x600660)]),
    (create_obj, '0041eea0', '??$create@VContentProvider@RBX@@@ServiceProvider@',
     [('??$find@VContentProvider@', 0x41ed60), ('??$create@VContentProvider@RBX@@@?$Creatable@', 0x41e5d0),
      ('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VContentProvider', 0x41e050),
      ('??4shared_count@', 0x4025b0), ('?setParent@Instance@', 0x55a8f0)]),
    (create_obj, '0041e5d0', '??$create@VContentProvider@RBX@@@?$Creatable@',
     [('??0ContentProvider@RBX@@', 0x562c30), ('??$?0VContentProvider@RBX@@', 0x41e420)]),
    (find_obj, '0041e050', '??$doGetClassIndex@VContentProvider@RBX@@@ServiceProvider@',
     [('?newIndex@ServiceProvider@', 0x572690)]),
    (find_obj, '0041dfe0', '??$doDeclare@$1?sContentProvider', [('?declare@Name@RBX@@', 0x553f90)]),
]:
    raw = path.read_bytes()
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[name]
    section = sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body)-3:
            value = (int(address, 16)+offset+4+struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls.append((symbols[symbol][0], value))
    assert len(calls) == len(expected) and all(n.startswith(p) and v == want
        for (n, v), (p, want) in zip(calls, expected)), (address, calls)
    if address == '0041dfe0':
        data = {offset: value.split(b'\0', 1)[0] for offset, value, _ in match.coff_data_refs(raw, name)}
        pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
        assert data[0x2b] == pe.get_string_at_rva(0x9441cc-pe.OPTIONAL_HEADER.ImageBase) == b'ContentProvider'
    rows.append({'address': address, 'symbol': name, 'size': len(body),
                 'calls': [{'symbol': n, 'target': hex(v)} for n, v in calls]})
raw = find_obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw)
                        if x[0].startswith('?getClassName@?$NonFactoryProduct@VInstance@RBX@@$1?sContentProvider'))
target, targetrefs, _ = match.target('2008-06', '0055ddb0')
assert match.exact_match(target, targetrefs, body, refs)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x82df60-pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x55ddb0
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
expected = {'?flag@': 0x96d0cc, '??$callDoDeclare@': 0x41e0f0,
            '?call_once@boost@@': 0x557330, '??$doDeclare@': 0x41dfe0}
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
                value = (0x55ddb0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected), found
rows.append({'address': '0055ddb0', 'symbol': name, 'size': len(body),
             'original_vtable_slot': '0x82df60', 'targets': found})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_source_sha256': sha(layout_source),
           'observer_sha256': sha(Path(__file__)), 'find_object_sha256': sha(find_obj),
           'create_object_sha256': sha(create_obj), 'find_flags': find_flags, 'create_flags': create_flags,
           'preprocess_flags': pre_flags, 'methods': rows,
           'scope': 'Inactive isolated profiles. Template name representation, COMDAT selection, DataModel and service ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/content-provider-service-trial.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS native ContentProvider service lookup and factory trial')
