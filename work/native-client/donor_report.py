"""Report on the donor-unit lane: for every remaining function with a donor-unit analog (creator-partition/
donor-units.json), what the latest donor wrapper prove says: exact, byte-equal (which symbol; does it carry the
registry's real name or a miner's placeholder), or no byte-equal body.  Read-only.
  python work/native-client/donor_report.py [PROVE_FAMILY_DIR]"""
import collections
import glob
import gzip
import json
import os
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv, argv = sys.argv[:1], sys.argv[1:]
sys.path.insert(0, str(HERE))
import native_llm as m  # noqa: E402

units = json.loads((HERE / 'creator-partition/donor-units.json').read_text())
want = {a: k for k, v in units.items() for a in v}
reg = m.load_registry()
fam = Path(argv[0]) if argv else Path(sorted((p for p in glob.glob(str(HERE / 'prove-out/prove-*')) if os.path.isdir(p)),
                                             key=os.path.getmtime)[-1])
ledger = json.loads((fam / 'ledger.json').read_text())
state = {}
for entry in ledger.values():
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (fam / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(fam / 'rows' / entry['harvest_ref']))
    if isinstance(rows, str):
        rows = json.loads(rows)
    for r in rows or []:
        cands = r.get('candidates') or '[]'
        for a in (json.loads(cands) if isinstance(cands, str) else cands):
            if a in want:
                prev = state.get(a)
                rank = 2 if r.get('status') == 'inactive_exact' else 1
                if not prev or rank > prev[0]:
                    state[a] = (rank, r['symbol'])
counts, real, out = collections.Counter(), collections.Counter(), {}
for a, key in want.items():
    recipe, path = key.split('|')[:2]
    authentic = not path.startswith('roc_')
    if a not in state:
        counts['no byte-equal body'] += 1
        continue
    rank, symbol = state[a]
    name = (reg.get(a) or {}).get('name') or ''
    placeholder = bool(re.search(r'sub_[0-9a-f]{6,8}|func_[0-9a-f]{6,8}|FUN_', symbol))
    kind = 'registry name' if symbol == name else 'placeholder name' if placeholder else 'other real-looking name'
    counts['exact' if rank == 2 else 'byte-equal, identity open'] += 1
    real[('authentic donor file' if authentic else 'mined roc_ unit', kind)] += 1
    out[a] = {'symbol': symbol, 'unit': path, 'recipe': recipe, 'exact': rank == 2, 'name_kind': kind}
print('family', fam.name, '| targets', len(want), dict(counts))
for k, v in real.most_common():
    print('  %4d  %s / %s' % (v, k[0], k[1]))
(HERE / 'donor-report.json').write_text(json.dumps(out, indent=1))
