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


def test_native_loop_forwards_parallelism_budgets_and_context(monkeypatch):
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
