"""Rescue identity of ICF-folded exact bodies with relocation evidence.

Template promotion keeps a line only when its symbol is byte-exact at exactly
one original address.  Folded bodies (same bytes at many addresses) were
rejected even when the closure names one of those addresses.  Here, for every
symbol in the given probe objects whose exact candidates include its closure
address, each candidate is audited with roc.native_bulk.audit_references using
the closure name->address map as bindings: every relocation must land on the
bound address of the symbol it names, and referenced initialized data must
equal the original.  A symbol is rescued when the closure address is the only
candidate with no identity/data contradiction and at least one reference was
actually checked (bound or data).

Read-only.  Output: claude-identity-rescue.json (rows per convert-state symbol).
"""
import argparse
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match, native_bulk  # noqa: E402
import native_template_probe as probe  # noqa: E402

BAD = ('reference identity differs', 'referenced data differs', 'unsupported', 'original relocated fields missing',
       'absolute field is not relocated')


def checked(refs, bindings):
    return sum(1 for r in refs if r['symbol'] in bindings or not r['requires_provider'])


def receipt_path(path):
    """Keep a portable repo-relative path for probe objects in any output tree."""
    try:
        return path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return str(path.resolve())


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('objects', nargs='+', type=Path)
    ap.add_argument('--any', action='store_true', help='also symbols with no closure address: unique passing candidate')
    ap.add_argument('--direct', action='store_true', help='closure-bound symbols outside the matcher index')
    ap.add_argument('--extra-bindings', nargs='*', type=Path, default=[], help='rescue receipts: rescued symbol->address added as bindings (chain proofs)')
    ap.add_argument('--skip-file', type=Path, help='json list of addresses already proven (skipped)')
    ap.add_argument('--output', type=Path, default=HERE / 'claude-identity-rescue.json')
    args = ap.parse_args()
    args.skip = set(json.loads(args.skip_file.read_text())) if args.skip_file else set()
    closure = json.loads((HERE / 'claude-identity-closure.json').read_text())['bindings']
    bindings = {r['symbol']: r['addr'] for r in closure}
    for receipt in args.extra_bindings:
        for row in json.loads(receipt.read_text()):
            if row['rescued'] and row['symbol'] not in bindings:
                bindings[row['symbol']] = row['passing'][0]
    queue = json.loads((HERE / 'claude-conversion-queue.json').read_text())['classes']
    convert = {m['symbol']: m['addr'] for r in queue for m in r['methods'] if m['state'] == 'convert'}
    targets = native_bulk.Targets('2008-06')
    rows, seen = [], set()
    objects = [o for p in args.objects for o in (sorted(p.glob('*/candidate.obj')) if p.is_dir() else [p])]
    for obj in objects:
        raw = obj.read_bytes()
        bodies = {s: (b, r) for s, b, r in match.coff_functions(raw)}
        exact = probe.exact(raw, targets)
        if args.direct:
            # Object-local bindings: uniquely exact symbols, plus aliases defined at the same
            # section+offset as a bound symbol (MSVC's main `??_E` is an alias of `??_G`).
            local = dict(bindings)
            for s, a in exact.items():
                if len(a) == 1:
                    local.setdefault(s, a[0])
            _, _, definitions, _ = match._coff_data_index(raw)
            at = {}
            for s, place in definitions.items():
                at.setdefault(tuple(place), []).append(s)
            for group in at.values():
                known = {local[s] for s in group if s in local}
                if len(known) == 1:
                    for s in group:
                        local.setdefault(s, next(iter(known)))
            # Closure-bound symbols the matcher index cannot see (EH handlers, unwind funclets, thunks):
            # bytes compared directly at the bound address; identity from the same relocation/data audit.
            for symbol, (body, relocs) in bodies.items():
                addr = bindings.get(symbol)
                if not addr or symbol in exact or symbol in seen or addr in args.skip:
                    continue
                try:
                    target, target_relocs = targets.body(addr)
                except (KeyError, ValueError, SystemExit):
                    continue
                if len(target) != len(body) or not set(target_relocs) <= set(relocs) or \
                        not match.exact_match(target, target_relocs, body, relocs):
                    continue
                seen.add(symbol)
                refs, errors = native_bulk.audit_references(raw, symbol, body, target, target_relocs, int(addr, 16),
                                                            targets, local)
                grew = False
                for ref in refs:
                    name = ref['symbol']
                    if name in local:
                        continue
                    # referenced body defined here (or `??_G` for an aliased main `??_E`), proven at the
                    # address the original relocation resolves to -> bind it (one chain step)
                    twin = name if name in bodies else name.replace('??_E', '??_G', 1)
                    if twin not in bodies:
                        continue
                    try:
                        t2, r2 = targets.body(ref['address'])
                    except (KeyError, ValueError, SystemExit):
                        continue
                    b2, rel2 = bodies[twin]
                    if len(t2) == len(b2) and set(r2) <= set(rel2) and match.exact_match(t2, r2, b2, rel2):
                        refs2, errors2 = native_bulk.audit_references(raw, twin, b2, t2, r2, int(ref['address'], 16),
                                                                      targets, local)
                        if not [e for e in errors2 if e.startswith(BAD)] and checked(refs2, local):
                            local[name] = local.setdefault(twin, ref['address'])
                            grew = True
                if grew:
                    refs, errors = native_bulk.audit_references(raw, symbol, body, target, target_relocs,
                                                                int(addr, 16), targets, local)
                ok = not [e for e in errors if e.startswith(BAD)] and bool(checked(refs, local))
                rows.append({'symbol': symbol, 'addr': addr, 'candidates': 1, 'passing': [addr] if ok else [],
                             'rescued': ok, 'direct': True, 'object': receipt_path(obj)})
        for symbol, cands in exact.items():
            addr = convert.get(symbol) or bindings.get(symbol) or 'any'
            if symbol in seen or not addr or len(cands) < 2 or (addr != 'any' and addr not in cands):
                continue
            if args.skip and addr in args.skip:
                continue
            if addr == 'any' and (symbol.startswith('__') or not args.any):
                continue
            seen.add(symbol)
            passing = []
            for cand in cands:
                target, target_relocs = targets.body(cand)
                refs, errors = native_bulk.audit_references(raw, symbol, bodies[symbol][0], target, target_relocs,
                                                            int(cand, 16), targets, bindings)
                if not [e for e in errors if e.startswith(BAD)] and checked(refs, bindings):
                    passing.append(cand)
            rows.append({'symbol': symbol, 'addr': addr, 'candidates': len(cands), 'passing': passing[:8],
                         'rescued': passing == [addr] or (addr == 'any' and len(passing) == 1), 'object': receipt_path(obj)})
            print(json.dumps({k: rows[-1][k] for k in ('addr', 'candidates', 'rescued')}), symbol[:70], flush=True)
    args.output.write_text(json.dumps(rows, indent=1) + '\n')
    print('folded convert symbols', len(rows), 'rescued', sum(r['rescued'] for r in rows))


if __name__ == '__main__':
    main()
