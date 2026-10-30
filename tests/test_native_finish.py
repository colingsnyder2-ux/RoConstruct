import json
import subprocess
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_finish as finish


@pytest.fixture
def batch(tmp_path, monkeypatch):
    monkeypatch.setattr(finish.rebuild, 'ROOT', tmp_path)
    config = dict(model='Actual model', user='colin', before='before.json', baseline='base.json',
                  test_source='test.cpp', evidence='Actual SDK source and native instruction evidence', submit=True)
    base = dict(revision='current', overlay={})
    (tmp_path / 'before.json').write_text(json.dumps(dict(module='RbxgsApp', owned_2008=1, owned_addrs=['00400000'])))
    (tmp_path / 'base.json').write_text(json.dumps(base))
    (tmp_path / 'test.cpp').write_text('int main(){return 0;}')
    overlay = tmp_path / 'overlay.json'; overlay.write_text(json.dumps({'App/test.cpp': [['', 'new source']]}))
    spec = dict(name='RbxgsApp', overlay=dict(patches='overlay.json'), layers=[], test_includes=[], test_defines='')
    monkeypatch.setattr(finish.rebuild, 'load_module', lambda *args: spec)
    report = dict(module='RbxgsApp', linked=True, test_exit=0, unresolved=[], owned_2008=2,
                  owned_addrs=['00400000', '00400010'])
    monkeypatch.setattr(finish.rebuild, 'build_module', lambda *args, **kwargs: report)
    monkeypatch.setattr(finish.rebuild, 'build_overlay', lambda *args: None)
    monkeypatch.setattr(finish.rebuild, 'resolve_objects', lambda *args, **kwargs: dict(linked=True, exit=0))
    monkeypatch.setattr(finish, 'linked_proofs', lambda *args: [dict(target='00400010', code_exact_in_executable=True)])
    out = tmp_path / 'rebuild/2008-06/out/RbxgsApp'; out.mkdir(parents=True)
    (out / 'owned-symbols.json').write_text(json.dumps({'00400010': [dict(symbol='?native', object='Native.obj')]}))
    (out / 'linked').mkdir();(out / 'linked/Native.obj').write_bytes(b'object')
    monkeypatch.setattr(finish.rebuild, 'coff_externals', lambda data: {'?native': True})
    (tmp_path / 'rebuild/2008-06/tests').mkdir()
    manifest = tmp_path / 'rebuild/2008-06/manifests'; manifest.mkdir()
    (manifest / 'functions.json').write_text(json.dumps([dict(addr='00400010', score=100)]))
    monkeypatch.setattr(finish.worker, 'load_settings', lambda: dict(server='local'))
    packets = {}
    calls = []
    def call(path, body=None):
        calls.append(path)
        if path.endswith('/base'):
            return base
        packet = body['packet']; key = finish.integration.digest(packet)
        packets.setdefault(key, packet)
        return dict(id=key, state='needs-owner-review', verified=False, credits=0)
    monkeypatch.setattr(finish.worker, 'Api', lambda *args: SimpleNamespace(call=call, close=lambda: None))
    (tmp_path / 'finish.json').write_text(json.dumps(config))
    return tmp_path, config, base, spec, report, packets, calls


def test_finish_submits_once_on_safe_rerun(batch):
    root, _, _, _, _, packets, _ = batch
    first = finish.run(root / 'finish.json', log=lambda _: None)
    second = finish.run(root / 'finish.json', log=lambda _: None)
    assert first == second
    assert len(packets) == 1
    assert first['gained'] == 1 and first['server']['verified'] is False


@pytest.mark.parametrize('failure', ['lost', 'link', 'runtime', 'proof', 'stale', 'changed', 'compile'])
def test_failure_cannot_submit_or_notify(batch, monkeypatch, failure):
    root, _, base, spec, report, packets, _ = batch
    if failure == 'lost':
        report['owned_addrs'] = ['00400010']
    elif failure == 'link':
        report['linked'] = False
    elif failure == 'runtime':
        monkeypatch.setattr(finish.rebuild, 'resolve_objects', lambda *a, **kw: dict(linked=True, exit=7))
    elif failure == 'proof':
        monkeypatch.setattr(finish, 'linked_proofs', lambda *a: [dict(code_exact_in_executable=False)])
    elif failure == 'stale':
        base['revision'] = 'advanced'
        config = json.loads((root / 'finish.json').read_text());config['auto_rebase'] = False
        (root / 'finish.json').write_text(json.dumps(config))
    elif failure == 'changed':
        def prove(*args):
            (root / 'test.cpp').write_text('concurrent edit')
            return [dict(code_exact_in_executable=True)]
        monkeypatch.setattr(finish, 'linked_proofs', prove)
    else:
        spec['layers'] = [dict(name='broken')]
        path = root / 'rebuild/2008-06/out/RbxgsApp/layer-broken';path.mkdir()
        (path / 'errors.json').write_text('{"file.cpp":"error"}')
    with pytest.raises(ValueError):
        finish.run(root / 'finish.json', log=lambda _: None)
    assert not packets
    assert json.loads((root / 'finished/state.json').read_text())['state'] == 'failed'


def test_server_checkout_rejected_before_build(batch):
    root, *_ = batch
    (root / 'work').mkdir(exist_ok=True)
    (root / 'work/server.db').touch()
    with pytest.raises(ValueError, match='private contributor'):
        finish.run(root / 'finish.json')


def test_packet_cannot_remove_accepted_path():
    with pytest.raises(ValueError, match='removes accepted'):
        finish.source_packet(dict(revision='base', overlay={'App/accepted.cpp': [['x', 'y']]}), {},
                             dict(owned_addrs=['00400000']), {}, ['00400000'], 'model', 'evidence', {'00400000'})


def test_nonconflicting_rebase_retains_both_changes_and_is_idempotent():
    before = dict(generator='same', overlay={'App/A.cpp': [['base', 'accepted']]})
    current = dict(generator='same', overlay={'App/A.cpp': [['base', 'accepted'], ['parameter', 'default10']]})
    ours = {'App/A.cpp': [['base', 'accepted'], ['tail', 'tail plus class name']]}
    rebased, paths = finish.rebase_candidate(before, current, ours)
    assert paths == ['App/A.cpp']
    assert rebased['App/A.cpp'] == current['overlay']['App/A.cpp'] + [['tail', 'tail plus class name']]
    assert finish.rebase_candidate(before, current, rebased)[0] == rebased


@pytest.mark.parametrize('kind', ['anchor', 'generator', 'replacement'])
def test_rebase_conflicts_cannot_overwrite_local_candidate(kind):
    before = dict(generator='same', overlay={'App/A.cpp': [['base', 'accepted']]})
    current = dict(generator='changed' if kind == 'generator' else 'same',
                   overlay={'App/A.cpp': [['base', 'accepted'], ['tail', 'server edit']]})
    ours = {'App/A.cpp': [['base', 'accepted'], ['tail', 'our edit']]}
    if kind == 'replacement':
        current['overlay']['App/A.cpp'] = [['base', 'different accepted replacement']]
    snapshot = json.dumps(ours)
    with pytest.raises(ValueError):
        finish.rebase_candidate(before, current, ours)
    assert json.dumps(ours) == snapshot


def test_linked_proof_rejects_wrong_provider_and_corrupt_bytes(tmp_path, monkeypatch):
    import pefile
    from test_coff_data_index import object_bytes
    obj = object_bytes(); (tmp_path / 'Native.obj').write_bytes(obj)
    symbol = '_f'; owners = {'00500000': [dict(symbol=symbol, object='Native.obj')]}
    monkeypatch.setattr(finish.match, 'target', lambda *a: (b'\xb8\x00\x00\x00\x00\xc3', [1], {}))
    monkeypatch.setattr(finish.rebuild, 'pair_object', lambda *a: [('_f', 6, ['00500000'])])
    image = b'\xb8\x80\x00\x50\x00\xc3'
    monkeypatch.setattr(pefile, 'PE', lambda *a: SimpleNamespace(get_memory_mapped_image=lambda: image,
                                                              OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000)))
    path = tmp_path / 'test.map'; path.write_text('0001:00000000 _f 00400000 f linked:Native.obj\n')
    args = ('test', ['00500000'], owners, tmp_path, tmp_path/'test.exe', path)
    assert finish.linked_proofs(*args)[0]['code_exact_in_executable']
    image = b'\x90'*6
    assert not finish.linked_proofs(*args)[0]['code_exact_in_executable']
    image = b'\xb8\x80\x00\x50\x00\xc3'
    path.write_text('0001:00000000 _f 00400000 f test.obj\n')
    assert not finish.linked_proofs(*args)[0]['code_exact_in_executable']


def test_publication_preserves_checkout_and_deduplicates(tmp_path):
    bare, repo, folder = [tmp_path / name for name in ('origin.git', 'repo', 'proof')]
    def git(*args, cwd=None):
        return subprocess.check_output(['git', *args], cwd=cwd, stderr=subprocess.PIPE)
    git('init', '--bare', '--initial-branch=main', str(bare))
    git('init', '--initial-branch=main', str(repo))
    git('config', 'user.name', 'Tester', cwd=repo);git('config', 'user.email', 'tester@example.com', cwd=repo)
    package = repo / '2008-06/package.json';package.parent.mkdir()
    package.write_text('{"files":{}}')
    (repo / 'accepted.txt').write_text('accepted source stays')
    git('add', '.', cwd=repo);git('commit', '-m', 'baseline', cwd=repo)
    git('remote', 'add', 'origin', str(bare), cwd=repo);git('push', 'origin', 'main', cwd=repo)
    original = git('rev-parse', 'HEAD', cwd=repo)
    folder.mkdir();(folder / 'proof.json').write_text('{"verified":false}')
    args = (repo, folder, ['proof.json'], '2008-06/verification/test-batch', repo)
    first = finish.publish(*args);second = finish.publish(*args)
    assert first['verified'] and second['unchanged'] and first['commit'] == second['commit']
    assert git('rev-parse', 'HEAD', cwd=repo) == original
    assert (repo / 'accepted.txt').read_text() == 'accepted source stays'
    assert not (repo / '2008-06/verification').exists()
    assert git('rev-parse', 'origin/main', cwd=repo).decode().strip() == first['commit']
