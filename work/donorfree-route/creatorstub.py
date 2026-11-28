"""python creatorstub.py: every FactoryProduct<T>::Creator vtable in our exe whose create slot (or the first calls
inside it) lands on a `return 0` stub -> Insert Object / AbstractFactoryProduct::create(name) gets NULL for T.
Writes auto/creatorstub.json [{creator, slot_target, stub}]."""
import bisect, json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
pe = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True); q = pe.get_memory_mapped_image(); B = pe.OPTIONAL_HEADER.ImageBase
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
rows, stubs = [], {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        rows.append((v, p[1], p[-1]))
        if 'stubs' in p[-1] and p[0].startswith('0001:'):
            stubs[v] = p[1]
rows.sort(); ks = [r[0] for r in rows]
name = lambda v: (lambda j: rows[j][1] if j >= 0 and rows[j][0] == v else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
bad = []
for v, n, ob in rows:
    if not (n.startswith('??_7Creator@?$FactoryProduct@') and n.endswith('6B@')):
        continue
    for k in range(4):
        t = struct.unpack_from('<I', q, v - B + 4 * k)[0]
        if not B < t < B + len(q):
            break
        hit = stubs.get(t)
        if not hit:
            for i in md.disasm(bytes(q[t - B:t - B + 0x60]), t):
                if i.mnemonic in ('call', 'jmp') and i.op_str.startswith('0x') and int(i.op_str, 16) in stubs:
                    hit = stubs[int(i.op_str, 16)]; break
                if i.mnemonic == 'ret':
                    break
        if hit:
            m = re.search(r'FactoryProduct@V(\w+)@', n)
            bad.append({'class': m.group(1) if m else n[:60], 'slot': k, 'target': name(t)[:100], 'stub': hit})
(H / 'auto/creatorstub.json').write_text(json.dumps(bad, indent=0))
print('Creator vtables reaching a stub: %d' % len({b['class'] for b in bad}))
for b in bad:
    print('  %-22s slot %d  %s -> %s' % (b['class'], b['slot'], b['target'][:50], b['stub'][:70]))
