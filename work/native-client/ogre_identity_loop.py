"""Fixpoint: Ogre native census (roc.native_bulk) <-> reference binder, until a round finds no new identity.

Each round: prove every Ogre native source with all evidence so far -> bind references of the now-exact owners
from the ORIGINAL relocations -> add the receipt as evidence. Only identities consistent across all owners are
kept (batch_reference_bind.py). Writes work/native-client/ogre-identity-loop.jsonl, one row per round.

  python work/native-client/ogre_identity_loop.py [--rounds 6]
"""
import argparse
import json
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE / 'ogre'))
from roc import match  # noqa: E402
import ogre_template_promote as tp  # noqa: E402
import run_all  # noqa: E402

INVENTORY = HERE / 'ogre-native-full-inventory-all.json'
LOG = HERE / 'ogre-identity-loop.jsonl'
SCOPE = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')


def size(addrs):
    return sum(len(match.target('2008-06', a)[0]) for a in addrs)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--rounds', type=int, default=6)
    args = ap.parse_args()
    roots = set(run_all.roots(SCOPE))
    inventory = json.loads(INVENTORY.read_text())
    evidence = inventory['families'][0]['evidence']
    known = [ROOT / e for e in evidence if 'reference-bindings' in e]
    for rnd in range(1, args.rounds + 1):
        started = time.time()
        INVENTORY.write_text(json.dumps(inventory, indent=1))
        out = HERE / ('ogre-native-full-census-loop%d' % rnd)
        subprocess.run([sys.executable, '-m', 'roc.native_bulk', '--out', str(out), str(INVENTORY)], cwd=ROOT,
                       capture_output=True, text=True, check=True)
        exact = {a for rows in tp.exact_by_source(out / 'manifest.json').values() for a in rows}
        receipt = HERE / ('ogre-reference-bindings-loop%d.json' % rnd)
        bind = subprocess.run([sys.executable, str(HERE / 'batch_reference_bind.py'), str(out / 'manifest.json'),
                               '--out', str(receipt), *sum((['--known', str(k)] for k in known), [])],
                              cwd=ROOT, capture_output=True, text=True, check=True)
        found = json.loads(bind.stdout.strip().splitlines()[-1])
        row = {'round': rnd, 'exact_addresses': len(exact), 'exact_bytes': size(exact),
               'root_addresses': len(exact & roots), 'root_bytes': size(exact & roots),
               'new_bindings': found['bindings'], 'seconds': round(time.time() - started, 1),
               'manifest': str(out.relative_to(ROOT))}
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        print(json.dumps(row), flush=True)
        if not found['bindings']:
            break
        known.append(receipt)
        evidence.append(str(receipt.relative_to(ROOT)).replace('\\', '/'))


if __name__ == '__main__':
    main()
