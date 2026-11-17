"""refbind.py FAMILY OUT.json : bind every 'unproven reference identity: SYM' of a prove family whose SYM is named by exactly one
address in remaining-classified.json / identity-registry.json (non-placeholder) / unnamed-identities*.json. Appends to OUT
(a trial evidence file for ROC_EXTRA_EVIDENCE). EH handler symbols are left to ehbind.py."""
import gzip, json, re, sys
from pathlib import Path
R = Path(__file__).resolve().parents[2]; W = R / 'work/native-client'
fam, out = sys.argv[1], Path(sys.argv[2])
names = {}
def add(n, a):
    if n: names.setdefault(n, set()).add(a)
for a, v in json.load(open(W / 'remaining-classified.json')).items(): add(v['name'], a)
for a, v in json.load(open(R / 'work/2008-06/identity-registry.json')).items():
    if not v.get('placeholder'): add(v.get('name'), a)
for f in ('unnamed-identities.json', 'unnamed-identities-inferred.json'):
    for a, v in json.load(open(W / f)).items(): add(v.get('name') or v.get('symbol') or v.get('inferred_name'), a)
p = W / 'prove-out' / fam / 'ledger.json'
want = set()
for e in json.load(open(p)).values():
    rows = e.get('harvest_rows')
    if rows is None and e.get('harvest_ref'): rows = json.load(gzip.open(p.parent / 'rows' / e['harvest_ref'], 'rt'))
    for r in rows or []:
        for c in r.get('rejections', []):
            for x in c['errors']:
                m = re.match(r'unproven reference identity: (.*)', x)
                if m and not m.group(1).startswith('__ehhandler'): want.add(m.group(1))
cur = json.load(open(out)) if out.is_file() else {'scope': 'reference identities named by exactly one address in the name tables', 'identity_bindings': []}
have = {(b['symbol'], b['address']) for b in cur['identity_bindings']}
n = amb = miss = 0
for s in sorted(want):
    a = names.get(s, set())
    if len(a) == 1 and (s, next(iter(a))) not in have:
        cur['identity_bindings'].append({'symbol': s, 'address': next(iter(a)), 'identity_evidence': 'unique address named by the name tables', 'votes': 1}); n += 1
    elif len(a) > 1: amb += 1
    elif not a: miss += 1
json.dump(cur, open(out, 'w'), indent=1)
print('bound', n, 'ambiguous', amb, 'unnamed', miss)
