"""Resumable native source sweep using the existing proof-gated batch runner.

Discovery is advisory. Only identities independently present in the reviewed
registry may be automatically promoted. Native activation and LLM review are
not implemented here and are reported as pending, never as successful.
"""
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time
import uuid

from roc.native_drafts import atomic, lock

ROOT = Path(__file__).resolve().parents[1]
TESTS = ROOT / 'rebuild/2008-06/tests'
RUNNER = TESTS / 'g3d_native_batch_review.py'
DISCOVERY = TESTS / 'native_autopilot_discovery.py'
REGISTRY = TESTS / 'g3d_verified_identities.json'
IDENTITIES = TESTS / 'g3d_native_batch_identities.json'
ORIGINAL = ROOT / 'clients/2008-06/Roblox.exe'
STATE_DIR = ROOT / 'work/native-autopilot/2008-06'


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(part)
    return digest.hexdigest()


def load_module(name, path):
    if str(TESTS) not in sys.path:
        sys.path.insert(0, str(TESTS))
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def make_jobs(discovery, verified, root=ROOT, limit=None):
    """Normalize discovered sources; only reviewed address/symbol pairs can promote."""
    root = Path(root).resolve()
    native = (root / 'rebuild/2008-06/native-classes').resolve()
    jobs, issues = {}, list(discovery.get('issues', []))
    for job in discovery.get('jobs', []):
        try:
            source = Path(job['source']).resolve()
            if not source.is_relative_to(native) or not source.is_file() or source.suffix.lower() not in ('.cpp', '.c'):
                raise ValueError('source is outside native classes or missing')
            key = str(source)
            checks = jobs.setdefault(key, {})
            for row in job.get('checks', []):
                addr = str(row['addr']).lower().removeprefix('0x').zfill(8)
                symbol = row['symbol']
                if len(addr) != 8 or any(c not in '0123456789abcdef' for c in addr) or not isinstance(symbol, str) or not symbol:
                    raise ValueError('invalid candidate address or symbol')
                checks[(addr, symbol)] = {'addr': addr, 'symbol': symbol,
                                          'review_only': addr not in verified.get(symbol, [])}
        except (KeyError, ValueError, TypeError, OSError) as error:
            issues.append({'source': str(job.get('source', '')), 'reason': str(error)})
    ordered = [{'source': source, 'checks': [rows[k] for k in sorted(rows)]}
               for source, rows in sorted(jobs.items(), key=lambda item: item[0].casefold()) if rows]
    return (ordered[:limit] if limit is not None else ordered), issues


def make_batches(jobs, size=8):
    return [jobs[i:i + size] for i in range(0, len(jobs), size)]


def read_report(path):
    data = json.loads(Path(path).read_text(encoding='utf-8'))
    if not isinstance(data, dict) or not isinstance(data.get('indexed'), list) or not isinstance(data.get('unresolved'), list):
        raise ValueError('invalid batch report')
    return data


def alive(pid):
    """None means liveness cannot safely be determined; never duplicate that work."""
    try:
        import psutil
        return psutil.pid_exists(pid)
    except ImportError:
        return None


def fresh_state(client, jobs, issues, followup, directory):
    run = directory / ('run-' + time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
    run.mkdir(parents=True)
    batches = []
    for index, group in enumerate(make_batches(jobs)):
        manifest = run / ('plan-%04d.json' % index)
        atomic(manifest, {'jobs': group})
        batches.append({'manifest': str(manifest), 'state': 'pending', 'sources': [j['source'] for j in group],
                        'source_hashes': {j['source']: sha(j['source']) for j in group}})
    return {'version': 1, 'client': client, 'run': str(run), 'state': 'running', 'started': time.time(),
            'original_sha256': sha(ORIGINAL), 'registry_sha256': sha(REGISTRY), 'runner_sha256': sha(RUNNER),
            'followup_seconds': followup, 'issues': issues, 'batches': batches,
            'integration': {'state': 'not_implemented', 'reason': 'Owner integration gates are not yet connected.'},
            'llm_review': {'state': 'not_implemented', 'reason': 'Automated LLM review is not yet connected.'}}


def save_state(state, state_path):
    atomic(state_path, state)


def report_path(manifest):
    path = Path(manifest)
    return path.with_name(path.stem + '-review-report.json')


def run_batch(state, batch, state_path):
    run = Path(state['run'])
    index = state['batches'].index(batch)
    review = run / ('plan-%04d-review.json' % index)
    report = report_path(batch['manifest'])
    logfile = run / ('batch-%04d.log' % index)
    if batch['state'] == 'running':
        live = alive(batch['pid'])
        if live is None:
            raise RuntimeError('Cannot determine whether previous batch is still running; inspect PID %s' % batch['pid'])
        while live:
            print('Waiting for existing batch PID %s...' % batch['pid'], flush=True)
            time.sleep(10)
            live = alive(batch['pid'])
        if report.is_file():
            batch.update(state='complete', report=str(report), result=read_report(report))
            save_state(state, state_path)
            return
        batch['state'] = 'pending'
    if batch['state'] == 'complete':
        return
    changed = [p for p, expected in batch['source_hashes'].items() if not Path(p).is_file() or sha(p) != expected]
    if changed or sha(ORIGINAL) != state['original_sha256'] or sha(RUNNER) != state['runner_sha256']:
        batch.update(state='stale', reason='Source, original image or runner changed; rerun discovery.', changed=changed)
        save_state(state, state_path)
        return
    command = [sys.executable, str(RUNNER), batch['manifest'], str(IDENTITIES), str(review), '--run', '--no-discovery']
    with logfile.open('wb') as output:
        process = subprocess.Popen(command, cwd=ROOT, stdin=subprocess.DEVNULL, stdout=output, stderr=subprocess.STDOUT,
                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0)
        batch.update(state='running', pid=process.pid, log=str(logfile))
        save_state(state, state_path)
        while True:
            try:
                code = process.wait(timeout=30)
                break
            except subprocess.TimeoutExpired:
                print('Batch %d/%d still running...' % (index + 1, len(state['batches'])), flush=True)
    if code == 0 and report.is_file():
        batch.update(state='complete', report=str(report), result=read_report(report))
    else:
        batch.update(state='failed', exit_code=code, reason='Batch failed; inspect its log.')
    save_state(state, state_path)


def summary(state):
    batches = state['batches']
    reports = [b['result'] for b in batches if b.get('state') == 'complete']
    return {'state': state['state'], 'run': state['run'], 'batches': len(batches),
            'complete_batches': sum(b.get('state') == 'complete' for b in batches),
            'indexed': sum(len(r['indexed']) for r in reports),
            'unresolved': sum(len(r['unresolved']) for r in reports),
            'issues': len(state['issues']), 'integration': state['integration'], 'llm_review': state['llm_review']}


def run(client='2008-06', followup_seconds=300, limit=None, plan_only=False, directory=STATE_DIR):
    if client != '2008-06':
        raise ValueError('Only 2008-06 is currently supported')
    if followup_seconds < 0 or (limit is not None and limit < 1):
        raise ValueError('follow-up must be nonnegative and limit must be positive')
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    state_path = directory / 'state.json'
    with lock(directory / 'coordinator.lock'):
        state = json.loads(state_path.read_text()) if state_path.exists() else None
        if state and state.get('state') in ('running', 'interrupted', 'waiting_followup'):
            if state.get('client') != client or state.get('limit') != limit:
                raise ValueError('An unfinished run has different options; finish it before starting another.')
            print('Resuming ' + state['run'], flush=True)
        else:
            discovery = load_module('native_autopilot_discovery', DISCOVERY).discover(ROOT)
            registry = load_module('native_verified_identities', TESTS / 'native_verified_identities.py')
            verified, rejected = registry.load(REGISTRY, ROOT, ORIGINAL)
            jobs, issues = make_jobs(discovery, verified, ROOT, limit)
            issues.extend({'reason': 'reviewed identity rejected', 'detail': item} for item in rejected)
            state = fresh_state(client, jobs, issues, followup_seconds, directory)
            state['limit'] = limit
            save_state(state, state_path)
        if plan_only:
            state['state'] = 'planned'
            save_state(state, state_path)
            print(json.dumps(summary(state), indent=2))
            return 0
        try:
            for index, batch in enumerate(state['batches']):
                print('Batch %d/%d (%d sources)' % (index + 1, len(state['batches']), len(batch['sources'])), flush=True)
                run_batch(state, batch, state_path)
            state['state'] = 'waiting_followup'
            state.setdefault('followup_at', time.time() + state['followup_seconds'])
            save_state(state, state_path)
            while time.time() < state['followup_at']:
                remaining = state['followup_at'] - time.time()
                print('Follow-up check in %d seconds.' % max(0, int(remaining)), flush=True)
                time.sleep(min(remaining, 30))
            state['followup'] = {'checked_at': time.time(), 'registry_changed': sha(REGISTRY) != state['registry_sha256'],
                                 'note': 'Unresolved results retained; automatic evidence-triggered retries are not yet connected.'}
            state['state'] = 'complete_with_pending'
            save_state(state, state_path)
        except KeyboardInterrupt:
            state['state'] = 'interrupted'
            save_state(state, state_path)
            raise
        result = summary(state)
        atomic(Path(state['run']) / 'summary.json', result)
        print(json.dumps(result, indent=2))
        return 2 if (result['unresolved'] or result['issues'] or any(b['state'] != 'complete' for b in state['batches'])
                     or state['integration']['state'] != 'complete') else 0
