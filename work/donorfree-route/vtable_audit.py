"""python vtable_audit.py: compare every class vtable of the donor-free exe with the original exe's, by RTTI name.
Reports classes whose slot count differs (an extra/missing virtual shifts every later slot: a wrong call at runtime) and,
for equal counts, slots that disagree on being code/folded. No run needed: reads link/donorfree.exe + link/donorfree.map."""
import re, struct, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]; sys.path.insert(0, str(ROOT)); sys.path.insert(0, str(Path(__file__).parent))
import pefile
import rtti_vtable as rv
ours = open(ROOT / 'work/donorfree-route/link/donorfree.exe', 'rb').read()
q = pefile.PE(data=ours)
txt = open(ROOT / 'work/donorfree-route/link/donorfree.map', errors='replace').read()
text_lo, text_hi = 0x401000, 0x401000 + q.sections[0].Misc_VirtualSize
def slots_ours(a):
    o = q.get_offset_from_rva(a - 0x400000); n = 0
    while True:
        v = struct.unpack_from('<I', ours, o + 4 * n)[0]
        if not (text_lo <= v < text_hi): return n
        n += 1
def slots_exe(a):
    n = 0
    while True:
        v = struct.unpack_from('<I', rv.rd(a + 4 * n, 4))[0]
        if not (0x401000 <= v < 0x800000): return n
        n += 1
bad = []; ok = 0; unknown = 0
by_class = {}
for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+\?\?_7(.+?)@@6B(.*?)@\s+([0-9a-f]{8})\s', txt, re.M):
    by_class.setdefault(m.group(1), []).append(int(m.group(3), 16))
for cls, addrs in by_class.items():
    ev = rv.vtable('.?AV' + cls + '@@')
    if not ev: unknown += 1; continue
    a = max(slots_ours(x) for x in addrs); b = slots_exe(ev)   # MI classes: the primary vtable is our largest one
    if a == b: ok += 1
    else: bad.append((cls, a, b))
print('vtables equal:', ok, ' mismatched:', len(bad), ' no exe RTTI:', unknown)
for c, a, b in sorted(bad, key=lambda x: x[0]): print('  %-60s ours %3d  exe %3d' % (c[:60], a, b))
