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


def queue_three(promotions, users=("alice", "alice", "alice"), files=("A", "B", "C")):
    jobs = []
    for user, name in zip(users, files):
        claim = promotions.claim(user, user + "-pc")["claims"]
        body = dict(upload(claim, user), patches={"App/%s.cpp" % name: [["old", "new"]]})
        jobs.append(promotions.submit(user, body)["id"])
    return jobs


def test_disjoint_same_author_jobs_verify_together_and_share_receipt(promotions):
    a, b, c = queue_three(promotions)
    job = promotions.take()
    assert job["id"] == a and job["members"] == [a, b, c] and promotions.take() is None
    assert set(json.loads(job["patches"])) == {"App/A.cpp", "App/B.cpp", "App/C.cpp"}
    assert promotions.finish(job, {"accepted": True, "gains": ["00500000"], "new_distinct": ["00500000"]})
    states = dict(promotions.store.db.execute("SELECT id,state FROM integration_jobs"))
    assert states == {a: "accepted", b: "accepted", c: "accepted"}
    assert promotions.status()["leaderboard"] == [{"user": "alice", "model": "human", "native_credits": 1}]
    accepted = promotions.store.db.execute("SELECT job,patches FROM integration_accepted").fetchall()
    assert len(accepted) == 1 and set(json.loads(accepted[0][1])) == {"App/A.cpp", "App/B.cpp", "App/C.cpp"}
    assert promotions.store.db.execute("SELECT COUNT(*) FROM integration_claims WHERE state='submitted'").fetchone()[0] == 0


def test_webhook_posts_only_accepted_gains(promotions, monkeypatch):
    posts = []
    monkeypatch.setattr(integration_notify, "server_mines_webhook", lambda: "https://example.invalid/hook")
    monkeypatch.setattr(integration_notify, "payload", lambda *a: posts.append(a) or {"embeds": [{"timestamp": 0}]})
    monkeypatch.setattr(integration_notify.urllib.request, "urlopen", lambda *a, **k: (_ for _ in ()).throw(OSError("offline")))
    job = {"id": "j", "user": "alice", "model": "human"}
    integration_notify.notify(promotions, job)  # phase/progress change
    integration_notify.notify(promotions, job, {"accepted": False, "reason": "build failed"})
    integration_notify.notify(promotions, job, {"accepted": True, "gains": []})
    assert posts == []
    integration_notify.notify(promotions, job, {"accepted": True, "gains": ["00500000"]})
    assert len(posts) == 1


def test_claim_packet_carries_native_names(promotions):
    out = promotions.root / "rebuild/2008-06/out"
    out.mkdir(parents=True, exist_ok=True)
    claim = promotions.claim("alice", "pc")["claims"][0]
    assert claim["native_names"] == {}
    addr = claim["addresses"][0]
    (out / "native-names.json").write_text(json.dumps({addr: {"symbol": "?f@First@RBX@@QAEXXZ", "score": 97, "strings": ["x"]}}))
    again = promotions.claim("alice", "pc")["claims"][0]
    assert again["native_names"] == {addr: {"symbol": "?f@First@RBX@@QAEXXZ", "score": 97, "strings": ["x"]}}


def test_failed_merge_requeues_members_solo(promotions):
    a, b, c = queue_three(promotions)
    merged = promotions.take()
    assert not promotions.finish(merged, {"accepted": False, "reason": "build failed"})
    note = json.loads(promotions.store.db.execute("SELECT receipt FROM integration_jobs WHERE id=?", (b,)).fetchone()[0])
    assert note == {"merged_failure": "build failed", "merged_jobs": [a, b, c]}
    solo = promotions.take()
    assert solo["id"] == a and "members" not in solo
    assert promotions.finish(solo, {"accepted": False, "reason": "build failed"})
    assert promotions.take()["id"] == b  # solo members never re-merge


def test_other_authors_and_overlapping_files_are_not_merged(promotions):
    a, b, c = queue_three(promotions, users=("alice", "bob", "alice"), files=("A", "B", "A"))
    job = promotions.take()
    assert job["id"] == a and "members" not in job  # bob differs, the third edits the same file


def test_two_thousand_targets_share_one_compact_batch_and_job(promotions):
    names = ['Bulk%d' % i for i in range(1000)]
    header = promotions.root / 'tools/rbxgs/Client/App/include/Classes.h'
    header.write_text('\n'.join('class %s {};' % name for name in names))
    rows = [{'unit': 'RBX::' + name, 'addr': '%08x' % (0x500000 + i * 2 + j),
             'score': 100, 'source_kind': 'snippet', 'size': 30}
            for i, name in enumerate(names) for j in range(2)]
    (promotions.root / 'rebuild/2008-06/manifests/functions.json').write_text(json.dumps(rows))
    result = promotions.claim('alice', 'pc', targets=2000, compact=True)
    assert result['classes'] == 1000 and result['targets'] == 2000
    assert len(result['baselines']) == 1
    assert all('baseline' not in c for c in result['claims'])
    assert promotions.claim('bob', 'other')['claims'] == []
    ids = [c['id'] for c in result['claims']]
    assert promotions.renew_many('alice', ids)['changed'] == 1000
    assert promotions.renew_many('bob', ids)['changed'] == 0
    body = upload(result['claims'])
    body['evidence'] += '\nMethod evidence and compiler receipts. ' * 1000
    body['patches'] = {'App/Unit%d.cpp' % i: [['old%d' % j, 'new%d' % j] for j in range(101)]
                       for i in range(41)}
    queued = promotions.submit('alice', body)
    assert promotions.submit('alice', body)['id'] == queued['id']
    job = promotions.take()
    assert job['id'] == queued['id'] and promotions.take() is None
    assert promotions.status()['leaderboard'] == []  # Queued fixtures earn no credit.


def test_target_budget_stops_at_whole_class_and_skips_old_baseline(promotions):
    old = promotions.claim('alice', 'pc')['claims'][0]
    promotions.overlay.write_text(json.dumps({'App/Fresh.cpp': [['a', 'b']]}))
    result = promotions.claim('alice', 'pc', targets=1, compact=True)
    assert result['classes'] == result['targets'] == 1
    assert result['claims'][0]['id'] != old['id']
    assert result['claims'][0]['base_revision'] != old['base_revision']


def test_catalog_drops_accepted_targets_without_server_restart(promotions):
    claim = promotions.claim('alice', 'pc')['claims']
    promotions.submit('alice', upload(claim))
    promotions.finish(promotions.take(), {'accepted': True, 'gains': claim[0]['addresses'], 'new_distinct': []})
    assert promotions.claim('bob', 'other')['claims'][0]['unit'] != claim[0]['unit']


def test_explicit_class_can_revisit_done_hint_but_not_parked_blocker(promotions):
    queue = promotions.root / 'rebuild/2008-06/out/agent-queue.json'
    queue.parent.mkdir(parents=True)
    queue.write_text(json.dumps({'done': ['RBX::First'], 'parked': {'RBX::Second': 'needs layout proof'}}))
    assert promotions.claim('bob', 'other')['claims'][0]['unit'] == 'RBX::Third'
    assert promotions.claim('alice', 'pc', unit='RBX::First')['claims'][0]['unit'] == 'RBX::First'
    assert promotions.claim('alice', 'pc', unit='RBX::Second')['claims'] == []


@pytest.mark.parametrize('count,targets', [(0, None), (1025, None), (True, None), (1, 0), (1, 100001)])
def test_bulk_claim_limits_remain_bounded(promotions, count, targets):
    with pytest.raises(ValueError):
        promotions.claim('alice', 'pc', count, targets=targets)


def test_large_overlay_and_evidence_still_enforce_limits():
    with pytest.raises(ValueError, match='paths'):
        integration.validate_patches({'App/File%d.cpp' % i: [['a', 'b']]
                                      for i in range(integration.MAX_OVERLAY_PATHS + 1)})
    with pytest.raises(ValueError, match='edits'):
        integration.validate_patches({'App/Test.cpp': [['a', 'b']] * (integration.MAX_EDITS_PER_PATH + 1)})


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


def test_cli_compact_claim_batch_selects_only_its_own_packets(promotions, monkeypatch):
    from unittest.mock import Mock
    api = Mock()
    calls = []
    def call(path, body=None, **kwargs):
        if path.endswith('/base'):
            return promotions.baseline()
        if path.endswith('/claim'):
            assert body['targets'] == 2000 and body['compact'] and kwargs['timeout'] == 300
            return promotions.claim('alice', body['worker'], targets=2000, compact=True)
        if path == '/v1/integration':
            return {'jobs': []}
        calls.append((path, body))
        return {'id': 'test-job', 'state': 'queued'}
    api.call.side_effect = call
    monkeypatch.setattr(worker, 'Api', lambda *_: api)
    monkeypatch.setattr(worker, 'load_settings', lambda: {'server': 'http://test', 'user': 'alice'})
    monkeypatch.setattr(integration, 'ROOT', promotions.root)
    args = SimpleNamespace(action='next', server=None, user=None, token='invitation', count=1, unit=None, targets=2000)
    integration.command(args)
    directory = promotions.root / 'work/integration-client'
    batch = next((directory / 'batches').glob('*.json'))
    ids = json.loads(batch.read_text())['claims']
    assert len(ids) == 3
    packet = json.loads((directory / 'claims' / ids[0] / 'packet.json').read_text())
    assert packet['baseline']['overlay'] == {}
    # A user selects two claims; the third local packet must stay out of submission.
    batch.write_text(json.dumps({'claims': ids[:2]}))
    evidence = promotions.root / 'notes.txt'
    evidence.write_text('claimed target evidence')
    promotions.overlay.write_text(json.dumps({'App/Test.cpp': [['old', 'new']]}))
    args = SimpleNamespace(action='submit', server=None, user=None, token='invitation',
                           claim=None, all=False, batch=str(batch), model='human', evidence_file=str(evidence),
                           retry=False, wait=False)
    integration.command(args)
    assert calls[-1][0] == '/v1/integration/submit'
    assert set(calls[-1][1]['claims']) == set(ids[:2])


def test_cli_bulk_request_requires_capable_server(promotions, monkeypatch):
    api = SimpleNamespace(call=lambda *args: {'generator': 'old'})
    monkeypatch.setattr(worker, 'Api', lambda *_: api)
    monkeypatch.setattr(worker, 'load_settings', lambda: {'server': 'http://test', 'user': 'alice'})
    args = SimpleNamespace(action='next', server=None, user=None, token='invitation', count=1, targets=2000)
    with pytest.raises(SystemExit, match='update and restart'):
        integration.command(args)


@pytest.mark.parametrize('modern', [False, True])
def test_cli_renew_falls_back_for_old_server(promotions, monkeypatch, modern):
    claims = promotions.claim('alice', 'pc', 2)['claims']
    for claim in claims:
        integration.atomic_json(promotions.root / 'work/integration-client/claims' / claim['id'] / 'packet.json', claim)
    requests = []
    def call(path, body=None):
        if path == '/v1/integration':
            return {'jobs': []}
        if path.endswith('/base'):
            return {'limits': {'claims': 1024}} if modern else {}
        requests.append(body)
        return {'ok': True}
    monkeypatch.setattr(worker, 'Api', lambda *args: SimpleNamespace(call=call))
    monkeypatch.setattr(worker, 'load_settings', lambda: {'user': 'alice', 'server': 'http://test'})
    monkeypatch.setattr(integration, 'ROOT', promotions.root)
    args = SimpleNamespace(action='renew', user=None, server=None, token='test', claim=None, all=True, reason=None)
    integration.command(args)
    assert len(requests) == (1 if modern else 2)
    assert all(('claims' in request) == modern for request in requests)


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


def test_stale_file_is_dropped_not_whole_batch(tmp_path):
    tree = tmp_path / "tools/rbxgs/Client/App"
    tree.mkdir(parents=True)
    (tree / "good.cpp").write_text("int a = 1;\n")
    (tree / "stale.cpp").write_text("int b = 2;\n")
    patches = {"App/good.cpp": [["int a = 1;", "int a = 3;"]], "App/stale.cpp": [["int gone;", "int c;"]]}
    combined, kept, dropped = integration_verify.preflight(tmp_path, {}, patches)
    assert kept == {"App/good.cpp": patches["App/good.cpp"]} and combined == kept
    assert list(dropped) == ["App/stale.cpp"] and "anchor" in dropped["App/stale.cpp"]
    with pytest.raises(ValueError, match="anchor"):
        integration_verify.preflight(tmp_path, {}, {"App/stale.cpp": patches["App/stale.cpp"]})


def test_live_hash_ignores_snapshotted_code_but_sees_vendor_trees(promotions):
    root = promotions.root
    (root / "roc").mkdir(exist_ok=True)
    (root / "work/2008-06").mkdir(parents=True, exist_ok=True)
    live, full = integration_verify.input_hash(root, live_only=True), integration_verify.input_hash(root)
    (root / "roc/edited.py").write_text("x = 1\n")
    (root / "work/2008-06/functions.jsonl").write_text("{}\n")
    assert integration_verify.input_hash(root, live_only=True) == live
    assert integration_verify.input_hash(root) != full
    (root / "tools/rbxgs/Client/App/include/Classes.h").write_text("class Changed {};")
    assert integration_verify.input_hash(root, live_only=True) != live


def test_content_hash_invalidates_same_size_same_mtime_header(promotions):
    path = promotions.root / "tools/rbxgs/Client/App/include/Classes.h"
    before = integration_verify.input_hash(promotions.root)
    times = path.stat()
    path.write_text(path.read_text().replace("First", "Worst"))
    os.utime(path, ns=(times.st_atime_ns, times.st_mtime_ns))
    assert integration_verify.input_hash(promotions.root) != before


def test_parallel_input_hash_is_stable_and_covers_linked_libraries(promotions):
    linked = promotions.root / "rebuild/2008-06/out/Dependency/linked"
    linked.mkdir(parents=True)
    library = linked / "dependency.lib"
    library.write_bytes(b"first")
    before = integration_verify.input_hash(promotions.root)
    assert integration_verify.input_hash(promotions.root) == before
    times = library.stat()
    library.write_bytes(b"other")
    os.utime(library, ns=(times.st_atime_ns, times.st_mtime_ns))
    assert integration_verify.input_hash(promotions.root) != before


def test_registry_updates_do_not_invalidate_installed_native_inputs(promotions):
    registry = promotions.root / "local/units/generated-units.json"
    registry.parent.mkdir(parents=True)
    registry.write_text('{"unrelated": "first"}')
    unit = promotions.root / "tools/rbxgs/Client/App/roc_fixture.cpp"
    unit.write_text('first')
    promotions.overlay.write_text(json.dumps({"App/include/Classes.h": [["@replace", "App/roc_fixture.cpp"]]}))
    before = integration_verify.input_hash(promotions.root)
    registry.write_text('{"unrelated": "other"}')
    assert integration_verify.input_hash(promotions.root) == before
    times = unit.stat()
    unit.write_text('other')
    os.utime(unit, ns=(times.st_atime_ns, times.st_mtime_ns))
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


def test_loss_allowed_only_when_another_module_still_owns_it():
    before = gate_result()
    after = copy.deepcopy(before)
    after["report"]["owned_addrs"] = ["00500001", "00500002"]  # 00500000 moved away, two new
    after["distinct"] += 1
    integration_verify.check_gates(after, before, elsewhere={"00500000"})
    with pytest.raises(ValueError, match="losing"):
        integration_verify.check_gates(after, before, elsewhere={"00500009"})
    after["report"]["owned_addrs"] = []  # nothing new: still rejected even if the loss is covered
    with pytest.raises(ValueError, match="losing"):
        integration_verify.check_gates(after, before, elsewhere={"00500000"})


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


def test_http_bulk_payload_exceeds_old_limit_only_for_authenticated_native(promotions):
    import http.client
    httpd = ThreadingHTTPServer(('127.0.0.1', 0), server.make_handler(
        promotions.store, 'test-password', {'2008-06'}, integration=promotions))
    httpd.daemon_threads = True
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    url = 'http://127.0.0.1:%d' % httpd.server_port
    try:
        api = worker.Api(url, 'test-password')
        result = api.call('/v1/integration/claim', {'user': 'alice', 'worker': 'pc', 'targets': 1000, 'compact': True})
        assert result['targets'] == 3 and len(result['baselines']) == 1
        body = upload(result['claims'])
        body['evidence'] += ' compiler evidence' * 70000
        assert len(json.dumps(body).encode()) > 1 << 20
        assert api.call('/v1/integration/submit', body)['state'] == 'queued'
        for path, token, length, expected in [
                ('/v1/integration/submit', 'wrong', 2 << 20, 403),
                ('/v1/integration/submit', 'test-password', integration.MAX_REQUEST_BYTES + 1, 413),
                ('/v1/submit', 'test-password', 2 << 20, 413)]:
            conn = http.client.HTTPConnection('127.0.0.1', httpd.server_port, timeout=3)
            conn.putrequest('POST', path)
            conn.putheader('X-Roc-Token', token)
            conn.putheader('Content-Length', str(length))
            conn.endheaders()
            assert conn.getresponse().status == expected  # No large body read before rejecting.
            conn.close()
    finally:
        httpd.shutdown()
        httpd.server_close()


def test_http_two_thousand_target_batch_queues_once(promotions, monkeypatch):
    groups = [('RBX::Bulk%d' % i, [{'addr': '%08x' % (0x500000 + i * 2 + j)} for j in range(2)])
              for i in range(1000)]
    monkeypatch.setattr(promotions, 'catalog', lambda: groups)
    promotions.native_paths = {}
    httpd = ThreadingHTTPServer(('127.0.0.1', 0), server.make_handler(
        promotions.store, 'test-password', {'2008-06'}, integration=promotions))
    httpd.daemon_threads = True
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    try:
        api = worker.Api('http://127.0.0.1:%d' % httpd.server_port, 'test-password')
        claimed = api.call('/v1/integration/claim', {'user': 'alice', 'worker': 'pc', 'targets': 2000, 'compact': True})
        assert claimed['classes'] == 1000 and claimed['targets'] == 2000
        assert len(claimed['baselines']) == 1
        ids = [c['id'] for c in claimed['claims']]
        assert api.call('/v1/integration/renew', {'user': 'alice', 'claims': ids})['changed'] == 1000
        body = upload(claimed['claims'])
        first = api.call('/v1/integration/submit', body)
        assert api.call('/v1/integration/submit', body)['id'] == first['id']
        assert promotions.take()['id'] == first['id'] and promotions.take() is None
        assert promotions.status()['leaderboard'] == []
        api.close()
    finally:
        httpd.shutdown()
        httpd.server_close()


def test_native_digest_resends_changes_without_fake_mining_points(promotions, monkeypatch):
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
    fields = data["embeds"][0]["fields"]
    workers = next(f["value"] for f in fields if f["name"].endswith("Workers"))
    assert workers == "**alice** \u00b7 0 native credits *(+0)*"
    assert "42 pts" not in text
    assert "exact waiting" in text and "partial mined" in text and "remaining" in text
    assert "1 / 3 integrated \u00b7 2 remaining" in data["embeds"][0]["description"]
    response = Mock()
    response.__enter__ = Mock(return_value=response)
    response.__exit__ = Mock(return_value=False)
    response.read.return_value = b'{"id":"123"}'
    send = Mock(return_value=response)
    monkeypatch.setattr(integration_notify, "server_mines_webhook", lambda: "https://discord.invalid/webhooks/example")
    monkeypatch.setattr(integration_notify.urllib.request, "urlopen", send)
    integration_notify.notify(promotions, job)
    send.assert_not_called()
    promotions.progress(job["id"], "building")
    integration_notify.notify(promotions, job)
    send.assert_not_called()
    receipt = {"accepted": True, "gains": ["00500001"], "credits": 1,
               "owned_before": 1, "owned_after": 2, "distinct_before": 1, "distinct_after": 2}
    integration_notify.notify(promotions, job, receipt)
    assert send.call_args.args[0].method == "POST"
    integration_notify.notify(promotions, job, receipt)
    assert send.call_count == 1
    receipt.update(gains=["00500001", "00500002"], credits=2, owned_after=3, distinct_after=3)
    integration_notify.notify(promotions, job, receipt)
    assert send.call_count == 2
    assert send.call_args.args[0].method == "POST"
    assert send.call_args.args[0].full_url == "https://discord.invalid/webhooks/example?wait=true"


def test_verify_build_runs_header_gates_beside_the_build(tmp_path, monkeypatch):
    built, order = threading.Event(), []

    def run(root, args, log):
        name = log.name
        order.append((name, built.is_set()))
        if name == "integration-build.log":
            # the header gates must already be running: the build waits for them instead of racing
            for _ in range(500):
                if {"integration-size.log", "integration-base.log"} <= {n for n, _ in order}:
                    break
                threading.Event().wait(0.01)
            built.set()

    monkeypatch.setattr(integration_verify, "run", run)
    monkeypatch.setattr(integration_verify, "collect", lambda root: "ok")
    assert integration_verify.verify_build(tmp_path, lambda phase: None) == "ok"
    seen = dict(order)
    assert order[0][0] == "integration-overlay.log"
    assert seen["integration-size.log"] is False and seen["integration-base.log"] is False
    assert seen["integration-milestones.log"] is True and seen["integration-status.log"] is True
