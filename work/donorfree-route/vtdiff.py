"""python vtdiff.py [EXE MAP]: every RTTI vtable in the original exe and in ours, paired by (class type name, subobject
offset); each slot's target compared by masked body (namediff rules). Wrong slots -> auto/vtdiff.json, counts printed."""
import json, re, struct, sys
from collections import Counter
from pathlib import Path
import capstone, pefile
from origcache import orig_body
H = Path(__file__).parent
ROOT = H.parents[1]
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'link/donorfree.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'link/donorfree.map')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MASK = re.compile(r'0x[0-9a-f]{5,8}')
def body(b, a):
    out = []
    for i in md.disasm(b[a - 0x400000:a - 0x400000 + 0x400], a):
        out.append(i.mnemonic + ' ' + MASK.sub('X', i.op_str))
        if i.mnemonic in ('ret', 'int3', 'jmp') or len(out) >= 60:
            break
    return out
def load(path):
    pe = pefile.PE(path)
    img = bytes(pe.get_memory_mapped_image())
    text = next(s for s in pe.sections if s.Name.startswith(b'.text'))
    lo, hi = 0x400000 + text.VirtualAddress, 0x400000 + text.VirtualAddress + text.Misc_VirtualSize
    rd = lambda a: struct.unpack_from('<I', img, a - 0x400000)[0] if 0x400000 <= a < 0x400000 + len(img) - 4 else None
    vts = {}
    for s in pe.sections:
        if not s.Name.startswith(b'.rdata'):
            continue
        a0 = 0x400000 + s.VirtualAddress
        for v in range(a0 + 4, a0 + s.Misc_VirtualSize - 4, 4):
            col = rd(v - 4)
            if not col or not (a0 <= col < a0 + s.Misc_VirtualSize) or rd(col) != 0:
                continue
            td = rd(col + 12)
            f0 = rd(v)
            if not td or not f0 or not (lo <= f0 < hi):
                continue
            raw = img[td + 8 - 0x400000:td + 8 - 0x400000 + 160].split(b'\0', 1)[0]
            if not raw.startswith((b'.?AV', b'.?AU')):
                continue
            slots = []
            k = v
            while True:
                f = rd(k)
                if not f or not (lo <= f < hi) or (k != v and rd(k - 4) and k - 4 != v - 4 and False):
                    break
                slots.append(f)
                k += 4
                if k - v > 4 and rd(k) is not None and rd(k + 0) and False:
                    break
                if len(slots) > 400:
                    break
            vts[(raw.decode('latin-1'), rd(col + 4))] = (v, slots)
    return img, vts
import pickle as _pk
_vf = H / 'auto/orig_vt.pkl'
try:
    bo, vo = _pk.load(open(_vf, 'rb'))
except Exception:
    bo, vo = load(str(ROOT / 'clients/2008-06/Roblox.exe'))
    _pk.dump((bo, vo), open(_vf, 'wb'), protocol=4)
bn, vn = load(exe)
name_at = {}
for l in open(mp, errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)', l)
    if m:
        name_at.setdefault(int(m.group(2), 16), (m.group(1), m.group(3)))
bad, ok, missing, short = [], 0, 0, 0
for key, (va, so) in vo.items():
    if key not in vn:
        missing += 1
        continue
    vb, sn = vn[key]
    if len(sn) < len(so):
        short += 1
    for i, (t, u) in enumerate(zip(so, sn)):
        if orig_body(body, bo, t, 'vt') == body(bn, u):
            ok += 1
            continue
        nm, ob = name_at.get(u, ('?', '?'))
        bad.append({'class': key[0], 'off': key[1], 'slot': i, 'orig': '%08x' % t, 'ours': nm, 'obj': ob, 'stub': ob == 'stubs.obj'})
# shifted tables: our slot i+d has the original slot i body for most i (a virtual added/missing in a native header)
shift = {}
for key, (va, so) in vo.items():
    if key in vn:
        sn = vn[key][1]
        for d in (-2, -1, 1, 2):
            hits = sum(1 for i, t in enumerate(so) if 0 <= i + d < len(sn) and orig_body(body, bo, t, 'vt') == body(bn, sn[i + d]))
            same = sum(1 for i, t in enumerate(so) if i < len(sn) and orig_body(body, bo, t, 'vt') == body(bn, sn[i]))
            if hits >= 3 and hits > same:
                shift[key[0] + '+%d' % key[1]] = d
                break
(H / 'auto/vtshift.json').write_text(json.dumps(shift, indent=0))
print('shifted vtables (virtual added/missing in our header): %d' % len(shift), list(shift.items())[:15])
(H / 'auto/vtdiff.json').write_text(json.dumps(bad, indent=0))
print('vtables orig %d ours %d | missing in ours %d, fewer slots %d | slots identical %d, differ %d (stub %d) in %d classes'
      % (len(vo), len(vn), missing, short, ok, len(bad), sum(b['stub'] for b in bad), len({b['class'] for b in bad})))
for c, n in Counter(b['class'] for b in bad).most_common(12):
    print('  %4d %s' % (n, c))
