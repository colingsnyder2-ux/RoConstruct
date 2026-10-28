import json
import threading
import urllib.error
import urllib.request
from http.server import ThreadingHTTPServer
from unittest.mock import Mock

import pytest

from roc import reports, server, worker


def test_player_destination_uses_existing_discord_config_without_legacy_server_fallback(tmp_path, monkeypatch):
    path = tmp_path / 'settings.json'
    path.write_text(json.dumps({'discord_webhook': 'https://player.invalid/hook',
                                'server_mines_webhook': 'https://server.invalid/hook'}))
    monkeypatch.setattr(reports.setup, 'config', lambda _: path)
    monkeypatch.delenv('ROCONSTRUCT_PLAYER_MINES_WEBHOOK', raising=False)
    monkeypatch.delenv('ROCONSTRUCT_DISCORD_WEBHOOK', raising=False)
    monkeypatch.setenv('ROCONSTRUCT_SERVER_MINES_WEBHOOK', 'https://old.invalid/hook')
    assert reports.player_mines_webhook() == 'https://player.invalid/hook'
    monkeypatch.setenv('ROCONSTRUCT_DISCORD_WEBHOOK', 'https://env.invalid/hook')
    assert reports.player_mines_webhook() == 'https://env.invalid/hook'
    monkeypatch.setenv('ROCONSTRUCT_PLAYER_MINES_WEBHOOK', 'https://explicit.invalid/hook')
    assert reports.player_mines_webhook() == 'https://explicit.invalid/hook'
    monkeypatch.delenv('ROCONSTRUCT_PLAYER_MINES_WEBHOOK')
    monkeypatch.delenv('ROCONSTRUCT_DISCORD_WEBHOOK')
    path.write_text(json.dumps({'server_mines_webhook': 'https://server.invalid/hook'}))
    assert reports.player_mines_webhook() is None


@pytest.mark.parametrize('model', ['function', 'family', 'unit', 'native', ' Function '])
def test_scratch_submission_rejects_lease_mode_as_model_before_network(monkeypatch, model):
    api = Mock()
    monkeypatch.setattr(worker, 'Api', api)
    with pytest.raises(ValueError, match='actual AI model'):
        worker.submit_files('https://server.invalid', 'alice', '2008-06', model=model)
    api.assert_not_called()


def test_submit_endpoints_reject_lease_labels_without_awarding_points():
    store = server.Store(':memory:', lease_seconds=10)
    feed = Mock()
    httpd = ThreadingHTTPServer(('127.0.0.1', 0), server.make_handler(store, None, {'C'}, mine_log=feed))
    thread = threading.Thread(target=httpd.serve_forever, daemon=True)
    thread.start()
    try:
        for path in ('/v1/submit', '/v1/submit-batch'):
            body = {'user': 'alice', 'model': 'function', 'client': 'C', 'addr': '00401000',
                    'addrs': ['00401000'], 'source': 'void f(){}', 'score': 100}
            request = urllib.request.Request('http://127.0.0.1:%d%s' % (httpd.server_port, path),
                                             data=json.dumps(body).encode(), headers={'Content-Type': 'application/json'})
            with pytest.raises(urllib.error.HTTPError) as error:
                urllib.request.urlopen(request, timeout=5)
            assert error.value.code == 400
        assert store.user_points('alice') == 0
        feed.submit.assert_not_called()
    finally:
        httpd.shutdown()
        httpd.server_close()
        thread.join(timeout=2)
        store.db.close()
