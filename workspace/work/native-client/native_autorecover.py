"""One-command, bounded, deterministic Phase-1 native recovery.

Plans closure-bound, source-backed methods, then (only with --apply) leases,
draft-checkpoints, promotes, and preserves a machine-readable result.  Every
write remains conditional on the existing byte/reference/layout gates.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import json
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
DEFAULT_CLOSURE = Path('work/native-client/claude-identity-closure.json')


def call(args, check=True):
    return subprocess.run([sys.executable, *map(str, args)], cwd=ROOT,
                          check=check, capture_output=True, text=True)


def roc(args, check=True):
    return subprocess.run([str(ROOT / 'roc.cmd'), *args], cwd=ROOT,
                          check=check, capture_output=True, text=True)


def draft(destination):
    init = call(["-m", "roc.native_drafts", "init", "--user", "codex",
                 "--model", "gpt-5", "--server",
                 "https://colinpc.tail2879d0.ts.net/native-drafts", "--paths", destination])
    session = json.loads(init.stdout)['session']
    call(["-m", "roc.native_drafts", "start", session])
    return session


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, default=DEFAULT_CLOSURE)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--phase', choices=('1', '2'), default='1')
    ap.add_argument('--plans', type=int, default=1, help='small default; raise after measured success')
    ap.add_argument('--start-plan', type=int, default=0, help='skip already measured plans')
    ap.add_argument('--batch-size', type=int, default=20)
    ap.add_argument('--apply', action='store_true', help='lease, draft, and promote exact survivors')
    ap.add_argument('--prove', action='store_true',
                    help='compile and byte/reference-prove planned batches without source writes')
    ap.add_argument('--probe-jobs', type=int, default=1,
                    help='parallel isolated --prove jobs; ignored for leased promotion')
    ap.add_argument('--retry-attempted', action='store_true')
    ap.add_argument('--source-preamble', action='store_true',
                    help='retain real source-local declarations/helpers for isolated donor probes')
    ap.add_argument('--short-identity-objects', action='append', type=Path,
                    help='trusted real VS2008 object directory; add unique 6-15 byte identities before planning')
    ap.add_argument('--plan-file', type=Path,
                    help='pre-proved deterministic plan JSON; skips normal source discovery')
    ap.add_argument('--graph', type=Path,
                    help='decision graph; keep only targets with --graph-action')
    ap.add_argument('--graph-action', default='probe-real-header-source',
                    help='exact decision-graph action allowed into this run')
    ap.add_argument('--owner-prefix', action='append', default=[],
                    help='keep only owner names with one of these prefixes (repeatable)')
    args = ap.parse_args()
    if args.plans < 1 or args.batch_size < 1 or args.start_plan < 0 or args.probe_jobs < 1:
        raise SystemExit('--plans, --batch-size, --probe-jobs must be positive; --start-plan must be nonnegative')
    if args.apply and args.prove:
        raise SystemExit('--apply already proves before promotion; do not combine --prove')
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    effective_closure = args.closure.resolve()
    identity_refresh = None
    if args.short_identity_objects:
        objects = [path.resolve() for path in args.short_identity_objects]
        if any(not path.is_dir() for path in objects):
            raise SystemExit('--short-identity-objects must name existing directories')
        if any('renamed' in (part.lower() for part in path.parts) for path in objects):
            raise SystemExit('renamed mined-packet objects are forbidden as identity inputs')
        candidate = out / 'short-identity-candidate.json'
        command = [ROOT / 'work/native-client/native_identity_closure.py']
        for path in objects:
            command += ['--objects', path]
        # Only unique exact bodies are admitted.  The merged closure remains
        # identity evidence; compile/byte/reference/layout gates remain below.
        call([*command, '--min-seed', '6', '--output', candidate])
        effective_closure = out / 'closure-with-short-identities.json'
        call([ROOT / 'work/native-client/native_identity_merge.py', '--base', args.closure,
              '--candidate', candidate, '--output', effective_closure])
        identity_refresh = {'objects': [str(path.relative_to(ROOT)).replace('\\', '/') for path in objects],
                            'candidate': str(candidate.relative_to(ROOT)).replace('\\', '/'),
                            'merged': str(effective_closure.relative_to(ROOT)).replace('\\', '/')}
    planning = out / 'planning'
    planning.mkdir(parents=True, exist_ok=True)
    plan_path = args.plan_file.resolve() if args.plan_file else planning / 'plan.json'
    if args.plan_file:
        if not plan_path.is_file():
            raise SystemExit('--plan-file does not exist')
    elif args.phase == '1':
        # Zero batches makes this a deterministic no-write dry plan; promotion
        # happens below one plan at a time.
        planner = [ROOT / 'work/native-client/native_recover.py', '--closure', effective_closure,
                   '--out', planning, '--batch-size', str(args.batch_size), '--batches', '0']
        if args.retry_attempted:
            planner.append('--retry-attempted')
        call(planner)
    else:
        queue = planning / 'fieldless-queue.json'
        call([ROOT / 'work/native-client/native_fieldless_queue.py', '--output', queue])
        call([ROOT / 'work/native-client/native_phase2_provider_plan.py', '--queue', queue,
              '--limit', str(args.batch_size), '--output', plan_path])
    plan = json.loads(plan_path.read_text())
    candidate_plans = list(enumerate(plan['plans']))
    if args.owner_prefix:
        candidate_plans = [(index, item) for index, item in candidate_plans
                           if any(item['owner'].startswith(prefix) for prefix in args.owner_prefix)]
    graph_filter = None
    if args.graph:
        graph = json.loads(args.graph.read_text())
        wanted = {str(row['address']).lower() for row in graph.get('next', [])
                  if row.get('action') == args.graph_action}
        if not wanted:
            raise SystemExit('decision graph has no targets for --graph-action %s' % args.graph_action)
        before = len(candidate_plans)
        candidate_plans = [(index, item) for index, item in candidate_plans
                           if any(str(row['addr']).lower() in wanted for row in item['rows'])]
        graph_filter = {'graph': str(args.graph.resolve().relative_to(ROOT)).replace('\\', '/'),
                        'action': args.graph_action, 'eligible_targets': len(wanted),
                        'plans_before_filter': before, 'plans_after_filter': len(candidate_plans)}
    selected = candidate_plans[args.start_plan:args.start_plan + args.plans]
    def prove(index, item):
        run_out = out / ('plan-%03d' % index)
        command = [ROOT / 'work/native-client/native_convert_run.py', '--plan', plan_path,
                   '--closure', effective_closure, '--batch', str(index), '--out', run_out,
                   '--source-includes', '--add-flags', '/GS-']
        if args.source_preamble:
            command.append('--source-preamble')
        try:
            call(command)
            detail = json.loads((run_out / 'result.json').read_text())
            # Donor source often has a file-local declaration needed by one
            # body.  Retry only compilation failures: full preambles cost much
            # more and must not slow already-clean queues.
            if (not args.source_preamble and not detail.get('requested_exact')
                    and detail.get('compile_blockers')):
                call(command + ['--source-preamble'])
                detail = json.loads((run_out / 'result.json').read_text())
                detail['source_preamble_retry'] = True
            return {'plan': index, 'owner': item['owner'], 'source': item['source'],
                    'headers': item['headers'], 'destination': item['destination'],
                    'requested': [row['addr'] for row in item['rows']],
                    'state': 'proven' if detail.get('requested_blocked') == 0 else 'probed_blocked',
                    'result': str((run_out / 'result.json').relative_to(ROOT)), 'detail': detail}
        except subprocess.CalledProcessError as error:
            return {'plan': index, 'owner': item['owner'], 'source': item['source'],
                    'headers': item['headers'], 'destination': item['destination'],
                    'requested': [row['addr'] for row in item['rows']], 'state': 'blocked_tool',
                    'detail': (error.stdout or '') + (error.stderr or '')}
    rows = []
    if args.prove:
        # Every probe has an isolated output path and never writes native source.
        # Parallelism therefore removes only redundant wall time, not proof.
        with ThreadPoolExecutor(max_workers=args.probe_jobs) as pool:
            futures = {pool.submit(prove, index, item): index
                       for index, item in selected}
            rows = [future.result() for future in as_completed(futures)]
        rows.sort(key=lambda row: row['plan'])
    else:
     for index, item in selected:
        result = {'plan': index, 'owner': item['owner'], 'source': item['source'],
                  'headers': item['headers'], 'destination': item['destination'],
                  'requested': [row['addr'] for row in item['rows']], 'state': 'planned'}
        if not args.apply:
            rows.append(result)
            continue
        lease_name = 'native-autorecover-%s-%d' % (item['owner'].replace('::', '-'), int(time.time()))
        taken = roc(['lease', 'take', lease_name, item['destination'], '--hours', '4'], check=False)
        if taken.returncode:
            result.update(state='blocked_lease', detail=(taken.stdout + taken.stderr).strip())
            rows.append(result)
            continue
        session = None
        try:
            session = draft(item['destination'])
            run_out = out / ('plan-%03d' % index)
            command = [ROOT / 'work/native-client/native_convert_run.py', '--plan', plan_path,
                       '--closure', effective_closure, '--batch', str(index), '--out', run_out,
                       '--promote', '--source-includes', '--add-flags', '/GS-']
            if args.source_preamble:
                command.append('--source-preamble')
            call(command)
            detail = json.loads((run_out / 'result.json').read_text())
            if (not args.source_preamble and not detail.get('requested_exact')
                    and detail.get('compile_blockers')):
                call(command + ['--source-preamble'])
                detail = json.loads((run_out / 'result.json').read_text())
                detail['source_preamble_retry'] = True
            if detail.get('compile_logs'):
                hints = run_out / 'provider-hints.json'
                call([ROOT / 'work/native-client/native_provider_hints.py', '--log',
                      ROOT / detail['compile_logs'][0], '--output', hints])
                detail['provider_hints'] = str(hints.relative_to(ROOT)).replace('\\', '/')
            result.update(state='promoted' if detail.get('destination_reproof', {}).get('passed') else 'blocked_gate',
                          result=str((run_out / 'result.json').relative_to(ROOT)), detail=detail)
            call(["-m", "roc.native_drafts", "checkpoint", session], check=False)
            call(["-m", "roc.native_drafts", "flush", session], check=False)
        except subprocess.CalledProcessError as error:
            result.update(state='blocked_tool', detail=(error.stdout or '') + (error.stderr or ''))
        finally:
            roc(['lease', 'release', lease_name], check=False)
        rows.append(result)
    summary = {state: sum(row['state'] == state for row in rows) for state in sorted({row['state'] for row in rows})}
    details = [row.get('detail', {}) if isinstance(row.get('detail', {}), dict) else {} for row in rows]
    proof = {'requested': sum(len(row.get('requested', [])) for row in rows),
             'inactive_exact': sum(detail.get('requested_exact', 0) for detail in details),
             'blocked': sum(detail.get('requested_blocked', 0) for detail in details),
             'compile_failed_batches': sum(bool(detail.get('compile_blockers')) for detail in details)}
    report = {'scope': 'automatic Phase-%s recovery; writes require every existing proof gate' % args.phase,
              'phase': args.phase, 'apply': args.apply, 'prove': args.prove,
              'probe_jobs': args.probe_jobs, 'plans_requested': args.plans,
              'start_plan': args.start_plan, 'batch_size': args.batch_size,
              'owner_prefix': args.owner_prefix, 'plans_after_owner_filter': len(candidate_plans),
              'closure': str(effective_closure.relative_to(ROOT)).replace('\\', '/'),
              'plan_file': str(plan_path.relative_to(ROOT)).replace('\\', '/'),
              'summary': summary, 'proof': proof, 'rows': rows,
              'next': 'raise --plans only after promoted rate is measured; report is not link/runtime evidence'}
    if graph_filter:
        report['decision_graph_filter'] = graph_filter
    if identity_refresh:
        report['short_identity_refresh'] = identity_refresh
    (out / 'result.json').write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps({'summary': summary, 'report': str((out / 'result.json').relative_to(ROOT))}))


if __name__ == '__main__':
    main()
