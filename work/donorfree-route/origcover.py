"""python origcover.py [secs]: the COMPLETE list of functions our build is missing on the startup + File->New path, in
one run instead of one crash per relink. Every function our current link resolves to a STUB is mapped back to its
original address (func_X -> X; named stubs via the registry or converted callers' refs), armed as a one-shot entry
breakpoint in the ORIGINAL exe (run/RobloxOrig.exe), and File->New is posted. Every hit = a function the real client
runs there that ours only has as a placeholder. Writes auto/origcover.json [{addr, stub, kind}] in first-call order and
prints a summary by fix kind. The trace depends only on the breakpoint set: re-run after a relink to see what is left."""
import json, os, re, subprocess, sys
from collections import Counter
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
secs = next((x for x in sys.argv[1:] if x.isdigit()), '45')
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
ren = json.loads((H / 'renamed/rename.json').read_text())
byname = {}
for a, v in reg.items():
    n = (v or {}).get('name')
    if n:
        byname.setdefault(n, set()).add(a)
refaddr = {}
for x in ren.values():
    for k, v in (x.get('refs') or {}).items():
        if not k.startswith(('collide:', 'split:', 'rebound:')):
            refaddr.setdefault(k, set()).add(v)
code_seg = set()
stubs = []
txt = (H / 'linkexp/qt.map').read_text(errors='replace')
code_seg = set(re.findall(r'^\s*([0-9a-f]{4}):[0-9a-f]{8}\s+[0-9a-f]+H\s+\S+\s+CODE\s*$', txt, re.M)) or {'0001'}
for m in re.finditer(r'^\s*([0-9a-f]{4}):[0-9a-f]{8}\s+(\S+)\s+[0-9a-f]{8}(?: f)?(?: i)?\s+\S*stubs\d?\.obj\s*$', txt, re.M):
    if m.group(1) in code_seg:
        stubs.append(m.group(2))
orig = {}   # original address -> our stub name
for s in stubs:
    mm = re.match(r'^_?func_([0-9a-f]{8})$', s)
    cand = {mm.group(1)} if mm else (byname.get(s, set()) if len(byname.get(s, ())) == 1 else refaddr.get(s, set()))
    if len(cand) == 1:
        a = next(iter(cand))
        if a in ff and 0x401000 <= int(a, 16) < 0x7c0000:   # code addresses only
            orig.setdefault(a, s)
if '--all' in sys.argv:
    # COMPLETE mode: every original function with no real body in our link, whatever our placeholder is called (the
    # name-based mapping above reached only 1571 of 42k stubs). Real = its converted object is linked, or a
    # non-stub definition owns its registry / native_addrs name, or it is an import thunk (jmp [IAT]).
    import pefile as _pf
    _o = _pf.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    _oi = _o.get_memory_mapped_image()
    _own = {}
    for _l in txt.splitlines():
        _p = _l.split()
        if len(_p) >= 4 and ':' in _p[0]:
            _own.setdefault(_p[1], _p[-1])
    _linked = {o_[:-4] for o_ in set(_own.values()) if re.fullmatch(r'[0-9a-f]{8}\.obj', o_)}
    _na = json.loads((H / 'renamed/native_addrs.json').read_text()) if (H / 'renamed/native_addrs.json').exists() else {}
    _real = lambda n_: bool(n_) and n_ in _own and 'stubs' not in _own[n_]
    orig = {}
    for a, v in ff.items():
        va = int(a, 16)
        if not 0x401000 <= va < 0x7c0000 or a in _linked:
            continue
        if _oi[va - 0x400000:va - 0x400000 + 2] == b'\xff\x25':
            continue   # import thunk: resolves to the import
        n_ = (v or {}).get('name') or ''
        if _real(n_) or _real(_na.get(a)) or _real('func_' + a):
            continue
        orig[a] = n_ or ('func_' + a)
bl = H / 'auto/origcover_bp.txt'
bl.write_text(''.join('%s %s\n' % (a, a) for a in sorted(orig)))
om = H / 'auto/orig.map'
if not om.exists():
    om.write_text(' Preferred load address is 00400000\n' + ''.join(
        ' 0001:%08x       %s %s f   orig.obj\n' % (int(a, 16) - 0x401000, ((v or {}).get('name') or 'fn_' + a).replace(' ', '_'), a)
        for a, v in sorted(ff.items())))
print('stubs in our link: %d; mapped to an original code address: %d (armed in the original exe)' % (len(stubs), len(orig)))
env = dict(os.environ, ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD='0xE100', BPLIST=str(bl),
           PROBE_IDLE='12')
env.pop('BPSTUBS', None)
r = subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxOrig.exe'), str(om), secs],
                   env=env, capture_output=True, text=True, cwd=H, errors='replace')
(H / 'auto/origcover.out').write_text(r.stdout + r.stderr)
hits = []
for l in r.stdout.splitlines():
    if l.startswith('STUB HIT '):
        a = l.split()[2]
        if a in orig and a not in hits:
            hits.append(a)
conv = {a for a, x in ren.items() if (x or {}).get('status') == 'renamed'}
nat = set(json.loads((H / 'renamed/native_addrs.json').read_text()).keys()) if (H / 'renamed/native_addrs.json').exists() else set()


def kind(a, s):
    if a in conv:
        return 'converted object exists, not linked/aliased (binding fix)'
    if a in nat:
        return 'native body exists (alias fix)'
    if s.startswith('??$') or '?$' in s:
        return 'template member (tmplinst / LLM)'
    return 'no body anywhere (LLM worker draft)'


out = [dict(addr=a, stub=orig[a], name=((ff.get(a) or {}).get('name') or ''), kind=kind(a, orig[a])) for a in hits]
(H / 'auto/origcover.json').write_text(json.dumps(out, indent=1))
end = next((l for l in reversed(r.stdout.splitlines()) if re.match(r'^(exception|process exited|no crash|crash after)', l)), '?')
print('original run: %d of our stubs are REAL functions on this path (auto/origcover.json); original ended: %s' % (len(hits), end[:90]))
for k, n in Counter(o['kind'] for o in out).most_common():
    print('  %4d  %s' % (n, k))
for o in out[:15]:
    print('  %s %-60s %s' % (o['addr'], o['stub'][:60], o['kind'][:30]))
