"""python layoutdiff.py [EXE MAP]: classes whose polymorphic subobject offsets (RTTI complete-object-locator offsets of their
vtables) differ between the original exe and ours. A difference means our objects of that class have another base
layout than the original, so exact code touching them breaks (native Instance's Notifiers sat at 20/52/.. instead of
36/68/..: setParent called a deleting destructor). Writes auto/layoutdiff.json, prints the worst classes. Seconds."""
import json, pickle, re, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
bo, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
orig = {}
for (cls, off), v in vo.items():
    orig.setdefault(cls, set()).add(off)
pe = pefile.PE(exe, fast_load=True)
img = pe.get_memory_mapped_image()
ours = {}
for m in re.finditer(r'\s(\?\?_7(\S+?)6B\S*)\s+([0-9a-f]{8})\s', open(mp, errors='replace').read()):
    va = int(m.group(3), 16)
    try:
        col = struct.unpack_from('<I', img, va - 4 - 0x400000)[0]
        off = struct.unpack_from('<I', img, col + 4 - 0x400000)[0]
        td = struct.unpack_from('<I', img, col + 12 - 0x400000)[0]
        name = img[td + 8 - 0x400000:img.index(b'\0', td + 8 - 0x400000)].decode('latin-1')
    except Exception:
        continue
    ours.setdefault(name, set()).add(off)
bad = {c: {'orig': sorted(o), 'ours': sorted(ours[c])} for c, o in orig.items() if c in ours and ours[c] != o}
(H / 'auto/layoutdiff.json').write_text(json.dumps(bad, indent=1))
print('%d of %d shared classes have a different subobject layout' % (len(bad), len(set(orig) & set(ours))))
for c, v in sorted(bad.items(), key=lambda x: -len(set(x[1]['orig']) ^ set(x[1]['ours'])))[:12]:
    print('  %-60s orig %s | ours %s' % (c[:60], v['orig'][:8], v['ours'][:8]))
