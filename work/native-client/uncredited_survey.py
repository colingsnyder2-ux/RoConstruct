"""Survey (no model): remaining functions that some per-source proof already shows as inactive exact, and why the
census does not count them (source not registered in the census inventory, source file gone, ...).
  python work/native-client/uncredited_survey.py  -> uncredited.json + counts"""
import collections
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
from roc import integration_site  # noqa: E402

for _try in range(5):
    try:
        inactive = integration_site.inactive_code(ROOT)
        break
    except FileNotFoundError:
        pass
cl = json.loads((HERE / 'remaining-classified.json').read_text())
inv = json.loads((HERE / 'ogre-native-full-inventory-all.json').read_text())['families'][0]
registered = {s.replace('\\', '/') for s in inv['sources']}
extra = set(json.loads((HERE / 'class-lane-new-sources.json').read_text()))
counts, rows = collections.Counter(), []
for addr, v in cl.items():
    hit = inactive.get(addr)
    if not hit:
        counts['no native body'] += 1
        continue
    if not hit[1]:
        counts['native body, not exact'] += 1
        continue
    source = hit[3][0].replace('\\', '/') if len(hit) > 3 and hit[3] else None
    family = str(hit[2])
    if not source:
        why = 'exact, source unknown'
    elif not (ROOT / source).is_file():
        why = 'exact, source file gone'
    elif source in registered:
        why = 'exact, source in census inventory (identity/evidence gap)'
    elif source in extra:
        why = 'exact, source only in class-lane-new-sources'
    else:
        why = 'exact, source not registered anywhere'
    counts[why] += 1
    rows.append({'addr': addr, 'why': why, 'family': family, 'source': source, 'symbol': hit[0], 'bucket': v.get('bucket'), 'size': v['size']})
(HERE / 'uncredited.json').write_text(json.dumps(rows, indent=1))
print('remaining (classified):', len(cl))
for key, n in counts.most_common():
    print('%5d  %s' % (n, key))
print('by family prefix:', collections.Counter(r['family'].split(':')[-1][:14] for r in rows).most_common(8))
print('by source:', collections.Counter(r['source'] for r in rows).most_common(12))
print('by bucket:', collections.Counter(r['bucket'] for r in rows).most_common(8))
