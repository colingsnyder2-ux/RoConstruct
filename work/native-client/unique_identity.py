"""Inferred identity tier (owner 2026-11-16: inferred names allowed, fix later): bind symbol S to remaining address A
when, across the whole census ledger, A is a body-byte-equal candidate of exactly one symbol, S has exactly one
candidate address, neither is bound elsewhere, and the body is at least MIN_SIZE bytes (tiny shared bodies - thunks,
`return this` stubs - never qualify).  The census still requires relocation and reference audits to pass, so a wrong
pick fails there.  Labelled 'inferred: unique body match' for later review.  -> unique-identity-bindings.json
  python work/native-client/unique_identity.py   (refuses while a census runs)"""
import collections
import gzip
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
MIN_SIZE = 24
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
sys.path.insert(0, str(ROOT))
from roc import integration_site  # noqa: E402

FAMILY = HERE / 'prove-out/OgreNativeFull'
exact = {a: v[0] for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
exact_symbols = set(exact.values())
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - set(exact)
sym_addrs, addr_syms, size = collections.defaultdict(set), collections.defaultdict(set), {}
for entry in json.loads((FAMILY / 'ledger.json').read_text()).values():
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (FAMILY / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(FAMILY / 'rows' / entry['harvest_ref']))
    for r in rows or []:
        cands = r.get('candidates') or '[]'
        cands = json.loads(cands) if isinstance(cands, str) else cands
        for a in cands:
            if isinstance(a, str):
                sym_addrs[r['symbol']].add(a)
                addr_syms[a].add(r['symbol'])
                size[r['symbol']] = int(r.get('size') or 0)
bound = collections.defaultdict(set)
for f in HERE.glob('*identity-bindings*.json'):
    if f.name == 'unique-identity-bindings.json':
        continue
    try:
        data = json.loads(f.read_text())
    except (OSError, ValueError):
        continue
    for b in (data.get('identity_bindings') or data.get('bindings') or []) if isinstance(data, dict) else []:
        if isinstance(b, dict) and b.get('address'):
            bound[b['address']].add(b.get('symbol'))
out, stat = [], collections.Counter()
for a in sorted(remaining):
    syms = addr_syms.get(a, set())
    if len(syms) != 1:
        stat['not-unique-%s' % ('none' if not syms else 'many')] += 1
        continue
    s = next(iter(syms))
    if len(sym_addrs[s]) != 1:
        stat['symbol-many-addresses'] += 1
        continue
    if s in exact_symbols:
        stat['symbol-already-exact-elsewhere'] += 1
        continue
    if bound.get(a, set()) - {s}:
        stat['address-bound-to-other-symbol'] += 1
        continue
    if size.get(s, 0) < MIN_SIZE:
        stat['too-small'] += 1
        continue
    out.append({'symbol': s, 'address': a, 'votes': 1,
                'identity_evidence': 'inferred: unique body match (sole byte-equal candidate both ways, %d bytes)' % size[s]})
    stat['bound'] += 1
print(dict(stat))
(HERE / 'unique-identity-bindings.json').write_text(json.dumps(
    {'scope': 'INFERRED identity tier: symmetric unique byte-equal body matches (unique_identity.py), review later',
     'sources': {}, 'identity_bindings': out}, indent=1))
