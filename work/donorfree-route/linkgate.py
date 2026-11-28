"""python linkgate.py [--promote]: acceptance gate after a link, before launching anything.
lld already resolves symbols exactly; this checks ITS answer against the last good build:
  1. zero-address names (an alias whose target is missing resolves to 0 -> call/test [0] at runtime)
  2. binding diff: every function/data name whose owning object KIND changed vs the last good map
     (converted / native / stub / import), the reviewable change set of this link
  3. retcheck.py + bindcheck.py counts vs the last good run (new wrong bindings / stack-balance mismatches)
Exit code 1 = do not launch (FAIL lines say why). --promote (after featladder passes): store this map, exe and
counts as the new good baseline (auto/good/), copy the exe to run/RobloxStable.exe."""
import json, re, shutil, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
G = H / 'auto/good'
G.mkdir(exist_ok=True)


def kind(ob):
    if 'stubs' in ob:
        return 'stub'
    if ':' in ob:
        return 'import'
    if re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob):
        return 'converted'
    return 'native'


def owners(mp):
    out, zero = {}, []
    for l in open(mp, errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0]:
            if p[0] == '0000:00000000' and p[-1] == '<absolute>' and re.match(r'^(?:func_|dat_|\?)', p[1]):
                zero.append(p[1])
            elif p[0].startswith(('0001:', '0002:', '0003:')) and re.match(r'^(?:func_|dat_|\?)', p[1]) and not p[1].startswith(('??_R', '??_C')):
                out.setdefault(p[1], (kind(p[-1]), p[-1]))
    return out, zero


cur, zero = owners(H / 'linkexp/qt.map')
fails = []
if zero:
    fails.append('zero-address names: %d %s' % (len(zero), zero[:8]))
if '--promote' in sys.argv:
    shutil.copy(H / 'linkexp/qt.map', G / 'qt.map'); shutil.copy(H / 'run/RobloxQT.exe', G / 'RobloxQT.exe')
    shutil.copy(H / 'run/RobloxQT.exe', H / 'run/RobloxStable.exe')
    for f in ('retcheck.json', 'bindcheck.json'):
        if (H / 'auto' / f).exists():
            shutil.copy(H / 'auto' / f, G / f)
    print('linkgate: promoted the current build as the good baseline (run/RobloxStable.exe)')
    sys.exit(0)
if (G / 'qt.map').exists():
    old, _ = owners(G / 'qt.map')
    ch = [(n, old[n][0], cur[n][0], cur[n][1]) for n in cur.keys() & old.keys() if old[n][0] != cur[n][0]]
    gone = [n for n in old if n not in cur and old[n][0] != 'stub']
    by = {}
    for n, a, b, ob in ch:
        by.setdefault('%s->%s' % (a, b), []).append((n, ob))
    print('binding diff vs good: %d kind changes, %d real names gone' % (len(ch), len(gone)))
    for k, v in sorted(by.items(), key=lambda kv: -len(kv[1])):
        print('  %-22s %5d  e.g. %s' % (k, len(v), [x[0][:60] for x in v[:3]]))
    (H / 'auto/linkgate_diff.json').write_text(json.dumps({'changes': ch, 'gone': gone[:500]}, indent=0))
    if len(by.get('converted->stub', [])) + len(by.get('native->stub', [])) > 20:
        fails.append('%d real bodies became stubs' % (len(by.get('converted->stub', [])) + len(by.get('native->stub', []))))
else:
    print('binding diff: no good baseline yet (python linkgate.py --promote after a passing featladder)')
for scr, key in (('retcheck.py', None), ('bindcheck.py', None)):
    subprocess.run([sys.executable, str(H / scr)], capture_output=True)
rc = json.loads((H / 'auto/retcheck.json').read_text())
bc = json.loads((H / 'auto/bindcheck.json').read_text())
nwrong = sum(1 for w in bc['wrong'] if w[3].startswith(('PROVEN', 'ctor')))
print('retcheck mismatches %d, bindcheck PROVEN/ctor %d, callee %d, stubs %d' % (len(rc), nwrong, len(bc.get('callee', [])), len(bc['stubs'])))
if (G / 'retcheck.json').exists():
    rc0 = {(r[0], r[1]) for r in json.loads((G / 'retcheck.json').read_text())}
    new = [r for r in rc if (r[0], r[1]) not in rc0]
    if new:
        fails.append('new stack-balance mismatches: %s' % [r[1] + ' ' + r[0][:40] for r in new[:5]])
if (G / 'bindcheck.json').exists():
    b0 = {(w[0], w[1]) for w in json.loads((G / 'bindcheck.json').read_text())['wrong'] if w[3].startswith(('PROVEN', 'ctor'))}
    new = [w for w in bc['wrong'] if w[3].startswith(('PROVEN', 'ctor')) and (w[0], w[1]) not in b0]
    if new:
        fails.append('new PROVEN/ctor wrong bindings: %s' % [w[1] + ' ' + w[0][:40] for w in new[:5]])
for f in fails:
    print('FAIL:', f)
print('linkgate:', 'FAIL' if fails else 'PASS')
sys.exit(1 if fails else 0)
