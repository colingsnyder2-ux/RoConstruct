"""Find linked stubs that replace direct import thunks in the original client."""
import re
import struct
import sys
from pathlib import Path

import pefile

pefile.MAX_IMPORT_SYMBOLS = 200000
root = Path(__file__).resolve().parent
tag = sys.argv[1] if len(sys.argv) > 1 else ''
linked = pefile.PE(str(root / ('run/RobloxQT' + tag + '.exe')), fast_load=True)
linked.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
linked_image = linked.get_memory_mapped_image()
linked_imports = {
    item.address: (dll.dll.decode().lower(), item.name.decode('latin-1') if item.name else '#' + str(item.ordinal))
    for dll in linked.DIRECTORY_ENTRY_IMPORT for item in dll.imports
}
original = pefile.PE(str(root.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
original.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
image = original.get_memory_mapped_image()
imports = {
    item.address: (dll.dll.decode(), item.name.decode('latin-1') if item.name else '#' + str(item.ordinal))
    for dll in original.DIRECTORY_ENTRY_IMPORT for item in dll.imports
}
bad = []
lines = (root / ('linkexp/qt' + tag + '.map')).read_text(errors='replace').splitlines()
update = None
for line in lines:
    fields = line.split()
    if len(fields) >= 4 and fields[1] == '?update@SoundServiceStatsItem@@UAEXXZ':
        update = int(fields[2], 16)
    if len(fields) < 4 or 'stubs' not in fields[-1]:
        continue
    match = re.fullmatch(r'func_([0-9a-f]{8})', fields[1])
    if not match:
        continue
    offset = int(match[1], 16) - original.OPTIONAL_HEADER.ImageBase
    code = image[offset:offset + 6]
    if code[:2] == b'\xff\x25':
        target = imports.get(struct.unpack_from('<I', code, 2)[0])
        if target:
            bad.append((fields[1], *target))

for name, dll, symbol in bad:
    print(f'{name}: {dll}!{symbol} replaced by stub')
if update is None:
    raise SystemExit('SoundServiceStatsItem::update missing from map')
call = update - linked.OPTIONAL_HEADER.ImageBase + 0x65
if linked_image[call] != 0xe8:
    raise SystemExit('SoundServiceStatsItem::update call layout changed')
target = update + 0x65 + 5 + struct.unpack_from('<i', linked_image, call + 1)[0]
offset = target - linked.OPTIONAL_HEADER.ImageBase
code = linked_image[offset:offset + 6]
actual = linked_imports.get(struct.unpack_from('<I', code, 2)[0]) if code[:2] == b'\xff\x25' else None
if actual != ('fmodex.dll', 'FMOD_Memory_GetStats'):
    print(f'SoundServiceStatsItem::update calls {target:#x}, import={actual!r}')
    bad.append(('update call', 'fmodex.dll', 'FMOD_Memory_GetStats'))
print(f'{len(bad)} stubbed import thunks')
raise SystemExit(bool(bad))
