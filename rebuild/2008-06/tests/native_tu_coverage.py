"""Native-source coverage of one original translation unit: which functions in an address range
are exact from the listed native-classes files (each compiled with its pinned flags).
usage: native_tu_coverage.py LO-HI native-classes/A.cpp [...]"""
import json, re, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
lo, hi = (int(x, 16) for x in sys.argv[1].split('-'))
covered = {}
for src in sys.argv[2:]:
    out = subprocess.run([sys.executable, str(Path(__file__).with_name('check_native_class.py')), src, sys.argv[1].join(['range=', ''])],
                         capture_output=True, text=True).stdout
    for line in out.splitlines():
        m = re.match(r'([0-9a-f]{8}) (\S+)', line)
        if m:
            covered.setdefault(m[1], (Path(src).stem, m[2]))
rows = [json.loads(l) for l in open(ROOT / 'work/2008-06/functions.jsonl')]
unit = [(r['addr'], r['size']) for r in rows if lo <= int(r['addr'], 16) < hi and r.get('kind', 'code') == 'code']
done = sum(s for a, s in unit if a in covered)
print('native exact: %d/%d functions, %d/%d bytes' % (sum(a in covered for a, _ in unit), len(unit), done, sum(s for _, s in unit)))
print('missing:', ' '.join('%s:%d' % (a, s) for a, s in unit if a not in covered))
