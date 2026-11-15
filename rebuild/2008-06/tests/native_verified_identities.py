"""Load explicitly reviewed identities backed by unchanged local exact receipts.

An exact byte receipt alone does not identify a function. Each registry entry
also requires a reviewer-supplied identity explanation and pins the original
image, receipt and source contents. Invalid or stale entries are ignored.
"""
import hashlib
import json
from pathlib import Path


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def load(path, root, original):
    root = Path(root).resolve()
    result, rejected = {}, []
    try:
        registry = json.loads(Path(path).read_text(encoding='utf-8'))
        if not isinstance(registry, dict) or not isinstance(registry.get('identities'), list):
            raise ValueError('invalid registry')
        image_hash = digest(Path(original))
    except (OSError, ValueError, TypeError) as exc:
        return {}, [{'reason': str(exc)}]
    for entry in registry.get('identities', []):
        try:
            symbol, address = entry['symbol'], entry['address'].lower()
            if not symbol or len(address) != 8 or int(address, 16) < 0:
                raise ValueError('invalid identity')
            if not entry.get('evidence') or entry['original_sha256'] != image_hash:
                raise ValueError('missing identity evidence or changed original')
            receipt_path = (root / entry['receipt']).resolve()
            receipt_path.relative_to(root)
            if digest(receipt_path) != entry['receipt_sha256']:
                raise ValueError('changed receipt')
            receipt = json.loads(receipt_path.read_text(encoding='utf-8'))
            source = Path(receipt['source_path'])
            if digest(source) != receipt['source_sha256']:
                raise ValueError('changed source')
            rows = [row for row in receipt['checks'] if row.get('address', '').lower() == address
                    and row.get('symbol') == symbol and row.get('exact') is True]
            if len(rows) != 1:
                raise ValueError('receipt does not prove requested identity')
            row = rows[0]
            metrics = row['metrics']
            if metrics['unmasked_differences'] != 0 or metrics['length_delta'] != 0:
                raise ValueError('receipt does not prove exact bytes')
            for field in ('verified_calls', 'verified_references'):
                if not isinstance(row[field], list) or any(
                        not r.get('status', '').startswith('verified_') for r in row[field]):
                    raise ValueError('unverified reference')
            result.setdefault(symbol, []).append(address)
        except (OSError, ValueError, KeyError, TypeError) as exc:
            rejected.append({'entry': entry, 'reason': str(exc)})
    return {k: sorted(set(v)) for k, v in result.items()}, rejected
