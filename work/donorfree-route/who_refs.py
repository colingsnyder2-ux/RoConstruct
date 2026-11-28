"""Which COMDAT sections / symbols reference a symbol? python who_refs.py OBJ SUBSTRING"""
import struct, sys
from pathlib import Path
data = Path(sys.argv[1]).read_bytes(); want = sys.argv[2]
_, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
strtab = symptr + nsym * 18
names = []; i = 0; secof = {}
while i < nsym:
    raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
    secnum = secnum - 0x10000 if secnum >= 0xFFFE else secnum   # unsigned section number; -1 abs / -2 debug stay special
    nm = data[strtab + struct.unpack_from('<I', raw, 4)[0]:].split(bytes(1), 1)[0].decode('latin-1') if raw[:4] == bytes(4) else raw.rstrip(bytes(1)).decode('latin-1')
    names.append((nm, secnum, cls)); names.extend([('', 0, 0)] * naux); i += 1 + naux
# a symbol that owns each section (first external symbol defined in it)
owner = {}
for nm, sn, cls in names:
    if sn > 0 and cls == 2 and sn not in owner: owner[sn] = nm
hits = {}
for s in range(nsec):
    sec = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * s)
    relptr, nrel = sec[5], sec[7]
    for k in range(nrel):
        off, symi, typ = struct.unpack_from('<IIH', data, relptr + 10 * k)
        if want in names[symi][0]:
            hits.setdefault(owner.get(s + 1, '<section %d>' % (s + 1)), set()).add(names[symi][0][:70])
for o, t in hits.items(): print(o[:110], '->', sorted(t)[:2])
