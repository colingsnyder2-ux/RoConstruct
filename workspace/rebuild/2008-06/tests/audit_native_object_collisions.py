"""Check native compiler-run objects for duplicate non-COMDAT definitions."""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('results', type=Path)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
rows = json.loads(args.results.read_text())
cache = {}
def sha(path):
    p = Path(path)
    if p not in cache:
        cache[p] = hashlib.sha256(p.read_bytes()).hexdigest()
    return cache[p]
providers = defaultdict(list)
objects = []
drift = []
for row in rows:
    assert row['status'] == 'complete' and row['compiler_exit'] == 0, row['source']
    for path, digest in {row['source']:row['source_sha256'], **row['dependencies']}.items():
        if not Path(path).exists() or sha(path) != digest:
            drift.append(path)
    obj = Path(row['object'])
    assert sha(obj) == row['object_sha256'], obj
    raw = obj.read_bytes()
    sections, _, definitions, _ = match._coff_data_index(raw)
    for name, defined in rebuild.coff_externals(raw).items():
        if defined and name in definitions:
            _, section = definitions[name]
            providers[name].append({'object':str(obj), 'comdat':bool(sections[section][9] & 0x1000)})
    objects.append({'source':row['source'], 'object':str(obj), 'sha256':sha(obj)})
assert not drift, ('compile input drift', sorted(set(drift))[:20])
collisions = [{'symbol':name, 'definitions':values} for name,values in providers.items() if sum(not item['comdat'] for item in values)>1]
result = {'scope':'Current isolated native objects: duplicate non-COMDAT external definitions only. COMDAT selection, unresolved symbols, libraries, ABI and executable link/runtime are not checked.', 'results_sha256':sha(args.results), 'objects':objects, 'external_symbols':len(providers), 'collisions':collisions}
args.output.parent.mkdir(parents=True,exist_ok=True)
args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(f'{len(objects)} objects, {len(providers)} symbols, {len(collisions)} non-COMDAT collisions')
if collisions:
    sys.exit(1)
