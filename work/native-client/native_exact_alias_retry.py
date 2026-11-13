"""Retry native-bulk proof after deriving exact COFF-reference aliases.

This is proof plumbing only: it never writes a native class or header.  A target
must already have one unique byte-exact candidate in the first native-bulk run.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def rows(value):
    if isinstance(value, dict):
        if value.get('symbol') and 'candidates' in value:
            yield value
        for child in value.values():
            yield from rows(child)
    elif isinstance(value, list):
        for child in value:
            yield from rows(child)


def run(args):
    print('+', ' '.join(map(str, args)))
    subprocess.run(list(map(str, args)), cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--config', type=Path, required=True)
    ap.add_argument('--first-out', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--jobs', type=int, default=4)
    ns = ap.parse_args()

    first = (ROOT / ns.first_out).resolve()
    out = (ROOT / ns.out).resolve()
    ledger = json.loads((first / 'ledger.json').read_text(encoding='utf-8'))
    manifest = json.loads((first / 'checks.json').read_text(encoding='utf-8'))
    objects = {j['source']: Path(j['object']) for j in manifest.get('jobs', [])}
    expected = {j['source']: {check['symbol'] for check in j.get('checks', [])}
                for j in manifest.get('jobs', [])}
    targets = []
    seen = set()
    for row in rows(ledger):
        if row.get('status') not in {'draft', 'stale', 'inactive_exact'}:
            continue
        candidates = row.get('candidates', [])
        if len(candidates) != 1:
            continue
        addr = row.get('addr', candidates[0])
        if addr != candidates[0]:
            continue
        key = (addr, row['symbol'])
        if key not in seen:
            seen.add(key)
            targets.append((addr, row['symbol']))
    if not targets:
        raise SystemExit('no unique byte-exact candidates in first ledger')

    bindings = []
    work = [(addr, symbol, objects[source]) for source, symbols in expected.items()
            for addr, symbol in targets if symbol in symbols and source in objects]
    def bind(item):
        addr, symbol, obj = item
        probe = out / 'aliases' / (addr + '-' + hashlib.sha1(symbol.encode()).hexdigest()[:12] + '.json')
        probe.parent.mkdir(parents=True, exist_ok=True)
        try:
            run([sys.executable, ROOT / 'work/native-client/native_reference_alias_bind.py',
                 '--object', obj, '--symbol', symbol, '--address', addr,
                 '--closure', ROOT / ns.closure, '--output', probe])
            return probe
        except subprocess.CalledProcessError:
            return None
    with ThreadPoolExecutor(max_workers=max(1, ns.jobs)) as pool:
        bindings = [probe for probe in pool.map(bind, work) if probe]

    evidence = out / 'identity-aliases.json'
    cmd = [sys.executable, ROOT / 'work/native-client/native_identity_evidence.py',
           '--closure', ROOT / ns.closure]
    for addr, _ in targets:
        cmd += ['--addr', addr]
    for binding in bindings:
        cmd += ['--extra-bindings', binding]
    run(cmd + ['--output', evidence])

    config = json.loads((ROOT / ns.config).read_text(encoding='utf-8'))
    for family in config.get('families', []):
        family['evidence'] = [str(evidence.relative_to(ROOT)).replace('\\', '/')]
    retry = out / 'retry-config.json'
    out.mkdir(parents=True, exist_ok=True)
    retry.write_text(json.dumps(config, indent=2) + '\n', encoding='utf-8')
    run([ROOT / 'roc.cmd', 'native-bulk', retry, '--out', out / 'proof'])


if __name__ == '__main__':
    main()
