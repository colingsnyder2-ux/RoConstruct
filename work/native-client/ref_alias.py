"""Reference aliases from the census's own rejections (the rule the lane gates use: exact-target-coff-reference-alias).
For a body-byte-equal candidate address, the census reports each reference it could not prove:
  'reference identity differs: X (bound B, original reference O)'  -> X is referenced where the original references O
  'unproven reference identity: X' + references[{symbol: X, address: O}]
Bind X -> O unless O is already bound to a different symbol by any evidence (then our source likely calls the wrong
function: skipped).  The census re-audits bytes, relocations and every reference with these rows.
  -> ref-alias-bindings.json      python work/native-client/ref_alias.py   (refuses while a census runs)"""
import collections
import gzip
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
FAMILY = HERE / 'prove-out/OgreNativeFull'
DIFFERS = re.compile(r'reference identity differs: (\S+) \(bound [0-9a-f]+, original reference ([0-9a-f]{8})\)')
UNPROVEN = re.compile(r'unproven reference identity: (\S+)$')
bound = collections.defaultdict(set)
for f in HERE.glob('*bindings*.json'):
    if f.name == 'ref-alias-bindings.json':
        continue
    try:
        data = json.loads(f.read_text())
    except (OSError, ValueError):
        continue
    for b in (data.get('identity_bindings') or data.get('bindings') or []) if isinstance(data, dict) else []:
        if isinstance(b, dict) and b.get('address') and b.get('symbol'):
            bound[b['address']].add(b['symbol'])
pairs, stat = collections.Counter(), collections.Counter()
for entry in json.loads((FAMILY / 'ledger.json').read_text()).values():
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (FAMILY / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(FAMILY / 'rows' / entry['harvest_ref']))
    for r in rows or []:
        rej = r.get('rejections') or '[]'
        for x in (json.loads(rej) if isinstance(rej, str) else rej):
            if not isinstance(x, dict):
                continue
            refs = {}
            for ref in x.get('references') or []:
                if isinstance(ref, dict) and ref.get('symbol') and ref.get('address'):
                    refs.setdefault(ref['symbol'], set()).add(ref['address'])
            for e in x.get('errors', []):
                m = DIFFERS.match(e)
                if m:
                    pairs[(m.group(1), m.group(2))] += 1
                    continue
                m = UNPROVEN.match(e)
                if m and '__ehhandler$' not in m.group(1) and len(refs.get(m.group(1), ())) == 1:
                    pairs[(m.group(1), next(iter(refs[m.group(1)])))] += 1
out = []
for (sym, addr), votes in sorted(pairs.items()):
    if bound.get(addr, set()) - {sym}:
        stat['address-bound-to-other-symbol'] += 1
        continue
    if not re.fullmatch(r'[0-9a-f]{8}', addr):
        stat['bad-address'] += 1
        continue
    out.append({'symbol': sym, 'address': addr, 'votes': votes,
                'identity_evidence': 'exact-target-coff-reference-alias (census rejection of a byte-equal body)'})
    stat['bound'] += 1
print(dict(stat))
(HERE / 'ref-alias-bindings.json').write_text(json.dumps(
    {'scope': 'reference aliases from census rejections of byte-equal bodies (ref_alias.py)', 'sources': {},
     'identity_bindings': out}, indent=1))
