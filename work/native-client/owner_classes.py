"""Infer owner classes for remaining 2008-06 functions with no owner (vtable / thiscall / callers / neighbours).
Each signal is validated on functions whose owner is known; signals under 90% precision are dropped.
  python work/native-client/owner_classes.py  -> work/native-client/owner-classes.json"""
import bisect, collections, json, re, struct, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m          # noqa: E402
from roc import match, integration_site   # noqa: E402

reg = m.load_registry()
base, image = match._image('2008-06')
relocs = sorted(match._base_relocs('2008-06'))
reloc_set = set(relocs)
starts = sorted(int(a, 16) for a in match._functions('2008-06'))
code_lo = starts[0]
code_hi = starts[-1] + len(match.target('2008-06', '%08x' % starts[-1])[0])   # end of .text
EXACT = {a: v[0] for a, v in integration_site.inactive_code(HERE.parents[1]).items() if v[1]}
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - set(EXACT)


def dw(va):
    return struct.unpack_from('<I', image, va - base)[0]


points_to = collections.defaultdict(list)
for r in relocs:
    try:
        points_to[dw(r)].append(r)
    except struct.error:
        pass


def owner(va):
    i = bisect.bisect_right(starts, va) - 1
    return starts[i] if i >= 0 else None


def vtable_start(slot):
    s = slot
    while True:
        if any(code_lo <= r < code_hi for r in points_to.get(s, ())):
            return s
        if not (s - 4 in reloc_set and code_lo <= dw(s - 4) < code_hi):
            return s
        s -= 4


def first_class(name):
    hit = re.match(r'\?\?(?:[01]|_[GE])(\w+)@', name) or re.match(r'\?\w+@(\w+)@', name)
    return hit.group(1) if hit else None


def cls(a):
    """Known leaf owner class of the function at int address a (registry owner_class, signature, name, exact symbol)."""
    k = '%08x' % a
    r = reg.get(k) or {}
    if r.get('placeholder'):
        r = {}
    oc = r.get('owner_class')
    if oc:
        return oc.split('::')[-1]
    hit = re.search(r'(\w+)::~?\w+\(', r.get('signature') or '')
    if hit:
        return hit.group(1)
    return first_class(r.get('name') or '') or first_class(EXACT.get(k) or '')


_cls = cls


def cls(a):             # template fragments from mangled names (`allocator<char> > >`) are not classes
    c = _cls(a)
    return c if c and re.fullmatch(r'[A-Za-z_]\w*', c) else None


C = {a: cls(a) for a in starts}
# call graph; call_ctx = callers that load ecx from a callee-saved register just before the call
callers = collections.defaultdict(set)
this_callers = collections.defaultdict(set)
for i, s in enumerate(starts[:-1]):
    body = image[s - base:min(starts[i + 1], s + 0x4000) - base]
    for mt in re.finditer(rb'[\xe8\xe9]', body):
        j = mt.start()
        if j + 5 > len(body):
            continue
        t = (s + j + 5 + struct.unpack_from('<i', body, j + 1)[0]) & 0xffffffff
        if code_lo <= t < code_hi:
            callers[t].add(s)
            if mt.group() == b'\xe8' and re.search(rb'\x8b[\xce\xcf\xcb\xcd]', body[max(0, j - 8):j]):
                this_callers[t].add(s)


def uniq(classes):
    classes = {c for c in classes if c}
    return next(iter(classes)) if len(classes) == 1 else None


def s_vtable(a):
    cs, n = set(), 0
    for slot in points_to.get(a, []):
        if code_lo <= slot < code_hi:
            continue
        for ref in points_to.get(vtable_start(slot), []):
            if code_lo <= ref < code_hi:
                n += 1
                cs.add(C.get(owner(ref)))
    return (uniq(cs), 'in vtable installed by %d site(s)' % n) if n else (None, '')


def s_thiscall(a):
    cs = [C.get(c) for c in this_callers.get(a, ())]
    c = uniq(cs) if cs and all(cs) else None
    return (c, 'ecx passed unchanged by %d member caller(s)' % len(cs)) if c else (None, '')


def s_callers(a):
    cs = [C.get(c) for c in callers.get(a, ())]
    c = uniq(cs) if len(cs) >= 2 and all(cs) else None
    return (c, 'all %d callers are %s members' % (len(cs), c)) if c else (None, '')


def s_neigh(a):
    """Nearest classed function on each side (skipping unclassed ones, at most 8 away) agree."""
    i = bisect.bisect_left(starts, a)
    side = []
    for rng in (range(i - 1, max(i - 9, -1), -1), range(i + 1, min(i + 9, len(starts)))):
        side.append(next((C[starts[j]] for j in rng if C[starts[j]]), None))
    p, n = side
    return (p, 'link-order neighbours on both sides are %s' % p) if p and p == n else (None, '')


SIGNALS = [('vtable', s_vtable), ('thiscall', s_thiscall), ('callers', s_callers), ('neighbours', s_neigh)]

# validation on known-owner functions; single signals first, then pairs of signals that agree
known = [a for a in starts if C[a]]
res = {a: {n: f(a) for n, f in SIGNALS} for a in starts}
combos = [(n,) for n, _ in SIGNALS] + [(x, y) for i, (x, _) in enumerate(SIGNALS) for y, _ in SIGNALS[i + 1:]]


def infer(a, combo):
    cs = [res[a][n][0] for n in combo]
    return cs[0] if cs[0] and all(c == cs[0] for c in cs) else None


prec, good = {}, []
for combo in combos:
    got = [(infer(a, combo), C[a]) for a in known]
    got = [(x, y) for x, y in got if x]
    prec[combo] = (sum(x == y for x, y in got), len(got))
print('%-22s %7s %7s %6s' % ('signal', 'right', 'total', 'prec'))
for combo, (ok, tot) in prec.items():
    keep = tot and ok / tot >= 0.9
    if keep:
        good.append(combo)
    print('%-22s %7d %7d %5.1f%% %s' % ('+'.join(combo), ok, tot, 100 * ok / max(tot, 1), '' if keep else 'DROPPED'))

out = {}
for k in sorted(remaining):
    a = int(k, 16)
    if C.get(a):
        continue
    for combo in sorted(good, key=lambda c: -len(c)):        # confirmed pairs before singles
        c = infer(a, combo)
        if c:
            out[k] = {'class': c, 'evidence': combo[0], 'detail': '; '.join(res[a][n][1] for n in combo)
                      + (' [confirmed by %s]' % '+'.join(combo[1:]) if len(combo) > 1 else '')}
            break
(HERE / 'owner-classes.json').write_text(json.dumps(out, indent=1))
print('%d remaining considered, %d attributed' % (len(remaining), len(out)))
print(collections.Counter(v['evidence'] for v in out.values()))
for c, n in collections.Counter(v['class'] for v in out.values()).most_common(25):
    print('%4d %s' % (n, c))
