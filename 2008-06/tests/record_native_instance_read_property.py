"""Verify native Instance property reading under recovered descriptor ABI trial."""
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
source = root / 'rebuild/2008-06/native-classes/InstanceReadProperty.cpp'
trial = root / 'rebuild/2008-06/out/property-abi-trial'
header = trial / 'reflection/property.h'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
flags.insert(1, '/I' + str(trial))
obj = out / 'NativeInstanceReadPropertyTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?readProperty@Instance@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00559170')
assert match.exact_match(target, targetrefs, body, refs)
assert target[0xa6:0xa9] == bytes.fromhex('8b 52 24')  # descriptor read slot 9
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x8318bc + 11*4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x559170
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
expected = {'?name_name@@': 0x975338, '?findAttribute@XmlElement@@': 0x57c2b0,
            '?getValue@XmlNameValuePair@@': 0x57c360, '?findDescriptor@': 0x61ba10,
            '??DIterator@': 0x4174b0}
found, api = {}, []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x559170 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found[prefix] = hex(value)
    if symbol.startswith('__imp__'):
        assert symbol.split('@')[0] == '__imp__' + imports[value]
        api.append(imports[value])
assert set(found) == set(expected) and api == ['_invalid_parameter_noinfo'] * 2
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'trial_header_sha256': sha(header), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00559170', 'size': len(body),
           'vtable_slot': '0x8318e8', 'descriptor_read_slot': 9, 'targets': found, 'imports': api,
           'scope': 'Inactive mixed-ABI diagnostic. Descriptor trial is not runtime-cleared; no swap.'}
(root / 'work/2008-06/shared-layouts/instance-read-property-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original Instance property reader under descriptor trial')
