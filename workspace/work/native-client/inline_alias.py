"""Reference aliases for ONE per-source proof (the census rule of ref_alias.py, applied at once instead of at the next
census).  A byte-equal body rejected with `unproven reference identity: X` references X where the original image
references address O (the prover lists it): bind X -> O unless O is already bound to another symbol by any evidence.
The prover re-audits bytes, relocations and every reference with the new rows.
  rows = inline_alias.rows(manifest_path, {addr, ...})"""
import collections
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
UNPROVEN = re.compile(r'unproven reference identity: (\S+)$')
WAITS = ('unproven reference identity', 'symbol identity not established')     # identity work the census binders finish


def bound():
    seen = collections.defaultdict(set)
    for f in HERE.glob('*bindings*.json'):
        try:
            data = json.loads(f.read_text(encoding='utf-8'))
        except (OSError, ValueError):
            continue
        for b in (data.get('identity_bindings') or data.get('bindings') or []) if isinstance(data, dict) else []:
            if isinstance(b, dict) and b.get('address') and b.get('symbol'):
                seen[b['address']].add(b['symbol'])
    return seen


def rejections(manifest, addrs):
    try:
        family = json.loads(Path(manifest).read_text(encoding='utf-8'))['families'][0]
    except (OSError, ValueError, KeyError, IndexError):
        return []
    return [x for r in family.get('symbols') or [] for x in r.get('rejections') or []
            if isinstance(x, dict) and x.get('addr') in addrs]


def rows(manifest, addrs):
    seen, out, done = bound(), [], set()
    for x in rejections(manifest, addrs):
        refs = collections.defaultdict(set)
        for ref in x.get('references') or []:
            if isinstance(ref, dict) and ref.get('symbol') and ref.get('address'):
                refs[ref['symbol']].add(ref['address'])
        for error in x.get('errors') or []:
            hit = UNPROVEN.match(error)
            if not hit or '__ehhandler$' in hit.group(1) or len(refs.get(hit.group(1), ())) != 1:
                continue
            sym, addr = hit.group(1), next(iter(refs[hit.group(1)]))
            if (sym, addr) in done or not re.fullmatch(r'[0-9a-f]{8}', addr) or seen.get(addr, set()) - {sym}:
                continue
            done.add((sym, addr))
            out.append({'symbol': sym, 'address': addr, 'votes': 1, 'identity_evidence':
                        'exact-target-coff-reference-alias (per-source rejection of a byte-equal body at %s)' % x.get('addr')})
    return out


def only_waiting(manifest, addr):
    """True when ADDR has a byte-equal body whose every remaining error is identity work the census binders do."""
    errs = [e for x in rejections(manifest, {addr}) for e in x.get('errors') or []]
    return bool(errs) and all(e.startswith(WAITS) for e in errs)
