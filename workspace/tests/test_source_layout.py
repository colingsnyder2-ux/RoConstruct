import hashlib
import json
import subprocess
from pathlib import Path

import pytest

from roc import source_layout


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


@pytest.fixture
def source_repo(tmp_path):
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    for path, data in {
        'workspace/rebuild/2008-06/native-classes/Thing.cpp': b'// native-flags: /O2\nint thing() { return 1; }\n',
        '2008-06/native-classes/Thing.cpp': b'// native-flags: /O2\nint thing() { return 1; }\n',
        'workspace/rebuild/2008-06/native-headers/thing.h': b'#pragma once\n',
        'workspace/rebuild/2008-06/tests/native_check_runner.py': b'# reviewed runner\n',
    }.items():
        target = tmp_path / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
    subprocess.run(['git', 'add', '.'], cwd=tmp_path, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'initial'], cwd=tmp_path, check=True)
    base = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=tmp_path, text=True).strip()
    spec = {'base': base, 'moves': [{'source': 'native-classes/Thing.cpp',
        'target': 'WindowsClient/src/Thing.cpp', 'checks': [{'addr': '00400000', 'symbol': '?thing@'}]}]}
    return tmp_path, spec


def test_prepare_preserves_bytes_and_refuses_existing_output(source_repo):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    plan = source_layout.prepare(root, spec, out)
    assert plan['moves'][0]['source'] == 'native-classes/Thing.cpp'
    assert (out / 'candidate/WindowsClient/src/Thing.cpp').read_bytes() == (root / 'workspace/rebuild/2008-06/native-classes/Thing.cpp').read_bytes()
    assert (out / 'candidate/native-classes/Thing.cpp').read_bytes().startswith(b'// native-flags: /O2\n')
    assert (out / 'frozen/rebuild/2008-06/native-headers/thing.h').read_bytes() == b'#pragma once\n'
    with pytest.raises(FileExistsError):
        source_layout.prepare(root, spec, out)


def test_prepare_rejects_unsafe_and_unreviewed_moves(source_repo):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    spec['moves'][0]['target'] = '../escape.cpp'
    with pytest.raises(ValueError):
        source_layout.prepare(root, spec, out)
    spec['moves'][0]['target'] = 'WindowsClient/src/Thing.cpp'
    spec['moves'][0]['checks'] = []
    with pytest.raises(ValueError):
        source_layout.prepare(root, spec, out)
    assert not out.exists()


def test_preservation_only_requires_explicit_opt_in(source_repo):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    spec['moves'][0]['checks'] = []
    with pytest.raises(ValueError):
        source_layout.prepare(root, spec, out)
    spec['moves'][0]['preservation_only'] = True
    plan = source_layout.prepare(root, spec, out)
    assert plan['moves'][0]['preservation_only'] is True
    assert plan['moves'][0]['checks'] == []


def test_compatibility_shim_preserves_flags_after_comments():
    old = source_layout.safe('native-classes/Thing.cpp')
    new = source_layout.safe('WindowsClient/src/Thing.cpp')
    native = b'// status\n// native-flags: /O2 /EHsc\nint thing();\n'
    assert source_layout.compatibility_shim(old, new, native).startswith(b'// native-flags: /O2 /EHsc\n')
    with pytest.raises(ValueError, match='Multiple native flag'):
        source_layout.compatibility_shim(old, new, native + b'// native-flags: /Od\n')


def test_suggestions_reuse_checks_and_skip_bad_sources(source_repo):
    root, spec = source_repo
    good = {'source': 'native-classes/Thing.cpp', 'checks': spec['moves'][0]['checks']}
    output = root / 'work/native-candidates/suggestions.json'
    result = source_layout.suggest(root, spec['base'], 'WindowsClient/src',
        {'jobs': [good, good, {'source': '../outside.cpp', 'checks': good['checks']}, None]}, output)
    assert len(result['moves']) == 1
    assert len(result['skipped']) == 3
    assert result['moves'][0]['target'] == 'WindowsClient/src/Thing.cpp'
    assert json.loads(output.read_text())['moves'] == result['moves']
    with pytest.raises(ValueError):
        source_layout.suggest(root, spec['base'], 'WindowsClient/src', {'jobs': [good]}, output)


def make_run(root, out, different=False, wrong_check=False):
    run = root / 'work/2008-06/native-check-runs/test'
    run.mkdir(parents=True)
    compiler = run / 'compiler'
    compiler.write_bytes(b'compiler')
    rows = []
    for index, source in enumerate((out / 'original/native-classes/Thing.cpp',
                                    out / 'candidate/native-classes/Thing.cpp',
                                    out / 'candidate/WindowsClient/src/Thing.cpp')):
        obj = run / ('unit%d.obj' % index)
        obj.write_bytes(b'different' if index == 2 and different else b'object')
        header = out / 'frozen/rebuild/2008-06/native-headers/thing.h'
        rows.append({'source': str(source), 'status': 'complete', 'object': str(obj),
                     'source_sha256': digest(source), 'object_sha256': digest(obj), 'flags': ['/O2'],
                     'build_inputs': {'compiler': {str(compiler): digest(compiler)}},
                     'dependencies': {str(source): digest(source), str(header): digest(header)},
                     'checks': [{'addr': '00400001' if wrong_check else '00400000',
                                 'requested_symbol': '?thing@', 'status': 'exact', 'data_errors': []}]})
    runner = root / 'workspace/rebuild/2008-06/tests/native_check_runner.py'
    (run / 'summary.json').write_text(json.dumps({'state': 'complete', 'total_sources': 3,
        'completed_sources': 3, 'shared_headers_changed': [], 'observer_sha256': digest(runner)}))
    (run / 'results.json').write_text(json.dumps(rows))
    return run


def test_preservation_only_checks_whole_object_without_claiming_original(source_repo, monkeypatch):
    root, spec = source_repo
    spec['moves'][0].update(checks=[], preservation_only=True)
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    rows = json.loads((run / 'results.json').read_text())
    for row in rows:
        row['checks'] = []
    (run / 'results.json').write_text(json.dumps(rows))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    result = source_layout.verify(root, out, run)
    assert result['accepted'][0]['preservation_only'] is True
    assert 'do not prove original identity' in result['scope']


def test_rejects_original_location_object_difference(source_repo, monkeypatch):
    root, spec = source_repo
    spec['moves'][0].update(checks=[], preservation_only=True)
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    rows = json.loads((run / 'results.json').read_text())
    for row in rows:
        row['checks'] = []
    original = Path(rows[0]['object'])
    original.write_bytes(b'different original object')
    rows[0]['object_sha256'] = digest(original)
    (run / 'results.json').write_text(json.dumps(rows))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    result = source_layout.verify(root, out, run)
    assert not result['accepted']
    assert 'relocations differ' in result['skipped'][0]['reason']


@pytest.mark.parametrize('different,wrong_check,accepted', [(False, False, 1), (True, False, 0), (False, True, 0)])
def test_verify_accepts_only_matching_fresh_evidence(source_repo, monkeypatch, different, wrong_check, accepted):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out, different, wrong_check)
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    monkeypatch.setattr(source_layout.match, 'coff_functions', lambda raw: [('?thing@', b'body', [])])
    monkeypatch.setattr(source_layout.match, 'target', lambda client, addr: (b'body', [], None))
    monkeypatch.setattr(source_layout.match, 'exact_match', lambda *args: True)
    monkeypatch.setattr(source_layout.match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(source_layout.match, 'data_check', lambda *args: ([], []))
    result = source_layout.verify(root, out, run)
    assert len(result['accepted']) == accepted
    assert len(result['skipped']) == 1 - accepted
    manifest = json.loads((out / 'integration-manifest.json').read_text())
    assert len(manifest['files']) == 2 * accepted
    with pytest.raises(FileExistsError):
        source_layout.verify(root, out, run)


def test_verify_rejects_changed_dependency(source_repo, monkeypatch):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    (run / 'compiler').write_bytes(b'changed')
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    result = source_layout.verify(root, out, run)
    assert not result['accepted']
    assert 'Compiler changed' in result['skipped'][0]['reason']


def test_verify_rechecks_cached_inputs_after_batch(source_repo, monkeypatch):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    def change_compiler(raw):
        (run / 'compiler').write_bytes(b'changed during verification')
        return raw
    monkeypatch.setattr(source_layout, 'object_identity', change_compiler)
    monkeypatch.setattr(source_layout.match, 'coff_functions', lambda raw: [('?thing@', b'body', [])])
    monkeypatch.setattr(source_layout.match, 'target', lambda client, addr: (b'body', [], None))
    monkeypatch.setattr(source_layout.match, 'exact_match', lambda *args: True)
    monkeypatch.setattr(source_layout.match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(source_layout.match, 'data_check', lambda *args: ([], []))
    with pytest.raises(ValueError, match='Input changed during batch verification'):
        source_layout.verify(root, out, run)


def test_verify_rejects_tampered_frozen_header(source_repo, monkeypatch):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    header = out / 'frozen/rebuild/2008-06/native-headers/thing.h'
    header.write_bytes(b'#pragma once\n// changed\n')
    run = make_run(root, out)
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    result = source_layout.verify(root, out, run)
    assert not result['accepted']
    assert 'differs from canonical base' in result['skipped'][0]['reason']


def test_verify_does_not_trust_receipt_exact_claim(source_repo, monkeypatch):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    monkeypatch.setattr(source_layout.match, 'coff_functions', lambda raw: [('?thing@', b'wrong', [])])
    monkeypatch.setattr(source_layout.match, 'target', lambda client, addr: (b'original', [], None))
    monkeypatch.setattr(source_layout.match, 'exact_match', lambda *args: False)
    result = source_layout.verify(root, out, run)
    assert not result['accepted']
    assert 'Independent original code check failed' in result['skipped'][0]['reason']


def test_run_rejects_unapproved_runner(source_repo):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    with pytest.raises(ValueError, match='runner hash'):
        source_layout.run(root, out, '0' * 64, 1)


def test_finished_partial_batch_skips_failed_sources(source_repo, monkeypatch):
    root, spec = source_repo
    for prefix in ('workspace/rebuild/2008-06/', '2008-06/'):
        (root / prefix / 'native-classes/Other.cpp').write_bytes(b'int other() { return 2; }\n')
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'add other'], cwd=root, check=True)
    spec['base'] = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    spec['moves'].append({'source': 'native-classes/Other.cpp', 'target': 'WindowsClient/src/Other.cpp',
                          'checks': [{'addr': '00400001', 'symbol': '?other@'}]})
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    rows = json.loads((run / 'results.json').read_text())
    for source in (out / 'original/native-classes/Other.cpp', out / 'candidate/native-classes/Other.cpp', out / 'candidate/WindowsClient/src/Other.cpp'):
        rows.append({'source': str(source), 'status': 'failed'})
    (run / 'results.json').write_text(json.dumps(rows))
    summary = json.loads((run / 'summary.json').read_text())
    summary.update(state='failed', total_sources=6, completed_sources=6)
    (run / 'summary.json').write_text(json.dumps(summary))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    monkeypatch.setattr(source_layout.match, 'coff_functions', lambda raw: [('?thing@', b'body', [])])
    monkeypatch.setattr(source_layout.match, 'target', lambda client, addr: (b'body', [], None))
    monkeypatch.setattr(source_layout.match, 'exact_match', lambda *args: True)
    monkeypatch.setattr(source_layout.match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(source_layout.match, 'data_check', lambda *args: ([], []))
    result = source_layout.verify(root, out, run)
    assert len(result['accepted']) == 1
    assert len(result['skipped']) == 1
    assert 'Other.cpp' in result['skipped'][0]['source']


def test_incomplete_failed_batch_is_not_accepted(source_repo):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    summary = json.loads((run / 'summary.json').read_text())
    summary.update(state='failed', completed_sources=1, error='worker failed')
    (run / 'summary.json').write_text(json.dumps(summary))
    with pytest.raises(ValueError, match='Runner incomplete'):
        source_layout.verify(root, out, run)
