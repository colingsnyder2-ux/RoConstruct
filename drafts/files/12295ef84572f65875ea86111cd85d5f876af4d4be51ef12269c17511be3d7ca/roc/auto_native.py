"""Resumable native source sweep using the existing proof-gated batch runner.

Discovery is advisory. Only independently reviewed identities can promote.
Inactive proof, native selection, runtime gates and server credit stay separate.
"""
import hashlib
import html
from concurrent.futures import ThreadPoolExecutor
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time
import threading
from types import SimpleNamespace
import uuid

from roc.integration import atomic_json as atomic
from roc.native_drafts import lock

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


def reviewed_identities():
    """Bind reviewed address/symbol identities to the source that was reviewed."""
    registry = load_module('native_verified_identities', TESTS / 'native_verified_identities.py')
    verified, rejected = registry.load(REGISTRY, ROOT, ORIGINAL)
    scoped = set()
    invalid = {json.dumps(row['entry'], sort_keys=True) for row in rejected if 'entry' in row}
    for entry in json.loads(REGISTRY.read_text()).get('identities', []):
        if json.dumps(entry, sort_keys=True) in invalid:
            continue
        if entry['address'] in verified.get(entry['symbol'], []):
            receipt = json.loads((ROOT / entry['receipt']).read_text())
            scoped.add((str(Path(receipt['source_path']).resolve()).casefold(), entry['address'], entry['symbol']))
            # A previously reviewed caller supplies independent callee names
            # and original destinations. Never derive these from the new
            # candidate's byte similarity or a model's suggested identity.
            for check in receipt['checks']:
                if check.get('address') != entry['address'] or check.get('symbol') != entry['symbol']:
                    continue
                for call in check.get('verified_calls', []):
                    if call.get('status') == 'verified_binding' and call.get('kind', 'direct') in ('direct', 'jump'):
                        scoped.add((None, call['target'], call['symbol']))
    return scoped, rejected


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
                proven = (key.casefold(), addr, symbol) in verified or (None, addr, symbol) in verified
                checks[(addr, symbol)] = dict(row, addr=addr, symbol=symbol, review_only=not proven)
        except (KeyError, ValueError, TypeError, OSError) as error:
            issues.append({'source': str(job.get('source', '')), 'reason': str(error)})
    ordered = [{'source': source, 'checks': [rows[k] for k in sorted(rows)]}
               for source, rows in sorted(jobs.items(), key=lambda item:
                   ('G3D' not in Path(item[0]).name, item[0].casefold())) if rows]
    return (ordered[:limit] if limit is not None else ordered), issues


def make_batches(jobs, size=8):
    return [jobs[i:i + size] for i in range(0, len(jobs), size)]


def lease_inventory():
    from roc import leases
    try:
        rows, cached = leases.fetch(SimpleNamespace(server=None, user=None))
        return {'state': 'available', 'checked_at': time.time(), 'cached': cached, 'leases': rows}
    except (Exception, SystemExit) as error:
        return {'state': 'unavailable', 'checked_at': time.time(), 'error_type': type(error).__name__,
                'leases': [], 'cached': False}


def expand_fingerprints(state, state_path):
    """Use existing native objects to find sources missed by filename mapping."""
    if state.get('fingerprint_discovery'):
        return
    from roc.native_autopilot_search import cross_discover
    builds = []
    for batch in state['batches']:
        name = batch.get('result', {}).get('builds')
        if name and Path(name).is_file():
            builds.extend(json.loads(Path(name).read_text()))
    client_work = ROOT / 'work/2008-06'
    for path in sorted(client_work.glob('*source-sweep*/ledger.json')):
        builds.extend(json.loads(path.read_text()).values())
    for path in sorted((client_work / 'native-object-cache').glob('*.json')):
        build = json.loads(path.read_text())
        build['object'] = str(path.with_suffix('.obj'))
        builds.append(build)
    found = cross_discover(ROOT, state['issues'], builds, Path(state['run']))
    verified, _ = reviewed_identities()
    jobs, _ = make_jobs(found, verified)
    present = {(str(Path(job['source']).resolve()).casefold(), check['addr'], check['symbol'])
               for batch in state['batches'] for job in json.loads(Path(batch['manifest']).read_text())['jobs']
               for check in job.get('checks', [])}
    added = []
    for job in jobs:
        checks = [c for c in job['checks'] if (job['source'].casefold(), c['addr'], c['symbol']) not in present]
        if checks:
            added.append(dict(job, checks=checks))
    for group in make_batches(added):
        manifest = Path(state['run']) / ('plan-%04d.json' % len(state['batches']))
        atomic(manifest, {'jobs': group})
        state['batches'].append({'manifest': str(manifest), 'state': 'pending', 'sources': [j['source'] for j in group],
                                'source_hashes': {j['source']: sha(j['source']) for j in group}})
    state['fingerprint_discovery'] = {'objects_reused': found['objects_reused'],
        'pairings': sum(len(j['checks']) for j in added), 'sources': len(added),
        'collisions': len(found['collisions']), 'errors': found['errors'],
        'report': str(Path(state['run']) / 'fingerprint-discovery.json')}
    save_state(state, state_path)


def promote_vtable_matches(state, state_path):
    """Resolve independent typed-slot identities, then run ordinary proof gates."""
    if state.get('vtable_identity'):
        return
    from roc.native_autopilot_identity import discover
    builds = [row for batch in state['batches'] if batch.get('result', {}).get('builds')
              for row in json.loads(Path(batch['result']['builds']).read_text())]
    evidence = discover(ROOT, summary(state)['diagnostics'], builds, Path(state['run']))
    proof_path = Path(state['run']) / 'identity-vtables.json'
    proof_hash = sha(proof_path)
    identified = {(row['address'], row['symbol']) for row in evidence['identities']}
    jobs = {}
    for batch in state['batches']:
        for job in json.loads(Path(batch['manifest']).read_text())['jobs']:
            for check in job.get('checks', []):
                if (check['addr'], check['symbol']) in identified:
                    jobs.setdefault(job['source'], {})[(check['addr'], check['symbol'])] = dict(check, review_only=False,
                        identity_evidence={'path': str(proof_path), 'sha256': proof_hash})
    groups = [{'source': source, 'checks': list(checks.values())} for source, checks in jobs.items()]
    for group in make_batches(groups):
        manifest = Path(state['run']) / ('plan-%04d.json' % len(state['batches']))
        atomic(manifest, {'jobs': group})
        state['batches'].append({'manifest': str(manifest), 'state': 'pending', 'no_variants': True,
            'sources': [job['source'] for job in group],
            'source_hashes': {job['source']: sha(job['source']) for job in group},
            'identity_inputs': dict(evidence['inputs'], **{str(proof_path): proof_hash})})
    state['vtable_identity'] = {'identities': len(identified), 'sources': len(groups),
                               'proof': str(proof_path), 'sha256': proof_hash}
    save_state(state, state_path)


def read_report(path):
    data = json.loads(Path(path).read_text(encoding='utf-8'))
    if not isinstance(data, dict) or not isinstance(data.get('indexed'), list) or not isinstance(data.get('unresolved'), list):
        raise ValueError('invalid batch report')
    return data


def alive(handle):
    """None means liveness cannot safely be determined; never duplicate that work."""
    try:
        import psutil
        process = psutil.Process(handle['pid'])
        return (process.create_time() == handle['created'] and process.is_running()
                and process.status() != psutil.STATUS_ZOMBIE)
    except ImportError:
        return None
    except (psutil.NoSuchProcess, psutil.ZombieProcess):
        return False
    except psutil.AccessDenied:
        return None


def search_changed(builds, cache):
    """Fresh include-name inventory, shared across units only within this check."""
    for build in builds:
        snapshot = build.get('include_search_snapshot') or {}
        for label, expected in snapshot.items():
            working = label == '<working-directory>'
            root = Path(build['object']).parent if working else Path(label)
            key = (str(root), working)
            if key not in cache:
                if not root.is_dir():
                    cache[key] = None
                else:
                    names = []
                    for directory, folders, files in os.walk(root):
                        folders.sort()
                        names.extend(str(Path(directory, name).relative_to(root)) for name in folders + files
                                     if not (working and name in ('candidate.obj', 'compiler.pdb', 'compile.log', 'receipt.json')))
                    cache[key] = hashlib.sha256('\n'.join(names).encode()).hexdigest()
            if cache[key] != expected:
                return True
    return False


def retry_reason(batch, previous_registry, current_registry, search_cache=None):
    if batch.get('attempts', 0) >= 2:
        return None
    if any(not Path(p).is_file() or sha(p) != digest for p, digest in batch.get('dependencies', {}).items()):
        return 'inputs_changed'
    builds = batch.get('result', {}).get('builds')
    if builds and Path(builds).is_file() and search_changed(json.loads(Path(builds).read_text()), search_cache if search_cache is not None else {}):
        return 'include_search_changed'
    if previous_registry != current_registry and batch.get('result', {}).get('unresolved'):
        return 'identity_evidence_changed'
    if batch['state'] == 'failed':
        return 'transient_failure'
    if any(row.get('status') == 'compile_failed' for row in batch.get('result', {}).get('diagnostics', [])):
        return 'compile_failure'
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
            'integration': {'state': 'pending', 'gated': 0}, 'llm_review': {'state': 'pending'}}


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
    # A saved launch intent closes the spawn/save interruption window. Adopt
    # the exact command if the parent died before recording the process handle.
    if batch['state'] == 'launching':
        import psutil
        found = []
        for candidate in psutil.process_iter(['pid', 'cmdline', 'create_time']):
            if candidate.info['cmdline'] == batch['command']:
                found.append(candidate.info)
        if len(found) > 1:
            raise RuntimeError('Multiple workers for the same batch; inspect before resuming.')
        if found:
            batch.update(state='running', process={'pid': found[0]['pid'], 'created': found[0]['create_time']})
        else:
            batch['state'] = 'pending'
    if batch['state'] == 'running':
        live = alive(batch['process'])
        if live is None:
            raise RuntimeError('Cannot inspect previous worker; no duplicate work started.')
        while live:
            print('Waiting for existing batch PID %s...' % batch['process']['pid'], flush=True)
            time.sleep(10)
            live = alive(batch['process'])
            if live is None:
                raise RuntimeError('Previous worker liveness became unknown; no duplicate work started.')
        if report.is_file():
            finish_batch(batch, report)
            save_state(state, state_path)
            return
        batch['state'] = 'pending'
    if batch['state'] == 'complete':
        return
    changed = [p for p, expected in batch['source_hashes'].items() if not Path(p).is_file() or sha(p) != expected]
    changed += [p for p, expected in batch.get('identity_inputs', {}).items() if not Path(p).is_file() or sha(p) != expected]
    if changed or sha(ORIGINAL) != state['original_sha256'] or sha(RUNNER) != state['runner_sha256']:
        batch.update(state='stale', reason='Source, original image or runner changed; rerun discovery.', changed=changed)
        save_state(state, state_path)
        return
    command = [sys.executable, str(RUNNER), batch['manifest'], str(IDENTITIES), str(review), '--run', '--no-discovery']
    if batch.get('no_variants'):
        command.append('--no-variants')
    if report.exists():
        report.replace(report.with_name(report.stem + '-previous-' + uuid.uuid4().hex[:8] + report.suffix))
    batch.update(state='launching', command=command, attempts=batch.get('attempts', 0) + 1)
    save_state(state, state_path)
    with logfile.open('wb') as output:
        process = subprocess.Popen(command, cwd=ROOT, stdin=subprocess.DEVNULL, stdout=output, stderr=subprocess.STDOUT,
                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0)
        import psutil
        batch.update(state='running', process={'pid': process.pid, 'created': psutil.Process(process.pid).create_time()}, log=str(logfile))
        save_state(state, state_path)
        while True:
            try:
                code = process.wait(timeout=30)
                break
            except subprocess.TimeoutExpired:
                print('Batch %d/%d still running...' % (index + 1, len(state['batches'])), flush=True)
    if code == 0 and report.is_file():
        finish_batch(batch, report)
    else:
        batch.update(state='failed', exit_code=code, reason='Batch failed; inspect its log.')
    save_state(state, state_path)


def finish_batch(batch, report):
    changed = [p for p, digest in batch.get('identity_inputs', {}).items() if not Path(p).is_file() or sha(p) != digest]
    if changed:
        batch.update(state='stale', reason='Identity evidence changed during worker execution.', changed=changed)
        batch.pop('result', None)
        return
    data = read_report(report)
    dependencies = dict(batch['source_hashes'])
    dependencies.update(data.get('dependencies', {}))
    dependencies.update(batch.get('identity_inputs', {}))
    batch.update(state='complete', report=str(report), result=data, dependencies=dependencies,
                 report_sha256=sha(report))


def summary(state):
    batches = state['batches']
    reports = [b['result'] for b in batches if b.get('state') == 'complete']
    indexed = {addr for r in reports for addr in r['indexed']}
    integrated = set(state['integration'].get('selected_addresses', []))
    unresolved = {}
    libraries = {}
    diagnostics = [row for report in reports for row in report.get('diagnostics', [])]
    for r in reports:
        for row in r['unresolved']:
            key = row.get('address', row.get('source', 'unknown'))
            if key not in indexed:
                unresolved.setdefault(key, []).append(row)
    for row in diagnostics:
        lib = libraries.setdefault(row.get('library', 'unclassified'), {'functions': set(), 'compiled': set(), 'byte_exact': set(), 'inactive_exact': set(), 'integrated': set(), 'unresolved': set()})
        lib['functions'].add(row['address'])
        if row['status'] != 'compile_failed':
            lib['compiled'].add(row['address'])
        if row['status'] == 'exact':
            lib['byte_exact'].add(row['address'])
        if row['address'] in indexed:
            lib['inactive_exact'].add(row['address'])
        else:
            lib['unresolved'].add(row['address'])
            if row['address'] not in unresolved:
                unresolved[row['address']] = [{'reason': row.get('error') or row['status'], 'source': row['source']}]
        if row['address'] in integrated:
            lib['integrated'].add(row['address'])
    # A failed translation unit affects each target; source-level failures are
    # retained separately instead of being counted as one unresolved function.
    source_failures = {key: rows for key, rows in unresolved.items() if len(key) != 8 or any(c not in '0123456789abcdef' for c in key)}
    unresolved = {key: rows for key, rows in unresolved.items() if key not in source_failures}
    return {'state': state['state'], 'run': state['run'], 'batches': len(batches),
            'complete_batches': sum(b.get('state') == 'complete' for b in batches),
            'indexed': len(indexed), 'indexed_addresses': sorted(indexed),
            'unresolved': len(unresolved), 'unresolved_functions': unresolved,
            'libraries': {name: {key: len(values) for key, values in counts.items()} for name, counts in libraries.items()},
            'diagnostics': diagnostics, 'issues': len(state['issues']), 'discovery_issues': state['issues'],
            'inventory': state.get('inventory', {}), 'source_failures': source_failures,
            'leases': state.get('leases', {}),
            'fingerprint_discovery': state.get('fingerprint_discovery'), 'similarity': state.get('similarity'),
            'vtable_identity': state.get('vtable_identity'),
            'integration': state['integration'], 'llm_review': state['llm_review'], 'server_credit': 'not_requested',
            'followup': state.get('followup')}


def write_report(state):
    """One self-contained local report, usable directly from the filesystem."""
    result = summary(state)
    folder = Path(state['run'])
    atomic(folder / 'summary.json', result)
    esc = lambda value: html.escape(str(value), quote=True)
    libraries = ''.join('<tr><th scope="row">%s</th>%s</tr>' % (esc(name), ''.join(
        '<td>%s</td>' % counts.get(key, 0) for key in ('functions', 'compiled', 'byte_exact', 'inactive_exact', 'integrated', 'unresolved')))
        for name, counts in sorted(result['libraries'].items()))
    rows = []
    for row in result['diagnostics']:
        metrics = row.get('metrics') or {}
        score = lambda key: '—' if metrics.get(key) is None else '%.6f%%' % metrics[key]
        reasons = result['unresolved_functions'].get(row['address'], [])
        details = esc(json.dumps({'source': row['source'], 'symbol': row.get('symbol'), 'metrics': metrics,
            'call_identity': row.get('call_identity'), 'reference_identity': row.get('reference_identity'),
            'unresolved': reasons, 'error': row.get('error')}, indent=2))
        status = 'bytes_exact_awaiting_proof' if row['status'] == 'exact' and row['address'] not in result['indexed_addresses'] else row['status']
        cells = [row.get('library', 'unclassified'), row['address'], status, score('raw_positional_percent'),
                 score('positional_percent'), score('fuzzy_percent'), metrics.get('length_delta', '—')]
        rows.append('<tr>' + ''.join('<td>%s</td>' % esc(value) for value in cells) +
                    '<td><details><summary>Evidence</summary><pre>' + details + '</pre></details></td></tr>')
    report = '''<!doctype html><html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1">
<title>Native sweep report</title><style>
body{font:16px/1.5 system-ui;background:#111916;color:#e3eee7;margin:0;padding:clamp(16px,4vw,56px)}
h1{font-size:clamp(28px,4vw,46px);margin-bottom:8px}a{color:#a7dcbd}p{max-width:90ch;color:#b8cbbf}
table{border-collapse:collapse;width:100%;margin:20px 0 40px;font-variant-numeric:tabular-nums}
th,td{text-align:left;border-bottom:1px solid #3a5144;padding:10px;vertical-align:top}th{color:#b9ddc6}
.scroll{overflow:auto}pre{white-space:pre-wrap;overflow-wrap:anywhere;font:12px/1.5 monospace;max-width:70ch;max-height:36em;overflow:auto}
input{padding:12px;font:inherit;color:inherit;background:#19271f;border:1px solid #6b9279;width:min(90%,600px)}
summary{cursor:pointer}summary:focus-visible,input:focus-visible{outline:3px solid #bce8cc;outline-offset:3px}
small{color:#b8cbbf}</style><main><h1>Native sweep report</h1>'''
    report += '<p>%s · %d / %d batches · %d fresh inactive exact proofs this run · %d unresolved checked functions.</p>' % (
        esc(result['state']), result['complete_batches'], result['batches'], result['indexed'], result['unresolved'])
    report += '<p>Indexed results are local evidence. Selected/runtime-gated: %s. Independent server credit: not requested.</p>' % esc(result['integration'].get('gated', 0))
    report += '<p>Raw includes address bytes. Adjusted compares unmasked bytes at the same positions. Fuzzy aligns bytes. Equal sizes do not prove equality or identity.</p>'
    workflow = esc(os.path.relpath(ROOT / 'work/workflow-map/index.html', folder).replace('\\', '/'))
    report += '<p><a href="summary.json">Complete JSON report</a> · <a href="%s">Workflow map</a> · <a href="similarity.json">Similarity</a> · <a href="fingerprint-discovery.json">Fingerprints</a> · <a href="llm-reviews/queue.json">Model queue</a></p>' % workflow
    report += '<h2>Checked functions by source group</h2><div class="scroll"><table><thead><tr><th>Group</th><th>Discovered</th><th>Compiled</th><th>Bytes exact</th><th>Indexed</th><th>Integrated</th><th>Unresolved</th></tr></thead><tbody>' + libraries + '</tbody></table></div>'
    report += '<h2>Function evidence</h2><label for="filter">Filter library, address or status</label><br><input id="filter" type="search"><div class="scroll"><table id="functions"><thead><tr><th>Group</th><th>Address</th><th>Status</th><th>Raw</th><th>Adjusted</th><th>Fuzzy</th><th>Length delta</th><th>Proof</th></tr></thead><tbody>' + ''.join(rows) + '</tbody></table></div>'
    report += '<h2>Discovery gaps</h2><p>%d inventory issues remain. Complete list and configured library totals are in the JSON report.</p>' % result['issues']
    inventory = ''.join('<tr><th scope="row">%s</th><td>%s</td><td>%s</td><td>%s</td></tr>' % (
        esc(name), esc(counts.get('total', '—')), esc(counts.get('inactive_exact', '—')),
        esc(counts.get('source_unmapped', '—'))) for name, counts in sorted(result['inventory'].items()))
    report += '<details><summary>Configured libraries and existing inactive index</summary><p>Historical index at discovery; separate from fresh proofs in this run. Recipe groups can overlap.</p><div class="scroll"><table><thead><tr><th>Library</th><th>Total</th><th>Prior inactive exact</th><th>Source unmapped</th></tr></thead><tbody>' + inventory + '</tbody></table></div></details>'
    report += '<details><summary>Integration and follow-up</summary><pre>' + esc(json.dumps({'integration': result['integration'], 'followup': result['followup'], 'llm': result['llm_review'], 'leases': result['leases']}, indent=2)) + '</pre></details></main>'
    report += '''<script>const rows=[...document.querySelectorAll('#functions tbody tr')];document.getElementById('filter').addEventListener('input',e=>{const query=e.target.value.toLowerCase();for(const row of rows)row.hidden=!row.textContent.toLowerCase().includes(query)});</script></html>'''
    (folder / 'report.html').write_text(report, encoding='utf-8')
    workflow = ROOT / 'work/workflow-map'
    if workflow.is_dir() and state.get('limit') is None:
        progress = {key: result[key] for key in ('state', 'indexed', 'unresolved', 'libraries', 'integration', 'llm_review')}
        progress.update(updated=time.time(), report=os.path.relpath(folder / 'report.html', workflow).replace('\\', '/'))
        temporary = workflow / 'progress.js.tmp'
        temporary.write_text('window.nativeSweep = ' + json.dumps(progress) + ';\n', encoding='utf-8')
        temporary.replace(workflow / 'progress.js')
    return result


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
        if state and state.get('state') in ('planned', 'running', 'interrupted', 'waiting_followup', 'reviewing_unresolved'):
            if plan_only and state['state'] != 'planned':
                raise ValueError('Cannot use plan-only during an unfinished run.')
            if state.get('client') != client or state.get('limit') != limit:
                raise ValueError('An unfinished run has different options; finish it before starting another.')
            print('Resuming ' + state['run'], flush=True)
        else:
            discovery = load_module('native_autopilot_discovery', DISCOVERY).discover(ROOT)
            verified, rejected = reviewed_identities()
            jobs, issues = make_jobs(discovery, verified, ROOT, limit)
            issues.extend({'reason': 'reviewed identity rejected', 'detail': item} for item in rejected)
            state = fresh_state(client, jobs, issues, followup_seconds, directory)
            state['limit'] = limit
            state['inventory'] = discovery.get('inventory', {})
            save_state(state, state_path)
        if plan_only:
            state['leases'] = lease_inventory()
            state['state'] = 'planned'
            save_state(state, state_path)
            write_report(state)
            print(json.dumps({'state': 'planned', 'run': state['run'], 'batches': len(state['batches']),
                              'sources': sum(len(b['sources']) for b in state['batches']), 'issues': len(state['issues'])}))
            return 0
        state['state'] = 'running'
        state['leases'] = lease_inventory()
        save_state(state, state_path)
        review_pool, review_future = None, None
        stop_reviews = threading.Event()
        try:
            # Base checks provide cached objects. Expansion then appends search
            # leads without repeatedly compiling unrelated source trees.
            for index, batch in enumerate(state['batches']):
                if batch['state'] == 'complete':
                    continue
                print('Batch %d/%d (%d sources)' % (index + 1, len(state['batches']), len(batch['sources'])), flush=True)
                run_batch(state, batch, state_path)
                write_report(state)
            if limit is None:
                previous = len(state['batches'])
                expand_fingerprints(state, state_path)
                for index in range(previous, len(state['batches'])):
                    run_batch(state, state['batches'][index], state_path)
                    write_report(state)
                previous = len(state['batches'])
                promote_vtable_matches(state, state_path)
                for index in range(previous, len(state['batches'])):
                    run_batch(state, state['batches'][index], state_path)
                    write_report(state)
            from roc import native_autopilot_search, native_autopilot_llm
            current = summary(state)
            diagnostics = [row for row in current['diagnostics'] if row['address'] not in current['indexed_addresses']]
            state.setdefault('followup_at', time.time() + state['followup_seconds'])
            if not state.get('similarity'):
                search = native_autopilot_search.investigate(ROOT, diagnostics, Path(state['run']))
                state['similarity'] = {'checked': len(search['functions']), 'objects_reused': search['objects_reused'],
                                       'report': str(Path(state['run']) / 'similarity.json')}
            review_pool = ThreadPoolExecutor(max_workers=1)
            review_future = review_pool.submit(native_autopilot_llm.investigate, ROOT, diagnostics,
                                               Path(state['run']), stop_event=stop_reviews)
            state['state'] = 'waiting_followup'
            save_state(state, state_path)
            while time.time() < state['followup_at']:
                remaining = state['followup_at'] - time.time()
                print('Follow-up check in %d seconds.' % max(0, int(remaining)), flush=True)
                time.sleep(min(remaining, 30))
            current_registry = sha(REGISTRY)
            retried = []
            search_cache = {}
            verified, _ = reviewed_identities()
            for batch in state['batches']:
                reason = retry_reason(batch, state['registry_sha256'], current_registry, search_cache)
                if reason:
                    manifest = json.loads(Path(batch['manifest']).read_text())
                    jobs, _ = make_jobs(manifest, verified)
                    atomic(batch['manifest'], {'jobs': jobs})
                    batch.update(state='pending', source_hashes={j['source']: sha(j['source']) for j in jobs})
                    retried.append({'manifest': batch['manifest'], 'reason': reason})
                    run_batch(state, batch, state_path)
            state['followup'] = {'checked_at': time.time(), 'registry_changed': current_registry != state['registry_sha256'],
                                 'retried': retried}
            integration = TESTS / 'native_autopilot_integration.py'
            if integration.is_file():
                state['integration'] = load_module('native_autopilot_integration', integration).integrate(
                    ROOT, [row for batch in state['batches'] for row in batch.get('result', {}).get('receipts', [])], Path(state['run']))
            while not review_future.done():
                state['state'] = 'reviewing_unresolved'
                queue = Path(state['run']) / 'llm-reviews/queue.json'
                if queue.exists():
                    jobs = json.loads(queue.read_text())['jobs'].values()
                    counts = {name: 0 for name in ('pending', 'running', 'hypothesis', 'unavailable', 'uncertain_timeout')}
                    for job in jobs:
                        counts[job['state']] = counts.get(job['state'], 0) + 1
                    state['llm_review'] = dict(state='running', counts=counts, verified=False)
                    print('Model review progress: ' + json.dumps(counts), flush=True)
                    save_state(state, state_path)
                    write_report(state)
                time.sleep(10)
            state['llm_review'] = review_future.result()
            state['state'] = 'complete_with_pending'
            save_state(state, state_path)
        except KeyboardInterrupt:
            state['state'] = 'interrupted'
            save_state(state, state_path)
            raise
        except Exception as error:
            state.update(state='interrupted', error=str(error))
            save_state(state, state_path)
            write_report(state)
            raise
        finally:
            stop_reviews.set()
            if review_pool:
                review_pool.shutdown(wait=False, cancel_futures=True)
        result = write_report(state)
        print(json.dumps({k: result[k] for k in ('state', 'run', 'batches', 'complete_batches', 'indexed', 'unresolved', 'issues')}, indent=2))
        return 2 if (result['unresolved'] or result['issues'] or any(b['state'] != 'complete' for b in state['batches'])
                     or state['integration']['state'] != 'complete') else 0
