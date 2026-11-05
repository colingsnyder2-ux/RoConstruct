from roc import native_recovery
from roc import gui_worker, match, native_sweep
from types import SimpleNamespace
import json


def test_class_priority_groups_methods_and_favors_mapped_classes():
    tasks = [
        {'method': 'B::first', 'integration_mapping': None},
        {'method': 'A::first', 'integration_mapping': 'App/A.cpp'},
        {'method': 'B::second', 'integration_mapping': None},
        {'method': 'A::second', 'integration_mapping': None},
        {'method': 'C::first', 'integration_mapping': 'App/C.cpp'},
    ]
    assert [(name, item['method']) for name, item in native_recovery.prioritize_classes(tasks)] == [
        ('A', 'A::first'), ('A', 'A::second'), ('C', 'C::first'),
        ('B', 'B::first'), ('B', 'B::second'),
    ]
    order = native_recovery.prioritize_classes(tasks, [{'class_name':'A', 'status':'needs-layout-owner',
                                                         'reason':'untrusted text; never execute'}])
    assert [name for name, _ in order] == ['C', 'B', 'B', 'A', 'A']


def test_credit_count_excludes_already_owned_module_matches():
    assert native_recovery.accepted_credits({'gains': ['a', 'b', 'c'], 'new_distinct': ['b', 'c'], 'credits': 2}) == 2
    assert native_recovery.accepted_credits({'gains': ['a', 'b'], 'new_distinct': ['b', 'b']}) == 1
    assert native_recovery.accepted_credits({'gains': ['a']}) == 0


def test_native_asm_is_offered_only_when_installed(tmp_path):
    assert native_recovery.native_asm_argv(tmp_path, '0057db00') is None
    (tmp_path / 'roc').mkdir()
    (tmp_path / 'roc.py').touch()
    (tmp_path / 'roc/native_asm.py').touch()
    command = native_recovery.native_asm_argv(tmp_path, '0057db00')
    assert command[1:] == [str(tmp_path / 'roc.py'), 'native-asm', '2008-06', '0057db00']


def test_only_recorded_preflight_losses_split_and_survive_restart(tmp_path):
    claims = native_recovery.Claims(tmp_path)
    group = []
    for index in range(4):
        key = str(index)
        record = {'task': {'method': 'A::f' + key}, 'candidate': key + '.cpp'}
        owner = claims.take(key, 'revision', record)
        claims.update(key, owner, 'remote-submitted', record)
        group.append((key, owner, record))
    receipt = tmp_path / 'receipt.json'
    receipt.write_text(json.dumps({'accepted': False, 'uncovered_losses': ['0057db00']}))
    assert not native_recovery.split_preflight_loss(claims, group, ValueError('link failed'), 'remote-submitted')
    assert native_recovery.split_preflight_loss(claims, group,
        ValueError('gate failed; lost exact functions: 0057db00; receipt: ' + str(receipt)), 'remote-submitted')
    restored = native_recovery.Claims(tmp_path).remote_submitted()
    partitions = {}
    for key, _, record in restored:
        partitions.setdefault(record['batch_partition'], []).append(key)
        assert record['batch_losses'] == ['0057db00'] and record['batch_loss_receipt'] == str(receipt)
    assert sorted(sorted(keys) for keys in partitions.values()) == [['0', '1'], ['2', '3']]
    assert not native_recovery.split_preflight_loss(claims, group[:1],
        ValueError('gate failed; lost exact functions: 0057db00; receipt: ' + str(receipt)), 'remote-submitted')
    receipt.write_text(json.dumps({'accepted': True, 'uncovered_losses': ['0057db00']}))
    assert not native_recovery.split_preflight_loss(claims, group,
        ValueError('gate failed; lost exact functions: 0057db00; receipt: ' + str(receipt)), 'remote-submitted')


def test_split_batches_wait_for_server_before_next_preflight(tmp_path, monkeypatch):
    shared = tmp_path / 'shared'
    rel = 'rebuild/2008-06/native-classes/A.cpp'
    source = shared / rel
    source.parent.mkdir(parents=True)
    source.write_text('int A::f(){return 1;}\nint A::g(){return 2;}\n')
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(shared))
    monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT', str(tmp_path/'proofs'))
    claims = native_recovery.Claims(shared)
    for index, method in enumerate(('A::f', 'A::g')):
        task = dict(file=rel, method=method, addr='0040000' + str(index))
        record = dict(task=task, candidate=str(source), original=source.read_text(),
                      existing_source=True, baseline=[], model='codex:gpt-6-luna')
        owner = claims.take(str(index), 'revision', record)
        claims.update(str(index), owner, 'recovered', record)
    state = {'job': 'queued'}
    class Api:
        def __init__(self, *args): pass
        def call(self, path, *args, **kwargs):
            if path.startswith('/v1/integration?id='):
                return {'jobs': [{'state': state['job'], 'receipt': {'credits': 1}}]}
            return {'revision':'base'}
        def close(self): pass
    monkeypatch.setattr(native_recovery.worker, 'Api', Api)
    monkeypatch.setattr(native_sweep, 'native_context', lambda *a: SimpleNamespace(names={}, by_addr={}, includes=[]))
    monkeypatch.setattr(native_sweep, 'Matcher', lambda *a: None)
    monkeypatch.setattr(match, '_functions', lambda *a: {})
    monkeypatch.setattr(native_recovery, 'nominations', lambda *a: [])
    monkeypatch.setattr(native_recovery, 'stage_submission', lambda *a, **kw: {'state':'mapped'})
    receipt = tmp_path/'preflight.json'
    receipt.write_text(json.dumps({'accepted': False, 'uncovered_losses': ['0057db00']}))
    calls = []
    def submit(records, *args):
        calls.append(len(records))
        if len(records) > 1:
            raise ValueError('lost; lost exact functions: 0057db00; receipt: ' + str(receipt))
        return {'job':'job' + str(len(calls)), 'submitted_addresses':[records[0]['task']['addr']]}
    monkeypatch.setattr(native_recovery, 'submit_batch', submit)
    config = dict(gui_worker.DEFAULTS, workers=5, native_agent_submit=True,
                  model='codex:gpt-6-luna', user='tester', server='localhost:8765', cloud_allowed=True)
    control = gui_worker.Control(config, lambda *a, **kw: None)
    native_recovery.run(config, control, lambda *a, **kw: None)
    assert calls == [2, 1]
    native_recovery.run(config, control, lambda *a, **kw: None)
    assert calls == [2, 1]
    state['job'] = 'accepted'
    native_recovery.run(config, control, lambda *a, **kw: None)
    assert calls == [2, 1, 1] and control.matched == 1


def test_recovery_fills_five_slots_across_prioritized_classes(tmp_path, monkeypatch):
    shared = tmp_path / 'shared'
    rel = 'rebuild/2008-06/native-classes/A.cpp'
    source = shared / rel
    source.parent.mkdir(parents=True)
    source.write_text('int A::f(){return 1;}\nint A::g(){return 2;}\nint B::f(){return 3;}\nint B::g(){return 4;}\nint C::f(){return 5;}\n')
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(shared))
    monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT', str(tmp_path / 'proofs'))

    class Api:
        def __init__(self, *args): pass
        def call(self, *args, **kwargs): return {'revision': 'base'}
        def close(self): pass

    monkeypatch.setattr(native_recovery.worker, 'Api', Api)
    monkeypatch.setattr(native_sweep, 'native_context', lambda *a: SimpleNamespace(names={}, by_addr={}, includes=[]))
    monkeypatch.setattr(native_sweep, 'Matcher', lambda *a: None)
    monkeypatch.setattr(match, '_functions', lambda *a: {})
    tasks = [dict(file=rel, method=name, addr=addr) for name, addr in
             [('A::f', '00400000'), ('A::g', '00400001'), ('B::f', '00400002'),
              ('B::g', '00400003'), ('C::f', '00400004')]]
    monkeypatch.setattr(native_recovery, 'nominations', lambda *a: tasks)
    def compile(root, *args, **kwargs):
        obj = root / 'proof.obj'
        obj.write_bytes(b'original object')
        return dict(ok=True, target_exact=True, hits=[], object=str(obj))
    monkeypatch.setattr(native_recovery, 'compile_probe', compile)
    monkeypatch.setattr(native_recovery, 'target_proof', lambda *a: dict(target_exact=True, diff=''))
    config = dict(gui_worker.DEFAULTS, workers=5, native_agent_submit=False,
                  model='codex:gpt-6-luna', user='tester', server='localhost:8765', cloud_allowed=True)
    control = gui_worker.Control(config, lambda *a, **kw: None)
    first = native_recovery.run(config, control, lambda *a, **kw: None)
    second = native_recovery.run(config, control, lambda *a, **kw: None)
    assert (first['attempted'], first['already_exact']) == (5, 5)
    assert (second['attempted'], second['already_exact']) == (0, 0)
    assert control.budget.requests == 0


def test_gui_reports_session_credits_and_start_time(monkeypatch):
    from roc import integration, providers
    config = dict(gui_worker.DEFAULTS, lease_mode='native', native_generation='agent', workers=1,
                  model='codex:gpt-6-luna', user='tester', server='localhost:8765', cloud_allowed=True)
    control = gui_worker.Control(config, lambda *a, **kw: None)
    monkeypatch.setattr(providers, 'available', lambda _: True)
    monkeypatch.setattr('roc.rebuild_install.prepare', lambda **kw: None)
    monkeypatch.setattr(gui_worker.worker, 'save_settings', lambda **kw: None)
    monkeypatch.setattr(integration, 'command', lambda _: None)
    def run(current, ctl, emit):
        ctl.matched = 2
        ctl.command({'action': 'stop'})
        return {'attempted': 0, 'accepted': 1, 'accepted_credits': 2}
    monkeypatch.setattr(native_recovery, 'run', run)
    events = []
    gui_worker.native_loop(config, control, lambda event, **kw: events.append((event, kw)))
    report = next(row for event, row in events if event == 'native_recovery')
    assert report['session_started'] == control.started_timestamp
    assert report['session_credits'] == 2 and report['credits_per_hour'] > 0
