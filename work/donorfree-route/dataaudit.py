"""python dataaudit.py [EXE MAP]: data-binding consistency of converted functions. Every converted func_<X> is the
original's code, so each absolute pointer into original data (0x7c0000-0x9a0000) at offset k pairs ONE original address
with the address our link put there. Across all converted functions the pairing must be one-to-one (up to the shift
inside one object): an our-address reached from two different original addresses means two original variables were
bound to one of ours (PartInstance::showAnchoredParts 00975f8c landed on FaceInstance's ClassDescriptor+4).
Prints the conflicts (our symbol+offset <- original addresses, and which functions) -> auto/dataaudit.json."""
import bisect, collections, json, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
qpe = pefile.PE(exe, fast_load=True); q = qpe.get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
syms, objof, names = {}, {}, {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            syms.setdefault(p[1], v); objof[p[1]] = p[-1]; names.setdefault(v, p[1])
ks = sorted(names)
near = lambda v: (lambda j: (names[ks[j]], v - ks[j]) if j >= 0 else ('?', v))(bisect.bisect_right(ks, v) - 1)
data_lo = min(s.VirtualAddress for s in qpe.sections if not s.Characteristics & 0x20000000) + B
pair = collections.defaultdict(lambda: collections.defaultdict(set))   # our address -> original address -> functions
for name, A in syms.items():
    if not (name.startswith('func_') and len(name) == 13 and objof.get(name) == name[5:] + '.obj'):
        continue
    X = int(name[5:], 16)
    for k in range(0, 0x400 - 4):
        if o[X - B + k] == 0xcc and o[X - B + k + 1] == 0xcc:
            break
        wo = struct.unpack_from('<I', o, X - B + k)[0]
        if not 0x7c0000 <= wo < 0x9a0000:
            continue
        wq = struct.unpack_from('<I', q, A - B + k)[0]
        if wq < data_lo or wq == wo:
            continue
        pair[wq][wo].add(name)
bad = []
for wq, m in pair.items():
    if len(m) > 1:
        s, off = near(wq)
        bad.append((s, off, {'%08x' % a: sorted(f)[:4] for a, f in m.items()}))
bad.sort(key=lambda b: -len(b[2]))
(H / 'auto/dataaudit.json').write_text(json.dumps(bad, indent=0))
print('our data addresses reached from 2+ original addresses: %d' % len(bad))
for s, off, m in bad[:15]:
    print('  %s+%x <- %s' % (s[:70], off, ', '.join('%s(%s)' % (a, f[0]) for a, f in list(m.items())[:3])))
