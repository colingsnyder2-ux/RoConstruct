"""python difftest.py [secs]: function-level differential test, original exe vs the current build (run/RobloxQT.exe).
Both run File->New under the same one-shot entry breakpoints (functions reachable in the original, paired with ours by
name: func_<addr> or the registry name) and BPRET return breakpoints. Reports the first divergence in first-call order
and every function whose FIRST return value differs while both values are small (bools, counts, enums, HRESULTs:
pointers differ between processes). A differing result points at the wrong function before anything crashes.
Original trace cached (auto/dtest_orig.cache.json). Output auto/difftest.json."""
import hashlib, json, os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
secs = sys.argv[1] if len(sys.argv) > 1 else '40'


def snapshot(tag):
    """Copy run/RobloxQT.exe + linkexp/qt.map to stable names (the main loop relinks them every few minutes); retry until
    the map's 'Timestamp is' equals the PE TimeDateStamp, so breakpoints never come from another link's map."""
    import shutil, struct, time
    for _ in range(30):
        if os.environ.get('PROBE_EXE'):   # a fixed pair (e.g. run/RobloxStable.exe + .map): used as is, no copy
            return Path(os.environ['PROBE_EXE']).resolve(), Path(os.environ['PROBE_MAP']).resolve()
        shutil.copyfile(H / 'run/RobloxQT.exe', H / ('run/RobloxQT_%s.exe' % tag))
        shutil.copyfile(H / 'linkexp/qt.map', H / ('auto/%s.map' % tag))
        d = (H / ('run/RobloxQT_%s.exe' % tag)).read_bytes()[:4096]
        ts = struct.unpack_from('<I', d, struct.unpack_from('<I', d, 0x3c)[0] + 8)[0]
        m = re.search(r'Timestamp is ([0-9a-f]+)', (H / ('auto/%s.map' % tag)).read_text(errors='replace')[:3000])
        if m and int(m.group(1), 16) == ts:
            return H / ('run/RobloxQT_%s.exe' % tag), H / ('auto/%s.map' % tag)
        time.sleep(10)
    raise SystemExit('exe and map never matched (relink in progress?)')
EXE, MAP = snapshot('dtest')
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
om = H / 'auto/orig.map'
if not om.exists():
    om.write_text(' Preferred load address is 00400000\n' + ''.join(
        ' 0001:%08x       %s %s f   orig.obj\n' % (int(a, 16) - 0x401000, ((v or {}).get('name') or 'fn_' + a).replace(' ', '_'), a)
        for a, v in sorted(ff.items())))
ours = {}
for l in MAP.read_text(errors='replace').splitlines():
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and re.fullmatch(r'[0-9a-f]{8}', p[2]) and not p[-1].lower().endswith('stubs.obj'):
        ours.setdefault(p[1], p[2])
try:
    reach = sorted({r['addr'] for r in json.load(open(H / 'auto/reach.json'))})
except Exception:
    reach = sorted(ff)
osel = reach[:int(os.environ.get('DT_MAX', '6000'))]
pairs = {}
for a in osel:
    for n in ('func_' + a, (ff.get(a) or {}).get('name') or ''):
        if n in ours:
            pairs[a] = ours[n]; break
(H / 'auto/dtest_orig.txt').write_text(''.join('%s %s\n' % (a, a) for a in osel))
(H / 'auto/dtest_ours.txt').write_text(''.join('%s %s\n' % (pairs[a], a) for a in osel if a in pairs))


def run(exe, mp, bl, out):
    env = dict(os.environ, ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD='0xE100', BPLIST=str(bl),
               BPRET='1', PROBE_IDLE='10', BPIMP='_invalid_parameter_noinfo,_purecall,abort')
    env.pop('BPSTUBS', None)
    r = subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), exe, str(mp), secs], env=env,
                       capture_output=True, text=True, cwd=H)
    (H / out).write_text(r.stdout + r.stderr)
    order = [l.split()[2] for l in r.stdout.splitlines() if l.startswith('STUB HIT ')]
    rets = {}
    for l in r.stdout.splitlines():
        m = re.match(r'RET (\S+) ([0-9a-f]{8})', l)
        if m:
            rets.setdefault(m.group(1), int(m.group(2), 16))
    return order, rets


key = hashlib.md5(((H / 'auto/dtest_orig.txt').read_text() + secs).encode()).hexdigest()
cf = H / 'auto/dtest_orig.cache.json'
try:
    c = json.load(open(cf)); assert c['key'] == key
    a, ra = c['a'], c['r']
except Exception:
    a, ra = run(str(H / 'run/RobloxOrig.exe'), om, H / 'auto/dtest_orig.txt', 'auto/dtest_orig.out')
    json.dump({'key': key, 'a': a, 'r': ra}, open(cf, 'w'))
b, rb = run(str(EXE), MAP, H / 'auto/dtest_ours.txt', 'auto/dtest_ours.out')
both = set(pairs)
a = [x for x in a if x in both]
k = next((i for i in range(min(len(a), len(b))) if a[i] != b[i]), min(len(a), len(b)))
nm = lambda x: ((ff.get(x) or {}).get('name') or 'fn_' + x)[:70]
small = lambda v: v < 0x10000 or v > 0xffff0000
diff = [(x, ra[x], rb[x]) for x in a if x in ra and x in rb and small(ra[x]) and small(rb[x]) and ra[x] != rb[x]]
print('first-call order: original %d, ours %d, identical prefix %d' % (len(a), len(b), k))
for i in range(max(0, k - 3), min(k + 4, max(len(a), len(b)))):
    print('%5d %s %-60s | %s' % (i, '  ' if i < k else '!!', nm(a[i]) if i < len(a) else '-', nm(b[i])[:50] if i < len(b) else '-'))
print('return values compared: %d; differing small results: %d' % (sum(1 for x in a if x in ra and x in rb), len(diff)))
for x, va, vb in diff[:15]:
    print('   %s %-60s orig %08x ours %08x' % (x, nm(x), va, vb))
(H / 'auto/difftest.json').write_text(json.dumps({'prefix': k, 'order_orig': a[:k + 20], 'order_ours': b[:k + 20],
                                                   'ret_diff': [{'addr': x, 'name': nm(x), 'orig': va, 'ours': vb} for x, va, vb in diff]}, indent=1))
