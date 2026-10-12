"""Tunnel rotation must not retire workers or strand the public server."""
from unittest.mock import Mock, patch
from pathlib import Path

import pytest

from roc import server, worker


def test_publish_lock_survives_stale_file_but_blocks_concurrent_publish(tmp_path):
    lock = tmp_path / "work/publish.lock"
    lock.parent.mkdir()
    lock.write_bytes(b"old")
    published = []

    def publish(*args):
        published.append(args)
        server.publish_once(Mock(), "other", log=lambda _: None)

    with patch.object(server, "ROOT", Path(tmp_path)), patch.object(server, "_publish_once", side_effect=publish):
        server.publish_once(Mock(), "first", log=lambda _: None)
        server.publish_once(Mock(), "second", log=lambda _: None)
    assert len(published) == 2


def test_reconnect_preserves_pinned_and_cluster_addresses():
    with patch.object(worker, "site_server") as site:
        for address in ("localhost:8765", "http://192.168.1.2:8765",
                        "https://fixed.example", "https://old.trycloudflare.com,http://other:8765"):
            assert not worker.reconnect(worker.Api(address), lambda _: None)
        site.assert_not_called()


def test_reconnect_closes_old_connection_and_keeps_token():
    api = worker.Api("https://old.trycloudflare.com", "secret")
    connection = api._conn = Mock()
    with patch.object(worker, "site_server", return_value="https://new.trycloudflare.com"), \
         patch.object(worker, "save_settings"):
        assert worker.reconnect(api, lambda _: None)
    connection.close.assert_called_once()
    assert api.server == "https://new.trycloudflare.com"
    assert api.token == "secret"


def test_rotated_server_still_offline_does_not_escape_worker():
    api = Mock()
    api.call.side_effect = [{"clients": {"C": {}}}, worker.ApiFailure("offline", "old DNS"),
                            worker.ApiFailure("offline", "new DNS"), {"job": None}]
    with patch.object(worker, "Api", return_value=api), \
         patch.object(worker, "usable_clients", return_value=["C"]), \
         patch.object(worker, "reconnect", return_value=True), \
         patch.object(worker.time, "sleep") as sleep, \
         patch.object(worker.metrics, "summary", return_value=""):
        worker.run("https://old.trycloudflare.com", "tester", source_only=True,
                   forever=True, max_jobs=1, log=lambda _: None)
    sleep.assert_called_once_with(60)


def test_primary_outage_uses_backup_then_returns_to_primary():
    clock = [0]
    probe = Mock()
    probe.call.side_effect = [{}, worker.ApiFailure("offline", "Funnel down"), {}]

    def tick(_):
        clock[0] += 31
        if clock[0] >= 93:
            raise KeyboardInterrupt

    with patch.object(worker, "Api", return_value=probe), \
         patch.object(server, "publish_once") as publish, \
         patch.object(server.time, "monotonic", side_effect=lambda: clock[0]), \
         patch.object(server.time, "sleep", side_effect=tick):
        with pytest.raises(KeyboardInterrupt):
            server.publish_loop(Mock(), "https://backup.trycloudflare.com", 3600,
                                log=lambda _: None, primary="https://primary.ts.net")
    assert [call.args[1] for call in publish.call_args_list] == [
        "https://primary.ts.net", "https://backup.trycloudflare.com", "https://primary.ts.net"]


@pytest.mark.parametrize("publish", [True, False])
def test_dead_tunnel_restarts_and_republishes_immediately(publish):
    dead, live = Mock(), Mock()
    dead.poll.return_value = 1
    live.poll.return_value = None
    with patch.object(server, "start_tunnel", return_value=("https://new.trycloudflare.com", live)) as start, \
         patch.object(server, "publish_once") as push, \
         patch.object(server.time, "sleep", side_effect=KeyboardInterrupt):
        with pytest.raises(KeyboardInterrupt):
            server.publish_loop(Mock(), "https://old.trycloudflare.com", 3600,
                                log=lambda _: None, tunnel=dead, port=8765, publish=publish)
    start.assert_called_once()
    assert start.call_args.args[0] == 8765
    if publish:
        assert push.call_args.args[1] == "https://new.trycloudflare.com"
    else:
        push.assert_not_called()
