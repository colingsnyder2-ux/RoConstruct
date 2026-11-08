from pathlib import Path
import shutil
import subprocess
import pytest
from roc import rebuild_install


def test_new_cache_checks_out_work(tmp_path, monkeypatch):
    calls = []
    cache = tmp_path / 'local/rebuild-inputs'
    def run(args, **kwargs):
        calls.append(args)
        if 'checkout' in args:
            assert args[-1] == 'work'
            config = cache / '2008-06/config/rbxgs-app.json'
            config.parent.mkdir(parents=True)
            config.write_text('{}')
    monkeypatch.setattr(rebuild_install.subprocess, 'run', run)
    monkeypatch.setattr(rebuild_install, 'ensure_abi', lambda *args: None)
    result = rebuild_install.install(tmp_path)
    assert (result / 'modules/rbxgs-app.json').is_file()
    assert any('clone' in args and '--branch' in args and 'work' in args for args in calls)
    assert not any('main' in args for args in calls)


def test_existing_cache_is_reused_without_git_changes(tmp_path, monkeypatch):
    config = tmp_path / 'local/rebuild-inputs/2008-06/config/rbxgs-app.json'
    config.parent.mkdir(parents=True)
    config.write_text('{}')
    monkeypatch.setattr(rebuild_install.subprocess, 'run', lambda *args, **kwargs: pytest.fail('cache must not change'))
    monkeypatch.setattr(rebuild_install, 'ensure_abi', lambda *args: None)
    assert (rebuild_install.install(tmp_path) / 'modules/rbxgs-app.json').is_file()


def test_incomplete_existing_cache_is_preserved(tmp_path, monkeypatch):
    cache = tmp_path / 'local/rebuild-inputs'
    (cache / '.git').mkdir(parents=True)
    (cache / 'uncommitted.txt').write_text('keep')
    monkeypatch.setattr(rebuild_install.subprocess, 'run', lambda *args, **kwargs: pytest.fail('cache must not change'))
    with pytest.raises(ValueError, match='preserved'):
        rebuild_install.install(tmp_path)
    assert (cache / 'uncommitted.txt').read_text() == 'keep'


@pytest.mark.skipif(not shutil.which('git'), reason='Git required')
def test_new_cache_materializes_work_branch(tmp_path, monkeypatch):
    source = tmp_path / 'source'
    source.mkdir()
    subprocess.run(['git', 'init', '-q', '-b', 'work'], cwd=source, check=True)
    config = source / '2008-06/config/rbxgs-app.json'
    config.parent.mkdir(parents=True)
    config.write_text('{"from":"work"}')
    subprocess.run(['git', 'add', '.'], cwd=source, check=True)
    subprocess.run(['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                    'commit', '-qm', 'work inputs'], cwd=source, check=True)
    real_run = subprocess.run
    def local_clone(args, **kwargs):
        if args[:2] == ['git', 'clone']:
            args = [source.as_uri() if arg == 'https://github.com/colingsnyder2-ux/RoConstruct.git' else arg for arg in args]
        return real_run(args, **kwargs)
    monkeypatch.setattr(rebuild_install.subprocess, 'run', local_clone)
    monkeypatch.setattr(rebuild_install, 'ensure_abi', lambda *args: None)
    target = tmp_path / 'client'
    installed = rebuild_install.install(target)
    assert (installed / 'modules/rbxgs-app.json').read_text() == '{"from":"work"}'
    cache = target / 'local/rebuild-inputs'
    assert subprocess.check_output(['git', '-C', str(cache), 'branch', '--show-current'], text=True).strip() == 'work'
