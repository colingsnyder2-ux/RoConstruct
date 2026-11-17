"""qc.py SOURCE [PROVE_FAMILY]: quick single-file compile reusing the exact cl flags/includes of the newest receipt of a prove
family (default: the source's own), so source shapes iterate in seconds-minutes without a full prove round. Prints errors + obj path.
The family must have been proved once with the same native-flags line."""
import json, glob, os, subprocess, sys
R = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
src = os.path.abspath(sys.argv[1])
fam = sys.argv[2] if len(sys.argv) > 2 else 'prove-' + os.path.splitext(os.path.basename(src))[0]
rec = max(glob.glob(os.path.join(R, 'work/native-client/prove-out', fam, 'objects/*/receipt.json')), key=os.path.getmtime)
r = json.load(open(rec)); flags = r['flags']
if isinstance(flags, str): flags = eval(flags)
inc = r['build_inputs'] if isinstance(r['build_inputs'], dict) else eval(r['build_inputs'])
cl = [k for k in inc['compiler'] if k.endswith('cl.exe')][0]
out = os.path.join(os.environ.get('TEMP', '/tmp'), 'qc'); os.makedirs(out, exist_ok=True)
extra = ['/I' + v for v in inc['includes'].values()]
cmd = [cl] + flags + extra + ['/Fo' + out + os.sep + 'q.obj', src]
env = dict(os.environ); env['PATH'] = os.path.dirname(cl) + os.pathsep + os.path.join(os.path.dirname(cl), '..', '..', 'Common7', 'IDE') + os.pathsep + env['PATH']
p = subprocess.run(cmd, capture_output=True, text=True, env=env)
for l in (p.stdout + p.stderr).splitlines():
    if l.strip() and 'Note:' not in l and 'warning' not in l: print(l[:400])
print('exit', p.returncode, os.path.join(out, 'q.obj'))
