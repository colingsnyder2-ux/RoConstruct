import io
import threading
import urllib.error
from types import SimpleNamespace
from unittest.mock import Mock

import pytest

from roc import gui_worker, native_sweep, providers


@pytest.mark.parametrize('model,remote', [
    ('nvidia/nemotron-3-ultra-550b-a55b', 'nvidia/nemotron-3-ultra-550b-a55b'),
    ('nvidia:nvidia/nemotron-3-ultra-550b-a55b', 'nvidia/nemotron-3-ultra-550b-a55b'),
    ('nvidia/qwen/qwen-model', 'qwen/qwen-model'),
    ('openai/gpt-example', 'gpt-example'),
])
def test_cloud_model_namespace_is_preserved(model, remote):
    assert providers.parse_model(model)[1] == remote


@pytest.mark.parametrize('status,category', [(401, 'provider_auth'), (403, 'provider_auth'), (404, 'provider_model')])
def test_permanent_http_failure_keeps_reason_and_never_opens_retry_circuit(monkeypatch, status, category):
    monkeypatch.setenv('NVIDIA_API_KEY', 'test-key')
    response = urllib.error.HTTPError('https://integrate.api.nvidia.com/v1/chat/completions', status, '', {},
                                     io.BytesIO(b'private account secret'))
    send = Mock(side_effect=response)
    sleep = Mock()
    monkeypatch.setattr(providers.urllib.request, 'urlopen', send)
    monkeypatch.setattr(providers.time, 'sleep', sleep)
    gate = providers.CloudGate(failures=1)
    for _ in range(3):
        with pytest.raises(providers.ProviderError) as failure:
            providers.generate('nvidia/nemotron-3-ultra-550b-a55b', 'tiny request',
                               {'allow_cloud': True, 'retry_forever': True, 'gate': gate})
        assert failure.value.category == category
        assert failure.value.status == status
        assert 'private' not in str(failure.value)
        if status == 401:
            assert 'NVIDIA_API_KEY' in str(failure.value)
        if status == 404:
            assert 'nvidia/nemotron-3-ultra-550b-a55b' in str(failure.value)
        gate.reset('nvidia')
    send.assert_called_once()
    sleep.assert_not_called()


def test_queued_gate_waiter_gets_original_auth_failure():
    gate = providers.CloudGate(1)
    lock = gate.enter('nvidia')
    outcomes = []
    def waiting():
        try:
            gate.enter('nvidia')
        except providers.ProviderError as error:
            outcomes.append((error.category, error.status))
    thread = threading.Thread(target=waiting)
    thread.start()
    gate.disable('nvidia', providers.ProviderError('provider_auth', 'HTTP 401', 401))
    lock.release()
    thread.join(2)
    assert outcomes == [('provider_auth', 401)]


@pytest.mark.parametrize('thinking,effort,expected', [('disabled', None, 'none'), ('enabled', 'low', 'medium'),
                                                  ('auto', 'high', 'high')])
def test_nemotron_ultra_uses_supported_reasoning_flags(monkeypatch, thinking, effort, expected):
    monkeypatch.setenv('NVIDIA_API_KEY', 'test-key')
    send = Mock(return_value=({'choices': [{'message': {'content': 'ok'}}]}, {}))
    monkeypatch.setattr(providers, '_post', send)
    providers.generate('nvidia/nemotron-3-ultra-550b-a55b', 'tiny request',
                       {'allow_cloud': True, 'thinking': thinking, 'reasoning_effort': effort})
    body = send.call_args.args[1]
    assert body['model'] == 'nvidia/nemotron-3-ultra-550b-a55b'
    assert body['reasoning_effort'] == expected
    assert 'thinking' not in body


def test_opencode_integrator_requests_edit_blocks_without_cpp_only_instruction(monkeypatch):
    monkeypatch.setattr(providers.shutil, 'which', lambda name: name)
    captured = []
    def run(argv, stdin, timeout):
        from pathlib import Path
        captured.append(Path(argv[argv.index('--file') + 1]).read_text())
        assert stdin == ''
        assert argv[-1].startswith('Follow the attached task exactly')
        return 0, '{"type":"text","part":{"text":"anchored edits"}}'
    monkeypatch.setattr(providers, '_opencode_run', run)
    providers.generate('opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b', 'edit native C++',
                       {'allow_cloud': True, 'edit_blocks': True})
    prompt = captured[0]
    assert 'ONLY THE REQUESTED SEARCH/REPLACE BLOCKS' in prompt
    assert 'EXACTLY ONE ```cpp CODE BLOCK' not in prompt


def test_opencode_api_timeout_does_not_duplicate_generation_via_cli(monkeypatch):
    monkeypatch.setattr(providers.shutil, 'which', lambda name: name)
    monkeypatch.setattr(providers, '_opencode_service', lambda: ('http://127.0.0.1:4096', 'test'))
    api = Mock(side_effect=providers.ProviderError('provider_retry', 'TimeoutError'))
    cli = Mock()
    monkeypatch.setattr(providers, '_opencode_api', api)
    monkeypatch.setattr(providers, '_opencode_run', cli)
    with pytest.raises(providers.ProviderError, match='TimeoutError'):
        providers.generate('opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b', 'native edit',
                           {'allow_cloud': True, 'opencode_api': True, 'retries': 0})
    api.assert_called_once()
    cli.assert_not_called()


def test_opencode_nemotron_disabled_thinking_selects_none_variant(monkeypatch):
    monkeypatch.setattr(providers.shutil, 'which', lambda name: name)
    run = Mock(return_value=(0, '{"type":"text","part":{"text":"edits"}}'))
    monkeypatch.setattr(providers, '_opencode_run', run)
    result = providers.generate('opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b', 'edit native C++',
                                {'allow_cloud': True, 'thinking': 'disabled'})
    assert result.model.endswith('#none')
    assert run.call_args.args[0][3].endswith('#none')


def test_cloud_retry_timeout_is_one_deadline_not_per_attempt(monkeypatch):
    clock=[0]
    monkeypatch.setattr(providers.time,'monotonic',lambda:clock[0])
    def request(*args):
        clock[0]+=10
        raise providers.ProviderError('provider_retry','TimeoutError')
    send=Mock(side_effect=request)
    monkeypatch.setattr(providers,'_openai_chat',send)
    with pytest.raises(providers.ProviderError,match='TimeoutError'):
        providers.generate('nvidia:nvidia/test','request',{'allow_cloud':True,'timeout':10,'retries':5})
    send.assert_called_once()


def test_opencode_transport_closed_is_retryable():
    assert providers._opencode_failure({'type':'Transport','message':'The socket connection was closed unexpectedly'}).category == 'provider_retry'


def test_auto_cloud_slots_bound_shared_nvidia_but_preserve_explicit_counts():
    model='opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none'
    assert providers.cloud_slots(model,20)==8
    assert providers.cloud_slots(model,4)==4
    assert providers.cloud_slots(model,20,20)==20
    assert providers.cloud_slots('codex:default',20)==20


def test_dead_opencode_service_metadata_is_ignored(tmp_path,monkeypatch):
    import json
    from pathlib import Path
    monkeypatch.delenv('OPENCODE_SERVER_URL',raising=False)
    monkeypatch.setattr(Path,'home',lambda:tmp_path)
    monkeypatch.setenv('LOCALAPPDATA',str(tmp_path/'local'))
    path=tmp_path/'.local/state/opencode/service.json';path.parent.mkdir(parents=True)
    path.write_text(json.dumps({'url':'http://127.0.0.1:4096','password':'not-an-api-key'}))
    monkeypatch.setattr(providers.socket,'create_connection',Mock(side_effect=OSError('connection refused')))
    assert providers._opencode_service() is None


def test_opencode_cli_runs_outside_repo_with_explicit_server(monkeypatch,tmp_path):
    task=tmp_path/'task.txt';task.write_text('native request')
    process=Mock(returncode=0);process.communicate.return_value=('response','')
    start=Mock(return_value=process)
    monkeypatch.setattr(providers.subprocess,'Popen',start)
    monkeypatch.setattr(providers,'_opencode_service',lambda:('http://127.0.0.1:4096','private-test-password'))
    providers._opencode_run(['opencode','run','--server','http://127.0.0.1:4096','--file',str(task)],'',5)
    options=start.call_args.kwargs
    assert options['cwd'] != providers.ROOT and options['cwd'] != task.parent
    assert options['cwd'].name == 'roconstruct-model-workspace'
    assert options['env']['OPENCODE_SERVER_PASSWORD'] == 'private-test-password'
    assert 'private-test-password' not in start.call_args.args[0]


def test_native_discovery_stops_queued_files_on_permanent_provider_failure(tmp_path, monkeypatch):
    files = {f'App/file{n}.cpp': 'void A::f() {}' for n in range(8)}
    monkeypatch.setattr(native_sweep, 'target_files', lambda *args: {name: ['00400000'] for name in files})
    obj = tmp_path / 'baseline.obj'
    obj.write_bytes(b'object')
    compile_source = Mock(return_value={'ok': True, 'object': str(obj)})
    proposal = Mock(side_effect=providers.ProviderError('provider_model', 'HTTP 404', 404))
    monkeypatch.setattr(native_sweep, 'model_proposal', proposal)
    _, trials = native_sweep.model_discovery({'llm': 'nvidia/nemotron-3-ultra-550b-a55b'}, files,
        {'00400000'}, set(), {}, SimpleNamespace(scan=lambda _: []), tmp_path, 1, lambda _: None,
        compile_source, {'00400000': {'symbol': 'f'}})
    compile_source.assert_called_once()
    proposal.assert_called_once()
    assert trials[-1]['error_category'] == 'provider_model'


def test_native_missing_provider_key_fails_before_dependency_build(monkeypatch):
    monkeypatch.setattr(providers, 'available', lambda model: False)
    from roc import rebuild_install
    prepare = Mock()
    monkeypatch.setattr(rebuild_install, 'prepare', prepare)
    with pytest.raises(providers.ProviderError, match='OpenCode sign-in uses opencode:nvidia/nvidia/'):
        gui_worker.native_loop({'model': 'nvidia/nemotron-3-ultra-550b-a55b'}, None, Mock())
    prepare.assert_not_called()
