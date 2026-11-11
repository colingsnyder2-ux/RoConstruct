#!/usr/bin/env python3
"""Fold one completed native-bulk reproof into identity and recovery reports."""
import argparse
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def run(*args):
    subprocess.run([sys.executable, *map(str, args)], cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--base', type=Path, required=True)
    ap.add_argument('--bulk', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--donor', type=Path, default=Path('work/native-client/codex-donor-queue-v3.json'))
    args = ap.parse_args()
    bulk = args.bulk.resolve()
    manifest = bulk / 'manifest.json'
    objects = bulk / 'objects'
    if not manifest.is_file() or not objects.is_dir():
        raise SystemExit('completed native-bulk manifest/objects required')
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    candidate, merged, recovery, report = (out / 'candidate-closure.json', out / 'closure.json',
                                            out / 'recovery', out / 'report.json')
    run(ROOT / 'work/native-client/native_identity_closure.py', '--objects', objects,
        '--output', candidate)
    run(ROOT / 'work/native-client/native_identity_merge.py', '--base', args.base,
        '--candidate', candidate, '--output', merged)
    run(ROOT / 'work/native-client/native_recover.py', '--closure', merged, '--out', recovery,
        '--batches', '0')
    report_args = [ROOT / 'work/native-client/native_convert_report.py', '--closure', merged,
                   '--gate', recovery / 'gate.json', '--sweep', recovery / 'result.json',
                   '--native-bulk', manifest, '--output', report]
    if args.donor.is_file():
        report_args += ['--donor', args.donor]
    run(*report_args)
    print(report)


if __name__ == '__main__':
    main()
