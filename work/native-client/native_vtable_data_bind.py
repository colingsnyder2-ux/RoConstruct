#!/usr/bin/env python3
"""Bind emitted vtable relocation symbols to original vtable slots.

No names are guessed: each binding is produced only from matching an emitted
COFF vtable symbol to a supplied original vtable address and its slot count.
Useful when a byte-exact constructor references its own full vtable data.
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, standins
from roc.native_bulk import Targets


def project(path):
    return str(path.resolve().relative_to(ROOT)).replace('\\', '/')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--tables', type=Path, required=True)
    ap.add_argument('--vtable', action='append', default=[],
                    help='COFF vtable symbol=original address')
    ap.add_argument('--vtable-list', type=Path, help='JSON array of symbol/address vtable candidates')
    ap.add_argument('--closure', action='append', type=Path, default=[],
                    help='optional closure used only for explicit symbols')
    ap.add_argument('--closure-symbol', action='append', default=[],
                    help='exact closure symbol to carry as identity evidence')
    ap.add_argument('--recursive-data', action='store_true',
                    help='verify and bind RTTI/data edges reachable from supplied vtables')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    if args.vtable_list:
        args.vtable.extend(row['symbol'] + '=' + row['address']
                           for row in json.loads(args.vtable_list.read_text()))
    if not args.vtable:
        ap.error('provide --vtable or --vtable-list')
    raw = args.object.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    table_rows = {row['vtable'].lower(): row for row in json.loads(args.tables.read_text())}
    bindings = {}
    data_roots = []
    proved_data = []
    targets = Targets('2008-06')
    for item in args.vtable:
        if '=' not in item:
            raise SystemExit('--vtable needs SYMBOL=ADDRESS')
        name, value = item.split('=', 1)
        va = f'{int(value, 16):08x}'
        row = table_rows.get(va)
        if not row or name not in definitions:
            raise SystemExit('missing original/coff vtable: ' + item)
        start, section = definitions[name]
        table = sections[section]
        relocs = {offset: (index, kind) for offset, index, kind in
                  (struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7]))}
        for slot, pair in enumerate(row['slots']):
            offset = start + slot * 4
            if offset not in relocs:
                raise SystemExit('missing COFF relocation %s slot %d' % (name, slot))
            index, kind = relocs[offset]
            if kind != 6:
                raise SystemExit('non-absolute vtable relocation %s slot %d' % (name, slot))
            symbol = symbols[index][0]
            if not table[4] or offset + 4 > table[3]:
                raise SystemExit('vtable slot outside initialized COFF data: ' + name)
            addend = struct.unpack_from('<i', raw, table[4] + offset)[0]
            address = f'{(int(pair[0], 16) - addend) & 0xffffffff:08x}'
            if symbol in bindings and bindings[symbol] != address:
                raise SystemExit('conflicting vtable slot symbol: ' + symbol)
            bindings[symbol] = address
        data_roots.append((name, int(va, 16)))
        # MSVC puts the complete-object locator immediately before each
        # vtable address point.  Its COFF relocation supplies the RTTI symbol;
        # its original word supplies the target address.
        locator = relocs.get(start - 4)
        if locator and locator[1] == 6:
            symbol = symbols[locator[0]][0]
            if not table[4] or start < 4:
                raise SystemExit('vtable locator outside initialized COFF data: ' + name)
            addend = struct.unpack_from('<i', raw, table[4] + start - 4)[0]
            target = (struct.unpack('<I', targets.data(int(va, 16) - 4, 4))[0] - addend) & 0xffffffff
            bindings[symbol] = f'{target:08x}'
            data_roots.append((symbol, target))
    if args.recursive_data:
        queued, seen = list(data_roots), set()
        while queued:
            name, va = queued.pop()
            if (name, va) in seen or name not in definitions:
                continue
            seen.add((name, va))
            start, section = definitions[name]
            table = sections[section]
            if table[9] & 0x20:
                continue
            values = [value for _, value, number, _ in symbols.values()
                      if number == section + 1 and value > start]
            end = min(values + [table[3]])
            native = raw[table[4] + start:table[4] + end] if table[4] else bytes(end - start)
            try:
                expected = targets.data(va, len(native))
            except ValueError:
                raise SystemExit('reachable data outside original image: ' + name)
            offsets = []
            for offset, index, kind in (struct.unpack_from('<IIH', raw, table[5] + i * 10)
                                        for i in range(table[7])):
                if not start <= offset < end:
                    continue
                if kind != 6:
                    raise SystemExit('unsupported reachable data relocation: ' + name)
                at = offset - start
                offsets.append(at)
                symbol = symbols[index][0]
                stored = struct.unpack_from('<i', native, at)[0]
                original = struct.unpack_from('<I', expected, at)[0]
                target = (original - stored) & 0xffffffff
                previous = bindings.get(symbol)
                if previous and previous != f'{target:08x}':
                    raise SystemExit('conflicting reachable data symbol: ' + symbol)
                bindings[symbol] = f'{target:08x}'
                queued.append((symbol, target))
            original_offsets = targets.data_relocations(va, len(native))
            if original_offsets != set(offsets) or not match.exact_match(expected, original_offsets, native, offsets):
                raise SystemExit('reachable data differs: ' + name)
            proved_data.append({'symbol': name, 'address': f'{va:08x}', 'bytes': len(native),
                                'relocations': len(offsets)})
    closure_rows = {}
    if args.closure_symbol:
        if not args.closure:
            raise SystemExit('--closure-symbol requires --closure')
        for closure in args.closure:
            for row in json.loads(closure.read_text()).get('bindings', []):
                closure_rows.setdefault(row['symbol'], []).append(row)
        for symbol in args.closure_symbol:
            rows = closure_rows.get(symbol, [])
            addresses = {row['addr'].lower() for row in rows if row.get('function_start')}
            if len(addresses) != 1:
                raise SystemExit('closure does not uniquely bind: ' + symbol)
            bindings[symbol] = addresses.pop()
    # Original PE imports prove both normal and C-decorated COFF spellings.
    for va, imported in standins._imports('2008-06').items():
        exported = imported.split('!', 1)[1]
        for name in ('__imp_' + exported,
                     '__imp__' + exported if exported.startswith('_') else ''):
            if name:
                bindings.setdefault(name, f'{va:08x}')
    sources = {project(args.object): hashlib.sha256(raw).hexdigest(),
               project(args.tables): hashlib.sha256(args.tables.read_bytes()).hexdigest()}
    for closure in args.closure:
        sources[project(closure)] = hashlib.sha256(closure.read_bytes()).hexdigest()
    out = {'scope': 'COFF vtable relocation slots bound to original vtable slots; native-bulk still byte/reference-proves bodies',
           'sources': sources,
           'proved_data': sorted(proved_data, key=lambda row: (row['address'], row['symbol'])),
           'identity_bindings': [{'symbol': name, 'address': address,
                                  'identity_evidence': 'original-vtable-data-slot', 'votes': 1}
                                 for name, address in sorted(bindings.items())]}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('bindings', len(bindings))


if __name__ == '__main__':
    main()
