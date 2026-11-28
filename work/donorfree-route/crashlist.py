"""python crashlist.py [secs]: EVERY crash site on the startup + File->New path in ONE run, instead of one crash per
relink. Runs oneshot.py with SKIPAV=200 + SKIPAV_ANY=1 (crashsite skips faulting loads, fake-returns 0 from calls into
NULL and from AVs in any DLL) and a longer time limit, then groups the skipped sites by function, lists the placeholders
that ran, and the C++ throws. State after a skip is not trustworthy: later sites can be consequences of earlier ones,
so fix from the top. Writes auto/crashlist.json {sites, stubs, throws}."""
import json, os, re, subprocess, sys
from collections import OrderedDict
from pathlib import Path
H = Path(__file__).parent
secs = next((x for x in sys.argv[1:] if x.isdigit()), '90')
env = dict(os.environ, ONESHOT_SKIPAV='200', SKIPAV_ANY='1')
subprocess.run([sys.executable, str(H / 'oneshot.py'), secs], cwd=H, env=env, capture_output=True)
out = (H / 'auto/oneshot.txt').read_text(errors='replace')
sites = OrderedDict()
for l in out.splitlines():
    m = re.match(r'^SKIPAV #\d+ (.*)$', l)
    if not m:
        continue
    t = m.group(1)
    f = re.match(r'(?:[0-9a-f]{8} )?(\S+?)(?:\+[0-9a-f]+)?\s', t)
    key = 'null call' if 'call to' in t else (f.group(1) if f else t[:60])
    sites.setdefault(key, []).append(t[:200])
stubs = OrderedDict()
for l in out.splitlines():
    m = re.match(r'^STUB (\S+) <- (.*)$', l)
    if m and m.group(1) not in stubs:
        stubs[m.group(1)] = m.group(2)[:120]
throws = [l[:240] for l in out.splitlines() if l.startswith('C++ throw #')]
end = next((l for l in reversed(out.splitlines()) if re.match(r'^(exception|process exited|no crash|crash after)', l)), '?')
(H / 'auto/crashlist.json').write_text(json.dumps(dict(sites=sites, stubs=stubs, throws=throws, end=end), indent=1))
print('crash sites skipped: %d in %d functions; placeholders run: %d; C++ throws: %d; end: %s'
      % (sum(map(len, sites.values())), len(sites), len(stubs), len(throws), end[:100]))
for k, v in list(sites.items())[:40]:
    print('  %3dx %-70s %s' % (len(v), k[:70], v[0][len(k):][:80] if v[0].startswith(k) else v[0][:80]))
for t in throws[:6]:
    print('  ' + t[:180])
