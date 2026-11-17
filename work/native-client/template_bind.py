"""Bind template-instantiation symbols to addresses from the proven/inferred name tables.
  python work/native-client/template_bind.py FAMILY   (e.g. prove-PartToolFactories)
For every harvest row of that prove run rejected only for 'symbol identity not established', bind symbol->candidate
when remaining-classified.json / identity-registry / unnamed-identities(-inferred) name that address with that symbol.
Appends to work/native-client/template-identity-bindings.json."""
import json, sys
from pathlib import Path


def _ledger_rows(entry, ledger_path):
    """Harvest rows of a native_bulk ledger entry: inline (older ledgers) or its compressed rows file (rows/<ref>)."""
    if 'harvest_rows' in entry:
        return entry['harvest_rows']
    ref = entry.get('harvest_ref')
    path = Path(ledger_path).parent / 'rows' / ref if ref else None
    if not path or not path.is_file():
        return []
    import gzip
    with gzip.open(path, 'rt', encoding='utf-8') as stream:
        return json.load(stream)
R = Path(__file__).resolve().parents[2]
W = R / 'work/native-client'
OUT = W / 'template-identity-bindings.json'
names = {}
for a, v in json.load(open(R / 'work/2008-06/identity-registry.json')).items():
    if not v.get('placeholder') and v.get('name'): names[a] = ('registry', v['name'])
for f in ('unnamed-identities.json', 'unnamed-identities-inferred.json'):
    for a, v in json.load(open(W / f)).items():
        n = v.get('name') or v.get('symbol') or v.get('inferred_name')
        if n and a not in names: names[a] = (f, n)
        for alt in v.get('alternatives', []) or []:
            names.setdefault(a + '|' + alt, (f, alt))
for a, v in json.load(open(W / 'remaining-classified.json')).items():
    names.setdefault(a, ('remaining-classified', v['name']))
cur = json.load(open(OUT)) if OUT.is_file() else {'scope': 'template-instantiation identity evidence (names from identity-registry / unnamed-identities / remaining-classified)', 'identity_bindings': []}
have = {(b['symbol'], b['address']) for b in cur['identity_bindings']}
led = json.load(open(W / 'prove-out' / sys.argv[1] / 'ledger.json'))
n = 0
for e in led.values():
    for r in _ledger_rows(e, W / 'prove-out' / sys.argv[1] / 'ledger.json'):
        if r['status'] != 'draft': continue
        for c in r.get('rejections', []):
            if not any('symbol identity not established' in x for x in c['errors']): continue
            a = c['addr']; nm = names.get(a) or names.get(a + '|' + r['symbol'])
            if nm and nm[1] == r['symbol'] and (r['symbol'], a) not in have:
                cur['identity_bindings'].append({'symbol': r['symbol'], 'address': a, 'identity_evidence': nm[0], 'votes': 1}); have.add((r['symbol'], a)); n += 1
OUT.write_text(json.dumps(cur, indent=1))
print('bound', n)
