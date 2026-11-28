"""python native_addrs.py: address -> native decorated name, from the '// <addr>' comments native sources put right above
a function definition ('// 004492d0 (thiscall ret 4...)' + 'void CRenderSettings::checkProfile(bool force)'). The
decorated name is the unique native-defined symbol for Class::method (link/native_defined.json). Writes
renamed/native_addrs.json {addr: symbol}. Seconds."""
import json, re
from pathlib import Path
EXTRA_INPUTS = ['link/native_defined.json', '../native-client/layout/function-files.json']
OUTPUTS = ['renamed/native_addrs.json']
# skip when no native source / input changed since the last run (stat of ~3.6k files: well under a second)
import os as _os0, json as _j0
_ins = [p for d in ('rebuild/2008-06/native-classes', 'rebuild/2008-06/native-findings', 'rebuild/2008-06/native-findings-new', 'rebuild/2008-06/native-findings-mew')
        for p in (Path(__file__).parents[2] / d).glob('*.cpp')] + list((Path(__file__).parents[2] / 'rebuild/2008-06/native-headers').rglob('*.h')) + [Path(__file__).parent / x for x in EXTRA_INPUTS]
_sig = '%d:%.0f' % (len(_ins), max((p.stat().st_mtime for p in _ins if p.exists()), default=0))
_sf = Path(__file__).parent / ('renamed/.%s.sig' % Path(__file__).stem)
if _sf.exists() and _sf.read_text() == _sig and all((Path(__file__).parent / o).exists() for o in OUTPUTS):
    print('%s: inputs unchanged, outputs kept' % Path(__file__).name); raise SystemExit(0)
H = Path(__file__).parent
ROOT = H.parents[1]
N = json.load(open(H / 'link/native_defined.json'))
by_key = {}
for n in N:   # ?method@Class@NS@@... -> key (method, Class) ; ??0Class@ ctor -> ('??0', Class)
    m = re.match(r'^\?(\?[0-9A-Z_]|[A-Za-z_]\w*)@([A-Za-z_]\w*)@', n)
    if m:
        by_key.setdefault((m.group(1), m.group(2)), []).append(n)
by_free = {}
for n in N:   # free functions: ?name@@Y... (global namespace)
    m = re.match(r'^\?([A-Za-z_]\w*)@@Y', n)
    if m:
        by_free.setdefault(m.group(1), []).append(n)
ADDR = re.compile(r'^\s*//\s*(?:@)?([0-9a-f]{8})\b')
DEF = re.compile(r'^[\w:<>,\s\*&~]*?\b(\w+)::(~?\w+)\s*\(')
out, amb = {}, 0
# the registry's real name for an address must agree with the definition below the comment: comments also cite callees
# ('// 0055d0b0 of "Fonts\comics.fnt"' above Fonts::getFont named resolveMapPath's address getFont -> wrong alias)
REG = {a: (r.get('name') or '') for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items()}
def _agrees(a, sym):
    r = REG.get(a, '')
    if not r.startswith('?') or r == sym:
        return True
    m = re.match(r'^\?(\?[0-9A-Z_]|[A-Za-z_]\w*)@([A-Za-z_]\w*)@', sym)
    return bool(m) and r.startswith('?%s@%s@' % m.groups())
bad = 0
for f in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
    lines = f.read_text(errors='replace').splitlines()
    for i, l in enumerate(lines):
        m = ADDR.match(l)
        if not m:
            continue
        for l2 in lines[i + 1:i + 5]:
            if l2.strip().startswith('//'):
                continue
            d = DEF.match(l2)
            if d and re.match(r'\s*template\b', l2):
                break   # a template definition names no single instance (ServiceProvider::create<C> paired with create(Name))
            if d:
                cls, meth = d.group(1), d.group(2)
                key = ('?0' if meth == cls else '?1' if meth == '~' + cls else meth, cls)
                c = by_key.get(key, [])
                if len(c) == 1 and not _agrees(m.group(1), c[0]):
                    bad += 1
                elif len(c) == 1:
                    out[m.group(1)] = c[0]
                elif c:
                    amb += 1
            elif l2 is lines[i + 1] and not l2.startswith((' ', '\t')):
                # free function right below its comment ('// 0041b6f0' + 'Marshaller* acquireMarshaller()'): the unique
                # native ?name@@Y... symbol. Registry names here are often analog guesses (getThreadObject), so the
                # comment must sit directly above the definition instead of passing _agrees
                f_ = re.match(r'^[\w<>,:\s\*&]*?\b([A-Za-z_]\w*)\s*\([^;]*$', l2)
                if f_ and f_.group(1) not in ('if', 'for', 'while', 'switch', 'return'):
                    c = [n for n in by_free.get(f_.group(1), [])]
                    _r = REG.get(m.group(1), '')
                    if len(c) == 1 and (not _r.startswith('?') or _r == c[0]):   # a different REAL registry name: skip
                        out[m.group(1)] = c[0]
            break
# HEADER declarations: 'void verifyCamera();' under a comment naming its 'registry placeholder func_005a5710', or a
# trailing '// 005a0120' on the declaration line. Native code calls the real name; without this alias the converted
# func_<addr> body is never used and the call links to a stub (verifyCamera stub -> no Camera -> near clip 0 -> Ogre
# InvalidParametersException on the first frame). Placeholder registry names only: never overrides a real name.
CLS = re.compile(r'^\s*(?:class|struct)\s+(?:\w+\s+)?([A-Za-z_]\w*)\b[^;]*$')
DECL = re.compile(r'^\s*(?:virtual\s+|static\s+|inline\s+)*[\w:<>,\s\*&~]*?\b(~?[A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:const\s*)?;\s*(?://\s*([0-9a-f]{8})\b)?')
nh = 0
calls = {}   # native-referenced name -> func_<addr> (no native definition exists)
by_stub = {}
try:
    for n in json.load(open(H / 'link/stubs.json'))['functions']:
        m = re.match(r'^\?(\?[0-9A-Z_]|[A-Za-z_]\w*)@([A-Za-z_]\w*)@', n)
        if m:
            by_stub.setdefault((m.group(1), m.group(2)), []).append(n)
except (OSError, ValueError, KeyError):
    pass
for f in (ROOT / 'rebuild/2008-06/native-headers').rglob('*.h'):
    cls, pend = None, None
    for l in f.read_text(errors='replace').splitlines():
        c_ = CLS.match(l)
        if c_:
            cls, pend = c_.group(1), None
            continue
        if l.strip().startswith('//'):
            m_ = re.search(r'func_([0-9a-f]{8})', l)
            pend = m_.group(1) if m_ else pend
            continue
        d_ = DECL.match(l)
        a_ = (d_.group(2) or pend) if d_ else None
        pend = None
        if not (d_ and cls and a_) or a_ in out or REG.get(a_, '').startswith('?'):
            continue
        meth = d_.group(1)
        key = ('?0' if meth == cls else '?1' if meth == '~' + cls else meth, cls)
        c = by_key.get(key, [])
        if len(c) == 1:
            out[a_] = c[0]; nh += 1
        elif not c and len(by_stub.get(key, [])) == 1:
            calls[by_stub[key][0]] = 'func_' + a_   # declared, called natively, defined nowhere: the converted body
print('%d addresses named from native HEADER declarations; %d declared-only names aliased to their converted body'
      % (nh, len(calls)))
(H / 'renamed/native_calls.json').write_text(json.dumps(calls, indent=0, sort_keys=True))
# template instances named inline in comments: 'ServiceProvider::doGetClassIndex<LocalBackpack>() 00575630'
TI = re.compile(r'(\w+)::(\w+)<(\w+)>\s*\([^)]*\)\s+([0-9a-f]{8})\b')
tmpl = {}
for n in N:
    m = re.match(r'^\?\?\$(\w+)@V(\w+)@', n)
    if m:
        tmpl.setdefault((m.group(1), m.group(2)), []).append(n)
nt = 0
for f in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
    for m in TI.finditer(f.read_text(errors='replace')):
        cls, meth, arg, a = m.groups()
        c = [n for n in tmpl.get((meth, arg), []) if '@' + cls + '@' in n]
        if len(c) == 1 and a not in out:
            out[a] = c[0]; nt += 1
print('%d template instances named from comments' % nt)
(H / 'renamed/native_addrs.json').write_text(json.dumps(out, indent=0, sort_keys=True))
print('%d addresses named from native comments (%d ambiguous overloads skipped, %d disagree with the registry name)' % (len(out), amb, bad))
_sf.write_text(_sig)
