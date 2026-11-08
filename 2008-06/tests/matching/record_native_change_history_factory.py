"""Verify inactive native ChangeHistoryService factory constructor chain."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/ChangeHistoryFactory.cpp'
header = root / 'rebuild/2008-06/native-headers/util/Object.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeChangeHistoryFactory.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
methods = []
for address, prefix, expected in [
        ('0058a8d0', '??$?0PBD@?$DescribedCreatable@VChangeHistoryService',
         [('??$?0PBD@?$FactoryProduct@VChangeHistoryService', 0x5871d0), ('?classDescriptor@', 0x58a2a0)]),
        ('005871d0', '??$?0PBD@?$FactoryProduct@VChangeHistoryService',
         [('??0Instance@RBX@@QAE@PBD', 0x55b960)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = definitions[name]
    section = sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body)-3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls.append((symbols[symbol][0], value))
    assert len(calls) == len(expected)
    assert all(name.startswith(prefix) and value == wanted
               for (name, value), (prefix, wanted) in zip(calls, expected)), (address, calls)
    methods.append({'address': address, 'symbol': name, 'size': len(body),
                    'calls': [{'symbol': n, 'target': hex(v)} for n, v in calls]})
name, body, refs = next(x for x in match.coff_functions(raw)
                        if x[0].startswith('?classDescriptor@?$Described@VChangeHistoryService'))
target, targetrefs, _ = match.target('2008-06', '0058a2a0')
assert match.exact_match(target, targetrefs, body, refs)
expected = {'??_C@': 0x948df8, '?classDescriptor@?$Described@VInstance@': 0x40ad80,
            '?descriptor@': 0x975928, '??0ClassDescriptor@': 0x5708f0,
            '??__Fdescriptor@': 0x7fd930, '_atexit': 0x6a17af, '??_B?1??classDescriptor@': 0x9759e8}
start, index = definitions[name]
section = sections[index]
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
                value = (0x58a2a0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected), found
methods.append({'address': '0058a2a0', 'symbol': name, 'size': len(body), 'targets': found})
name, body, refs = next(x for x in match.coff_functions(raw)
                        if x[0].startswith('??__Fdescriptor@?1??classDescriptor@?$Described@VChangeHistoryService'))
target, targetrefs, _ = match.target('2008-06', '007fd930')
assert match.exact_match(target, targetrefs, body, refs)
methods.append({'address': '007fd930', 'symbol': name, 'size': len(body)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'header_sha256': sha(header), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'methods': methods,
           'scope': 'Inactive diagnostic. Constructor bodies and direct calls match; vtable and descriptor identities and factory destructor remain unproven.'}
(root / 'work/2008-06/shared-layouts/change-history-factory-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ChangeHistoryService factory constructor chain')
