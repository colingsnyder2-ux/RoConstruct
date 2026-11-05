import json
import sqlite3
import subprocess
import sys
import threading
from types import SimpleNamespace

import pytest

from roc import gui_worker, integration, native_collaboration_host, native_recovery, native_sweep


def test_class_exclusions_protect_other_agents_and_are_editable():
    tasks = [{'method': 'CMainFrame::f'}, {'method': 'RBX::HUMAN::f'},
             {'method': 'CRobloxView::f'}, {'method': 'RBX::Workspace::f'}]
    assert native_recovery.exclude_classes(tasks, 'CMainFrame, HUMAN, CRobloxView') == [tasks[3]]
    assert native_recovery.exclude_classes(tasks, '') == tasks
    config = dict(lease_mode='native', native_generation='agent', model='codex:gpt-6.1-terra',
                  workers=5, user='tester', server='localhost:8765', cloud_allowed=True)
    assert gui_worker.validate(config, check_model=False)['native_excluded_classes'] == 'CRobloxView,CMainFrame,HUMAN'
    with pytest.raises(ValueError, match='Excluded native classes'):
        gui_worker.validate(dict(config, native_excluded_classes='../unsafe'), check_model=False)


def test_probe_client_retries_transient_windows_read_lock(tmp_path):
    injection = '''import json,time,uuid
original_read = Path.read_text
def locked_once(path, *args, **kwargs):
    marker = path.parent / 'lock-tested'
    if path.suffix == '.json' and not marker.exists():
        marker.write_text('yes')
        raise PermissionError('temporary Windows sharing violation')
    return original_read(path, *args, **kwargs)
Path.read_text = locked_once
'''
    script = native_recovery.PROBE_CLIENT.replace('import json,time,uuid\n', injection, 1)
    (tmp_path/'check.py').write_text(script)
    broker = native_recovery.ProbeServer(1, lambda: False)
    broker.add(tmp_path, lambda: {'ok':True, 'target_exact':True, 'losses':[]}, 1)
    try:
        child = subprocess.run([sys.executable, 'check.py'], cwd=tmp_path, capture_output=True, text=True, timeout=10)
        assert child.returncode == 0, child.stderr
        assert json.loads(child.stdout)['target_exact'] and (tmp_path/'checks/lock-tested').exists()
    finally:
        broker.close()


def test_owner_mapped_helper_preserves_unit_and_rechecks(tmp_path, monkeypatch):
    original = 'namespace Helpers { int fresh(); }\n'
    added = 'int Helpers::fresh(){return 7;}\n'
    candidate = tmp_path / 'candidate.cpp'
    candidate.write_text(original + added)
    tree = tmp_path / 'tree'
    canonical = tree / 'App/util/A.cpp'
    canonical.parent.mkdir(parents=True)
    canonical.write_text('int A::f(){return 1;}\n')
    task = dict(method='Helpers::fresh', addr='00400000', add_method=True,
                canonical_file='App/util/A.cpp', canonical_append={'edits': [], 'suffix': '\n'})
    checked = []
    def recheck(proposal, ctx, texts, output, revision, log, recover):
        checked.append(proposal)
        assert recover and native_sweep.apply_edits(texts[proposal['file']], proposal['edits']).endswith(added + '\n')
        return proposal
    monkeypatch.setattr(native_sweep, 'recheck_proposal', recheck)
    record = dict(candidate=str(candidate), original=original, task=task)
    result = native_recovery.stage_submission(record, SimpleNamespace(tree=tree, overlay=tmp_path/'overlay'),
                                               {'revision': 'base'}, tmp_path/'out', lambda _: None)
    assert result['state'] == 'ready' and checked and canonical.read_text() == 'int A::f(){return 1;}\n', result
    task['canonical_file'] = '../../outside.cpp'
    assert native_recovery.stage_submission(record, SimpleNamespace(tree=tree, overlay=tmp_path/'overlay'),
                                             {'revision':'base'}, tmp_path/'out', lambda _: None)['state'] == 'pending-linkage'


def test_host_owner_mapping_changes_task_signature_and_rejects_unsafe_paths(tmp_path, monkeypatch):
    root = tmp_path / 'host'
    rel = 'rebuild/2008-06/native-classes/A.cpp'
    source = root / rel
    source.parent.mkdir(parents=True)
    source.write_text('int A::f(){return 1;}\n')
    headers = root / 'rebuild/2008-06/native-headers'
    headers.mkdir()
    (headers / 'A.h').write_text('struct A{int f();};')
    patches = root / 'rebuild/2008-06/patches'
    patches.mkdir()
    (patches / 'make_rbxgs_client.py').write_text('# fixture')
    (patches / 'rbxgs-client.json').write_text('{}')
    canonical = root / 'tools/rbxgs/Client/App/util/Helpers.cpp'
    canonical.parent.mkdir(parents=True)
    canonical.write_text('int Existing::keep(){return 1;}')
    store = SimpleNamespace(db=sqlite3.connect(tmp_path/'db', check_same_thread=False), lock=threading.Lock())
    promotions = integration.Promotions(store, root)
    task = dict(file=rel, method='A::f', addr='00400000', add_method=True)
    monkeypatch.setattr(native_recovery, 'nominations', lambda *a: [task])
    service = native_collaboration_host.Host(promotions)
    try:
        initial = service.catalog()
        task.update(canonical_file='App/util/Helpers.cpp', canonical_append={'edits': [], 'suffix': '\n'})
        service.cache_key = None
        updated = service.catalog()
        assert updated['owner_append_mapping'] == 1 and updated['revision'] == initial['revision']
        assert updated['tasks'][0]['signature'] != initial['tasks'][0]['signature']
        assert updated['tasks'][0]['integration_mapping'] == 'App/util/Helpers.cpp'
        task['canonical_file'] = '../../outside.cpp'
        service.cache_key = None
        with pytest.raises(ValueError, match='canonical unit'): service.catalog()
    finally:
        service.stop.set()
        service.wake.set()
        store.db.close()


def test_host_merge_is_not_recompiled_on_mapping_retry(tmp_path, monkeypatch):
    from roc import match, native_collaboration
    shared = tmp_path/'shared'
    rel = 'rebuild/2008-06/native-classes/A.cpp'
    source = shared/rel
    source.parent.mkdir(parents=True)
    source.write_text('int A::f(){return 2;}\n')
    task = dict(file=rel, method='A::f', addr='00400000', target='target', available=False,
                canonical_file='App/util/A.cpp', canonical_append={'edits': [], 'suffix':'stale'})
    claims = native_recovery.Claims(shared)
    record = dict(task=task, candidate=str(source), original='int A::f(){return 1;}\n', baseline=[],
                  model='codex:gpt-6.1-terra', merge={'state':'merged'}, host_merge_counted=True,
                  collaboration_submission={'job':'host-job'})
    owner = claims.take('key', 'signature', record)
    claims.update('key', owner, 'remote-submitted', record)
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(shared))
    monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT', str(tmp_path/'proofs'))
    class Api:
        token = 'test'
        def __init__(self, *args): pass
        def call(self, *args, **kwargs): return {'revision':'base', 'features':{'native_recovery_collaboration':True}}
        def close(self): pass
    class Remote:
        def __init__(self, *args): pass
        def snapshot(self, *args): return {'workspace':str(shared), 'files':{rel:source.read_text()}, 'tasks':[task], 'classes':['A']}
        def status(self, *args): return {'state':'merged'}
        def close(self): pass
    monkeypatch.setattr(native_recovery.worker, 'Api', Api)
    monkeypatch.setattr(native_collaboration, 'Remote', Remote)
    monkeypatch.setattr(native_sweep, 'native_context', lambda *a: SimpleNamespace(names={}, by_addr={}, includes=[]))
    monkeypatch.setattr(native_sweep, 'Matcher', lambda *a: None)
    monkeypatch.setattr(match, '_functions', lambda *a: {})
    monkeypatch.setattr(native_recovery, 'merge', lambda *a, **kw: pytest.fail('Already merged source was recompiled'))
    def stage(record, *args, **kwargs):
        assert 'canonical_append' not in record['task']  # Older host does not bind this metadata.
        return {'state':'pending-mapping'}
    monkeypatch.setattr(native_recovery, 'stage_submission', stage)
    config = dict(gui_worker.DEFAULTS, workers=5, native_agent_submit=True,
                  model='codex:gpt-6.1-terra', user='tester', server='localhost:8765', cloud_allowed=True)
    result = native_recovery.run(config, gui_worker.Control(config, lambda *a, **kw: None), lambda *a, **kw: None)
    assert result['canonical_blocked'] == 1 and result['merged'] == 0
