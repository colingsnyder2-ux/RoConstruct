"""Monotonic merge of two identity closures.

Keep every binding from a trusted base closure.  Add only candidate symbols not
already bound by base; contradictory candidate bindings are recorded, never
chosen.  This lets newly compiled real objects contribute identities even when
an old cache directory is no longer complete.
"""
import argparse
import json
from pathlib import Path


def load(path):
    return json.loads(path.read_text())


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--base', type=Path, required=True)
    ap.add_argument('--candidate', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    base, candidate = load(args.base), load(args.candidate)
    bindings = list(base.get('bindings', []))
    by_symbol = {row['symbol']: row for row in bindings}
    added, conflicts = [], []
    for row in candidate.get('bindings', []):
        existing = by_symbol.get(row['symbol'])
        if existing is None:
            bindings.append(row)
            by_symbol[row['symbol']] = row
            added.append(row)
        elif existing['addr'] != row['addr']:
            conflicts.append({'symbol': row['symbol'], 'base': existing['addr'], 'candidate': row['addr']})
    bindings.sort(key=lambda row: (row['addr'], row['symbol']))
    addresses = {row['addr'] for row in bindings}
    summary = dict(base.get('summary', {}))
    summary.update({'bound_symbols': len(bindings), 'bound_addresses': len(addresses),
                    'body_exact': sum(bool(row.get('body_exact')) for row in bindings)})
    out = {'scope': 'monotonic merge: base bindings retained; only nonconflicting candidate symbols added',
           'base': str(args.base), 'candidate': str(args.candidate), 'summary': summary,
           'bindings': bindings,
           'merge': {'base_bindings': len(base.get('bindings', [])), 'candidate_bindings': len(candidate.get('bindings', [])),
                     'added': len(added), 'conflicts': conflicts}}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps({'base': out['merge']['base_bindings'], 'candidate': out['merge']['candidate_bindings'],
                      'added': out['merge']['added'], 'conflicts': len(conflicts),
                      'bound_symbols': summary['bound_symbols'], 'bound_addresses': summary['bound_addresses']}))


if __name__ == '__main__':
    main()
