"""Read-only: every MSVC vtable in the 2008-06 exe (found through its RTTI complete-object locator), and which
registry placeholder functions sit in a vtable slot.  A slot proves owner class + virtual __thiscall; a name
still needs a header-slot match (native_vtable_slot_identity.py).

  python work/native-client/vtable_owner_scan.py   -> work/native-client/vtable-owner-scan.json
"""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, rtti  # noqa: E402

CLIENT = '2008-06'
REGISTRY = ROOT / 'work/native-client/ogre-names-registry.json'
OUT = ROOT / 'work/native-client/vtable-owner-scan.json'


def main():
    base, image = match._image(CLIENT)
    funcs = {int(a, 16) for a, r in match._functions(CLIENT).items() if r.get('kind') == 'code'}
    types = rtti.descriptors(CLIENT)
    u32 = lambda va: struct.unpack_from('<I', image, va - base)[0]
    # Complete object locator: {signature 0, offset, cdOffset, pTypeDescriptor, pClassHierarchyDescriptor}
    cols = {}
    for off in range(0, len(image) - 20, 4):
        sig, offset, cd, td, chd = struct.unpack_from('<IIIII', image, off)
        if sig == 0 and td in types and base <= chd < base + len(image) and offset < 0x10000:
            cols[base + off] = (types[td], offset)
    slots = defaultdict(list)                 # function va -> [(class, this-offset, slot, vtable va)]
    vtables = 0
    for off in range(0, len(image) - 8, 4):
        col = struct.unpack_from('<I', image, off)[0]
        if col not in cols:
            continue
        table = base + off + 4
        name, offset = cols[col]
        vtables += 1
        for slot in range(512):
            entry = u32(table + 4 * slot)
            if entry not in funcs or (slot and (table + 4 * slot - base) // 4 * 4 in ()):
                break
            slots[entry].append((name, offset, slot, '%08x' % table))
    registry = json.loads(REGISTRY.read_text())
    rows = registry.items() if isinstance(registry, dict) else ((r['addr'], r) for r in registry)
    placeholders = {a for a, r in rows if isinstance(r, dict) and r.get('placeholder')}
    hit = {a: slots[int(a, 16)] for a in sorted(placeholders) if int(a, 16) in slots}
    single = {a: v for a, v in hit.items() if len({n for n, *_ in v}) == 1}
    report = {'vtables': vtables, 'complete_object_locators': len(cols), 'placeholders': len(placeholders),
              'placeholders_in_a_vtable': len(hit), 'single_owner_class': len(single),
              'owners': {a: [{'class': n, 'this_offset': o, 'slot': s, 'vtable': t} for n, o, s, t in v]
                         for a, v in hit.items()}}
    OUT.write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps({k: v for k, v in report.items() if k != 'owners'}))


if __name__ == '__main__':
    main()
