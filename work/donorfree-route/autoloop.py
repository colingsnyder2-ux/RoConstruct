"""python autoloop.py [--no-link]: one round of the batch loop.
link (quicktest 0, gate included) -> featladder -> if the score beats the good baseline: linkgate --promote
(run/RobloxStable.exe) -> else classify the first failing step's crash into a KNOWN class and name the fix:
  zero-address   eip/stack at 0 or a 0000:00000000 name  -> alias_zero/natdata extern (automatic next link)
  stub-hit       eip inside a qt_stubs*.obj body           -> stubhits.py list -> Codex / createinst / glue
  heap           c0000374 / page-heap verifier stop        -> RobloxPH.exe + crashsite (mutex/size/ABI class)
  static-init    crash before the main window              -> xcusweep/memdiff (unconstructed globals)
  binding        crash in real code                        -> difftrace2.py first divergence + bindcheck/reccmp
Writes auto/autoloop.json (history of rounds)."""
import json, re, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
hist_f = H / 'auto/autoloop.json'
hist = json.loads(hist_f.read_text()) if hist_f.exists() else []
t0 = time.time()
if '--no-link' not in sys.argv:
    r = subprocess.run([sys.executable, str(H / 'quicktest.py'), '0'], capture_output=True, text=True, errors='replace')
    gate = [l for l in r.stdout.splitlines() if l.startswith(('linkgate', 'FAIL', 'ZERO'))]
    print('\n'.join(gate))
lad = subprocess.run([sys.executable, str(H / 'featladder.py')], capture_output=True, text=True, errors='replace').stdout
m = re.search(r'score: (\d+)/(\d+)', lad)
score = int(m.group(1)) if m else 0
best = max([h.get('score', 0) for h in hist if h.get('promoted')] or [0])
row = {'t': time.strftime('%H:%M'), 'score': score, 'secs': round(time.time() - t0)}
print(lad.strip().splitlines()[-1] if lad.strip() else 'ladder: no output')
if score > best:
    subprocess.run([sys.executable, str(H / 'linkgate.py'), '--promote'])
    row['promoted'] = True
else:
    fail = next((l for l in lad.splitlines() if 'CRASH' in l or 'no window' in l or 'HUNG' in l), '')
    step = fail.split('|')[0].strip() if fail else ''
    post = {'file_new': '0xE100', 'insert_dialog': '0xE100,0x807f', 'insert_items': '0xE100,0x807f',
            'run': '0xE100,0x80c6', 'reset': '0xE100,0x80c6,0x80c8'}.get(step, '0xE100')
    if step == 'startup' or 'no window' in fail:
        cls = 'static-init'
        out = subprocess.run([sys.executable, str(H.parents[0] / 'native-client/shortcut/crashsite.py'), str(H / 'run/RobloxQT.exe'),
                              str(H / 'linkexp/qt.map'), '30'], capture_output=True, errors='replace').stdout.decode('latin-1', 'replace') \
            if False else ''
    else:
        out = subprocess.run([sys.executable, str(H / 'attachcrash.py'), '2', '25'], capture_output=True, text=True, errors='replace',
                             env={**__import__('os').environ, 'ATTACH_POST': post}).stdout
        exc = next((l for l in out.splitlines() if l.startswith('exception')), '')
        eip = re.search(r'eip ([0-9a-f]{8}) (\S*)', exc)
        if 'c0000374' in exc:
            cls = 'heap'
        elif eip and (int(eip.group(1), 16) < 0x10000 or 'esp 00000000' in out):
            cls = 'zero-address/stack'
        elif eip and 'func_' in (eip.group(2) or '') and any('stubs' in l for l in open(H / 'linkexp/qt.map', errors='replace') if eip.group(2).split('+')[0] in l):
            cls = 'stub-hit'
        else:
            cls = 'binding'
        row['exception'] = exc[:200]
    row.update({'failed_step': step, 'class': cls})
    print('failed step %s -> class %s' % (step, cls))
    print('  next tool:', {'static-init': 'xcusweep.py / memdiff.py / crashsite', 'heap': 'RobloxPH.exe + crashsite (page heap)',
                           'zero-address/stack': 'RobloxPH.exe page heap (stack smash) + linkgate zero list',
                           'stub-hit': 'stubhits.py -> Codex / createinst / glue', 'binding': 'difftrace2.py + bindcheck/reccmp_map'}[cls])
hist.append(row)
hist_f.write_text(json.dumps(hist, indent=0))
