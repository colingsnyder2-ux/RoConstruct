"""python bisect.py SIGNATURE [--set FILE]: find which linked converted (mass) object causes a crash whose probe output contains
SIGNATURE (e.g. "at 00000000"). Candidates = mass-converted objects currently linked (or --set FILE, a JSON address list).
Each step excludes half the candidates (renamed/bisect_exclude.json), relinks (boot.py --full), probes File->New, and keeps
the half that still reproduces. Prints the culprit address(es); leaves bisect_exclude.json removed at the end."""
import json, os, subprocess, sys, time
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
sig = sys.argv[1]
if '--set' in sys.argv:
    cand = json.load(open(sys.argv[sys.argv.index('--set') + 1]))
else:
    mass = {v['exact'][0] for v in json.load(open(H / 'renamed/addrmap_mass.json')).values()}
    linked = {Path(r['object']).stem for r in json.load(open(H / 'renamed/results.json'))}
    cand = sorted(mass & linked)
BX = H / 'renamed/bisect_exclude.json'


def crashes(excluded):
    BX.write_text(json.dumps(sorted(excluded)))
    subprocess.run([sys.executable, str(H / 'renamed_link.py')], cwd=ROOT, capture_output=True)
    subprocess.run([sys.executable, str(H / 'boot.py'), '--full', '--no-probe'], cwd=ROOT, capture_output=True)
    out = subprocess.run(['sh', str(H / 'final_probe.sh'), '40'], cwd=ROOT, capture_output=True, text=True, env=dict(os.environ, SKIP_LINK='1')).stdout
    subprocess.run([sys.executable, str(ROOT / 'work/ie_cleanup.py')], capture_output=True)
    line = next((l for l in out.splitlines() if l.startswith(('exception', 'NO CRASH'))), '?')
    print(time.strftime('%H:%M:%S'), 'excluded %d -> %s' % (len(excluded), line[:100]), flush=True)
    return sig in line


print('candidates', len(cand))
if not crashes(set()):
    print('signature does not reproduce with all candidates linked'); BX.unlink(missing_ok=True); sys.exit(1)
while len(cand) > 1:
    half = cand[:len(cand) // 2]
    rest = cand[len(cand) // 2:]
    cand = rest if crashes(set(half)) else half   # still crashes without `half` -> culprit in `rest`
    print('remaining', len(cand), cand[:6], flush=True)
print('CULPRIT', cand)
BX.unlink(missing_ok=True)
