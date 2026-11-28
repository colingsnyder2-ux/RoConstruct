"""python next_targets.py [--file-new] [--limit N]: probe the donor-free exe and print the addresses of the stubs it hits, in call
order, that exist as named functions in the original exe (candidates for autorecover.py). Templates, vendor/MFC and trivial noise
are skipped. --file-new posts File->New on the VISIBLE desktop (owner-approved single runs; pops a window)."""
import json, os, re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
H = ROOT / 'work/donorfree-route'
names = {}
for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items():
    n = r.get('name') or ''
    if n.startswith('?'):
        names.setdefault(n, int(a, 16))
env = dict(os.environ, BPSTUBS='1')
if '--file-new' in sys.argv:
    env.update(POSTCMD='0xE100', ROC_PROBE_VISIBLE='1')
limit = int(sys.argv[sys.argv.index('--limit') + 1]) if '--limit' in sys.argv else 15
out = subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxDonorFree.exe'),
                      str(H / 'link/donorfree.map'), '45'], capture_output=True, text=True, env=env, cwd=ROOT).stdout
seen = []
for line in out.splitlines():
    m = re.match(r'^STUB (\S+) <-', line)
    if not m:
        continue
    sym = m.group(1)
    # the printed symbol is truncated to 90 chars: match by prefix
    full = next((n for n in names if n.startswith(sym)), None)
    if not full:   # draft helper stub: the address is in its name (fn_<addr> or name_<addr>@@...)
        m2 = re.search(r'_([0-9a-f]{8})(?:@@|@|$)', sym)
        if m2 and int(m2.group(1), 16) in {v for v in names.values()} and sym not in seen:
            seen.append(sym)
            names.setdefault(sym, int(m2.group(1), 16))
        continue
    if full in seen:
        continue
    if re.search(r'\?\$|hasStringValue|isReadOnly|convertTo|CXTP|CWnd|CString|@ATL@|G3D@@|boost@@|std@@', full[:80]):
        continue
    seen.append(full)
for n in seen[:limit]:
    print('%08x %s' % (names[n], n[:100]))
