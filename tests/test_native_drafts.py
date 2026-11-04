import json
from pathlib import Path
import subprocess
import threading
from http.server import ThreadingHTTPServer
from urllib.error import HTTPError

import pytest

from roc import native_drafts as d


@pytest.fixture
def receiver(tmp_path):
    inbox = d.Inbox(tmp_path / 'owner')
    server = ThreadingHTTPServer(('127.0.0.1', 0), d.handler(inbox))
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    yield inbox, 'http://127.0.0.1:' + str(server.server_port)
    server.shutdown()
    server.server_close()
    thread.join()


def workspace(tmp_path):
    root = tmp_path / 'contributor'
    (root / 'docs').mkdir(parents=True)
    (root / 'docs/Native.cpp').write_text('int value() { return 1; }\n')
    (root / 'roconstruct-package.json').write_text(json.dumps({'revision': 'abc123'}))
    return root


def test_http_drafts_new_files_deletions_offline_and_restart(tmp_path, receiver):
    inbox, server = receiver
    root = workspace(tmp_path)
    session = d.initialize(root, ['docs'], 'contributor', 'actual-model', server)
    assert d.checkpoint(root, session) is None
    (root / 'docs/Native.cpp').write_text('incomplete intentionally broken source\n')
    (root / 'docs/New.h').write_text('// new header\n')
    identifier = d.checkpoint(root, session)
    assert identifier and d.checkpoint(root, session) is None
    assert d.flush(root, session) == [identifier]
    assert d.flush(root, session) == []
    packet = inbox.packet(identifier)
    assert packet['files']['docs/Native.cpp']['base'].startswith('int value')
    assert packet['files']['docs/New.h']['base'] is None
    assert packet['exact_credits'] == 0
    assert len(d.Inbox(inbox.root).pending()) == 1
    # A lost response/retried POST does not create another event or ID.
    auth = json.loads((d.session_path(root, session) / 'credentials.json').read_text())
    assert d.request(server, 'upload', packet, auth['token'])['id'] == identifier
    assert len(inbox.pending()) == 1
    (root / 'docs/Native.cpp').unlink()
    second = d.checkpoint(root, session)
    assert second != identifier
    folder = d.session_path(root, session)
    state = json.loads((folder / 'session.json').read_text())
    state['server'] = 'http://127.0.0.1:1'
    d.atomic(folder / 'session.json', state)
    with pytest.raises(OSError):
        d.flush(root, session)
    assert (folder / 'outbox' / (second + '.json')).exists()
    assert not (folder / 'receipts' / (second + '.json')).exists()
    state['server'] = server
    d.atomic(folder / 'session.json', state)
    assert d.flush(root, session) == [second]
    assert inbox.packet(second)['files']['docs/Native.cpp']['text'] is None
    assert inbox.packet(second)['parent'] == identifier
    archive=inbox.archive()
    assert len(archive) == 6
    assert archive['drafts/files/'+identifier+'/docs/Native.cpp'] == packet['files']['docs/Native.cpp']['text'].encode('utf-8')
    assert 'drafts/files/'+second+'/docs/Native.cpp' not in archive
    events = [json.loads(line) for line in (inbox.root/'work/agent-inbox/events.jsonl').read_text().splitlines()]
    assert [row['bundle'] for row in events] == [identifier,second]


@pytest.mark.parametrize('name', ['../escape.cpp','/absolute.cpp','docs/a/../../escape.cpp',
    'docs\\evil.cpp','docs/C:bad.cpp','local/config/settings.json','docs/token.json',
    'docs/.env','docs/CON.txt','docs/foo./safe.cpp','tools/new.cpp','rebuild/x/out/value.cpp'])
def test_reject_unsafe_private_paths(name):
    with pytest.raises(ValueError):
        d.safe_path(name)


def test_scope_preserves_unrelated_dirty_files(tmp_path, receiver):
    inbox, server = receiver
    root = workspace(tmp_path)
    unrelated = root / 'docs/Other.cpp'
    unrelated.write_text('other worker dirty edits')
    session = d.initialize(root, ['docs/Native.cpp'], 'contributor', 'model', server)
    (root / 'docs/Native.cpp').write_text('new draft')
    identifier = d.checkpoint(root, session)
    d.flush(root, session)
    assert set(inbox.packet(identifier)['files']) == {'docs/Native.cpp'}
    assert unrelated.read_text() == 'other worker dirty edits'


def test_credential_cannot_impersonate_contributor(tmp_path, receiver):
    inbox, server = receiver
    root = workspace(tmp_path)
    session = d.initialize(root, ['docs'], 'alice', 'model', server)
    (root / 'docs/Native.cpp').write_text('new')
    identifier = d.checkpoint(root, session)
    packet = json.loads((d.session_path(root, session) / 'outbox' / (identifier + '.json')).read_text())
    token = d.request(server, 'register', {'user': 'bob'})['token']
    with pytest.raises(HTTPError) as error:
        d.request(server, 'upload', packet, token)
    assert error.value.code == 403
    assert inbox.pending() == []


def test_git_existing_edits_are_drafts(tmp_path, receiver):
    _, server = receiver
    root = workspace(tmp_path)
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=root)
    git('init')
    git('config','user.name','Test')
    git('config','user.email','test@example.invalid')
    git('add','.')
    git('commit','-m','baseline')
    (root / 'docs/Native.cpp').write_text('uncommitted work')
    (root / 'docs/Other.cpp').write_text('new untracked')
    before = git('status','--porcelain')
    session = d.initialize(root,['docs'],'alice','model',server)
    identifier = d.checkpoint(root,session)
    packet = json.loads((d.session_path(root,session)/'outbox'/(identifier+'.json')).read_text())
    assert packet['files']['docs/Native.cpp']['base'].startswith('int value')
    assert packet['files']['docs/Other.cpp']['base'] is None
    # Only ignored local state is added; original sources/index stay unchanged.
    assert (root/'docs/Native.cpp').read_text() == 'uncommitted work'
    assert b'docs/Native.cpp' in before


def test_live_lock_released_and_corrupt_archive_refused(tmp_path, receiver):
    inbox, _ = receiver
    path = tmp_path/'test.lock'
    with d.lock(path):
        with pytest.raises(RuntimeError,match='Already running'):
            with d.lock(path):
                pass
    with d.lock(path):
        pass
    with inbox.connect() as db:
        db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,0)',('bad','alice','{}'))
    with pytest.raises(ValueError):
        inbox.archive()


def test_generated_probe_outputs_skipped_but_existing_git_deletion_saved(tmp_path, receiver):
    _,server=receiver
    root=workspace(tmp_path)
    def git(*args):
        return subprocess.check_output(['git',*args],cwd=root)
    git('init');git('config','user.name','Test');git('config','user.email','test@example.invalid')
    git('add','.');git('commit','-m','baseline')
    (root/'docs/Native.cpp').unlink()
    (root/'docs/generated.obj').write_bytes(b'\0binary')
    session=d.initialize(root,['docs'],'alice','model',server)
    identifier=d.checkpoint(root,session)
    d.flush(root,session)
    packet=receiver[0].packet(identifier)
    assert set(packet['files']) == {'docs/Native.cpp'}
    assert packet['files']['docs/Native.cpp']['text'] is None


@pytest.mark.parametrize('name',['rebuild/2008-06/native-world/owner.inc','packaging/setup.ps1','roc.py','roc.cmd','docs/native.toml'])
def test_scoped_source_and_build_text_files_supported(name):
    assert d.safe_path(name)==name
