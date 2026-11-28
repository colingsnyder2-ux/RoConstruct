"""python audits_all.py: the binding audits in waves on the CURRENT map/exe (quicktest used to run them before every
link: 231 s of a ~5 min link). quicktest now starts this right AFTER a link in the background; the next link skips
it when auto/audits_stamp.json matches the map it is about to read, or waits for a run still going (pid file).
Independent readers run in parallel; funcdefaudit and classdesc both write natbody_defrename.json and callaudit
reads it -> serial, last.
Opt-in, for a link started while these still run (they hold CPU, RAM and disk the link needs):
  AUDIT_NICE=1  start every audit at BELOW_NORMAL priority (Windows): a concurrent quicktest gets the CPU first.
  AUDIT_JOBS=N  at most N first-wave audits at once (default: all 9 together, each loading multi-GB caches); with a cap
                each audit gets its own AUDIT_TIMEOUT from its start instead of one deadline for the whole wave."""
import json, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
(H / 'auto/audits.pid').write_text(str(os.getpid()))
t0 = time.time()
mt = (H / 'linkexp/qt.map').stat().st_mtime
W = ['cnames.py', 'natdata.py', 'foldaudit.py', 'natbody_check.py', 'natcallaudit.py', 'aliasaudit.py', 'natinit.py',
     'accessalias.py', 'creatorinit.py']
TMO = float(os.environ.get('AUDIT_TIMEOUT', '300'))   # one hung audit (natdata/natbody_check ran 40+ min) must not stall links
times = {}
CF = 0x08000000 | (0x00004000 if os.environ.get('AUDIT_NICE') == '1' else 0)   # CREATE_NO_WINDOW [| BELOW_NORMAL_PRIORITY_CLASS]
JOBS = int(os.environ.get('AUDIT_JOBS', '0') or 0)
if JOBS <= 0:   # default: the whole wave at once, one deadline
    ps = [(w, subprocess.Popen([sys.executable, str(H / w)], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, creationflags=CF)) for w in W]
    for w, p in ps:
        try:
            p.wait(timeout=max(1, TMO - (time.time() - t0)))
            times[w] = round(time.time() - t0)
        except subprocess.TimeoutExpired:
            p.kill(); times[w] = 'TIMEOUT'
else:   # AUDIT_JOBS=N: a pool of N, each audit timed from its own start
    todo, run = list(W), {}
    while todo or run:
        while todo and len(run) < JOBS:
            w = todo.pop(0)
            run[w] = (subprocess.Popen([sys.executable, str(H / w)], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, creationflags=CF), time.time())
        for w, (p, ts) in list(run.items()):
            if p.poll() is not None:
                times[w] = round(time.time() - ts); del run[w]
            elif time.time() - ts > TMO:
                p.kill(); times[w] = 'TIMEOUT'; del run[w]
        time.sleep(0.5)
for w in ('funcdefaudit.py', 'classdesc.py', 'callaudit.py', 'callfix_validate.py'):
    t1 = time.time()
    try:
        subprocess.run([sys.executable, str(H / w)], capture_output=True, timeout=TMO, creationflags=CF)
        times[w] = round(time.time() - t1)
    except subprocess.TimeoutExpired:
        times[w] = 'TIMEOUT'
(H / 'auto/audits_stamp.json').write_text(json.dumps({'map_mtime': mt, 'secs': round(time.time() - t0), 'times': times}))
try:
    (H / 'auto/audits.pid').unlink()
except OSError:
    pass
print('audits_all: %.0f s' % (time.time() - t0))
