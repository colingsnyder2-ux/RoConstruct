#!/usr/bin/env python3
"""Bind one callee from a closure-bound, byte-exact caller's COFF relocation."""
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
    ap.add_argument('--caller', required=True)
    ap.add_argument('--address', required=True)
    ap.add_argument('--callee', required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    address = f'{int(args.address, 16):08x}'
    closure = json.loads(args.closure.read_text())
    if address not in {r['addr'].lower() for r in closure['bindings'] if r['symbol'] == args.caller}:
        raise SystemExit('caller is not closure-bound')
    raw = args.object.read_bytes()
    candidate = next((r for r in match.coff_functions(raw) if r[0] == args.caller), None)
    if not candidate:
        raise SystemExit('caller not emitted')
    _, body, body_relocs = candidate
    targets = Targets('2008-06')
    target, target_relocs = targets.body(address)
    if len(body) != len(target) or not set(target_relocs) <= set(body_relocs) or not match.exact_match(target, target_relocs, body, body_relocs):
        raise SystemExit('caller is not byte-exact')
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[args.caller]
    table = sections[section]
    resolved = set()
    for offset, index, kind in (struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7])):
        at = offset - start
        if not 0 <= at < len(body) or symbols[index][0] != args.callee or kind not in (6, 20):
            continue
        if kind == 6:
            if at not in target_relocs:
                continue
            resolved.add(struct.unpack_from('<I', target, at)[0])
        else:
            resolved.add((int(address, 16) + at + 4 + struct.unpack_from('<i', target, at)[0]) & 0xffffffff)
    if len(resolved) != 1:
        raise SystemExit('callee relocation is absent or ambiguous')
    callee = '%08x' % resolved.pop()
    for path in (args.object, args.closure):
        if not path.resolve().is_relative_to(ROOT):
            raise SystemExit('input outside repository')
    out = {'scope': 'closure-bound byte-exact caller direct COFF relocation; callee identity only',
           'sources': {str(args.object.resolve().relative_to(ROOT)).replace('\\', '/'): hashlib.sha256(raw).hexdigest(),
                       str(args.closure.resolve().relative_to(ROOT)).replace('\\', '/'): hashlib.sha256(args.closure.read_bytes()).hexdigest()},
           'identity_bindings': [{'symbol': args.callee, 'address': callee,
                                  'identity_evidence': 'exact-caller-direct-relocation', 'votes': 1}]}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(args.callee, callee)


if __name__ == '__main__':
    main()
