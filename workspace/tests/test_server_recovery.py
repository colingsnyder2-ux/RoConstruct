"""Tunnel rotation must not retire workers or strand the public server."""
from unittest.mock import Mock, patch
from pathlib import Path

import pytest

from roc import server, worker


def test_reseed_updates_corrected_bounds_and_removes_false_starts(tmp_path):
    import json
    functions = tmp_path / "work" / "2008-06" / "functions.jsonl"
    functions.parent.mkdir(parents=True)
    functions.write_text(json.dumps(dict(addr="00401000", size=100, unit="Old", kind="code")) + "\n")
    store = server.Store(":memory:", 60)
    with patch.object(server, "ROOT", tmp_path):
        store.seed("2008-06")
        store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                         ("2008-06", "00401050", 20, "False split"))
        store.db.execute("UPDATE funcs SET score=73, source='int f();' WHERE addr='00401000'")
        functions.write_text(json.dumps(dict(addr="00401000", size=140, unit="Corrected", kind="code")) + "\n")
        store.seed("2008-06")
    assert store.db.execute("SELECT size,unit,score,source FROM funcs WHERE client='2008-06'").fetchall() == [
        (140, "Corrected", 0, "int f();")]


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
         patch.object(worker.telemetry, "summary", return_value=""):
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


def test_source_download_endpoint_and_publisher_share_store_method(tmp_path):
    import json
    import threading
    import urllib.request
    from http.server import ThreadingHTTPServer
    store = server.Store(tmp_path / "group.db", 60)
    store.db.executemany("INSERT INTO funcs(client,addr,size,unit,score,source,user) VALUES(?,?,?,?,?,?,?)", [
        ("2008-06", "00401000", 10, "Pilot", 99, "partial", "alice"),
        ("2008-06", "00401010", 10, "Pilot", 100, "exact", "alice"),
        ("2009-12", "00401000", 10, "Pilot", 100, "other client", "alice")])
    store.db.commit()
    httpd = ThreadingHTTPServer(("127.0.0.1", 0), server.make_handler(store, None, set()))
    httpd.daemon_threads = True
    thread = threading.Thread(target=httpd.serve_forever, daemon=True)
    thread.start()
    try:
        with urllib.request.urlopen("http://127.0.0.1:%d/v1/sources?client=2008-06&min_score=100" % httpd.server_port) as response:
            rows = json.load(response)
        assert [row["addr"] for row in rows] == ["00401010"]
        assert rows == store.sources("2008-06", min_score=100)
        assert store.sources("2009-12")[0]["source"] == "other client"
    finally:
        httpd.shutdown()
        httpd.server_close()
        thread.join()
        store.db.close()


def test_manual_sources_are_searchable_without_worker_activity(tmp_path):
    store = server.Store(tmp_path / "group.db", 60)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit,score,source,user,updated) VALUES(?,?,?,?,?,?,?,?)",
        ("2009-12", "00401000", 10, "Mined getter", 100, "int f(){return 1;}", "alice", 10))
    store.db.commit()
    rows = store.function_history(query="alice", status="matched")
    assert len(rows) == 1 and rows[0]["client"] == "2009-12"
    assert rows[0]["base_score"] is None and "after" not in rows[0]
    detail = store.function_history(rows[0]["id"])
    assert detail["after"] == "int f(){return 1;}" and detail["origin"] == "server"
    assert store.function_history(query="missing") == []
    store.db.close()


def test_unlimited_lease_has_no_size_ceiling(tmp_path):
    store = server.Store(tmp_path / "group.db", 60)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit,score,source,user) VALUES(?,?,?,?,?,?,?)",
        ("2008-06", "00401000", 2_000_000, "Large fn", 98, "source", "alice"))
    store.db.commit()
    assert store.lease("alice", "bounded", ["2008-06"], "ai", 8192) is None
    job = store.lease("alice", "deep", ["2008-06"], "ai", 0)
    assert job["size"] == 2_000_000
    store.db.close()


def test_shared_assignments_can_pick_same_target_and_keep_best_score(tmp_path):
    store = server.Store(tmp_path / "group.db", 60)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit,score,source,user) VALUES(?,?,?,?,?,?,?)",
        ("2008-06", "00401000", 32, "Shared", 80, "old", "alice"))
    store.db.commit()
    first = store.lease("alice", "w1", ["2008-06"], "ai", 256)
    second = store.lease("bob", "w2", ["2008-06"], "ai", 256)
    assert first["addr"] == second["addr"] == "00401000"
    assert store.submit("2008-06", "00401000", "alice", 90, "better", lease=first["lease"]) == (90, True)
    assert store.submit("2008-06", "00401000", "bob", 85, "worse", lease=second["lease"]) == (90, False)
    store.db.close()


def test_lease_skips_targets_claimed_by_another_worker(tmp_path):
    from roc import server
    store = server.Store(str(tmp_path / "s.db"), 3600)
    store.db.execute("INSERT INTO funcs (client, addr, size, unit, score, source) VALUES ('c','00401000',64,'u',90,'x')")
    store.db.commit()
    target = [{"client": "c", "addr": "00401000"}]
    first = store.lease("u1", "w1", ["c"], "ai", 0, targets=target)
    assert first and store.lease("u2", "w2", ["c"], "ai", 0, targets=target) is None
    again = store.lease("u1", "w1", ["c"], "ai", 0, targets=target)  # the same worker may re-lease
    store.release(again["lease"])
    assert store.lease("u2", "w2", ["c"], "ai", 0, targets=target)
