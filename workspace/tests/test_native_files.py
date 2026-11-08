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
    new = [('o/r', 'b', 'abc123', N + 'A.cpp', 'new'), ('o/r', 'b', 'abc123', 'rebuild/2008-06/native-headers/A.h', 'new'),
           ('o/r', 'b', 'abc123', N + 'B.cpp', 'changed')]
    bodies = [p['embeds'][0] for p in nf.build_payloads(new)]
    assert bodies[0]['title'].endswith('RoConstruct Integration Digest')
    assert 'New native files' in bodies[0]['description'] and 'Changed native files' in bodies[1]['description']
    assert '[native-classes/A.cpp](https://github.com/o/r/blob/abc123/' + N + 'A.cpp)' in bodies[0]['description']
    assert '[native-classes/B.cpp](' in bodies[1]['description']
    assert nf.is_native(N + 'x.cpp') and not nf.is_native(N + 'x.txt') and not nf.is_native('src/x.cpp')
    # many long links: several small messages, every link whole, nothing lost
    sha = 'f' * 40
    many = [('someone/RoConstruct', 'claude/a-long-branch-name', sha, N + 'HumanoidStatesLeaves%03d.cpp' % i, 'new') for i in range(60)]
    payloads = nf.build_payloads(many)
    assert len(payloads) == 8, len(payloads)                    # 60 links / 8 per message
    seen = 0
    for p in payloads:
        embed = p['embeds'][0]
        assert len(embed['description']) < 4096 and 'fields' not in embed
        links = [l for l in embed['description'].split('\n') if l.startswith('[')]
        assert len(links) <= nf.LINKS_PER_MESSAGE
        for line in links:
            assert line.endswith('.cpp)'), line
        seen += len(links)
    assert seen == 60, seen


def test_changed_files():
    with tempfile.TemporaryDirectory() as tmp:
        repo = Path(tmp)
        git(repo, 'init', '-q', '-b', 'work')
        git(repo, 'config', 'user.name', 't'); git(repo, 'config', 'user.email', 't@t')
        a = commit(repo, {N + 'A.cpp': 'int a;\n', 'README.md': 'x\n'}, 'a')
        b = commit(repo, {N + 'A.cpp': 'int a2;\n', N + 'B.cpp': 'int b;\n', 'README.md': 'y\n'}, 'b')
        old = nf.ROOT
        nf.ROOT = repo
        try:
            got = sorted(nf.changed_files(a, b))
        finally:
            nf.ROOT = old
        assert got == [('changed', N + 'A.cpp'), ('new', N + 'B.cpp')], got


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




def test_draft_paths_and_complete_payload_delivery():
    path = N + 'A.cpp'
    draft = 'drafts/files/' + 'a' * 64 + '/' + path
    assert nf.is_native(draft)
    description = nf.build_payloads([('o/r', 'work', 'a' * 40, draft, 'new')])[0]['embeds'][0]['description']
    assert '[native-classes/A.cpp](' in description
    assert '[drafts/' not in description and '/drafts/files/' in description
    assert nf.native_path(draft) == nf.native_path('workspace/' + path) == path
    rows = [('o/r', 'work', 'b' * 40, 'drafts/files/' + 'a' * 64 + '/' + N + 'A%d.cpp' % i, 'new') for i in range(161)]
    payloads = nf.build_payloads(rows)
    assert sum(p['embeds'][0]['description'].count('](https://') for p in payloads) == 161
    assert all('Inactive draft upload' in p['embeds'][0]['description'] for p in payloads)


def setup_delivery_scan(monkeypatch, tmp_path, count):
    import json
    monkeypatch.setattr(nf, 'STATE', tmp_path / 'state.json')
    nf.STATE.write_text(json.dumps({'tips': {'o/r@feature': 'a' * 40}, 'announced': []}))
    monkeypatch.setattr(nf, 'github_token', lambda: None)
    monkeypatch.setattr(nf, 'upstream_slug', lambda: 'o/r')
    monkeypatch.setattr(nf, 'discover', lambda *a: {'o/r': 'origin'})
    monkeypatch.setattr(nf, 'fetch_refs', lambda *a: {'feature': 'b' * 40})
    monkeypatch.setattr(nf, 'upstream_main_tip', lambda *a: None)
    monkeypatch.setattr(nf, 'changed_files', lambda *a: [('new', N + 'A%d.cpp' % i) for i in range(count)])
    monkeypatch.setattr(nf, 'git', lambda *a, **kw: 'commit' if a[0] == 'cat-file' else 'blob-' + a[-1])


def test_partial_delivery_retries_only_unsent_files(monkeypatch, tmp_path):
    setup_delivery_scan(monkeypatch, tmp_path, 24)
    delivered = []
    def partial(rows, log, on_sent):
        delivered.extend(rows[:8]); on_sent(rows[:8]); return False
    monkeypatch.setattr(nf, 'post_files', partial)
    nf.scan()
    state = nf.load_state()
    assert len(state['announced']) == 8 and len(state['pending']) == 16
    def finish(rows, log, on_sent):
        assert not set(delivered).intersection(rows)
        delivered.extend(rows); on_sent(rows); return True
    monkeypatch.setattr(nf, 'post_files', finish)
    nf.scan()
    assert len(delivered) == 24 and not nf.load_state()['pending']
    assert nf.scan() == []


def test_delivery_cap_keeps_durable_tail(monkeypatch, tmp_path):
    setup_delivery_scan(monkeypatch, tmp_path, 161)
    batches = []
    def deliver(rows, log, on_sent):
        batches.append(len(rows)); on_sent(rows); return True
    monkeypatch.setattr(nf, 'post_files', deliver)
    nf.scan()
    assert batches == [150] and len(nf.load_state()['pending']) == 11
    nf.scan()
    assert batches == [150, 11] and len(nf.load_state()['announced']) == 161
    assert not nf.load_state()['pending']




def test_post_acknowledges_successful_message_before_failure(monkeypatch):
    from roc import reports
    monkeypatch.setattr(reports, 'server_mines_webhook', lambda: 'https://example.invalid/webhook')
    monkeypatch.setattr(nf.time, 'sleep', lambda seconds: None)
    rows = [('o/r', 'work', 'a' * 40, N + 'A%d.cpp' % i, 'new') for i in range(16)]
    class Response:
        def read(self): return b''
    calls = []
    def request(*args, **kwargs):
        calls.append(args)
        if len(calls) == 2: raise OSError('delivery failed')
        return Response()
    monkeypatch.setattr(nf.urllib.request, 'urlopen', request)
    acknowledged = []
    assert not nf.post_files(rows, log=lambda text: None, on_sent=acknowledged.extend)
    assert acknowledged == rows[:8]


def test_git_fetch_is_noninteractive_and_bounded(monkeypatch):
    def timeout(command, **kwargs):
        assert kwargs['timeout'] == 120
        assert kwargs['env']['GIT_TERMINAL_PROMPT'] == '0'
        assert kwargs['env']['GCM_INTERACTIVE'] == 'never'
        raise subprocess.TimeoutExpired(command, 120)
    monkeypatch.setattr(nf.subprocess, 'run', timeout)
    import pytest
    with pytest.raises(RuntimeError, match='git fetch timed out'):
        nf.git('fetch', 'https://example.invalid/repo.git')


if __name__ == '__main__':
    test_payload_links()
    test_changed_files()
    test_fork_merge()
    print('native files tests ok')


def test_webhook_uses_fresh_progress_each_delivery(monkeypatch, tmp_path):
    import json
    from roc import integration_site, reports
    monkeypatch.setattr(nf, 'ROOT', tmp_path)
    (tmp_path/'site').mkdir()
    (tmp_path/'site/integration.json').write_text('{}')  # Stale site data must be ignored.
    monkeypatch.setattr(reports, 'server_mines_webhook', lambda: 'https://example.invalid/webhook')
    monkeypatch.setattr(nf.time, 'sleep', lambda _: None)
    monkeypatch.setattr(integration_site, 'integration_rate', lambda *a: 'rate')
    current = {'count': 1}
    monkeypatch.setattr(integration_site, 'live_progress', lambda root: dict(current))
    monkeypatch.setattr(integration_site, 'progress_description', lambda data: 'fresh %d' % data['count'])
    bodies = []
    class Response:
        def read(self): return b''
    def request(req, **kwargs):
        bodies.append(json.loads(req.data))
        return Response()
    monkeypatch.setattr(nf.urllib.request, 'urlopen', request)
    row = ('owner/repo','work','a'*40,N+'Example.cpp','new')
    assert nf.post_files([row], log=lambda _: None)
    current['count'] = 2
    assert nf.post_files([row], log=lambda _: None)
    assert [body['embeds'][0]['description'] for body in bodies] == ['fresh 1','fresh 2']


def test_organized_native_paths_and_drafts_are_detected():
    path = 'rebuild/2008-06/App/src/v8tree/Instance.cpp'
    header = 'rebuild/2008-06/Network/include/net/Packet.h'
    assert nf.is_native(path) and nf.is_native('workspace/' + path)
    assert nf.is_native('drafts/files/' + 'b' * 64 + '/' + path)
    assert nf.is_native(header)
    assert not nf.is_native('rebuild/2008-06/App/tests/Trial.cpp')
    assert not nf.is_native('2008-06/App/src/v8tree/Instance.cpp')
    assert nf.native_path('workspace/' + path) == nf.native_path('drafts/files/' + 'b' * 64 + '/' + path)
