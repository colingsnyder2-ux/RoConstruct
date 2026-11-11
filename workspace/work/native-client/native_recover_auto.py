"""Run bounded deterministic native recovery batches from one command."""
import argparse
import json
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def run(command):
    return subprocess.run([sys.executable, *map(str, command)], cwd=ROOT, check=False).returncode


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--gate', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--batch-size', type=int, default=8)
    ap.add_argument('--max-batches', type=int, default=1)
    ap.add_argument('--existing-profiles', action='store_true',
                    help='also profile-prove already native closure-bound methods')
    ap.add_argument('--source-includes', action=argparse.BooleanOptionalAction, default=True,
                    help='carry local quoted donor headers into isolated probes (default: enabled)')
    ap.add_argument('--source-preamble', action='store_true',
                    help='also carry donor preamble declarations into isolated probes')
    ap.add_argument('--add-flags', default='/GS-',
                    help='extra isolated compiler flags; destination still proves its own profile')
    ap.add_argument('--promote', action='store_true')
    ap.add_argument('--lease-name', help='required with --promote; leases each destination')
    args = ap.parse_args()
    if args.promote and not args.lease_name:
        ap.error('--promote requires --lease-name')
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    plan_path = out / 'plan.json'
    plan_command = [ROOT / 'work/native-client/native_convert_plan.py', '--gate', args.gate,
                    '--skip-attempted', '--limit', str(args.batch_size), '--output', plan_path]
    plan_command.append('--source-includes' if args.source_includes else '--no-source-includes')
    if args.source_preamble:
        plan_command.append('--source-preamble')
    if args.add_flags:
        plan_command += ['--add-flags', args.add_flags]
    if run(plan_command):
        raise SystemExit('plan failed')
    plan = json.loads(plan_path.read_text())
    results = []
    for index, entry in enumerate(plan['plans'][:args.max_batches]):
        destination = entry['destination']
        leased = False
        if args.promote:
            lease = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'take', args.lease_name,
                                    destination, '--hours', '1'], cwd=ROOT)
            if lease.returncode:
                results.append({'batch': index, 'owner': entry['owner'], 'status': 'lease_blocked'})
                continue
            leased = True
        batch_out = out / ('batch-%03d' % index)
        command = [ROOT / 'work/native-client/native_convert_run.py', '--plan', plan_path,
                   '--closure', args.closure, '--batch', str(index), '--out', batch_out]
        if args.promote:
            command.append('--promote')
        if args.source_includes:
            command.append('--source-includes')
        if args.source_preamble:
            command.append('--source-preamble')
        if args.add_flags:
            command += ['--add-flags', args.add_flags]
        code = run(command)
        result_path = batch_out / 'result.json'
        result = json.loads(result_path.read_text()) if result_path.is_file() else {'status': 'runner_failed'}
        result['exit'] = code
        # One missing declaration can reject an otherwise independent source
        # batch.  Re-run its individual bodies once; no new hypothesis, just
        # deterministic isolation.  This is especially useful for vendor TUs
        # whose newer revision has one field absent from the 2008 header.
        if len(entry['rows']) > 1 and any(row.get('status') == 'compile_failed'
                                          for row in result.get('requested', [])):
            split = []
            for row_index in range(len(entry['rows'])):
                split_out = out / ('batch-%03d-row-%03d' % (index, row_index))
                split_command = list(command)
                split_command[split_command.index('--out') + 1] = split_out
                split_command += ['--row', str(row_index)]
                split_code = run(split_command)
                split_path = split_out / 'result.json'
                child = json.loads(split_path.read_text()) if split_path.is_file() else {'status': 'runner_failed'}
                child['exit'] = split_code
                child['row_index'] = row_index
                split.append(child)
            result['split_results'] = split
        results.append(result)
        if leased:
            subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'release', args.lease_name], cwd=ROOT)
    profile_results = []
    if args.existing_profiles and len(results) < args.max_batches:
        profile_plan = out / 'existing-profile-plan.json'
        if run([ROOT / 'work/native-client/native_existing_profile_plan.py', '--gate', args.gate,
                '--closure', args.closure,
                '--skip-attempted', '--limit', str(args.batch_size), '--output', profile_plan]):
            raise SystemExit('existing profile plan failed')
        for index, entry in enumerate(json.loads(profile_plan.read_text())['plans'][:args.max_batches - len(results)]):
            batch_out = out / ('existing-profile-%03d' % index)
            code = run([ROOT / 'work/native-client/native_profile_sweep.py', '--source-preamble',
                        '--plan', profile_plan, '--closure', args.closure, '--batch', str(index), '--out', batch_out])
            result_path = batch_out / 'result.json'
            result = json.loads(result_path.read_text()) if result_path.is_file() else {'status': 'runner_failed'}
            result['exit'] = code
            result['kind'] = 'existing-profile'
            profile_results.append(result)
    remaining_path = out / 'remaining-plan.json'
    remaining_command = [ROOT / 'work/native-client/native_convert_plan.py', '--gate', args.gate,
                         '--skip-attempted', '--limit', str(args.batch_size), '--output', remaining_path]
    remaining_command.append('--source-includes' if args.source_includes else '--no-source-includes')
    if args.source_preamble:
        remaining_command.append('--source-preamble')
    if args.add_flags:
        remaining_command += ['--add-flags', args.add_flags]
    if run(remaining_command):
        raise SystemExit('post-run plan failed')
    remaining = json.loads(remaining_path.read_text())['summary']
    effective = [child for row in results for child in row.get('split_results', [row])]
    summary = {'scope': 'bounded deterministic conversion campaign; promotion requires lease, exact, vtable and field-layout gates',
               'plan_summary': plan['summary'], 'batches_requested': args.max_batches,
               'batches_run': len(results),
               'requested_exact': sum(row.get('requested_exact', 0) for row in effective),
               'requested_blocked': sum(row.get('requested_blocked', 0) for row in effective),
               'existing_profile_batches_run': len(profile_results),
               'existing_profile_exact_profiles': sum(len(row.get('exact_profiles', [])) for row in profile_results),
               'remaining_plan_summary': remaining,
               'results': results, 'existing_profile_results': profile_results}
    (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps({key: summary[key] for key in ('plan_summary', 'remaining_plan_summary', 'batches_run', 'requested_exact', 'requested_blocked')}))


if __name__ == '__main__':
    main()
