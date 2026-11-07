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
    assert rows[0]['group'] == 'Studio/App'
    assert rows[1]['group'] == 'Other'
