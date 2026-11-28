"""python nightly.py: unattended full refresh (Task Scheduler, 03:00). Rebuild every native source against the current
headers (native_check_runner, 8 workers), swap the fresh objects into the quicktest link set, then a full reconvert +
closure + probe cycle (fixloop.py --has @?$). Daytime cycles stay incremental. Log: auto/nightly.log"""
import json, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
log = open(H / 'auto/nightly.log', 'a', encoding='utf-8')
def run(cmd, **kw):
    t = time.time()
    p = subprocess.run(cmd, capture_output=True, text=True, **kw)
    log.write('%s %.0fs %s\n%s\n' % (time.strftime('%Y-%m-%d %H:%M'), time.time() - t, ' '.join(map(str, cmd))[:200], (p.stdout + p.stderr)[-3000:]))
    log.flush()
    return p
if (H / 'auto/NO_NIGHTLY').exists():
    sys.exit('auto/NO_NIGHTLY present')
p = run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(H / 'auto/rebuild_natives.json'), '--workers', '8'], cwd=ROOT)
try:
    res = json.loads(p.stdout.strip().splitlines()[-1])['results']
    f = H / 'linkexp/qt_results.txt'   # fresh natives first; accepted drafts / later swaps stay after it (later wins)
    keep = [l for l in (f.read_text().split() if f.exists() else []) if l != res]
    f.write_text('\n'.join([res] + keep) + '\n')
except Exception as e:
    log.write('native rebuild result unreadable: %s\n' % e)
run([sys.executable, str(H / 'fixloop.py'), '--has', '@?$'], cwd=H)
log.close()
