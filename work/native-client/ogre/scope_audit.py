"""Audit original Ogre addresses, never the union of byte-match candidates.

An exact candidate is not recovery until its accepted row.addr passes references.
This report does not park targets automatically or grant runtime/server credit.
"""
import argparse
from collections import defaultdict
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

import run_all

ROOT = run_all.ROOT
PREFIXES = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')


def audit(manifest, inferred):
    scope = set(run_all.roots(PREFIXES))
    functions = run_all.match._functions('2008-06')
    sizes = {addr: len(run_all.match.target('2008-06', addr)[0]) for addr in scope}
    accepted = defaultdict(list)
    candidates = defaultdict(list)
    inferred_symbols = {r['symbol'] for r in inferred.get('rows', []) if r.get('inferred_name')}
    for family in manifest['families']:
        for row in family['symbols']:
            # Exception/unwind metadata aliases are not additional scope functions.
            if row['symbol'].startswith(('__', '$')):
                continue
            addr = row.get('addr')
            if row['status'] == 'inactive_exact' and addr in scope:
                accepted[addr].append(row['symbol'])
            elif row['status'] == 'draft':
                for rejection in row.get('rejections', []):
                    addr = rejection.get('addr')
                    if addr in scope and addr in row.get('candidates', []):
                        candidates[addr].append({'symbol': row['symbol'],
                                                 'errors': rejection.get('errors', [])})
    records = []
    for addr in sorted(scope):
        row = {'address': addr, 'bytes': sizes[addr], 'unit': functions[addr].get('unit'),
               'status': 'inactive_exact' if addr in accepted else 'untriaged',
               'source_packet': 'src/2008-06/' + addr + '.cpp'}
        if addr in accepted:
            row['accepted_symbols'] = sorted(set(accepted[addr]))
            row['inferred_name'] = any(s in inferred_symbols for s in accepted[addr])
        elif addr in candidates:
            row['status'] = 'byte_candidate_blocked'
            row['candidate_rejections'] = sorted(candidates[addr],
                key=lambda r: (len(r['errors']), len(r['symbol']), r['symbol']))
        records.append(row)
    named = {r['address'] for r in records if r.get('inferred_name')}
    remaining = scope - set(accepted)
    totals = {
        'scope_functions': len(scope), 'scope_bytes': sum(sizes.values()),
        'inactive_exact_functions': len(accepted),
        'inactive_exact_bytes': sum(sizes[a] for a in accepted),
        'remaining_functions': len(remaining), 'remaining_bytes': sum(sizes[a] for a in remaining),
        'inferred_name_functions': len(named), 'inferred_name_bytes': sum(sizes[a] for a in named),
        'inferred_name_note': ('Counts accepted owner symbols marked inferred; does not audit '
                               'dependencies on inferred reference names.'),
        'inferred_name_dependency_functions': None,
        'inferred_field_functions': None,
        'inferred_field_note': 'Separate field/layout dependence audit remains required; names are counted above.',
    }
    assert totals['inactive_exact_bytes'] + totals['remaining_bytes'] == totals['scope_bytes']
    return {'timestamp': datetime.now(timezone.utc).isoformat(),
            'scope': 'Inactive byte/reference proof only; no selected/runtime/server/P5/P6 credit.',
            'totals': totals, 'functions': records}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('--inferred', type=Path,
        default=ROOT / 'work/native-client/inferred-name-identities.json')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--pinned-native', type=Path,
        help='Check existing bytes AND added/deleted native filenames against this snapshot.')
    args = parser.parse_args()
    raw = args.manifest.read_bytes()
    result = audit(json.loads(raw), json.loads(args.inferred.read_text()))
    result['manifest_sha256'] = hashlib.sha256(raw).hexdigest()
    result['manifest'] = str(args.manifest.resolve())
    if args.pinned_native:
        pinned = json.loads(args.pinned_native.read_text())
        current = {str(p): hashlib.sha256(p.read_bytes()).hexdigest()
                   for directory in ('native-classes', 'native-headers')
                   for p in (Path('rebuild/2008-06') / directory).rglob('*') if p.is_file()}
        result['native_inputs'] = {
            'changed': sorted(k for k in pinned.keys() & current.keys() if pinned[k] != current[k]),
            'added': sorted(current.keys() - pinned.keys()),
            'deleted': sorted(pinned.keys() - current.keys()),
        }
        result['native_input_set_unchanged'] = not any(result['native_inputs'].values())
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=1))
    print(json.dumps(result['totals']))


if __name__ == '__main__':
    main()
