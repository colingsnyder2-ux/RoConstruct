"""Timed no-promotion sweep of deterministic native conversion plans."""
import argparse
import json
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--plan', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--skip', type=int, action='append', default=[])
    ap.add_argument('--profile', action='append', default=[],
                    help='extra compiler flags; runs one isolated profile per batch')
    args = ap.parse_args()
    plans = json.loads(args.plan.read_text())['plans']
    rows = []
    profiles = args.profile or ['']
    for batch, plan in enumerate(plans):
        if batch in args.skip:
            continue
        for profile_index, profile in enumerate(profiles):
            started = time.perf_counter()
            output = args.out / ('batch-%03d-profile-%02d' % (batch, profile_index))
            command = [sys.executable, str(ROOT / 'work/native-client/native_convert_run.py'),
                       '--plan', str(args.plan), '--closure', str(args.closure), '--batch', str(batch),
                       '--out', str(output), '--source-includes']
            if profile:
                command += ['--add-flags', profile]
            completed = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
            result_path = output / 'result.json'
            result = json.loads(result_path.read_text()) if result_path.is_file() else {}
            manifest = Path(result['manifest']) if result.get('manifest') else None
            report = json.loads(manifest.read_text()) if manifest and manifest.is_file() else {}
            blockers = [blocker for family in report.get('families', []) for blocker in family.get('blockers', [])]
            rows.append({'batch': batch, 'owner': plan['owner'], 'profile': profile,
                         'seconds': round(time.perf_counter() - started, 3),
                         'exit': completed.returncode, 'requested_exact': result.get('requested_exact', 0),
                         'requested_blocked': result.get('requested_blocked', len(plan['rows'])),
                         'blockers': blockers, 'stderr': completed.stderr[-1000:]})
            print(json.dumps(rows[-1]), flush=True)
    summary = {'batches': len(rows), 'seconds': round(sum(row['seconds'] for row in rows), 3),
               'requested_exact': sum(row['requested_exact'] for row in rows),
               'requested_blocked': sum(row['requested_blocked'] for row in rows), 'rows': rows}
    args.out.mkdir(parents=True, exist_ok=True)
    (args.out / 'sweep.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps(summary), flush=True)


if __name__ == '__main__':
    main()
