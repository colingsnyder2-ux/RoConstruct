"""Bind MSVC ``type_info`` vtable identity from original RTTI descriptors.

No address is supplied as a fact: each --descriptor VA is an original type
descriptor used by a reviewed target body.  Its first word is the CRT
``type_info`` vptr.  The tool accepts it only when every supplied descriptor
has the same nonzero pointer in the original executable's read-only data and
the candidate object really references the decorated vtable symbol.
"""
import argparse
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / 'clients' / '2008-06' / 'Roblox.exe'
SYMBOL = '??_7type_info@@6B@'


def image_reader(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    base = struct.unpack_from('<I', data, pe + 0x34)[0]
    count = struct.unpack_from('<H', data, pe + 6)[0]
    optional = struct.unpack_from('<H', data, pe + 20)[0]
    sections = []
    for index in range(count):
        off = pe + 24 + optional + index * 40
        name = data[off:off + 8].split(b'\0', 1)[0].decode('ascii', 'replace')
        size, rva, raw_size, raw = struct.unpack_from('<IIII', data, off + 8)
        sections.append((name, rva, max(size, raw_size), raw))

    def read_word(va):
        rva = va - base
        for name, start, size, raw in sections:
            if start <= rva and rva + 4 <= start + size:
                return struct.unpack_from('<I', data, raw + rva - start)[0], name
        raise ValueError('VA outside image: %08x' % va)
    return base, read_word


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--descriptor', action='append', required=True,
                    help='original type-descriptor VA read by the reviewed target')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    raw_object = args.object.read_bytes()
    if SYMBOL.encode('ascii') not in raw_object:
        raise ValueError('candidate object does not reference ' + SYMBOL)
    image = EXE.read_bytes()
    base, read_word = image_reader(image)
    seen = []
    for text in args.descriptor:
        va = int(text, 16)
        value, section = read_word(va)
        # MSVC places the type name and descriptor in writable .data in this
        # EXE, while the common type_info virtual table remains in .rdata.
        if section not in ('.data', '.rdata') or not value:
            raise ValueError('descriptor %08x is not a nonzero data vptr' % va)
        value_section = read_word(value)[1]
        if value_section != '.rdata':
            raise ValueError('descriptor vptr %08x is not .rdata' % value)
        seen.append((f'{va:08x}', f'{value:08x}'))
    values = {value for _, value in seen}
    if len(values) != 1:
        raise ValueError('descriptors disagree: ' + repr(seen))
    address = values.pop()
    out = {
        'scope': 'original RTTI descriptor vptr identity only; no source/body/layout claim',
        'object': str(args.object.resolve().relative_to(ROOT)).replace('\\', '/'),
        'descriptors': [{'address': va, 'type_info_vptr': value} for va, value in seen],
        'identity_bindings': [{'symbol': SYMBOL, 'address': address,
                               'identity_evidence': 'original-rtti-type-descriptor-vptr',
                               'votes': len(seen)}],
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('bound', SYMBOL, address, 'from', len(seen), 'descriptors')


if __name__ == '__main__':
    main()
