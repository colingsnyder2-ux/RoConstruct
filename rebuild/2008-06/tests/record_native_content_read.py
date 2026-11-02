"""Verify the native content callback's main body and direct call target."""
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
source = root / 'rebuild/2008-06/tests/NativeContentReadTrial.cpp'
layout = root / 'rebuild/2008-06/tests/NativeContentProviderTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeContentReadTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?readContent@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0055dc80')
assert match.exact_match(target, targetrefs, body[:len(target)], [r for r in refs if r < len(target)])
catch_target, catch_refs, _ = match.target('2008-06', '0055dd60')
catch_body = body[len(target):]
assert match.exact_match(catch_target, catch_refs, catch_body, [r-len(target) for r in refs if r >= len(target)])
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(target) - 3:
        value = (0x55dc80 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        calls[symbols[symbol][0]] = value
assert len(calls) == 1 and next(iter(calls.values())) == 0x5aae30, calls
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image_base = pe.OPTIONAL_HEADER.ImageBase
read = lambda addr, size: pe.get_data(addr-image_base, size)
handler = struct.unpack('<I', target[6:10])[0]
assert handler == 0x7ce8d4 and read(handler, 1) == b'\xb8'
info = struct.unpack('<I', read(handler+1, 4))[0]
magic, max_state, unwind, count, trymap = struct.unpack('<5I', read(info, 20))
assert (magic, max_state, count) == (0x19930522, 6, 1)
low, high, catch_high, catches, catchmap = struct.unpack('<5I', read(trymap, 20))
assert (low, high, catch_high, catches) == (2, 3, 5, 1)
attrs, exception_type, displacement, catch_address = struct.unpack('<4I', read(catchmap, 16))
assert (attrs, displacement, catch_address) == (8, 0xffffffe4, 0x55dd60)
assert pe.get_string_at_rva(exception_type-image_base+8) == b'.?AVexception@std@@'
catch_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start + len(target)
    if 0 <= offset < len(catch_target)-3:
        name_at_ref = symbols[symbol][0]
        value = struct.unpack_from('<I', catch_target, offset)[0]
        if kind == 20:
            value = (0x55dd60 + offset + 4 + struct.unpack_from('<i', catch_target, offset)[0]) & 0xffffffff
        catch_calls[name_at_ref] = value
assert any(k.startswith('?singleton@StandardOut@') and v == 0x569620 for k,v in catch_calls.items())
assert any(k.startswith('?print@StandardOut@') and v == 0x5693a0 for k,v in catch_calls.items())
assert 0x600660 in catch_calls.values() and 0x55dcf1 in catch_calls.values()
assert pe.get_string_at_rva(0x82dd04-image_base) == b'ContentProvider callback exception: %s'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '0055dc80', 'size': len(target),
           'direct_calls': {k: hex(v) for k, v in calls.items()},
           'catch': {'address': hex(catch_address), 'size': len(catch_target), 'exception_type': hex(exception_type),
                     'original_handler': hex(handler), 'targets': {k: hex(v) for k, v in catch_calls.items()}},
           'scope': 'Inactive trial. Main body, catch and original EH metadata checked; linked EH metadata and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/content-read-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider readContent body, catch and original exception metadata')
