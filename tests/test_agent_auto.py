import json
from pathlib import Path

import pytest

from roc import agent_auto


@pytest.fixture(autouse=True)
def offline_memory(monkeypatch):
    monkeypatch.setattr(agent_auto.agent_memory, "shared", lambda *a, **kw: {"available": True, "records": []})


def row(addr, score=98, source="int f() { return 1; }", **fields):
    return dict(addr=addr, score=score, source=source, unit="RBX", size=50, kind="code", **fields)


def test_ranking_uses_real_sources_and_family_donors():
    result = agent_auto.plan([
        row("00401000", shape="mov eax,N;ret"), row("00401010", 100, shape="mov eax,N;ret"),
        row("00401020", imports=["KERNEL32!EnterCriticalSection"]),
        row("00401030", source="// metadata only"),
        row("00401040", 80, source="// roc-lib: xtp-11.2.2-lib x.cpp"),
        row("00401050", 20),
    ], records=[])
    assert result["areas"][0]["id"] == "family"
    assert {a["id"] for a in result["areas"]} == {"family", "templates", "imports"}
    assert result["areas"][0]["targets"][0]["donors"][0]["score"] == 100
    assert result["excluded"]["no usable source; individual mining deferred"] == 1
    assert result["excluded"]["low similarity; needs stronger source evidence"] == 1
    assert "source" not in json.dumps(agent_auto.public_plan(result)["areas"][0]["examples"])


def test_parked_batches_require_same_profile_and_source_revision():
    rows = [row("00401000"), row("00401010")]
    target = agent_auto.plan(rows, records=[])["areas"][0]["targets"][0]
    records = [dict(kind="auto_batch", area="repair", profile="claude:default", group=target["group"], group_cohort=target["group_cohort"],
                    phase="repair", outcome="no_gain") for _ in range(2)]
    assert agent_auto.plan(rows, records=records)["areas"][0]["parked"]
    assert not agent_auto.plan(rows, profile="codex:default", records=records)["areas"][0]["parked"]
    rows[0]["source"] = "int f() { return 2; }"
    assert not agent_auto.plan(rows, records=records)["areas"][0]["parked"]


def make_task(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.match.clients, "load", lambda: {"2008-06": {"compiler_build": 21022}})
    folder = tmp_path / "work" / "agent-auto" / "run" / "00401000"
    folder.mkdir(parents=True)
    path = folder / "00401000.cpp"
    path.write_text("winner")
    (folder / "best.cpp").write_text("original")
    (folder / "task.json").write_text(json.dumps(dict(client="2008-06", addr="00401000",
        area="repair", profile="test", best_score=90)))
    return path


def test_source_free_targets_can_use_verified_family_seeds():
    result = agent_auto.plan([row("00401000", 0, source="", shape="mov eax,N;ret"),
                              row("00401010", 100, shape="mov eax,N;ret")], records=[])
    target = result["areas"][0]["targets"][0]
    assert target["area"] == "family" and target["source"]
    assert target["score"] == 0


def test_every_trial_journals_failure_and_keeps_best(tmp_path, monkeypatch):
    path = make_task(tmp_path, monkeypatch)
    def check(client, addr, source):
        if source == "broken":
            raise agent_auto.match.CompileError("bad C++")
        return (100 if source == "winner" else 10), "f", "diff", []
    monkeypatch.setattr(agent_auto.match, "check_text", check)
    assert agent_auto.trial("2008-06", "00401000", path, "import fix")["after"] == 100
    path.write_text("loser")
    agent_auto.trial("2008-06", "00401000", path, "wrong constant")
    path.write_text("broken")
    result = agent_auto.trial("2008-06", "00401000", path, "invalid declaration")
    assert result["outcome"] == "compile_failed"
    assert (path.parent / "best.cpp").read_text() == "winner"
    records = [json.loads(line) for line in (path.parent / "trials.jsonl").read_text().splitlines()]
    assert len(records) == 3 and records[1]["before"] == 100
    assert records[0]["compiler"] == 21022 and records[0]["source_hash"]
    with pytest.raises(ValueError):
        agent_auto.trial("2008-06", "00401010", path, "wrong target")
    with pytest.raises(ValueError):
        agent_auto.trial("2008-06", "00401000", tmp_path / "src.cpp", "shared file")


def test_run_reuses_before_models_and_leases_explicit_targets(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent, "memory_prompt", lambda *args: "memory")
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: ["2008-06"])
    rows = [row("00401000"), row("00401010"), row("00401020", imports=["CRT!f"]),
            row("00401030", imports=["CRT!f"])]
    monkeypatch.setattr(agent_auto, "snapshot", lambda api: rows)
    monkeypatch.setattr(agent_auto.match, "check_text", lambda c, a, s: (98, "f", "diff", []))
    order, calls, paths = [], [], []
    class Api:
        def __init__(self, *args):
            pass
        def call(self, endpoint, body=None, **kwargs):
            calls.append((endpoint, body))
            if endpoint == "/v1/info":
                return {"verify": ["2008-06"]}
            if endpoint == "/v1/lease":
                addr = body["targets"][0]["addr"]
                return {"job": dict(client="2008-06", addr=addr, source="int f() { return 1; }",
                                     score=98, lease=addr)}
            return {"ok": True}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    monkeypatch.setattr(agent_auto, "reuse", lambda task, portfolio, tried: (order.append("reuse"), paths.append(task["path"])))
    monkeypatch.setattr(agent_auto.agent, "run_agent", lambda *args: order.append("model") or 0)
    result = agent_auto.run("server", "me", workers=2, jobs=4, batch_size=2, log=lambda *args: None)
    assert order.count("reuse") == 4 and order.count("model") == 2
    assert order[:4] == ["reuse"] * 4
    assert len(set(paths)) == 4 and all("agent-auto" in path for path in paths)
    assert len([call for call in calls if call[0] == "/v1/release"]) == 8
    assert result["matched"] == 0 and result["errors"] == 0
    assert all(body["clients"] == ["2008-06"] and 1 <= len(body["targets"]) <= 32
               for endpoint, body in calls if endpoint == "/v1/lease")


def test_server_verified_reuse_is_counted_without_a_model(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: ["2008-06"])
    monkeypatch.setattr(agent_auto, "snapshot", lambda api: [row("00401000")])
    monkeypatch.setattr(agent_auto.match, "check_text", lambda *args: (100, "f", "", []))
    monkeypatch.setattr(agent_auto, "reuse", lambda *args: None)
    model_calls = []
    monkeypatch.setattr(agent_auto.agent, "run_agent", lambda *args: model_calls.append(args))
    class Api:
        exact = False
        def __init__(self, *args):
            pass
        def call(self, endpoint, body=None, **kwargs):
            if endpoint == "/v1/info":
                return {"verify": ["2008-06"]}
            if endpoint == "/v1/lease":
                return {"job": None if Api.exact else dict(addr="00401000", score=98, lease="L")}
            if endpoint == "/v1/submit":
                Api.exact = True
                return dict(verified=True, score=100, stored=100, improved=True)
            return {}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    totals = agent_auto.run("server", "me", jobs=1, log=lambda *args: None)
    assert totals["matched"] == 1 and not model_calls


def test_excluded_client_is_rejected_before_reading(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    with pytest.raises(ValueError, match="2008-06 only"):
        agent_auto.snapshot("2009-12")


def test_exhausted_family_does_not_park_other_shapes():
    rows = [row("00401000", shape="getter"), row("00401010", shape="getter"),
            row("00401020", shape="tree"), row("00401030", shape="tree")]
    target = agent_auto.plan(rows, records=[])["areas"][0]["targets"][0]
    records = [dict(kind="auto_batch", area="repair", phase="repair", profile="claude:default",
        group=target["group"], group_cohort=target["group_cohort"], outcome="no_gain") for _ in range(2)]
    area = agent_auto.plan(rows, records=records)["areas"][0]
    assert not area["parked"]
    assert sum(row["group_parked"] for row in area["targets"]) == 2


def test_shared_copy_of_one_failure_is_not_two_failed_batches():
    rows = [row("00401000")]
    target = agent_auto.plan(rows, records=[])["areas"][0]["targets"][0]
    record = dict(kind="auto_batch", date="2026-10-12T01:00:00", area="repair", phase="repair",
        profile="claude:default", group=target["group"], group_cohort=target["group_cohort"], outcome="no_gain")
    assert not agent_auto.plan(rows, records=[record, dict(record, reported_by="alice")])["areas"][0]["parked"]


def test_reuse_runs_compiler_gates_and_skips_known_failures(tmp_path, monkeypatch):
    folder = tmp_path / "work" / "agent-auto" / "run" / "reuse" / "00401000"
    folder.mkdir(parents=True)
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    source = "// roc-cl: 21022\n// roc-flags: /O2 /GS /MD\nint f() { return 1; }\n"
    path = folder / "00401000.cpp"
    path.write_text(source)
    (folder / "best.cpp").write_text(source)
    (folder / "task.json").write_text(json.dumps(dict(addr="00401000", client="2008-06", area="repair",
                                                      profile="p", best_score=95)))
    monkeypatch.setattr(agent_auto.match.clients, "load", lambda: {"2008-06": {"compiler_build": 21022}})
    gates = [s for s, _, _ in agent_auto.research.variants(source, profiles=agent_auto.GATES)]
    failed = {("00401000", agent_auto.digest(gates[0]))}
    checked = []
    monkeypatch.setattr(agent_auto.match, "check_text",
                        lambda c, a, text: checked.append(text) or (95, "f", "diff", []))
    task = dict(addr="00401000", path=str(path), source=source, donors=[], before=95)
    agent_auto.reuse(task, [], failed)
    # Skipped: the recorded failure, and the gate identical to the current source (21022 + keep).
    assert gates[0] not in checked and source not in checked and len(checked) == len(gates) - 2
    assert any("// roc-cl: 50727" in text for text in checked)
    assert agent_auto.known_failures([{"kind": "trial", "addresses": ["00401000"], "source_hash": "h",
                                       "outcome": "no_gain"}]) == {("00401000", "h")}
    assert path.read_text() == source  # best source restored after losing gates
