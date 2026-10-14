import hashlib
import json
import threading
from http.server import ThreadingHTTPServer

import pytest

from roc import agent, agent_memory, server, worker


def test_manual_trial_infers_campaign_metadata_from_evidence(tmp_path, monkeypatch):
    from roc import research
    import json
    monkeypatch.setattr(agent_memory, "ROOT", tmp_path)
    folder = tmp_path / "work/agent-campaigns/run/00401000"
    folder.mkdir(parents=True)
    (folder / "task.json").write_text(json.dumps(dict(client="2008-06", addr="00401000",
        campaign_id="run", baseline_hash="baseline", target_revision="revision")))
    row = agent_memory.append_record(dict(kind="trial", client="2008-06", date="2026-10-13",
        addresses=["00401000"], evidence=str(folder / "00401000.cpp"), outcome="no_gain"))
    assert row["campaign_id"] == "run" and row["baseline_hash"] == "baseline"
    assert "T" in row["date"]
    assert research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")[0] == row


@pytest.fixture
def shared_server(tmp_path, monkeypatch):
    docs = tmp_path / "server" / "docs"
    docs.mkdir(parents=True)
    (docs.parent / "research").mkdir()
    (docs.parent / "research" / "lessons.json").write_text(json.dumps([{"id": "prelude", "exacts_gained": 321}]))
    (docs / "AGENT_GUIDE.md").write_text("Reuse genuine vendor headers first.")
    monkeypatch.setattr(server, "ROOT", docs.parent)
    monkeypatch.setattr(agent_memory, "context", lambda: {"docs/AGENT_GUIDE.md": "Reuse genuine vendor headers first."})
    store = server.Store(tmp_path / "server.db", 60)
    http = ThreadingHTTPServer(("127.0.0.1", 0), server.make_handler(store, "test-token", set()))
    thread = threading.Thread(target=http.serve_forever, daemon=True)
    thread.start()
    yield store, "http://127.0.0.1:%s" % http.server_port
    http.shutdown()
    http.server_close()
    thread.join()
    store.db.close()


def test_two_pcs_share_negative_trials_and_missing_docs(shared_server, tmp_path, monkeypatch):
    store, address = shared_server
    monkeypatch.setattr(worker, "load_settings", lambda: {})
    pc1 = tmp_path / "pc1"
    journal = pc1 / "work" / "agent-memory" / "attempts.jsonl"
    journal.parent.mkdir(parents=True)
    journal.write_text(json.dumps(dict(kind="trial", date="2026-10-12", client="2008-06",
        addresses=["00401000"], hypothesis="vendor prelude", outcome="compile_failed",
        error="Missing authentic header", source_hash="abc", evidence="PRIVATE/PATH", token="secret")) + '\n{"broken":')
    monkeypatch.setattr(agent_memory, "ROOT", pc1)
    assert agent_memory.shared(address, "test-token", "alice", upload=True)["available"]
    assert agent_memory.shared(address, "test-token", "alice", upload=True)["available"]
    assert len(store.agent_memory()["records"]) == 1
    pc2 = tmp_path / "pc2"
    monkeypatch.setattr(agent_memory, "ROOT", pc2)
    monkeypatch.setattr(agent, "ROOT", pc2)
    result = agent_memory.shared(address, "test-token", "bob")
    record = result["records"][0]
    assert record["reported_by"] == "alice" and record["outcome"] == "compile_failed"
    assert record["error"] == "Missing authentic header" and not record["server_confirmed"]
    assert "token" not in record and "evidence" not in record
    cached = pc2 / "work" / "agent-memory" / "context" / "docs" / "AGENT_GUIDE.md"
    assert cached.read_text() == "Reuse genuine vendor headers first."
    memory = agent.memory(result)
    assert memory["lessons"][0]["exacts_gained"] == 321
    assert json.dumps(str(cached)) in agent.memory_prompt(memory)
    # Wrong server credential must not upload a report.
    api = worker.Api(address, "wrong")
    with pytest.raises(worker.ApiFailure):
        api.call("/v1/agent-memory", {"user": "mallory", "records": [{"kind": "trial"}]})
    api.close()


def test_reports_cannot_claim_server_verification(shared_server):
    store, _ = shared_server
    source = "int f() { return 1; }"
    store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('2008-06','00401000',10,'Pilot')")
    store.db.commit()
    store.submit("2008-06", "00401000", "alice", 99, source, verified=True)
    report = dict(kind="auto_target", client="2008-06", addresses=["00401000"], after=99,
                  outcome="server_verified", source_hash=hashlib.sha256(source.encode()).hexdigest())
    assert store.remember("alice", [report])["added"] == 1
    assert store.remember("alice", [report])["added"] == 0
    store.remember("mallory", [dict(report, server_confirmed=True)])
    store.remember("alice", [dict(report, source_hash="fake", server_confirmed=True)])
    flags = [row["server_confirmed"] for row in store.agent_memory()["records"]]
    assert flags == [True, False, False]
    assert store.agent_memory(after=1, limit=1)["cursor"] == 2
    with pytest.raises(ValueError):
        store.remember("alice", [dict(report, client="unknown-client")])


def test_findings_export_keeps_portable_evidence(shared_server, tmp_path, monkeypatch):
    store, _ = shared_server
    monkeypatch.setattr(server, "ROOT", tmp_path)
    store.remember("alice", [dict(kind="trial", outcome="no_gain", addresses=["00401000"])])
    stale = tmp_path / "local" / "findings" / "agent-memory" / "context" / "docs" / "retired.md"
    stale.parent.mkdir(parents=True)
    stale.write_text("old guide")
    server.export_agent_findings(store)
    folder = tmp_path / "local" / "findings" / "agent-memory"
    assert not stale.exists()
    assert json.loads((folder / "attempts.jsonl").read_text())["reported_by"] == "alice"
    assert (folder / "context" / "docs" / "AGENT_GUIDE.md").is_file()
    assert not (folder / "README.md").exists()


def test_rejected_record_is_skipped_and_offline_keeps_queue(shared_server, tmp_path, monkeypatch):
    store, address = shared_server
    monkeypatch.setattr(worker, "load_settings", lambda: {})
    pc = tmp_path / "pc"
    journal = pc / "work" / "agent-memory" / "attempts.jsonl"
    journal.parent.mkdir(parents=True)
    rows = [dict(kind="trial", client="2008-06", addresses=["not-an-address"], outcome="no_gain"),
            dict(kind="trial", client="2008-06", addresses=["00401000"], outcome="no_gain")]
    journal.write_text("".join(json.dumps(row) + "\n" for row in rows))
    monkeypatch.setattr(agent_memory, "ROOT", pc)
    offline = agent_memory.shared("http://127.0.0.1:9", "test-token", "alice", upload=True)
    assert not offline["available"] and not offline.get("uploaded")
    result = agent_memory.shared(address, "test-token", "alice", upload=True)
    assert result["available"] and result["uploaded"] == 2 and result["rejected"] == 1
    assert [row["addresses"] for row in store.agent_memory()["records"]] == [["00401000"]]


def test_verification_receipts_match_the_report_client(shared_server):
    store, _ = shared_server
    source = "int f() { return 2; }"
    for client in ("2008-06", "2009-12"):
        store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,10,'Pilot')", (client,"00401000"))
    store.db.commit()
    store.submit("2009-12", "00401000", "alice", 99, source, verified=True)
    report = dict(kind="auto_target", client="2009-12", addresses=["00401000"], after=99,
        outcome="server_verified", source_hash=hashlib.sha256(source.encode()).hexdigest())
    store.remember("alice", [report])
    store.remember("alice", [dict(report, client="2008-06")])
    assert [row["server_confirmed"] for row in store.agent_memory()["records"]] == [True, False]
