"""Run a locally reviewed native integration plan with durable, fail-closed resume."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import time


def fingerprint(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(value, indent=2), encoding='utf-8')
    temporary.replace(path)


def validate(spec):
    if spec.get('schema') != 1 or not spec.get('reviewed_by'):
        raise ValueError('Need schema 1 and explicit local reviewer')
    if not spec.get('inputs') or not spec.get('stages'):
        raise ValueError('Need pinned inputs and stages')
    names = [stage['name'] for stage in spec['stages']]
    if len(names) != len(set(names)):
        raise ValueError('Duplicate stage names')
    effects = [stage['kind'] for stage in spec['stages']]
    if any(kind not in ('check', 'integrate', 'publish') for kind in effects):
        raise ValueError('Unknown stage kind')
    if effects.count('integrate') > 1 or effects.count('publish') > 1:
        raise ValueError('One integration/publication per plan')
    if 'integrate' in effects and ('check' not in effects[:effects.index('integrate')]):
        raise ValueError('Integration requires preceding checks')
    if 'integrate' in effects and 'publish' in effects and effects.index('publish') < effects.index('integrate'):
        raise ValueError('Publication must follow integration')
    for stage in spec['stages'] + spec.get('acquire', []) + spec.get('cleanup', []):
        if not isinstance(stage.get('argv'), list) or not stage['argv'] or not all(isinstance(arg, str) for arg in stage['argv']):
            raise ValueError('Commands require argv arrays; no shell strings')
    for stage in spec['stages']:
        if stage['kind'] == 'check' and not stage.get('assertions'):
            raise ValueError('Checks require explicit receipt assertions; exit zero is insufficient')


def assert_receipts(stage, root):
    for assertion in stage.get('assertions', []):
        value = json.loads((root / assertion['file']).read_text(encoding='utf-8-sig'))
        for key in assertion['key'].split('.'):
            value = value[int(key)] if isinstance(value, list) else value[key]
        if type(value) is not type(assertion['equals']) or value != assertion['equals']:
            raise ValueError('Receipt assertion failed: ' + assertion['file'] + ':' + assertion['key'])


def run(plan, root, execute=None, guard=None):
    from roc.native_drafts import integration_lock
    root = Path(root).resolve()
    plan = Path(plan).resolve()
    spec = json.loads(plan.read_text(encoding='utf-8-sig'))
    validate(spec)
    identity = fingerprint(plan)
    folder = root / 'work/native-pipeline' / identity
    state_path = folder / 'state.json'
    guard = guard or integration_lock
    token = guard(root, 'start')['token']
    deadline = time.monotonic() + 9000
    state = {'plan': str(plan), 'identity': identity, 'stages': {}}
    try:
        if state_path.exists():
            state = json.loads(state_path.read_text())
        def inputs():
            if fingerprint(plan) != identity:
                raise ValueError('Reviewed plan changed during run')
            for name, expected in spec['inputs'].items():
                if fingerprint(root / name) != expected:
                    raise ValueError('Pinned input changed: ' + name)
        def command(stage, label):
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                raise TimeoutError('Run budget exhausted; stop before guard expiry')
            receipts = {item['file']: (root / item['file']).stat().st_mtime_ns
                        if (root / item['file']).exists() else None
                        for item in stage.get('assertions', [])}
            if execute:
                execute(stage, root)
            else:
                folder.mkdir(parents=True, exist_ok=True)
                with (folder / (label + '.log')).open('ab') as log:
                    subprocess.run(stage['argv'], cwd=root / stage.get('cwd', '.'),
                                   stdout=log, stderr=subprocess.STDOUT, check=True,
                                   timeout=min(stage.get('timeout', 1800), remaining))
            for name, before in receipts.items():
                if (root / name).stat().st_mtime_ns == before:
                    raise ValueError('Receipt not refreshed by command: ' + name)
            assert_receipts(stage, root)
        inputs()
        for index, stage in enumerate(spec.get('acquire', [])):
            command(stage, 'acquire-' + str(index))
        for index, stage in enumerate(spec['stages']):
            inputs()
            previous = state['stages'].get(stage['name'], {})
            if stage['kind'] != 'check' and previous.get('state') == 'done':
                continue
            if stage['kind'] != 'check' and previous.get('state') == 'running':
                raise ValueError('Uncertain side effect; reconcile remote receipt before resuming: ' + stage['name'])
            state['stages'][stage['name']] = {'state': 'running', 'kind': stage['kind']}
            save(state_path, state)
            command(stage, 'stage-' + str(index))
            state['stages'][stage['name']]['state'] = 'done'
            save(state_path, state)
        state['status'] = 'complete'
        state.pop('error', None)
    except Exception as error:
        state.update(status='blocked', error=str(error))
        raise
    finally:
        errors = []
        for index, stage in enumerate(spec.get('cleanup', [])):
            try:
                # Cleanup retains a bounded window even after the work deadline.
                deadline = max(deadline, time.monotonic() + 60)
                command(stage, 'cleanup-' + str(index))
            except Exception as error:
                errors.append(str(error))
        try:
            guard(root, 'release', token=token)
        except Exception as error:
            errors.append(str(error))
        state['cleanup_errors'] = errors
        if errors:
            state['status'] = 'blocked'
        save(state_path, state)
    if state['cleanup_errors']:
        raise RuntimeError('Cleanup failed: ' + '; '.join(state['cleanup_errors']))
    return state


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('plan', type=Path)
    parser.add_argument('--root', type=Path, default=Path.cwd())
    parser.add_argument('--validate', action='store_true')
    args = parser.parse_args()
    if args.validate:
        validate(json.loads(args.plan.read_text(encoding='utf-8-sig')))
        print('Plan structure valid; commands not executed')
    else:
        print(json.dumps(run(args.plan, args.root), indent=2))


if __name__ == '__main__':
    main()
