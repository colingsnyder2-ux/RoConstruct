"""Inventory object-level native symbol providers and unresolved external references."""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild
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
requesters = defaultdict(list)
failed = []
drift = []
objects = []
for row in rows:
    if row.get('compiler_exit') != 0 or row.get('status') != 'complete':
        failed.append({'source':row['source'],'status':row.get('status'),'compiler_exit':row.get('compiler_exit'),'log':row.get('log')})
        continue
    for path,digest in {row['source']:row['source_sha256'],**row['dependencies']}.items():
        if not Path(path).exists() or sha(path) != digest:
            drift.append(path)
    obj=Path(row['object'])
    assert sha(obj)==row['object_sha256'], obj
    for symbol,defined in rebuild.coff_externals(obj.read_bytes()).items():
        (providers if defined else requesters)[symbol].append(row['source'])
    objects.append({'source':row['source'],'object':str(obj),'sha256':sha(obj)})
assert not drift, ('compile input drift',sorted(set(drift))[:20])
unresolved=[]
for symbol,sources in sorted(requesters.items()):
    if symbol not in providers:
        unresolved.append({'symbol':symbol,'requesters':sorted(set(sources)), 'import_symbol':symbol.startswith('__imp_')})
result={'scope':'External COFF symbol inventory across supplied native objects only. Not a linker: ignores weak externals, common-symbol rules, libraries, dead-code elimination, COMDAT selection, ABI and runtime. Failed source units excluded.', 'results_sha256':sha(args.results), 'objects':objects,'failed_sources':failed,'defined_symbol_count':len(providers),'referenced_symbol_count':len(requesters),'unresolved_count':len(unresolved),'unresolved_import_count':sum(x['import_symbol'] for x in unresolved),'unresolved':unresolved}
args.output.parent.mkdir(parents=True,exist_ok=True)
args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(f"{len(objects)} objects; {len(failed)} failed; {len(providers)} defined; {len(unresolved)} references without object provider ({result['unresolved_import_count']} import symbols)")
