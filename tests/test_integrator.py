import json
import subprocess
import threading
import time
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import Mock
import io
import urllib.error

import pytest

from roc import gui_worker, integration, integrator, native_sweep, providers


def test_codex_models_follow_cli_catalog_and_hide_internal_models(tmp_path, monkeypatch):
    monkeypatch.setenv('CODEX_HOME', str(tmp_path))
    path = tmp_path / 'models_cache.json'
    assert providers.codex_models() == ['default']
    path.write_text(json.dumps({'identity': 'private account metadata', 'models': [
        {'slug': 'gpt-6.1-sol', 'visibility': 'list'},
        {'slug': 'gpt-6-astra', 'visibility': 'list'},
        {'slug': 'gpt-reserve', 'visibility': 'hide'},
        {'slug': 'gpt-6.1-sol', 'visibility': 'list'},
    ]}), encoding='utf-8')
    assert providers.providers()['codex']['defaults'] == ['default', 'gpt-6.1-sol', 'gpt-6-astra']
    path.write_text('{invalid', encoding='utf-8')
    assert providers.codex_models() == ['default']


def test_insufficient_balance_is_not_retried_or_exposed(monkeypatch):
    response = urllib.error.HTTPError('https://api.deepseek.com/chat/completions', 402, 'Payment Required', {},
                                     io.BytesIO(b'{"error":"insufficient balance private-account-details"}'))
    send = Mock(side_effect=response)
    monkeypatch.setattr(providers.urllib.request, 'urlopen', send)
    with pytest.raises(providers.ProviderError) as failure:
        providers._post('https://api.deepseek.com/chat/completions', {}, {}, 5)
    assert failure.value.category == 'provider_auth'
    assert 'insufficient provider balance' in str(failure.value)
    assert 'private-account' not in str(failure.value)
    send.assert_called_once()


@pytest.mark.parametrize('provider,output', [
    ('codex', '\n'.join(json.dumps(row) for row in [
        {'type': 'item.completed', 'item': {'type': 'agent_message', 'text': 'anchored edit'}},
        {'type': 'turn.completed', 'usage': {'input_tokens': 12, 'output_tokens': 4}}])),
    ('claude', json.dumps({'result': 'anchored edit', 'usage': {'input_tokens': 12, 'output_tokens': 4}})),
])
def test_cli_provider_uses_signed_in_cli_and_returns_usage(monkeypatch, provider, output):
    monkeypatch.setattr(providers.shutil, 'which', lambda name: name)
    process = Mock(returncode=0)
    process.communicate.return_value = (output, '')
    start = Mock(return_value=process)
    monkeypatch.setattr(providers.subprocess, 'Popen', start)
    result = providers.generate(provider + ':default', [{'role': 'user', 'content': 'fix source'}],
                                {'allow_cloud': True, 'retries': 0})
    assert result.text == 'anchored edit'
    assert (result.input_tokens, result.output_tokens) == (12, 4)
    argv = start.call_args.args[0]
    assert '--model' not in argv
    assert Path(start.call_args.kwargs['cwd']) != providers.ROOT
    if provider == 'codex':
        assert argv[argv.index('--sandbox') + 1] == 'read-only'
    else:
        assert argv[argv.index('--tools') + 1] == ''
    assert 'fix source' in process.communicate.call_args.args[0]


def test_cli_budget_and_consent_are_enforced(monkeypatch):
    start = Mock()
    monkeypatch.setattr(providers.subprocess, 'Popen', start)
    for options in ({}, {'allow_cloud': True, 'budget': providers.CloudBudget(cost=1)}):
        with pytest.raises(providers.ProviderError):
            providers.generate('codex:default', 'prompt', options)
    start.assert_not_called()


def test_cli_failure_does_not_print_provider_output(monkeypatch):
    monkeypatch.setattr(providers.shutil, 'which', lambda name: name)
    process = Mock(returncode=1)
    process.communicate.return_value = ('private provider content', 'secret auth details')
    monkeypatch.setattr(providers.subprocess, 'Popen', Mock(return_value=process))
    with pytest.raises(providers.ProviderError, match='check CLI sign-in') as failure:
        providers.generate('claude:sonnet', 'prompt', {'allow_cloud': True, 'retries': 0})
    assert 'secret' not in str(failure.value)
    assert 'private' not in str(failure.value)


def test_workspace_preserves_server_and_separates_writable_sources(tmp_path, monkeypatch):
    for name in ('roc', 'research', 'rebuild/2008-06/patches', 'clients/2008-06', 'tools', 'work/2008-06'):
        (tmp_path / name).mkdir(parents=True, exist_ok=True)
    (tmp_path / 'roc.py').write_text('# runtime')
    (tmp_path / 'roc/__init__.py').write_text('')
    (tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py').write_text('# original')
    (tmp_path / 'clients/clients.json').write_text('{}')
    (tmp_path / 'work/2008-06/functions.jsonl').write_text('{}')
    (tmp_path / 'work/server.db').write_text('server only')
    monkeypatch.setattr(integrator, 'ROOT', tmp_path)
    links = []
    monkeypatch.setattr(integrator, 'link_directory', lambda source, target: links.append((source, target)))
    folder = integrator.workspace(log=lambda _: None)
    assert not (folder / 'work/server.db').exists()
    assert (folder / 'work/2008-06/functions.jsonl').read_text() == '{}'
    private = folder / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    private.write_text('# private edit')
    assert (tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py').read_text() == '# original'
    assert len(links) == 2


@pytest.fixture
def private_session_root(tmp_path, monkeypatch):
    for name in ('roc','research','rebuild/2008-06/patches','clients','work/2008-06'):
        (tmp_path/name).mkdir(parents=True)
    (tmp_path/'roc.py').write_text('# runtime')
    (tmp_path/'roc/__init__.py').write_text('# first runtime')
    (tmp_path/'rebuild/2008-06/patches/make_rbxgs_client.py').write_text('# original')
    monkeypatch.setattr(integrator,'ROOT',tmp_path)
    monkeypatch.setenv('ROC_TASK_ID','123456abcdef')
    return tmp_path


def test_dashboard_restart_reuses_private_proofs_outputs_and_edits_but_refreshes_runtime(private_session_root):
    root = private_session_root
    with integrator.session_workspace(lambda _:None) as first:
        generator = first/'rebuild/2008-06/patches/make_rbxgs_client.py'
        generator.write_text('# unsent private edit')
        cache = first/'work/cached-proof.json'
        cache.parent.mkdir(parents=True,exist_ok=True)
        cache.write_text('{"proof":"saved"}')
    (root/'roc/__init__.py').write_text('# updated runtime')
    with integrator.session_workspace(lambda _:None) as second:
        assert second == first
        assert generator.read_text() == '# unsent private edit'
        assert cache.read_text() == '{"proof":"saved"}'
        assert (second/'roc/__init__.py').read_text() == '# updated runtime'
    assert (root/'rebuild/2008-06/patches/make_rbxgs_client.py').read_text() == '# original'


def test_different_dashboard_sessions_keep_independent_workspaces(private_session_root, monkeypatch):
    with integrator.session_workspace(lambda _:None) as first:pass
    monkeypatch.setenv('ROC_TASK_ID','abcdef123456')
    with integrator.session_workspace(lambda _:None) as second:pass
    assert first != second


def test_same_session_cannot_be_opened_twice(private_session_root):
    with integrator.session_workspace(lambda _:None):
        with pytest.raises(RuntimeError,match='already active'):
            with integrator.session_workspace(lambda _:None):pass


def test_session_marker_cannot_overwrite_another_checkout(private_session_root):
    root = private_session_root
    markers = root/'work/integrator-sessions'
    markers.mkdir(parents=True)
    (markers/'123456abcdef.json').write_text(json.dumps({'workspace':str(root)}))
    with pytest.raises(ValueError,match='outside'):
        with integrator.session_workspace(lambda _:None):pass


def test_session_marker_cannot_reuse_another_sessions_private_tree(private_session_root, monkeypatch):
    root = private_session_root
    with integrator.session_workspace(lambda _:None) as first:pass
    markers = root/'work/integrator-sessions'
    monkeypatch.setenv('ROC_TASK_ID','abcdef123456')
    (markers/'abcdef123456.json').write_text(json.dumps({'workspace':str(first)}))
    with pytest.raises(ValueError,match='different integrator session'):
        with integrator.session_workspace(lambda _:None):pass


def test_controller_reader_preserves_coalesced_messages_and_split_utf8(monkeypatch):
    content = '{"config":{}}\n{"action":"update","label":"☃"}\n{"action":"stop"}'
    data = content.encode('utf-8')
    split = data.index('☃'.encode())+1
    pieces = iter([data[:split],data[split:],b''])
    monkeypatch.setattr(gui_worker.os,'read',lambda *_:next(pieces))
    stream = SimpleNamespace(fileno=lambda:0)
    commands = gui_worker.command_lines(stream)
    assert json.loads(next(commands)) == {'config':{}}
    assert [json.loads(line) for line in commands] == [{'action':'update','label':'☃'},{'action':'stop'}]


def test_native_loop_forwards_parallelism_budgets_and_context(monkeypatch):
    monkeypatch.setattr(providers, 'available', lambda _: True)
    monkeypatch.setattr('roc.rebuild_install.prepare', lambda **kwargs: None)
    config = {**gui_worker.DEFAULTS, 'lease_mode': 'native', 'client': '2008-06', 'model': 'codex:default',
              'workers': 8, 'user': 'tester', 'server': 'localhost:8765', 'cloud_allowed': True,
              'cloud_concurrency': 'auto', 'native_batch_files': 100, 'max_cloud_requests': 12}
    events, calls = [], []
    control = gui_worker.Control(config, lambda event, **fields: events.append((event, fields)))
    def run(spec, name, **kwargs):
        calls.append((dict(spec['native_sweep']), kwargs))
        if len(calls) == 2: control.command({'action': 'stop'})
        return {'files_tried': ['App/test.cpp'] if len(calls) == 1 else [], 'state': 'no-proposals'}
    monkeypatch.setattr(native_sweep, 'run', run)
    monkeypatch.setattr(gui_worker.worker, 'save_settings', lambda **kwargs: None)
    monkeypatch.setattr(integration, 'command', lambda _: None)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event, fields)))
    options = calls[0][0]
    assert calls[0][1]['jobs'] == 8
    assert options['wait'] is False
    assert options['max_files'] == 100 and options['context'] == 'methods'
    assert options['provider_options']['budget'] is control.budget
    assert calls[1][0]['exclude_files'] == ['App/test.cpp']
    control.command({'action': 'stop'})
    assert not options['provider_options']['before_request']()


def test_model_jobs_parallel_but_compilers_bounded(tmp_path, monkeypatch):
    files = {f'App/file{n}.cpp': 'void A::f() {}' for n in range(8)}
    homes = {name: ['00400000'] for name in files}
    monkeypatch.setattr(native_sweep, 'target_files', lambda *args: homes)
    obj = tmp_path / 'test.obj'
    obj.write_bytes(b'object')
    lock = threading.Lock()
    counts = {'compiling': 0, 'compile_peak': 0, 'model': 0, 'model_peak': 0}
    def compile_source(*args):
        with lock:
            counts['compiling'] += 1
            counts['compile_peak'] = max(counts['compile_peak'], counts['compiling'])
        time.sleep(.01)
        with lock:
            counts['compiling'] -= 1
        return {'ok': True, 'object': str(obj)}
    def proposal(*args, **kwargs):
        with lock:
            counts['model'] += 1
            counts['model_peak'] = max(counts['model_peak'], counts['model'])
        time.sleep(.04)
        with lock:
            counts['model'] -= 1
        return None, []
    monkeypatch.setattr(native_sweep, 'model_proposal', proposal)
    events = []
    native_sweep.model_discovery({'llm': 'codex:default', 'compile_workers': 2,
        'provider_options': {'event': lambda kind, **fields: events.append((kind, fields))}}, files, {'00400000'}, set(), {},
        SimpleNamespace(scan=lambda _: []), tmp_path, 8, lambda _: None, compile_source, {'00400000': {'symbol': 'f'}})
    assert counts['compile_peak'] <= 2
    assert counts['model_peak'] > 1
    assert len([row for row in events if row[0] == 'native_started']) == 8
    assert len([row for row in events if row[0] == 'native_result']) == 8
    assert len({row[1]['slot'] for row in events}) > 1


def test_native_loop_counts_async_acceptance_and_stops_at_budget(monkeypatch):
    monkeypatch.setattr(providers, 'available', lambda _: True)
    monkeypatch.setattr('roc.rebuild_install.prepare', lambda **kwargs: None)
    config = {**gui_worker.DEFAULTS, 'lease_mode': 'native', 'client': '2008-06', 'model': 'codex:default',
              'workers': 2, 'user': 'tester', 'server': 'localhost:8765', 'cloud_allowed': True,
              'max_cloud_requests': 1}
    events = []
    control = gui_worker.Control(config, lambda *args, **kwargs: None)
    calls = []
    def run(*args, **kwargs):
        calls.append(1)
        if len(calls) == 2:
            control.budget.requests = 1
        return {'files_tried': ['App/test.cpp'], 'job': 'queued'} if len(calls) == 1 else {'files_tried': []}
    api = Mock()
    api.call.return_value = {'jobs': [{'state': 'accepted', 'receipt': {'credits': 3}}]}
    monkeypatch.setattr(gui_worker.worker, 'Api', lambda *args: api)
    monkeypatch.setattr(gui_worker.worker, 'load_settings', lambda: {})
    monkeypatch.setattr(gui_worker.worker, 'save_settings', lambda **kwargs: None)
    monkeypatch.setattr(integration, 'command', lambda _: None)
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event, fields)))
    assert control.matched == 3
    assert control.stopping
    assert len(calls) == 2
    assert any('accepted' in fields.get('message', '') for _, fields in events)


@pytest.fixture
def continuous_native(monkeypatch, tmp_path):
    monkeypatch.setattr(providers, 'available', lambda _: True)
    monkeypatch.setattr('roc.rebuild_install.prepare', lambda **kwargs: None)
    monkeypatch.setattr(gui_worker.worker, 'save_settings', lambda **kwargs: None)
    monkeypatch.setattr(gui_worker.worker, 'load_settings', lambda: {})
    monkeypatch.setattr(integration, 'command', lambda _: None)
    monkeypatch.setattr(native_sweep, 'ROOT', tmp_path)
    api = Mock()
    api.call.return_value = {'clients':[{'client':'2008-06','matched':100,'integrated':50,'functions':200}]}
    monkeypatch.setattr(gui_worker.worker, 'Api', lambda *args: api)
    config = {**gui_worker.DEFAULTS, 'lease_mode':'native', 'client':'2008-06',
              'model':'codex:default', 'workers':2, 'user':'tester', 'server':'localhost:8765', 'cloud_allowed':True}
    events = []
    control = gui_worker.Control(config, lambda *args, **kwargs: None)
    clock = [100.]
    monkeypatch.setattr(gui_worker.time, 'monotonic', lambda: clock[0])
    monkeypatch.setattr(control, 'wait', lambda seconds: clock.__setitem__(0, clock[0]+seconds))
    return config, control, events, tmp_path


def test_native_coordinator_reports_one_stage_without_duplicate_worker_log(continuous_native, monkeypatch):
    config, control, events, _ = continuous_native
    message = 'Linked preflight baseline: building'
    def run(*args, **kwargs):
        kwargs['log'](message)
        control.command({'action':'stop'})
        return {'files_tried':[]}
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields:events.append((event, fields)))
    matching = [(event, fields) for event, fields in events if fields.get('message') == message]
    assert matching == [('stage', {'message':message, 'task_status':'running'})]


def test_baseline_advance_preserves_scheduling_and_rechecks_without_error_count(continuous_native, monkeypatch):
    config, control, events, root = continuous_native
    output = root/'work/research/native-model-2008'
    output.mkdir(parents=True)
    calls = []
    def run(spec, *args, **kwargs):
        calls.append(dict(spec['native_sweep']))
        if len(calls) == 1:
            (output/'summary.json').write_text(json.dumps(dict(files_tried=['App/A.cpp'],base_revision='old',pending_files={'App/A.cpp':20})))
            raise native_sweep.BaselineAdvanced('Saved proofs queued')
        control.command({'action':'stop'})
        return dict(files_tried=[],base_revision='new')
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields:events.append((event,fields)))
    assert calls[1]['resume_saved'] and calls[1]['rolling_workers']
    assert calls[1]['file_offsets'] == {'App/A.cpp':4}
    assert calls[1]['retry_targets'] == {'App/A.cpp':20} and calls[1]['tried_revision'] == 'old'
    assert control.errors == 0
    assert any('without AI' in fields.get('message','') for _,fields in events)


def test_exhausted_discovery_restarts_with_rotated_targets_without_changed_stats(continuous_native, monkeypatch):
    config, control, events, _ = continuous_native
    calls = []
    def run(spec, *args, **kwargs):
        calls.append(dict(spec['native_sweep']))
        if len(calls) == 3:control.command({'action':'stop'})
        return {'files_tried':['App/A.cpp']} if len(calls) == 1 else {'files_tried':[]}
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event,fields)))
    assert len(calls) == 3 and not control.paused
    assert calls[1]['exclude_files'] == ['App/A.cpp']
    assert calls[2]['exclude_files'] == [] and calls[2]['target_offset'] == 4
    assert any('rotated pending' in fields.get('message','') for _,fields in events)


@pytest.mark.parametrize('failure', [ValueError('Linked ownership regression; gate rejected candidate'),
                                    gui_worker.worker.ApiFailure('bad_request','Submission rejected')])
def test_rejected_preflight_preserves_proof_and_continues_other_files(continuous_native, monkeypatch, failure):
    config, control, events, root = continuous_native
    output = root/'work/research/native-model-2008'
    output.mkdir(parents=True)
    (output/'summary.json').write_text(json.dumps({'files_tried':['App/Rejected.cpp']}))
    (output/'proposals.json').write_text('[{"saved":"proof"}]')
    calls = []
    def run(spec, *args, **kwargs):
        calls.append(dict(spec['native_sweep']))
        if len(calls) == 1:raise failure
        control.command({'action':'stop'})
        return {'files_tried':[]}
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event,fields)))
    assert calls[1]['exclude_files'] == ['App/Rejected.cpp'] and control.errors == 1
    assert json.loads((output/'proposals.json').read_text()) == [{'saved':'proof'}]
    assert any('Continuing in 30s' in fields.get('message','') for _,fields in events)


def test_permanent_provider_failure_still_stops_continuous_discovery(continuous_native, monkeypatch):
    config, control, events, _ = continuous_native
    monkeypatch.setattr(native_sweep, 'run', Mock(side_effect=providers.ProviderError('provider_auth','HTTP 401')))
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event,fields)))
    assert control.stopping and control.errors == 0


def test_startup_server_outage_resumes_without_repeating_setup(continuous_native, monkeypatch):
    config, control, events, _ = continuous_native
    syncing = Mock(side_effect=[gui_worker.worker.ApiFailure('offline','down'),None])
    monkeypatch.setattr(integration, 'command', syncing)
    def run(*args, **kwargs):
        control.command({'action':'stop'})
        return {'files_tried':[]}
    monkeypatch.setattr(native_sweep, 'run', run)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event,fields)))
    assert syncing.call_count == 2
    assert any('Waiting for server' in fields.get('message','') for _,fields in events)


def test_server_outage_obeys_two_hour_deadline(continuous_native, monkeypatch):
    config, control, events, _ = continuous_native
    clock = [100.]
    monkeypatch.setattr(gui_worker.time,'monotonic',lambda:clock[0])
    monkeypatch.setattr(control,'wait',lambda _:clock.__setitem__(0,clock[0]+3600))
    run = Mock(side_effect=gui_worker.worker.ApiFailure('server_fail','HTTP 503'))
    monkeypatch.setattr(native_sweep,'run',run)
    gui_worker.native_loop(config, control, lambda event, **fields: events.append((event,fields)))
    assert control.stopping and run.call_count == 3
    assert any('two hours' in fields.get('message','') for _,fields in events)


def test_unchanged_native_sync_does_not_spawn_generator(tmp_path, monkeypatch):
    import hashlib
    folder = tmp_path / 'rebuild/2008-06/patches'
    folder.mkdir(parents=True)
    generator = folder / 'make_rbxgs_client.py'
    generator.write_bytes(b'pass\n')
    (folder / 'rbxgs-client.json').write_text('{}')
    base = {'generator': hashlib.sha256(generator.read_bytes()).hexdigest(), 'overlay': {}, 'accepted': [], 'revision': 'current'}
    spawn = Mock(side_effect=AssertionError('unchanged baseline must not launch a generator'))
    monkeypatch.setattr(integration, 'run_generator', spawn)
    assert integration.sync_client_baseline(tmp_path, base)
    assert json.loads((tmp_path / 'work/integration-client/baseline.json').read_text())['revision'] == 'current'
    spawn.assert_not_called()


def test_generator_timeout_reports_liveness_and_terminates_child(tmp_path, monkeypatch, capsys):
    process = Mock(returncode=None)
    process.communicate.side_effect = [subprocess.TimeoutExpired('generator',10), (b'', None)]
    monkeypatch.setattr(integration.subprocess, 'Popen', Mock(return_value=process))
    with pytest.raises(TimeoutError, match='exceeded'):
        integration.run_generator(tmp_path / 'generator.py', tmp_path, timeout=0)
    process.kill.assert_called_once()
    assert 'still running' in capsys.readouterr().out
