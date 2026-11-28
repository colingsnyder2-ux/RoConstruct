"""python vtaudit.py [EXE MAP]: slot-by-slot audit of every primary vtable (??_7X@@6B@) in our link against the ORIGINAL
exe's vtable for that class (auto/orig_vt.pkl). Each original slot is resolved to the symbol our link should hold there
(make_stubs.data_relocs: the same mapping the original-bytes data copies use) and compared by ADDRESS with our slot.
Catches wrong-header layouts (stock Ogre SceneNode: 2 virtuals short, every later slot shifted) before they crash.
Read-only, seconds. Writes auto/vtaudit.json {vtable: {owner, slots, orig_slots, bad: [[i, ours, expected]...]}}."""
import json, pickle, re, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
q = pefile.PE(exe, fast_load=True); img = q.get_memory_mapped_image(); b = q.OPTIONAL_HEADER.ImageBase
addr, inv, owner = {}, {}, {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            a = int(p[2], 16)
        except ValueError:
            continue
        addr.setdefault(p[1], a); inv.setdefault(a, p[1]); owner.setdefault(p[1], p[-1])
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))


def thunk_target(v):
    """our import thunk (jmp [iat]) -> the IAT slot, so a slot bound to func_X vs the real name compares equal"""
    o = v - b
    if 0 <= o < len(img) - 6 and img[o:o + 2] == b'\xff\x25':
        return ('iat', struct.unpack_from('<I', img, o + 2)[0])
    return v


out, nbad, ncmp, nshift = {}, 0, 0, 0
for (cls, off), ov in vo.items():
    if off != 0 or not cls.startswith(('.?AV', '.?AU')):
        continue
    name = '??_7' + cls[4:] + '6B@'
    if name not in addr:
        continue
    va, slots = ov[0], ov[1]
    exp = dict(ms.data_relocs(va, 4 * len(slots)))   # {byte offset: symbol our link should have}
    a = addr[name]; bad = []
    want = {thunk_target(addr[e]): k // 4 for k, e in exp.items() if e in addr}   # target -> original slot index
    shifted = 0
    for i in range(len(slots)):
        e = exp.get(4 * i)
        if not e or e not in addr:
            continue   # original slot not resolvable to a linked symbol: no verdict
        ours = struct.unpack_from('<I', img, a - b + 4 * i)[0]
        if thunk_target(ours) != thunk_target(addr[e]):
            bad.append([i, inv.get(ours, '%08x' % ours)[:90], e[:90]])
            # LAYOUT evidence: our slot holds a method the original has at ANOTHER index (wrong header / missing
            # virtual), unlike func_X-vs-real-name identity noise where the same function just has two names
            shifted += want.get(thunk_target(ours), i) != i
    ncmp += 1
    if shifted >= 2:
        nshift += 1
    if bad:
        nbad += 1
        out[name] = dict(owner=owner.get(name), orig='%08x' % va, orig_slots=len(slots), bad=bad[:8], nbad=len(bad), shifted=shifted)
# SECONDARY subobject tables (??_7X@@6BBase@@) and LOCAL vftables (??_S...: native code's own copy of a dllimport
# class's table, e.g. the stock-header ??_SCamera@Ogre@@6BShadowCaster@1@@ that made a near-clip getter return 0):
# matched to the original by (class, subobject offset) from our own RTTI locator (??_R4 + the same suffix)
nsec = 0
for name, a in sorted(addr.items()):
    if not name.startswith(('??_7', '??_S')) or '@@6B' not in name or name in out or name.endswith('@@6B@'):
        if not (name.startswith('??_S') and name.endswith('@@6B@')):
            continue
    suffix = name[4:]
    col = '??_R4' + suffix
    if col not in addr:
        continue
    off = struct.unpack_from('<I', img, addr[col] - b + 4)[0]
    cls = suffix[:suffix.index('@@6B') + 2]
    ov = vo.get(('.?AV' + cls, off)) or vo.get(('.?AU' + cls, off))
    if not ov:
        continue
    va, slots = ov[0], ov[1]
    exp = dict(ms.data_relocs(va, 4 * len(slots)))
    want = {thunk_target(addr[e]): k // 4 for k, e in exp.items() if e in addr}
    bad, shifted = [], 0
    for i in range(len(slots)):
        e = exp.get(4 * i)
        if not e or e not in addr:
            continue
        ours = struct.unpack_from('<I', img, a - b + 4 * i)[0]
        if thunk_target(ours) != thunk_target(addr[e]):
            bad.append([i, inv.get(ours, '%08x' % ours)[:90], e[:90]])
            shifted += want.get(thunk_target(ours), i) != i
    ncmp += 1; nsec += 1
    if shifted >= 2:
        nshift += 1
    if bad:
        nbad += 1
        out[name] = dict(owner=owner.get(name), orig='%08x' % va, orig_slots=len(slots), bad=bad[:8], nbad=len(bad), shifted=shifted, subobject=off)
print('secondary/local vtables compared: %d' % nsec)
(H / 'auto/vtaudit.json').write_text(json.dumps(out, indent=1))
print('vtables compared %d, with wrong slots %d, LAYOUT-SHIFTED (>=2 slots hold methods the original has elsewhere) %d' % (ncmp, nbad, nshift))
for n, v in sorted(out.items(), key=lambda kv: -kv[1]['shifted'])[:25]:
    print('  %-55s shift %3d bad %3d/%3d [%s]' % (n[:55], v['shifted'], v['nbad'], v['orig_slots'], v['owner']))
