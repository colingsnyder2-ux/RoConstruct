"""Byte-check every function a native source defines against the 2008 exe (address from function-files.json by name).
    python work/donorfree-route/exact_check.py native-classes/Foo.cpp [...]"""
import json, subprocess, sys, os
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]; BASE = ROOT / 'rebuild/2008-06'
sys.path.insert(0, str(ROOT))
from roc import match
ff = json.loads((ROOT / 'work/native-client/layout/function-files.json').read_text())
by_name = {}
for a, v in ff.items():
    if isinstance(v, dict) and v.get('name'):
        by_name.setdefault(v['name'], a)
srcs = sys.argv[1:]
REST=set(json.load(open('C:/Users/colin/AppData/Local/Temp/rest.json')))
def run(jobs, tag):
    m = ROOT / 'work/donorfree-route' / ('exact-%s.json' % tag)
    m.write_text(json.dumps({'compiler_build': 21022, 'jobs': jobs}))
    p = subprocess.run([sys.executable, str(BASE / 'tests/native_check_runner.py'), 'run', str(m), '--workers', '8'],
                       cwd=ROOT, capture_output=True, text=True)
    if not p.stdout.strip():
        raise SystemExit('runner gave no result: ' + p.stderr.strip()[-400:])
    d = json.loads(Path(json.loads(p.stdout.strip().splitlines()[-1])['results']).read_text())
    return d if isinstance(d, list) else d['results']
first = run([{'source': s} for s in srcs], 'pass1')
jobs = []
for r in first:
    if r['status'] != 'complete':
        print('COMPILE FAIL', r['source'], (r.get('error') or '')[:80]); continue
    names = [f[0] for f in match.coff_functions(Path(r['object']).read_bytes())]
    checks = [{'addr': by_name[n], 'symbol': n} for n in dict.fromkeys(names) if n in by_name]
    jobs.append({'source': Path(os.path.relpath(r['source'], BASE)).as_posix(), 'checks': checks})
for r in run(jobs, 'pass2'):
    st = [c['status'] for c in r.get('checks', [])]
    bad = [(c['addr'], c['symbol'][:60], c.get('score')) for c in r.get('checks', []) if c['status'] != 'exact']
    print('%-40s exact %d/%d; target-exact: %s; target-NOT: %s' % (Path(r['source']).name, st.count('exact'), len(st), sorted(c['addr'] for c in r.get('checks',[]) if c['status']=='exact' and c['addr'] in REST), [b for b in bad if b[0] in REST]))
