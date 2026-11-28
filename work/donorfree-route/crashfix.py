"""python crashfix.py [--rounds N] [--secs S]: unattended File->New crash loop.
Each round: relink (boot.py --no-probe), probe on the real desktop with the window kept behind other windows (second-chance
crash only), then
  * first stub hit that is a function the original exe has -> autorecover it (normal draft);
  * else the innermost stack frame that belongs to an AutoRecover draft -> redraft it with the crash in the prompt
    (auto/crash_<addr>.txt, read by autorecover.crash_context).
Stops when File->New survives the probe, after N rounds, or when the same crash repeats twice with nothing new to try.
Log: auto/crashfix.log (one line per round)."""
import json, os, re, subprocess, sys, time
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
NC = ROOT / 'rebuild/2008-06/native-classes'
rounds = int(sys.argv[sys.argv.index('--rounds') + 1]) if '--rounds' in sys.argv else 10
secs = sys.argv[sys.argv.index('--secs') + 1] if '--secs' in sys.argv else '40'
names = {r.get('name') or '': int(a, 16) for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items()}
NOISE = re.compile(r'hasStringValue|isReadOnly|raisePropertyChanged|convertToString|InitializeAllIcons|loadBrowserIcons|\?\$')
LOG = H / 'auto/crashfix.log'


def log(msg):
    line = time.strftime('%H:%M:%S ') + msg
    print(line, flush=True)
    with open(LOG, 'a') as f:
        f.write(line + '\n')


def addr_of(sym):
    m = re.search(r'fn_([0-9a-f]{8})', sym)
    if m:
        return m.group(1)
    full = next((n for n in names if n.startswith(sym)), None) if sym.startswith('?') else None
    return '%08x' % names[full] if full else None


def probe():
    env = dict(os.environ, ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', PEEK='esp', POSTCMD='0xE100', BPSTUBS='1')
    return subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxDonorFree.exe'),
                           str(H / 'link/donorfree.map'), secs], env=env, capture_output=True, text=True, cwd=ROOT).stdout


def recover(addr, force):
    args = [sys.executable, str(H / 'autorecover.py'), addr, '--mix', 'sonnet:1', '--workers', '1', '--tries', '2', '--no-link']
    out = subprocess.run(args + (['--force'] if force else []), capture_output=True, text=True, cwd=ROOT).stdout
    try:
        rows = json.load(open(H / 'auto/results.json'))
        return next((r['results'] for r in reversed(rows) if r['addr'] == addr and r.get('compile')), None)
    except Exception:
        return None


results, seen = [], {}
for rnd in range(1, rounds + 1):
    subprocess.run([sys.executable, str(H / 'boot.py'), *results, '--no-probe'], capture_output=True, text=True, cwd=ROOT)
    results = []
    for _try in range(3):   # 800706be = the probe's IE killer cut CBrowserView's COM call: harness noise, probe again
        out = probe()
        exc = next((l for l in out.splitlines() if l.startswith('exception ')), None)
        if not exc or not exc.startswith('exception 800706be'):
            break
    if not exc:
        log('round %d: no crash within %ss: File->New survived' % (rnd, secs))
        break
    stubs = [l[5:].split(' <- ')[0] for l in out.splitlines() if l.startswith('STUB ') and not NOISE.search(l[:120])]
    frames = [l.split(None, 2)[2] for l in out.splitlines() if l.startswith('  stack ')]
    eip_sym = exc.split(' at ', 1)[1].split(None, 2)[1] if ' at ' in exc else ''
    target, force, why = None, False, ''
    for s in stubs:
        a = addr_of(s)
        if a and not (NC / ('AutoRecover_%s.cpp' % a)).exists():
            target, why = a, 'stub hit ' + s[:60]
            break
    if not target:
        for s in [eip_sym] + frames:
            a = addr_of(s.split('+')[0])
            if a and (NC / ('AutoRecover_%s.cpp' % a)).exists() and seen.get(a, 0) < 2:
                target, force, why = a, True, 'crash frame ' + s[:60]
                break
    key = exc[:60]
    if not target:
        log('round %d: %s | no draft frame to fix (frames: %s)' % (rnd, exc[:90], '; '.join(f[:50] for f in frames[:4])))
        break
    seen[target] = seen.get(target, 0) + 1
    if force:
        (H / ('auto/crash_%s.txt' % target)).write_text(exc + '\n' + '\n'.join(l for l in out.splitlines()
            if l.startswith(('eax ', 'peek ', '  stack ', 'fault ')))[:2000])
    log('round %d: %s | %s -> redraft %s' % (rnd, exc[:80], why, target))
    r = recover(target, force)
    if r:
        results.append(r)
    else:
        log('   %s: no compiled draft' % target)
