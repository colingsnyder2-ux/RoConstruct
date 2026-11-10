"""Guard and replay the latest diagnostic with one direct-object replacement.

No compilation, executable execution, default selection, or archive mutation.
"""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import time
import uuid

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import rebuild
from p6_probe import classify
from relink_native_document import prepare


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def main():
    baseline = ROOT / 'work/2008-06/native-doc-relinks/20261105-134712-a99864f1'
    command_path = baseline / 'command.json'
    command = json.loads(command_path.read_text())
    prior = json.loads((baseline / 'result.json').read_text())
    old_inputs = json.loads((baseline / 'inputs.json').read_text())
    assert prior['outcome'] == 'link_failed' and not prior['changed_inputs']
    for path, expected in old_inputs.items():
        assert digest(path) == expected, ('prior input drift', path)

    vista = ROOT / 'work/2008-06/shared-layouts/sol-vista-native-20261105'
    subprocess.run([sys.executable, str(vista / 'guard.py')], cwd=ROOT, check=True)
    comparison = json.loads((vista / 'comparison.json').read_text())
    old, new = Path(comparison['old']), Path(comparison['new'])
    assert digest(old) == comparison['old_sha256']
    assert digest(new) == comparison['new_sha256']
    assert comparison['status'] == 'PASS_NO_LOSS_COMDAT'
    assert not comparison['lost'] and not comparison['changed']
    assert len(comparison['vista']) == 4
    assert all(row['new_selection'] == 2 and row['new_equal'] and row['donor_equal']
               for row in comparison['vista'])

    goal = ROOT / 'work/2008-06/shared-layouts/sol-move-goal-20261105'
    receipt = json.loads((goal / 'compile-receipt.json').read_text())
    proof = json.loads((goal / 'proof.json').read_text())
    assert receipt['status'] == 'complete'
    assert digest(receipt['source']) == receipt['source_sha256']
    assert digest(receipt['object']) == receipt['object_sha256']
    for path, expected in receipt['dependencies'].items():
        assert digest(path) == expected, ('move-goal input drift', path)
    assert len(proof) == 1 and not proof[0]['changed_inputs']
    assert proof[0]['object'] == receipt['object'] and len(proof[0]['checks']) == 1
    check = proof[0]['checks'][0]
    assert check['status'] == 'exact' and not check['data_errors']
    assert check['call_identity']['passed']

    arguments = list(command['arguments'])
    indices = [i for i, value in enumerate(arguments)
               if not value.startswith('/') and Path(value).resolve() == old.resolve()]
    assert len(indices) == 1, 'replace exactly one direct native input'
    arguments[indices[0]] = str(new.resolve())
    assert receipt['object'] not in arguments
    arguments.insert(0, receipt['object'])
    tc = rebuild.toolchain(21022)
    destination = ROOT / 'work/2008-06/native-doc-relinks' / (
        time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
    destination.mkdir(parents=True)
    arguments, inputs = prepare(arguments, Path(command['cwd']), destination, tc)
    inputs.add(Path(tc['link']))
    before = {str(path): digest(path) for path in sorted(inputs)}
    removed = sorted(set(old_inputs) - set(before))
    added = sorted(set(before) - set(old_inputs))
    assert removed == [str(old.resolve())], removed
    assert set(added) == {str(new.resolve()), str(Path(receipt['object']).resolve())}, added
    assert all(before[path] == expected for path, expected in old_inputs.items() if path in before)
    write(destination / 'inputs.json', before)
    write(destination / 'command.json', {'cwd': str(destination), 'arguments': arguments})
    response = destination / 'link.rsp'
    response.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in arguments) + '\n')
    started = time.monotonic()
    code, log = rebuild.run(tc, 'link', ['@' + str(response)], destination)
    (destination / 'link.log').write_text(log + '\n')
    changed = [path for path, expected in before.items()
               if not Path(path).is_file() or digest(path) != expected]
    result = classify(code, '', '', link_text=log, exe_exists=any(destination.glob('*.exe')))
    differences = {}
    for key in ('blockers', 'duplicates'):
        previous = {row['symbol'] for row in prior[key]}
        current = {row['symbol'] for row in result[key]}
        differences[key] = {'added': sorted(current - previous), 'removed': sorted(previous - current)}
    result.update(source_run=str(baseline), source_command_sha256=digest(command_path),
                  seconds=round(time.monotonic() - started, 3), changed_inputs=changed,
                  baseline_comparison=differences, explicit_input_delta={'removed': removed, 'added': added},
                  source_compiles=0, executed=False, activation=False, server_credit=0,
                  scope='Isolated diagnostic link. Implicit libraries, original ABI/EH and runtime remain separate gates.')
    if changed:
        result['outcome'] = 'input_drift'
    write(destination / 'result.json', result)
    scoped = HERE / destination.name
    scoped.mkdir()
    for name in ('command.json', 'inputs.json', 'result.json', 'link.log'):
        shutil.copyfile(destination / name, scoped / name)
    campaign = json.loads((HERE / 'campaign.json').read_text())
    campaign.update(current_run=destination.name, baseline_receipt=str(baseline / 'result.json'),
                    unresolved=[row['symbol'] for row in result['blockers']],
                    duplicates=[row['symbol'] for row in result['duplicates']], inputs_changed=changed,
                    next_queue=['Axis renderer authentic Extents evidence parked',
                                'Workspace writer lifetime evidence parked',
                                'Selected provider and ABI/EH audit after successful diagnostic link'])
    write(HERE / 'campaign.json', campaign)
    summary = {'run': str(destination), 'outcome': result['outcome'],
               'unresolved': len(result['blockers']), 'duplicates': len(result['duplicates']),
               'changed_inputs': len(changed), 'source_compiles': 0, 'executed': False}
    write(HERE / 'vista-move-goal-link.json', dict(summary, baseline_comparison=differences,
                                                explicit_input_delta=result['explicit_input_delta']))
    print(json.dumps(summary))
    return 2 if changed else 0


if __name__ == '__main__':
    sys.exit(main())
