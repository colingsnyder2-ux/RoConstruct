"""Probe one RTTI-backed Ogre class into a private name receipt.

Uses existing deterministic ogre_names mechanics, but never rewrites its shared
link artifacts.  Every emitted slot name is checked against its original RTTI
vtable slot count and imported slots before it is reported.
"""
import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'work/native-client/ogre'))
sys.path.insert(0, str(ROOT))
import ogre_names as names  # noqa: E402
from roc import native_asm  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('class_name')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    args.output = args.output.resolve()
    names.PROBE = args.output.parent / 'probe'
    names.PROBE.mkdir(parents=True, exist_ok=True)
    tables = names.exe_vtables()
    cpp = names.undname(sorted({row[0] for row in tables}))
    raws = [raw for raw, value in cpp.items() if value == args.class_name]
    if len(raws) != 1:
        raise SystemExit('need one RTTI class match, got %d' % len(raws))
    raw = raws[0]
    names.RAW_OF.clear()
    names.RAW_OF[args.class_name] = raw
    incs = names.includes_for(args.class_name)
    if not incs:
        raise SystemExit('no matching real header')
    form, probe = names.probe(hashlib.sha1(raw.encode()).hexdigest()[:16], args.class_name, incs)
    if form is None:
        raise SystemExit('probe failed: ' + str(probe))
    if form == 'P3':
        raise SystemExit('derived probe requires destructor/name adjustment; parked')
    vts, symbols = probe
    iat = native_asm.names(names.CLIENT)
    base, image = names.match._image(names.CLIENT)
    def imported(va):
        import struct
        body = bytes(image[va - base:va - base + 6])
        if body[:2] != b'\xff\x25':
            return None
        label = iat.get(struct.unpack_from('<I', body, 2)[0], '')
        return label.split('!', 1)[1] if '!' in label else label
    out, tables_out = {}, []
    for class_raw, vtable, offset, slots, _bases in tables:
        if class_raw != raw:
            continue
        candidates = [row for row in vts if row[1] == offset and len(row[2]) == len(slots)]
        if len(candidates) != 1:
            tables_out.append({'vtable': '%08x' % vtable, 'status': 'ambiguous-probe-vtable'})
            continue
        symbol, _, nameslots = candidates[0]
        mismatch, proposed = [], {}
        for index, (address, decorated) in enumerate(zip(slots, nameslots)):
            imp = imported(address)
            if imp and decorated not in (imp, '_' + imp):
                mismatch.append(index)
            elif decorated == '__purecall':
                mismatch.append(index)
            elif not imp:
                proposed['%08x' % address] = decorated
        if not mismatch:
            out.update(proposed)
        tables_out.append({'vtable': '%08x' % vtable, 'status': 'named' if not mismatch else 'import-mismatch',
                           'vtable_symbol': symbol, 'slots': len(slots), 'mismatches': mismatch})
    receipt = {'class': args.class_name, 'headers': [p.relative_to(ROOT).as_posix() for p in incs],
               'form': form, 'names': out, 'tables': tables_out}
    receipt['header_sha256'] = {p.relative_to(ROOT).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
                                for p in incs}
    receipt['placeholder_addresses'] = [address for address, symbol in out.items() if '?func_' in symbol]
    receipt['scope'] = 'compiler vtable identity plus RTTI offset, slot count and imported-slot agreement; body proof required separately'
    args.output.write_text(json.dumps(receipt, indent=1) + '\n')
    print(json.dumps({'tables': len(tables_out), 'named': len(out),
                      'ok_tables': sum(r['status'] == 'named' for r in tables_out)}, sort_keys=True))


if __name__ == '__main__':
    main()
