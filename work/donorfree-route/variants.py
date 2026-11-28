"""python variants.py SPEC.json: build several link variants IN PARALLEL (quicktest.py QT_TAG=<tag>: own exe/map/
stubs/patched copies) and probe each, to try competing fixes in one round instead of one relink each.
SPEC: [{"tag": "A", "env": {"XCU_OBJ": "...", "QT_EXCLUDE": "..."}, "pre": ["xcu_gen.py"], "pre_env": {...}}, ...]
`pre` commands run first (serially, with pre_env) -- e.g. xcu_gen.py with XCU_CTOR/XCU_OUT to make one initializer
family's object. Links run concurrently (lld uses all cores; 2-4 variants fit in 32 GB); probes run one at a time
(GUI windows). Prints one verdict line per variant and writes auto/variants.json."""
import json, os, re, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
spec = json.loads(Path(sys.argv[1]).read_text())
# seed each tag from the BASE build's state (previous stub names, pass-2 leftovers, externals cache, map, fixes):
# a fresh tag predicted a different stub set, so even the plain base variant crashed differently (1.8 s on the stack
# vs the base build's 2.3 s) -- variants must differ ONLY by their env
import shutil
for v in spec:
    for base, tagged in (('linkexp/qt_prev_und.txt', 'linkexp/qt%s_prev_und.txt'), ('linkexp/qt_und.txt', 'linkexp/qt%s_und.txt'),
                         ('linkexp/qt_und2.txt', 'linkexp/qt%s_und2.txt'), ('linkexp/qt_ext_cache.pkl', 'linkexp/qt%s_ext_cache.pkl'),
                         ('linkexp/qt.map', 'linkexp/qt%s.map'), ('linkexp/qt.exe', 'linkexp/qt%s.exe'),
                         ('linkexp/lld_fixes.json', 'linkexp/lld_fixes%s.json'), ('linkexp/obj_alias_cache.pkl', 'linkexp/obj_alias_cache%s.pkl'),
                         ('linkexp/mfc_static_cache.json', 'linkexp/mfc_static_cache%s.json')):
        if (H / base).exists():
            shutil.copyfile(H / base, H / (tagged % v['tag']))
for v in spec:
    for c in v.get('pre', []):
        _c = c.split()   # 'script.py --flag ...'
        subprocess.run([sys.executable, str(H / _c[0])] + _c[1:], cwd=H, env=dict(os.environ, **v.get('pre_env', {})), capture_output=True)
t0 = time.time()
procs = {}
for v in spec:
    env = dict(os.environ, QT_TAG=v['tag'], **v.get('env', {}))
    procs[v['tag']] = subprocess.Popen([sys.executable, str(H / 'quicktest.py'), '0'], cwd=H, env=env,
                                       stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors='replace')
link = {t: p.communicate()[0] for t, p in procs.items()}
print('links done in %.0fs (%d variants in parallel)' % (time.time() - t0, len(spec)), flush=True)
res = {}
for v in spec:
    t = v['tag']
    ok = (H / ('run/RobloxQT%s.exe' % t)).exists() and 'Traceback' not in link[t]
    if not ok:
        res[t] = dict(verdict='LINK FAILED', tail=link[t][-400:])
        print('  %-6s LINK FAILED' % t); continue
    subprocess.run([sys.executable, str(H / 'oneshot.py'), str(H / ('run/RobloxQT%s.exe' % t)), str(H / ('linkexp/qt%s.map' % t)), '40'],
                   cwd=H, capture_output=True)
    out = (H / 'auto/oneshot.txt').read_text(errors='replace')
    (H / ('auto/oneshot_%s.txt' % t)).write_text(out)
    end = next((l for l in reversed(out.splitlines()) if re.match(r'^(exception|process exited|no crash|crash after)', l)), '?')
    after = next((l for l in reversed(out.splitlines()) if l.startswith('crash after')), '')
    throws = [l[:120] for l in out.splitlines() if l.startswith('C++ throw #')]
    res[t] = dict(verdict=end, after=after, throws=throws, env=v.get('env', {}))
    print('  %-6s %s %s %s' % (t, end[:90], after, ('| ' + throws[0][:80]) if throws else ''), flush=True)
(H / 'auto/variants.json').write_text(json.dumps(res, indent=1))
