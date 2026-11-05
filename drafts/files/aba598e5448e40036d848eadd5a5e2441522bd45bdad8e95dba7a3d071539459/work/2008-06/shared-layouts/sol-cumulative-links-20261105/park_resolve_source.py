"""Keep the genuine best near-match as inactive reference; archive all rejections."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
digest = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
canonical = ROOT / 'rebuild/2008-06/native-classes/ArchiveBinderResolve.cpp'
h1 = ROOT / 'work/2008-06/shared-layouts/sol-archive-resolve-guards-20261105/H1-source.cpp'
assert digest(canonical) == 'fcbf9d854dfa63eb4cb6646deadff54416d7a9328c1db362a52280ec60544f81'
assert digest(h1) == 'c49296ed0b3948ae2cbabe988031fcc4f24c0109c04b5de0cb16d1290d3d2c0b'
archived = HERE / 'parked-resolve-H3.cpp'
archived.write_bytes(canonical.read_bytes())
canonical.write_bytes(h1.read_bytes())
assert digest(canonical) == digest(h1)
projection = {
    'status': 'PARKED; no accepted native resolveRefs provider; three rejected hypotheses',
    'canonical_source': str(canonical), 'canonical_sha256': digest(canonical),
    'reason': 'Restore genuine donor-body H1 as the inactive reference rather than leave a rejected control-flow experiment as the reference source.',
    'rejected_H3_source': str(archived), 'rejected_H3_sha256': digest(archived),
    'hypothesis_receipts': [str(ROOT / 'work/2008-06/shared-layouts' / task / 'summary.json') for task in (
        'sol-archive-resolve-20261105', 'sol-archive-resolve-guards-20261105', 'sol-archive-resolve-final-20261105')],
    'source_projection_session': '1e9ae82220f6408593d89957bd3e425d',
    'source_lease': 'SolResolveParkProjection20261105',
    'selected_in_diagnostic': False, 'additional_compiles_authorized': 0, 'compiles': 0,
    'scope': 'Reference restoration only. No current object/archive/command input or selection changed. Prior failed-object receipts are historical diagnostics; canonical source now holds genuine H1.'}
(HERE / 'parked-resolve-projection.json').write_text(json.dumps(projection, indent=2) + '\n')
print(json.dumps({'restored_genuine_source': digest(canonical), 'preserved_H3': digest(archived), 'compiles': 0}))
