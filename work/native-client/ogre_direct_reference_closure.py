"""Bind unknown Ogre names from direct calls in closure-bound exact native bodies.

Each receipt is identity evidence only: a named closure-bound caller is byte-exact,
and its REL32 COFF relocation resolves to exactly one source-backed Ogre address.
The same emitted callee symbol must vote for one address across all callers.
"""
import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from roc.native_bulk import Targets, audit_references  # noqa: E402


def exact_at(body, relocs, address, targets):
    try:
        target, target_relocs = targets.body(address)
    except (KeyError, ValueError):
        return None
    if (len(body) != len(target) or not set(target_relocs) <= set(relocs)
            or not match.exact_match(target, target_relocs, body, relocs)):
        return None
    return body, target, target_relocs


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--objects-dir', type=Path, required=True)
    ap.add_argument('--registry', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    registry = json.loads(args.registry.read_text())
    wanted = {address for address, row in registry.items() if row.get('placeholder')}
    closure = json.loads(args.closure.read_text())['bindings']
    bindings = {row['symbol']: row['addr'].lower() for row in closure}
    targets, votes = Targets('2008-06'), defaultdict(lambda: defaultdict(set))
    callers = 0
    for obj in sorted(args.objects_dir.glob('Native*.obj')):
        raw = obj.read_bytes()
        for symbol, body, object_relocs in match.coff_functions(raw):
            address = bindings.get(symbol)
            if not address:
                continue
            proved = exact_at(body, object_relocs, address, targets)
            if not proved:
                continue
            callers += 1
            body, target, relocs = proved
            try:
                refs, _ = audit_references(raw, symbol, body, target, relocs, int(address, 16), targets, bindings)
            except (KeyError, ValueError, IndexError):
                continue
            for ref in refs:
                # REL32 is a call/jump.  Absolute references can be code pointers or data.
                if ref['kind'] == 20 and ref['symbol'] not in bindings and ref['address'] in wanted:
                    votes[ref['symbol']][ref['address']].add(f'{obj.name}:{symbol}')
    rows = []
    for symbol, addresses in sorted(votes.items()):
        if len(addresses) != 1:
            continue
        address, evidence = next(iter(addresses.items()))
        rows.append({'symbol': symbol, 'addr': address, 'passing': [address], 'rescued': True,
                     'direct': True, 'evidence': sorted(evidence)})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(rows, indent=1) + '\n')
    print(json.dumps({'exact_callers': callers, 'candidate_symbols': len(votes), 'rescued': len(rows)}, sort_keys=True))


if __name__ == '__main__':
    main()
