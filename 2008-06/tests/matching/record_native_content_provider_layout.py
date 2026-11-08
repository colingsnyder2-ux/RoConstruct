"""Verify isolated 2008 ContentProvider service layout and lifetime."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeContentProviderTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected_vtables = [0x82df6c, 0x82df5c, 0x82df54, 0x82df4c, 0x82df3c,
                    0x82df2c, 0x82df1c, 0x82df0c, 0x82defc, 0x82deec]
methods = []
for address, prefix, expected_calls in [
    ('00562c30', '??0ContentProvider@RBX@@', [('??0?$DescribedNonCreatable@', 0x5613f0),
        ('??0mutex@boost@@', 0x594c90), ('??0?$list@UContentRequest@', 0x55e530),
        ('??0?$list@UFailedUrl@', 0x55e590), ('??0mutex@boost@@', 0x594c90),
        ('??0?$_Tree@', 0x4b0b90), ('??2@', 0x6a0920), ('??$?0V?$bind_t@', 0x55f350),
        ('??0worker_thread@', 0x5971d0), ('??1worker_thread@', 0x595cb0), ('??3@', 0x6a067a)]),
    ('00562e60', '??1ContentProvider@RBX@@', [('?join@worker_thread@', 0x595d70),
        ('??1worker_thread@', 0x595cb0), ('??3@', 0x6a067a), ('??1?$_Tree@', 0x561180),
        ('??1mutex@boost@@', 0x594cb0), ('??1?$list@UFailedUrl@', 0x55e5f0),
        ('??1?$list@UContentRequest@', 0x562bd0), ('??1mutex@boost@@', 0x594cb0), ('??1Instance@', 0x55a540)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = definitions[name]
    section = sections[index]
    calls, vtables = [], []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3:
            continue
        symbol = symbols[symbol][0]
        if kind == 20:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls.append((symbol, value))
        elif symbol.startswith('??_7ContentProvider@RBX@@'):
            vtables.append(struct.unpack_from('<I', target, offset)[0])
    assert len(calls) == len(expected_calls) and all(
        symbol.startswith(prefix) and target == wanted
        for (symbol, target), (prefix, wanted) in zip(calls, expected_calls)), (address, calls)
    assert vtables == expected_vtables, (address, vtables)
    methods.append({'address': address, 'symbol': name, 'size': len(body),
                    'calls': [{'symbol': n, 'target': hex(v)} for n, v in calls],
                    'vtable_targets': [hex(v) for v in vtables]})
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?classDescriptor@?$Described@VContentProvider'))
target, targetrefs, _ = match.target('2008-06', '005612b0')
assert match.exact_match(target, targetrefs, body, refs)
expected = {'??_B?1??classDescriptor@': 0x9740e8, '??_C@': 0x9441cc,
            '?classDescriptor@?$Described@VInstance@': 0x40ad80, '?descriptor@': 0x974028,
            '??0ClassDescriptor@': 0x5708f0, '??__Fdescriptor@': 0x7fcc00, '_atexit': 0x6a17af}
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
                value = (0x5612b0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
assert set(found) == set(expected), found
methods.append({'address': '005612b0', 'symbol': name, 'size': len(body), 'targets': found})
name, body, refs = next(x for x in match.coff_functions(raw)
    if x[0].startswith('??__Fdescriptor@?1??classDescriptor@?$Described@VContentProvider'))
target, targetrefs, _ = match.target('2008-06', '007fcc00')
assert match.exact_match(target, targetrefs, body, refs)
methods.append({'address': '007fcc00', 'symbol': name, 'size': len(body)})
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack('<I', pe.get_data(address-base, 4))[0]
locator = read32(0x82df6c-4)
assert pe.get_string_at_rva(read32(locator+12)+8-base) == b'.?AVContentProvider@RBX@@'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj),
           'flags': flags, 'class_size': '0x19c',
           'member_offsets': {'requestSync':'0x130', 'requestQueue':'0x138', 'failedUrls':'0x154',
                              'contentCacheMutex':'0x170', 'contentCache':'0x178', 'requestProcessor':'0x198'},
           'rtti': 'RBX::ContentProvider', 'methods': methods,
           'scope': 'Inactive trial. Template name representation, dependent layouts, vtable slots, exception metadata and runtime ownership remain unproven.'}
(root/'work/2008-06/shared-layouts/content-provider-layout-trial.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS ContentProvider constructor, destructor and layout trial')
