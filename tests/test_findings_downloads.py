import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import zipfile

import pytest

from roc.findings_transport import publish_downloads, publish_package


@pytest.mark.skipif(not shutil.which('git'), reason='Git required for isolated local transport test')
def test_download_publication_preserves_remote_sources_and_local_edits(tmp_path):
    def git(folder, *args):
        return subprocess.check_output(['git', *args], cwd=folder, text=True).strip()
    seed = tmp_path / 'seed'
    seed.mkdir()
    git(seed, 'init', '-b', 'main')
    git(seed, 'config', 'user.email', 'test@example.invalid')
    git(seed, 'config', 'user.name', 'Test')
    (seed / 'keep.cpp').write_text('existing remote source')
    old_native = seed / '2008-06/src/rbxgs/Client/App/Widget.cpp'
    old_native.parent.mkdir(parents=True)
    old_native.write_text('native source')
    native_hash = hashlib.sha256(old_native.read_bytes()).hexdigest()
    (seed / '2008-06/package.json').write_text(json.dumps({'files': {'src/rbxgs/Client/App/Widget.cpp': native_hash}}))
    git(seed, 'add', '.')
    git(seed, 'commit', '-m', 'seed')
    remote = tmp_path / 'remote.git'
    git(tmp_path, 'clone', '--bare', str(seed), str(remote))
    root = tmp_path / 'contributor'
    git(tmp_path, 'clone', str(remote), str(root))
    git(root, 'remote', 'rename', 'origin', 'findings')
    git(root, 'config', 'user.email', 'test@example.invalid')
    git(root, 'config', 'user.name', 'Test')
    (root / 'keep.cpp').write_text('unsent local edits')
    (root / 'staged.txt').write_text('unsent staged work')
    git(root, 'add', 'staged.txt')
    before = git(root, 'status', '--porcelain')
    folder = root / 'local/findings/data'
    folder.mkdir(parents=True)
    (root / '.git/info/exclude').write_text('local/\nwork/\n')
    with zipfile.ZipFile(folder / 'native-worker.zip', 'w') as zipped:
        zipped.writestr('roc/native_try.py', '# fixture')
    digest = hashlib.sha256((folder / 'native-worker.zip').read_bytes()).hexdigest()
    (folder / 'native-worker.json').write_text(json.dumps({'sha256': digest}))
    (folder / 'NATIVE_AGENT.md').write_text('Which client do you want to run?')
    (folder / 'MATCHING_AGENT.md').write_text('Matching agent workflow')
    logs = []
    publish_downloads(root, shutil.which('git'), logs.append)
    assert 'published' in logs[-1]
    assert git(remote, 'show', 'main:keep.cpp') == 'existing remote source'
    assert git(remote, 'show', 'main:data/NATIVE_AGENT.md') == 'Which client do you want to run?'
    assert git(remote, 'show', 'main:data/MATCHING_AGENT.md') == 'Matching agent workflow'
    assert (root / 'keep.cpp').read_text() == 'unsent local edits'
    assert git(root, 'status', '--porcelain') == before
    version = git(remote, 'rev-parse', 'main')
    publish_downloads(root, shutil.which('git'), logs.append)
    assert git(remote, 'rev-parse', 'main') == version
    assert 'already current' in logs[-1]
    package = root / 'local/findings/2008-06'
    native = package / 'src/Client/App/Widget.cpp'
    native.parent.mkdir(parents=True)
    native.write_text('native source')
    (package / 'package.json').write_text(json.dumps({'files': {'src/Client/App/Widget.cpp': native_hash}}))
    publish_package(root, shutil.which('git'), logs.append)
    assert git(remote, 'show', 'main:2008-06/src/Client/App/Widget.cpp') == 'native source'
    assert not git(remote, 'ls-tree', '-r', 'main', '--', '2008-06/src/rbxgs')
    assert git(root, 'status', '--porcelain') == before
    version = git(remote, 'rev-parse', 'main')
    publish_package(root, shutil.which('git'), logs.append)
    assert git(remote, 'rev-parse', 'main') == version
    assert 'already current' in logs[-1]


def test_download_publication_refuses_bad_hash_before_transport(tmp_path):
    folder = tmp_path / 'local/findings/data'
    folder.mkdir(parents=True)
    (folder / 'native-worker.zip').write_bytes(b'archive')
    (folder / 'native-worker.json').write_text(json.dumps({'sha256': 'wrong'}))
    with pytest.raises(ValueError, match='hash mismatch'):
        publish_downloads(tmp_path, None)
