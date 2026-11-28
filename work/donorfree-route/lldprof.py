"""python lldprof.py [RSP]: time one lld-link run on a copy of the last final response file (default
linkexp/qt.final.rsp) with /time, writing linkexp/prof.exe/.map so the real link outputs are untouched.
Prints lld's own phase timings, plus counts of objects/libs/aliases and the flags in use."""
import subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
LLD = r'C:\Program Files\LLVM\bin\lld-link.exe'
src = Path(sys.argv[1]) if len(sys.argv) > 1 else H / 'linkexp/qt.final.rsp'
L = src.read_text().splitlines()
out = []
for l in L:
    if l.startswith('"/OUT:'):
        l = '"/OUT:%s"' % (H / 'linkexp/prof.exe')
    elif l.startswith('"/MAP:'):
        l = '"/MAP:%s"' % (H / 'linkexp/prof.map')
    out.append(l)
extra = [a for a in sys.argv[2:]]
rsp = H / 'linkexp/prof.rsp'
rsp.write_text('\n'.join(out + ['"/time"'] + extra) + '\n')
objs = [l for l in L if l.lower().endswith('.obj"')]
libs = [l for l in L if l.lower().endswith('.lib"')]
flags = [l for l in L if l.startswith('"/') and 'alternatename' not in l.lower() and '/include' not in l.lower()]
print('objects %d, libs %d, aliases %d' % (len(objs), len(libs), sum(1 for l in L if 'alternatename' in l.lower())))
print('flags:', ' '.join(f.strip('"') for f in flags)[:600])
t = time.time()
r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, errors='replace')
print('lld exit %d in %.1fs' % (r.returncode, time.time() - t))
for l in (r.stdout + r.stderr).splitlines():
    if not any(w in l.lower() for w in ('warning', 'undefined symbol', '>>>')):
        print('  ' + l[:140])
