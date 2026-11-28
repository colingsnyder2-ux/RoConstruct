"""python oneshot.py [EXE MAP] [secs]: ONE probe run that collects everything one crash loop used to need 3-4 runs for:
LIVE_STUBFIX (stubs of names a loaded DLL exports jump to the real function), BPSTUBS (placeholder stubs actually run,
in order, with callers), SKIPAV (the next crash sites, continuing past each), C++ throw types, and File->New posted.
Writes auto/oneshot.txt (raw) and prints a short report. Default exe/map: run/RobloxQT.exe + linkexp/qt.map."""
import os, re, subprocess, sys
from collections import OrderedDict
from pathlib import Path
H = Path(__file__).parent
a = [x for x in sys.argv[1:] if not x.isdigit()]
exe = a[0] if len(a) > 0 else str(H / 'run/RobloxQT.exe')
mp = a[1] if len(a) > 1 else str(H / 'linkexp/qt.map')
secs = next((x for x in sys.argv[1:] if x.isdigit()), '40')
env = dict(os.environ, LIVE_STUBFIX='1', BPSTUBS='1', SKIPAV=os.environ.get('ONESHOT_SKIPAV', '15'), FASTFWD='30', CXXSTACK='1', POSTCMD='0xE100',
           ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', PROBE_IDLE='12')
env.pop('SECOND_CHANCE_ONLY', None)
p = subprocess.run([sys.executable, str(H.parents[1] / 'work/native-client/shortcut/crashsite.py'), exe, mp, secs],
                   cwd=H, capture_output=True, env=env)
out = p.stdout.decode('latin-1', 'replace').replace('\x00', '')
(H / 'auto/oneshot.txt').write_text(out)
stubs = OrderedDict()
for l in out.splitlines():
    m = re.match(r'^STUB (\S+) <- (.*)$', l)
    if m and m.group(1) not in stubs:
        stubs[m.group(1)] = m.group(2)
skips = [l for l in out.splitlines() if l.startswith('SKIPAV')]
throws = OrderedDict()
for l in out.splitlines():
    m = re.match(r'^C\+\+ throw #\d+ \(type ([^,]*),', l)
    if m:
        throws[m.group(1)] = throws.get(m.group(1), 0) + 1
end = next((l for l in reversed(out.splitlines()) if re.match(r'^(exception|process exited|no crash|crash after)', l)), '?')
fix = next((l for l in out.splitlines() if l.startswith('LIVE_STUBFIX')), '')
print(fix)
print('stubs run (%d, first-hit order):' % len(stubs))
for n, c in list(stubs.items())[:40]:
    print('  %-80s <- %s' % (n[:80], c[:60]))
print('crash sites skipped (%d):' % len(skips))
for l in skips[:15]:
    print('  ' + l[:170])
print('C++ throws: %s' % ', '.join('%s x%d' % (t, c) for t, c in throws.items()) if throws else 'C++ throws: none')
print('end: ' + end[:160])
