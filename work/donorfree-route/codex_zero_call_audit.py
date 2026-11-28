"""Verify three original direct calls do not resolve to address zero."""
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parent
tag = sys.argv[1] if len(sys.argv) > 1 else ''
image = pefile.PE(str(root / ('run/RobloxQT' + tag + '.exe')), fast_load=True)
memory = image.get_memory_mapped_image()
checks = {
    'func_0055fa70': (0x21, 'cache path'),
    'func_00562a30': (0xbb, 'cache path'),
    '?execute@?$TGenericSlotWrapper@VWaitScriptSlot@@@Reflection@RBX@@UAEXABV?$vector@Vany@boost@@V?$allocator@Vany@boost@@@std@@@std@@@Z': (0x49, 'Lua argument helper'),
}
found = {}
for line in (root / ('linkexp/qt' + tag + '.map')).read_text(errors='replace').splitlines():
    fields = line.split()
    if len(fields) >= 4 and fields[1] in checks:
        found[fields[1]] = int(fields[2], 16)

errors = 0
for name, (offset, description) in checks.items():
    address = found.get(name)
    if address is None:
        print(f'{description}: caller missing ({name})')
        errors += 1
        continue
    position = address + offset - image.OPTIONAL_HEADER.ImageBase
    if memory[position] != 0xe8:
        print(f'{description}: call layout changed at {address + offset:#x}')
        errors += 1
        continue
    target = (address + offset + 5 + struct.unpack_from('<i', memory, position + 1)[0]) & 0xffffffff
    print(f'{description}: call {address + offset:#x} -> {target:#x}')
    errors += target == 0
raise SystemExit(bool(errors))
