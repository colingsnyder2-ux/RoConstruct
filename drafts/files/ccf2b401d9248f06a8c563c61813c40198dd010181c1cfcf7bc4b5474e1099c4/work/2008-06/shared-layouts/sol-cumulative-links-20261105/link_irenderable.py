"""Replay the actual diagnostic with guarded authentic IRenderable ownership."""
from collections import Counter
import json
from pathlib import Path
import shutil
import subprocess
import sys
import time
import uuid
from link_vista_move_goal import ROOT, HERE, digest, write, prepare, classify, rebuild


def members(path):
    raw = Path(path).read_bytes()
    assert raw[:8] == b'!<arch>\n'
    result, offset = [], 8
    while offset < len(raw):
        header = raw[offset:offset + 60]
        assert len(header) == 60 and header[58:] == b'`\n'
        size = int(header[48:58])
        name = header[:16].decode('ascii').strip()
        payload = raw[offset + 60:offset + 60 + size]
        assert len(payload) == size
        if name not in ('/', '//', '/SYM64/'):
            import hashlib
            result.append(hashlib.sha256(payload).hexdigest())
        offset += 60 + size + (size & 1)
    assert offset == len(raw)
    return Counter(result)


def main():
    scope = ROOT / 'work/2008-06/shared-layouts/sol-irenderable-20261105'
    replacement = json.loads((scope / 'replacement.json').read_text())
    subprocess.run([sys.executable, str(ROOT / 'work/native-candidates/sol-irenderable-20261105/guard.py')],
                   cwd=ROOT, check=True)
    receipts = [json.loads((scope / 'run' / unit / 'receipt.json').read_text())
                for unit in ('unit-000', 'unit-001')]
    for receipt in receipts:
        assert receipt['status'] == 'complete'
        assert digest(receipt['source']) == receipt['source_sha256']
        assert digest(receipt['object']) == receipt['object_sha256']
        for path, expected in receipt['dependencies'].items():
            assert digest(path) == expected, path
    definitions = {}
    for flag in receipts[0]['flags']:
        if flag[:2].upper() in ('/D', '/U'):
            definitions[flag[2:].split('=')[0]] = flag[:2].upper() == '/D'
    assert definitions.get('_RELEASEASSERT') is False and definitions.get('_DEBUG') is False
    proof = json.loads((scope / 'native-proof.json').read_text())
    assert proof['object_sha256'] == replacement['native_provider_sha256']
    assert len(proof['checks']) == 1
    check = proof['checks'][0]
    assert check['status'] == 'exact' and check['target_size'] == check['object_size'] == 1
    assert not check['data_errors'] and check['call_identity']['passed']
    assert check['call_identity']['calls'] == []
    old, new = Path(replacement['base_archive']), Path(replacement['archive_proposal'])
    native = Path(replacement['native_provider'])
    assert digest(old) == replacement['base_sha256']
    assert digest(new) == replacement['proposal_sha256']
    assert digest(native) == replacement['native_provider_sha256']
    old_members, new_members = members(old), members(new)
    assert sum(old_members.values()) == sum(new_members.values()) == 267
    assert old_members[replacement['old_member_sha256']] == 1
    assert new_members[replacement['new_member_sha256']] == 1
    old_members.subtract([replacement['old_member_sha256']])
    new_members.subtract([replacement['new_member_sha256']])
    assert +old_members == +new_members and sum((+old_members).values()) == 266

    baseline = ROOT / 'work/2008-06/native-doc-relinks/20261105-135622-0161a2a8'
    command_path = baseline / 'command.json'
    command = json.loads(command_path.read_text())
    prior = json.loads((baseline / 'result.json').read_text())
    old_inputs = json.loads((baseline / 'inputs.json').read_text())
    assert prior['outcome'] == 'link_failed' and not prior['changed_inputs']
    for path, expected in old_inputs.items():
        assert digest(path) == expected, path
    arguments = list(command['arguments'])
    indices = [i for i, value in enumerate(arguments)
               if not value.startswith('/') and Path(value).resolve() == old.resolve()]
    assert len(indices) == 1
    arguments[indices[0]] = str(new.resolve())
    assert str(native.resolve()) not in arguments
    arguments.insert(0, str(native.resolve()))
    tc = rebuild.toolchain(21022)
    destination = ROOT / 'work/2008-06/native-doc-relinks' / (
        time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
    destination.mkdir(parents=True)
    arguments, inputs = prepare(arguments, Path(command['cwd']), destination, tc)
    inputs.add(Path(tc['link']))
    before = {str(path): digest(path) for path in sorted(inputs)}
    removed, added = sorted(set(old_inputs) - set(before)), sorted(set(before) - set(old_inputs))
    assert removed == [str(old.resolve())]
    assert set(added) == {str(new.resolve()), str(native.resolve())}
    assert all(before[path] == expected for path, expected in old_inputs.items() if path in before)
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
                  unchanged_other_archive_members=266, native_profile=receipts[0]['flags'],
                  source_compiles=0, executed=False, activation=False, server_credit=0,
                  scope='Isolated diagnostic only; no selected PE or complete ABI/EH/runtime claim.')
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
                    duplicates=[r['symbol'] for r in result['duplicates']], inputs_changed=changed,
                    cumulative_archive=str(new), cumulative_archive_sha256=digest(new))
    write(HERE / 'campaign.json', campaign)
    summary = {'run': str(destination), 'outcome': result['outcome'], 'unresolved': len(result['blockers']),
               'duplicates': len(result['duplicates']), 'changed_inputs': len(changed),
               'explicit_inputs': len(before), 'source_compiles': 0, 'executed': False}
    write(HERE / 'irenderable-link.json', dict(summary, baseline_comparison=delta,
                                            explicit_input_delta=result['explicit_input_delta']))
    print(json.dumps(summary))
    return 2 if changed else 0


if __name__ == '__main__':
    sys.exit(main())
