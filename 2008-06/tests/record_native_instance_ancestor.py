"""Verify recovered Instance ancestry callback in inactive native profile."""
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
source = root / 'rebuild/2008-06/native-classes/InstanceAncestorChanged.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeInstanceAncestorTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I', pe.get_data(0x8318bc + 4*4 - base, 4))[0] == 0x55acc0
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
methods = []
for address, prefix, size in [('0055acc0', '?onAncestorChanged@Instance@RBX@@', 348),
                              ('0049d200', '?fire@?$SignalDescImpl@$00', 175),
                              ('00558730', '?raise@?$Notifier@VInstance@RBX@@UAncestorChanged', 138)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix) and len(x[1]) == size)
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    row = {'address': address, 'symbol': name, 'size': len(body)}
    if address == '0055acc0':
        expected = {'?read@?$CopyOnWrite@': 0x4915b0, '??$shared_from@VInstance@': 0x618a40,
                    '?event_ancestryChanged@Instance@': 0x973c38, '?fire@?$SignalDescImpl@': 0x49d200,
                    '?raise@?$Notifier@': 0x558730}
        start, index = definitions[name]
        section = sections[index]
        found, api = {}, []
        for i in range(section[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
            offset -= start
            if not 0 <= offset < len(body)-3:
                continue
            symbol = symbols[symbol][0]
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            for key, wanted in expected.items():
                if symbol.startswith(key):
                    assert value == wanted, (symbol, hex(value), hex(wanted))
                    found[key] = hex(value)
            if symbol.startswith('__imp__'):
                assert symbol.split('@')[0] == '__imp__' + imports[value]
                api.append(imports[value])
        assert set(found) == set(expected) and api == ['_invalid_parameter_noinfo'] * 4
        row.update(targets=found, imports=api, original_vtable_slot='0x8318cc')
    methods.append(row)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'methods': methods,
           'scope': 'Inactive diagnostic. Signal descriptor identity, event ABI, helper call targets and runtime ownership require further proof.'}
(root / 'work/2008-06/shared-layouts/instance-ancestor-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Instance ancestry callback and original helper bodies')
