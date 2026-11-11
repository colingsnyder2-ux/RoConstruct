"""Emit direct-call identity bindings from a named, byte-exact native object."""
import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match
from roc.native_bulk import Targets, audit_references


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--symbol', required=True)
    ap.add_argument('--address', required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    closure = json.loads(args.closure.read_text())
    names = {row['symbol']: row['addr'].lower() for row in closure['bindings']}
    if names.get(args.symbol) != args.address.lower():
        raise SystemExit('caller is not closure-bound to requested address')
    raw, targets = args.object.read_bytes(), Targets('2008-06')
    candidate = next((row for row in match.coff_functions(raw) if row[0] == args.symbol), None)
    if not candidate:
        raise SystemExit('caller symbol not emitted')
    _, body, relocs = candidate
    target, target_relocs = targets.body(args.address.lower())
    if len(body) != len(target) or not set(target_relocs) <= set(relocs) or not match.exact_match(target, target_relocs, body, relocs):
        raise SystemExit('caller body is not exact')
    refs, errors = audit_references(raw, args.symbol, body, target, target_relocs,
                                    int(args.address, 16), targets, names)
    bindings = {row['symbol']: row['address'] for row in refs if row['symbol'] not in names}
    unexpected = [error for error in errors if not error.startswith('unproven reference identity: ')]
    if unexpected or not bindings:
        raise SystemExit('cannot isolate direct identities: ' + '; '.join(unexpected or errors))
    out = {'scope': 'direct COFF relocation target from closure-bound, byte-exact caller; identity evidence only',
           'symbol': args.symbol, 'address': args.address.lower(), 'bindings': bindings,
           'object': str(args.object.resolve().relative_to(ROOT)).replace('\\', '/')}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out))


if __name__ == '__main__':
    main()
