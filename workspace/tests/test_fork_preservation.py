import subprocess

from roc.fork_merge import preservation_losses, run, BRANCH


def git(repo, *args):
    return subprocess.check_output(['git', '-C', str(repo), *args]).decode().strip()


def test_snapshot_cannot_remove_sources_or_their_proofs(tmp_path):
    git(tmp_path, 'init', '-q')
    git(tmp_path, 'config', 'user.name', 'test')
    git(tmp_path, 'config', 'user.email', 'test@example.invalid')
    paths = ['native-classes/Team.cpp', 'native-headers/Team.h',
             'tests/record_native_team.py', 'native-world/Team.json']
    for rel in paths:
        path = tmp_path / 'rebuild/2008-06' / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('verified body\n')
    git(tmp_path, 'add', '.')
    git(tmp_path, 'commit', '-qm', 'verified')
    base = git(tmp_path, 'rev-parse', 'HEAD')
    (tmp_path / 'rebuild/2008-06/native-classes/Team.cpp').unlink()
    (tmp_path / 'rebuild/2008-06/tests/record_native_team.py').unlink()
    (tmp_path / 'rebuild/2008-06/native-headers/Team.h').write_text('')
    git(tmp_path, 'add', '-A')
    tree = git(tmp_path, 'write-tree')
    before_index = (tmp_path / '.git/index').read_bytes()
    losses = preservation_losses(tmp_path, base, tree)
    assert {row['path'] for row in losses} == {
        'rebuild/2008-06/native-classes/Team.cpp',
        'rebuild/2008-06/native-headers/Team.h',
        'rebuild/2008-06/tests/record_native_team.py'}
    assert (tmp_path / '.git/index').read_bytes() == before_index
    assert preservation_losses(tmp_path, base, base) == []


def test_rename_is_a_reviewed_provider_move_not_an_implicit_allowance(tmp_path):
    git(tmp_path, 'init', '-q')
    git(tmp_path, 'config', 'user.name', 'test')
    git(tmp_path, 'config', 'user.email', 'test@example.invalid')
    path = tmp_path / 'rebuild/2008-06/native-classes/Keep.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('verified body\n')
    git(tmp_path, 'add', '.')
    git(tmp_path, 'commit', '-qm', 'base')
    base = git(tmp_path, 'rev-parse', 'HEAD')
    path.rename(path.with_name('Moved.cpp'))
    git(tmp_path, 'add', '-A')
    assert preservation_losses(tmp_path, base, git(tmp_path, 'write-tree'))[0]['path'].endswith('Keep.cpp')


def test_additions_and_unrelated_deletions_are_allowed(tmp_path):
    git(tmp_path, 'init', '-q')
    git(tmp_path, 'config', 'user.name', 'test')
    git(tmp_path, 'config', 'user.email', 'test@example.invalid')
    (tmp_path / 'note.txt').write_text('old\n')
    git(tmp_path, 'add', '.')
    git(tmp_path, 'commit', '-qm', 'base')
    base = git(tmp_path, 'rev-parse', 'HEAD')
    (tmp_path / 'note.txt').unlink()
    path = tmp_path / 'rebuild/2008-06/native-classes/New.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('new body\n')
    git(tmp_path, 'add', '-A')
    assert preservation_losses(tmp_path, base, git(tmp_path, 'write-tree')) == []


def test_source_cannot_become_a_symlink_without_windows_symlink_privilege(tmp_path):
    git(tmp_path, 'init', '-q')
    git(tmp_path, 'config', 'user.name', 'test')
    git(tmp_path, 'config', 'user.email', 'test@example.invalid')
    path = tmp_path / 'rebuild/2008-06/native-classes/Keep.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('verified body\n')
    git(tmp_path, 'add', '.')
    git(tmp_path, 'commit', '-qm', 'base')
    base = git(tmp_path, 'rev-parse', 'HEAD')
    blob = git(tmp_path, 'hash-object', '-w', str(path))
    git(tmp_path, 'update-index', '--cacheinfo', '120000,' + blob + ',rebuild/2008-06/native-classes/Keep.cpp')
    losses = preservation_losses(tmp_path, base, git(tmp_path, 'write-tree'))
    assert len(losses) == 1 and losses[0]['status'] == 'T'


def test_tracking_snapshot_cannot_delete_previous_bot_sources_or_proofs(tmp_path):
    repo = tmp_path / 'repo'
    repo.mkdir()
    git(repo, 'init', '-q', '-b', 'work')
    git(repo, 'config', 'user.name', 'test')
    git(repo, 'config', 'user.email', 'test@example.invalid')
    paths = ['rebuild/2008-06/native-classes/Team.cpp',
             'rebuild/2008-06/tests/record_native_team.py']
    for rel in paths:
        path = repo / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('verified body\n')
    git(repo, 'add', '.')
    git(repo, 'commit', '-qm', 'verified')
    base = git(repo, 'rev-parse', 'HEAD')
    git(repo, 'update-ref', 'refs/forks/origin/' + BRANCH, base)
    for rel in paths:
        (repo / rel).unlink()
    (repo / 'README.md').write_text('unverified snapshot\n')
    git(repo, 'add', '-A')
    git(repo, 'commit', '-qm', 'snapshot')
    bad = git(repo, 'rev-parse', 'HEAD')
    git(repo, 'update-ref', 'refs/forks/origin/work', bad)
    logs = []
    clone = tmp_path / 'clone'
    run(push=False, log=logs.append, repo=repo, clone=clone, mine='work',
        days=36500, state_file=tmp_path / 'state.json')
    assert all((clone / rel).is_file() for rel in paths)
    assert git(repo, 'rev-parse', 'HEAD') == bad
    assert any('refused tracking snapshot' in line for line in logs)


def test_organized_and_public_subtrees_reject_losses(tmp_path):
    git(tmp_path, 'init', '-q')
    git(tmp_path, 'config', 'user.name', 'test')
    git(tmp_path, 'config', 'user.email', 'test@example.invalid')
    rels = ['rebuild/2008-06/App/src/tool/Foo.cpp',
            'rebuild/2008-06/Network/include/net/Foo.h',
            '2008-06/App/src/tool/Foo.cpp',
            '2008-06/native-headers/tool/Foo.h']
    for rel in rels:
        path = tmp_path / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('recovered source\n')
    (tmp_path / '2008-06/README.md').write_text('keep subtree\n')
    git(tmp_path, 'add', '.')
    git(tmp_path, 'commit', '-qm', 'base')
    base = git(tmp_path, 'rev-parse', 'HEAD')
    for rel in rels:
        (tmp_path / rel).unlink()
    git(tmp_path, 'add', '-A')
    tree = git(tmp_path, 'write-tree')
    assert {row['path'] for row in preservation_losses(tmp_path, base, tree)} == set(rels)
    public_base = git(tmp_path, 'rev-parse', base + ':2008-06')
    public_tree = git(tmp_path, 'rev-parse', tree + ':2008-06')
    assert {row['path'] for row in preservation_losses(tmp_path, public_base, public_tree)} == {
        'App/src/tool/Foo.cpp', 'native-headers/tool/Foo.h'}
