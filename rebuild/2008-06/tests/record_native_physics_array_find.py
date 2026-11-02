"""Verify PhysicsService lookup using original array-name template ABI."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
unit = 'roc_espeon_physicsservicenativeconstructorcfa29528d50b74b1.cpp'
source = root / 'rebuild/2008-06/tests/NativePhysicsArrayFindTrial.inc'
text = libs.unit('openrbx-client-dll', unit, 21022)
needle = 'template<class T> class shared_ptr\n{\nprivate:'
assert text.count(needle) == 1
text = text.replace(needle, 'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr();\nprivate:', 1)
needle = 'std::vector<boost::shared_ptr<Instance> > serviceArray;'
assert text.count(needle) == 1
text = text.replace(needle, 'mutable ' + needle, 1)
needle = 'Instance* findServiceByClassName(const Name& className) const;'
assert text.count(needle) == 1
text = text.replace(needle, 'boost::shared_ptr<Instance> findServiceByClassName(const Name& className) const;', 1)
start = text.index('class ServiceProvider : public DescribedNonCreatable<ServiceProvider')
opening = text.index('{', start)
declarations = '\npublic: static size_t newIndex(); template<class C> static size_t doGetClassIndex(); template<class C> static void callDoGetClassIndex(); template<class C> static size_t getClassIndex(); template<class C> C* find() const;\n'
text = text[:opening + 1] + declarations + text[opening + 1:]
needle = 'PhysicsService::PhysicsService() {setName("PhysicsService");}'
assert text.count(needle) == 1
text = text.replace(needle, '', 1)
profile = out / 'NativePhysicsArrayFindProfile.cpp'
profile.write_text(text + '\n' + source.read_text())
obj = out / 'NativePhysicsArrayFindTrial.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$find@VPhysicsService@RBX@@@ServiceProvider'))
target, targetrefs, _ = match.target('2008-06', '004ccca0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
def bindings(symbol, data, original, address):
    start, section = definitions[symbol]
    table = sections[section]
    result = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < len(data) - 3:
            value = struct.unpack_from('<I', original, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', original, offset)[0]) & 0xffffffff
            result.setdefault(symbols[index][0], set()).add(value)
    return result
find_calls = bindings(name, body, target, 0x4ccca0)
for key, value in [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VPhysicsService@', 0x4c9be0), ('??$doDeclare@', 0x4c9b70), ('?findServiceByClassName@ServiceProvider@', 0x572a90), ('??1?$shared_ptr@VInstance@RBX@@', 0x600660)]:
    assert any(k.startswith(key) and v == {value} for k, v in find_calls.items()), (key, find_calls)
declare_name, declare_body, declare_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$doDeclare@') and 'sPhysicsService' in x[0])
declare_target, declare_targetrefs, _ = match.target('2008-06', '004c9b70')
assert match.exact_match(declare_target, declare_targetrefs, declare_body, declare_refs)
declare_calls = bindings(declare_name, declare_body, declare_target, 0x4c9b70)
for key, value in [('?sPhysicsService@RBX@@3QBDB', 0x83f858), ('?declare@Name@RBX@@', 0x553f90)]:
    assert any(k.startswith(key) and v == {value} for k, v in declare_calls.items()), (key, declare_calls)
array_receipt = root / 'work/2008-06/shared-layouts/physics-array-lifetime-trial.json'
data = json.loads(array_receipt.read_text())
assert data['name']['symbol'] == '?sPhysicsService@RBX@@3QBDB'
receipt = {'scope': 'Inactive array-name PhysicsService lookup and Name::doDeclare match original. Static cache identity, ServiceProvider hierarchy and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'name_receipt_sha256': hashlib.sha256(array_receipt.read_bytes()).hexdigest(), 'methods': [{'address': '004ccca0', 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in find_calls.items()}}, {'address': '004c9b70', 'symbol': declare_name, 'size': len(declare_body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in declare_calls.items()}}], 'flags': flags}
(root / 'work/2008-06/shared-layouts/physics-array-find-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS array-name PhysicsService lookup and native Name declaration')
