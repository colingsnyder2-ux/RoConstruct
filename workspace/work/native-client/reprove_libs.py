"""Re-prove library native files after a checker change and report the files whose exact bytes moved.

  python work/native-client/reprove_libs.py PREFIX [PREFIX ...]      e.g. G3D XTP Lua Png Jpeg Boost Zlib Mfc Scint Atl
Per-file proofs (cached objects are reused), not a census. Prints `file  old -> new B` only for files that changed.
"""
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
LOG = HERE / 'prove-log.jsonl'


def latest():
    out = {}
    for line in LOG.read_text(errors='replace').splitlines():
        try:
            d = json.loads(line)
        except ValueError:
            continue
        if d.get('family', '').startswith('prove-'):
            out[d['family']] = d['exact_bytes']
    return out


before = latest()
files = sorted(p for prefix in sys.argv[1:] for p in (ROOT / 'rebuild/2008-06/native-classes').glob(prefix + '*.cpp'))
gain = 0
for f in files:
    run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(f), '--rounds', '2', '--infer-names', '--quiet'], cwd=ROOT, capture_output=True, text=True)
    rows = [json.loads(l) for l in run.stdout.splitlines() if l.startswith('{')]
    if not rows:
        continue
    new, old = rows[-1]['exact_bytes'], before.get('prove-' + f.stem, 0)
    if new != old:
        gain += new - old
        print('%-36s %7d -> %7d B (%+d)' % (f.name, old, new, new - old), flush=True)
print('DONE %d files, net %+d B' % (len(files), gain), flush=True)
