"""Batch binary-proven MSVC vtable-store evidence for native recovery."""
import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rtti


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--inventory', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--skip', type=int, default=0)
    ap.add_argument('--limit', type=int, default=500)
    args = ap.parse_args()
    inventory = json.loads(args.inventory.read_text())
    units = inventory['mined_units'][args.skip:args.skip + args.limit]
    headers, native = inventory['header_classes'], inventory['native_methods']
    rows = []
    blocked = []
    for unit in units:
        if not unit.get('mined_body'):
            blocked.append({'addr': unit['addr'], 'reason': 'vendor replay-only packet'})
            continue
        try:
            stores = rtti.vtable_stores('2008-06', unit['addr'])
        except BaseException as exc:
            blocked.append({'addr': unit['addr'], 'reason': str(exc)[:160]})
            continue
        if stores:
            owners = []
            for store in stores:
                name = store['type'].split('@', 1)[0].removeprefix('.?AV').removeprefix('.?AU')
                owners.append({'class': name, 'headers': headers.get(name, []),
                               'native_sources': native.get(name, [])})
            rows.append({'addr': unit['addr'], 'unit': unit['unit'], 'vtable_stores': stores,
                         'owner_candidates': owners,
                         'routable': any(x['headers'] and x['native_sources'] for x in owners),
                         'unit_confirms_owner': any(x['class'] in unit['unit'] for x in owners)})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps({'skip': args.skip, 'checked': len(units), 'owners': rows,
                                       'blocked': blocked}, indent=1) + '\n')
    print('checked', len(units), 'owner-evidence', len(rows), 'blocked', len(blocked))


if __name__ == '__main__':
    main()
