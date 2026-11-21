"""Which remaining 'template instantiation' addresses are inactive_exact in the given prove families' ledgers?
  python work/native-client/template_gain.py FAMILY..."""
import json, sys
from pathlib import Path
W = Path(__file__).resolve().parent
rem = {a: v for a, v in json.load(open(W / 'remaining-classified.json')).items() if v['bucket'] == 'template instantiation'}
got = {}
for fam in sys.argv[1:]:
    led = json.load(open(W / 'prove-out' / fam / 'ledger.json'))
    for e in led.values():
        rows = e.get('harvest_rows')
        if rows is None and e.get('harvest_ref'):
            import gzip
            rows = json.load(gzip.open(W / 'prove-out' / fam / 'rows' / e['harvest_ref'], 'rt'))
        for r in rows or []:
            if r['status'] == 'inactive_exact':
                for a in r.get('candidates') or []:
                    if a in rem and rem[a]['name'] == r['symbol']: got[a] = fam
print(len(got), sorted(got))
