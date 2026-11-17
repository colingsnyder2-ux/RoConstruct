"""Identity rows for lane-proven files.  A lane file proves exactly one address (TmplInst_<addr>.cpp,
Inferred_<addr>.cpp): its gate asserted address = symbol for that check only, so the census rejects the same body as
"symbol identity not established by current reference evidence".  This reads the census ledger row of the lane's own
file, takes the symbol whose ONLY rejection at that address is the identity one, and writes
lane-identity-bindings.json (identity_bindings format; registered by the census lane).  The census still byte- and
reference-proves every row; a symbol that also matches other addresses is skipped.
  python work/native-client/lane_identity.py   (refuses while a census runs)"""
import gzip
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
FAMILY = HERE / 'prove-out/OgreNativeFull'
ledger = json.loads((FAMILY / 'ledger.json').read_text())
IDENTITY = 'symbol identity not established by current reference evidence'
out, stat = [], {}
LIVE = set()
for key, entry in ledger.items():
    hit = re.search(r'native-classes/(?:TmplInst|Inferred)_([0-9a-f]{8})\.cpp$', key)
    if not hit or not entry.get('harvest_ref'):
        continue
    addr = hit.group(1)
    if not (ROOT / key.split(':', 1)[1]).is_file():          # promote deleted the TU after a failed re-proof
        stat['file-gone'] = stat.get('file-gone', 0) + 1
        continue
    LIVE.add(addr)
    rows_path = FAMILY / 'rows' / entry['harvest_ref']
    if not rows_path.is_file():
        stat['no-rows'] = stat.get('no-rows', 0) + 1
        continue
    picks = []
    for row in json.load(gzip.open(rows_path)):
        rej = row.get('rejections') or '[]'
        rej = json.loads(rej) if isinstance(rej, str) else rej
        cands = row.get('candidates') or '[]'
        cands = json.loads(cands) if isinstance(cands, str) else cands
        mine = [r for r in rej if isinstance(r, dict) and r.get('addr') == addr]
        if row.get('status') == 'inactive_exact' and addr in cands:
            picks = []
            stat['already-exact'] = stat.get('already-exact', 0) + 1
            break
        # Bytes equal at this address (it is a candidate) and every rejection there is about identity - its own
        # (IDENTITY) or a reference's (callee / EH handler, covered by the alias rows below).
        if addr in cands and all(e == IDENTITY or e.startswith(('unproven reference identity', 'reference identity differs'))
                                 for r in mine for e in r.get('errors', [])):
            picks.append((len(cands), row['symbol']))
    if not picks:
        stat['no-identity-only-row'] = stat.get('no-identity-only-row', 0) + 1
        continue
    picks.sort()
    if len(picks) > 1 and picks[0][0] == picks[1][0]:
        # several symbols byte-equal here: keep the one naming this address (placeholder sub_<addr>) if any
        named = [s for _, s in picks if 'sub_' + addr in s]
        if len(named) != 1:
            stat['ambiguous'] = stat.get('ambiguous', 0) + 1
            continue
        picks = [(0, named[0])]
    out.append({'symbol': picks[0][1], 'address': addr, 'votes': 1,
                'identity_evidence': 'lane gate byte-proof of %s (sole source for this address)' % Path(key.split(':', 1)[1]).name})
    stat['bound'] = stat.get('bound', 0) + 1
# Callee / EH-handler identities the lane gate proved for its own object (native_reference_alias_bind output,
# exact-target-coff-reference-alias): the census rejects these bodies only for those references.
alias = []
for f in list(HERE.glob('template-instances/*/alias-*.json')) + list(HERE.glob('placeholder-lane/*/alias-*.json')):
    if f.parent.name not in LIVE:
        continue
    try:
        alias += [dict(b, identity_evidence='lane gate alias for %s: %s' % (f.parent.name, b.get('identity_evidence', '')))
                  for b in json.loads(f.read_text()).get('identity_bindings', [])]
    except (OSError, ValueError):
        pass
seen = {(b['symbol'], b['address']) for b in out}
alias = [b for b in alias if (b['symbol'], b['address']) not in seen and not seen.add((b['symbol'], b['address']))]
stat['alias-bindings'] = len(alias)
used = {}
for b in out:
    used[b['symbol']] = used.get(b['symbol'], 0) + 1
out = [b for b in out if used[b['symbol']] == 1]
# Earlier own-address bindings stay: once the census accepts one, that address's rejection moves on to a callee, so
# re-deriving it from the new rows would drop it.  Kept only while its lane file still exists.
prev_path = HERE / 'lane-identity-bindings.json'
prev = json.loads(prev_path.read_text()).get('identity_bindings', []) if prev_path.is_file() else []
have = {(b['symbol'], b['address']) for b in out}
taken = {b['symbol'] for b in out}
for b in prev:
    if (b['identity_evidence'].startswith('lane gate byte-proof') and b['address'] in LIVE
            and (b['symbol'], b['address']) not in have and b['symbol'] not in taken):
        out.append(b)
        have.add((b['symbol'], b['address']))
        taken.add(b['symbol'])
stat['own-kept'] = len(out)
out += [b for b in alias if (b['symbol'], b['address']) not in have]
print(stat, 'kept', len(out))
(HERE / 'lane-identity-bindings.json').write_text(json.dumps(
    {'scope': 'identity evidence only: lane-proven single-address files (lane_identity.py)', 'sources': {},
     'identity_bindings': out}, indent=1))
