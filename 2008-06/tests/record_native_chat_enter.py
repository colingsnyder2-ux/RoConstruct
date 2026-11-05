"""Verify inactive ChatEnter constructor, keyboard handler and layout."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match

base = root / 'rebuild/2008-06'
out = base / 'out/native-chat-enter-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checker = str(base / 'tests/check_native_class.py')
checks = ['00411720=??0ChatEnter@@', '00411300=?process@ChatEnter@@', '00574150=??_GChatEnter@@']
result = subprocess.run([sys.executable, checker, 'native-classes/ChatEnter.cpp'] + checks,
                        cwd=root, env=env, text=True, capture_output=True, check=True)
assert '3/3 exact' in result.stdout, result.stdout
subprocess.run([sys.executable, checker, 'tests/NativeChatEnterLayout.cpp'],
               cwd=root, env=env, text=True, capture_output=True, check=True)
obj = (out / 'CheckChatEnter.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(obj)
name = next(n for n in definitions if n.startswith('?process@ChatEnter@@'))
start, index = definitions[name]
section = sections[index]
original, _, _ = match.target('2008-06', '00411300')
bindings = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', obj, section[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(original) - 3:
        bindings[symbols[symbol][0]] = struct.unpack_from('<I', original, offset)[0]
assert any('PostMessageA' in symbol and value == 0x802e0c for symbol, value in bindings.items())
dtor_name = next(n for n in definitions if n.startswith('??_GChatEnter@@'))
start, index = definitions[dtor_name]
section = sections[index]
dtor_original, _, _ = match.target('2008-06', '00574150')
dtor_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', obj, section[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(dtor_original) - 3 and kind == 20:
        dtor_calls[symbols[symbol][0]] = (0x574150 + offset + 4 + struct.unpack_from('<i', dtor_original, offset)[0]) & 0xffffffff
assert any(n.startswith('??1GuiItem@RBX@@') and address == 0x411540 for n, address in dtor_calls.items())
image = root / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(image), fast_load=True)
base_address = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack('<I', pe.get_data(address - base_address, 4))[0]
assert read32(0x80e0a8) == 0x411300
locator = read32(0x80e12c - 4)
descriptor = read32(locator + 12)
assert pe.get_string_at_rva(descriptor - base_address + 8) == b'.?AVChatEnter@@'
table_name = next(n for n in definitions if n.startswith('??_7ChatEnter@@6B?$GuidItem'))
table_start, table_index = definitions[table_name]
table = sections[table_index]
slots = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', obj, table[5] + 10 * i)
    offset -= table_start
    if offset >= 0:
        slots[offset // 4] = symbols[symbol][0]
assert set(slots) == set(range(25))
bodies = {name: (body, refs) for name, body, refs in match.coff_functions(obj)}
slot_checks = []
for index in range(25):
    address = read32(0x80e12c + 4 * index)
    symbol = slots[index]
    status = 'external; identity not checked'
    if symbol in bodies:
        target, refs, _ = match.target('2008-06', '%08x' % address)
        body, actual_refs = bodies[symbol]
        assert match.exact_match(target, refs, body, actual_refs), (index, symbol, hex(address))
        status = 'local body matches original slot'
    slot_checks.append({'slot': index, 'symbol': symbol, 'original': hex(address), 'status': status})
assert sum(row['status'].startswith('local') for row in slot_checks) == 11
paths = [base / 'native-headers/ChatEnter.h', base / 'native-classes/ChatEnter.cpp',
         base / 'tests/NativeChatEnterLayout.cpp', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'source_sha256': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'methods': result.stdout, 'layout': 'size 0x148; owner at 0x144',
           'event_binding': 'original GuiTarget vtable points to 00411300; PostMessageA IAT verified',
           'primary_vtable_slots': slot_checks,
           'destructor': 'Implicit destructor: deleting destructor calls original GuiItem destructor at 00411540.',
           'scope': 'Inactive checks only. Complete vtable, selected link and runtime remain unverified.'}
output = root / 'work/2008-06/native-chat-enter.json'
output.write_text(json.dumps(receipt, indent=2) + '\n')
print(result.stdout, end='')
print(output)
