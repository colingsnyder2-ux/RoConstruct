"""One deterministic bounded native-recovery pass.

Builds identity queue, native gate and source plan, then runs a requested small
number of no-promotion compile/proof batches.  `--promote` is explicit and
still enforced by exact proof plus the group lease check in the promoter.
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def run(arguments):
    subprocess.run([sys.executable, *map(str, arguments)], cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--inventory', type=Path, default=Path('work/native-client/native-recovery-inventory.json'))
    ap.add_argument('--memfn', type=Path, default=Path('work/native-client/claude-memfn-args.json'))
    ap.add_argument('--eh-types', type=Path, default=Path('work/native-client/claude-eh-types.json'))
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--batch-size', type=int, default=8)
    ap.add_argument('--batches', type=int, default=1)
    ap.add_argument('--promote', action='store_true')
    ap.add_argument('--source-includes', action=argparse.BooleanOptionalAction, default=True,
                    help='carry local quoted donor headers into isolated probes (default: enabled)')
    ap.add_argument('--source-preamble', action='store_true')
    ap.add_argument('--add-flags', default='/GS-')
    ap.add_argument('--retry-attempted', action='store_true',
                    help='include prior nonexact probes (normally advance to untried rows)')
    args = ap.parse_args()
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    queue, gate, plan = out / 'queue.json', out / 'gate.json', out / 'plan.json'
    run([ROOT / 'work/native-client/native_conversion_queue.py', '--closure', args.closure, '--output', queue])
    gate_args = [ROOT / 'work/native-client/native_transplant_gate.py', '--inventory', args.inventory,
                 '--closure', args.closure, '--queue', queue, '--output', gate]
    if args.memfn.is_file():
        gate_args += ['--memfn', args.memfn]
    if args.eh_types.is_file():
        gate_args += ['--eh-types', args.eh_types]
    run(gate_args)
    plan_args = [ROOT / 'work/native-client/native_convert_plan.py', '--gate', gate,
                 '--limit', str(args.batch_size), '--output', plan]
    plan_args.append('--source-includes' if args.source_includes else '--no-source-includes')
    if args.source_preamble:
        plan_args.append('--source-preamble')
    if args.add_flags:
        plan_args += ['--add-flags', args.add_flags]
    if not args.retry_attempted:
        plan_args.append('--skip-attempted')
    run(plan_args)
    plans = json.loads(plan.read_text())['plans']
    results = []
    for batch in range(min(args.batches, len(plans))):
        batch_out = out / ('batch-%03d' % batch)
        command = [ROOT / 'work/native-client/native_convert_run.py', '--plan', plan,
                   '--closure', args.closure, '--batch', str(batch), '--out', batch_out]
        if args.promote:
            command.append('--promote')
        if args.source_includes:
            command.append('--source-includes')
        if args.source_preamble:
            command.append('--source-preamble')
        if args.add_flags:
            command += ['--add-flags', args.add_flags]
        run(command)
        results.append(json.loads((batch_out / 'result.json').read_text()))
    result = {'scope': 'deterministic native recovery; promotion needs exact proof and lease',
              'closure': str(args.closure), 'queue': str(queue), 'gate': str(gate), 'plan': str(plan),
              'batches_requested': args.batches, 'batches_run': len(results), 'promote': args.promote,
              'requested_exact': sum(row['requested_exact'] for row in results),
              'requested_blocked': sum(row['requested_blocked'] for row in results), 'results': results}
    (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
    print(json.dumps({key: result[key] for key in ('batches_run', 'requested_exact', 'requested_blocked', 'promote')}))


if __name__ == '__main__':
    main()
