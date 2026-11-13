#!/usr/bin/env python3
"""Make a narrow native-bulk identity receipt from an original vtable slot.

This is deliberately not a name recovery tool.  Caller supplies an emitted
COFF symbol plus its address-placeholder declaration.  We only accept it if
the original table, original slot target, and compiler-reported virtual slot
all agree.  native-bulk still compiles, byte-proves and audits references.
"""
import argparse
import hashlib
import json
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))


def rel(path):
    return str(path.resolve().relative_to(ROOT)).replace('\\', '/')


def hashed(path):
    return {rel(path): hashlib.sha256(path.read_bytes()).hexdigest()}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--tables', type=Path, required=True)
    ap.add_argument('--layout', type=Path, required=True)
    ap.add_argument('--class-name', required=True)
    ap.add_argument('--layout-class', required=True)
    ap.add_argument('--vtable', required=True)
    ap.add_argument('--slot', type=int, required=True)
    ap.add_argument('--method', required=True)
    ap.add_argument('--symbol', required=True)
    ap.add_argument('--address', required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    address = f'{int(args.address, 16):08x}'
    vtable = f'{int(args.vtable, 16):08x}'
    tables = json.loads(args.tables.read_text())
    rows = [r for r in tables if r.get('class') == args.class_name and r.get('vtable', '').lower() == vtable]
    if len(rows) != 1:
        raise SystemExit('need exactly one original class/vtable record')
    slots = rows[0].get('slots', [])
    if not 0 <= args.slot < len(slots):
        raise SystemExit('slot outside original table')
    target, confidence = slots[args.slot]
    if target.lower() != address:
        raise SystemExit('original slot target differs')
    if not confidence:
        raise SystemExit('original slot has no confidence')
    layout = json.loads(args.layout.read_text())
    cls = layout.get('classes', {}).get(args.layout_class)
    if not cls:
        raise SystemExit('compiler layout class missing')
    expected = '&' + args.method
    emitted = [m for m in cls.get('members', []) if m.get('offset') == args.slot and m.get('name') == expected]
    if len(emitted) != 1:
        raise SystemExit('compiler virtual slot differs')
    sources = hashed(args.tables)
    sources.update(hashed(args.layout))
    # PE IAT uniquely proves imported spelling/address.  Match the normal
    # closure receipt behavior so a body cannot be rejected merely because it
    # calls a CRT import rather than a locally bound function.
    from roc import standins
    imports, duplicate = {}, set()
    for value, imported in standins._imports('2008-06').items():
        exported = imported.split('!', 1)[1]
        spellings = ['__imp_' + exported]
        # COFF uses one extra leading underscore for undecorated C imports.
        if exported.startswith('_'):
            spellings.append('__imp__' + exported)
        for name in spellings:
            if name in imports and imports[name] != value:
                duplicate.add(name)
            else:
                imports[name] = value
    bindings = [{
        'symbol': args.symbol, 'address': address,
        'identity_evidence': 'original-vtable-slot', 'votes': 1,
        'vtable_class': args.class_name, 'vtable': vtable,
        'slot': args.slot, 'method': args.method,
    }]
    bindings.extend({'symbol': name, 'address': f'{value:08x}',
                     'identity_evidence': 'original-iAT', 'votes': 1}
                    for name, value in sorted(imports.items()) if name not in duplicate)
    out = {
        'scope': 'original vtable target plus compiler virtual-slot identity; native-bulk still byte/reference-proves body',
        'sources': sources,
        'identity_bindings': bindings,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('bound', args.symbol, address, 'slot', args.slot)


if __name__ == '__main__':
    main()
