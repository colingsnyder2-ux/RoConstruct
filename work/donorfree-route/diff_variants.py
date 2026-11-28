import json, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
p = subprocess.run([sys.executable, 'rebuild/2008-06/tests/native_check_runner.py', 'run', 'work/donorfree-route/cwv.json', '--workers', '4'],
                   cwd=ROOT, capture_output=True, text=True)
run = Path(json.loads(p.stdout.strip().splitlines()[-1])['run'])
for i, name in enumerate('ABCD'):
    unit = run / ('unit-%03d' % i)
    obj = unit / 'candidate.obj'
    if not obj.exists():
        errs = [l for l in (unit / 'compile.log').read_text(errors='replace').splitlines() if ': error' in l]
        print(name, 'compile failed', errs[:1])
        continue
    q = subprocess.run(['roc.cmd', 'native-asm', '2008-06', '00615640', '--obj', str(obj), '--sym',
                        '?writeValue@?$TypedPropertyDescriptor@VContentId'], cwd=ROOT, capture_output=True, text=True, shell=True)
    line = q.stdout.splitlines()[1] if len(q.stdout.splitlines()) > 1 else q.stdout[:200]
    print(name, line[line.find(' bytes:') - 3:][:80])
