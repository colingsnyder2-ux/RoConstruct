"""python ttdrun.py [EXE] [--post 0xE100,...] [--out auto/ttd] [--secs 60]: record a TTD trace WITHOUT an admin shell.
Writes auto/ttd_request.json and triggers the elevated scheduled task RoConstructTTD (installed once by
ttd/setup_ttd_task.ps1), which validates the request, records, posts the commands and writes auto/ttd_done.json.
Prints the .run path(s). Replay with ttdq.py."""
import json, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
a = sys.argv[1:]
exe = os.path.abspath(next((x for x in a if x.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
post = next((a[i + 1] for i, x in enumerate(a) if x == '--post'), '0xE100').split(',')
out = os.path.abspath(next((a[i + 1] for i, x in enumerate(a) if x == '--out'), str(H / 'auto/ttd')))
secs = int(next((a[i + 1] for i, x in enumerate(a) if x == '--secs'), '60'))
done = H / 'auto/ttd_done.json'
if done.exists():
    done.unlink()
(H / 'auto/ttd_request.json').write_text(json.dumps({'exe': exe, 'out': out, 'post': post, 'secs': secs}))
r = subprocess.run(['schtasks', '/run', '/tn', 'RoConstructTTD'], capture_output=True, text=True)
if r.returncode:
    sys.exit('task not triggered (run ttd/setup_ttd_task.ps1 once as admin): ' + (r.stdout + r.stderr).strip())
t0 = time.time()
while not done.exists() and time.time() - t0 < secs + 300:
    time.sleep(3)
print(done.read_text() if done.exists() else 'timeout: no done marker (see auto/ttd_runner.log)')
