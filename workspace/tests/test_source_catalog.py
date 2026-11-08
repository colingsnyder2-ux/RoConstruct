from roc import source_catalog


def test_classify_pairs_canonical_and_public_blobs():
    rows = source_catalog.classify_files(
        {'native-classes/A.cpp': 'same', 'native-headers/B.h': 'canonical'},
        {'native-classes/A.cpp': 'same', 'native-headers/B.h': 'public',
         'native-classes/C.cpp': 'only-public'})
    assert [(row['path'], row['state']) for row in rows] == [
        ('native-classes/A.cpp', 'equivalent'),
        ('native-classes/C.cpp', 'public-only'),
        ('native-headers/B.h', 'diverged'),
    ]


def test_native_entries_excludes_non_native_tree_paths(tmp_path, monkeypatch):
    def entries(root, ref, prefix):
        if any(prefix.endswith('/' + scope) for scope in source_catalog.ORGANIZED_SCOPES + source_catalog.EXPERIMENT_SCOPES):
            return {}
        return {'A.cpp': prefix} if prefix.endswith('native-classes') else {'B.h': prefix}
    monkeypatch.setattr(source_catalog, 'tree_entries', entries)
    rows = source_catalog.native_entries(tmp_path, 'work', 'workspace/rebuild/2008-06')
    assert rows == {
        'native-classes/A.cpp': 'workspace/rebuild/2008-06/native-classes',
        'native-headers/B.h': 'workspace/rebuild/2008-06/native-headers',
        'native-world/B.h': 'workspace/rebuild/2008-06/native-world',
    }


def test_snapshot_hash_tracks_paths_and_contents(tmp_path):
    folder = tmp_path / 'snapshot'
    folder.mkdir()
    (folder / 'A.cpp').write_text('int a;')
    first = source_catalog.local_snapshot(tmp_path, 'test', 'snapshot', 'test')
    (folder / 'B.h').write_text('struct B;')
    second = source_catalog.local_snapshot(tmp_path, 'test', 'snapshot', 'test')
    assert first['source_files'] == 1
    assert second['source_files'] == 2
    assert first['sha256'] != second['sha256']


def test_catalog_refuses_overwrite(tmp_path):
    out = tmp_path / 'out.json'
    out.write_text('{}')
    try:
        source_catalog.main.__wrapped__ if hasattr(source_catalog.main, '__wrapped__') else None
    except Exception:
        pass
    import subprocess, sys
    from pathlib import Path
    res = subprocess.run([sys.executable, '-m', 'roc.source_catalog',
                          '--ref', 'HEAD', '--output', str(out)],
                         capture_output=True, text=True)
    assert res.returncode != 0
    assert 'Refusing to overwrite' in res.stderr or 'Refusing' in res.stdout + res.stderr


def test_catalog_produces_valid_json(tmp_path):
    out = tmp_path / 'cat.json'
    import subprocess, sys
    res = subprocess.run([sys.executable, '-m', 'roc.source_catalog',
                          '--ref', 'HEAD', '--output', str(out)],
                         capture_output=True, text=True)
    assert res.returncode == 0, res.stderr
    import json
    d = json.loads(out.read_text())
    assert d['schema'] == 1
    assert 'summary' in d
    assert 'files' in d


def test_source_map_keeps_every_catalog_file_and_marks_unclear_paths_other():
    data = {
        'work_commit': 'abc',
        'authority': 'test',
        'scope': 'test',
        'files': [
            {'path': 'native-classes/CRobloxApp.cpp', 'state': 'diverged'},
            {'path': 'native-headers/NoKnownFamily.h', 'state': 'public-only'},
        ],
    }
    mapped = source_catalog.source_map(data)
    rows = [row for group in mapped['groups'] for row in group['files']]
    assert len(rows) == 2
    assert rows[0]['group'] == 'WindowsClient'
    assert rows[1]['group'] == 'Other'


def test_local_variants_deduplicate_bytes_without_losing_origins(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'git', lambda *args: 'abc')
    monkeypatch.setattr(source_catalog.subprocess, 'check_output', lambda *args, **kwargs: b'')
    for name in ('first', 'second'):
        folder = tmp_path / name / 'rebuild/2008-06/native-classes'
        folder.mkdir(parents=True)
        (folder / 'Instance.cpp').write_bytes(b'void Instance::remove() {}\n')
    result = source_catalog.source_versions(tmp_path, 'abc', source_roots=[tmp_path])
    assert not result['errors']
    assert len(result['versions']) == 1
    assert len(result['versions'][0]['origins']) == 2
    assert result['versions'][0]['proof_status'] == 'not-assessed'
    assert all('url' not in origin for origin in result['versions'][0]['origins'])


def test_other_client_native_paths_do_not_enter_2008_catalog():
    assert source_catalog.logical_native_path('snapshot/2008-06/native-classes/A.cpp') == 'native-classes/A.cpp'
    assert source_catalog.logical_native_path('snapshot/2016-06/native-classes/A.cpp') is None
    assert source_catalog.logical_native_path('2008-06/reference/2016-06/native-classes/A.cpp') is None
    assert source_catalog.logical_native_path('unknown/native-classes/A.cpp') is None
    assert source_catalog.map_group('native-classes/AppUnit558_2008Instance.cpp') == 'App/v8tree'


def test_organized_source_is_indexed_without_mixing_client_versions(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'tree_entries', lambda root, ref, prefix:
                        {'v8tree/InstanceChildLookup.cpp': 'blob'} if prefix.endswith('/App/src') else {})
    rows = source_catalog.native_entries(tmp_path, 'work', 'workspace/rebuild/2008-06')
    assert rows == {'App/src/v8tree/InstanceChildLookup.cpp': 'blob'}
    assert source_catalog.logical_native_path('workspace/rebuild/2008-06/App/src/v8tree/InstanceChildLookup.cpp') == 'App/src/v8tree/InstanceChildLookup.cpp'
    assert source_catalog.logical_native_path('workspace/rebuild/2016-06/App/src/v8tree/Instance.cpp') is None
    assert source_catalog.map_group('App/src/v8tree/InstanceChildLookup.cpp') == 'App/v8tree'


def test_archived_source_versions_keep_immutable_origin(tmp_path):
    import subprocess
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=tmp_path, text=True).strip()
    git('init', '-q')
    path = tmp_path / 'archive/source-snapshots/old/2008-06/native-classes/Example.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('void Example::f() {}\n')
    git('add', '.')
    git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'snapshot')
    commit = git('rev-parse', 'HEAD')
    result = source_catalog.source_versions(tmp_path, commit)
    assert not result['errors']
    row = next(v for v in result['versions'] if v['path'] == 'native-classes/Example.cpp')
    assert row['origins'][0]['kind'] == 'archive'
    assert '/blob/' + commit + '/archive/source-snapshots/' in row['origins'][0]['url']


def test_alternative_navigation_preserves_immutable_and_local_origins():
    mapped = source_catalog.source_map(dict(work_commit='abc', authority='test', scope='test', files=[],
        alternatives=dict(sources=['fork', 'local'], errors=[], versions=[dict(path='native-classes/A.cpp',
            blob='123456789abcdef', origins=[dict(kind='fork', path='native-classes/A.cpp',
                url='https://github.com/example/repo/blob/abc/native-classes/A.cpp'),
                dict(kind='local', path='work/trial/2008-06/native-classes/A.cpp')])])))
    markdown = source_catalog.render_source_map_markdown(mapped)
    assert 'proof not assessed' in markdown
    assert 'https://github.com/example/repo/blob/abc/' in markdown
    assert '(local only)' in markdown


def test_same_named_external_worktrees_keep_distinct_local_origins(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'git', lambda *args: 'abc')
    monkeypatch.setattr(source_catalog.subprocess, 'check_output', lambda *args, **kwargs: b'')
    roots = [tmp_path / name / 'RoConstruct' for name in ('worker-a', 'worker-b')]
    for root in roots:
        path = root / 'rebuild/2008-06/native-classes/Instance.cpp'
        path.parent.mkdir(parents=True)
        path.write_bytes(b'void Instance::remove() {}')
    result = source_catalog.source_versions(tmp_path / 'owner', 'abc', source_roots=roots)
    origins = result['versions'][0]['origins']
    assert len(origins) == 2
    assert len({origin['root_id'] for origin in origins}) == 2


def test_project_pages_include_donor_only_paths(tmp_path):
    data = source_catalog.source_map(dict(work_commit='abc', authority='test', scope='test', files=[],
        alternatives=dict(sources=[], errors=[], versions=[dict(path='native-classes/AppUnit558_2008Instance.cpp',
            blob='123456789abcdef', origins=[dict(kind='fork', path='native-classes/AppUnit558_2008Instance.cpp',
                url='https://github.com/mewpokemons/RoConstruct/blob/abc/native-classes/AppUnit558_2008Instance.cpp')])])))
    source_catalog.write_browse(tmp_path / 'catalog', data)
    page = (tmp_path / 'catalog/App/v8tree/sources-001.md').read_text(encoding='utf-8')
    assert 'candidate-only' in page
    assert 'AppUnit558_2008Instance.cpp' in page
    assert 'mewpokemons' in page
    assert 'proof not assessed' in page


def test_local_branches_do_not_get_fabricated_public_links(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'git', lambda *args: 'abc')
    raw = b'100644 blob 123456789abcdef\trebuild/2008-06/native-classes/Private.cpp\0'
    monkeypatch.setattr(source_catalog.subprocess, 'check_output', lambda *args, **kwargs: raw)
    result = source_catalog.source_versions(tmp_path, 'abc', donor_refs=['refs/heads/private'])
    origin = next(o for o in result['versions'][0]['origins'] if o['kind'] == 'local-branch')
    assert 'url' not in origin
    assert origin['revision'] == 'abc'
    assert origin['ref'] == 'refs/heads/private'


def test_generated_banner_does_not_hide_changed_code_or_flags():
    source = b'// native-flags: /O2\nint f() { return 1; }\n'
    banner = b'// >>> native-status (generated) -- do not edit >>>\n// inactive\n// <<< native-status | hash\n'
    assert source_catalog.body_comparison(source, banner + source) == 'generated-banner-only'
    assert source_catalog.body_comparison(source, source.replace(b'\n', b'\r\n')) == 'line-endings-only'
    assert source_catalog.body_comparison(source, banner + source.replace(b'return 1', b'return 2')) == 'requires-method-review'
    assert source_catalog.body_comparison(source, banner + source.replace(b'/O2', b'/Od')) == 'requires-method-review'
    malformed = b'// >>> native-status (generated)\nint lost;\n// <<< native-status\n'
    assert source_catalog.body_comparison(source, malformed + source) == 'requires-method-review'


def test_all_project_scopes_keep_provenance_and_grouping():
    cases = {
        'App/include/v8tree/Instance.h': 'App/v8tree',
        'App/src/tool/AnchorTool.cpp': 'App/tool',
        'Unclassified/src/Unknown.cpp': 'Unclassified',
        'App/src/v8datamodel/Settings.cpp': 'App/v8datamodel',
        'Base/src/util/Name.cpp': 'Base/util',
        'Network/include/network/Peer.h': 'Network',
        'Rendering/src/Camera.cpp': 'Rendering',
        'WindowsClient/src/Frame.cpp': 'WindowsClient',
        'Studio/include/Editor.h': 'Studio',
        'App/src/unknown/Thing.cpp': 'Other',
    }
    for path, group in cases.items():
        assert source_catalog.logical_native_path('workspace/rebuild/2008-06/' + path) == path
        assert source_catalog.logical_native_path('2008-06/' + path) == path
        assert source_catalog.map_group(path) == group
        assert source_catalog.logical_native_path('workspace/rebuild/2012-06/' + path) is None


def test_all_organized_scopes_are_enumerated(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'tree_entries',
        lambda root, ref, prefix: {'File.cpp': prefix} if any(
            prefix.endswith('/' + scope) for scope in source_catalog.ORGANIZED_SCOPES) else {})
    entries = source_catalog.native_entries(tmp_path, 'work', 'workspace/rebuild/2008-06')
    assert set(entries) == {scope + '/File.cpp' for scope in source_catalog.ORGANIZED_SCOPES}


def test_compatibility_paths_show_old_donors_with_moved_source(tmp_path):
    import subprocess
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=tmp_path, text=True).strip()
    git('init', '-q')
    base = tmp_path / 'workspace/rebuild/2008-06'
    old, target = 'native-classes/Example.cpp', 'App/src/v8tree/Example.cpp'
    old_header, target_header = 'native-headers/v8tree/Example.h', 'App/include/v8tree/Example.h'
    for path, data in [(old, '// Compatibility translation unit; compile this file or the organized source, not both.\n#include "../App/src/v8tree/Example.cpp"\n'),
                       (target, 'void Example::run() {}\n'),
                       (old_header, '// Compatibility header; declarations live at the organized path.\n#include "../../App/include/v8tree/Example.h"\n'),
                       (target_header, '#pragma once\nclass Example;\n'),
                       ('native-classes/NotShim.cpp', '#include "../App/src/v8tree/Example.cpp"\n')]:
        p = base / path
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(data, encoding='utf-8')
    git('add', '.')
    git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'source')
    commit = git('rev-parse', 'HEAD')
    canonical = source_catalog.native_entries(tmp_path, commit, 'workspace/rebuild/2008-06')
    aliases = source_catalog.compatibility_aliases(tmp_path, canonical)
    assert aliases == {old: target, old_header: target_header}
    result = source_catalog.source_map(dict(work_commit=commit, authority='test', scope='test',
        files=source_catalog.classify_files(canonical, {}), compatibility_aliases=aliases,
        alternatives=dict(sources=[], errors=[], versions=[dict(path=old, blob='123456789abcdef',
            origins=[dict(kind='fork', path=old, url='https://github.com/example/repo/blob/abc/' + old)])])))
    source_catalog.write_browse(tmp_path / 'browse', result)
    text = ''.join(p.read_text(encoding='utf-8') for p in (tmp_path / 'browse/App/v8tree').glob('*.md'))
    assert 'Earlier paths and their donor versions' in text
    assert 'https://github.com/example/repo/blob/abc/' in text
    other = ''.join(p.read_text(encoding='utf-8') for p in (tmp_path / 'browse/Other').glob('*.md'))
    assert 'compile either path, never both' in other


def test_prior_source_versions_and_origins_survive_refresh():
    import pytest
    current = dict(versions=[dict(path='native-classes/A.cpp', blob='one', origins=[{'ref': 'new'}])],
                   sources=[{'source': 'new'}], errors=[], excluded_directory_names=['tools'])
    previous = dict(versions=[dict(path='native-classes/A.cpp', blob='one', origins=[{'ref': 'old'}], sha256='abc'),
                              dict(path='native-classes/B.cpp', blob='two', origins=[{'ref': 'old'}])],
                    sources=[{'source': 'old'}], excluded_directory_names=['cache'])
    result = source_catalog.preserve_prior_versions(current, previous)
    assert [(row['path'], row['blob']) for row in result['versions']] == [
        ('native-classes/A.cpp', 'one'), ('native-classes/B.cpp', 'two')]
    assert result['versions'][0]['origins'] == [{'ref': 'new'}, {'ref': 'old'}]
    assert result['versions'][0]['sha256'] == 'abc'
    assert result['sources'] == [{'source': 'new'}, {'source': 'old'}]
    assert result['excluded_directory_names'] == ['cache', 'tools']
    previous['versions'][0]['sha256'] = 'conflict'
    with pytest.raises(ValueError, match='Conflicting source digest'):
        source_catalog.preserve_prior_versions(result, previous)
    with pytest.raises(ValueError, match='lacks version inventory'):
        source_catalog.preserve_prior_versions(result, {})


def test_previous_source_map_reads_only_pinned_git_commit(tmp_path):
    import json
    import subprocess
    import pytest
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=tmp_path, text=True).strip()
    git('init', '-q')
    path = tmp_path / '2008-06/source-map.json'
    path.parent.mkdir(parents=True)
    path.write_text(json.dumps({'schema': 1, 'alternatives': {'versions': []}}))
    git('add', '.')
    git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'valid')
    commit = git('rev-parse', 'HEAD')
    path.write_text('corrupt uncommitted file')
    assert source_catalog.prior_source_map(tmp_path, commit) == {'versions': []}
    git('add', '.')
    git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'bad')
    with pytest.raises(ValueError):
        source_catalog.prior_source_map(tmp_path, git('rev-parse', 'HEAD'))


def test_preserve_many_repeated_origins_keeps_order_and_uniqueness():
    from roc import source_catalog
    existing = [{"ref": str(i), "kind": "local"} for i in range(300)]
    prior = [{"kind": "local", "ref": str(i)} for i in range(150, 450)]
    current = {"versions": [{"path": "native-classes/A.cpp", "blob": "a", "origins": existing.copy()}], "sources": [], "excluded_directory_names": []}
    previous = {"versions": [{"path": "native-classes/A.cpp", "blob": "a", "origins": prior}], "sources": [], "excluded_directory_names": []}
    result = source_catalog.preserve_prior_versions(current, previous)
    assert [item["ref"] for item in result["versions"][0]["origins"]] == [str(i) for i in range(450)]


def test_header_alias_is_compared_to_target_content(tmp_path):
    import subprocess
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    def blob(data):
        return subprocess.check_output(['git', 'hash-object', '-w', '--stdin'], cwd=tmp_path, input=data).decode().strip()
    target = blob(b'#pragma once\nstruct Log {};\n')
    public = blob(b'#pragma once\n// >>> native-status (generated) -- do not edit >>>\n// Log\n// <<< native-status\nstruct Log {};\n')
    different = blob(b'#pragma once\nstruct Other {};\n')
    shim = blob(b'// Compatibility header; declarations live at the organized path.\n#include "../../../Base/include/util/Log.h"\n')
    rows = [dict(path='native-headers/log/Log.h', state='diverged', canonical_blob=shim, public_blob=public),
            dict(path='native-headers/other/Log.h', state='diverged', canonical_blob=shim, public_blob=different),
            dict(path='native-classes/Log.cpp', state='diverged', canonical_blob=shim, public_blob=public)]
    aliases = {row['path']: 'Base/include/util/Log.h' for row in rows}
    counts = source_catalog.compare_blobs(tmp_path, rows, aliases, {'Base/include/util/Log.h': target})
    assert [row['comparison'] for row in rows] == ['alias-target-content', 'requires-method-review', 'requires-method-review']
    assert counts == {'alias-target-content': 1, 'requires-method-review': 2}


def test_experimental_overlay_is_indexed_and_stays_labeled(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'tree_entries', lambda root, ref, prefix:
                        {'test/Example.h': 'blob'} if prefix.endswith('/experiments/overlays') else {})
    rows = source_catalog.native_entries(tmp_path, 'work', 'workspace/rebuild/2008-06')
    assert rows == {'experiments/overlays/test/Example.h': 'blob'}
    assert source_catalog.logical_native_path('workspace/rebuild/2008-06/experiments/overlays/test/Example.h') == 'experiments/overlays/test/Example.h'
    assert source_catalog.logical_native_path('workspace/rebuild/2016-06/experiments/overlays/test/Example.h') is None
    assert source_catalog.map_group('experiments/overlays/test/Example.h') == 'Experiments/overlays'


def test_experimental_overlay_alias_targets_real_file(tmp_path):
    import subprocess
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    def blob(data):
        return subprocess.check_output(['git', 'hash-object', '-w', '--stdin'], cwd=tmp_path, input=data).decode().strip()
    old = 'Unclassified/include/test/Example.h'
    new = 'experiments/overlays/test/Example.h'
    shim = blob(b'// Compatibility header; experiment lives in the organized path.\n#include "../../../experiments/overlays/test/Example.h"\n')
    assert source_catalog.compatibility_aliases(tmp_path, {old: shim, new: blob(b'// original\n')}) == {old: new}


def test_unclassified_source_alias_tracks_organized_code(tmp_path):
    import subprocess
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    def blob(data):
        return subprocess.check_output(['git', 'hash-object', '-w', '--stdin'], cwd=tmp_path, input=data).decode().strip()
    old = 'Unclassified/src/Widget.cpp'
    new = 'App/src/gui/Widget.cpp'
    shim = blob(b'// Compatibility translation unit; compile this file or the organized source, not both.\n#include "../../App/src/gui/Widget.cpp"\n')
    assert source_catalog.compatibility_aliases(tmp_path, {old: shim, new: blob(b'// original\n')}) == {old: new}


def test_generated_map_json_is_compact_and_complete(tmp_path, monkeypatch):
    import json, sys
    from roc.native_drafts import Inbox
    rows = [{'path': 'App/src/A.cpp', 'state': 'equivalent', 'canonical_blob': 'a', 'public_blob': 'a'}]
    catalog = dict(work_commit='abc', authority='test', scope='test', files=rows, summary={})
    monkeypatch.setattr(source_catalog, 'catalog', lambda *args: catalog)
    monkeypatch.setattr(source_catalog, 'git', lambda *args: '')
    monkeypatch.setattr(source_catalog, 'source_versions', lambda *args: dict(versions=[], sources=[], errors=[]))
    monkeypatch.setattr(source_catalog, 'prior_source_map', lambda *args: None)
    monkeypatch.setattr(Inbox, 'archive', lambda self: [])
    monkeypatch.setattr(source_catalog, 'write_browse', lambda *args: None)
    output, mapped = tmp_path / 'catalog.json', tmp_path / 'map.json'
    monkeypatch.setattr(sys, 'argv', ['source_catalog', '--output', str(output), '--map-output', str(mapped)])
    source_catalog.main()
    text = mapped.read_text(encoding='utf-8')
    data = json.loads(text)
    assert '\n  ' not in text
    assert any(row['path'] == 'App/src/A.cpp' for group in data['groups'] for row in group['files'])


def test_experiment_trial_appears_in_catalog_and_map(tmp_path, monkeypatch):
    monkeypatch.setattr(source_catalog, 'tree_entries', lambda root, ref, prefix:
                        {'Probe.cpp': 'trial-blob'} if prefix.endswith('/experiments/trials') else {})
    rows = source_catalog.native_entries(tmp_path, 'work', 'workspace/rebuild/2008-06')
    assert rows['experiments/trials/Probe.cpp'] == 'trial-blob'
    assert source_catalog.logical_native_path('workspace/rebuild/2008-06/experiments/trials/Probe.cpp') == 'experiments/trials/Probe.cpp'
    assert source_catalog.map_group('experiments/trials/Probe.cpp') == 'Experiments/trials'


def test_unclassified_probe_alias_tracks_trial_source(tmp_path):
    import subprocess
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    def blob(data):
        return subprocess.check_output(['git', 'hash-object', '-w', '--stdin'], cwd=tmp_path, input=data).decode().strip()
    old, new = 'Unclassified/src/Probe.cpp', 'experiments/trials/Probe.cpp'
    shim = blob(b'// Compatibility translation unit; compile this file or the organized source, not both.\n#include "../../experiments/trials/Probe.cpp"\n')
    assert source_catalog.compatibility_aliases(tmp_path, {old: shim, new: blob(b'// original\n')}) == {old: new}


def test_source_map_shards_preserve_origins_and_reject_corruption(tmp_path):
    import json, subprocess
    subprocess.run(['git', 'init', '-q'], cwd=tmp_path, check=True)
    source = tmp_path / '2008-06'
    source.mkdir()
    versions = [dict(path='App/src/%d.cpp' % i, blob=str(i),
                     origins=[dict(kind='local', path='work/trial/%d.cpp' % i)]) for i in range(5)]
    shards = source_catalog.write_version_shards(source / 'source-map-versions', versions, max_bytes=160)
    assert len(shards) > 1
    alternatives = dict(version_shards=shards, version_count=len(versions), sources=[], errors=[])
    (source / 'source-map.json').write_text(json.dumps(dict(schema=1, alternatives=alternatives)), encoding='utf-8')
    subprocess.run(['git', 'add', '.'], cwd=tmp_path, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'map'], cwd=tmp_path, check=True)
    assert source_catalog.prior_source_map(tmp_path, 'HEAD')['versions'] == versions
    (source / shards[0]['path']).write_text('[]', encoding='utf-8')
    subprocess.run(['git', 'add', '.'], cwd=tmp_path, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'corrupt'], cwd=tmp_path, check=True)
    import pytest
    with pytest.raises(ValueError, match='hash mismatch'):
        source_catalog.prior_source_map(tmp_path, 'HEAD')


def test_publication_requires_every_unchanged_shard(tmp_path):
    import json
    import pytest
    folder = tmp_path / 'map'
    folder.mkdir()
    (folder / 'catalog').mkdir()
    (folder / 'catalog' / 'README.md').write_text('catalog', encoding='utf-8')
    (folder / 'source-map.md').write_text('map', encoding='utf-8')
    versions = [dict(path='App/src/A.cpp', blob='a', origins=[dict(kind='local', path='work/a')])]
    shards = source_catalog.write_version_shards(folder / 'source-map-versions', versions, max_bytes=200)
    index = dict(schema=1, generated_from=dict(work_commit='a' * 40), groups=[],
                 alternatives=dict(version_shards=shards, version_count=1, sources=[], errors=[]))
    (folder / 'source-map.json').write_text(json.dumps(index), encoding='utf-8')
    base, files = source_catalog.source_map_publication_files(folder)
    assert base == 'a' * 40
    assert '2008-06/source-map-versions/0000.json' in files
    assert json.loads(files['2008-06/source-map-versions/0000.json']) == versions
    (folder / shards[0]['path']).write_text('[]', encoding='utf-8')
    with pytest.raises(ValueError, match='failed verification'):
        source_catalog.source_map_publication_files(folder)
    (folder / shards[0]['path']).unlink()
    with pytest.raises(ValueError, match='Missing or unsafe'):
        source_catalog.source_map_publication_files(folder)


def test_publish_cli_does_not_generate_catalog(tmp_path, monkeypatch, capsys):
    import json, sys
    seen = []
    monkeypatch.setattr(source_catalog, 'publish_source_map', lambda root, folder: seen.append(folder) or dict(commit='abc', changed=True))
    monkeypatch.setattr(sys, 'argv', ['source_catalog', '--publish', str(tmp_path)])
    source_catalog.main()
    assert seen == [tmp_path]
    assert json.loads(capsys.readouterr().out) == dict(commit='abc', changed=True)


def test_publication_rejects_missing_previously_published_origins():
    import pytest
    old = dict(versions=[dict(path='A.cpp', blob='abc', sha256='digest',
                              origins=[dict(kind='fork', ref='old')])],
               sources=[dict(kind='fork', ref='old')], excluded_directory_names=['build'])
    new = dict(sources=[dict(kind='fork', ref='old')], excluded_directory_names=['build'])
    current = [dict(path='A.cpp', blob='abc', sha256='digest', origins=[])]
    with pytest.raises(ValueError, match='origin is missing'):
        source_catalog.require_prior_source_versions(old, new, current)
    current[0]['origins'].append(dict(kind='fork', ref='old'))
    source_catalog.require_prior_source_versions(old, new, current)
