"""Stage exact native candidates and run pinned, reviewed owner gate plans.

No compiler receipt alone authorizes activation. This adapter reuses the owner
pipeline (lock, pinned inputs, fresh assertions, cleanup and durable resume).
Plans are local owner configuration, never commands supplied by a receipt.
"""
import hashlib
import json
from pathlib import Path
import subprocess
from types import SimpleNamespace

from roc import leases, native_drafts, native_pipeline, worker
from roc.integration import atomic_json as atomic

GATES = {'provider', 'layout', 'abi', 'link', 'preservation', 'regressions', 'p5', 'p6', 'runtime'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def eligible_receipt(root, row):
    identity_inputs = dict(row.get('identity_inputs', {}), **row.get('binding_inputs', {}))
    for name, digest in identity_inputs.items():
        if not Path(name).is_file() or sha(name) != digest:
            raise ValueError('identity input changed: ' + name)
    original = root / 'clients/2008-06/Roblox.exe'
    if identity_inputs.get(str(original)) != sha(original):
        raise ValueError('Missing or changed original image pin; refresh the body proof')
    path = Path(row['receipt']).resolve()
    path.relative_to(root / 'work/2008-06/shared-layouts')
    if sha(path) != row['sha256']:
        raise ValueError('receipt changed')
    receipt = json.loads(path.read_text())
    source = Path(receipt['source_path']).resolve()
    source.relative_to(root / 'rebuild/2008-06/native-classes')
    if sha(source) != receipt['source_sha256']:
        raise ValueError('source changed after proof')
    for name, digest in receipt.get('dependencies', {}).items():
        if sha(name) != digest:
            raise ValueError('proof dependency changed: ' + name)
    checks = receipt['checks']
    if not checks or {r['address'] for r in checks} != set(row['addresses']):
        raise ValueError('receipt target set differs')
    for check in checks:
        metrics = check.get('metrics', {})
        if (check.get('exact') is not True or metrics.get('unmasked_differences') != 0
                or metrics.get('length_delta') != 0):
            raise ValueError('inexact code')
        for field in ('verified_calls', 'verified_references'):
            refs = check.get(field)
            if not isinstance(refs, list) or any(not r.get('status', '').startswith('verified_') for r in refs):
                raise ValueError('incomplete reference proof')
    # The compact index is only a pointer. Revalidate its compiler/object and
    # dependency record before handing it to the owner pipeline.
    analysis = Path(receipt['analysis']).resolve()
    analysis.relative_to(root / 'work/2008-06/native-check-runs')
    builds = json.loads((analysis.parent / 'results.json').read_text())
    build = next(row for row in builds if Path(row['source']).resolve() == source)
    if build.get('status') != 'complete' or build.get('object_sha256') != receipt['object_sha256']:
        raise ValueError('original proof build is incomplete or differs')
    for name, digest in dict(build['dependencies'], **{build['object']: receipt['object_sha256']}).items():
        if sha(name) != digest:
            raise ValueError('proof build input changed: ' + name)
    import native_check_runner as checker
    manifest = json.loads((analysis.parent / 'manifest.json').read_text())
    if checker.build_changes(build, checker.selected_toolchain(manifest)):
        raise ValueError('proof toolchain or compiler flags changed')
    checker.require_proof(json.loads(analysis.read_text()))
    inputs = dict(build['dependencies'])
    inputs.update(identity_inputs)
    inputs.update(build['build_inputs'].get('compiler', {}))
    inputs.update(build['build_inputs'].get('build_tools', {}))
    inputs.update({str(path): row['sha256'], str(analysis): sha(analysis),
                   str(analysis.parent / 'results.json'): sha(analysis.parent / 'results.json'),
                   build['object']: receipt['object_sha256'],
                   str(root / 'clients/2008-06/Roblox.exe'): sha(root / 'clients/2008-06/Roblox.exe')})
    receipt['_required_inputs'] = {str(Path(name).resolve()): digest for name, digest in inputs.items()}
    return source, receipt


def run_leased_plan(root, path, sources):
    spec = json.loads(path.read_text())
    paths = leases._clean(spec.get('write_paths'))
    if any(not leases._literal(name) or not (root / name).resolve().is_relative_to(root) for name in paths):
        raise ValueError('owner write_paths must be concrete paths within the checkout')
    if not set(sources) <= {str((root / name).resolve()) for name in paths}:
        raise ValueError('owner write_paths must include every candidate source')
    api, user = leases._api(SimpleNamespace(server=None, user=None))
    name = 'AutoNativeIntegration-' + sha(path)[:24]
    # A fresh server acquisition is mandatory; cached/offline lease data cannot
    # authorize writes. The server atomically rejects another owner's overlap.
    api.call('/v1/leases/take', dict(user=user, name=name, patterns=paths, hours=3,
                                 note='Reviewed auto-native owner integration'))
    try:
        return native_pipeline.run(path, root)
    finally:
        api.call('/v1/leases/release', dict(user=user, name=name, hours=3))


def handoff_candidates(root, candidates, output_dir):
    """Send frozen evidence through the existing durable native draft inbox."""
    path = output_dir / 'owner-handoff.json'
    state = json.loads(path.read_text()) if path.exists() else {'sessions': {}}
    settings = worker.load_settings()
    marker = root / 'roconstruct-package.json'
    package = json.loads(marker.read_text()) if marker.is_file() else {}
    server = package.get('draft_server') or settings.get('draft_server') or 'https://colinpc.tail2879d0.ts.net/native-drafts'
    issues = []
    for row in candidates:
        key = row['sha256']
        try:
            if key not in state['sessions']:
                if not settings.get('user'):
                    raise ValueError('Contributor identity missing; native handoff remains local')
                scope = Path(row['staged']).relative_to(root).as_posix()
                session = native_drafts.initialize(root, [scope], settings['user'],
                    'deterministic auto-native; review codex:gpt-6-luna', server)
                state['sessions'][key] = {'session': session, 'addresses': row['addresses']}
                atomic(path, state)
            session = state['sessions'][key]['session']
            native_drafts.checkpoint(root, session)
            # flush verifies durable receipt IDs, including already sent bundles.
            native_drafts.flush(root, session)
            session_dir = native_drafts.session_path(root, session)
            bundle = json.loads((session_dir / 'session.json').read_text()).get('parent')
            if not bundle:
                raise ValueError('No changed evidence packet was created')
            receipt = json.loads((session_dir / 'receipts' / (bundle + '.json')).read_text())
            if receipt.get('id') != bundle or receipt.get('durable') is not True:
                raise ValueError('Owner handoff lacks a durable receipt')
            state['sessions'][key].update(state='durably_uploaded', bundle=bundle)
        except (OSError, ValueError, KeyError, RuntimeError, SystemExit) as error:
            issues.append({'candidate': key, 'error_type': type(error).__name__})
        atomic(path, state)
    state.update(state='queued_locally' if issues else 'durably_uploaded' if candidates else 'not_needed', issues=issues)
    atomic(path, state)
    return state


def reviewed_plan(root, entry, addresses, required_inputs=None):
    path = (root / entry['path']).resolve()
    path.relative_to(root / 'rebuild/2008-06')
    if sha(path) != entry['sha256']:
        raise ValueError('owner plan changed after review')
    spec = json.loads(path.read_text())
    native_pipeline.validate(spec)
    if set(spec.get('autopilot_targets', [])) != set(entry['addresses']):
        raise ValueError('owner plan target scope differs')
    if not set(entry['addresses']) <= addresses:
        raise ValueError('owner plan requires unavailable exact candidates')
    pinned = {str((root / name).resolve()): digest for name, digest in spec['inputs'].items()}
    for name, digest in (required_inputs or {}).items():
        if pinned.get(name) != digest:
            raise ValueError('owner plan does not pin candidate proof input: ' + name)
    gates = set()
    integration_seen = False
    for stage in spec['stages']:
        if stage['kind'] == 'publish':
            raise ValueError('publication is separate from auto-native')
        if stage['kind'] == 'check':
            if integration_seen:
                raise ValueError('activation must follow all gates')
            gates.update(stage.get('gates', []))
        elif stage['kind'] == 'integrate':
            if GATES - gates:
                raise ValueError('owner plan missing gates: ' + ', '.join(sorted(GATES - gates)))
            integration_seen = True
    if not integration_seen:
        raise ValueError('owner plan has no integration stage')
    return path


def integrate(root, indexed_rows, output_dir):
    root, output_dir = Path(root).resolve(), Path(output_dir).resolve()
    result = {'state': 'complete', 'attempted': 0, 'selected': 0, 'gated': 0, 'candidates': [], 'issues': [],
              'runtime': 'not_run', 'server_credit': 'not_requested'}
    addresses, proof_inputs = set(), {}
    source_paths = {}
    for row in indexed_rows:
        try:
            source, receipt = eligible_receipt(root, row)
            # Freeze only eligible source and its original path; never replace
            # canonical files or import another worker's header edits.
            folder = root / 'work/native-candidates/auto-native' / row['sha256']
            folder.mkdir(parents=True, exist_ok=True)
            raw = source.read_bytes()
            if hashlib.sha256(raw).hexdigest() != receipt['source_sha256']:
                raise ValueError('candidate changed while staging')
            (folder / source.name).write_bytes(raw)
            atomic(folder / 'candidate.json', dict(row, original_path=source.relative_to(root).as_posix(),
                                                  source_sha256=receipt['source_sha256']))
            (folder / 'body-proof.json').write_bytes(Path(row['receipt']).read_bytes())
            for name, digest in row.get('identity_inputs', {}).items():
                if Path(name).name == 'identity-vtables.json':
                    raw = Path(name).read_bytes()
                    if hashlib.sha256(raw).hexdigest() != digest:
                        raise ValueError('identity proof changed while staging')
                    (folder / 'identity-proof.json').write_bytes(raw)
            result['candidates'].append(dict(row, staged=str(folder)))
            addresses.update(row['addresses'])
            for addr in row['addresses']:
                proof_inputs.setdefault(addr, {}).update(receipt['_required_inputs'])
                source_paths.setdefault(addr, set()).add(str(source))
        except (OSError, ValueError, KeyError, TypeError, StopIteration, SystemExit) as error:
            result['issues'].append({'receipt': row.get('receipt'), 'reason': str(error)})
    config = root / 'rebuild/2008-06/manifests/native-autopilot-integrations.json'
    entries = json.loads(config.read_text()).get('plans', []) if config.is_file() else []
    covered = set()
    for entry in entries:
        if not set(entry.get('addresses', [])) & addresses:
            continue
        try:
            required = {name: digest for addr in entry['addresses'] for name, digest in proof_inputs.get(addr, {}).items()}
            path = reviewed_plan(root, entry, addresses, required)
            result['attempted'] += 1
            sources = {name for addr in entry['addresses'] for name in source_paths.get(addr, set())}
            state = run_leased_plan(root, path, sources)
            if state.get('status') != 'complete':
                raise ValueError('owner pipeline did not complete')
            covered.update(entry['addresses'])
        except (OSError, ValueError, KeyError, TypeError, RuntimeError, subprocess.SubprocessError, SystemExit) as error:
            result['issues'].append({'plan': entry.get('path'), 'reason': str(error)})
    result['selected'] = result['gated'] = len(covered)
    result['selected_addresses'] = sorted(covered)
    if covered:
        result['runtime'] = 'passed_for_selected_targets'
    if addresses - covered:
        result['issues'].append({'addresses': sorted(addresses - covered),
            'reason': 'No complete owner gate plan for these candidates; provider/layout/ABI/link/no-loss/regression/runtime proof required.'})
    if result['issues']:
        result['state'] = 'pending_owner_gates'
    pending = [row for row in result['candidates'] if set(row['addresses']) - covered]
    result['handoff'] = handoff_candidates(root, pending, output_dir)
    atomic(output_dir / 'integration.json', result)
    return result
