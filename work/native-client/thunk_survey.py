"""Survey (no model): remaining 5-byte `jmp TARGET` thunks and what their targets are.
Such a thunk is a forwarding function (tail call); its identity is its target, not its registry name.
  python work/native-client/thunk_survey.py   -> jmp-thunks.json + printed counts"""
import collections
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
from roc import integration_site, match  # noqa: E402
import native_llm as m  # noqa: E402

reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
inactive = integration_site.inactive_code(ROOT)
counts, rows = collections.Counter(), []
for addr, v in cl.items():
    if v['size'] != 5:
        continue
    body = match.target('2008-06', addr)[0]
    if body[0] != 0xE9:
        counts['5 bytes, not a jmp'] += 1
        continue
    target = '%08x' % ((int(addr, 16) + 5 + struct.unpack('<i', body[1:5])[0]) & 0xffffffff)
    hit = inactive.get(target)
    name = (reg.get(target) or {}).get('signature') or (reg.get(target) or {}).get('name') or ''
    kind = 'target exact' if hit and hit[1] else 'target remaining' if target in cl else 'target not native yet'
    family = 'doDeclare' if 'doDeclare' in name else 'other function'
    counts[(kind, family)] += 1
    rows.append({'addr': addr, 'target': target, 'kind': kind, 'target_name': name[:160], 'bucket': v.get('bucket'),
                 'name': (reg.get(addr) or {}).get('signature') or v.get('name')})
(HERE / 'jmp-thunks.json').write_text(json.dumps(rows, indent=1))
print('remaining functions of 5 bytes:', sum(1 for v in cl.values() if v['size'] == 5))
for key, n in counts.most_common():
    print(n, key)
print('sizes:', collections.Counter(v['size'] for v in cl.values()).most_common(6))
for row in rows[:8]:
    print(row['addr'], '->', row['target'], row['kind'], '|', row['target_name'][:80])
