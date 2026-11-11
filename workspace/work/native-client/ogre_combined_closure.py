"""One identity closure for Ogre native gates: the Ogre merged closure plus registry proved names, import-thunk
identities and every binder round's reference identities. A symbol bound to two addresses anywhere is dropped.

  python work/native-client/ogre_combined_closure.py  -> work/native-client/ogre-combined-closure.json
"""
import json
import sys
from collections import defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

BASE = HERE / 'ogre-rbxscenemanager-shadow-merged-closure.json'
OUT = HERE / 'ogre-combined-closure.json'


def main():
    functions = set(match._functions('2008-06'))
    base = json.loads(BASE.read_text())
    candidates = defaultdict(set)
    rows = {}
    def add(symbol, addr, evidence, votes=1):
        addr = addr.lower()
        candidates[symbol].add(addr)
        rows.setdefault(symbol, {'symbol': symbol, 'addr': addr, 'evidence': evidence, 'votes': votes,
                                 'function_start': addr in functions})
    for row in base['bindings']:
        add(row['symbol'], row['addr'], row.get('evidence', 'closure'), row.get('votes', 1))
    registry = json.loads((HERE / 'ogre-names-registry.json').read_text())
    for addr, row in (registry.items() if isinstance(registry, dict) else ((r['addr'], r) for r in registry)):
        if isinstance(row, dict) and row.get('name') and not row.get('placeholder'):
            add(row['name'], addr, 'registry:' + str(row.get('name_source')))
    receipts = [HERE / 'import-thunk-identities.json', *sorted(HERE.glob('ogre-reference-bindings*.json'))]
    for path in receipts:
        for row in json.loads(path.read_text()).get('rows', []):
            add(row['symbol'], row['address'], path.name)
    conflicts = sorted(s for s, a in candidates.items() if len(a) > 1)
    bindings = [row for s, row in sorted(rows.items()) if s not in conflicts]
    out = dict(base, bindings=bindings, combined_from=[BASE.name, 'ogre-names-registry.json'] + [p.name for p in receipts],
               dropped_conflicts=conflicts)
    OUT.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps({'bindings': len(bindings), 'conflicts_dropped': len(conflicts)}))


if __name__ == '__main__':
    main()
