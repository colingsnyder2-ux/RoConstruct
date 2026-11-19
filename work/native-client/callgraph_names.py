"""Attribute unnamed remaining 2008-06 functions to owner classes from call-graph/Ghidra evidence.
Signals are validated on functions with known owners; only combos with >=90% precision are used.
  python work/native-client/callgraph_names.py -> work/native-client/callgraph-names.json"""
import bisect, collections, json, re, sqlite3, struct, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m          # noqa: E402
from roc import match, integration_site   # noqa: E402

DB = 'C:/Users/colin/RBXBanland/work/re/rbx2008m.db'
reg = m.load_registry()
base, image = match._image('2008-06')
relocs = sorted(match._base_relocs('2008-06'))
reloc_set = set(relocs)
starts = sorted(int(a, 16) for a in match._functions('2008-06'))
code_lo = starts[0]
code_hi = starts[-1] + len(match.target('2008-06', '%08x' % starts[-1])[0])
EXACT = {a: v[0] for a, v in integration_site.inactive_code(HERE.parents[1]).items() if v[1]}
rc = json.loads((HERE / 'remaining-classified.json').read_text())
targets = {k for k, v in rc.items() if v.get('bucket') == 'unnamed (identity session)'} - set(EXACT)


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


def _cls(a):
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


def cls(a):
    c = _cls(a)
    return c if c and re.fullmatch(r'[A-Za-z_]\w*', c) else None


C = {a: cls(a) for a in starts}
KNOWN = {a for a in starts if C[a]}
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

# Ghidra text
db = sqlite3.connect('file:%s?mode=ro' % DB, uri=True)
dec = {int(a, 16): d or '' for a, d in db.execute(
    "select addr,decompiled from functions where program='RobloxApp_client.exe'")}
CLASSES = {c for c in C.values() if c and len(c) >= 5}
this_call = re.compile(r'\b(?:FUN|thunk_FUN)_([0-9a-f]{8})\((?:\([\w\s\*]+\))?(?:param_1|this)\s*[,)]')
data_re = re.compile(r'\bDAT_([0-9a-f]{8})\b')
str_re = re.compile(r'"((?:[^"\\]|\\.){4,})"|\bs_(\w+?)_[0-9a-f]{8}\b')
ids = {c: re.compile(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(c)) for c in CLASSES}
file_re = re.compile(r'(\w+)\.(?:cpp|h)\b')

G = collections.defaultdict(set)            # data global -> functions using it
for a, t in dec.items():
    for g in set(data_re.findall(t)):
        G[g].add(a)


def uniq(cs):
    cs = {c for c in cs if c}
    return next(iter(cs)) if len(cs) == 1 else None


def s_vtable(a):
    cs, n = set(), 0
    for slot in points_to.get(a, []):
        if code_lo <= slot < code_hi:
            continue
        for ref in points_to.get(vtable_start(slot), []):
            if code_lo <= ref < code_hi:
                n += 1
                cs.add(C.get(owner(ref)))
    return (uniq(cs), 'vtable installed by %d site(s)' % n) if n else (None, '')


def s_thiscall(a):
    cs = [C.get(c) for c in this_callers.get(a, ())]
    c = uniq(cs) if cs and all(cs) else None
    return (c, 'ecx unchanged from %d member caller(s)' % len(cs)) if c else (None, '')


def s_callers(a):
    cs = [C.get(c) for c in callers.get(a, ())]
    c = uniq(cs) if len(cs) >= 2 and all(cs) else None
    return (c, 'all %d callers are %s' % (len(cs), c)) if c else (None, '')


def s_neigh(a):
    i = bisect.bisect_left(starts, a)
    side = [next((C[starts[j]] for j in rng if C[starts[j]]), None)
            for rng in (range(i - 1, max(i - 9, -1), -1), range(i + 1, min(i + 9, len(starts))))]
    return (side[0], 'link-order neighbours') if side[0] and side[0] == side[1] else (None, '')


def callee_votes(a):
    return collections.Counter(C.get(int(h, 16)) for h in set(this_call.findall(dec.get(a, '')))
                               if int(h, 16) != a and C.get(int(h, 16)))


def s_callee_all(a):
    v = callee_votes(a)
    return (next(iter(v)), 'passes this to %d %s method(s)' % (sum(v.values()), next(iter(v)))) if len(v) == 1 else (None, '')


def s_callee_maj(a):
    v = callee_votes(a)
    if sum(v.values()) >= 3:
        c, n = v.most_common(1)[0]
        if n / sum(v.values()) > 0.6:
            return c, 'passes this to %d/%d %s method(s)' % (n, sum(v.values()), c)
    return None, ''


def s_string(a):
    t = dec.get(a, '')
    hits = set()
    for lit, sname in str_re.findall(t):
        s = lit or sname
        for c, rx in ids.items():
            if rx.search(s):
                hits.add(c)
        for f in file_re.findall(s):
            if f in CLASSES:
                hits.add(f)
    c = uniq(hits)
    return (c, 'string literal names %s' % c) if c else (None, '')


def s_callers2(a):
    """Callers' owner by direct classification, else by *their* callers (2 levels); all must agree."""
    cs = set()
    for p in callers.get(a, ()):
        c = C.get(p)
        if not c:
            gp = [C.get(q) for q in callers.get(p, ()) if q != a]
            c = uniq(gp) if len(gp) >= 2 and all(gp) else None
        if not c:
            return None, ''
        cs.add(c)
    c = uniq(cs)
    return (c, '2-level caller chain all %s' % c) if c and len(callers.get(a, ())) >= 2 else (None, '')


def s_data(minusers):
    def f(a):
        cs = collections.Counter()
        n = 0
        for g in set(data_re.findall(dec.get(a, ''))):
            users = G[g] - {a}
            kc = [C.get(u) for u in users if C.get(u)]
            if len(kc) >= minusers and len(set(kc)) == 1 and len(users) <= 12:
                cs[kc[0]] += 1
                n = len(kc)
        if len(cs) == 1:
            return next(iter(cs)), 'shares static data with %d known %s fn(s)' % (n, next(iter(cs)))
        return None, ''
    return f


SIGNALS = [('vtable', s_vtable), ('thiscall', s_thiscall), ('callers', s_callers), ('neighbours', s_neigh),
           ('callee_all', s_callee_all), ('callee_maj', s_callee_maj), ('string', s_string),
           ('callers2', s_callers2), ('data1', s_data(1)), ('data2', s_data(2))]
names = [n for n, _ in SIGNALS]
cand = [a for a in starts if a in KNOWN or '%08x' % a in targets]
res = {a: {n: f(a) for n, f in SIGNALS} for a in cand}
combos = [(n,) for n in names] + [(x, y) for i, x in enumerate(names) for y in names[i + 1:]]


def infer(a, combo):
    cs = [res[a][n][0] for n in combo]
    return cs[0] if cs[0] and all(c == cs[0] for c in cs) else None


good = []
print('%-28s %6s %6s %6s %8s' % ('signal', 'right', 'total', 'prec', 'targets'))
for combo in combos:
    got = [(infer(a, combo), C[a]) for a in cand if a in KNOWN]
    got = [(x, y) for x, y in got if x]
    ok = sum(x == y for x, y in got)
    nt = sum(1 for a in cand if '%08x' % a in targets and infer(a, combo))
    keep = len(got) >= 10 and ok / len(got) >= 0.9
    if keep:
        good.append(combo)
    if got:
        print('%-28s %6d %6d %5.1f%% %8d %s' % ('+'.join(combo), ok, len(got), 100 * ok / len(got), nt, '' if keep else 'DROPPED'))

out = {}
for k in sorted(targets):
    a = int(k, 16)
    if C.get(a):
        continue
    for combo in sorted(good, key=lambda c: (-len(c), c)):
        c = infer(a, combo)
        if c:
            out[k] = {'class': c, 'evidence': '+'.join(combo),
                      'detail': '; '.join(res[a][n][1] for n in combo)}
            break
(HERE / 'callgraph-names.json').write_text(json.dumps(out, indent=1))
print('%d targets, %d attributed' % (len(targets), len(out)))
print(collections.Counter(v['evidence'] for v in out.values()).most_common())
for c, n in collections.Counter(v['class'] for v in out.values()).most_common(20):
    print('%4d %s' % (n, c))
