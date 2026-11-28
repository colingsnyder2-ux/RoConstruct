"""Verify selected Stats string constructor, caption imports, and Sound update slot."""
import struct
import sys
from pathlib import Path

import pefile

pefile.MAX_IMPORT_SYMBOLS = 200000
root = Path(__file__).resolve().parent
tag = next((arg for arg in sys.argv[1:] if not arg.startswith('--')), '')
pe = pefile.PE(str(root / ('run/RobloxQT' + tag + '.exe')))
memory = pe.get_memory_mapped_image()
base = pe.OPTIONAL_HEADER.ImageBase
imports = {item.address: (dll.dll.decode().lower(), item.name.decode('latin1') if item.name else item.ordinal)
           for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
symbols = {}
for line in (root / ('linkexp/qt' + tag + '.map')).read_text(errors='replace').splitlines():
    fields = line.split()
    if len(fields) >= 4:
        try:
            symbols[fields[1]] = int(fields[2], 16)
        except ValueError:
            pass


def imported_call(symbol, offset, dll, name):
    address = symbols[symbol] + offset - base
    assert memory[address:address + 2] == b'\xff\x15', (symbol, offset, 'not an indirect call')
    imported = imports.get(struct.unpack_from('<I', memory, address + 2)[0])
    assert imported == (dll, name), imported
    print(f'{symbol}+{offset:#x}: {imported}')


imported_call('func_0045ebe0', 0x86, 'msvcp90.dll', '??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ')
imported_call('func_00456770', 0x70, 'msvcp90.dll', '?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEPBDXZ')
imported_call('func_00456770', 0x7d, 'mfc90.dll', 310)
constructor = symbols['??0SoundServiceStatsItem@@QAE@PBVSoundService@Soundscape@RBX@@@Z'] - base
assert memory[constructor + 0x47:constructor + 0x49] == b'\xc7\x06'
table = struct.unpack_from('<I', memory, constructor + 0x49)[0]
update = struct.unpack_from('<I', memory, table - base + 0x40)[0]
assert update == symbols['?update@SoundServiceStatsItem@@UAEXXZ'], (hex(update), hex(table))
print(f'Sound vtable {table:#x} update slot -> {update:#x}')
if '--no-workarounds' in sys.argv:
    link = (root / ('linkexp/qt' + tag + '.rsp')).read_text(errors='replace')
    for name in ('_SoundServiceStatsItem_update_noop', '_CXTPPropExchangeXMLNode_dtor_noop'):
        assert name not in link and name not in symbols, f'workaround still linked: {name}'
    print('Named no-op workarounds absent from link')
