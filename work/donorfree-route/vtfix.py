"""python vtfix.py: repoint vt_orig.obj slots that natret.py found bound to the WRONG function (same registry name, other
code: a folded label made DescribedCreatable<BodyForce> slot 1 call DirectPhysicsReceiver::receivePacket, and an input
listener slot popped the wrong amount -> func_00575ba0 returned to 0 on File->New). Each such slot's relocation is
pointed at a new external func_<original slot address> (the converted copy, glue, or a stub with the original's pop
size). Reads auto/natret.json; patches linkexp/vt_orig.obj in place from linkexp/vt_orig_prev.obj (idempotent)."""
import json, pickle, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
bad = json.loads((H / 'auto/natret.json').read_text())
_vl = H / 'auto/vtfix_list.json'   # grow-only: vtfix rebuilds from vt_orig_prev.obj, so a fixed slot must stay listed
try:
    _old = json.loads(_vl.read_text())
except (OSError, ValueError):
    _old = []
_seen = {(b[0], b[1]) for b in _old}
bad = _old + [b for b in bad if (b[0], b[1]) not in _seen]
_vl.write_text(json.dumps(bad, indent=0))
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
src = H / 'linkexp/vt_orig_prev.obj'
data = bytearray(src.read_bytes())
_, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
strtab = symptr + nsym * 18
tail = bytearray(data[strtab + 4:])
sec_of, i = {}, 0
while i < nsym:
    raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
    if raw[:4] == b'\0\0\0\0':
        o = strtab + struct.unpack_from('<I', raw, 4)[0]
        name = data[o:data.index(b'\0', o)].decode('latin-1')
    else:
        name = raw.rstrip(b'\0').decode('latin-1')
    if name.startswith(('??_7', '??_S')) and 0 < secnum < 0xfff0 and cls == 2:
        sec_of[name] = (secnum, value)
    i += 1 + naux
# original slot address per (vtable, slot): natret saw the vt_orig table at the vt_orig COL offset -> recompute from
# the slot's CURRENT relocation is not needed: natret recorded orig ret only, so look the table up the same way
q_col = json.loads((H / 'auto/natret_tables.json').read_text())   # vtable name -> original table address
newsyms, newidx, done = bytearray(), {}, 0
for row in bad:
    vt, slot = row[0], row[1]
    if vt not in sec_of:
        continue
    if len(row) > 5:   # explicit target (dtorslots.py: the native deleting destructor)
        new = row[5]
    else:
        if vt not in q_col:
            continue
        oa = int(q_col[vt], 16)
        tbl = next((sl for (tn, off), (va, sl) in vo.items() if va == oa), None)
        if not tbl or slot >= len(tbl):
            continue
        new = 'func_%08x' % tbl[slot]
    secnum, value = sec_of[vt]
    sh = 20 + optsz + 40 * (secnum - 1)
    relptr, nrel = struct.unpack_from('<I', data, sh + 24)[0], struct.unpack_from('<H', data, sh + 32)[0]
    for r in range(nrel):
        ro = relptr + 10 * r
        if struct.unpack_from('<I', data, ro)[0] == value + 4 * slot:
            if new not in newidx:
                nb = new.encode()
                rawn = struct.pack('<II', 0, 4 + len(tail)); tail += nb + b'\0'
                newidx[new] = nsym + len(newsyms) // 18
                newsyms += rawn + struct.pack('<IhHBB', 0, 0, 0x20, 2, 0)
            struct.pack_into('<I', data, ro + 4, newidx[new]); done += 1
data = data[:strtab] + newsyms + struct.pack('<I', 4 + len(tail)) + tail
struct.pack_into('<I', data, 12, nsym + len(newsyms) // 18)
(H / 'linkexp/vt_orig.obj').write_bytes(bytes(data))
print('vtfix: %d vt_orig slots repointed to func_<original address> (%d new externals)' % (done, len(newidx)))
