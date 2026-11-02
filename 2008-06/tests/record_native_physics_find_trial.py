"""Profile PhysicsService lookup with native name and out-of-line ownership."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorldServiceFactoriesTrial.cpp'
obj = out / 'NativePhysicsFindTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre = out / 'physics-find-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/DWORLD_PHYSICS_FIND_PROFILE', '/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeWorldServiceFactoriesTrial.i').read_text(errors='replace')
needle = 'template<class T> class shared_ptr\n{\nprivate:'
assert text.count(needle) == 1
text = text.replace(needle, 'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr();\nprivate:', 1)
profile = out / 'NativePhysicsFindProfile.cpp'
profile.write_text(text)
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$find@VPhysicsService@RBX@@@ServiceProvider'))
target, targetrefs, _ = match.target('2008-06', '004ccca0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls.setdefault(symbols[index][0], set()).add((0x4ccca0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff)
for key, value in [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VPhysicsService@', 0x4c9be0), ('?resize@?$vector@', 0x4124c0), ('??$doDeclare@', 0x4c9b70), ('?findServiceByClassName@ServiceProvider@', 0x572a90), ('??1?$shared_ptr@VInstance@RBX@@', 0x600660)]:
    assert any(k.startswith(key) and v == {value} for k, v in calls.items()), (key, calls)
selection = out / 'ServiceSelectionProfile.obj'
destructor, destructor_body, destructor_refs = next(x for x in match.coff_functions(selection.read_bytes()) if x[0].startswith('??1?$shared_ptr@VInstance@RBX@@'))
destructor_target, destructor_targetrefs, _ = match.target('2008-06', '00600660')
assert match.exact_match(destructor_target, destructor_targetrefs, destructor_body, destructor_refs)
declare_name, declare_body, declare_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$doDeclare@') and 'sPhysicsService' in x[0])
declare_target, declare_targetrefs, _ = match.target('2008-06', '004c9b70')
assert not match.exact_match(declare_target, declare_targetrefs, declare_body, declare_refs)
original = (root / 'work/2008-06/original-p4-reference/Roblox.exe').read_bytes()
original_rtti = b'.?AV?$DescribedNonCreatable@VPhysicsService@RBX@@VInstance@2@$1?sPhysicsService@2@3QBDB@RBX@@'
candidate_rtti = b'??_R0?AV?$DescribedNonCreatable@VPhysicsService@RBX@@VInstance@2@$1?sPhysicsService@2@3PBDB@RBX@@@8'
assert original_rtti in original
world_obj = out / 'NativeWorldServiceJointFindTrial.obj'
assert candidate_rtti in world_obj.read_bytes()
receipt = {'scope': 'Inactive lookup matches; original PhysicsService class-name storage and RTTI use an array, candidate uses a pointer. Name declaration body and type identity differ; do not use this profile as live ABI.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '004ccca0', 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: [hex(v) for v in sorted(values)] for k, values in calls.items()}, 'selected_destructor': {'object_sha256': hashlib.sha256(selection.read_bytes()).hexdigest(), 'symbol': destructor, 'address': '00600660', 'size': len(destructor_body), 'exact': True}, 'name_declaration': {'symbol': declare_name, 'address': '004c9b70', 'candidate_size': len(declare_body), 'original_size': len(declare_target), 'exact': False, 'original_rtti': original_rtti.decode(), 'candidate_rtti': candidate_rtti.decode()}, 'flags': compileflags}
(root / 'work/2008-06/shared-layouts/physics-find-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native PhysicsService lookup and selected shared_ptr destructor')
