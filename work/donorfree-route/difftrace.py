"""python difftrace.py [secs]: run the ORIGINAL exe and ours under the same one-shot entry breakpoints (functions whose bodies
are identical in both: auto/bodymatch.json pairs, File->New-reachable first) with the same File->New command, and print
the first point where the first-call order diverges. One run pair finds the first wrong behaviour, not one crash."""
import json, os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
secs = sys.argv[1] if len(sys.argv) > 1 else '40'
OURS_EXE = os.environ.get('DT_EXE', str(H / 'run/RobloxQT.exe'))
OURS_MAP = os.environ.get('DT_MAP', str(H / 'linkexp/qt.map'))
# original address -> OUR address of the same function, from the CURRENT link: its converted symbol, else its
# native_addrs name (was: auto/bodymatch.json pairs of the retired donorfree link)
_ren = json.load(open(H / 'renamed/rename.json'))
_na = json.load(open(H / 'renamed/native_addrs.json')) if (H / 'renamed/native_addrs.json').exists() else {}
_ma = {}
for _l in open(OURS_MAP, errors='replace'):
    _p = _l.split()
    if len(_p) >= 4 and ':' in _p[0] and 'stubs' not in _p[-1]:
        try:
            _ma.setdefault(_p[1], int(_p[2], 16))
        except ValueError:
            pass
pairs = {}
for _a in set(_ren) | set(_na):
    _s = (_ren.get(_a) or {}).get('symbol') if (_ren.get(_a) or {}).get('status') == 'renamed' else None
    _v = _ma.get(_s) or _ma.get(_na.get(_a)) or _ma.get('func_' + _a)
    if _v:
        pairs[_a] = '%08x' % _v
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
om = H / 'auto/orig.map'
if not om.exists():
    om.write_text(' Preferred load address is 00400000\n' + ''.join(
        ' 0001:%08x       %s %s f   orig.obj\n' % (int(a, 16) - 0x401000, ((v or {}).get('name') or 'fn_' + a).replace(' ', '_'), a)
        for a, v in sorted(ff.items())))
try:
    reach = {r['addr'] for r in json.load(open(H / 'auto/reach.json'))}
except Exception:
    reach = set()
# original list is build-independent (reachable functions, fixed order): its trace is cached once; ours uses the pairs
osel = sorted(reach)[:int(os.environ.get('DT_MAX', '6000'))]
sel = [a for a in osel if a in pairs]
(H / 'auto/dt_orig.txt').write_text(''.join('%s %s\n' % (a, a) for a in osel))
(H / 'auto/dt_ours.txt').write_text(''.join('%s %s\n' % (pairs[a], a) for a in sel))
def run(exe, mp, bl, out):
    env = dict(os.environ, ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD='0xE100', BPLIST=str(bl),
               BPIMP='_invalid_parameter_noinfo,_purecall,abort')
    env.pop('BPSTUBS', None)
    r = subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), exe, str(mp), secs], env=env,
                       capture_output=True, text=True, cwd=H)
    (H / out).write_text(r.stdout + r.stderr)
    return [l.split()[2] for l in r.stdout.splitlines() if l.startswith('STUB HIT ')], r.stdout
import hashlib
_key = hashlib.md5(((H / 'auto/dt_orig.txt').read_text() + secs).encode()).hexdigest()
_cf = H / 'auto/dt_orig.cache.json'   # the original's trace never changes for the same breakpoint list: run it once
try:
    _c = json.load(open(_cf))
    assert _c['key'] == _key
    a, ta = _c['a'], _c['t']
except Exception:
    a, ta = run(str(H / 'run/RobloxOrig.exe'), om, H / 'auto/dt_orig.txt', 'auto/dt_orig.out')
    json.dump({'key': _key, 'a': a, 't': ta}, open(_cf, 'w'))
b, tb = run(OURS_EXE, OURS_MAP, H / 'auto/dt_ours.txt', 'auto/dt_ours.out')
_ss = set(sel)
a = [x for x in a if x in _ss]   # compare only functions both runs watch
k = next((i for i in range(min(len(a), len(b))) if a[i] != b[i]), min(len(a), len(b)))
nm = lambda x: ((ff.get(x) or {}).get('name') or 'fn_' + x)[:70]
print('first-call trace: original %d functions, ours %d; identical prefix %d' % (len(a), len(b), k))
for i in range(max(0, k - 4), min(k + 6, max(len(a), len(b)))):
    print('%4d %s %-62s | %s %s' % (i, '  ' if i < k else '!!', nm(a[i]) if i < len(a) else '-', b[i] if i < len(b) else '-', nm(b[i])[:40] if i < len(b) else ''))
_sb = set(b)
missing = [x for x in a if x not in _sb]
print('called in original, never in ours: %d  first: %s' % (len(missing), ', '.join(nm(x)[:40] for x in missing[:6])))
for t in (tb,):
    m = re.search(r'^(exception .*|ENTRY hit.*|process exited.*)$', t, re.M)
    print('ours ends:', m.group(1)[:120] if m else 'ran to time limit')
