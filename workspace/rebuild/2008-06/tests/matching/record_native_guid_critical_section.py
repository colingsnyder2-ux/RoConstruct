"""Verify recovered Boost critical-section allocator and call targets."""
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
source = root / 'rebuild/2008-06/native-classes/GuidRegistryCriticalSection.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/guid-item-working-probe.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('GuidItem.cpp')]
obj = out / 'NativeGuidRegistryCriticalSection.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?newGuidRegistryCriticalSection@'))
target, targetrefs, _ = match.target('2008-06', '00594c10')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
expected = {'??2@': 0x6a0920, '??0thread_resource_error@boost@@': 0x568430,
            '__CxxThrowException@8': 0x6a158c}
direct, api, typeinfo = [], [], []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body) - 3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x594c10 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        assert any(symbol.startswith(prefix) and value == address for prefix, address in expected.items()), (symbol, value)
        direct.append([symbol, hex(value)])
    elif symbol.startswith('__imp__'):
        assert symbol.split('@')[0] == '__imp__' + imports[value]
        api.append(imports[value])
    elif symbol.startswith('__TI3?AVthread_resource_error@boost@@'):
        assert value == 0x8d4f30
        typeinfo.append(hex(value))
assert len(direct) == 5 and api == ['InitializeCriticalSection'] and len(typeinfo) == 2
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00594c10', 'size': len(body),
           'direct_calls': direct, 'imports': api, 'exception_typeinfo_addresses': typeinfo,
           'scope': 'Inactive diagnostic. Exception data identity and runtime registry ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/guid-critical-section-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Boost critical-section allocator and targets')
