"""Prove (and register into the census inventory) every native-classes TU the inventory lacks, as one family, at
below-normal priority.  The site counts native exacts from prove-out manifests; 839 TUs were only covered by per-file
prove runs whose manifests were lost with prove-out (2026-11-15)."""
import glob
import json
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
inv = json.loads((ROOT / 'work/native-client/ogre-native-full-inventory-all.json').read_text())
have = {os.path.normcase(os.path.normpath(s)) for s in inv['families'][0]['sources']}
files = sorted(Path(p).as_posix() for p in glob.glob(str(ROOT / 'rebuild/2008-06/native-classes/*.cpp'))
               if not Path(p).name.startswith('Mined')
               and os.path.normcase(os.path.normpath(Path(p).relative_to(ROOT))) not in have)
rel = [Path(f).relative_to(ROOT).as_posix() for f in files]
(ROOT / 'work/native-client/uninventoried.txt').write_text('\n'.join(rel))
print('uninventoried', len(rel), flush=True)
if '--dry-run' in sys.argv:
    sys.exit(0)
# Windows caps a command line at 32K characters: sequential families of 200 TUs (each prove-<first stem>).
log = open(ROOT / 'work/native-client/prove-uninventoried.log', 'a')
for i in range(0, len(rel), 200):
    batch = rel[i:i + 200]
    print('batch', i // 200, len(batch), flush=True)
    subprocess.run([sys.executable, str(ROOT / 'work/native-client/prove.py'), '--quiet', '--rounds', '2', *batch],
                   cwd=ROOT, stdout=log, stderr=subprocess.STDOUT,
                   creationflags=getattr(subprocess, 'BELOW_NORMAL_PRIORITY_CLASS', 0))
print('done', flush=True)
