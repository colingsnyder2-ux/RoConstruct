"""Reject trial-header dependencies in native source candidates."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
paths = [Path(arg) if Path(arg).is_absolute() else ROOT / arg for arg in sys.argv[1:]]
if not paths:
    paths = sorted((ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'))
bad = []
for path in paths:
    for number, line in enumerate(path.read_text(encoding='utf-8-sig', errors='replace').splitlines(), 1):
        if re.search(r'#include\s+[<"]\.\./tests/', line):
            bad.append('%s:%d: %s' % (path.relative_to(ROOT), number, line.strip()))
if bad:
    print('\n'.join(bad))
    raise SystemExit(1)
print('PASS native source hygiene: %d files' % len(paths))
