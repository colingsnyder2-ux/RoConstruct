#!/usr/bin/env python3
"""Bounded deterministic closure -> native-probe -> closure feedback loop."""
import argparse
import json
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def run(*args):
    subprocess.run([sys.executable, *map(str, args)], cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--batch-size', type=int, default=8)
    ap.add_argument('--max-rounds', type=int, default=8)
    args = ap.parse_args()
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    current = args.closure.resolve()
    rows = []
    for index in range(args.max_rounds):
        started = time.perf_counter()
        round_dir = out / ('round-%03d' % index)
        recover = round_dir / 'recover'
        run(ROOT / 'work/native-client/native_recover.py', '--closure', current, '--out', recover,
            '--batch-size', str(args.batch_size), '--batches', '1')
        result = json.loads((recover / 'result.json').read_text())
        if not result['results']:
            rows.append({'round': index, 'closure': str(current), 'state': 'no-untried-plan',
                         'seconds': round(time.perf_counter() - started, 3)})
            break
        manifest = Path(result['results'][0]['manifest'])
        candidate, merged = round_dir / 'candidate-closure.json', round_dir / 'closure.json'
        run(ROOT / 'work/native-client/native_identity_closure.py', '--objects', manifest.parent / 'objects',
            '--output', candidate)
        run(ROOT / 'work/native-client/native_identity_merge.py', '--base', current,
            '--candidate', candidate, '--output', merged)
        merge = json.loads(merged.read_text())['merge']
        row = {'round': index, 'closure': str(current), 'manifest': str(manifest),
               'requested_exact': result['requested_exact'],
               'requested_blocked': result['requested_blocked'],
               'added_symbols': merge['added'], 'conflicts': merge['conflicts'],
               'next_closure': str(merged), 'seconds': round(time.perf_counter() - started, 3)}
        rows.append(row)
        print(json.dumps(row), flush=True)
        if not merge['added']:
            break
        current = merged
    summary = {'scope': 'compiler-symbol native probes only; no renamed-object evidence or source promotion',
               'initial_closure': str(args.closure), 'final_closure': str(current), 'rounds': rows,
               'added_symbols': sum(row.get('added_symbols', 0) for row in rows),
               'seconds': round(sum(row['seconds'] for row in rows), 3)}
    (out / 'feedback.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps({key: summary[key] for key in ('final_closure', 'added_symbols', 'seconds')}))


if __name__ == '__main__':
    main()
