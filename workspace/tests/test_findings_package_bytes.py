import hashlib
import json
import shutil
import subprocess

from roc.findings_transport import publish_package


def test_publication_repairs_filtered_blob_with_unchanged_manifest(tmp_path):
    git = shutil.which('git')
    remote = tmp_path / 'remote.git'
    root = tmp_path / 'checkout'
    root.mkdir()

    def run(*args):
        return subprocess.check_output([git, *args], cwd=root)

    run('init', '--bare', str(remote))
    run('init', '-b', 'main')
    run('config', 'user.name', 'Package test')
    run('config', 'user.email', 'package@example.invalid')
    run('config', 'core.autocrlf', 'false')
    run('remote', 'add', 'findings', str(remote))
    original = b'<roblox/>\r\n'
    manifest = {'files': {'tests/falling.rbxl': hashlib.sha256(original).hexdigest()}}
    tracked = root / '2008-06'
    (tracked / 'tests').mkdir(parents=True)
    (tracked / 'tests/falling.rbxl').write_bytes(original.replace(b'\r\n', b'\n'))
    (tracked / 'package.json').write_text(json.dumps(manifest))
    run('add', '2008-06')
    run('commit', '-m', 'Prior export with filtered fixture')
    run('push', 'findings', 'main')
    package = root / 'local/findings/2008-06'
    (package / 'tests').mkdir(parents=True)
    (package / 'tests/falling.rbxl').write_bytes(original)
    (package / 'package.json').write_text(json.dumps(manifest))
    run('config', 'core.autocrlf', 'true')
    publish_package(root, git, log=lambda message: None)
    run('fetch', 'findings', 'main')
    assert run('show', 'FETCH_HEAD:2008-06/tests/falling.rbxl') == original
