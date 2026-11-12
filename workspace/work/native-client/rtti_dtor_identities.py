"""Identity receipt from RTTI vftables: ??_7 (vftable), ??_G/??_E (scalar deleting dtor) and ??1 (dtor).

For each class with exactly one complete-object locator (offset 0, single vftable): ??_7<cls>6B@ is the address after
the locator pointer. A vftable slot whose body is exactly the MSVC scalar deleting destructor
    push esi; mov esi,ecx; call D; test byte [esp+8],1; je +9; push esi; call operator delete; add esp,4; mov eax,esi;
    pop esi; ret 4
binds ??_G and ??_E (MSVC names the slot ??_E; with no array delete the body is the scalar one) and D = ??1 when D
itself stores that vftable. Virtual public dtor spelling (UAE) only; other access levels simply never match.

  python work/native-client/rtti_dtor_identities.py   -> work/native-client/rtti-dtor-identities.json
"""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, rtti  # noqa: E402

OUT = ROOT / 'work/native-client/rtti-dtor-identities.json'


def main():
    base, image = match._image('2008-06')
    funcs = {int(a, 16) for a in match._functions('2008-06')}
    starts = sorted(funcs)
    from bisect import bisect_right
    types = rtti.descriptors('2008-06')
    u32 = lambda va: struct.unpack_from('<I', image, va - base)[0]
    cols = defaultdict(list)                          # class -> [(col va, offset)]
    for off in range(0, len(image) - 20, 4):
        sig, offset, cd, td, chd = struct.unpack_from('<IIIII', image, off)
        if sig == 0 and td in types and base <= chd < base + len(image) and offset < 0x10000:
            cols[types[td]].append((base + off, offset))
    tables = defaultdict(list)                        # col va -> vftable va
    want = {c[0][0]: n for n, c in cols.items() if len(c) == 1 and c[0][1] == 0}
    for off in range(0, len(image) - 8, 4):
        c = struct.unpack_from('<I', image, off)[0]
        if c in want:
            tables[c].append(base + off + 4)
    rows, conflicts = [], defaultdict(set)
    for col, name in want.items():
        if len(tables[col]) != 1 or not name.startswith(('.?AV', '.?AU')):
            continue
        cls, vft = name[4:], tables[col][0]
        rows.append({'symbol': f'??_7{cls}6B@', 'address': f'{vft:08x}', 'evidence': f'RTTI {name} locator {col:08x}'})
        for slot in range(64):
            fn = u32(vft + 4 * slot)
            if fn not in funcs:
                break
            b = image[fn - base:fn - base + 32]
            if not (b[:3] == b'\x56\x8b\xf1' and b[3] == 0xe8 and b[8:15] == b'\xf6\x44\x24\x08\x01\x74\x09'
                    and b[15] == 0x56 and b[16] == 0xe8 and b[21:29] == b'\x83\xc4\x04\x8b\xc6\x5e\xc2\x04'):
                continue
            dtor = fn + 8 + struct.unpack_from('<i', b, 4)[0]
            ev = f'slot {slot} of {name} vftable {vft:08x}: exact MSVC scalar deleting dtor body'
            rows += [{'symbol': f'??_G{cls}UAEPAXI@Z', 'address': f'{fn:08x}', 'evidence': ev},
                     {'symbol': f'??_E{cls}UAEPAXI@Z', 'address': f'{fn:08x}', 'evidence': ev}]
            nxt = starts[bisect_right(starts, dtor)] if bisect_right(starts, dtor) < len(starts) else dtor + 0x400
            d = image[dtor - base:dtor - base + min(0x400, nxt - dtor)]      # the dtor's own bytes only: a neighbour's constructor also stores the vftable
            if dtor in funcs and struct.pack('<I', vft) in d:
                rows.append({'symbol': f'??1{cls}UAE@XZ', 'address': f'{dtor:08x}',
                             'evidence': f'called by deleting dtor {fn:08x}; stores vftable {vft:08x}'})
            break
    for r in rows:
        conflicts[r['symbol']].add(r['address'])
    rows = [r for r in rows if len(conflicts[r['symbol']]) == 1]
    OUT.write_text(json.dumps({'scope': __doc__.splitlines()[0], 'rows': rows}, indent=1) + '\n')
    print(json.dumps({'rows': len(rows), 'dtors': sum(r['symbol'].startswith('??1') for r in rows),
                      'deleting': sum(r['symbol'].startswith('??_G') for r in rows)}))


if __name__ == '__main__':
    main()
