import hashlib
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
    (root / 'roconstruct-package.json').write_text(json.dumps({'revision': 'abc123','authority':'RoConstruct/work/workspace'}))
    return root


def test_triage_deduplicates_fork_and_drafts_without_touching_work(tmp_path):
    import sqlite3
    import time

    root = tmp_path / 'owner'
    root.mkdir()
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=root).decode().strip()
    git('init', '-q')
    git('config', 'user.name', 'Test')
    git('config', 'user.email', 'test@example.invalid')
    name = 'rebuild/2008-06/native-classes/Foo.cpp'
    canonical = root / 'workspace' / name
    canonical.parent.mkdir(parents=True)
    canonical.write_bytes(b'int value = 1;\n')
    fork = root / name
    fork.parent.mkdir(parents=True)
    fork.write_bytes(b'int value = 1;\n')
    git('add', '.')
    git('commit', '-qm', 'base')
    old = git('rev-parse', 'HEAD')
    git('update-ref', 'refs/remotes/findings/work', old)
    fork.write_bytes(b'int value = 2;\n')
    git('add', name)
    git('commit', '-qm', 'fork')
    new = git('rev-parse', 'HEAD')

    inbox = d.Inbox(root)
    token = inbox.register('tester')['token']
    common = dict(schema=1, user='tester', model='model', session='a'*32, baseline='worker')
    for original in ('int value = 1;\n', 'int value = 0;\n'):
        packet = dict(common, files={name: {'base': original, 'text': 'int value = 2;\n'}})
        inbox.receive(packet, token)
    server = root / 'work/server.db'
    with sqlite3.connect(server) as db:
        db.execute('CREATE TABLE file_leases(name TEXT,user TEXT,patterns TEXT,expires REAL)')
        db.execute('INSERT INTO file_leases VALUES(?,?,?,?)', ('active', 'other', json.dumps([name]), time.time()+600))
    canonical.write_bytes(b'active worker edit\n')
    index = (root / '.git/index').read_bytes()
    report = d.triage(root, forks=[('fork', old, new)], include_diff=True)
    assert report['canonical_commit'] == old and report['pending_packets'] == 2
    assert len(report['variants']) == 1 and report['errors'] == []
    variant = report['variants'][0]
    assert sorted(s['relation'] for s in variant['sources']) == ['base_matches_current', 'base_matches_current', 'three_way_review']
    assert variant['leases'][0]['name'] == 'active' and '+int value = 2;' in variant['diff']
    assert canonical.read_bytes() == b'active worker edit\n' and (root / '.git/index').read_bytes() == index
    assert git('rev-parse', 'HEAD') == new and len(inbox.pending()) == 2
    inbox.receive(dict(common, files={name: {'base': 'int value = 1;\n', 'text': None}}), token)
    deletion = d.triage(root, after=2)
    assert len(deletion['variants']) == 1
    assert deletion['variants'][0]['sources'][0]['relation'] == 'deletion_proposed'
    existing = root / 'existing-report.json'
    existing.write_text('preserve me')
    with pytest.raises(FileExistsError):
        d.main(['--root', str(root), 'triage', '--output', str(existing)])
    assert existing.read_text() == 'preserve me'
    blocked_fork = d.triage(root, forks=[('fork', new, old)])
    assert blocked_fork['pending_packets'] == 3 and blocked_fork['errors'][0]['fork'] == 'fork'
    git('update-ref', 'refs/forks/alice/main', new)
    git('update-ref', 'refs/forks/bob/main', old)
    state = root / 'work/native-draft-integration-state.json'
    state.write_text(json.dumps({'reviewed_fork_tips': {'alice/main': old}}))
    discovered = d.triage(root, discover_forks=True)
    assert [x['status'] for x in discovered['forks_observed']] == ['comparison_requested', 'already_in_canonical']
    assert any(s.get('label') == 'alice/main' for s in discovered['variants'][0]['sources'])
    assert json.loads(state.read_text())['reviewed_fork_tips']['alice/main'] == old


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


def test_sparse_notes_are_advisory_expire_and_cannot_replace_leases(tmp_path,receiver):
    inbox,server=receiver
    auth=d.request(server,'register',dict(user='alice'))
    body=dict(user='alice',scope='CRobloxView',text='Working on view; see class lease.')
    assert d.request(server,'note',body,auth['token'])['saved']
    assert d.request(server,'note',body,auth['token'])['unchanged']
    notes=d.request(server,'notes')
    assert notes['leases_authoritative'] is True
    assert len(notes['notes'])==1 and notes['notes'][0]['advisory_only']
    with pytest.raises(HTTPError):
        d.request(server,'note',dict(body,text='Per-function spam'),auth['token'])
    with pytest.raises(HTTPError):
        d.request(server,'note',dict(body,scope='AnotherClass'),auth['token'])
    bob=d.request(server,'register',dict(user='bob'))
    with pytest.raises(HTTPError) as error:
        d.request(server,'note',body,bob['token'])
    assert error.value.code==403
    assert d.request(server,'note',dict(body,clear=True),auth['token'])['cleared']
    assert d.request(server,'notes')['notes']==[]
    with inbox.connect() as db:
        db.execute('UPDATE notes SET updated=0,expires=0')
    assert inbox.notes()==[]


def test_package_preexisting_edits_not_absorbed(tmp_path, receiver):
    import hashlib
    _, server = receiver
    root = workspace(tmp_path)
    source = root / 'docs/Native.cpp'
    original = source.read_bytes()
    (root / 'workspace-manifest.json').write_text(json.dumps({'files': {'docs/Native.cpp': hashlib.sha256(original).hexdigest()}}))
    source.write_text('pre-existing work from another contributor')
    with pytest.raises(ValueError, match='Pre-existing package edits'):
        d.initialize(root, ['docs/Native.cpp'], 'alice', 'model', server)
    assert source.read_text() == 'pre-existing work from another contributor'
    assert not (root / 'local/drafts/sessions').exists()


def test_final_receipt_covers_latest_edit_and_reversion(tmp_path, receiver):
    inbox, server = receiver
    root = workspace(tmp_path)
    source = root / 'docs/Native.cpp'
    original = source.read_bytes().decode('utf-8')
    session = d.initialize(root, ['docs/Native.cpp'], 'alice', 'model', server)
    source.write_text('first saved change')
    first = d.checkpoint(root, session)
    d.flush(root, session)
    source.write_text('last edit after milestone')
    assert d.status(root, session)['snapshot_current'] is False
    final = d.stop(root, session, wait=True)
    assert final['snapshot_current'] and final['pending'] == 0
    assert final['latest_packet'] != first
    assert inbox.packet(final['latest_packet'])['files']['docs/Native.cpp']['text'] == 'last edit after milestone'
    source.write_bytes(original.encode('utf-8'))
    final = d.stop(root, session, wait=True)
    packet = inbox.packet(final['latest_packet'])
    assert packet['files']['docs/Native.cpp'] == {'base': 'last edit after milestone', 'text': original}
    assert d.checkpoint(root, session) is None
    assert final['latest_receipt']['durable'] and final['snapshot_current']
    assert json.loads((d.session_path(root,session)/'session.json').read_text())['base']['docs/Native.cpp'] == original


def test_watcher_stop_not_lost_and_final_transport_retry(tmp_path, receiver, monkeypatch):
    _, server = receiver
    root = workspace(tmp_path)
    session = d.initialize(root, ['docs'], 'alice', 'model', server)
    folder = d.session_path(root, session)
    (folder / 'stop').touch()
    (root / 'docs/Native.cpp').write_text('final offline draft')
    with monkeypatch.context() as m:
        m.setattr(d, 'request', lambda *args, **kwargs: (_ for _ in ()).throw(OSError('offline')))
        with pytest.raises(OSError, match='offline'):
            d.watch(root, session, every=1)
    assert json.loads((folder / 'health.json').read_text())['stopped'] is True
    assert d.status(root, session)['pending'] == 1
    d.flush(root, session)
    result = d.stop(root, session, wait=True)
    assert result['snapshot_current'] and result['pending'] == 0
    assert result['latest_receipt']['id'] == result['latest_packet']


def test_invalid_local_receipt_is_retried(tmp_path, receiver):
    _, server = receiver
    root = workspace(tmp_path)
    session = d.initialize(root, ['docs'], 'alice', 'model', server)
    (root / 'docs/Native.cpp').write_text('new draft')
    packet = d.checkpoint(root, session)
    d.atomic(d.session_path(root,session)/'receipts'/(packet+'.json'), {'id':packet,'durable':False})
    assert d.status(root,session)['pending'] == 1
    assert d.flush(root,session) == [packet]
    assert d.status(root,session)['latest_receipt']['durable'] is True


def test_scoped_package_port_and_live_watcher_final_receipt(tmp_path, receiver):
    import hashlib
    import shutil
    import time
    _, server = receiver
    root = workspace(tmp_path)
    source = root / 'docs/Native.cpp'
    original = source.read_bytes()
    (root/'workspace-manifest.json').write_text(json.dumps({'files':{'docs/Native.cpp':hashlib.sha256(original).hexdigest()}}))
    shutil.copytree(Path(d.__file__).parent,root/'roc',ignore=shutil.ignore_patterns('__pycache__'))
    session = d.initialize(root,['docs/Native.cpp'],'alice','model',server)
    source.write_text('ported task change')
    process = d.start(root,session,every=10)
    try:
        deadline=time.monotonic()+10
        while time.monotonic()<deadline:
            result=d.status(root,session)
            if result['latest_receipt']:
                break
            time.sleep(.05)
        assert result['latest_receipt'] and result['health']['pid']==process['pid']
        source.write_text('final edit after watcher milestone')
        final=d.stop(root,session,wait=True,timeout=10)
        assert final['snapshot_current'] and final['pending']==0
        assert final['latest_receipt']['id']==final['latest_packet']
        folder=d.session_path(root,session)
        packet=json.loads((folder/'outbox'/(final['latest_packet']+'.json')).read_text())
        assert packet['files']['docs/Native.cpp']['base']==original.decode()
        assert packet['files']['docs/Native.cpp']['text']=='final edit after watcher milestone'
    finally:
        d.stop(root,session,wait=True,timeout=10)


@pytest.mark.parametrize('prefix', ['', 'workspace/'])
def test_triage_includes_organized_fork_paths(tmp_path, prefix):
    import subprocess
    root = tmp_path
    def git(*args):
        return subprocess.check_output(['git', *args], cwd=root).decode().strip()
    git('init', '-q')
    git('config', 'user.name', 'test')
    git('config', 'user.email', 'test@example.invalid')
    name = 'rebuild/2008-06/App/src/v8tree/Instance.cpp'
    canonical = root / 'workspace' / name
    canonical.parent.mkdir(parents=True)
    canonical.write_text('old body\n')
    public = root / name.removeprefix('rebuild/')
    public.parent.mkdir(parents=True)
    public.write_text('public body\n')
    fork = root / (prefix + name)
    fork.parent.mkdir(parents=True, exist_ok=True)
    fork.write_text('old body\n')
    git('add', '.')
    git('commit', '-qm', 'base')
    old = git('rev-parse', 'HEAD')
    git('update-ref', 'refs/remotes/findings/work', old)
    fork.write_text('new body\n')
    git('add', prefix + name)
    git('commit', '-qm', 'fork')
    new = git('rev-parse', 'HEAD')
    report = d.triage(root, forks=[('contributor', old, new)], include_diff=True)
    assert not report['errors']
    assert len(report['variants']) == 1
    assert report['variants'][0]['path'] == name
    assert report['variants'][0]['public_path'] == name.removeprefix('rebuild/')
    assert report['variants'][0]['public_relation'] == 'different'
    assert '-public body' in report['variants'][0]['public_diff']
    assert '+new body' in report['variants'][0]['public_diff']
    assert report['variants'][0]['public_sha256'] == hashlib.sha256(b'public body\n').hexdigest()
    assert report['variants'][0]['sources'][0]['fork_path'] == prefix + name
