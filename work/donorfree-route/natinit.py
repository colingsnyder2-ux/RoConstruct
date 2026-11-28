"""python natinit.py: pair ORIGINAL static globals with the NATIVE globals that replace them, by the string literals
their initializers push. Converted code used dat_00976b7c / dat_00976b94 copies of ScriptContext::propScriptsDisabled
(the native one is linked and constructed): the copy was never constructed -> DataModel::clearContents read a null
member (+0x18) on Reset.
Original side: auto/initscan.json {global: {initializer, literals}}. Native side: every ??__E<S>@@YAXXZ in our link,
string literals it pushes. A unique equal literal tuple pairs A -> S. Every dat_X placeholder with A <= X < A + size(S)
becomes S + (X - A): writes auto/natinit_plan.json {dat_X: [S, offset]}; quicktest patches the referencing objects."""
import collections, json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000


def cstr(img, va):
    try:
        b = bytes(img[va - B:va - B + 80])
    except Exception:
        return None
    s = b.split(b'\0')[0]
    return s.decode('latin-1') if 2 <= len(s) < 80 and all(32 <= c < 127 for c in s) else None


rows, names = [], {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            rows.append((v, p[1], p[-1])); names.setdefault(p[1], (v, p[-1]))
rows.sort()
starts = sorted({v for v, _, _ in rows})
nat = collections.defaultdict(list)   # literal tuple -> [S]
for v, n, ob in rows:
    m = re.fullmatch(r'\?\?__E(\?.+)@@YAXXZ', n)
    if not m or re.fullmatch(r'(?:(?:ca|cf|dr|nx)_)*[0-9a-f]{8}\.obj', ob) or 'stubs' in ob:
        continue
    lits = []
    for ins in md.disasm(bytes(q[v - B:v - B + 0x200]), v):
        if ins.mnemonic in ('push', 'mov') and '0x' in ins.op_str:
            for h in re.findall(r'0x[0-9a-f]{6,}', ins.op_str):
                s = cstr(q, int(h, 16))
                if s:
                    lits.append(s)
        if ins.mnemonic in ('ret', 'int3'):
            break
    if lits:
        nat[tuple(lits)].append(m.group(1))
scan = json.loads((H / 'auto/initscan.json').read_text())
def literal_matches_symbol(literals, symbol):
    if not literals:
        return True
    literal = max(literals, key=len)
    if len(literal) < 4:
        return True
    normalize = lambda s: re.sub(r'[^a-z0-9]', '', s.lower())
    return normalize(literal) in normalize(symbol)

pair = {}
for A, v in scan.items():
    lt = tuple(v.get('literals') or ())
    if lt and len(nat.get(lt, [])) == 1 and nat[lt][0] in names and literal_matches_symbol(lt, nat[lt][0]):
        pair[int(A, 16)] = nat[lt][0]
# name pairing: the original global's registry name IS the native global's name and a native dynamic initializer
# constructs it (_prop_profileName at 0x96d514: converted CRenderSettings reset read dat_0096d52c = +0x18, a zero copy
# -> null manager on File->New). Literal pairing alone found 3 of these.
_real = {}
for v, n, ob in rows:
    if 'stubs' not in ob:
        _real.setdefault(n, (v, ob))
_natinit = set()
for n, (v, ob) in _real.items():
    m = re.fullmatch(r'\?\?__E(.+)@@YAXXZ', n)
    if m and not re.fullmatch(r'(?:(?:ca|cf|dr|nx)_)*[0-9a-f]{8}\.obj', ob):
        g = m.group(1)
        _natinit.add(g if g.startswith('?') else '_' + g)
_reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
_npair = 0
for a_, v_ in _reg.items():
    n_ = (v_ or {}).get('name')
    A_ = int(a_, 16)
    if n_ and n_ in _natinit and n_ in _real and 0x802000 <= A_ < 0x9a0000 and A_ not in pair:
        pair[A_] = n_; _npair += 1
# function-local statics (?foo@?1??classDescriptor@...@4V...A) and their guards (??_B?1??...): no initializer, but the
# registry name IS the native COMDAT's name. Converted code used dat_ copies of them -> a second ClassDescriptor per
# class (HtmlWindow, NetworkServer... twice; Part attached to the other copy) -> Insert Object grew a vector it iterated.
_nfl = 0
for a_, v_ in _reg.items():
    n_ = (v_ or {}).get('name')
    A_ = int(a_, 16)
    if n_ and ('@?1??' in n_ or '@?2??' in n_ or n_.startswith('??_B?')) and n_ in _real and 0x802000 <= A_ < 0x9a0000 and A_ not in pair:
        pair[A_] = n_; _nfl += 1
print('natinit: name-paired function-local statics/guards: %d' % _nfl)
names.update({n: _real[n] for n in set(pair.values()) if n in _real})   # the native definition, not a stub copy
print('natinit: name-paired native-initialized globals: %d' % _npair)
# extent of each native global: up to the next symbol in our image
plan = {}
stubs = sorted(int(n[4:], 16) for n, (v, ob) in names.items() if re.fullmatch(r'dat_[0-9a-f]{8}', n) and 'stubs' in ob)
import bisect
for A, S in pair.items():
    sv = names[S][0]
    j = bisect.bisect_right(starts, sv)
    size = min((starts[j] - sv) if j < len(starts) else 0x40, 0x200)
    # Clamp extent to real struct size (starts[j]-sv includes alignment padding that can swallow the next global, e.g. prop_SkyFt+28 -> Sky::classDescriptor)
    if '??_B' in S or 'flag@' in S:
        size = min(size, 4)
    elif 'BoundProp' in S or 'RefPropDescriptor' in S:
        size = min(size, 28)
    elif 'EnumPropDescriptor' in S:
        size = min(size, 36)
    elif 'SignalDesc' in S:
        size = min(size, 52)
    elif 'FillToolColor' in S:
        size = min(size, 32)
    i = bisect.bisect_left(stubs, A)
    while i < len(stubs) and stubs[i] < A + size:
        plan['dat_%08x' % stubs[i]] = [S, stubs[i] - A]
        i += 1
pf = H / 'auto/natinit_plan.json'
prev = json.loads(pf.read_text()) if pf.exists() else {}
prev.update(plan)
prev = {a: v for a, v in prev.items() if literal_matches_symbol(
    scan.get('%08x' % (int(a[4:], 16) - v[1]), {}).get('literals', []), v[0])}
pf.write_text(json.dumps(prev, indent=0))
print('natinit: native initializers with literals %d, original globals paired %d, dat_ placeholders rebound %d (total %d)'
      % (sum(len(x) for x in nat.values()), len(pair), len(plan), len(prev)))
print('  dat_00976b7c ->', prev.get('dat_00976b7c'), ' dat_00976b94 ->', prev.get('dat_00976b94'))
