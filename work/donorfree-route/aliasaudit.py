"""python aliasaudit.py: func_<A>=S aliases whose S is NATIVE code proven to be another original function.
aliases_renamed.txt bound func_00490c30 (the original find<Service>) to the registry's folded name
SpawnLocation::onServiceProvider; the native SpawnLocation draft defines that name, so DataModel::clearContents
"found" a SpawnLocation and cleared a std::list inside it -> heap corruption on Reset.
Proof standard (as natbody_check): our S body differs from the original at A AND equals another original function.
Writes auto/alias_drop.json [alias line] (grow-only, re-proven each run); quicktest skips those lines."""
import json, re, sys
from pathlib import Path
H = Path(__file__).parent
src = (H / 'natcallaudit.py').read_text(encoding='utf-8')
g = {'__file__': str(H / 'natcallaudit.py')}
exec(compile(src.split('names, objat, rows, real = ')[0], 'natcallaudit_head', 'exec'), g)   # body(), osig, images
body, q, o, B, osig = g['body'], g['q'], g['o'], g['B'], g['osig']
rows, addr = [], {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        rows.append(v); addr.setdefault(p[1], (v, p[-1]))
rows = sorted(set(rows))
import bisect, difflib
md = g['md']


def mn(img, va):
    out = []
    for i_ in md.disasm(bytes(img[va - B:va - B + 0x600]), va):
        out.append(i_.mnemonic)
        if i_.mnemonic in ('ret', 'int3') or len(out) > 200:
            break
    return out

import collections as _co
_reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
_cnt = _co.Counter(v['name'] for a_, v in _reg.items() if v and (v.get('name') or '').startswith('?') and 0x401000 <= int(a_, 16) < 0x7c0000)
FOLDED = {n_ for n_, c_ in _cnt.items() if c_ > 1}
_qn = {}
for l_ in open(H / 'linkexp/qt.map', errors='replace'):
    p_ = l_.split()
    if len(p_) >= 4 and p_[0].startswith('0001:'):
        try:
            _qn.setdefault(int(p_[2], 16), p_[1])
        except ValueError:
            pass


def _calls(img, va):
    out = []
    for i_ in md.disasm(bytes(img[va - B:va - B + 0x300]), va):
        if i_.mnemonic == 'call' and i_.op_str.startswith('0x'):
            out.append((i_.address - va, int(i_.op_str, 16)))
        if i_.mnemonic in ('ret', 'int3'):
            break
    return out


def callee_clash(A, v):   # a constructor/class-named callee differs: ??0Team vs ??0GameSettings at the same offset
    for (oo, to), (oq, tq) in zip(_calls(o, A), _calls(q, v)):
        if oo != oq:
            return False
        on = (_reg.get('%08x' % to) or {}).get('name') or ''
        qn = _qn.get(tq, '')
        if on.startswith('??0') and qn.startswith('??0') and on.split('@')[0] != qn.split('@')[0]:
            return True
    return False


drop = []
for fn in ('aliases_renamed.txt', 'aliases_auto.txt', 'aliases_qualname.txt', 'aliases_twins.txt', 'aliases_long.txt'):
    f = H / fn
    if not f.exists():
        continue
    for l in f.read_text().splitlines():
        m = re.fullmatch(r'func_([0-9a-f]{8})=(\S+)', l.strip())
        if not m or m.group(2) not in addr:
            continue
        A = int(m.group(1), 16)
        v, ob = addr[m.group(2)]
        if re.fullmatch(r'(?:(?:ca|cf|dr|nx)_)*[0-9a-f]{8}\.obj', ob) or 'stubs' in ob or ':' in ob or not 0x401000 <= A < 0x7c0000:
            continue   # converted / stub / import targets: callaudit covers them
        j = bisect.bisect_right(rows, v)
        sq = body(q, v, rows[j] if j < len(rows) else v + 0x200, 0x400000, 0x3000000)[0]
        so = body(o, A, A + 0x1800, 0x400000, 0x9a0000)[0]
        other = [a for a, _ in osig.get(sq, [])] if sq else []
        if sq and sq != so and other and A not in other:
            drop.append(l.strip())
        elif m.group(2) in FOLDED and sq == so and callee_clash(A, v):   # same shape, other constructor (create<Team> vs create<GameSettings>)
            drop.append(l.strip())
        elif sq != so and m.group(2) in FOLDED and (H / 'renamed/obj' / ('%08x.obj' % A)).exists():
            # registry-folded name (create<Team> stands for 4 create<X>): A's own converted body takes over
            drop.append(l.strip())
        elif sq != so:   # fuzzy: mnemonic sequences of different functions barely overlap; a rebuild of the same one does
            ra = mn(o, A); rb = mn(q, v)
            if len(ra) >= 8 and len(rb) >= 8 and difflib.SequenceMatcher(None, ra, rb, autojunk=False).ratio() < 0.6:   # 11-25 distribution: different functions <= 0.44, rebuilds >= 0.85
                drop.append(l.strip())
pf = H / 'auto/alias_drop.json'
prev = json.loads(pf.read_text()) if pf.exists() else []
# dropcheck.py proved these EXACT at A from the native objects themselves (our exe's body for S was another copy, or S
# was dropped by the linker, so the comparison above read the wrong bytes): never drop them again
_fp = set(json.loads((H / 'auto/alias_drop_falsepos.json').read_text())) if (H / 'auto/alias_drop_falsepos.json').exists() else set()
allv = sorted((set(prev) | set(drop)) - _fp)
pf.write_text(json.dumps(allv, indent=0))
print('aliasaudit: func_<A> aliases bound to native code of another original function: %d (total %d)' % (len(drop), len(allv)))
for d in drop[:10]:
    print('  ', d[:120])
