"""Restore audited switch destinations by retargeting COFF label relocations.

Only tables whose original and converted targets are the same local labels in a
different order are eligible. Original executable supplies the target order.
"""
import json
import struct
from pathlib import Path
import pefile
import datafix

H = Path(__file__).parent


def plan():
    records = json.loads((H / 'auto/switch_table_audit.json').read_text())
    result = {}
    for item in records:
        result.setdefault(item['function'], []).append(item)
    return result


def patch(source, destination, address, tables):
    data = bytearray(Path(source).read_bytes())
    symbols, opt = datafix._symtab(data)
    name = json.loads((H / 'renamed/rename.json').read_text())[address]['symbol']
    fn = next(v for v in symbols.values() if v[0] == name and 0 < v[1] < 0xfffe)
    header = struct.unpack_from('<8sIIIIIIHHI', data, 20 + opt + 40 * (fn[1] - 1))
    rel, count = header[5], header[7]
    relocs = {}
    for n in range(count):
        off, idx, kind = struct.unpack_from('<IIH', data, rel + n * 10)
        if kind == 6:
            relocs[off - fn[2]] = (rel + n * 10, idx)
    original = pefile.PE(str(H / 'run/RobloxOrig.exe'), fast_load=True)
    base = int(address, 16)
    changes = {}
    for table in tables:
        offset, size = int(table['table_offset'], 16), table['count']
        expected = struct.unpack('<' + 'I' * size, original.get_data(base + offset - original.OPTIONAL_HEADER.ImageBase, size * 4))
        expected = [v - base for v in expected]
        if expected != table['original']:
            raise ValueError('original switch differs from audit: ' + address)
        for n, target in enumerate(expected):
            off = offset + 4 * n
            pos, idx = relocs[off]
            symbol = symbols[idx]
            if symbol[1] != fn[1] or symbol[2] - fn[2] != table['converted'][n]:
                raise ValueError('converted switch differs from audit: ' + address)
            candidates = [i for i, v in symbols.items() if v[1] == fn[1] and v[2] - fn[2] == target]
            if not candidates:
                raise ValueError('original switch target missing: ' + address)
            if off in changes and changes[off] != candidates[0]:
                raise ValueError('overlapping switch tables disagree: ' + address)
            changes[off] = candidates[0]
    for off, idx in changes.items():
        struct.pack_into('<I', data, relocs[off][0] + 4, idx)
    destination = Path(destination)
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes(data)
    return destination
