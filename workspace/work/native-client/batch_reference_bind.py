"""Batch reference-identity binding from a native_bulk manifest (no LLM, no source edits).

For every draft row with exactly one identity-established candidate whose only rejection is
"unproven reference identity", run native_reference_alias_bind.py on its object: each referenced symbol's address
is read from the ORIGINAL code at the same relocation. Results are merged; a symbol whose callers point at
different addresses (identical copies in the exe) is dropped, never guessed.

  python work/native-client/batch_reference_bind.py MANIFEST --out RECEIPT.json
"""
import argparse
import json
import subprocess
import sys
import tempfile
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match  # noqa: E402



def reference_owner(row):
    """Only bind one identity-established candidate with solely unresolved references."""
    if row.get('status') != 'draft':
        return None
    candidates = set(row.get('candidates') or [])
    eligible = {rejection['addr'] for rejection in row.get('rejections', [])
                if rejection.get('addr') in candidates and rejection.get('errors')
                and all(error.startswith('unproven reference identity') for error in rejection['errors'])}
    if len(eligible) != 1:
        return None
    address = next(iter(eligible))
    rejected = {rejection['addr'] for rejection in row.get('rejections', [])
                if rejection.get('errors') == ['symbol identity not established by current reference evidence']}
    # Every other byte candidate must fail the owner's identity gate, not data/reference checks.
    return address if candidates - {address} <= rejected else None


def read_known_list(path):
    paths = json.loads(Path(path).read_text(encoding='utf-8'))
    if not isinstance(paths, list) or not all(isinstance(path, str) for path in paths):
        raise ValueError('known list must contain a JSON array of paths')
    return [Path(path) for path in paths]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('manifest', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--jobs', type=int, default=8)
    ap.add_argument('--known', type=Path, action='append', default=[], help='earlier binding receipts')
    ap.add_argument('--known-list', type=Path, help='JSON array of earlier receipt paths')
    args = ap.parse_args()
    if args.known_list:
        try:
            args.known.extend(read_known_list(args.known_list))
        except ValueError as error:
            ap.error(str(error))
    data = json.loads(args.manifest.read_text())
    emitted = {}                                   # symbol -> object path
    for family in data['families']:
        for job in family.get('jobs', []):
            obj = Path(job.get('object', ''))
            if obj.is_file():
                for name, _, _ in match.coff_functions(obj.read_bytes()):
                    emitted.setdefault(name, obj)
    work = {}
    for family in data['families']:
        for row in family['symbols']:
            address = reference_owner(row)
            if address and row['symbol'] in emitted:
                work[row['symbol']] = (address, emitted[row['symbol']])
    folder = Path(tempfile.mkdtemp(prefix='refbind-', dir=HERE))
    closure = folder / 'owners.json'
    owner_evidence = folder / 'import-thunk-identities-as-owner.json'
    closure.write_text(json.dumps({'bindings': [{'symbol': s, 'addr': a} for s, (a, _) in work.items()]}))

    import contextlib, io
    import native_reference_alias_bind as binder
    shared = binder.Targets('2008-06')               # build the target index once, not once per owner
    binder.Targets = lambda client: shared
    cached_imports = binder.imports()
    binder.imports = lambda: cached_imports

    def bind(item):
        symbol, (address, obj) = item
        out = folder / ('%s-%d.json' % (address, abs(hash(symbol)) % 10**8))
        argv = sys.argv
        sys.argv = ['bind', '--object', str(obj), '--symbol', symbol, '--address', address, '--closure', str(closure),
                    '--owner-evidence', str(owner_evidence), '--output', str(out)]
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                binder.main()
        except (SystemExit, Exception):
            return None
        finally:
            sys.argv = argv
        return json.loads(out.read_text()) if out.is_file() else None

    # The binder only reads 'identity_bindings' from owner evidence: expose the thunk receipt in that shape.
    thunks = json.loads((HERE / 'import-thunk-identities.json').read_text())['rows']
    known = []                                       # earlier rounds' receipts: feed them, and never re-emit them
    for path in args.known:
        known += json.loads(path.read_text())['rows']
    owner_evidence.write_text(json.dumps({'identity_bindings': thunks + known}))
    already = {row['symbol'] for row in thunks + known}
    results = [r for r in map(bind, work.items()) if r]      # in-process: argv-driven, so sequential
    votes = defaultdict(set)
    for result in results:
        for row in result['identity_bindings']:
            votes[row['symbol']].add(row['address'])
    rows = [{'symbol': s, 'address': next(iter(a)), 'evidence': 'original relocation target at an exact owner'}
            for s, a in sorted(votes.items()) if len(a) == 1 and not s.startswith('$') and s not in already]   # $LN labels are per-object
    conflicts = {s: sorted(a) for s, a in votes.items() if len(a) > 1}
    args.out.write_text(json.dumps({'scope': 'merged exact-owner reference identities', 'sources': {},
                                    'owner_proofs': [{'owner': r['owner'], 'input_sha256': r['input_sha256']}
                                                     for r in results],
                                    'rows': rows, 'conflicts': conflicts, 'owners_tried': len(work),
                                    'owners_bound': len(results)}, indent=1) + '\n')
    print(json.dumps({'owners_tried': len(work), 'owners_bound': len(results), 'bindings': len(rows),
                      'conflicts': len(conflicts)}))


if __name__ == '__main__':
    main()
