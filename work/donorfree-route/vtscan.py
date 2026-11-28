"""python vtscan.py: every vtable (??_7) in our link: slots that point into DATA instead of code (a vtable slot bound
to a data symbol jumps into data at runtime). Compares slot count/targets with the original exe's vtable when the
converter recorded the original address. Read-only, seconds."""
import pefile, struct, sys
from pathlib import Path
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
q = pefile.PE(exe, fast_load=True); img = q.get_memory_mapped_image(); b = q.OPTIONAL_HEADER.ImageBase
code = [(b + s.VirtualAddress, b + s.VirtualAddress + s.Misc_VirtualSize) for s in q.sections if s.Characteristics & 0x20000000]
iscode = lambda v: any(lo <= v < hi for lo, hi in code)
inv, vt = {}, []
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            a = int(p[2], 16)
        except ValueError:
            continue
        inv.setdefault(a, p[1])
        if p[1].startswith('??_7'):
            vt.append((a, p[1], p[-1]))
starts = sorted(inv)
import bisect
bad = 0
for a, n, obj in vt:
    j = bisect.bisect_right(starts, a)
    end = starts[j] if j < len(starts) else a + 4
    for i in range(min((end - a) // 4, 400)):
        o = a - b + 4 * i
        if o + 4 > len(img):
            break
        v = struct.unpack_from('<I', img, o)[0]
        if v and not iscode(v) and b <= v < b + len(img):
            if inv.get(v, '').startswith('??_R4') or not v:
                break   # next vtable's RTTI locator: this table ended
            bad += 1
            print('%s slot %d -> %08x %s  [%s]' % (n[:70], i, v, inv.get(v, '?')[:60], obj))
print('vtables %d, data-pointing slots %d' % (len(vt), bad))
