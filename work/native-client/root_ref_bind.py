"""Identity rows for a byte-equal body whose identity is known (RTTI / dynamic initializer), and for what it references.

  python work/native-client/root_ref_bind.py FILE.cpp ADDR=NEEDLE [ADDR=NEEDLE ...] --why "evidence for the roots"

After `agent_prove.py FILE.cpp ...` said REJECTED (bytes equal): for each ADDR the emitted symbol containing NEEDLE
that is byte-equal there is bound to ADDR, and every symbol the prover listed as `unproven reference identity` for it
is bound to the address the ORIGINAL image holds at the same place: code relocation of the body, or the same slot of a
data symbol it reaches (vftable slots).  No names are guessed and no body is accepted here: the prover still compares
bytes, relocations and referenced data.  A symbol already bound to another address is refused.  Then prove again."""
import argparse
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import shared_json  # noqa: E402
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402


def reachable(raw, symbol, va, size, targets):
    """{referenced code/external symbol: original address} for the body of SYMBOL placed at VA."""
    sections, symbols, definitions, _ = match._coff_data_index(raw)

    def relocs(table):
        return [struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7])]

    out, seen = {}, set()

    def visit(index, base, depth):
        name, value, number, _ = symbols[index]
        if number <= 0 or sections[number - 1][9] & 0x20:
            out.setdefault(name, set()).add(base)
            return
        if (index, base) in seen or depth > 6:
            return
        seen.add((index, base))
        table = sections[number - 1]
        end = min([v for _, v, n, _ in symbols.values() if n == number and v > value] + [table[3]])
        if not table[4]:
            return
        for offset, nested, kind in relocs(table):
            if value <= offset < end and kind == 6:
                stored = struct.unpack_from('<i', raw, table[4] + offset)[0]
                original = struct.unpack('<I', targets.data(base + offset - value, 4))[0]
                visit(nested, (original - stored) & 0xffffffff, depth + 1)

    start, section = definitions[symbol]
    table = sections[section]
    body = raw[table[4] + start:table[4] + start + size]
    target = targets.data(va, size)
    for offset, index, kind in relocs(table):
        at = offset - start
        if 0 <= at and at + 4 <= size and kind in (6, 20):
            stored = struct.unpack_from('<i', body, at)[0]
            original = struct.unpack_from('<I', target, at)[0] if kind == 6 else (
                va + at + 4 + struct.unpack_from('<i', target, at)[0]) & 0xffffffff
            visit(index, (original - stored) & 0xffffffff, 0)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('roots', nargs='+', help='ADDR=NEEDLE')
    ap.add_argument('--why', required=True)
    args = ap.parse_args()
    out = HERE / 'prove-out' / ('prove-' + Path(args.source).stem)
    rows = [r for r in json.loads((out / 'manifest.json').read_text(encoding='utf-8'))['families'][0]['symbols']]
    raw = max(out.glob('objects/*/*.obj'), key=lambda p: p.stat().st_mtime).read_bytes()
    targets = Targets('2008-06')
    new = []
    for item in args.roots:
        addr, _, needle = item.partition('=')
        addr = addr.lower()
        hits = [(r, q) for r in rows if needle in r['symbol'] and not r['symbol'].startswith('__')
                for q in r.get('rejections') or [] if q['addr'] == addr]
        if len(hits) != 1:
            print('%s: %d byte-equal symbols contain %r: %s' % (addr, len(hits), needle, [r['symbol'][:90] for r, _ in hits][:4]))
            continue
        row, rejection = hits[0]
        wanted = {e.split(': ', 1)[1] for e in rejection['errors'] if e.startswith('unproven reference identity: ')}
        if any('not established' in e for e in rejection['errors']):
            new.append((row['symbol'], addr, args.why))
            continue                                   # its references are listed only once the symbol is bound: run again
        found = reachable(raw, row['symbol'], int(addr, 16), row['size'], targets)
        for name in sorted(wanted):
            places = found.get(name, set())
            if len(places) != 1:
                print('%s: reference %s not resolved (%d places)' % (addr, name[:90], len(places)))
                continue
            new.append((name, '%08x' % places.pop(), 'reference of %s (identified at %s: %s): the original image holds '
                        'this address at the same relocation / vftable slot' % (row['symbol'][:120], addr, args.why[:120])))

    def apply(doc):
        have = {}
        for r in doc['identity_bindings']:
            have.setdefault(r['symbol'], set()).add(r['address'])
        for sym, addr, why in new:
            if addr in have.get(sym, ()):
                continue
            if sym in have:
                print('REFUSED %s -> %s: already bound to %s' % (sym[:100], addr, sorted(have[sym])))
                continue
            doc['identity_bindings'].append({'symbol': sym, 'address': addr, 'votes': 1, 'identity_evidence': why})
            have.setdefault(sym, set()).add(addr)
            print('bound', addr, sym[:110])
        return doc
    while (HERE / 'prove-out/CENSUS.lock').is_file():
        import time
        time.sleep(30)
    shared_json.update(HERE / 'class-identity-bindings.json', apply)


if __name__ == '__main__':
    main()
