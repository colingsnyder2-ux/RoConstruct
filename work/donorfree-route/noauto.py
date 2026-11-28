"""python noauto.py [--start]: functions that still differ from the original (namediff), are called wrongly or stubbed
(calldiff), or fill a wrong virtual slot (vtdiff), for which no automatic fix exists (no server-exact analog that converts).
Writes auto/noauto.txt (reachable first). --start queues them on the dashboard as a 5-worker boot_recover job."""
import json, re, sys, urllib.request
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
R = json.load(open(H / 'renamed/rename.json'))
def exact_ok(a):
    try:
        return open(ROOT / 'src/2008-06' / (a + '.cpp'), errors='replace').readline().startswith('// from server: 100%') and (R.get(a) or {}).get('status') == 'renamed'
    except OSError:
        return False
want = {}
for n, d in json.load(open(H / 'auto/namediff.json')).items():
    want[d['orig']] = max(want.get(d['orig'], 0), 2 if d.get('reach') else 1)
for c in json.load(open(H / 'auto/calldiff.json')):
    want[c['target']] = max(want.get(c['target'], 0), 2 if c.get('reach') else 1)
try:
    for v in json.load(open(H / 'auto/vtdiff.json')):
        want[v['orig']] = max(want.get(v['orig'], 0), 1)
except OSError:
    pass
todo = sorted((a for a in want if not exact_ok(a) and 0x401000 <= int(a, 16) < 0x6a0000), key=lambda a: (-want[a], a))
(H / 'auto/noauto.txt').write_text('\n'.join(todo) + '\n')
print('no automatic fix: %d (File->New-reachable %d)' % (len(todo), sum(1 for a in todo if want[a] == 2)))
if '--start' in sys.argv:
    tok = (ROOT / 'work/gui-token.txt').read_text().strip()
    port = int(sys.argv[sys.argv.index('--port') + 1]) if '--port' in sys.argv else 63936
    body = json.dumps({'kind': 'boot_recover', 'addrs': todo[:60], 'workers': 5, 'tries': 3, 'mix': 'sonnet:5'}).encode()
    rq = urllib.request.Request('http://127.0.0.1:%d/api/start' % port, data=body, method='POST',
                                headers={'X-ROC-Token': tok, 'Content-Type': 'application/json', 'Host': '127.0.0.1:%d' % port})
    print(urllib.request.urlopen(rq, timeout=20).read()[:300])
