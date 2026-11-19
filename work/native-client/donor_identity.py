"""Identity rows for donor-unit wrappers (rebuild/2008-06/native-classes/donor_i/...).  Each wrapper compiles the
unit the mining server verified byte-exact for specific addresses (listed in the wrapper's header comment).  For such
an address A, the symbol of that wrapper that compiled byte-equal to A is bound to A when it is the only one - the
same rule lane_identity.py applies to lane-proven files.  The census still audits bytes, relocations and references.
Reads every prove-out/*/ledger.json that holds donor_i entries.  -> donor-identity-bindings.json
  python work/native-client/donor_identity.py   (refuses to write while a census runs)"""
import collections
import glob
import gzip
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
picks = collections.defaultdict(set)          # address -> symbols byte-equal to it in its own donor wrapper
for led_path in glob.glob(str(HERE / 'prove-out/*/ledger.json')):
    fam = Path(led_path).parent
    try:
        ledger = json.loads(Path(led_path).read_text())
    except (OSError, ValueError):
        continue
    for key, entry in ledger.items():
        if '/donor_i/' not in key:
            continue
        wrapper = ROOT / key.split(':', 1)[1]
        if not wrapper.is_file():
            continue
        targets = set(re.findall(r'\b[0-9a-f]{8}\b', '\n'.join(wrapper.read_text(errors='replace').splitlines()[:6])))
        rows = entry.get('harvest_rows')
        if rows is None and entry.get('harvest_ref') and (fam / 'rows' / entry['harvest_ref']).is_file():
            rows = json.load(gzip.open(fam / 'rows' / entry['harvest_ref']))
        if isinstance(rows, str):
            rows = json.loads(rows)
        for r in rows or []:
            cands = r.get('candidates') or '[]'
            for a in (json.loads(cands) if isinstance(cands, str) else cands):
                if a in targets:
                    picks[a].add(r['symbol'])
out, stat = [], collections.Counter()
for a, symbols in sorted(picks.items()):
    if len(symbols) != 1:
        stat['several symbols'] += 1
        continue
    out.append({'symbol': next(iter(symbols)), 'address': a, 'votes': 1,
                'identity_evidence': 'donor unit mined byte-exact for this address; its sole byte-equal symbol'})
used = collections.Counter(b['symbol'] for b in out)
stat['symbol picked for several addresses'] = sum(1 for b in out if used[b['symbol']] > 1)
print('donor identity bindings: %d %s' % (len(out), dict(stat)))
(HERE / 'donor-identity-bindings.json').write_text(json.dumps(
    {'scope': 'identity evidence only: donor-unit wrappers and the addresses they were mined for (donor_identity.py)',
     'sources': {}, 'identity_bindings': out}, indent=1))
