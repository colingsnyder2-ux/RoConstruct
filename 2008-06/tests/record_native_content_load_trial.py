"""Verify ContentProvider::loadContent in an isolated native layout."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeContentLoadTrial.cpp'
layout = root / 'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeContentLoadTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?loadContent@ContentProvider@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00561980')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'?isAsset@ContentId@RBX@@': 0x55bae0, '?nativeFindAsset@RBX@@': 0x560460,
            '?nativeFindHashFile@RBX@@': 0x55fdc0, '?isHttp@ContentId@RBX@@': 0x55bb50,
            '?isUrlBad@ContentProvider@RBX@@': 0x55f7b0, '?wake@worker_thread@RBX@@': 0x595de0,
            '?do_lock@mutex@boost@@': 0x594ce0, '?do_unlock@mutex@boost@@': 0x594d00,
            '?get@Http@RBX@@': 0x569ae0, '??0FailedUrl@ContentProvider@RBX@@': 0x55f710}
start, index = definitions[name]
section = sections[index]
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x561980 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected), found
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00561980', 'size': len(body), 'targets': found,
           'scope': 'Inactive trial. Asset lookup helpers, container ABI, exception metadata and ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/content-load-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider loadContent and selected targets')
