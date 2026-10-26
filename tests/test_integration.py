import copy
import json
import os
import shutil
import sqlite3
import threading
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer
from types import SimpleNamespace

import pytest

from roc import integration, integration_verify, integration_notify, server, worker


def make_store(path):
    return SimpleNamespace(db=sqlite3.connect(path, check_same_thread=False), lock=threading.Lock())


@pytest.fixture
def promotions(tmp_path):
    root = tmp_path / "checkout"
    patchdir = root / "rebuild/2008-06/patches"
    patchdir.mkdir(parents=True)
    (patchdir / "rbxgs-client.json").write_text("{}")
    (patchdir / "make_rbxgs_client.py").write_text("# trusted generator\n")
    include = root / "tools/rbxgs/Client/App/include"
    include.mkdir(parents=True)
    (include / "Classes.h").write_text("class First {}; class Second {}; class Third {};")
    manifest = root / "rebuild/2008-06/manifests/functions.json"
    manifest.parent.mkdir()
    manifest.write_text(json.dumps([{"unit": "RBX::" + name, "addr": "0050000" + str(i),
        "score": 100, "source_kind": "snippet", "size": 30}
        for i, name in enumerate(("First", "Second", "Third"))]))
    p = integration.Promotions(make_store(tmp_path / "server.db"), root)
    yield p
    p.store.db.close()


def upload(claims, user="alice"):
    return {"user": user, "claims": [c["id"] for c in claims], "model": "human",
            "base_revision": claims[0]["base_revision"],
            "evidence": "constructor evidence " + " ".join(c["addresses"][0] for c in claims),
            "patches": {"App/Test.cpp": [["old", "new"]]}}


def test_claims_atomic_across_two_server_connections_and_restart(promotions):
    other = integration.Promotions(make_store(promotions.root.parent / "server.db"), promotions.root)
    with ThreadPoolExecutor(2) as pool:
        a, b = list(pool.map(lambda pair: pair[0].claim(pair[1], pair[1] + "-pc")["claims"][0],
                            ((promotions, "alice"), (other, "bob"))))
    assert a["unit"] != b["unit"]
    resumed = other.claim("alice", "alice-pc")["claims"][0]
    assert resumed["id"] == a["id"]
    assert not other.renew("bob", a["id"], True)["ok"]
    assert other.renew("alice", a["id"], True)["ok"]
    other.store.db.close()


def test_expired_claim_cannot_submit_or_release_successor(promotions):
    old = promotions.claim("alice", "pc")["claims"][0]
    with promotions.store.db:
        promotions.store.db.execute("UPDATE integration_claims SET expires=0 WHERE id=?", (old["id"],))
    fresh = promotions.claim("bob", "other")["claims"][0]
    assert fresh["unit"] == old["unit"] and fresh["id"] != old["id"]
    assert not promotions.renew("alice", old["id"], True)["ok"]
    with pytest.raises(ValueError, match="expired"):
        promotions.submit("alice", upload([old]))


def test_bulk_submit_and_replay_are_one_job_one_credit(promotions):
    claims = promotions.claim("alice", "pc", 2)["claims"]
    body = upload(claims)
    submitted = promotions.submit("alice", body)
    assert promotions.submit("alice", body)["id"] == submitted["id"]
    job = promotions.take()
    assert promotions.take() is None
    receipt = {"accepted": True, "gains": ["00500000"], "new_distinct": ["00500000"]}
    assert promotions.finish(job, receipt)
    assert not promotions.finish(job, receipt)
    assert promotions.submit("alice", body)["duplicate"]
    assert promotions.status()["leaderboard"] == [{"user": "alice", "model": "human", "native_credits": 1}]
    assert promotions.store.db.execute("SELECT COUNT(*) FROM integration_claims WHERE state='submitted'").fetchone()[0] == 0


def test_rejected_verification_and_publish_failure_never_credit(promotions):
    claim = promotions.claim("alice", "pc")["claims"]
    promotions.submit("alice", upload(claim))
    job = promotions.take()

    def fail(_):
        raise OSError("disk full")

    with pytest.raises(OSError):
        promotions.finish(job, {"accepted": True, "gains": ["00500000"], "new_distinct": ["00500000"]}, fail)
    assert promotions.accepted() == []
    assert promotions.status()["leaderboard"] == []
    promotions.finish(job, {"accepted": False, "reason": "runtime failed"})
    assert promotions.status()["jobs"][0]["state"] == "rejected"


def test_unchanged_rejected_batch_explicit_retry_is_idempotent(promotions):
    claims = promotions.claim("alice", "pc")["claims"]
    body = upload(claims)
    original = promotions.submit("alice", body)
    promotions.finish(promotions.take(), {"accepted": False, "reason": "compiler temporarily unavailable"})
    body["retry_of"] = original["id"]
    retried = promotions.submit("alice", body)
    assert retried["id"] != original["id"]
    assert promotions.submit("alice", body)["id"] == retried["id"]
    assert promotions.status()["leaderboard"] == []


def test_park_reason_hides_blocked_class_from_other_pc(promotions):
    claim = promotions.claim("alice", "pc")["claims"][0]
    assert promotions.renew("alice", claim["id"], True, "missing class; 00500000")["ok"]
    assert promotions.claim("bob", "other")["claims"][0]["unit"] != claim["unit"]
    assert promotions.status()["parked"][0]["reason"] == "missing class; 00500000"


def test_cli_worker_identity_is_stable_per_checkout_not_shared_by_same_pc(promotions, monkeypatch):
    from unittest.mock import Mock
    original = promotions.root
    other = original.with_name("second-checkout")
    shutil.copytree(original, other)
    api = Mock()
    identities = []
    def call(path, body=None):
        if path.endswith("/base"):
            return promotions.baseline()
        identities.append(body["worker"])
        return {"claims": []}
    api.call.side_effect = call
    monkeypatch.setattr(worker, "Api", lambda *_: api)
    monkeypatch.setattr(worker, "load_settings", lambda: {"server": "http://test", "user": "alice"})
    args = SimpleNamespace(action="next", server=None, user=None, token="invitation", count=1, unit=None)
    for root in (original, original, other):
        monkeypatch.setattr(integration, "ROOT", root)
        integration.command(args)
    assert identities[0] == identities[1]
    assert identities[0] != identities[2]


def test_claim_packet_keeps_original_base_when_other_work_is_accepted(promotions):
    claim = promotions.claim("alice", "pc")["claims"][0]
    promotions.overlay.write_text(json.dumps({"App/Fresh.cpp": [["a", "b"]]}))
    resumed = promotions.claim("alice", "pc")["claims"][0]
    assert resumed["base_revision"] == claim["base_revision"]
    assert resumed["baseline"]["overlay"] == {}
    assert promotions.baseline()["revision"] != claim["base_revision"]


@pytest.mark.parametrize("path,edit", [
    ("../tools/a.h", ["x", "y"]), ("App/../../a.h", ["x", "y"]),
    ("C:/secret.h", ["x", "y"]), ("App/a.py", ["x", "y"]),
    ("App/a.h", ["@replace", "private.h"]), ("App/a.h", ["x", "__asm nop"]),
    ("App/a.h", ["x", "struct S { char padding[1024]; }; "]),
    ("App/a.h", ["x", "reinterpret_cast<int*>(base + 4)"]),
    ("App/a.cpp", ["", "struct S { char unknown0x14[256]; int value; }; "]),
])
def test_unsafe_or_non_native_payload_rejected(path, edit):
    with pytest.raises(ValueError):
        integration.validate_patches({path: [edit]})


def test_existing_overlay_cannot_be_removed_or_rewritten():
    before = {"App/a.h": [["a", "b"]]}
    with pytest.raises(ValueError):
        integration.overlay_delta(before, {})
    assert integration.overlay_delta(before, {"App/a.h": [["a", "b"], ["b", "c"]]}) == {"App/a.h": [["b", "c"]]}
    replacement = integration.overlay_delta(before, {"App/a.h": [["a", "c"]]})
    assert integration.merge_patches(before, replacement) == {"App/a.h": [["a", "c"]]}
    with pytest.raises(ValueError, match="Stale"):
        integration.merge_patches({"App/a.h": [["a", "other fix"]]}, replacement)


def test_stale_anchor_fails_before_hash_or_build(promotions, monkeypatch):
    claims = promotions.claim("alice", "pc")["claims"]
    promotions.submit("alice", upload(claims))
    job = promotions.take()
    monkeypatch.setattr(integration_verify, "input_hash", lambda _: pytest.fail("expensive input scan"))
    with pytest.raises(ValueError, match="anchor"):
        integration_verify.verify(promotions, job)


def test_content_hash_invalidates_same_size_same_mtime_header(promotions):
    path = promotions.root / "tools/rbxgs/Client/App/include/Classes.h"
    before = integration_verify.input_hash(promotions.root)
    times = path.stat()
    path.write_text(path.read_text().replace("First", "Worst"))
    os.utime(path, ns=(times.st_atime_ns, times.st_mtime_ns))
    assert integration_verify.input_hash(promotions.root) != before


def gate_result():
    return {"report": {"linked": True, "test_exit": 0, "owned_addrs": ["00500000"]},
            "distinct": 5, "milestones": {m: {"passed": True, "exit": 0} for m in ("M2", "M4a", "M5")},
            "size": {"rows": [{"class": "First", "delta": 0}], "probe_errors": {}},
            "base": {"checked": 4, "mismatch": [], "probe_errors": {}}}


@pytest.mark.parametrize("failure", ["runtime", "milestone", "size", "base", "probe", "coverage", "lost", "distinct"])
def test_every_gate_rejects_regression(failure):
    before = gate_result()
    after = copy.deepcopy(before)
    after["report"]["owned_addrs"].append("00500001")
    after["distinct"] += 1
    if failure == "runtime": after["report"]["test_exit"] = 1
    if failure == "milestone": after["milestones"]["M5"]["exit"] = 1
    if failure == "size": after["size"]["rows"][0]["delta"] = 4
    if failure == "base": after["base"]["mismatch"] = ["wrong"]
    if failure == "probe": after["base"]["probe_errors"] = {"new.h": "failed"}
    if failure == "coverage": after["base"]["checked"] = 3
    if failure == "lost": after["report"]["owned_addrs"] = ["00500001", "00500002"]
    if failure == "distinct": after["distinct"] = 4
    with pytest.raises(ValueError):
        integration_verify.check_gates(after, before)


def test_two_pcs_use_http_without_shared_client_files(promotions):
    httpd = ThreadingHTTPServer(("127.0.0.1", 0), server.make_handler(
        promotions.store, "test-password", {"2008-06"}, integration=promotions))
    httpd.daemon_threads = True
    thread = threading.Thread(target=httpd.serve_forever, daemon=True)
    thread.start()
    url = "http://127.0.0.1:%d" % httpd.server_port
    try:
        alice, bob = worker.Api(url, "test-password"), worker.Api(url, "test-password")
        a = alice.call("/v1/integration/claim", {"user": "alice", "worker": "laptop", "count": 1})["claims"]
        b = bob.call("/v1/integration/claim", {"user": "bob", "worker": "desktop", "count": 1})["claims"]
        assert a[0]["unit"] != b[0]["unit"]
        queued = alice.call("/v1/integration/submit", upload(a))
        assert queued["state"] == "queued"
        with pytest.raises(worker.ApiFailure):
            bob.call("/v1/integration/submit", upload(a, "bob"))
        with pytest.raises(worker.ApiFailure):
            alice.call("/v1/integration/finish", {"user": "alice", "accepted": True})
        assert alice.call("/v1/integration")["leaderboard"] == []
    finally:
        httpd.shutdown()
        httpd.server_close()


def test_native_digest_fields_edit_same_message_without_fake_mining_points(promotions, monkeypatch):
    from unittest.mock import Mock
    root = promotions.root
    work = root / "work/2008-06"
    work.mkdir(parents=True)
    functions = [{"addr": "0050000" + str(i), "size": 30} for i in range(3)]
    (work / "functions.jsonl").write_text("\n".join(json.dumps(f) for f in functions))
    integration.atomic_json(promotions.directory / "progress-native.json", {"addresses": ["00500000"]})
    promotions.store.db.execute("CREATE TABLE funcs(client TEXT,addr TEXT,score INT)")
    promotions.store.db.execute("INSERT INTO funcs VALUES('2008-06','00500002',50)")
    promotions.store.db.commit()
    promotions.store.user_points = lambda _: 42
    claims = promotions.claim("alice", "pc")["claims"]
    promotions.submit("alice", upload(claims))
    job = promotions.take()
    data = integration_notify.payload(promotions, job)
    assert data["allowed_mentions"] == {"parse": []}
    text = json.dumps(data)
    assert "42 pts" in text and "+0 mining" in text
    assert "exact waiting" in text and "partial mined" in text and "remaining" in text
    assert "1" in data["embeds"][0]["fields"][1]["value"]
    response = Mock()
    response.__enter__ = Mock(return_value=response)
    response.__exit__ = Mock(return_value=False)
    response.read.return_value = b'{"id":"123"}'
    send = Mock(return_value=response)
    monkeypatch.setattr(integration_notify, "server_mines_webhook", lambda: "https://discord.invalid/webhooks/example")
    monkeypatch.setattr(integration_notify.urllib.request, "urlopen", send)
    integration_notify.notify(promotions, job)
    assert send.call_args.args[0].method == "POST"
    integration_notify.notify(promotions, job)
    assert send.call_count == 1
    promotions.progress(job["id"], "building")
    integration_notify.notify(promotions, job)
    assert send.call_args.args[0].method == "PATCH"
    assert send.call_args.args[0].full_url.endswith("/messages/123")
