"""Disambiguate identical MeshFactory code using independently bound references."""
import json
import pathlib
import runpy
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'work/native-client'))
from roc import native_bulk, match

trial = runpy.run_path(str(ROOT / 'work/native-client/identity-conflict-trial.py'))
seed, audit = trial['seed'], trial['audit']
inventory = json.loads((ROOT/'work/native-client/ogre-native-full-inventory-all.json').read_text())
_, bindings, blockers, _ = seed(ROOT, inventory['families'][0]['evidence'])
assert not blockers, blockers
manifest = json.loads((ROOT/'work/native-client/prove-out/prove-ViewNewPartMesh2008/manifest.json').read_text())
family = manifest['families'][0]
rows = [r for r in family['symbols'] if r['symbol'].startswith(('?createTexture@?$MeshFactory@', '?createDecal@?$MeshFactory@')) and len(r.get('candidates') or []) > 1]
raw = pathlib.Path(family['jobs'][0]['object']).read_bytes()
bodies = {name: body for name, body, _ in match.coff_functions(raw)}
addresses = {address for row in rows for address in row['candidates']}
targets = native_bulk.Targets('2008-06', addresses)
inferred = []
for row in rows:
    symbol, body = row['symbol'], bodies[row['symbol']]
    if symbol in bindings:
        continue
    viable, rejected = [], []
    for address in row['candidates']:
        target, relocations = targets.body(address)
        refs, errors = audit(raw, symbol, body, target, relocations, int(address,16), targets, bindings)
        unknown = [error for error in errors if not error.startswith('unproven reference identity: __ehhandler$')]
        if not unknown:
            viable.append((address, errors, refs))
        else:
            rejected.append((address, unknown))
    if len(viable) != 1 or len(rejected) != len(row['candidates']) - 1:
        continue
    address, errors, refs = viable[0]
    if not all(any(e.startswith('reference identity differs: ') for e in errors2) for _, errors2 in rejected):
        continue
    inferred.append({'symbol': symbol, 'address': address, 'inferred_name': True,
        'evidence': 'INFERRED: unique byte-compatible target after checking independent original constructor and cache identities; alternatives reject by reference identity',
        'alternatives': [{'address': a, 'errors': e} for a,e in rejected],
        'remaining_errors': errors, 'references': refs})
out = ROOT/'work/native-client/partchunk-invalidate-trial/mesh-owner-trial.json'
out.write_text(json.dumps({'scope':'scratch inferred identities, pending full proof', 'rows': inferred}, indent=2))
print('reference-disambiguated names:', len(inferred))
for r in inferred: print(r['address'], r['symbol'][:80], r['remaining_errors'])
