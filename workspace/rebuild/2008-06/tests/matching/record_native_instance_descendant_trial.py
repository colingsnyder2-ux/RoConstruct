"""Record descendant callback comparison against original listener semantics."""
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
source = root / 'rebuild/2008-06/native-classes/InstanceDescendantEvents.cpp'
donor = root / 'tools/rbxgs/Client/App/include/util/Events.h'
trial = root / 'rebuild/2008-06/out/descendant-event-trial'
(trial / 'util').mkdir(parents=True, exist_ok=True)
(trial / 'reflection/signal.h').unlink(missing_ok=True)
text = donor.read_text()
needle = 'return !listeners.empty();'
assert text.count(needle) == 1
(trial / 'util/Events.h').write_text(text.replace(needle, 'return listeners.size() > 0;'))
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
common = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
rows = []
for profile in ('donor', 'size'):
    flags = list(common)
    if profile == 'size':
        flags.insert(1, '/I' + str(trial))
    obj = out / ('NativeInstanceDescendant-' + profile + '.obj')
    flags += ['/Fo' + str(obj), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
    assert code == 0, log
    raw = obj.read_bytes()
    methods = []
    for address, prefix in [('0055ae20', '?onDescendentAdded@Instance'),
                            ('0055ae90', '?onDescendentRemoving@Instance')]:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
        target, targetrefs, _ = match.target('2008-06', address)
        methods.append({'address': address, 'symbol': name, 'candidate_size': len(body),
                        'original_size': len(target), 'match': match.exact_match(target, targetrefs, body, refs)})
    rows.append({'profile': profile, 'flags': flags, 'methods': methods})
assert not any(item['match'] for row in rows for item in row['methods'] if item['address'] == '0055ae90')
# Isolate the original no-unwind calling profile; helper bodies must be checked separately.
match_trial = root / 'rebuild/2008-06/out/descendant-event-match'
(match_trial / 'util').mkdir(parents=True, exist_ok=True)
(match_trial / 'reflection').mkdir(exist_ok=True)
events = text.replace(needle, 'return listeners.size() > 0;')
events = events.replace('void raise(Event event) const\n', 'void raise(Event event) const throw()\n')
(match_trial / 'util/Events.h').write_text(events)
signal = (root / 'tools/rbxgs/Client/App/include/reflection/signal.h').read_text()
needle = 'void fire(SignalSource* source, typename const boost::function_traits<CallbackSignature>::arg1_type arg1)'
assert signal.count(needle) == 1
(match_trial / 'reflection/signal.h').write_text(signal.replace(needle, needle + ' throw()'))
flags = list(common)
flags.insert(1, '/I' + str(match_trial))
obj = out / 'NativeInstanceDescendantThrow.obj'
flags += ['/DNATIVE_DESCENDANT_REMOVE_ONLY', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
methods = []
for address, prefix, size in [('0055ae90', '?onDescendentRemoving@Instance', 241),
                              ('0049d200', '?fire@?$SignalDescImpl@$00', 175),
                              ('00558660', '?raise@?$Notifier@VInstance@RBX@@UDescendantRemoving', 202)]:
    choices = [x for x in match.coff_functions(raw) if x[0].startswith(prefix)]
    target, targetrefs, _ = match.target('2008-06', address)
    matches = [x for x in choices if match.exact_match(target, targetrefs, x[1], x[2])]
    methods.append({'address': address, 'original_size': size, 'candidate_sizes': [len(x[1]) for x in choices],
                    'match': bool(matches)})
assert methods[0]['match'] and not methods[1]['match'] and not methods[2]['match'], methods
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?onDescendentRemoving@Instance'))
target, _, _ = match.target('2008-06', '0055ae90')
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
expected = {'?event_descendentRemoving@Instance@': 0x973ca0, '?fire@?$SignalDescImpl@': 0x49d200,
            '??$shared_from@VInstance@': 0x618a40, '?raise@?$Notifier@': 0x558660}
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
                value = (0x55ae90 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x8318bc + 6*4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x55ae90
methods[0]['targets'] = found
methods[0]['original_vtable_slot'] = '0x8318d4'
rows.append({'profile': 'size-no-unwind', 'flags': flags, 'methods': methods})
add_obj = out / 'NativeInstanceDescendantAddTrial.obj'
add_flags = list(common)
add_flags.insert(1, '/I' + str(match_trial))
add_flags += ['/DNATIVE_DESCENDANT_ADD_ONLY', '/Fo' + str(add_obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', add_flags, out)
assert code == 0, log
add_raw = add_obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(add_raw) if x[0].startswith('?onDescendentAdded@Instance'))
target, targetrefs, _ = match.target('2008-06', '0055ae20')
assert match.exact_match(target, targetrefs, body, refs)
assert struct.unpack('<I', pe.get_data(0x8318bc + 5*4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x55ae20
add_sections, add_symbols, add_definitions, _ = match._coff_data_index(add_raw)
start, index = add_definitions[name]
section = add_sections[index]
expected = {'??0DescendantAdded@': 0x558910, '?raise@?$Notifier@': 0x557e80,
            '??$shared_from@VInstance@': 0x618a40, '?event_descendentAdded@Instance@': 0x973e40,
            '?fire@?$SignalDescImpl@': 0x49d200}
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', add_raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = add_symbols[symbol][0]
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (0x55ae20 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected)
ctor_name, ctor_body, ctor_refs = next(x for x in match.coff_functions(add_raw)
    if x[0].startswith('??0DescendantAdded@') and len(x[1]) == 85)
ctor_target, ctor_targetrefs, _ = match.target('2008-06', '00558910')
assert match.exact_match(ctor_target, ctor_targetrefs, ctor_body, ctor_refs)
rows.append({'profile': 'added-no-unwind', 'flags': add_flags,
             'methods': [{'address': '0055ae20', 'symbol': name, 'match': True, 'targets': found,
                          'original_vtable_slot': '0x8318d0'},
                         {'address': '00558910', 'symbol': ctor_name, 'match': True}]})
helper_source = root / 'rebuild/2008-06/tests/NativeDescendantHelpersTrial.cpp'
helper_obj = out / 'NativeDescendantHelpersTrial.obj'
helper_flags = common + ['/Fo' + str(helper_obj), str(helper_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', helper_flags, out)
assert code == 0, log
helper_raw = helper_obj.read_bytes()
helper_sections, helper_symbols, helper_definitions, _ = match._coff_data_index(helper_raw)
helper_rows = []
for address, prefix, size, expected_calls in [
        ('0049d200', '?fire@?$SignalDescImpl@$00', 175,
         [('?findSignalInstance@SignalDescriptor@', 0x56b620), ('??R?$signal1@', 0x49cd00)]),
        ('00558660', '?raise@?$Notifier@VInstance@RBX@@UDescendantRemoving', 202,
         [('?raise@?$Notifier@', 0x557c40), ('??1DescendantRemoving@', 0x422c60)]),
        ('00557e80', '?raise@?$Notifier@VInstance@RBX@@UDescendantAdded', 202,
         [('?raise@?$Notifier@', 0x557780), ('??1DescendantAdded@', 0x422c60)])]:
    name, body, refs = next(x for x in match.coff_functions(helper_raw) if x[0].startswith(prefix) and len(x[1]) == size)
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = helper_definitions[name]
    section = helper_sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', helper_raw, section[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body)-3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls.append((helper_symbols[symbol][0], value))
    assert len(calls) == len(expected_calls) and all(
        name.startswith(prefix) and value == wanted for (name, value), (prefix, wanted) in zip(calls, expected_calls))
    assert any(x[0] == name for x in match.coff_functions(raw) + match.coff_functions(add_raw)), name
    helper_rows.append({'address': address, 'symbol': name, 'size': len(body),
                        'calls': [{'symbol': n, 'target': hex(v)} for n, v in calls]})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'donor_sha256': sha(donor), 'observer_sha256': sha(Path(__file__)),
           'trial_header_sha256': sha(trial / 'util/Events.h'), 'profiles': rows,
           'helper_source_sha256': sha(helper_source), 'helper_object_sha256': sha(helper_obj),
           'helper_flags': helper_flags, 'exact_helpers': helper_rows,
           'added_object_sha256': sha(add_obj),
           'scope': 'Inactive mixed-profile trial: callback and separate helper bodies match, but COMDAT selection, target data and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/instance-descendant-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS descendant profile recorded; helpers differ, callbacks remain inactive')
