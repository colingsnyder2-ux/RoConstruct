"""Verify the native content callback's main body and direct call target."""
import argparse
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
source = root / 'rebuild/2008-06/native-classes/ContentRead.cpp'
layout = root / 'rebuild/2008-06/native-headers/util/ContentRequest.h'
from native_check_runner import compiler_flags
flags = compiler_flags(source)
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--obj', type=Path, help='audit an existing object without compiling')
parser.add_argument('--output', type=Path, default=root / 'work/2008-06/shared-layouts/content-read-native.json')
args = parser.parse_args()
obj = args.obj.resolve() if args.obj else out / 'NativeContentRead.obj'
if not args.obj:
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
data_spans, data_mismatches = match.data_check('2008-06', '0055dc80', target + catch_target,
                                             match.coff_data_refs(raw, name))
assert not data_mismatches, data_mismatches
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

def native_table(prefix, size):
    name = next(name for name in definitions if name.startswith(prefix + '$?readContent@'))
    offset, index = definitions[name]
    return raw[sections[index][4] + offset:sections[index][4] + offset + size]

native_info = struct.unpack('<5I', native_table('__ehfuncinfo', 20))
native_try = struct.unpack('<5I', native_table('__tryblocktable', 20))
native_catch = struct.unpack('<4I', native_table('__catchsym', 16))
assert (native_info[0], native_info[1], native_info[3]) == (magic, max_state, count)
assert native_try[:4] == (low, high, catch_high, catches)
assert (native_catch[0], native_catch[2]) == (attrs, displacement)
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
           'object_sha256': sha(obj), 'object': str(obj), 'compiled_here': not bool(args.obj),
           'flags': flags if not args.obj else None, 'address': '0055dc80', 'size': len(target),
           'direct_calls': {k: hex(v) for k, v in calls.items()},
           'catch': {'address': hex(catch_address), 'size': len(catch_target), 'exception_type': hex(exception_type),
                     'original_handler': hex(handler), 'targets': {k: hex(v) for k, v in catch_calls.items()}},
           'native_eh': {'max_state': native_info[1], 'try_blocks': native_info[3],
                         'try_states': list(native_try[:4]), 'catch_displacement': hex(native_catch[2])},
           'referenced_data': data_spans,
           'scope': 'Native source diagnostic. Main body, catch and original EH metadata checked; linked EH metadata and runtime ABI remain unproven.'}
args.output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider readContent body, catch and original exception metadata')
