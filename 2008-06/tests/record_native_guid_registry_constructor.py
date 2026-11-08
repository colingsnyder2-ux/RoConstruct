"""Probe GUID registry constructor; class layout remains unproven."""
import hashlib
import json
import struct
import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeGuidRegistryConstructorTrial.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/guid-item-working-probe.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('GuidItem.cpp')]
obj = out / 'NativeGuidRegistryConstructorTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0GuidRegistry@'))
target, targetrefs, _ = match.target('2008-06', '00499d60')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
expected = {'??0?$_Tree@': 0x589190, '??0GuidRegistryMutex@': 0x563070}
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind != 20 or not 0 <= offset < len(body) - 3:
        continue
    symbol = symbols[symbol][0]
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            value = (0x499d60 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected)
shared_source = root / 'rebuild/2008-06/native-classes/GuidRegistryConstructor.cpp'
shared_obj = out / 'NativeGuidRegistryConstructor.obj'
shared_flags = flags[:-2] + ['/Fo' + str(shared_obj), str(shared_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', shared_flags, out)
assert code == 0, log
shared_raw = shared_obj.read_bytes()
shared_name, shared_body, shared_refs = next(x for x in match.coff_functions(shared_raw)
                                               if x[0].startswith('??0GuidRegistry@'))
assert match.exact_match(target, targetrefs, shared_body, shared_refs)
shared_sections, shared_symbols, shared_definitions, _ = match._coff_data_index(shared_raw)
shared_start, shared_index = shared_definitions[shared_name]
shared_section = shared_sections[shared_index]
shared_calls = []
for i in range(shared_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', shared_raw, shared_section[5] + 10*i)
    offset -= shared_start
    if kind == 20 and 0 <= offset < len(shared_body) - 3:
        value = (0x499d60 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        shared_calls.append((shared_symbols[symbol][0], value))
assert len(shared_calls) == 2
assert all(any(name.startswith(prefix) and value == wanted for name, value in shared_calls)
           for prefix, wanted in expected.items())
methods = []
for address, prefix, size, expected_calls in [
        ('004ad940', '?_Eqrange@?$_Tree', 171, [('??MData@Guid@RBX@@', 0x5a8210)] * 3),
        ('004af4c0', '?erase@?$_Tree', 106, [('?_Eqrange@?$_Tree', 0x4ad940),
                                             ('??$_Distance2@', 0x4ad520), ('?erase@?$_Tree', 0x4983f0)]),
        ('004983f0', '?erase@?$_Tree', 220, [('?_Erase@?$_Tree', 0x4970e0),
                                             ('?_Inc@const_iterator@', 0x5b7250), ('?erase@?$_Tree', 0x497b00)])]:
    name, candidate, candidate_refs = next(x for x in match.coff_functions(raw)
                                            if x[0].startswith(prefix) and len(x[1]) == size)
    original, original_refs, _ = match.target('2008-06', address)
    assert match.exact_match(original, original_refs, candidate, candidate_refs), address
    start, index = definitions[name]
    section = sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(candidate) - 3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', original, offset)[0]) & 0xffffffff
            calls.append((symbols[symbol][0], value))
    assert len(calls) == len(expected_calls)
    assert all(name.startswith(prefix) and target == wanted
               for (name, target), (prefix, wanted) in zip(calls, expected_calls)), (address, calls)
    methods.append({'address': address, 'size': size, 'symbol': name,
                    'calls': [{'symbol': n, 'target': hex(v)} for n, v in calls]})
register, _, _ = match.target('2008-06', '0049bba0')
instructions = {i.address: (i.mnemonic, i.op_str) for i in
                Cs(CS_ARCH_X86, CS_MODE_32).disasm(register, 0x49bba0)}
assert instructions[0x49bbb9] == ('mov', 'esi, ecx')
assert instructions[0x49bbe0] == ('mov', 'edi, dword ptr [0x9705e8]')
assert instructions[0x49bc0b] == ('call', '0x4991d0')
assert instructions[0x49bc12] == ('mov', 'dword ptr [eax], esi')
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00499d60',
           'size': len(body), 'class_size': 44, 'targets': found, 'container_methods': methods,
           'shared_source_sha256': sha(shared_source), 'shared_object_sha256': sha(shared_obj),
           'shared_header_sha256': sha(root / 'rebuild/2008-06/native-headers/util/GuidRegistry.h'),
           'register_store': {'address': '0049bc12', 'value': 'original GuidItem this pointer',
                              'registry_global': '009705e8'},
           'scope': 'Inactive conflicting layout trial; mapped value stores the GuidItem this pointer, but destructor and runtime ownership remain unproven. Never link or run.'}
(root / 'work/2008-06/shared-layouts/guid-registry-constructor-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS registry constructor trial; layout remains unproven')
