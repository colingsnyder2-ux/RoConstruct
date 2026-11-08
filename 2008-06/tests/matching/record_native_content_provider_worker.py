"""Verify original ContentProvider queued request worker in isolated native layout."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/experiments/trials/NativeContentProviderWorkerTrial.cpp'
layout = root/'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out/'NativeContentProviderWorkerTrial.obj'
flags += ['/Fo'+str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?processRequests@ContentProvider@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005620f0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
expected = {'??0ContentRequest@': 0x560fa0, '??1ContentRequest@': 0x561020,
            '?do_lock@mutex@': 0x594ce0, '?do_unlock@mutex@': 0x594d00,
            '??0Http@': 0x41d4b0, '?get@Http@': 0x569ae0, '??1Http@': 0x5df620,
            '??0FailedUrl@': 0x55f710, '?push_front@?$list@UFailedUrl@': 0x55e650,
            '?singleton@StandardOut@': 0x569620, '?print@StandardOut@': 0x5693a0,
            '??$for_each@': 0x55ead0, '?erase@?$list@UContentRequest@': 0x5617c0,
            '?readContent@RBX@@': 0x55dc80, '??_C@': 0x82deb8}
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
        value = (0x5620f0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
    if symbol.startswith('__imp_'):
        assert imports[value] in (symbol[6:], symbol[7:]), (symbol, imports.get(value))
        api.append(imports[value])
assert set(found) == set(expected), found
assert pe.get_string_at_rva(0x82deb8-pe.OPTIONAL_HEADER.ImageBase) == b'Content failed for %s because %s'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '005620f0', 'size': len(body),
           'targets': found, 'imports': api,
           'scope': 'Inactive trial. Queue element types and selected calls verified; callback, cache, exception metadata and runtime ownership remain unproven.'}
(root/'work/2008-06/shared-layouts/content-provider-worker-trial.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS ContentProvider request worker and selected targets')
