"""Target-exact census for vendor wrappers: python vendor_measure.py <prove-out family dir name> -> prints/writes per-unit target_exact/total."""
import json, sys
from pathlib import Path
R = Path(__file__).resolve().parents[2]
fam = sys.argv[1]
m = json.load(open(R / 'work/native-client/prove-out' / fam / 'manifest.json'))
exact = {s['addr'].lower() for f in m['families'] for s in f['symbols'] if s['status'] == 'inactive_exact' and s.get('addr')}
units = json.load(open(R / 'work/native-client/creator-partition/vendor-units.json'))
tot = sum(len(v) for v in units.values()); hit = 0; rows = {}
for k, addrs in units.items():
    h = [a for a in addrs if a.lower() in exact]; hit += len(h); rows[k] = dict(target_exact=len(h), target_total=len(addrs), missing=[a for a in addrs if a not in h])
print('target exact %d / %d (all exact addrs %d)' % (hit, tot, len(exact)))
json.dump(rows, open(R / 'work/native-client/vendor-measure.json', 'w'), indent=1)
