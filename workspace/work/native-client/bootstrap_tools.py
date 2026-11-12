"""Check (and where possible prepare) everything the native recovery tools need, then run a smoke test.

  python work/native-client/bootstrap_tools.py            -> report; exit 1 if a required input is missing
  python work/native-client/bootstrap_tools.py --smoke    -> also prove one tiny native class end to end

Fixes what it can: unpacks work/native-client/data/identity-registry.json.gz, builds registry-identities.json,
creates prove-cache/ and prove-out/. Everything else (original exe, MSVC toolchain, library sources) comes from
`roc install --yes --client 2008-06`, `roc client-fetch 2008-06`, `roc lib-fetch ...` as NATIVE_AGENT.md lists.
"""
import argparse
import gzip
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'
PACKED = HERE / 'data/identity-registry.json.gz'


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--smoke', action='store_true')
    args = ap.parse_args()
    bad = []

    def need(ok, what, fix):
        print('%-4s %s' % ('ok' if ok else 'MISS', what) + ('' if ok else '  -> ' + fix))
        if not ok:
            bad.append(what)

    if not REGISTRY.exists() and PACKED.exists():
        REGISTRY.parent.mkdir(parents=True, exist_ok=True)
        with gzip.open(PACKED) as src, open(REGISTRY, 'wb') as dst:
            shutil.copyfileobj(src, dst)
    inventory = HERE / 'ogre-native-full-inventory-all.json'     # shared proof inventory: seed it from the packaged baseline
    if not inventory.exists() and (HERE / 'data' / inventory.name).exists():
        shutil.copyfile(HERE / 'data' / inventory.name, inventory)
    need(REGISTRY.exists(), 'work/2008-06/identity-registry.json', 'ask the owner for data/identity-registry.json.gz in the Worker package')
    for name in ('prove-cache', 'prove-out'):
        (HERE / name).mkdir(exist_ok=True)
    if REGISTRY.exists() and not (HERE / 'registry-identities.json').exists():
        subprocess.run([sys.executable, str(HERE / 'registry_identity_receipt.py')], check=True)
    for rel, fix in (('work/native-client/ogre-native-full-inventory-all.json', 'missing from the package: ask the owner'),
                     ('work/native-client/inferred-name-identities.json', 'git checkout it'),
                     ('work/native-client/registry-identities.json', 'run registry_identity_receipt.py'),
                     ('scripts/native_status.py', 'package incomplete'),
                     ('rebuild/2008-06/native-classes', 'package incomplete')):
        need((ROOT / rel).exists(), rel, fix)
    need(any((ROOT / 'clients').glob('2008-06*')), 'original 2008-06 client', 'roc client-fetch 2008-06')
    try:
        sys.path.insert(0, str(ROOT))
        from roc import rebuild
        rebuild.toolchain(21022)
        need(True, 'MSVC 2008 toolchain (cl 15.00.21022)', '')
    except Exception as error:  # noqa: BLE001 - report any toolchain failure
        need(False, 'MSVC 2008 toolchain (%s)' % str(error)[:80], 'roc install --yes --client 2008-06')
    for module in ('roc.native_bulk', 'roc.native_promotion', 'roc.autocommit', 'roc.integration_site', 'roc.match', 'roc.rebuild', 'roc.libs'):
        run = subprocess.run([sys.executable, '-c', 'import ' + module], capture_output=True, text=True, cwd=ROOT)
        need(run.returncode == 0, 'import ' + module, (run.stderr.strip().splitlines() or ['import fails'])[-1][:110] + ' (package incomplete: ask the owner to republish)')
    for label, argv in (('native_drafts stop --wait', ['-m', 'roc.native_drafts', 'stop', '--help']),
                        ('native_check_runner --require-proof', ['rebuild/2008-06/tests/native_check_runner.py', 'analyze', '--help'])):
        run = subprocess.run([sys.executable, *argv], capture_output=True, text=True, cwd=ROOT)
        flag = '--wait' if 'drafts' in label else '--require-proof'
        need(flag in (run.stdout + run.stderr), 'capability: ' + label, 'package too old: ask the owner to republish the Worker')
    for tool in ('prove.py', 'native_commit.py', 'upstream_lane.py', 'fingerprint.py', 'scope.py', 'audit_digest.py'):
        run = subprocess.run([sys.executable, str(HERE / tool), '--help'], capture_output=True, text=True, cwd=ROOT)
        need(run.returncode == 0, tool + ' --help', (run.stderr or run.stdout).strip().splitlines()[-1:] and (run.stderr or run.stdout).strip().splitlines()[-1][:100] or 'fails')
    if args.smoke and not bad:
        probe = ROOT / 'rebuild/2008-06/native-classes/G3DAABox.cpp'
        run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(probe), '--rounds', '1', '--infer-names', '--quiet'],
                             capture_output=True, text=True, cwd=ROOT)
        rows = [l for l in run.stdout.splitlines() if l.startswith('{')]
        need(run.returncode == 0 and bool(rows), 'smoke: prove.py G3DAABox.cpp ' + (rows[-1][:90] if rows else (run.stderr.strip().splitlines() or ['no output'])[-1][:90]), 'see output')
    print('READY' if not bad else 'NOT READY: %d problem(s)' % len(bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
