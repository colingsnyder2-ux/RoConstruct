"""Identity receipt from the full 2008-06 identity registry: every non-placeholder decorated name -> its address.

ogre-registry-identities.json only covers the Ogre names registry; this covers work/2008-06/identity-registry.json
(e.g. G3D::Sky::render, proven by byte-data-relocation proofs). A symbol named at more than one address is dropped.

  python work/native-client/registry_identity_receipt.py   -> work/native-client/registry-identities.json
"""
import collections
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SOURCE = ROOT / 'work/2008-06/identity-registry.json'
OUT = HERE / 'registry-identities.json'


def main():
    reg = json.loads(SOURCE.read_text())
    where = collections.defaultdict(set)
    for addr, row in reg.items():
        if isinstance(row, dict) and not row.get('placeholder') and str(row.get('name', '')).startswith('?'):
            where[row['name']].add(addr)
    rows = [{'symbol': s, 'address': next(iter(a)), 'evidence': 'identity-registry non-placeholder decorated name'}
            for s, a in sorted(where.items()) if len(a) == 1]
    OUT.write_text(json.dumps({'scope': __doc__.splitlines()[0], 'rows': rows,
                               'registry_sha256': hashlib.sha256(SOURCE.read_bytes()).hexdigest()}, indent=1) + '\n')
    print(json.dumps({'rows': len(rows), 'ambiguous_dropped': sum(len(a) > 1 for a in where.values())}))


if __name__ == '__main__':
    main()
