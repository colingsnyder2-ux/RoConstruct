"""python vtslotaudit.py: every ??_7 vtable in our exe (linkexp/qt.map) whose slots point OUTSIDE .text (data executed
as code: a slot relocated to a dat_/vtable name), or to 0. Compares with the original table where the registry names
it. Writes auto/vtslotaudit.json [{vtable, owner, slot, target, target_sym}]."""
import bisect, json, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
pe = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True)
q = pe.get_memory_mapped_image(); B = pe.OPTIONAL_HEADER.ImageBase
text = [(B + s.VirtualAddress, B + s.VirtualAddress + s.Misc_VirtualSize) for s in pe.sections if s.Name.startswith(b'.text')]
rows = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            rows.append((int(p[2], 16), p[1], p[-1]))
        except ValueError:
            pass
rows.sort(); ks = [r[0] for r in rows]
near = lambda v: (lambda j: '%s+%x' % (rows[j][1][:80], v - ks[j]) if j >= 0 else '?')(bisect.bisect_right(ks, v) - 1)
intext = lambda v: any(a <= v < b for a, b in text)
bad = []
for i, (v, n, ob) in enumerate(rows):
    if not n.startswith('??_7') or v < B:
        continue
    end = rows[i + 1][0] if i + 1 < len(rows) else v + 4
    nslots = min((end - v) // 4, 200)
    for k in range(nslots):
        t = struct.unpack_from('<I', q, v - B + 4 * k)[0]
        if t == 0 or not intext(t):
            if t != 0 and k == nslots - 1:
                break   # next table's COL pointer
            bad.append({'vtable': n, 'owner': ob, 'slot': k, 'target': '%08x' % t, 'target_sym': near(t) if t else 'NULL'})
(H / 'auto/vtslotaudit.json').write_text(json.dumps(bad, indent=0))
import collections
print('vtables with non-code slots: %d (slots %d); by owner:' % (len({b['vtable'] for b in bad}), len(bad)), collections.Counter(b['owner'] for b in bad).most_common(6))
for b in [b for b in bad if b['target'] != '00000000'][:25]:
    print('  %-70s slot %2d -> %s' % (b['vtable'][:70], b['slot'], b['target_sym'][:70]))
