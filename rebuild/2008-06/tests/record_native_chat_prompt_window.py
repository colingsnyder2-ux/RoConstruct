"""Record inactive chat-window matches; this is not a runtime swap test."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import pefile

root = Path(__file__).resolve().parents[3]
base = root / 'rebuild/2008-06'
sys.path.insert(0, str(root))
from roc import match
checks = {
    '004115c0': '?OnSetFocusReflect@CChatPrompt@@',
    '00411370': '?PreCreateWindow@CChatPrompt@@',
    '004113a0': '?CtlColor@CChatPrompt@@',
    '004120a0': '?GetMessageMap@CChatPrompt@@',
    '0047d410': '?OnChange@CChatPrompt@@',
    '00702d70': '?OnSysChar@CChatPrompt@@',
    '0045aeb0': '?OnFocusMessage@CChatPrompt@@',
}
cmd = [sys.executable, str(base / 'tests/check_native_class.py'),
       'native-classes/CChatPromptWindow.cpp']
cmd += [address + '=' + name for address, name in checks.items()]
out = base / 'out/native-chat-prompt-window'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
result = subprocess.run(cmd, cwd=root, text=True, capture_output=True, check=True, env=env)
assert '7/7 exact' in result.stdout, result.stdout + result.stderr
obj = (out / 'CheckCChatPromptWindow.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(obj)
char_name, char_body, char_refs = next(x for x in match.coff_functions(obj)
                                        if x[0].startswith('?OnChar@CChatPrompt@@'))
first, first_refs, _ = match.target('2008-06', '00411c30')
tail, tail_refs, _ = match.target('2008-06', '00411d55')
original_char = first + tail
original_refs = list(first_refs) + [len(first) + x for x in tail_refs]
assert len(first) == 293 and len(tail) == 55 and len(char_body) == 348
assert match.exact_match(original_char, original_refs, char_body, char_refs)
start, index = definitions[char_name]
char_section = sections[index]
char_bindings = {}
for i in range(char_section[7]):
    position, symbol, kind = struct.unpack_from('<IIH', obj, char_section[5] + 10 * i)
    position -= start
    if not 0 <= position < len(original_char) - 3:
        continue
    value = struct.unpack_from('<I', original_char, position)[0]
    if kind == 20:
        value = (0x411c30 + position + 4 + struct.unpack_from('<i', original_char, position)[0]) & 0xffffffff
    char_bindings.setdefault(symbols[symbol][0], set()).add(value)
for prefix, address in [('?chat@Players@Network@RBX@@', 0x49cb30),
                        ('??0Lock@DataModel@RBX@@', 0x411b40),
                        ('??1Lock@DataModel@RBX@@', 0x5773c0),
                        ('?chatPromptText@@', 0x92b780),
                        ('?SetFocus@CWnd@@', 0x6a0a28)]:
    assert any(n.startswith(prefix) and address in values for n, values in char_bindings.items()), prefix
name = next(n for n in definitions if n.startswith('?_messageEntries@?1??GetThisMessageMap@CChatPrompt'))
offset, section_index = definitions[name]
section = sections[section_index]
native = bytearray(obj[section[4] + offset:section[4] + offset + 192])
image = root / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(image), fast_load=True)
original = bytearray(pe.get_data(0x80e360 - pe.OPTIONAL_HEADER.ImageBase, 192))
addresses = [0x47d410, 0x411c30, 0x702d70, 0x45aeb0, 0x4115c0, 0x411640, 0x4113a0]
handlers = ['OnChange', 'OnChar', 'OnSysChar', 'OnFocusMessage', 'OnSetFocusReflect', 'OnCreate', 'CtlColor']
relocations = {}
for i in range(section[7]):
    position, symbol, kind = struct.unpack_from('<IIH', obj, section[5] + 10 * i)
    relocations[position - offset] = symbols[symbol][0]
for i, (address, handler) in enumerate(zip(addresses, handlers)):
    pos = i * 24 + 20
    assert struct.unpack_from('<I', original, pos)[0] == address
    assert relocations[pos].startswith('?' + handler + '@CChatPrompt@@')
    original[pos:pos + 4] = native[pos:pos + 4] = b'\0' * 4
assert native == original
read = lambda address, size: pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, size)
words = lambda address, count: struct.unpack('<' + 'I' * count, read(address, count * 4))
assert read(0x7bd751, 1) == b'\xb8'
info = words(0x7bd752, 1)[0]
magic, states, unwind, count, tries = words(info, 5)
assert magic == 0x19930522 and count == 1
low, high, catch_high, catches, entries = words(tries, 5)
attrs, descriptor, displacement, catch_body = words(entries, 4)
assert (catches, attrs, catch_body) == (1, 8, 0x411d55)
assert pe.get_string_at_rva(descriptor - pe.OPTIONAL_HEADER.ImageBase + 8) == b'.?AVexception@std@@'
paths = [base / 'native-headers/CChatPrompt.h', base / 'native-classes/CChatPromptWindow.cpp',
         base / 'tests/check_native_class.py', Path(__file__)]
receipt = {
    'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
    'sha256': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
    'compiler': 'MSVC 21022', 'output': result.stdout,
    'message_map': 'All entries and handler relocations match original identities; base getter not checked.',
    'on_char': 'Full 348-byte split body exact; key call and global bindings verified.',
    'on_char_exception': 'Original MSVC exception metadata identifies catch(const std::exception&).',
    'scope': 'Inactive relocation-normalized body checks and selected bindings only. Other call identity, OnCreate, selection and runtime remain unverified.',
}
output = root / 'work/2008-06/native-chat-prompt-window.json'
output.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print(result.stdout, end='')
print(output)
