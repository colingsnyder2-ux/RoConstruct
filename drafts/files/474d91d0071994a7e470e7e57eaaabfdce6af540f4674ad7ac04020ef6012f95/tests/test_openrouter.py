import io
import json
from unittest.mock import Mock

import pytest

from roc import providers


@pytest.mark.parametrize('model', ['openrouter:google/gemini-2.5-flash',
                                  'openrouter/google/gemini-2.5-flash',
                                  'hosted:openrouter/google/gemini-2.5-flash'])
def test_google_routes_through_openrouter_not_direct_gemini(model):
    name, remote, config = providers.parse_model(model)
    assert (name, remote) == ('openrouter', 'google/gemini-2.5-flash')
    assert config['key_env'] == 'OPENROUTER_API_KEY'


@pytest.mark.parametrize('thinking,effort,expected', [
    ('disabled', 'high', {'enabled': False}),
    ('enabled', 'low', {'enabled': True, 'effort': 'low'}),
    ('auto', 'high', {'effort': 'high'}),
    ('auto', None, None)])
def test_openrouter_google_request_preserves_namespace_and_uses_unified_reasoning(monkeypatch, thinking, effort, expected):
    monkeypatch.setenv('OPENROUTER_API_KEY', 'test-openrouter-key')
    send = Mock(return_value=({'choices': [{'message': {'content': 'int f(){return 1;}'}, 'finish_reason': 'stop'}],
                              'usage': {'prompt_tokens': 12, 'completion_tokens': 8}}, {}))
    monkeypatch.setattr(providers, '_post', send)
    result = providers.generate('openrouter:google/test:free', 'repair',
        {'allow_cloud': True, 'thinking': thinking, 'reasoning_effort': effort})
    url, body, headers, timeout = send.call_args.args
    assert url == 'https://openrouter.ai/api/v1/chat/completions'
    assert body['model'] == 'google/test:free'
    assert body.get('reasoning') == expected
    assert 'thinking' not in body and 'reasoning_effort' not in body
    assert headers['Authorization'] == 'Bearer test-openrouter-key'
    assert (result.provider, result.input_tokens, result.output_tokens) == ('openrouter', 12, 8)


def test_openrouter_catalog_public_cached_and_keeps_only_text_output(monkeypatch):
    monkeypatch.setattr(providers, 'MODEL_CATALOG', {})
    response = Mock()
    response.__enter__ = Mock(return_value=io.StringIO(json.dumps({'data': [
        {'id': 'google/test:free', 'architecture': {'output_modalities': ['text']}},
        {'id': 'image-only', 'architecture': {'output_modalities': ['image']}},
        {'id': 'google/test:free'}, {'id': 'anthropic/test'}]})))
    response.__exit__ = Mock(return_value=False)
    send = Mock(return_value=response)
    monkeypatch.setattr(providers.urllib.request, 'urlopen', send)
    config = providers.BUILTINS['openrouter']
    assert providers.provider_models('openrouter', config) == ['anthropic/test', 'google/test:free']
    assert providers.provider_models('openrouter', config) == ['anthropic/test', 'google/test:free']
    send.assert_called_once()
    assert send.call_args.args[0].get_header('Authorization') is None


def test_openrouter_catalog_outage_preserves_last_success(monkeypatch):
    monkeypatch.setattr(providers, 'MODEL_CATALOG', {'https://openrouter.ai/api/v1/models': (0, ['google/last'])})
    monkeypatch.setattr(providers.urllib.request, 'urlopen', Mock(side_effect=OSError('offline')))
    assert providers.provider_models('openrouter', providers.BUILTINS['openrouter']) == ['google/last']


@pytest.mark.parametrize('code,category', [(401,'provider_auth'),(404,'provider_model'),(429,'provider_retry')])
def test_openrouter_embedded_errors_are_safe_not_empty_success(monkeypatch, code, category):
    monkeypatch.setenv('OPENROUTER_API_KEY', 'test-key')
    monkeypatch.setattr(providers, '_post', Mock(return_value=({'error': {'code': code, 'message': 'private details'}}, {})))
    with pytest.raises(providers.ProviderError) as failure:
        providers.generate('openrouter:google/test', 'repair', {'allow_cloud': True, 'retries': 0})
    assert failure.value.category == category
    assert 'private' not in str(failure.value)


def test_openrouter_does_not_treat_reasoning_as_source(monkeypatch):
    monkeypatch.setenv('OPENROUTER_API_KEY', 'test-key')
    monkeypatch.setattr(providers, '_post', Mock(return_value=({'choices': [
        {'message': {'content': None, 'reasoning': 'private thoughts'}, 'finish_reason': 'length'}]}, {})))
    result = providers.generate('openrouter:google/test', 'repair', {'allow_cloud': True})
    assert result.text == '' and result.finish_reason == 'length'
