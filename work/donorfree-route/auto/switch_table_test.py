"""Compare audited switch destinations against the original client."""
import json
from pathlib import Path
import pefile
import re
import struct
import sys
root = Path(__file__).resolve().parents[1]
orig = pefile.PE(str(root / 'run/RobloxOrig.exe'), fast_load=True)
ours = pefile.PE(str(root / 'run/RobloxQT.exe'), fast_load=True)
records = json.loads((root / 'renamed/rename.json').read_text())
rows = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = line.split()
    if len(p) >= 4 and p[0].startswith('0001:') and re.fullmatch(r'[0-9a-f]{8}', p[2], re.I):
        rows[p[1]] = int(p[2], 16)
failed = 0
for table in json.loads((root / 'auto/switch_table_audit.json').read_text()):
    origbase = int(table['function'], 16)
    base = rows[records[table['function']]['symbol']]
    offset, count = int(table['table_offset'], 16), table['count']
    fmt = '<' + 'I' * count
    expected = [v - origbase for v in struct.unpack(fmt, orig.get_data(origbase + offset - orig.OPTIONAL_HEADER.ImageBase, count * 4))]
    got = [v - base for v in struct.unpack(fmt, ours.get_data(base + offset - ours.OPTIONAL_HEADER.ImageBase, count * 4))]
    ok = got == expected
    if not ok:
        print('FAIL', table['function'], hex(offset), got, 'expected', expected)
        failed += 1
print('switch tables:', 'FAIL' if failed else 'PASS', 'failed', failed)
sys.exit(bool(failed))
