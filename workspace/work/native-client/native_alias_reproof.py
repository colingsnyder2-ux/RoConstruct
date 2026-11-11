"""Two-pass deterministic native proof: target bytes, then exact relocation aliases.

Pass one compiles an unchanged native batch.  If its requested body has target
bytes but unbound references, pass two derives only same-edge COFF aliases from
the original image and re-runs the normal native-bulk gate.  No source, header,
layout, signature or target byte is generated or changed.
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def run(args):
    return subprocess.run([str(ROOT / 'roc.cmd'), *map(str, args)], cwd=ROOT, check=True)


def rows(ledger):
    for family in ledger.values():
        yield from family.get('harvest_rows', [])


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--config', required=True, type=Path)
    ap.add_argument('--closure', required=True, type=Path)
    ap.add_argument('--address', required=True)
    ap.add_argument('--symbol', required=True)
    ap.add_argument('--out', required=True, type=Path)
    ap.add_argument('--owner-evidence', type=Path, action='append', default=[],
                    help='prior alias receipts proving this symbol owner')
    args = ap.parse_args()
    address = args.address.lower().removeprefix('0x').zfill(8)
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    first = out / 'first'
    run(['native-bulk', args.config.resolve(), '--out', first])
    ledger = json.loads((first / 'ledger.json').read_text())
    owner = next((family for family in ledger.values()
                  if any(row.get('symbol') == args.symbol for row in family.get('harvest_rows', []))), None)
    if not owner or not owner.get('object'):
        raise SystemExit('requested symbol was not emitted by first pass')
    alias = out / 'alias.json'
    bind = [sys.executable, str(ROOT / 'work/native-client/native_reference_alias_bind.py'),
            '--object', owner['object'], '--symbol', args.symbol, '--address', address,
            '--closure', args.closure.resolve(), '--output', alias]
    for evidence in args.owner_evidence:
        bind.extend(['--owner-evidence', str(evidence.resolve())])
    subprocess.run(bind, cwd=ROOT, check=True)
    bindings = json.loads(alias.read_text()).get('identity_bindings', [])
    if not bindings:
        raise SystemExit('no unique original relocation aliases')
    config = json.loads(args.config.read_text())
    for family in config['families']:
        evidence = family.setdefault('evidence', [])
        alias_name = str(alias.relative_to(ROOT)).replace('\\', '/')
        if alias_name not in evidence:
            evidence.append(alias_name)
    second_config = out / 'config-with-alias.json'
    second_config.write_text(json.dumps(config, indent=1) + '\n')
    second = out / 'second'
    run(['native-bulk', second_config, '--out', second])
    final = json.loads((second / 'ledger.json').read_text())
    target = next((row for row in rows(final)
                   if row.get('symbol') == args.symbol and row.get('addr', '').lower() == address), None)
    result = {'address': address, 'symbol': args.symbol, 'aliases': len(bindings),
              'status': target.get('status') if target else 'not-proved',
              'first': str(first.relative_to(ROOT)).replace('\\', '/'),
              'alias': str(alias.relative_to(ROOT)).replace('\\', '/'),
              'second': str(second.relative_to(ROOT)).replace('\\', '/')}
    (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
    print(json.dumps(result))
    if result['status'] != 'inactive_exact':
        raise SystemExit('normal reproof did not reach inactive_exact')


if __name__ == '__main__':
    main()
