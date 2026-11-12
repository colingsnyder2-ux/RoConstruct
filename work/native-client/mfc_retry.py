"""Retry failed upstream-lane files with a different CRT flag: python mfc_retry.py PREFIX FROM TO  (e.g. Mfc /MD /MT)."""
import shutil
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import upstream_lane as lane  # noqa: E402

prefix, old, new = sys.argv[1:4]
kept = total = 0
for folder in sorted((lane.FAILED).glob(prefix + '*')):
    for src in folder.glob('*.cpp'):
        dest = lane.CLASSES / src.name
        if dest.exists():
            continue
        text = src.read_bytes().decode('utf-8', 'replace')
        first, sep, rest = text.partition(chr(13) + chr(10))
        if not first.startswith('// native-flags: ') or (' ' + old + ' ') not in (first + ' '):
            continue
        dest.write_bytes((first.replace(' ' + old + ' ', ' ' + new + ' ', 1) + sep + rest).encode('utf-8', 'replace'))
        row = lane.prove(dest)
        if row and row['exact']:
            kept += 1
            total += row['exact_bytes']
            print('%-34s %4d exact %7d B' % (dest.name, row['exact'], row['exact_bytes']), flush=True)
        else:
            err = lane.compile_error(dest)
            dest.unlink()
            print('%-34s none  %s' % (dest.name, (err or 'no exact function')[:100]), flush=True)
print('kept %d files, %d exact bytes' % (kept, total))
