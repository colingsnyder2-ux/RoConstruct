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
        '2008-06/package.json': json.dumps({'format': 1, 'files': {'native-classes/Thing.cpp': hashlib.sha256(b'// native-flags: /O2\nint thing() { return 1; }\n').hexdigest()}}).encode(),
        'workspace/rebuild/2008-06/native-headers/thing.h': b'#include \"../App/include/thing.h\"\n',
        'workspace/rebuild/2008-06/App/include/thing.h': b'#pragma once\n',
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
    assert (out / 'frozen/rebuild/2008-06/native-headers/thing.h').read_bytes() == b'#include \"../App/include/thing.h\"\n'
    assert (out / 'frozen/rebuild/2008-06/App/include/thing.h').read_bytes() == b'#pragma once\n'
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


def test_different_public_version_requires_opt_in_and_keeps_its_flags(source_repo):
    root, spec = source_repo
    public = root / '2008-06/native-classes/Thing.cpp'
    public.write_bytes(b'// native-flags: /Od\nint thing() { return 2; }\n')
    package = root / '2008-06/package.json'
    data = json.loads(package.read_text())
    data['files']['native-classes/Thing.cpp'] = digest(public)
    package.write_text(json.dumps(data))
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'public variant'], cwd=root, check=True)
    spec['base'] = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    out = root / 'work/native-candidates/test'
    with pytest.raises(ValueError, match='Public source differs'):
        source_layout.prepare(root, spec, out)
    spec['moves'][0]['preserve_public_variant'] = True
    plan = source_layout.prepare(root, spec, out)
    assert plan['moves'][0]['public_variant'] is True
    assert (out / 'public/native-classes/Thing.cpp').read_bytes() == public.read_bytes()
    assert not (out / 'public-shim/native-classes/Thing.cpp').exists()
    assert (out / 'candidate/native-classes/Thing.cpp').read_bytes().startswith(b'// native-flags: /O2\n')


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


def test_public_mirror_leaves_different_public_file_unchanged(source_repo, monkeypatch):
    root, spec = source_repo
    public = root / '2008-06/native-classes/Thing.cpp'
    public.write_bytes(b'// native-flags: /Od\nint thing() { return 2; }\n')
    package = root / '2008-06/package.json'
    data = json.loads(package.read_text())
    data['files']['native-classes/Thing.cpp'] = digest(public)
    package.write_text(json.dumps(data))
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'public variant'], cwd=root, check=True)
    spec['base'] = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    spec['moves'][0].update(checks=[], preservation_only=True, preserve_public_variant=True)
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    rows = json.loads((run / 'results.json').read_text())
    for row in rows:
        row['checks'] = []
    (run / 'results.json').write_text(json.dumps(rows))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    assert len(source_layout.verify(root, out, run)['accepted']) == 1
    mirror = json.loads((out / 'public-manifest.json').read_text())
    assert '2008-06/native-classes/Thing.cpp' not in mirror
    assert public.read_bytes() == b'// native-flags: /Od\nint thing() { return 2; }\n'
    assert Path(mirror['2008-06/WindowsClient/src/Thing.cpp']).read_bytes() == (root / 'workspace/rebuild/2008-06/native-classes/Thing.cpp').read_bytes()


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


def test_verify_rejects_tampered_organized_header(source_repo, monkeypatch):
    root, spec = source_repo
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    header = out / 'frozen/rebuild/2008-06/App/include/thing.h'
    header.write_bytes(b'tampered')
    rows = json.loads((run / 'results.json').read_text())
    for row in rows:
        row['dependencies'][str(header)] = digest(header)
    (run / 'results.json').write_text(json.dumps(rows))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    result = source_layout.verify(root, out, run)
    assert not result['accepted']
    assert 'Frozen header differs from canonical base' in result['skipped'][0]['reason']


def test_local_symbol_identity_checks_definition_and_rejects_ambiguity():
    a = {0: ('?helper@?A0x12345678@@YAXXZ', 4, 2, 32)}
    b = {0: ('?helper@?A0x87654321@@YAXXZ', 4, 2, 32)}
    assert next(iter(source_layout.local_symbol_identities(a).values())) == next(iter(source_layout.local_symbol_identities(b).values()))
    b[0] = (b[0][0], 5, 2, 32)
    assert next(iter(source_layout.local_symbol_identities(a).values())) != next(iter(source_layout.local_symbol_identities(b).values()))
    assert not source_layout.local_symbol_identities({0: (a[0][0], 4, 0, 32)})
    assert not source_layout.local_symbol_identities({0: a[0], 1: (a[0][0], 8, 2, 32)})
    assert not source_layout.local_symbol_identities({0: a[0], 1: ('?other@?A0x87654321@@YAXXZ', 4, 2, 32)})


def test_object_identity_compares_local_binding_and_section(monkeypatch):
    import struct
    def fake_index(raw):
        tag = '12345678' if raw[0] == 1 else '87654321'
        value = 5 if raw[0] == 3 else 4
        name = '?helper@?A0x' + tag + '@@YAXXZ'
        section = (b'.text', 0, 0, 4, 10, 20, 0, 1, 0, 0x60000020)
        return [section], {1: (name, value, 1, 32)}, {}, {}
    def fake_functions(raw):
        tag = '12345678' if raw[0] == 1 else '87654321'
        return [('?helper@?A0x' + tag + '@@YAXXZ', b'body', [])]
    def obj(which):
        raw = bytearray(40)
        raw[0] = which
        raw[10:14] = b'code'
        struct.pack_into('<IIH', raw, 20, 0, 1, 20)
        return bytes(raw)
    monkeypatch.setattr(source_layout.match, '_coff_data_index', fake_index)
    monkeypatch.setattr(source_layout.match, 'coff_functions', fake_functions)
    first = source_layout.object_identity(obj(1))
    assert first[0][0][0] == '.text'
    assert first == source_layout.object_identity(obj(2))
    assert first != source_layout.object_identity(obj(3))


def test_prepare_accepts_scoped_existing_accepted_source(source_repo):
    root, spec = source_repo
    old = 'native-classes/accepted/App/util/Thing.cpp'
    for prefix in ('workspace/rebuild/2008-06/', '2008-06/'):
        path = root / prefix / old
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(b'int thing() { return 1; }\n')
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'donor'], cwd=root, check=True)
    spec['base'] = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    spec['moves'][0].update(source=old, target='Base/src/util/Thing.cpp', checks=[], preservation_only=True)
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    assert (out / 'candidate/Base/src/util/Thing.cpp').read_bytes() == b'int thing() { return 1; }\n'
    assert '#include "../../../../Base/src/util/Thing.cpp"' in (out / 'candidate' / old).read_text()
    spec['moves'][0]['source'] = 'native-classes/unreviewed/App/Thing.cpp'
    with pytest.raises(ValueError):
        source_layout.inspect_move(root, spec['base'], spec['moves'][0])


def test_public_manifest_updates_package_hashes(source_repo, monkeypatch):
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
    source_layout.verify(root, out, run)
    mirror = json.loads((out / 'public-manifest.json').read_text())
    package = json.loads(Path(mirror['2008-06/package.json']).read_text())
    for path in ('native-classes/Thing.cpp', 'WindowsClient/src/Thing.cpp'):
        assert package['files'][path] == digest(Path(mirror['2008-06/' + path]))


def test_public_manifest_rejects_stale_existing_package_entry(source_repo, monkeypatch):
    root, spec = source_repo
    package = root / '2008-06/package.json'
    data = json.loads(package.read_text())
    data['files']['native-classes/Thing.cpp'] = 'stale'
    package.write_text(json.dumps(data))
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'stale package'], cwd=root, check=True)
    spec['base'] = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    spec['moves'][0].update(checks=[], preservation_only=True)
    out = root / 'work/native-candidates/test'
    source_layout.prepare(root, spec, out)
    run = make_run(root, out)
    rows = json.loads((run / 'results.json').read_text())
    for row in rows:
        row['checks'] = []
    (run / 'results.json').write_text(json.dumps(rows))
    monkeypatch.setattr(source_layout, 'object_identity', lambda raw: raw)
    with pytest.raises(ValueError, match='package entry is stale'):
        source_layout.verify(root, out, run)
    assert not (out / 'public-manifest.json').exists()


def test_public_package_rejects_unrelated_stale_entry(source_repo):
    root, spec = source_repo
    other = root / '2008-06/other.h'
    other.write_bytes(b'other')
    package = root / '2008-06/package.json'
    data = json.loads(package.read_text())
    data['files']['other.h'] = 'stale'
    package.write_text(json.dumps(data))
    subprocess.run(['git', 'add', '.'], cwd=root, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'unrelated stale package'], cwd=root, check=True)
    base = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    with pytest.raises(ValueError, match='package entry is stale: other.h'):
        source_layout.validate_public_package(root, base, data)
