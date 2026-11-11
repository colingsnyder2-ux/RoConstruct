"""Seed-free symbol identity closure over already compiled native objects.

Read-only diagnostic.  No source, header or client is changed and nothing is
compiled.  For every function in every cached VS2008 object:

1. find original bodies with identical relocation-masked bytes;
2. seed  symbol -> address  where a non-trivial body has exactly one such body;
3. every relocation of a seeded body names its callee/data symbol and the
   original address at that field: a vote  symbol -> address;
4. votes pick between byte-identical candidates and name functions that no
   object defines; repeat to a fixed point.

A symbol whose evidence names two addresses is reported as a conflict and bound
to nothing.  A binding is identity evidence for a mangled name (owner and
signature as the compiled header declared them).  It is not layout, ABI, link
or runtime proof, and the header that produced the name may itself be an analog.
"""
import argparse
import hashlib
import json
import struct
import sys
import time
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402

MIN_SEED = 16  # ponytail: fixed size floor for seeds; lower only with a caller-vote requirement


def functions(raw):
    """(symbol, body, reloc offsets, [(offset, referenced symbol, kind, stored addend)])"""
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for symbol, body, relocs in match.coff_functions(raw):
        if symbol not in definitions:
            continue
        start, section = definitions[symbol]
        table, refs = sections[section], []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
            at = offset - start
            if 0 <= at and at + 4 <= len(body) and kind in (6, 20) and index in symbols:
                refs.append((at, symbols[index][0], kind, struct.unpack_from('<i', body, at)[0]))
        yield symbol, bytes(body), tuple(sorted(relocs)), refs


def vtables(raw):
    """(vftable symbol, ((offset from symbol, referenced symbol), ...)) for each emitted ??_7 table."""
    sections, symbols, _, _ = match._coff_data_index(raw)
    for name, value, number, _ in symbols.values():
        if name.startswith('??_7') and number > 0:
            table = sections[number - 1]
            slots = []
            for i in range(table[7]):
                offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
                if kind == 6 and index in symbols:
                    slots.append((offset - value, symbols[index][0]))
            yield name, tuple(sorted(slots))


def bindable(name):
    return name[:1] in '?_@' and not name.startswith('??_C@')  # pooled strings may be duplicated


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--objects', action='append', type=Path, required=True,
                    help='directory searched recursively for *.obj')
    ap.add_argument('--gate', type=Path, help='native-transplant-gate.json to join against')
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--min-seed', type=int, default=MIN_SEED,
                    help='minimum unique exact body size to seed (default: %(default)s)')
    args = ap.parse_args()
    clock = time.monotonic()
    targets = Targets('2008-06')
    timing = {'index_seconds': round(time.monotonic() - clock, 2)}

    clock = time.monotonic()
    seen_objects, seen_bodies = set(), set()
    analogs = defaultdict(set)   # symbol -> addresses with identical bytes
    variants = {}                # (symbol, addr) -> refs of the matching body
    sizes, objects, emitted = {}, 0, 0
    tables = defaultdict(set)    # vftable symbol -> slot layouts emitted by objects
    paths = sorted(p for d in args.objects for p in d.rglob('*.obj'))
    for path in paths[:args.limit or None]:
        raw = path.read_bytes()
        key = hashlib.sha1(raw).digest()
        if key in seen_objects:
            continue
        seen_objects.add(key)
        objects += 1
        try:
            rows = list(functions(raw))
            for name, slots in vtables(raw):
                tables[name].add(slots)
        except (struct.error, ValueError, IndexError, KeyError):
            continue
        for symbol, body, relocs, refs in rows:
            emitted += 1
            key = (symbol, hashlib.sha1(body).digest(), relocs)
            if key in seen_bodies or len(body) < 6:
                continue
            seen_bodies.add(key)
            for addr in targets.candidates(body, relocs):
                try:
                    target, original = targets.body(addr)
                except (KeyError, ValueError, SystemExit):
                    continue
                if len(target) == len(body) and set(original) <= set(relocs) and \
                        match.exact_match(target, original, body, relocs):
                    analogs[symbol].add(addr)
                    variants[(symbol, addr)] = (target, refs)
                    sizes[symbol] = len(body)
    timing['scan_seconds'] = round(time.monotonic() - clock, 2)

    clock = time.monotonic()
    bound, why, votes, conflicts = {}, {}, defaultdict(Counter), {}
    pending = []

    def accept(symbol, addr, reason):
        if symbol in bound or symbol in conflicts:
            return
        bound[symbol], why[symbol] = addr, reason
        pending.append((symbol, addr))

    for symbol, addrs in analogs.items():
        if len(addrs) == 1 and sizes[symbol] >= args.min_seed and bindable(symbol):
            accept(symbol, next(iter(addrs)), 'unique-body')
    rounds = 0
    while pending:
        rounds += 1
        batch, pending[:] = pending[:], []
        touched = set()
        for symbol, addr in batch:
            # A bound vftable names every slot target (and its RTTI locator at -4).
            for slots in tables.get(symbol, ()):
                for offset, name in slots:
                    at = int(addr, 16) + offset
                    if bindable(name) and at in targets.relocs:
                        votes[name]['%08x' % struct.unpack('<I', targets.data(at, 4))[0]] += 1
                        touched.add(name)
            if (symbol, addr) not in variants:
                continue
            target, refs = variants[(symbol, addr)]
            va = int(addr, 16)
            for at, name, kind, stored in refs:
                if not bindable(name):
                    continue
                field = struct.unpack_from('<I' if kind == 6 else '<i', target, at)[0]
                original = field if kind == 6 else va + at + 4 + field
                votes[name]['%08x' % ((original - stored) & 0xffffffff)] += 1
                touched.add(name)
        for name in touched:
            if len(votes[name]) > 1 or (name in bound and bound[name] not in votes[name]):
                conflicts[name] = {'votes': dict(votes[name]), 'bound': bound.pop(name, None)}
                continue
            addr = next(iter(votes[name]))
            if name in analogs and addr not in analogs[name]:
                continue  # compiled body exists but differs there: name known, body not exact
            accept(name, addr, 'reference-vote' if name not in analogs else 'vote-selected-body')
    timing['closure_seconds'] = round(time.monotonic() - clock, 2)

    starts = set(match._functions('2008-06'))
    # 'address' makes this file readable as a native-bulk evidence receipt.
    rows = [{'symbol': s, 'addr': a, 'address': a, 'evidence': why[s], 'votes': votes[s].get(a, 0),
             'body_exact': a in analogs.get(s, ()), 'function_start': a in starts}
            for s, a in sorted(bound.items(), key=lambda item: item[1])]
    named = defaultdict(list)
    for row in rows:
        named[row['addr']].append(row['symbol'])
    out = {'scope': __doc__.splitlines()[0] + ' Identity evidence only.',
           'timing': timing,
           'summary': {'objects': objects, 'functions_emitted': emitted, 'distinct_bodies': len(seen_bodies),
                       'symbols_with_byte_analog': len(analogs), 'bound_symbols': len(rows),
                       'bound_addresses': len(named), 'rounds': rounds,
                       'by_evidence': dict(Counter(r['evidence'] for r in rows)),
                       'body_exact': sum(r['body_exact'] for r in rows),
                       'named_without_exact_body': sum(not r['body_exact'] and r['function_start'] for r in rows),
                       'conflicts': len(conflicts),
                       'ambiguous_unresolved': sum(len(a) > 1 and s not in bound for s, a in analogs.items())},
           'bindings': rows, 'conflicts': conflicts}
    if args.gate:
        gate = json.loads(args.gate.read_text())
        joined = [dict(row, proven_symbols=named[row['addr']]) for row in gate['rows'] if row['addr'] in named]
        out['gate_join'] = {'summary': dict(Counter(r['status'] for r in joined)), 'rows': joined}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps({**out['summary'], **timing, 'gate_join': out.get('gate_join', {}).get('summary')}, indent=1))


if __name__ == '__main__':
    main()
