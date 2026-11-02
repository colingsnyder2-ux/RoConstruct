"""Verify native world service creation against original specializations."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorldServiceFactoriesTrial.cpp'
find_trial = '--find-trial' in sys.argv
allocation_trial = '--allocation-trial' in sys.argv
lifetime_trial = '--lifetime-trial' in sys.argv
event_trial = '--event-trial' in sys.argv
action_trial = '--action-trial' in sys.argv
secure_trial = '--secure-trial' in sys.argv
remove_only = '--remove-only' in sys.argv
joints_find = '--joints-find-trial' in sys.argv
assert not secure_trial or action_trial
assert not remove_only or action_trial
assert not (find_trial and (allocation_trial or lifetime_trial or event_trial or action_trial or joints_find))
obj = out / ('NativeWorldServiceFindTrial.obj' if find_trial else 'NativeWorldServiceJointFindTrial.obj' if joints_find else 'NativeWorldServiceCompleteTrial.obj' if remove_only and event_trial and allocation_trial and lifetime_trial else 'NativeWorldServiceActionsSecureTrial.obj' if secure_trial else 'NativeWorldServiceActionsTrial.obj' if action_trial else 'NativeWorldServiceAllTrial.obj' if event_trial and allocation_trial and lifetime_trial else 'NativeWorldServiceEventTrial.obj' if event_trial else 'NativeWorldServiceFullTrial.obj' if allocation_trial and lifetime_trial else 'NativeWorldServiceAllocationTrial.obj' if allocation_trial else 'NativeWorldServiceLifetimeTrial.obj' if lifetime_trial else 'NativeWorldServiceFactoriesTrial.obj')
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
if find_trial:
    flags.append('/DWORLD_FIND_PROFILE')
if joints_find:
    flags.append('/DWORLD_JOINTS_FIND_PROFILE')
if allocation_trial:
    flags.append('/DWORLD_ALLOCATION_PROFILE')
if lifetime_trial:
    flags.append('/DWORLD_LIFETIME_PROFILE')
if event_trial:
    flags.append('/DWORLD_EVENT_PROFILE')
if action_trial:
    flags.append('/DWORLD_ACTION_PROFILE')
if secure_trial:
    flags.append('/D_SECURE_SCL=1')
if remove_only:
    flags.append('/DWORLD_EXCLUDE_ADDED')
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for cls, address, find_addr, create_addr, index_addr in [('JointsService', '004b3a50', 0x4b34c0, 0x4b0df0, 0x4ab4d0), ('PhysicsService', '004cd7e0', 0x4ccca0, 0x4cd760, 0x4c9be0)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$create@V' + cls + '@RBX@@@ServiceProvider'))
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
    expected = [('??$find@V' + cls, find_addr), ('??$create@V' + cls + '@RBX@@@?$Creatable', create_addr), ('??$doGetClassIndex@V' + cls, index_addr), ('?setParent@Instance@RBX@@', 0x55a8f0)]
    for prefix, value in expected:
        assert any(k.startswith(prefix) and v == value for k, v in calls.items()), (cls, prefix, calls)
    rows.append({'class': cls, 'address': address, 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
receipt = {'scope': 'Inactive typed service factories match; class layouts, cache/once identity, constructors and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'flags': flags}
if find_trial or joints_find:
    receipt['scope'] = 'Inactive JointsService null-name specialization matches; PhysicsService find remains unproven; class metadata and runtime ABI remain unproven.'
    receipt['find_methods'] = []
    for cls, address in ([('JointsService', '004b34c0')] if joints_find else [('JointsService', '004b34c0'), ('PhysicsService', '004ccca0')]):
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$find@V' + cls + '@RBX@@@ServiceProvider'))
        target, targetrefs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, targetrefs, body, refs)
        assert exact == (cls == 'JointsService')
        if exact:
            start, section = definitions[name]
            table = sections[section]
            calls = {}
            for i in range(table[7]):
                offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
                offset -= start
                if kind == 20 and 0 <= offset < len(body) - 3:
                    calls[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            for key, value in [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VJointsService@', 0x4ab4d0), ('?resize@?$vector@', 0x4124c0)]:
                assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
        receipt['find_methods'].append({'class': cls, 'address': address, 'candidate_size': len(body), 'original_size': len(target), 'exact': exact})
if allocation_trial:
    prefix = '??$create@VPhysicsService@RBX@@@?$Creatable@VInstance@RBX@@'
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '004cd760')
    exact = match.exact_match(target, targetrefs, body, refs)
    assert exact and bytes.fromhex('6858010000') in body
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[symbols[index][0]] = (0x4cd760 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for key, value in [('??0PhysicsService@RBX@@', 0x4cd5b0), ('??$?0VPhysicsService@RBX@@', 0x4cb0c0)]:
        assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
    receipt['allocation'] = {'address': '004cd760', 'symbol': name, 'candidate_size': len(body), 'original_size': len(target), 'exact': exact, 'allocation_size': '0x158', 'calls': {k: hex(v) for k, v in calls.items()}}
    print('PhysicsService allocation:', receipt['allocation'])
if lifetime_trial:
    receipt['lifetime'] = []
    for prefix, address in [('??0PhysicsService@RBX@@', '004cd5b0'), ('??1PhysicsService@RBX@@', '005e8d30')]:
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
        expected = [('?setName@Instance@RBX@@', 0x55af90)] if address == '004cd5b0' else [('??1Instance@RBX@@', 0x55a540)]
        for key, value in expected:
            assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
        receipt['lifetime'].append({'address': address, 'symbol': name, 'candidate_size': len(body), 'original_size': len(target), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
    print('PhysicsService lifetime:', receipt['lifetime'])
if event_trial:
    receipt['events'] = []
    pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
    image = pe.OPTIONAL_HEADER.ImageBase
    for kind, address, method, method_address in [('AssemblyPhysicsOn', '005e9110', '?onAdded@PhysicsService@RBX@@', 0x5e8f70), ('AssemblyPhysicsOff', '005e9130', '?onRemoved@PhysicsService@RBX@@', 0x5e9040)]:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?onEvent@PhysicsService@RBX@@') and kind in x[0])
        target, targetrefs, _ = match.target('2008-06', address)
        assert match.exact_match(target, targetrefs, body, refs)
        vtable = 0x826a24 if kind == 'AssemblyPhysicsOn' else 0x826a18
        assert struct.unpack('<I', pe.get_data(vtable - image, 4))[0] == int(address, 16)
        start, section = definitions[name]
        table = sections[section]
        calls = {}
        for i in range(table[7]):
            offset, index, relocation_kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if relocation_kind == 20 and 0 <= offset < len(body) - 3:
                calls[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        for key, value in [('?fromPrimitive@PartInstance@RBX@@', 0x599f80), (method, method_address)]:
            assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
        receipt['events'].append({'event': kind, 'address': address, 'symbol': name, 'size': len(body), 'original_size': len(target), 'exact': True, 'vtable': hex(vtable), 'calls': {k: hex(v) for k, v in calls.items()}})
    donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/PartInstance.obj'
    donor_name, donor_body, donor_refs = next(x for x in match.coff_functions(donor.read_bytes()) if x[0].startswith('?fromPrimitive@PartInstance@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', '00599f80')
    receipt['donor_from_primitive'] = {'symbol': donor_name, 'address': '00599f80', 'candidate_size': len(donor_body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, donor_body, donor_refs), 'object_sha256': hashlib.sha256(donor.read_bytes()).hexdigest()}
    print('PhysicsService events:', receipt['events'])
if action_trial:
    receipt['actions'] = []
    for method, address in ([('onRemoved', '005e9040')] if remove_only else [('onAdded', '005e8f70'), ('onRemoved', '005e9040')]):
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + method + '@PhysicsService@RBX@@'))
        target, targetrefs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, targetrefs, body, refs)
        if remove_only:
            assert exact
            start, section = definitions[name]
            table = sections[section]
            calls = {}
            bindings = {}
            for i in range(table[7]):
                offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
                offset -= start
                if 0 <= offset < len(body) - 3:
                    value = struct.unpack_from('<I', target, offset)[0]
                    if kind == 20:
                        value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                        calls[symbols[index][0]] = value
                    bindings[symbols[index][0]] = value
            for key, value in [('??$shared_from@VPartInstance@RBX@@', 0x618a40), ('?fire@?$SignalDescImpl@', 0x49d200), ('?erase@', 0x5e9f60)]:
                assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
            assert any('eventRemoved' in k and v == 0x97ac20 for k, v in bindings.items()), bindings
        receipt['actions'].append({'method': method, 'address': address, 'symbol': name, 'size': len(body), 'original_size': len(target), 'exact': exact})
    print('PhysicsService actions:', receipt['actions'])
    if not remove_only:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?insert@') and 'PartInstance' in x[0])
        target, targetrefs, _ = match.target('2008-06', '005e8c40')
        assert match.exact_match(target, targetrefs, body, refs)
        receipt['set_insert'] = {'address': '005e8c40', 'symbol': name, 'size': len(body), 'exact': True}
        receipt['scope'] = 'Inactive action candidates: onRemoved and set insertion match; onAdded differs and is excluded from diagnostic. Signal/data identity, class layouts and runtime remain unproven.'
filename = 'world-service-find-mismatch.json' if find_trial else 'world-service-joints-find-trial.json' if joints_find else 'world-service-complete-trial.json' if remove_only and event_trial and allocation_trial and lifetime_trial else 'world-service-actions-secure-trial.json' if secure_trial else 'world-service-actions-trial.json' if action_trial else 'world-service-all-trial.json' if event_trial and allocation_trial and lifetime_trial else 'world-service-event-trial.json' if event_trial else 'world-service-full-trial.json' if allocation_trial and lifetime_trial else 'world-service-allocation-trial.json' if allocation_trial else 'world-service-lifetime-trial.json' if lifetime_trial else 'world-service-factories-trial.json'
(root / 'work/2008-06/shared-layouts' / filename).write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native service factory checks; find trial:', find_trial)
