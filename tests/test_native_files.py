"""Fork merge + new-file digest, against throwaway git repos (no network, no webhook)."""
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import fork_merge, native_files_notify as nf  # noqa: E402

N = 'rebuild/2008-06/native-classes/'


def git(cwd, *a, input=None):
    r = subprocess.run(['git', *a], cwd=cwd, capture_output=True, text=True, input=input)
    assert r.returncode == 0, (a, r.stderr)
    return r.stdout.strip()


def commit(cwd, files, msg, deletes=()):
    for name, text in files.items():
        p = Path(cwd) / name
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    for name in deletes:
        (Path(cwd) / name).unlink()
    git(cwd, 'add', '-A')
    git(cwd, 'commit', '-q', '-m', msg)
    return git(cwd, 'rev-parse', 'HEAD')


def test_payload_links():
    new = [('o/r', 'b', 'abc123', N + 'A.cpp'), ('o/r', 'b', 'abc123', 'rebuild/2008-06/native-headers/A.h')]
    body = nf.build_payloads(new)[0]['embeds'][0]
    assert body['title'].endswith('RoConstruct Integration Digest')
    value = body['fields'][0]['value']
    assert '[native-classes/A.cpp](https://github.com/o/r/blob/abc123/' + N + 'A.cpp)' in value
    assert nf.is_native(N + 'x.cpp') and not nf.is_native(N + 'x.txt') and not nf.is_native('src/x.cpp')


def test_fork_merge():
    with tempfile.TemporaryDirectory() as tmp:
        repo, clone, state = Path(tmp) / 'repo', Path(tmp) / 'clone', Path(tmp) / 'state.json'
        repo.mkdir()
        git(repo, 'init', '-q', '-b', 'work')
        git(repo, 'config', 'user.name', 't'); git(repo, 'config', 'user.email', 't@t')
        base = commit(repo, {N + 'Shared.cpp': 'int shared=1;\n', N + 'Keep.cpp': 'int keep;\n'}, 'base')
        mine = commit(repo, {N + 'Mine.cpp': 'int mine;\n'}, 'mine')
        git(repo, 'update-ref', 'refs/forks/origin/work', mine)

        def fork(name, branch, files, deletes=()):
            git(repo, 'checkout', '-q', '-B', 'tmp-' + name, base)
            sha = commit(repo, files, name, deletes)
            git(repo, 'update-ref', 'refs/forks/%s/%s' % (name, branch), sha)
            return sha

        fork('clean', 'feat', {N + 'FromClean.cpp': 'int c;\n'})
        fork('conflict', 'feat', {N + 'Shared.cpp': 'int shared=2;\n'})
        git(repo, 'checkout', '-q', '-B', 'tmp-mine', mine)
        commit(repo, {N + 'Shared.cpp': 'int shared=3;\n'}, 'mine edits shared')
        git(repo, 'update-ref', 'refs/forks/origin/work', git(repo, 'rev-parse', 'HEAD'))
        fork('deleter', 'feat', {N + 'Extra.cpp': 'int e;\n'}, deletes=[N + 'Keep.cpp'])
        git(repo, 'checkout', '-q', '--orphan', 'unrelated'); git(repo, 'rm', '-rfq', '.')
        sha = commit(repo, {N + 'Orphan.cpp': 'int o;\n'}, 'orphan')
        git(repo, 'update-ref', 'refs/forks/orphan/feat', sha)
        git(repo, 'checkout', '-q', 'work')

        logs = []
        fork_merge.run(push=True, log=logs.append, repo=repo, clone=clone, mine='work', days=36500, state_file=state)
        out = '\n'.join(logs)
        tree = git(clone, 'ls-tree', '-r', '--name-only', 'auto-merge/native').splitlines()
        assert N + 'FromClean.cpp' in tree, out                       # clean fork merged
        assert N + 'Keep.cpp' in tree, out                            # deleter was not merged
        assert any(p.startswith('merge/conflict/feat/') and p.endswith('Shared.cpp') for p in tree), out
        assert any(p.startswith('merge/deleter/feat/') and p.endswith('Extra.cpp') for p in tree), out
        assert any(p.startswith('merge/orphan/feat/') and p.endswith('Orphan.cpp') for p in tree), out
        note = git(clone, 'show', 'auto-merge/native:merge/conflict/feat/MERGE_NEEDED.md')
        assert 'CONFLICT' in note, note
        again = []
        fork_merge.run(push=True, log=again.append, repo=repo, clone=clone, mine='work', days=36500, state_file=state)
        assert not any('merged' in l or 'parked' in l for l in again), again   # idempotent


if __name__ == '__main__':
    test_payload_links()
    test_fork_merge()
    print('native files tests ok')
