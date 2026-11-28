"""python livebisect.py ADDRS.json --bad REGEX [--secs N]: find which converted function causes a regression WITHOUT
relinking. Leaving a converted object out of the link only turns its function into a `return 0` stub; the probe can do
the same in the running client (crashsite PATCH: `xor eax,eax; ret N` at the function's entry, N = the argument bytes
the original pops). Each test is one oneshot probe (~12-40 s) instead of a relink (4-10 min).
ADDRS.json: original addresses whose converted bodies are in the current link (run/RobloxQT.exe + linkexp/qt.map).
--bad: regex over the probe's end/exception lines that marks the regression (e.g. 'at 00000000').
Assumes one culprit: halves the set, keeps the half whose patching makes --bad disappear. Writes auto/livebisect.json."""
import json, os, re, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
args = sys.argv[1:]
bad = args[args.index('--bad') + 1]
secs = args[args.index('--secs') + 1] if '--secs' in args else '25'
addrs = json.loads(Path(args[0]).read_text())
ren = json.loads((H / 'renamed/rename.json').read_text())
mapaddr = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            mapaddr.setdefault(p[1], int(p[2], 16))
        except ValueError:
            pass
patch = {}
for a in addrs:
    s = (ren.get(a) or {}).get('symbol')
    va = mapaddr.get(s) or mapaddr.get('func_' + a)
    if not va:
        continue
    try:
        n = ms.addr_ret_bytes(int(a, 16)) or 0
    except Exception:
        n = 0
    patch[a] = '%08x:31c0%s' % (va, ('c2%02x%02x' % (n & 0xff, n >> 8)) if n else 'c3')
print('livebisect: %d of %d addresses patchable; bad = %r' % (len(patch), len(addrs), bad), flush=True)


def probe(sub):
    env = dict(os.environ, PATCH=';'.join(patch[a] for a in sub))
    t = time.time()
    subprocess.run([sys.executable, str(H / 'oneshot.py'), secs], cwd=H, env=env, capture_output=True)
    out = (H / 'auto/oneshot.txt').read_text(errors='replace')
    ends = '\n'.join(l for l in out.splitlines() if re.match(r'^(exception|process exited|no crash|crash after)', l))
    hit = bool(re.search(bad, ends))
    print('  probe %4d patched -> %s (%.0fs) %s' % (len(sub), 'BAD' if hit else 'good', time.time() - t, ends.splitlines()[0][:90] if ends else ''), flush=True)
    return hit


cur = sorted(patch)
log = []
if probe([]) is False:
    print('baseline does not show the regression: nothing to bisect'); sys.exit(1)
if probe(cur):
    print('patching ALL of them still shows the regression: the culprit is not in this set'); sys.exit(1)
while len(cur) > 1:
    half = cur[:len(cur) // 2]
    if not probe(half):      # patching this half removes the regression -> culprit inside it
        cur = half
    else:
        cur = cur[len(cur) // 2:]
    log.append(list(cur))
a = cur[0]
res = dict(culprit=a, symbol=(ren.get(a) or {}).get('symbol'), steps=len(log))
(H / 'auto/livebisect.json').write_text(json.dumps(res, indent=1))
print('CULPRIT: %s %s (%d probes)' % (a, res['symbol'], len(log) + 2))
