"""Verify PhysicsService using its recovered original array-name class template."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
unit = 'roc_espeon_physicsservicenativeconstructorcfa29528d50b74b1.cpp'
source = root / 'rebuild/2008-06/tests/NativePhysicsArrayLifetimeTrial.inc'
profile = out / 'NativePhysicsArrayLifetimeProfile.cpp'
text = libs.unit('openrbx-client-dll', unit, 21022)
replacements = {
    'virtual bool askAddChild(const Instance* instance) const { return false; }': 'virtual bool askAddChild(const Instance* instance) const;',
    'virtual bool askSetParent(const Instance* instance) const { return false; }': 'virtual bool askSetParent(const Instance* instance) const;',
    'virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {\n\t}': 'virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);',
}
for old, new in replacements.items():
    assert text.count(old) == 1, old
    text = text.replace(old, new, 1)
old_shared_count = '''template<class P, class D> shared_count(P p, D d): pi_(0)
    {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
        if(pi_ == 0)
        {
            d(p);{space}
            boost::throw_exception(std::bad_alloc());
        }
    }'''.replace('{space}', ' ')
native_shared_count = '''template<class P, class D> shared_count(P p, D d): pi_(0)
    {
        try { pi_ = new sp_counted_impl_pd<P, D>(p, d); }
        catch (...) { d(p); throw; }
    }'''
assert text.count(old_shared_count) == 1
text = text.replace(old_shared_count, native_shared_count, 1)
old_pointer_count = '''template<class Y> explicit shared_count( Y * p ): pi_( 0 )
    {
        pi_ = new sp_counted_impl_p<Y>( p );
        if( pi_ == 0 )
        {
            boost::checked_delete( p );
            boost::throw_exception( std::bad_alloc() );
        }
    }'''
native_pointer_count = '''template<class Y> explicit shared_count( Y * p ): pi_( 0 )
    {
        try { pi_ = new sp_counted_impl_p<Y>( p ); }
        catch (...) { boost::checked_delete( p ); throw; }
    }'''
assert text.count(old_pointer_count) == 1
text = text.replace(old_pointer_count, native_pointer_count, 1)
weak_definition = '''inline shared_count::shared_count( weak_count const & r ): pi_( r.pi_ )
{
    if( pi_ == 0 || !pi_->add_ref_lock() )
    {
        boost::throw_exception( boost::bad_weak_ptr() );
    }
}'''
assert text.count(weak_definition) == 1
text = text.replace(weak_definition, '', 1)
function1_definition = r'template<typename R\s*,\s*typename T0,\s*typename Allocator>\s*typename function1<\s*R\s*,\s*T0,\s*Allocator>::result_type\s*function1<R\s*,\s*T0,\s*Allocator>\s*::operator\(\)\( T0 a0\) const\s*\{.*?\n  \}'
text, removed = re.subn(function1_definition, '', text, count=1, flags=re.S)
assert removed == 1
event_declarations = '''class World;
class Primitive;
struct AssemblyPhysicsOn { Primitive* primitive; };
struct AssemblyPhysicsOff { Primitive* primitive; };
class PartInstance : public Instance { public: static PartInstance* fromPrimitive(Primitive*); };'''
old_declarations = '''class World;
struct AssemblyPhysicsOn;
struct AssemblyPhysicsOff;
class PartInstance;'''
assert text.count(old_declarations) == 1
text = text.replace(old_declarations, event_declarations, 1)
old_events = ''' virtual void onEvent(const World*,AssemblyPhysicsOff);
 public: PhysicsService();'''
new_events = ''' virtual void onEvent(const World*,AssemblyPhysicsOff);
 void onAdded(PartInstance*);
 void onRemoved(PartInstance*);
 static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventAdded;
 static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventRemoved;
 public: PhysicsService();'''
assert text.count(old_events) == 1
text = text.replace(old_events, new_events, 1)
text += '''
namespace RBX {
Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> PhysicsService::eventAdded("AssemblyAdded", "part");
Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> PhysicsService::eventRemoved("AssemblyRemoved", "part");
void PhysicsService::onEvent(const World*, AssemblyPhysicsOn e) { onAdded(PartInstance::fromPrimitive(e.primitive)); }
void PhysicsService::onEvent(const World*, AssemblyPhysicsOff e) { onRemoved(PartInstance::fromPrimitive(e.primitive)); }
void PhysicsService::onAdded(PartInstance* part) {
    eventAdded.fire(this, shared_from(part));
    std::pair<std::set<PartInstance*>::iterator, bool> result = parts.insert(part);
}
void PhysicsService::onRemoved(PartInstance* part) { parts.erase(part); eventRemoved.fire(this, shared_from(part)); }
}
'''
profile.write_text(text + '\n' + source.read_text())
obj = out / 'NativePhysicsArrayLifetimeTrial.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
signal_methods = []
for prefix, address, expected in [
    ('??__E?eventAdded@PhysicsService', 0x7f6e40, [('AssemblyAdded', 0x83f878), ('part', 0x81c960), ('?eventAdded@', 0x97abec), ('??0?$SignalDesc@VPhysicsService', 0x5e8df0), ('_atexit', 0x6a17af)]),
    ('??__E?eventRemoved@PhysicsService', 0x7f6e60, [('AssemblyRemoved', 0x83f888), ('part', 0x81c960), ('?eventRemoved@', 0x97ac20), ('??0?$SignalDesc@VPhysicsService', 0x5e8df0), ('_atexit', 0x6a17af)]),
    ('??0?$SignalDesc@VPhysicsService', 0x5e8df0, [('?classDescriptor@', 0x4cd300), ('??0SignalDescriptor@', 0x56bab0), ('??_7?$SignalDesc@', 0x83f86c), ('?declare@Name@', 0x553f90)]),
    ('?connectGeneric@?$SignalDescImpl@', 0x49de70, [('??$?0VGenericSlotWrapper@Reflection@RBX@@@shared_count@', 0x41a620)]),
    ('??$?0VGenericSlotWrapper@Reflection@RBX@@@shared_count@', 0x41a620, [('??2@YAPAXI@Z', 0x6a0920), ('__CxxThrowException@8', 0x6a158c)]),
]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs)
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
        assert any(key in k and v == value for k, v in bindings.items()), (key, bindings)
    signal_methods.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
events = []
for kind, address, handler in [('AssemblyPhysicsOn', '005e9110', 0x5e8f70), ('AssemblyPhysicsOff', '005e9130', 0x5e9040)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?onEvent@PhysicsService@RBX@@') and kind in x[0])
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (kind, len(body), len(target))
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, relocation_kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if relocation_kind == 20 and 0 <= offset < len(body) - 3:
            calls[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    assert any(k.startswith('?fromPrimitive@PartInstance@RBX@@') and v == 0x599f80 for k, v in calls.items())
    assert any(k.startswith('?onAdded@PhysicsService@RBX@@' if kind == 'AssemblyPhysicsOn' else '?onRemoved@PhysicsService@RBX@@') and v == handler for k, v in calls.items())
    events.append({'address': address, 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
remove_name, remove_body, remove_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?onRemoved@PhysicsService@RBX@@'))
remove_target, remove_targetrefs, _ = match.target('2008-06', '005e9040')
assert match.exact_match(remove_target, remove_targetrefs, remove_body, remove_refs)
remove_offset, remove_section = definitions[remove_name]
remove_table = sections[remove_section]
remove_bindings = {}
for i in range(remove_table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, remove_table[5] + 10 * i)
    offset -= remove_offset
    if 0 <= offset < len(remove_body) - 3:
        value = struct.unpack_from('<I', remove_target, offset)[0]
        if kind == 20:
            value = (0x5e9040 + offset + 4 + struct.unpack_from('<i', remove_target, offset)[0]) & 0xffffffff
        remove_bindings[symbols[index][0]] = value
for key, value in [('??$shared_from@VPartInstance@RBX@@', 0x618a40), ('?fire@?$SignalDescImpl@', 0x49d200), ('?erase@', 0x5e9f60), ('?eventRemoved@PhysicsService@RBX@@', 0x97ac20)]:
    assert any(k.startswith(key) and v == value for k, v in remove_bindings.items()), (key, remove_bindings)
added_name, added_body, added_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?onAdded@PhysicsService@RBX@@'))
added_target, added_targetrefs, _ = match.target('2008-06', '005e8f70')
assert match.exact_match(added_target, added_targetrefs, added_body, added_refs)
added_offset, added_section = definitions[added_name]
added_table = sections[added_section]
added_bindings = {}
for i in range(added_table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, added_table[5] + 10 * i)
    offset -= added_offset
    if 0 <= offset < len(added_body) - 3:
        value = struct.unpack_from('<I', added_target, offset)[0]
        if kind == 20:
            value = (0x5e8f70 + offset + 4 + struct.unpack_from('<i', added_target, offset)[0]) & 0xffffffff
        added_bindings[symbols[index][0]] = value
for key, value in [('??$shared_from@VPartInstance@RBX@@', 0x618a40), ('?fire@?$SignalDescImpl@', 0x49d200), ('?insert@', 0x5e8c40), ('?eventAdded@PhysicsService@RBX@@', 0x97abec)]:
    assert any(k.startswith(key) and v == value for k, v in added_bindings.items()), (key, added_bindings)
insert_name, insert_body, insert_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?insert@') and 'PartInstance' in x[0])
insert_target, insert_targetrefs, _ = match.target('2008-06', '005e8c40')
assert match.exact_match(insert_target, insert_targetrefs, insert_body, insert_refs)
weak_name = '??0shared_count@detail@boost@@QAE@ABVweak_count@12@@Z'
assert weak_name not in definitions
donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/PartInstance.obj'
donor_raw = donor.read_bytes()
_, weak_body, weak_refs = next(x for x in match.coff_functions(donor_raw) if x[0] == weak_name)
weak_target, weak_targetrefs, _ = match.target('2008-06', '00411ad0')
assert match.exact_match(weak_target, weak_targetrefs, weak_body, weak_refs)
function_name = '??R?$function1@XV?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@X@std@@@boost@@QBEXV?$shared_ptr@VInstance@RBX@@@1@@Z'
assert function_name not in definitions
_, function_body, function_refs = next(x for x in match.coff_functions(donor_raw) if x[0] == function_name)
function_target, function_targetrefs, _ = match.target('2008-06', '00496a00')
assert match.exact_match(function_target, function_targetrefs, function_body, function_refs)
for prefix, address, expected_prefix, expected_address in [
    ('??$shared_from@VPartInstance@RBX@@', 0x618a40, '?shared_from_this@', 0x42af90),
    ('?shared_from_this@?$enable_shared_from_this@VInstance@RBX@@', 0x42af90, '??0shared_count@detail@boost@@QAE@ABVweak_count', 0x411ad0),
]:
    method_name, method_body, method_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    method_target, method_targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(method_target, method_targetrefs, method_body, method_refs)
    start, section = definitions[method_name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(method_body) - 3:
            calls[symbols[index][0]] = (address + offset + 4 + struct.unpack_from('<i', method_target, offset)[0]) & 0xffffffff
    assert any(k.startswith(expected_prefix) and v == expected_address for k, v in calls.items()), (expected_prefix, calls)
rows = []
for prefix, address in [('??0PhysicsService@RBX@@', '004cd5b0'), ('??1PhysicsService@RBX@@', '005e8d30'), ('??$create@VPhysicsService@RBX@@@?$Creatable@VInstance@RBX@@', '004cd760')]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    expected = {'004cd5b0': [('??0?$DescribedNonCreatable@VPhysicsService@', 0x4cd510), ('?setName@Instance@RBX@@', 0x55af90)], '005e8d30': [('??1Instance@RBX@@', 0x55a540)], '004cd760': [('??0PhysicsService@RBX@@', 0x4cd5b0), ('??$?0VPhysicsService@RBX@@', 0x4cb0c0)]}[address]
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
    rows.append({'address': address, 'symbol': name, 'candidate_size': len(body), 'original_size': len(target), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
count_name, count_body, count_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$?0PAVPhysicsService@RBX@@') and 'shared_count@detail@boost@@' in x[0])
count_target, count_targetrefs, _ = match.target('2008-06', '004ca3c0')
assert match.exact_match(count_target, count_targetrefs, count_body, count_refs), (len(count_body), len(count_target))
count_offset, count_section = definitions[count_name]
count_table = sections[count_section]
count_bindings = {}
for i in range(count_table[7]):
    relocation, index, kind = struct.unpack_from('<IIH', raw, count_table[5] + 10 * i)
    relocation -= count_offset
    if 0 <= relocation < len(count_body) - 3:
        value = struct.unpack_from('<I', count_target, relocation)[0]
        if kind == 20:
            value = (0x4ca3c0 + relocation + 4 + struct.unpack_from('<i', count_target, relocation)[0]) & 0xffffffff
        count_bindings[symbols[index][0]] = value
for key, value in [('??2@YAPAXI@Z', 0x6a0920), ('??_7?$sp_counted_impl_pd@PAVPhysicsService@', 0x826830), ('??RDeleter@', 0x405e30), ('__CxxThrowException@8', 0x6a158c)]:
    assert any(k.startswith(key) and v == value for k, v in count_bindings.items()), (key, count_bindings)
name_symbol = '?sPhysicsService@RBX@@3QBDB'
offset, section = definitions[name_symbol]
name_bytes = raw[sections[section][4] + offset:][:15]
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert name_bytes == b'PhysicsService\0' == pe.get_data(0x83f858 - pe.OPTIONAL_HEADER.ImageBase, 15)
instance_symbol = '?sInstance@RBX@@3QBDB'
instance_offset, instance_section = definitions[instance_symbol]
instance_bytes = raw[sections[instance_section][4] + instance_offset:][:9]
assert instance_bytes == b'Instance\0' == pe.get_data(0x82d6a0 - pe.OPTIONAL_HEADER.ImageBase, 9)
descriptor_name, descriptor_body, descriptor_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?classDescriptor@') and 'sInstance' in x[0])
descriptor_target, descriptor_targetrefs, _ = match.target('2008-06', '0040ad80')
assert match.exact_match(descriptor_target, descriptor_targetrefs, descriptor_body, descriptor_refs)
descriptor_offset, descriptor_section = definitions[descriptor_name]
descriptor_table = sections[descriptor_section]
descriptor_bindings = {}
for i in range(descriptor_table[7]):
    relocation, index, kind = struct.unpack_from('<IIH', raw, descriptor_table[5] + 10 * i)
    relocation -= descriptor_offset
    if 0 <= relocation < len(descriptor_body) - 3:
        value = struct.unpack_from('<I', descriptor_target, relocation)[0]
        if kind == 20:
            value = (0x40ad80 + relocation + 4 + struct.unpack_from('<i', descriptor_target, relocation)[0]) & 0xffffffff
        descriptor_bindings[symbols[index][0]] = value
assert descriptor_bindings[instance_symbol] == 0x82d6a0
assert any(k.startswith('?rootDescriptor@ClassDescriptor@') and v == 0x40ad20 for k, v in descriptor_bindings.items())
rtti = '??_R0?AV?$DescribedNonCreatable@VPhysicsService@RBX@@VInstance@2@$1?sPhysicsService@2@3QBDB@RBX@@@8'
assert rtti in definitions
assert struct.unpack('<I', pe.get_data(0x83f870 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x49de70
assert b'.?AV?$DescribedNonCreatable@VPhysicsService@RBX@@VInstance@2@$1?sPhysicsService@2@3QBDB@RBX@@' in pe.__data__[:]
receipt = {'scope': 'Inactive original array-name class profile and Boost exception path match selected methods. Full base/data, event and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'unit': unit, 'methods': rows, 'shared_count': {'address': '004ca3c0', 'symbol': count_name, 'size': len(count_body), 'exact': True, 'bindings': {k: hex(v) for k, v in count_bindings.items()}}, 'name': {'symbol': name_symbol, 'original_address': '0x83f858', 'value': name_bytes.decode().rstrip('\0')}, 'instance_name': {'symbol': instance_symbol, 'original_address': '0x82d6a0', 'value': 'Instance'}, 'instance_class_descriptor': {'symbol': descriptor_name, 'address': '0040ad80', 'size': len(descriptor_body), 'exact': True, 'bindings': {k: hex(v) for k, v in descriptor_bindings.items()}}, 'rtti_symbol': rtti, 'flags': flags}
receipt['event_methods'] = events
receipt['signal_methods'] = signal_methods
receipt['on_removed'] = {'address': '005e9040', 'symbol': remove_name, 'size': len(remove_body), 'exact': True, 'bindings': {k: hex(v) for k, v in remove_bindings.items()}}
receipt['on_added'] = {'address': '005e8f70', 'symbol': added_name, 'size': len(added_body), 'exact': True, 'bindings': {k: hex(v) for k, v in added_bindings.items()}}
receipt['set_insert'] = {'address': '005e8c40', 'symbol': insert_name, 'size': len(insert_body), 'exact': True}
receipt['weak_count_donor'] = {'address': '00411ad0', 'symbol': weak_name, 'size': len(weak_body), 'exact': True, 'object_sha256': hashlib.sha256(donor_raw).hexdigest(), 'note': 'Recovered no-exception definition excluded; donor body matches. Link selection and live ABI remain unproven.'}
receipt['function1_donor'] = {'address': '00496a00', 'symbol': function_name, 'size': len(function_body), 'exact': True, 'object_sha256': hashlib.sha256(donor_raw).hexdigest(), 'note': 'Recovered no-exception definition excluded; donor body matches. Link selection and live ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/physics-array-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS array-name PhysicsService lifetime, allocation, original string and RTTI')
