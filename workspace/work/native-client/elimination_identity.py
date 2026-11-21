"""INFERRED identity tier by elimination (owner-approved 2026-11-17).  A symbol S compiled byte-equal to several
addresses is bound to remaining address A when every other address it matches is already credited (exact under some
symbol), A's only not-yet-credited candidate symbol is S, and the body is >= MIN_SIZE bytes.  Applied to a fixed point
(a binding can free the next).  The census still audits relocations and every reference.  Rows are labelled
'inferred: elimination' for later review.  -> elimination-identity-bindings.json
  python work/native-client/elimination_identity.py   (refuses while a census runs)"""
import collections
import gzip
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
MIN_SIZE = 16
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
sys.path.insert(0, str(ROOT))
from roc import integration_site  # noqa: E402

FAMILY = HERE / 'prove-out/OgreNativeFull'
exact = {a: v[0] for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
credited = set(exact.values())
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - set(exact)
s2a, a2s, size = collections.defaultdict(set), collections.defaultdict(set), {}
for entry in json.loads((FAMILY / 'ledger.json').read_text()).values():
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (FAMILY / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(FAMILY / 'rows' / entry['harvest_ref']))
    if isinstance(rows, str):
        rows = json.loads(rows)
    for r in rows or []:
        cands = r.get('candidates') or '[]'
        for a in (json.loads(cands) if isinstance(cands, str) else cands):
            s2a[r['symbol']].add(a)
            a2s[a].add(r['symbol'])
            size[r['symbol']] = int(r.get('size') or 0)
free_s = {s: {a for a in addrs if a in remaining} for s, addrs in s2a.items() if s not in credited}
free_a = {a: {s for s in a2s[a] if s not in credited} for a in remaining if a in a2s}
bound, changed = {}, True
while changed:
    changed = False
    taken = set(bound.values())
    for a, symbols in list(free_a.items()):
        symbols = symbols - taken
        if len(symbols) != 1:
            continue
        s = next(iter(symbols))
        if {x for x in free_s.get(s, ()) if x not in bound} == {a} and size.get(s, 0) >= MIN_SIZE:
            bound[a] = s
            taken.add(s)
            free_a.pop(a)
            changed = True
out = [{'symbol': s, 'address': a, 'votes': 1,
        'identity_evidence': 'inferred: elimination (sole uncredited byte-equal pair, %d bytes)' % size[s]}
       for a, s in sorted(bound.items())]
print('elimination bindings: %d' % len(out))
(HERE / 'elimination-identity-bindings.json').write_text(json.dumps(
    {'scope': 'INFERRED identity tier: elimination over byte-equal candidates (elimination_identity.py), review later',
     'sources': {}, 'identity_bindings': out}, indent=1))
