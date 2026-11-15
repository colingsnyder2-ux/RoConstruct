"""Reuse mining fingerprints for native discovery; never promote a search hit."""
import difflib
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import re

from roc import fingerprint, match
from roc.native_drafts import atomic


@lru_cache(maxsize=4096)
def features(code, relocs):
    shape = tuple(re.sub(r'\bsym\b', '#', line) for line in fingerprint.shape_of(code, relocs))
    asm = match.disasm(code, 0)
    opcodes = fingerprint.opcode_shape(asm)
    family = fingerprint.fingerprint({'size': len(code)}, asm)
    return shape, opcodes, family


def rank_bodies(target, target_relocs, bodies, limit=5, band=0.35):
    shape, opcodes, family = features(target, tuple(target_relocs))
    rows = []
    for symbol, code, relocs in bodies:
        if abs(len(code) - len(target)) > max(8, len(target) * band):
            continue
        other_shape, other_ops, other_family = features(code, tuple(relocs))
        opcode_score = 100 * difflib.SequenceMatcher(None, opcodes, other_ops, autojunk=False).ratio()
        # Avoid quadratic byte alignment for unrelated functions.
        if opcode_score < 45:
            continue
        shape_score = 100 * difflib.SequenceMatcher(None, shape, other_shape, autojunk=False).ratio()
        rows.append({'symbol': symbol, 'opcode_percent': round(opcode_score, 6), 'shape_percent': round(shape_score, 6),
                     'same_family': family == other_family, 'target_family': family, 'verified': False,
                     'metrics': match.comparison_metrics(target, target_relocs, code, relocs)})
    rows.sort(key=lambda row: (-row['shape_percent'], -row['metrics']['positional_percent'],
                               -row['metrics']['fuzzy_percent'], row['symbol']))
    best = [(r['shape_percent'], r['metrics']['positional_percent'], r['metrics']['fuzzy_percent']) for r in rows[:2]]
    ambiguous = len(best) == 2 and best[0] == best[1]
    for row in rows[:limit]:
        row['ambiguous_best'] = ambiguous and (row['shape_percent'], row['metrics']['positional_percent'], row['metrics']['fuzzy_percent']) == best[0]
    return rows[:limit]


def investigate(root, diagnostics, output_dir, limit=0):
    """Compare unresolved targets to functions in their already-built object.

    Never uses mining's score<100 pool: mined 100% functions can still lack
    native proof. Object bytes are reused; no source edits or recompilation.
    """
    root, output_dir = Path(root).resolve(), Path(output_dir)
    objects, results, errors = {}, [], []
    for row in diagnostics:
        if row.get('status') not in ('different', 'missing', 'ambiguous') or not row.get('object'):
            continue
        if limit and len(results) >= limit:
            break
        try:
            obj = Path(row['object']).resolve()
            obj.relative_to(root / 'work/2008-06')
            if str(obj) not in objects:
                raw = obj.read_bytes()
                objects[str(obj)] = (match.coff_functions(raw), hashlib.sha256(raw).hexdigest())
            bodies, digest = objects[str(obj)]
            target, relocs, _ = match.target('2008-06', row['address'])
            results.append({'address': row['address'], 'source': row['source'], 'requested_symbol': row.get('symbol'),
                            'object': str(obj), 'object_sha256': digest,
                            'candidates': rank_bodies(target, relocs, bodies), 'verified': False})
        except (OSError, ValueError, KeyError) as error:
            errors.append({'address': row['address'], 'reason': str(error)})
    report = {'scope': 'Search-only masked bytes, opcode families and normalized instruction shapes. No identity, calls, ABI, runtime or exact proof.',
              'functions': results, 'errors': errors, 'objects_reused': len(objects)}
    atomic(output_dir / 'similarity.json', report)
    return report


def cross_discover(root, issues, builds, output_dir):
    """Mining's fast masked-prefix index over explicit native gaps, not scores.

    Preserve competing source owners. A unique byte hit remains review-only.
    This function neither compiles nor calls mining save/submit helpers.
    """
    from roc.native_sweep import Matcher
    root, output_dir = Path(root).resolve(), Path(output_dir)
    addresses = set()
    for issue in issues:
        addr = issue.get('address')
        if not addr and issue.get('row') and type(issue['row'][0]) is int:
            addr = '%08x' % issue['row'][0]
        if addr:
            addresses.add(addr)
    matcher = Matcher(addresses, cache_dir=output_dir / 'fingerprint-cache')
    jobs, hits, errors = {}, {}, []
    seen = set()
    for build in builds:
        if build.get('status') != 'complete' or not build.get('object'):
            continue
        try:
            source, obj = Path(build['source']).resolve(), Path(build['object']).resolve()
            source.relative_to(root / 'rebuild/2008-06/native-classes')
            obj.relative_to(root / 'work/2008-06')
            if str(obj) in seen:
                continue
            seen.add(str(obj))
            raw = obj.read_bytes()
            if hashlib.sha256(raw).hexdigest() != build.get('object_sha256'):
                raise ValueError('object fingerprint changed')
            if hashlib.sha256(source.read_bytes()).hexdigest() != build.get('source_sha256'):
                raise ValueError('source fingerprint changed')
            for hit in matcher.scan(raw):
                row = dict(hit, review_only=True, library='fingerprint-discovery', source=str(source), object=str(obj))
                jobs.setdefault(str(source), {})[(row['addr'], row['symbol'])] = {k: v for k, v in row.items() if k != 'source'}
                hits.setdefault(row['addr'], []).append(row)
        except (OSError, ValueError, KeyError, IndexError) as error:
            errors.append({'source': build.get('source'), 'reason': str(error)})
    collisions = {addr: rows for addr, rows in hits.items() if len({(r['source'], r['symbol']) for r in rows}) > 1}
    result = {'jobs': [{'source': source, 'checks': list(checks.values())} for source, checks in sorted(jobs.items())],
              'issues': [], 'collisions': collisions, 'errors': errors, 'objects_reused': len(seen),
              'scope': 'Masked code and referenced-data discovery only. Every hit needs independent identity/call/reference proof.'}
    atomic(output_dir / 'fingerprint-discovery.json', result)
    return result
