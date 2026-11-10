"""Task-local isolated link replay; exact explicit-input deltas only, no execution."""
from pathlib import Path
import json
import shutil
import subprocess
import time
import uuid
from link_vista_move_goal import ROOT, HERE, digest, write, prepare, classify, rebuild


def replay(baseline, replacements, additions, label, limitations):
    command_path = baseline / 'command.json'
    command = json.loads(command_path.read_text())
    prior = json.loads((baseline / 'result.json').read_text())
    recorded = json.loads((baseline / 'inputs.json').read_text())
    assert prior['outcome'] in ('link_failed', 'linked') and not prior['changed_inputs']
    for path, expected in recorded.items():
        assert digest(path) == expected, ('prior input drift', path)
    arguments = list(command['arguments'])
    removed_expected, added_expected = set(), set()
    for old, new in replacements:
        old, new = Path(old).resolve(), Path(new).resolve()
        assert old.is_file() and new.is_file() and old.suffix == new.suffix
        assert old.suffix.lower() in ('.obj', '.lib', '.res')
        indices = [i for i, value in enumerate(arguments)
                   if not value.startswith('/') and Path(value).resolve() == old]
        assert len(indices) == 1
        arguments[indices[0]] = str(new)
        removed_expected.add(str(old))
        added_expected.add(str(new))
    for path in additions:
        path = Path(path).resolve()
        assert path.is_file() and path.suffix.lower() == '.obj' and str(path) not in arguments
        arguments.insert(0, str(path))
        added_expected.add(str(path))
    tc = rebuild.toolchain(21022)
    destination = ROOT / 'work/2008-06/native-doc-relinks' / (
        time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
    destination.mkdir(parents=True)
    arguments, inputs = prepare(arguments, Path(command['cwd']), destination, tc)
    inputs.add(Path(tc['link']))
    before = {str(path): digest(path) for path in sorted(inputs)}
    removed, added = sorted(set(recorded) - set(before)), sorted(set(before) - set(recorded))
    assert set(removed) == removed_expected and set(added) == added_expected
    assert all(before[path] == expected for path, expected in recorded.items() if path in before)
    write(destination / 'inputs.json', before)
    write(destination / 'command.json', {'cwd': str(destination), 'arguments': arguments})
    response = destination / 'link.rsp'
    response.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in arguments) + '\n')
    start = time.monotonic()
    code, log = rebuild.run(tc, 'link', ['@' + str(response)], destination)
    (destination / 'link.log').write_text(log + '\n')
    changed = [path for path, expected in before.items()
               if not Path(path).is_file() or digest(path) != expected]
    result = classify(code, '', '', link_text=log, exe_exists=any(destination.glob('*.exe')))
    delta = {}
    for key in ('blockers', 'duplicates'):
        previous, current = {r['symbol'] for r in prior[key]}, {r['symbol'] for r in result[key]}
        delta[key] = {'added': sorted(current - previous), 'removed': sorted(previous - current)}
    result.update(source_run=str(baseline), source_command_sha256=digest(command_path),
                  seconds=round(time.monotonic() - start, 3), changed_inputs=changed,
                  baseline_comparison=delta, explicit_input_delta={'removed': removed, 'added': added},
                  source_compiles=0, executed=False, activation=False, server_credit=0,
                  limitations=limitations, scope=__doc__)
    if changed:
        result['outcome'] = 'input_drift'
    write(destination / 'result.json', result)
    saved = HERE / destination.name
    saved.mkdir()
    for name in ('command.json', 'inputs.json', 'result.json', 'link.log'):
        shutil.copyfile(destination / name, saved / name)
    campaign = json.loads((HERE / 'campaign.json').read_text())
    campaign.update(current_run=destination.name, baseline_receipt=str(baseline / 'result.json'),
                    unresolved=[r['symbol'] for r in result['blockers']],
                    duplicates=[r['symbol'] for r in result['duplicates']], inputs_changed=changed)
    libraries = [Path(new) for old, new in replacements if Path(new).suffix.lower() == '.lib']
    if libraries:
        assert len(libraries) == 1
        campaign.update(cumulative_archive=str(libraries[0]), cumulative_archive_sha256=digest(libraries[0]))
    write(HERE / 'campaign.json', campaign)
    summary = {'run': str(destination), 'outcome': result['outcome'], 'unresolved': len(result['blockers']),
               'duplicates': len(result['duplicates']), 'changed_inputs': len(changed),
               'explicit_inputs': len(before), 'source_compiles': 0, 'executed': False}
    write(HERE / (label + '-link.json'), dict(summary, baseline_comparison=delta,
                                           explicit_input_delta=result['explicit_input_delta'], limitations=limitations))
    print(json.dumps(summary))
    assert not changed
    return destination
