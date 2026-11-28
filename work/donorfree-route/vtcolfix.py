"""python vtcolfix.py: vt_orig.obj tables whose RTTI-locator slot ([-1]) has no relocation (our link had no ??_R4 for
the class) get a DIR32 relocation to dat_<original COL address> (a copy of the original locator, stubbed with its
type descriptor/hierarchy relocated). A null [-1] made dynamic_cast throw __non_rtti_object (CPropGrid::rebuild on
PropDescriptor<PartInstance,CoordinateFrame>). Original table address: identity registry (unique ??_7 name).
Patches linkexp/vt_orig.obj in place (backup vt_orig_precol.obj); idempotent."""
import json, shutil, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
src = H / 'linkexp/vt_orig.obj'
bak = H / 'linkexp/vt_orig_precol.obj'
if not bak.exists():
    shutil.copy(src, bak)
reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
byname = {}
for a, v in reg.items():
    n = (v or {}).get('name')
    if n and n.startswith('??_7'):
        byname.setdefault(n, []).append(int(a, 16))
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
d = bytearray(src.read_bytes())
_, nsec, _, sp, nsym, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
st = sp + nsym * 18
tail = bytearray(d[st + 4:])


def nm(i):
    r = d[sp + 18 * i:sp + 18 * i + 8]
    if r[:4] == b'\0\0\0\0':
        s = st + struct.unpack_from('<I', r, 4)[0]; return bytes(d[s:d.index(b'\0', s)]).decode('latin1')
    return bytes(r).rstrip(b'\0').decode('latin1')


want = {}   # section -> dat_ name
i = 0; miss = 0
while i < nsym:
    v, sec, ty, cl, na = struct.unpack_from('<IhHBB', d, sp + 18 * i + 8)
    n = nm(i)
    if cl == 2 and sec > 0 and n.startswith('??_7') and v == 4:
        sh = 20 + opt + 40 * (sec - 1)
        prel, = struct.unpack_from('<I', d, sh + 24); nrel = struct.unpack_from('<H', d, sh + 32)[0]
        if not any(struct.unpack_from('<I', d, prel + 10 * r)[0] == 0 for r in range(nrel)):
            oa = byname.get(n, [])
            if len(oa) == 1:
                c4 = struct.unpack_from('<I', o, oa[0] - 0x400000 - 4)[0]
                if 0x7c0000 <= c4 < 0x9a0000:
                    want[sec] = 'dat_%08x' % c4
                    continue_ = True
            else:
                miss += 1
    i += 1 + na
if want:
    body, symtab = d[:sp], d[sp:st]
    newidx = {}
    for sec, s in sorted(want.items()):
        if s not in newidx:
            newidx[s] = nsym + len(newidx)
            nb = s.encode()
            symtab += struct.pack('<II', 0, 4 + len(tail)) + struct.pack('<IhHBB', 0, 0, 0, 2, 0); tail += nb + b'\0'
        sh = 20 + opt + 40 * (sec - 1)
        prel, = struct.unpack_from('<I', d, sh + 24); nrel = struct.unpack_from('<H', d, sh + 32)[0]
        old = bytes(d[prel:prel + 10 * nrel]) if nrel else b''
        struct.pack_into('<I', body, sh + 24, len(body)); struct.pack_into('<H', body, sh + 32, nrel + 1)
        body += old + struct.pack('<IIH', 0, newidx[s], 6)
        struct.pack_into('<I', body, sh + 36, struct.unpack_from('<I', d, sh + 36)[0])
    struct.pack_into('<I', body, 8, len(body)); struct.pack_into('<I', body, 12, nsym + len(newidx))
    src.write_bytes(bytes(body + symtab + struct.pack('<I', 4 + len(tail)) + tail))
print('vtcolfix: tables given the original RTTI locator: %d (no unique registry address: %d)' % (len(want), miss))
