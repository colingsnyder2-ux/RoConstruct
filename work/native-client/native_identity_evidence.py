"""Make native-bulk evidence receipts from deterministic identity-closure bindings.

This does not generate code or grant proof.  It only carries a selected closed
symbol/address identity into native-bulk, with the closure hash as an input.
"""
import argparse
import hashlib
import json
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--addr', action='append', required=True)
    ap.add_argument('--extra-bindings', type=Path, action='append', default=[],
                    help='exact-owner reference-alias receipts')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    closure = args.closure.resolve()
    wanted = {f'{int(value, 16):08x}' for value in args.addr}
    closure_data = json.loads(closure.read_text())
    bindings = {row['addr']: row for row in closure_data['bindings']}
    missing = sorted(wanted - bindings.keys())
    if missing:
        raise ValueError('unbound addresses: ' + ', '.join(missing))
    rows = []
    for addr in sorted(wanted):
        row = bindings[addr]
        if not row.get('function_start'):
            raise ValueError('not a function-start binding: ' + addr)
        rows.append({'symbol': row['symbol'], 'address': addr,
                     'identity_evidence': row['evidence'], 'votes': row['votes']})
    # Reference auditing must also know a selected body's closure-bound
    # callees/data.  The closure has already removed conflicting symbols, so
    # carry its complete fixed point instead of guessing a dependency cut.
    selected_symbols = {row['symbol'] for row in rows}
    rows.extend({'symbol': row['symbol'], 'address': row['addr'],
                 'identity_evidence': row['evidence'], 'votes': row['votes']}
                for row in closure_data['bindings']
                if row['symbol'] not in selected_symbols)
    # The PE import table proves an IAT slot's exported spelling and target VA.
    # Keep only one-slot spellings: duplicate import spellings stay unbound just
    # like closure conflicts.
    from roc import standins
    imports = {}
    duplicates = set()
    for address, imported in standins._imports('2008-06').items():
        symbol = '__imp_' + imported.split('!', 1)[1]
        if symbol in imports and imports[symbol] != address:
            duplicates.add(symbol)
        else:
            imports[symbol] = address
    closure_symbols = {row['symbol'] for row in rows}
    rows.extend({'symbol': symbol, 'address': f'{address:08x}',
                 'identity_evidence': 'original-iAT', 'votes': 1}
                for symbol, address in sorted(imports.items())
                if symbol not in duplicates and symbol not in closure_symbols)
    by_symbol = {row['symbol']: row['address'].lower() for row in rows}
    for path in args.extra_bindings:
        extra = json.loads(path.read_text())
        for row in extra.get('identity_bindings', []):
            symbol, address = row['symbol'], row['address'].lower()
            if symbol in by_symbol and by_symbol[symbol] != address:
                raise ValueError('extra binding conflicts: ' + symbol)
            if symbol not in by_symbol:
                rows.append(dict(row, address=address))
                by_symbol[symbol] = address
    try:
        source = closure.relative_to(ROOT).as_posix()
    except ValueError:
        raise ValueError('closure must remain inside repository')
    out = {'scope': 'identity evidence only; native-bulk still compiles and byte-proves every body',
           'sources': {source: hashlib.sha256(closure.read_bytes()).hexdigest()},
           'identity_bindings': rows,
           'unbound_import_conflicts': sorted(duplicates)}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('bindings', len(rows), 'output', args.output)


if __name__ == '__main__':
    main()
