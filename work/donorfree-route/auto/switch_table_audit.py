"""Find reordered switch tables where original and converted code share label offsets."""
from pathlib import Path
import bisect
import json
import re
import struct
import pefile
root = Path(__file__).resolve().parents[1]
records = json.loads((root / 'renamed/rename.json').read_text())
rows = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = line.split()
    if len(p) >= 4 and re.fullmatch(r'[0-9a-f]{8}', p[2], re.I) and p[0].startswith('0001:'):
        rows[p[1]] = int(p[2], 16)
functions = sorted((int(a, 16), rows[v['symbol']], a) for a, v in records.items() if v.get('symbol') in rows and v.get('status') == 'renamed')
keys = [v[0] for v in functions]
orig = pefile.PE(str(root / 'run/RobloxOrig.exe'), fast_load=True)
ours = pefile.PE(str(root / 'run/RobloxQT.exe'), fast_load=True)
od, qd = orig.get_memory_mapped_image(), ours.get_memory_mapped_image()
result = []
for match in re.finditer(rb'\xff\x24[\x85\x8d\x95\x9d\xa5\xad\xb5\xbd]', od[0x1000:0x3c0000]):
    rva = match.start() + 0x1000
    address = rva + 0x400000
    index = bisect.bisect_right(keys, address) - 1
    if index < 0:
        continue
    ob, qb, label = functions[index]
    offset = address - ob
    if offset > 0x10000:
        continue
    q = qb - 0x400000 + offset
    if q < 0 or q + 7 > len(qd) or qd[q:q+3] != od[rva:rva+3]:
        continue
    ot = struct.unpack_from('<I', od, rva+3)[0] - 0x400000
    qt = struct.unpack_from('<I', qd, q+3)[0] - 0x400000
    if not (0 <= ot < len(od)-16 and 0 <= qt < len(qd)-16):
        continue
    # Read local case labels until a non-label entry; four entries minimum.
    o, n = [], []
    for k in range(64):
        if ot + k*4 + 4 > len(od) or qt + k*4 + 4 > len(qd):
            break
        a = struct.unpack_from('<I', od, ot+k*4)[0] - ob
        b = struct.unpack_from('<I', qd, qt+k*4)[0] - qb
        if not (0 <= a < 0x10000 and 0 <= b < 0x10000):
            break
        o.append(a); n.append(b)
    if len(o) >= 4 and o != n and sorted(o) == sorted(n):
        result.append({'function': label, 'instruction': hex(address), 'table_offset': hex(ot + 0x400000 - ob), 'count': len(o), 'original': o, 'converted': n})
report = root / 'auto/switch_table_audit.json'
existing = json.loads(report.read_text()) if report.exists() else []
merged = {(r['function'], r['table_offset']): r for r in existing}
for item in result:
    merged.setdefault((item['function'], item['table_offset']), item)
report.write_text(json.dumps(list(merged.values()), indent=1))
print('reordered tables:', len(result), 'functions:', len({r['function'] for r in result}))
for r in result[:15]:
    print(r['function'], r['table_offset'], r['count'])
