"""Bind unique COFF aliases reached from an exact target body's relocations.

This closes MSVC import-library indirection: a code relocation can name an
``__imp_`` symbol while its COFF data thunk names a different decorated alias.
Every emitted binding is calculated from the original target relocation/data
word at the same recursive edge.  Ambiguous aliases, code/data differences and
unknown relocation kinds are rejected.
"""
import argparse
import hashlib
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, standins
from roc.native_bulk import Targets


def imports():
    out, duplicate = {}, set()
    for address, imported in standins._imports('2008-06').items():
        symbol = '__imp_' + imported.split('!', 1)[1]
        if symbol in out and out[symbol] != address:
            duplicate.add(symbol)
        else:
            out[symbol] = '%08x' % address
    return {key: value for key, value in out.items() if key not in duplicate}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--symbol', required=True)
    ap.add_argument('--address', required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--owner-evidence', type=Path, action='append', default=[],
                    help='prior exact-target alias receipts; used only to bind this owner')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    address = '%08x' % int(args.address, 16)
    closure = json.loads(args.closure.read_text())['bindings']
    bindings = {row['symbol']: row['addr'].lower() for row in closure}
    for path in args.owner_evidence:
        evidence = json.loads(path.read_text())
        for row in evidence.get('identity_bindings', []):
            bindings.setdefault(row['symbol'], row['address'].lower())
    bindings.update({key: value for key, value in imports().items() if key not in bindings})
    raw = args.object.read_bytes()
    candidate = next((row for row in match.coff_functions(raw) if row[0] == args.symbol), None)
    if not candidate or bindings.get(args.symbol) != address:
        raise SystemExit('requires closure-bound emitted owner')
    _, body, relocs = candidate
    targets = Targets('2008-06')
    target, target_relocs = targets.body(address)
    if len(body) != len(target) or not set(target_relocs) <= set(relocs) or not match.exact_match(target, target_relocs, body, relocs):
        raise SystemExit('owner is not byte-exact')
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[args.symbol]
    found, seen = defaultdict(set), set()

    def relocs_for(table):
        return [struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7])]

    def walk(index, stored, original, depth=0):
        name, value, number, _ = symbols[index]
        base = (original - stored) & 0xffffffff
        known = bindings.get(name)
        if known is not None and int(known, 16) != base:
            raise ValueError('known identity differs: ' + name)
        if number <= 0 or sections[number - 1][9] & 0x20:
            if known is None:
                # Only original image addresses are admitted. This excludes a
                # COFF-local/addend artifact from becoming an invented target.
                targets.data(base, 1)
                found[name].add('%08x' % base)
            return
        table = sections[number - 1]
        rawsize, rawptr = table[3], table[4]
        following = [other for _, other, sec, _ in symbols.values() if sec == number and other > value]
        end = min(following + [rawsize])
        begin = value + stored
        key = (index, original, begin)
        if depth > 6 or not value <= begin < end or key in seen:
            return
        seen.add(key)
        native = raw[rawptr + begin:rawptr + end] if rawptr else bytes(end - begin)
        expected = targets.data(original, len(native))
        nested_relocs = [(offset, nested, kind) for offset, nested, kind in relocs_for(table)
                         if begin <= offset < end]
        offsets = [offset - begin for offset, _, _ in nested_relocs]
        original_offsets = targets.data_relocations(original, len(native))
        if original_offsets != set(offsets) or not match.exact_match(expected, original_offsets, native, offsets):
            raise ValueError('reachable data differs: ' + name)
        for offset, nested, kind in nested_relocs:
            if begin <= offset < end:
                at = offset - begin
                if kind != 6 or at + 4 > len(native) or original + at not in targets.relocs:
                    raise ValueError('unsupported nested relocation: ' + name)
                walk(nested, struct.unpack_from('<i', native, at)[0],
                     struct.unpack_from('<I', expected, at)[0], depth + 1)

    for offset, index, kind in relocs_for(sections[section]):
        at = offset - start
        if not 0 <= at < len(body) or at + 4 > len(body):
            continue
        if kind == 6:
            if at not in target_relocs:
                raise ValueError('candidate absolute edge absent from target')
            original = struct.unpack_from('<I', target, at)[0]
        elif kind == 20:
            original = (int(address, 16) + at + 4 + struct.unpack_from('<i', target, at)[0]) & 0xffffffff
        else:
            raise ValueError('unsupported code relocation')
        walk(index, struct.unpack_from('<i', body, at)[0], original)
    ambiguous = {name: sorted(values) for name, values in found.items() if len(values) != 1}
    rows = [{'symbol': name, 'address': next(iter(values)),
             'identity_evidence': 'exact-target-coff-reference-alias', 'votes': 1}
            for name, values in sorted(found.items()) if len(values) == 1]
    out = {'scope': 'exact target COFF relocation/data alias identities only; no body/layout claim',
           'owner': {'symbol': args.symbol, 'address': address},
           'input_sha256': {str(path): hashlib.sha256(path.read_bytes()).hexdigest()
                            for path in [args.object, args.closure, *args.owner_evidence]},
           'identity_bindings': rows, 'ambiguous': ambiguous}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps({'bindings': len(rows), 'ambiguous': len(ambiguous)}))


if __name__ == '__main__':
    main()
