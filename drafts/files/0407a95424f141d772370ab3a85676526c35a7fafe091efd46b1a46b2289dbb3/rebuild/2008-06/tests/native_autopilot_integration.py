"""Stage exact native candidates and run pinned, reviewed owner gate plans.

No compiler receipt alone authorizes activation. This adapter reuses the owner
pipeline (lock, pinned inputs, fresh assertions, cleanup and durable resume).
Plans are local owner configuration, never commands supplied by a receipt.
"""
import hashlib
import json
from pathlib import Path
import subprocess

from roc import native_pipeline
from roc.native_drafts import atomic

GATES = {'provider', 'layout', 'abi', 'link', 'preservation', 'regressions', 'p5', 'p6', 'runtime'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def eligible_receipt(root, row):
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
    inputs.update(build['build_inputs'].get('compiler', {}))
    inputs.update(build['build_inputs'].get('build_tools', {}))
    inputs.update({str(path): row['sha256'], str(analysis): sha(analysis),
                   str(analysis.parent / 'results.json'): sha(analysis.parent / 'results.json'),
                   build['object']: receipt['object_sha256'],
                   str(root / 'clients/2008-06/Roblox.exe'): sha(root / 'clients/2008-06/Roblox.exe')})
    receipt['_required_inputs'] = {str(Path(name).resolve()): digest for name, digest in inputs.items()}
    return source, receipt


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
    for row in indexed_rows:
        try:
            source, receipt = eligible_receipt(root, row)
            # Freeze only eligible source and its original path; never replace
            # canonical files or import another worker's header edits.
            folder = output_dir / 'integration-candidates' / row['sha256']
            folder.mkdir(parents=True, exist_ok=True)
            raw = source.read_bytes()
            if hashlib.sha256(raw).hexdigest() != receipt['source_sha256']:
                raise ValueError('candidate changed while staging')
            (folder / source.name).write_bytes(raw)
            atomic(folder / 'candidate.json', dict(row, original_path=source.relative_to(root).as_posix(),
                                                  source_sha256=receipt['source_sha256']))
            result['candidates'].append(dict(row, staged=str(folder)))
            addresses.update(row['addresses'])
            for addr in row['addresses']:
                proof_inputs.setdefault(addr, {}).update(receipt['_required_inputs'])
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
            state = native_pipeline.run(path, root)
            if state.get('status') != 'complete':
                raise ValueError('owner pipeline did not complete')
            covered.update(entry['addresses'])
        except (OSError, ValueError, KeyError, TypeError, RuntimeError, subprocess.SubprocessError) as error:
            result['issues'].append({'plan': entry.get('path'), 'reason': str(error)})
    result['selected'] = result['gated'] = len(covered)
    if covered:
        result['runtime'] = 'passed_for_selected_targets'
    if addresses - covered:
        result['issues'].append({'addresses': sorted(addresses - covered),
            'reason': 'No complete owner gate plan for these candidates; provider/layout/ABI/link/no-loss/regression/runtime proof required.'})
    if result['issues']:
        result['state'] = 'pending_owner_gates'
    atomic(output_dir / 'integration.json', result)
    return result
