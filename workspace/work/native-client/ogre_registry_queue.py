"""Refresh a source-discovery queue from the selected Ogre identity registry.

This adapter carries identity evidence only. Existing source detection is not
byte proof; header candidates are not layout proof. Vendor replay stays labelled.
"""
import json
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / 'work/native-client'


def main():
    registry = json.loads((HERE / 'ogre-names-registry.json').read_text())
    bindings = []
    blocked = []
    addresses = defaultdict(set)
    for address, row in registry.items():
        if not row.get('placeholder'):
            addresses[row['name']].add(address)
    for address, row in registry.items():
        if row.get('placeholder'):
            continue
        if len(addresses[row['name']]) != 1:
            blocked.append({'addr': address, 'name': row['name'], 'reason': 'conflicting-symbol-addresses',
                            'addresses': sorted(addresses[row['name']])})
            continue
        # Synthetic analog-owner spellings must not acquire native authority.
        if any(token in row['name'] for token in ('Recovery', 'roc_fn_', 'roc_abs_', '?func_')):
            blocked.append({'addr': address, 'name': row['name'], 'reason': 'synthetic-analog-identity'})
            continue
        bindings.append({'addr': address, 'symbol': row['name'], 'function_start': True,
                         'body_exact': False, 'evidence': row['name_source'], 'votes': 0})
    closure = HERE / 'ogre-registry-queue-identities.json'
    closure.write_text(json.dumps({'scope': 'registry identity adapter only', 'bindings': bindings,
                                   'blocked': blocked}, indent=1) + '\n')
    subprocess.run([sys.executable, str(HERE / 'native_conversion_queue.py'), '--closure', str(closure),
                    '--output', str(HERE / 'ogre-registry-conversion-queue.json')], cwd=ROOT, check=True)
    print('synthetic identities blocked', len(blocked))


if __name__ == '__main__':
    main()
