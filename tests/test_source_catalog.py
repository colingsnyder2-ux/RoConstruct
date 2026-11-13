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
    page = (tmp_path / 'catalog/App/v8tree/sources-001.md').read_text()
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
