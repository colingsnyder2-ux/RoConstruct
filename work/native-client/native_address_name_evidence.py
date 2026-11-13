#!/usr/bin/env python3
"""Turn an address->decorated-symbol map into native-bulk identity evidence."""
import argparse
import json
from pathlib import Path


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--names', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    names = json.loads(args.names.read_text())
    records = []
    for address, symbol in sorted(names.items()):
        if isinstance(symbol, str) and symbol:
            records.append({'symbol': symbol, 'address': address})
    args.output.write_text(json.dumps({
        'scope': 'address-name identity supplied by prior RTTI/vtable/header evidence; body proof remains native-bulk',
        'names': str(args.names), 'records': records,
    }, indent=1) + '\n')
    print('records=%d' % len(records))


if __name__ == '__main__':
    main()
