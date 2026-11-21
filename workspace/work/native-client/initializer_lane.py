"""Prove + bind loop for dynamic initializers of statics defined in one native unit.
  python work/native-client/initializer_lane.py FILE.cpp ADDR=NEEDLE [...] [--why TEXT]
Runs agent_prove.py, then root_ref_bind.py for the byte-equal addresses, until every address is EXACT, nothing
changes, or 6 rounds passed.  Prints the last verdicts."""
import re, subprocess, sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
args = sys.argv[1:]
why = 'dynamic initializer: name string, constructor arguments and RTTI class of the constructor read from the original initializer (research-twins/initializers.json)'
if '--why' in args:
    i = args.index('--why'); why = args[i + 1]; del args[i:i + 2]
src, roots = args[0], args[1:]
last = None
for _ in range(10):
    out = subprocess.run([sys.executable, str(HERE / 'agent_prove.py'), src] + roots, capture_output=True, text=True).stdout
    verdict = dict(re.findall(r'^== (\w{8}) (EXACT|REJECTED|DIFF|COMPILE FAILED|RETRY LATER)', out, re.M))
    if 'RETRY LATER' in verdict.values():
        continue
    todo = [r for r in roots if verdict.get(r.split('=')[0].lower()) == 'REJECTED']
    if not todo:
        break
    bound = subprocess.run([sys.executable, str(HERE / 'root_ref_bind.py'), src] + todo + ['--why', why], capture_output=True, text=True).stdout
    print(bound.strip())
    if 'bound ' not in bound or (verdict, bound) == last:
        break
    last = (verdict, bound)
print(out[-6000:])
print('SUMMARY', verdict)
