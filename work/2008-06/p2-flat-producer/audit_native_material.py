"""Audit compiled virtual tables independently of the C++ header dispatch tests."""
import json
from pathlib import Path
import re
import struct
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match


def audit():
    test = ROOT / 'rebuild/2008-06/out/tests/P2NativeMaterialTest/P2NativeMaterialTest'
    symbols = {}
    by_address = {}
    for line in test.with_suffix('.map').read_text().splitlines():
        found = re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\b', line)
        if found:
            name, address = found.group(1), int(found.group(2), 16)
            symbols[name] = address
            by_address.setdefault(address, []).append(name)
    pe = pefile.PE(str(test.with_suffix('.exe')))
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    target_base, target_image = match._image('2008-06')
    # Order is read from original tables; names are checked against compiled maps.
    tables = [
        ('Material', 0x874ac0, ['??_GMaterial@', '?appendEmptyLevel@', '?appendLevel@', '?appendLevel@', '?levelCount@', '?getLevel@', '?detailLevel@', '?veryTransparent@']),
        ('Level@Material', 0x874ae4, ['?isEmptyLevel@', '??_GLevel@', '?baseTexture@', '?baseTexture@', '?setBaseTexture@', '?matte@', '?color@', '?specular@', '?shiny@', '?reflect@', '?transparent@']),
        ('TextureProxyBase', 0x82d168, ['??_GTextureProxyBase@', '?setValue28@', '?getValue28@', '?setValue2c@', '?getValue2c@', '__purecall', '__purecall', '__purecall']),
        ('TextureProxy', 0x82d18c, ['??_GTextureProxy@', '?setValue28@', '?getValue28@', '?setValue2c@', '?getValue2c@', '?getSize@', '?resolve@', '?shade@']),
        ('MegaTextureProxy', 0x874bd8, ['??_GMegaTextureProxy@', '?setValue28@', '?getValue28@', '?setValue2c@', '?getValue2c@', '?getSize@', '?resolve@', '?shade@']),
    ]
    result = {}
    for name, original, expected in tables:
        symbol = '??_7' + name + '@PlayerNativeMaterial@@6B@'
        address = symbols[symbol]
        slots = []
        for index, prefix in enumerate(expected):
            value = struct.unpack_from('<I', image, address - base + index * 4)[0]
            candidates = by_address[value]
            assert any(s.startswith(prefix) for s in candidates), (name, index, candidates)
            if name == 'Material' and index in (2, 3):
                assert any(('ReferenceCountedPointer' in s) == (index == 3) and s.startswith(prefix) for s in candidates)
            if name == 'Level@Material' and index in (2, 3):
                assert any(('VTextureProxyBase@' in s) == (index == 3) and s.startswith(prefix) for s in candidates)
            native = struct.unpack_from('<I', target_image, original - target_base + index * 4)[0]
            slots.append({'slot': index, 'original': f'{native:08x}', 'compiled': f'{value:08x}', 'symbols': candidates})
        # Actual original RTTI base list, rather than a donor class-name assumption.
        def word(va):
            return struct.unpack_from('<I', target_image, va - target_base)[0]
        locator = word(original - 4)
        descriptor = word(locator + 16)
        count, array = word(descriptor + 8), word(descriptor + 12)
        bases = []
        for i in range(count):
            string = word(word(array + i * 4)) + 8 - target_base
            bases.append(target_image[string:target_image.index(b'\0', string)].decode('ascii'))
        result[name] = {'original_table': f'{original:08x}', 'compiled_table': f'{address:08x}', 'original_RTTI_bases': bases, 'slots': slots}
    output = Path(__file__).with_name('native-material-vtables.json')
    output.write_text(json.dumps(result, indent=2) + '\n')
    print('PASS: five original/compiled table contracts, overload slots, native RTTI')
    return result


if __name__ == '__main__':
    audit()
