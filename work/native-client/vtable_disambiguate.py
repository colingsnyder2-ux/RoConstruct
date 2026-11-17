"""Disambiguate byte-identical candidates (no model, no new source).  The census ledger rows already compile a body
byte-equal to many remaining addresses, rejected only because one symbol matches several addresses (identical
destructors/accessors of different classes).  For a remaining address A held in a vtable, the code installing that
vtable (`mov [reg], vftable` in a constructor/destructor) names the owning class C; the candidate symbol whose class is
C (or one of C's names in the mangling) is A's symbol.  Writes vtable-identity-bindings.json (identity_bindings
format) for the census; the census still byte-proves every row.
  python work/native-client/vtable_disambiguate.py   (refuses while a census runs)"""
import bisect
import collections
import json
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m          # noqa: E402
from roc import match           # noqa: E402

if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
reg = m.load_registry()


def ledger_candidates():
    """remaining addr -> symbols whose compiled body the census ledger found byte-equal to it."""
    import glob
    import gzip
    remaining = set(json.loads((HERE / 'remaining-classified.json').read_text()))
    found = collections.defaultdict(set)
    for f in glob.glob(str(HERE / 'prove-out/OgreNativeFull/rows/*.json.gz')):
        for r in json.load(gzip.open(f)):
            c = r.get('candidates') or '[]'
            for a in (json.loads(c) if isinstance(c, str) else c):
                if isinstance(a, str) and a in remaining:
                    found[a].add(r['symbol'])
    return {a: sorted(v) for a, v in found.items()}


cands = ledger_candidates()
(HERE / 'ambiguous-candidates.json').write_text(json.dumps(cands, indent=1))
base, image = match._image('2008-06')
relocs = sorted(match._base_relocs('2008-06'))
starts = sorted(int(a, 16) for a in match._functions('2008-06'))
reloc_set = set(relocs)


def dw(va):
    return struct.unpack_from('<I', image, va - base)[0]


points_to = collections.defaultdict(list)          # value -> reloc sites holding it
for r in relocs:
    try:
        points_to[dw(r)].append(r)
    except struct.error:
        pass
code_lo, code_hi = starts[0], starts[-1] + 0x10000


def owner(va):
    i = bisect.bisect_right(starts, va) - 1
    return '%08x' % starts[i] if i >= 0 else None


def vtable_start(slot):
    """Walk back over contiguous relocated code pointers to the first slot (vtables are runs of code pointers)."""
    # No RTTI pointer separates adjacent vtables here, so stop at the nearest slot code references (an installer's
    # `mov [reg], offset vftable`), not at the start of the whole run of code pointers.
    s = slot
    while True:
        if any(code_lo <= r < code_hi for r in points_to.get(s, ())):
            return s
        if not (s - 4 in reloc_set and code_lo <= dw(s - 4) < code_hi):
            return s
        s -= 4


def classes_in(symbol):
    """Leaf class names mentioned by an MSVC-mangled member symbol (`??1ShootTool@RBX@@` -> {'ShootTool'})."""
    body = symbol.lstrip('?')
    body = re.sub(r'^(?:_[0-9A-Z]|[0-9])', '', body)       # ??0 ctor, ??1 dtor, ??_G/_E deleting dtors
    parts = [p for p in re.split(r'@', body.split('@@')[0]) if p]
    out = set()
    for p in parts:
        p = p.lstrip('?$')
        if re.fullmatch(r'[A-Za-z_]\w*', p):
            out.add(p)
    return out


from roc import integration_site                                   # noqa: E402
EXACT = {a: v[0] for a, v in integration_site.inactive_code(HERE.parents[1]).items() if v[1]}
INTEGRATED = {}
try:
    INTEGRATED = {a: r for a, r in m.load_registry().items() if False}
except Exception:                                                  # noqa: BLE001
    pass

# Reverse call graph: rel32 `call`/`jmp` targets are not relocations, so scan each function body for E8/E9.
callers = collections.defaultdict(set)
for i, start in enumerate(starts[:-1]):
    end = min(starts[i + 1], start + 0x4000)
    body = image[start - base:end - base]
    for j in range(len(body) - 4):
        if body[j] in (0xE8, 0xE9):
            tgt = (start + j + 5 + struct.unpack_from('<i', body, j + 1)[0]) & 0xffffffff
            if code_lo <= tgt < code_hi:
                callers[tgt].add('%08x' % start)


def first_class(name):
    """Owning class of an MSVC member symbol: `??0X@`/`??1X@`/`??_GX@` -> X, `?f@X@RBX@@` -> X."""
    hit = re.match(r'\?\?(?:[01]|_[GE])(\w+)@', name) or re.match(r'\?\w+@(\w+)@', name)
    return hit.group(1) if hit else None


INSTALLERS = set()          # full names of the vtable installers / exact callers seen for the current address


def template_pick(symbols, names):
    """Template owners (`??__F?creator@?$FactoryProduct@VSkin@RBX@@...`) have no plain class name: pick the candidate
    sharing the longest prefix after the first `?$Name@` with an installer name; unique maximum, ending on `@@`."""
    best, ties, length = None, 0, 0
    for n in names:
        if '?$' not in n:
            continue
        tail = n.split('?$', 1)[1]
        for cand in symbols:
            if '?$' not in cand:
                continue
            ct = cand.split('?$', 1)[1]
            k = 0
            while k < min(len(ct), len(tail)) and ct[k] == tail[k]:
                k += 1
            k = ct.rfind('@@', 0, k) + 2 if '@@' in ct[:k] else 0  # whole template-argument list, not a partial name
            if k > length:
                best, ties, length = cand, 1, k
            elif k == length and k and cand != best:
                ties += 1
    return best if ties == 1 and length > 8 else None


REG_COUNT = collections.Counter((r or {}).get('name') for r in reg.values())


def installer_name(fn):
    """A registry name unique to FN beats the census-credited symbol: identical-body stubs (`??__F` creator atexit
    dtors) are credited to one twin's name, while the registry's unique name comes from the address's own evidence."""
    name = (reg.get(fn) or {}).get('name') or ''
    if name and REG_COUNT[name] == 1 and not name.startswith(('func_', 'sub_')):
        return name
    return EXACT.get(fn) or name


def class_of_installer(fn, top=False):
    if top and installer_name(fn):                                    # direct vtable installers only
        INSTALLERS.add(installer_name(fn))
    if first_class(installer_name(fn) or ''):
        return first_class(installer_name(fn))
    sig = ((reg.get(fn) or {}).get('signature') or '')
    name = (reg.get(fn) or {}).get('name') or ''
    hit = re.search(r'__thiscall ((?:\w+::)*)(\w+)::~?(\w+)\(', sig)
    if hit and hit.group(2) == hit.group(3):              # constructor or destructor of class hit.group(2)
        return hit.group(2)
    hit = re.match(r'\?\?[01](\w+)@', name)
    return hit.group(1) if hit else None


out, stat = [], collections.Counter()
def owners_of(a, depth=2, seen=None):
    """Classes owning A: vtable installers, else exact callers' classes, else (depth) the owners of its callers."""
    seen = seen if seen is not None else set()
    if a in seen:
        return set()
    seen.add(a)
    owners = set()
    for slot in points_to.get(a, []):
        if code_lo <= slot < code_hi:                     # absolute operand in code, not a vtable slot
            continue
        vt = vtable_start(slot)
        for ref in points_to.get(vt, []):
            if code_lo <= ref < code_hi:
                cls = class_of_installer(owner(ref), top=(depth == 2))
                if cls:
                    owners.add(cls)
    if owners:
        return owners
    for c in callers.get(a, ()):
        if c in EXACT:
            cls = first_class(EXACT[c])
            if cls:
                owners.add(cls)
        elif depth:
            owners |= owners_of(int(c, 16), depth - 1, seen)
    return owners


for addr, symbols in cands.items():
    a = int(addr, 16)
    INSTALLERS.clear()
    owners = owners_of(a)
    if not owners and not INSTALLERS:
        stat['no-owner'] += 1
        continue
    pick = [s for s in symbols if classes_in(s) & owners]
    if len(pick) != 1:
        t = template_pick(symbols, INSTALLERS)
        if t:
            pick, owners = [t], {'template prefix of ' + sorted(INSTALLERS)[0][:80]}
            stat['template-prefix'] += 1
    if len(pick) == 1:
        stat['resolved'] += 1
        out.append({'symbol': pick[0], 'address': addr, 'votes': 1,
                    'identity_evidence': 'vtable installed by %s code; ledger body byte-equal' % '/'.join(sorted(owners))})
    else:
        stat['ambiguous-%d' % min(len(pick), 2)] += 1
used = collections.Counter(b['symbol'] for b in out)        # one symbol picked for two addresses proves neither
out = [b for b in out if used[b['symbol']] == 1]
stat['dropped-shared-pick'] = sum(v for v in used.values() if v > 1)
print(dict(stat))
(HERE / 'vtable-identity-bindings.json').write_text(json.dumps(
    {'scope': 'identity evidence only: vtable owner class picks among byte-equal ledger candidates (vtable_disambiguate.py)',
     'sources': {}, 'identity_bindings': out}, indent=1))
print('wrote %d bindings' % len(out), out[:3])
