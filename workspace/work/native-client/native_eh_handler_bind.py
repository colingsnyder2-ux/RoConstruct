"""Bind an MSVC x86 __ehhandler$ symbol from a byte-exact C++ owner body.

The owner must be closure-bound and use the standard `push -1; push handler`
prologue.  The target immediate and the candidate COFF relocation at that
immediate are the only identity evidence; no layout or declaration is inferred.
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match
from roc.native_bulk import Targets


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--identity', type=Path, action='append', default=[],
                    help='additional native-bulk identity-evidence receipts')
    ap.add_argument('--owner', required=True)
    ap.add_argument('--address', required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    address = '%08x' % int(args.address, 16)
    closure = json.loads(args.closure.read_text())['bindings']
    bindings = {row['symbol']: row['addr'].lower() for row in closure}
    for path in args.identity:
        for row in json.loads(path.read_text()).get('identity_bindings', []):
            bindings.setdefault(row['symbol'], row['address'].lower())
    if bindings.get(args.owner) != address:
        raise SystemExit('owner is not closure-bound')
    raw = args.object.read_bytes()
    candidate = next((row for row in match.coff_functions(raw) if row[0] == args.owner), None)
    if not candidate:
        raise SystemExit('owner symbol not emitted')
    _, body, relocs = candidate
    targets = Targets('2008-06')
    target, target_relocs = targets.body(address)
    if len(body) != len(target) or not set(target_relocs) <= set(relocs) or not match.exact_match(target, target_relocs, body, relocs):
        raise SystemExit('owner body is not byte-exact')
    prologue = target.find(b'\x6a\xff\x68', 0, 24)
    if prologue < 0:
        raise SystemExit('target lacks standard EH prologue')
    handler_at = prologue + 3
    handler = struct.unpack_from('<I', target, handler_at)[0]
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[args.owner]
    table = sections[section]
    matches = []
    for offset, index, kind in (struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7])):
        if offset == start + handler_at and kind == 6:
            matches.append(symbols[index][0])
    if len(matches) != 1 or not matches[0].startswith('__ehhandler$'):
        raise SystemExit('candidate EH relocation is absent or ambiguous')
    try:
        targets.body('%08x' % handler)
    except (KeyError, ValueError):
        raise SystemExit('target handler is not an original function')
    for path in (args.object, args.closure, *args.identity):
        if not path.resolve().is_relative_to(ROOT):
            raise SystemExit('input outside repository')
    out = {'scope': 'closure-bound byte-exact owner standard EH prologue; handler identity only',
           'sources': {str(args.object.resolve().relative_to(ROOT)).replace('\\', '/'): hashlib.sha256(raw).hexdigest(),
                       str(args.closure.resolve().relative_to(ROOT)).replace('\\', '/'): hashlib.sha256(args.closure.read_bytes()).hexdigest()},
           'identity_bindings': [{'symbol': matches[0], 'address': '%08x' % handler,
                                  'identity_evidence': 'exact-owner-eh-prologue', 'votes': 1}]}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(matches[0], '%08x' % handler)


if __name__ == '__main__':
    main()
