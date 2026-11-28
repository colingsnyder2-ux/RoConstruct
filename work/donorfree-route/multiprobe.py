"""python multiprobe.py [secs]: ONE probe run that skips up to 30 faults (crashsite FASTFWD fakes a null call's return)
and lists every distinct fault site with its caller, so a batch of crash classes gets fixed per relink instead of one."""
import os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
secs = sys.argv[1] if len(sys.argv) > 1 else '60'
env = dict(os.environ, FASTFWD='30', ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD='0xE100', PROBE_IDLE='12',
           BPIMP='_invalid_parameter_noinfo,_purecall,abort,_invoke_watson,_crt_debugger_hook,_amsg_exit')
p = subprocess.run([sys.executable, str(H.parents[1] / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxQT.exe'),
                    str(H / 'linkexp/qt.map'), secs], capture_output=True, text=True, env=env, cwd=H)
(H / 'auto/multiprobe.txt').write_text(p.stdout + p.stderr)
sites = []
for l in p.stdout.splitlines():
    m = re.match(r'FASTFWD #(\d+) null call \(eip ([0-9a-f]+)\) from (.*?); ', l)
    if m:
        sites.append(('null call', m.group(3)[:110]))
    m = re.match(r'(exception \S+ at .*?) \(tid', l) or re.match(r'(process exited \S+)', l) or re.match(r'(ENTRY hit .*)', l)
    if m:
        sites.append(('final', m.group(1)[:140]))
seen = []
for s in sites:
    if s not in seen:
        seen.append(s)
print('%d fault sites in one run (%d distinct):' % (len(sites), len(seen)))
for k, s in seen:
    print('  %-10s %s' % (k, s))
if not any(k == 'final' for k, _ in seen):
    print('  no fatal fault: ' + next((l for l in p.stdout.splitlines() if 'no crash' in l.lower()), 'ran to time limit')[:100])
