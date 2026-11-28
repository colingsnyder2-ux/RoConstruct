"""python vtdiff_obj.py A.obj B.obj: per vtable symbol, the relocation target names of its slots; prints names whose
slot lists differ and writes auto/vt_force_diff.json (the names to take from B)."""
import json, struct, sys
from pathlib import Path


def tables(path):
    d = Path(path).read_bytes()
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18
    names, i = {}, 0
    while i < ns:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', d, sp + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            o = st + struct.unpack_from('<I', raw, 4)[0]; n = d[o:d.index(b'\0', o)].decode('latin-1')
        else:
            n = raw.rstrip(b'\0').decode('latin-1')
        names[i] = (n, sec, val, cls)
        i += 1 + naux
    out = {}
    for idx, (n, sec, val, cls) in names.items():
        if n.startswith(('??_7', '??_S')) and 0 < sec < 0xfff0 and cls == 2:
            sh = 20 + opt + 40 * (sec - 1)
            size, relptr, nrel = struct.unpack_from('<I', d, sh + 16)[0], struct.unpack_from('<I', d, sh + 24)[0], struct.unpack_from('<H', d, sh + 32)[0]
            sl = {}
            for r in range(nrel):
                off, si, ty = struct.unpack_from('<IIH', d, relptr + 10 * r)
                sl[(off - val) // 4] = names.get(si, ('?',))[0]
            out[n] = [sl.get(k) for k in range(size // 4 - 1)]
    return out


a, b = tables(sys.argv[1]), tables(sys.argv[2])
diff = sorted(n for n in b if a.get(n) != b[n])
Path('auto/vt_force_diff.json').write_text(json.dumps(diff))
print('tables in B: %d, differing from A: %d' % (len(b), len(diff)))
for n in diff[:12]:
    print('  %-80s %s -> %s slots' % (n[:80], len(a.get(n) or []), len(b[n])))
