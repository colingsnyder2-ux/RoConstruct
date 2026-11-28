"""python rescore.py: exact_check every AutoRecover draft in chunks; writes auto/scores.txt (one exact_check line per draft)."""
import glob, os, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
srcs = sorted('native-classes/' + os.path.basename(f) for f in glob.glob(str(ROOT / 'rebuild/2008-06/native-classes/AutoRecover_*.cpp')))
out = open(H / 'auto/scores.txt', 'w')
for i in range(0, len(srcs), 150):
    r = subprocess.run([sys.executable, str(H / 'exact_check.py')] + srcs[i:i + 150], capture_output=True, text=True, cwd=ROOT)
    out.write(r.stdout); out.flush()
    print('chunk', i // 150 + 1, 'of', (len(srcs) + 149) // 150, flush=True)
