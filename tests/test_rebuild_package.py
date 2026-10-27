import hashlib
import json
from pathlib import Path

import pytest

from roc import rebuild_package


def test_curated_package_preserves_native_source_and_required_build_inputs(tmp_path, monkeypatch):
    root = tmp_path / 'roc'
    source = root / 'rebuild/2008-06'
    for relative, data in {
        'modules/a.json': b'{}', 'glue/test.cpp': b'int glue;',
        'tests/test.cpp': b'int main() {}', 'out/engine/linked/linked.lib': b'0123456789abcdef',
        'manifests/functions.json': b'[]', 'check.py': b'print(1)',
        'out/log.txt': b'build complete', 'patches/rbxgs-client.json':
            json.dumps({'App/test.cpp': [['old', 'new']], 'App/added.h': [['', 'added']]}).encode(),
        'out/native-integration-token': b'PRIVATE',
    }.items():
        path = source / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
    native = root / 'tools/rbxgs/Client/App/test.cpp'
    native.parent.mkdir(parents=True)
    native.write_text('old')
    destination = root / 'local/findings/2008-06'
    manifest = rebuild_package.export(root, destination)
    assert (destination / 'config/a.json').read_text() == '{}'
    assert (destination / 'src/glue/test.cpp').is_file()
    assert (destination / 'verification/manifests/functions.json').is_file()
    assert (destination / 'src/rbxgs/Client/App/test.cpp').read_text() == 'new'
    assert (destination / 'src/rbxgs/Client/App/added.h').read_text() == 'added'
    assert native.read_text() == 'old'
    assert not (destination / 'work/build/native-integration-token').exists()
    assert not (destination / 'work/build/engine/linked/linked.lib').exists()
    assert not any(name.startswith('work/') or name.endswith(('.obj', '.lib', '.log')) for name in manifest['files'])
    for relative, digest in manifest['files'].items():
        assert hashlib.sha256((destination / relative).read_bytes()).hexdigest() == digest
    # Re-export never deletes a user's later test output.
    output = destination / 'work/build/after-export.txt'
    output.parent.mkdir(parents=True)
    output.write_text('keep')
    rebuild_package.export(root, destination)
    assert output.read_text() == 'keep'


def test_restore_rejects_corrupt_chunks_without_overwriting_existing_file(tmp_path):
    from roc.rebuild_package_launcher import restore
    (tmp_path / 'work').mkdir()
    (tmp_path / 'chunk').write_bytes(b'bad')
    (tmp_path / 'kept.lib').write_bytes(b'existing')
    (tmp_path / 'work/large-files.json').write_text(json.dumps({'kept.lib': {
        'bytes': 3, 'sha256': hashlib.sha256(b'good').hexdigest(), 'parts': ['chunk']}}))
    with pytest.raises(ValueError, match='checksum mismatch'):
        restore(tmp_path)
    assert (tmp_path / 'kept.lib').read_bytes() == b'existing'
    assert not list(tmp_path.glob('*.restoring-*'))


def test_locked_build_artifact_is_explicitly_pending(tmp_path, monkeypatch):
    source = tmp_path / 'rebuild/2008-06/out/locked.obj'
    source.parent.mkdir(parents=True)
    source.write_bytes(b'building')
    read = Path.read_bytes
    def locked(path):
        if path == source:
            raise PermissionError('compiler writing')
        return read(path)
    monkeypatch.setattr(Path, 'read_bytes', locked)
    destination = tmp_path / 'local/findings/2008-06'
    result = rebuild_package.export(tmp_path, destination)
    assert result['pending_build_files'] == []
    assert 'work/build/locked.obj' not in result['files']


def test_install_restores_existing_roc_paths_without_downloading_artifacts(tmp_path):
    from roc.rebuild_install import install
    package = tmp_path / 'findings/2008-06'
    for relative, text in {'config/rbxgs-app.json': '{}', 'src/glue/a.cpp': 'glue',
                           'scripts/base_check.py': 'check', 'verification/manifests/functions.json': '[]',
                           'work/build/huge.lib': 'do not copy'}.items():
        path = package / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
    target = install(tmp_path / 'roc', package=package)
    assert (target / 'modules/rbxgs-app.json').read_text() == '{}'
    assert (target / 'glue/a.cpp').read_text() == 'glue'
    assert (target / 'base_check.py').read_text() == 'check'
    assert (target / 'manifests/functions.json').read_text() == '[]'
    assert not (target / 'out/huge.lib').exists()


def test_install_preserves_unrelated_existing_edits(tmp_path):
    from roc.rebuild_install import install
    package = tmp_path / 'findings/2008-06'
    (package / 'config').mkdir(parents=True)
    (package / 'config/rbxgs-app.json').write_text('{}')
    (package / 'scripts').mkdir()
    (package / 'scripts/base_check.py').write_text('published')
    target = tmp_path / 'roc/rebuild/2008-06'
    target.mkdir(parents=True)
    (target / 'base_check.py').write_text('private changes')
    with pytest.raises(ValueError, match='Preserving existing'):
        install(tmp_path / 'roc', package=package)
    assert (target / 'base_check.py').read_text() == 'private changes'
    assert not (target / 'modules/rbxgs-app.json').exists()


def test_rebuild_progress_never_sends_webhooks(tmp_path, monkeypatch):
    import urllib.request
    from roc import rebuild
    from unittest.mock import Mock
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild, 'DOCS', tmp_path / 'docs')
    (tmp_path / 'docs').mkdir()
    send = Mock(side_effect=AssertionError('rebuild progress must stay local'))
    monkeypatch.setattr(urllib.request, 'urlopen', send)
    result = rebuild.progress(notify=True, log=lambda text: None)
    assert result['phase'] == '0'
    send.assert_not_called()


def test_adopted_units_survive_but_unreferenced_probe_units_are_excluded(tmp_path):
    tree = tmp_path / 'tools/rbxgs/Client/App'
    (tree / 'include').mkdir(parents=True)
    (tree / 'include/Thing.h').write_text('old header')
    (tree / 'roc_adopted.cpp').write_text('class Thing {};')
    (tree / 'roc_unused.cpp').write_text('unused probe')
    patches = tmp_path / 'rebuild/2008-06/patches'
    patches.mkdir(parents=True)
    (patches / 'rbxgs-client.json').write_text(json.dumps({'App/include/Thing.h': [['@replace', 'App/roc_adopted.cpp']]}))
    destination = tmp_path / 'local/findings/2008-06'
    result = rebuild_package.export(tmp_path, destination)
    assert (destination / 'src/rbxgs/Client/App/include/Thing.h').read_text() == 'class Thing {};'
    assert 'src/rbxgs/Client/App/roc_adopted.cpp' in result['files']
    assert 'src/rbxgs/Client/App/roc_unused.cpp' not in result['files']


def test_overlay_paths_apply_regardless_of_filename_case(tmp_path):
    path = tmp_path / 'tools/rbxgs/Client/App/include/util/object.h'
    path.parent.mkdir(parents=True)
    path.write_text('old')
    patch = tmp_path / 'rebuild/2008-06/patches/rbxgs-client.json'
    patch.parent.mkdir(parents=True)
    patch.write_text(json.dumps({'App/include/util/Object.h': [['old', 'new']]}))
    destination = tmp_path / 'local/findings/2008-06'
    rebuild_package.export(tmp_path, destination)
    assert (destination / 'src/rbxgs/Client/App/include/util/object.h').read_text() == 'new'
