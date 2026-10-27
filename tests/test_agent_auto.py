import json
import threading
from pathlib import Path

import pytest

from roc import agent_auto


@pytest.fixture(autouse=True)
def offline_memory(monkeypatch, request):
    monkeypatch.setattr(agent_auto.agent_recovery, "packet", lambda *args: {"target_asm": ["ret"], "neighbours": []})
    monkeypatch.setattr(agent_auto.agent_recovery, "propagate", lambda *args: [])
    monkeypatch.setattr(agent_auto.agent_memory, "shared", lambda *a, **kw: {"available": True, "records": []})
    library_cycle = agent_auto.library_cycle
    if not request.node.name.startswith("test_prepare_clients"):
        monkeypatch.setattr(agent_auto, "prepare_clients", lambda *args: None)
    monkeypatch.setattr(agent_auto, "library_cycle", lambda *args, **kwargs:
                        None if args[0] == "server" else library_cycle(*args, **kwargs))


def row(addr, score=98, source="int f() { return 1; }", **fields):
    return dict(addr=addr, score=score, source=source, unit="RBX", size=50, kind="code", **fields)


def test_continuous_switches_after_no_gains_and_keeps_winning_strategy(monkeypatch):
    strategies, delays = [], []

    def cycle(*args):
        strategies.append(args[-1])
        return dict(attempted=2, matched=int(len(strategies) == 2), improved=0, errors=0)

    def pause(seconds):
        delays.append(seconds)
        if len(delays) == 3:
            raise KeyboardInterrupt

    monkeypatch.setattr(agent_auto, "run_cycle", cycle)
    monkeypatch.setattr(agent_auto.time, "sleep", pause)
    with pytest.raises(KeyboardInterrupt):
        agent_auto.run("server", "me", continuous=True, log=lambda *a: None)
    assert strategies == [0, 1, 1]
    assert delays == [5, 5, 5]


def test_continuous_idle_cycle_waits_before_refresh(monkeypatch):
    monkeypatch.setattr(agent_auto, "run_cycle", lambda *a: dict(attempted=0, matched=0, improved=0, errors=0))
    delays = []

    def pause(seconds):
        delays.append(seconds)
        raise KeyboardInterrupt

    monkeypatch.setattr(agent_auto.time, "sleep", pause)
    with pytest.raises(KeyboardInterrupt):
        agent_auto.run("server", "me", continuous=True, log=lambda *a: None)
    assert delays == [30]


def test_library_campaign_uses_real_recipes_all_sizes_and_rotates_strategy():
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    rows = [{**row("00401000", 91, source), "size": 5000}, row("00401010", 100, source),
            row("00401020", 99, "// roc-lib: invented-vendor x.cpp\n")]
    campaign = agent_auto.library_campaigns(rows, "2008-06", [])[0]
    assert campaign["library"] == "g3d-6.09/source"
    assert len(campaign["targets"]) == 1 and campaign["targets"][0]["size"] == 5000
    assert campaign["exact"] == 1 and campaign["strategy"] == 0
    records = [dict(kind="library_campaign", client="2008-06", library=campaign["library"],
                    cohort=campaign["revision"], profile="library-strategy-0", outcome="no_gain", tested_hypotheses=2)]
    assert agent_auto.library_campaigns(rows, "2008-06", records)[0]["strategy"] == 1
    for strategy in range(3):
        records.extend(dict(kind="library_campaign", client="2008-06", library=campaign["library"],
                            cohort=campaign["revision"], profile="library-strategy-%d" % strategy,
                            outcome="no_gain", tested_hypotheses=2) for _ in range(2))
    assert agent_auto.library_campaigns(rows, "2008-06", records) == []
    rows[0]["source"] += "// new evidence\n"
    assert agent_auto.library_campaigns(rows, "2008-06", records)
    assert agent_auto.library_campaigns(rows, "2009-12", records)


def test_campaign_choice_randomizes_least_tried_without_score_bias(monkeypatch):
    candidates = [dict(library="G3D", visits=1, verified_exacts_per_minute=100),
                  dict(library="Lua", visits=0, targets=[dict(score=99)]),
                  dict(library="Ogre", visits=0, targets=[dict(score=0)])]
    pools = []
    monkeypatch.setattr(agent_auto.random, "choice", lambda pool: pools.append(pool) or pool[-1])
    assert agent_auto.choose_campaign(candidates)["library"] == "Ogre"
    assert pools == [[(None, "Lua"), (None, "Ogre")], [candidates[2]]]


def test_campaign_largest_first_and_visits_survive_source_changes():
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    rows = [row("00401000", 99, source), {**row("00401010", 20, source), "size": 5000}]
    campaign = agent_auto.library_campaigns(rows, "2008-06", [])[0]
    records = [dict(kind="library_campaign", client="2008-06", library=campaign["library"],
                    cohort=campaign["revision"], profile="library-strategy-0", outcome="improved")]
    rows[0]["source"] += "// changed\n"
    refreshed = agent_auto.library_campaigns(rows, "2008-06", records)[0]
    assert refreshed["visits"] == 1
    assert [target["score"] for target in refreshed["targets"]] == [20, 99]


def test_campaign_packet_seeds_sources_and_ready_commands(tmp_path):
    campaign = dict(client="2008-06", targets=[row("00401000", source="int f(){return 1;}")])
    agent_auto.campaign_packet(campaign, tmp_path, "https://server", "tester")
    target = campaign["targets"][0]
    assert Path(target["file"]).read_text() == target["source"]
    assert 'agent-check' in target["check"] and '--hypothesis' in target["check"]
    assert '--user "tester"' in target["submit"]
    assert "--background" in campaign["research_commands"]["background"]
    assert json.loads((tmp_path / "campaign.json").read_text()) == campaign


def test_campaign_finalize_selects_best_current_or_preserved_candidate(tmp_path, monkeypatch):
    campaign = dict(client="2008-06", targets=[row("00401000", source="current")])
    agent_auto.campaign_packet(campaign, tmp_path, "https://server", "tester")
    path = Path(campaign["targets"][0]["file"])
    (path.parent / "best.cpp").write_text("preserved", encoding="utf-8")
    monkeypatch.setattr(agent_auto.match, "check_text", lambda client, addr, text:
                        (86 if text == "current" else 70, "f", "", []))
    submitted = []
    monkeypatch.setattr(agent_auto.worker, "submit_files", lambda *args, **kwargs:
                        submitted.append((kwargs["file"].read_text(),
                        json.loads((kwargs["file"].parent / "task.json").read_text()))))
    assert agent_auto.finalize_campaign(campaign, "https://server", "tester", None, lambda message: None) == []
    assert submitted[0][0] == "current" and submitted[0][1]["campaign_id"] == tmp_path.name


def test_short_untested_campaigns_do_not_park_strategies():
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    rows = [row("00401000", source=source)]
    campaign = agent_auto.library_campaigns(rows, "2008-06", [])[0]
    records = [dict(kind="library_campaign", client="2008-06", library=campaign["library"],
                    cohort=campaign["revision"], profile="library-strategy-%d" % strategy,
                    outcome="no_gain", elapsed_seconds=8) for strategy in range(3)]
    assert agent_auto.library_campaigns(rows, "2008-06", records)


def test_family_rotation_does_not_weight_versions(monkeypatch):
    candidates = [dict(library="ogre-1.4.5/src", family="Ogre", visits=0, family_visits=2),
                  dict(library="ogre-1.7.0/src", family="Ogre", visits=0, family_visits=2),
                  dict(library="g3d-6.09/source", family="G3D", visits=1, family_visits=1)]
    monkeypatch.setattr(agent_auto.random, "choice", lambda pool: pool[0])
    assert agent_auto.choose_campaign(candidates)["family"] == "G3D"


def test_campaign_includes_rtti_and_matching_neighbour_targets_without_sources():
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    rows = [{**row("00401000", 100, source), "size": 100},
            {**row("00401010", 0, ""), "unit": "seg_0040"},
            {**row("00401020", 100, source), "size": 100},
            {**row("00401030", 0, ""), "unit": "Ogre::SceneManager"}]
    campaigns = agent_auto.library_campaigns(rows, "2008-06", [])
    assert {c["family"]: [r["addr"] for r in c["targets"]] for c in campaigns} == {
        "G3D": ["00401010"], "Ogre": ["00401030"]}


def test_campaign_rotates_tried_target_until_evidence_changes():
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    rows = [{**row("00401000", source=source), "size": 5000}, row("00401010", source=source)]
    first = agent_auto.library_campaigns(rows, "2008-06", [])[0]["targets"][0]
    records = [dict(kind="trial", client="2008-06", addresses=[first["addr"]],
                    baseline_hash=first["baseline_hash"], target_revision=first["target_revision"], outcome="no_gain")]
    assert agent_auto.library_campaigns(rows, "2008-06", records)[0]["targets"][0]["addr"] == "00401010"
    rows[0]["source"] += "// new source\n"
    assert agent_auto.library_campaigns(rows, "2008-06", records)[0]["targets"][0]["addr"] == "00401000"


def test_campaign_cools_down_promoted_source_across_library_versions():
    from datetime import datetime, timezone, timedelta
    source = "// roc-lib: libpng-1.2.6 pngread.c\n"
    rows = [row("0051f140", 95, source)]
    record = dict(kind="trial", date=datetime.now(timezone.utc).isoformat(), client="2008-06",
                  addresses=["0051f140"], baseline_hash=agent_auto.digest(""),
                  target_revision="old-zero-score-revision", source_hash=agent_auto.digest(source), outcome="improved")
    assert not agent_auto.library_campaigns(rows, "2008-06", [record])
    record["date"] = (datetime.now(timezone.utc) - timedelta(minutes=11)).isoformat()
    campaign = agent_auto.library_campaigns(rows, "2008-06", [record])[0]
    assert campaign["targets"][0]["trial_visits"] == 1
    record["date"] = datetime.now(timezone.utc).isoformat()
    rows[0]["source"] += "// new evidence\n"
    assert agent_auto.library_campaigns(rows, "2008-06", [record])


def test_campaign_results_only_credit_own_verified_improvement_receipts():
    rows = [dict(campaign_id="own", receipt=dict(verified=True, improved=True, stored=100), addresses=["00401000"]),
            dict(campaign_id="other", receipt=dict(verified=True, improved=True, stored=100), addresses=["00401010"]),
            dict(campaign_id="own", receipt=dict(verified=True, improved=False, stored=100), addresses=["00401020"])]
    assert agent_auto.campaign_results("own", rows) == ({"00401000": 100}, 0)


def test_source_policy_failures_do_not_exhaust_campaign_hypotheses():
    rows = [dict(campaign_id="own", kind="trial", outcome="compile_failed", hypothesis="vendor source",
                 error='#import, #using, #include "file" and #pragma comment are not allowed'),
            dict(campaign_id="own", kind="trial", outcome="compile_failed", hypothesis="other source",
                 validation_failed=True)]
    assert agent_auto.campaign_results("own", rows) == ({}, 0)


def test_default_automatic_mode_uses_ranked_repair_batches(monkeypatch):
    calls = []
    monkeypatch.setattr(agent_auto, "library_cycle", lambda *args: pytest.fail("library campaigns were removed"))
    monkeypatch.setattr(agent_auto, "run_cycle", lambda *args: calls.append(args) or
                        dict(attempted=1, matched=0, improved=0, errors=0))
    assert agent_auto.run("server", "me", workers=1)["attempted"] == 1
    assert len(calls) == 1


def test_failed_target_stays_parked_when_only_sibling_evidence_changes():
    rows = [row("00401000", shape="shape"), row("00401010", shape="shape")]
    target = agent_auto.plan(rows, records=[])["areas"][0]["targets"][0]
    records = [dict(kind="auto_target", client="2008-06", phase="repair", repair_attempted=True,
                    addresses=[target["addr"]], evidence_hash=target["evidence_hash"], outcome="no_gain")]
    rows[1]["source"] += "// changed sibling\n"
    targets = agent_auto.plan(rows, records=records)["areas"][0]["targets"]
    assert {r["addr"]: r["group_parked"] for r in targets} == {"00401000": True, "00401010": False}
    rows[0]["source"] += "// fresh source\n"
    assert not any(r["group_parked"] for r in agent_auto.plan(rows, records=records)["areas"][0]["targets"])


@pytest.mark.parametrize("failure", ["exit", "exception", "edited_exception", "invalid_edited_exception"])
def test_cli_failure_stops_further_paid_batches_without_parking_targets(tmp_path, monkeypatch, failure):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda *args: ["2008-06"])
    rows = [row("004010%02x" % index, shape="same") for index in range(4)]
    monkeypatch.setattr(agent_auto, "snapshot", lambda *args, **kwargs: rows)
    def check(*args):
        if "bad edit" in args[2]:
            raise agent_auto.match.CompileError("bad edit does not compile")
        return (100 if "repaired" in args[2] else 98, "f", "diff", [])
    monkeypatch.setattr(agent_auto.match, "check_text", check)
    monkeypatch.setattr(agent_auto, "reuse", lambda *args: None)
    calls = []
    def fail(*args, **kwargs):
        calls.append(args)
        args[4]("provider output before failure")
        if "edited" in failure:
            path = next(p for p in (tmp_path / "work/agent-auto").glob("*/repair/2008-06/*/*.cpp")
                        if p.name != "best.cpp")
            path.write_text("bad edit" if failure.startswith("invalid") else "int repaired(){return 1;}")
        if failure.endswith("exception"):
            raise OSError(22, "Invalid argument")
        return 1
    monkeypatch.setattr(agent_auto.agent, "run_agent", fail)

    class Api:
        def __init__(self, *args):
            pass

        def call(self, endpoint, body=None, **kwargs):
            if endpoint == "/v1/info":
                return dict(clients={"2008-06": {}}, verify=["2008-06"])
            if endpoint == "/v1/lease":
                addr = body["targets"][0]["addr"]
                return {"job": dict(client="2008-06", addr=addr, source="int f(){return 1;}", score=98, lease=addr)}
            if endpoint == "/v1/submit":
                return dict(verified=True, improved=True, score=body["score"])
            return {"ok": True}

    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    totals = agent_auto.run_cycle("server", "tester", jobs=4, workers=1, batch_size=2, minutes=1, log=lambda *args: None)
    assert totals["matched"] == int(failure == "edited_exception")
    assert len(calls) == 1
    records = agent_auto.history()
    repairs = [r for r in records if r.get("kind") == "auto_batch" and r.get("phase") == "repair"]
    assert len(repairs) == 1 and repairs[0]["skip_reason"] == "cli_error"
    assert repairs[0]["outcome"] == ("improved" if failure == "edited_exception" else "error")
    assert not repairs[0]["exhausted"]
    summary = json.loads(next((tmp_path / "work/agent-auto").glob("*/summary.json")).read_text())
    assert summary["stop_reason"] == "cli_error"
    assert summary["batch_outcomes"]["repair:cli_error"] == 1
    assert summary["time_budget_seconds"] == 60 and summary["workers"] == 1
    result_path = next((tmp_path / "work/agent-auto").glob("*/repair/2008-06/*/model-result.json"))
    result = json.loads(result_path.read_text())
    assert result["exit_code"] == 1 and not result["interrupted"]
    output = agent_auto.research.journal_records(result_path.with_name("agent-output.jsonl"))
    assert output[0]["message"] == "provider output before failure"
    assert result["agent_output_tail"][0] == "provider output before failure"
    if failure.endswith("exception"):
        assert result["error"]["type"] == "OSError"
        assert "Invalid argument" in result["error"]["traceback"]
        assert "Agent CLI exception: OSError" in output[-1]["message"]
    else:
        assert result["error"] is None


def test_pull_sources_downloads_on_a_new_pc_without_local_analysis(monkeypatch):
    calls = []

    class Api:
        def __init__(self, *args):
            pass

        def call(self, path):
            assert path == "/v1/info"
            return {"clients": {"2008-06": {}}}

    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    monkeypatch.setattr(agent_auto.worker, "pull_files",
                        lambda server, client, token, force, log: calls.append((server, client, token, force)))
    agent_auto.pull_sources("https://server.test", "token", "2008-06", lambda _: None)
    assert calls == [("https://server.test", "2008-06", "token", False)]


def test_prepare_clients_fetches_then_analyzes_missing_laptop_target(tmp_path, monkeypatch):
    calls = []
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.clients, "load", lambda: {"2008-06": {"exe": "Roblox.exe", "compiler_build": 21022}})
    monkeypatch.setattr(agent_auto.clients, "status", lambda *args: "missing")
    monkeypatch.setattr(agent_auto.clients, "ensure", lambda name: calls.append(("fetch", name)) or True)
    monkeypatch.setattr(agent_auto.clients, "exe_path", lambda *args: "Roblox.exe")
    monkeypatch.setattr(agent_auto.setup, "compilers", lambda: {21022: "cl.exe"})
    monkeypatch.setattr("roc.analyze.analyze", lambda name, exe: calls.append(("analyze", name, exe)))
    agent_auto.prepare_clients("2008-06", lambda _: None)
    assert calls == [("fetch", "2008-06"), ("analyze", "2008-06", "Roblox.exe")]


def test_prepare_clients_installs_the_missing_exact_compiler(tmp_path, monkeypatch):
    calls, installed = [], {}
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    (tmp_path / "work" / "2008-06").mkdir(parents=True)
    (tmp_path / "work" / "2008-06" / "functions.jsonl").write_text("")
    monkeypatch.setattr(agent_auto.clients, "load", lambda: {"2008-06": {"compiler_build": 21022}})
    monkeypatch.setattr(agent_auto.clients, "status", lambda *args: "ok")
    monkeypatch.setattr(agent_auto.setup, "compilers", lambda: dict(installed))
    monkeypatch.setattr(agent_auto.setup, "install_compilers",
                        lambda only, assume_yes: calls.append((only, assume_yes)) or installed.update({21022: "cl.exe"}))
    agent_auto.prepare_clients("2008-06", lambda _: None)
    assert calls == [([21022], True)]


def test_campaign_materializes_only_missing_target_sources(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    campaign = {"client": "2008-06", "targets": [
        {"addr": "00401000", "source": "int new_source;"},
        {"addr": "00401010", "source": "int kept_source;"}]}
    kept = tmp_path / "src" / "2008-06" / "00401010.cpp"
    kept.parent.mkdir(parents=True)
    kept.write_text("local edit")
    assert agent_auto.materialize_campaign_sources(campaign) == 1
    assert (tmp_path / "src" / "2008-06" / "00401000.cpp").read_text() == "int new_source;"
    assert kept.read_text() == "local edit"


def test_automatic_campaigns_include_nonlibrary_categories():
    campaigns = agent_auto.library_campaigns([row("00401000", imports=["KERNEL32!Sleep"])], "2008-06", [])
    assert campaigns[0]["library"] == "Category: Imported calls"
    assert campaigns[0]["recipes"] == []
    assert campaigns[0]["targets"][0]["addr"] == "00401000"


@pytest.mark.parametrize("exit_mode", ["complete", "error", "exception"])
def test_library_cycle_records_server_observed_gains_and_research_scope(tmp_path, monkeypatch, exit_mode):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto, "finalize_campaign", lambda *args: [])
    monkeypatch.setattr(agent_auto, "history", lambda: [])
    monkeypatch.setattr(agent_auto.agent, "memory", lambda *a: {})
    source = "// roc-lib: g3d-6.09 GLG3Dcpp/Sky.cpp\n"
    monkeypatch.setattr(agent_auto, "snapshot", lambda *a: [row("00401000", 91, source),
                        row("00401010", 99, imports=["KERNEL32!Sleep"])])
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: list(info["clients"]))

    class Api:
        def __init__(self, *args):
            pass

        def call(self, path, **kwargs):
            if path == "/v1/info":
                return dict(clients={"2008-06": {}}, verify=["2008-06"])
            assert path == "/v1/sources?scores=1&client=2008-06"
            return [row("00401000", 100, source), row("00401010", 100)]

    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    prompts = []
    def run_agent(cli, prompt, model, minutes, output, **kwargs):
        prompts.append(prompt)
        output("Stopped: missing vendor evidence")
        if exit_mode == "exception":
            raise RuntimeError("CLI launch failed")
        return int(exit_mode == "error")
    monkeypatch.setattr(agent_auto.agent, "run_agent", run_agent)
    logs = []
    totals = agent_auto.library_cycle("https://example.test", "tester", None, "codex", None, 1,
                                    logs.append, "2008-06")
    assert totals == dict(attempted=1, matched=0, improved=0, errors=int(exit_mode != "complete"))
    assert not any("server verified exact" in line for line in logs)
    assert "Client: 2008-06" in prompts[0] and "g3d-6.09" in prompts[0]
    assert "research/recipes.json" in prompts[0] and "libs.add_unit" in prompts[0]
    assert "No unrelated infrastructure edits" in prompts[0]
    record = [r for r in map(json.loads, (tmp_path / "work/agent-memory/attempts.jsonl").read_text().splitlines())
              if r["kind"] == "library_campaign"][0]
    assert record["outcome"] == ("incomplete" if exit_mode == "complete" else "error") and record["addresses"] == []
    assert record["observed_server_gains"] == 2
    assert record["profile"] == "library-strategy-0"
    assert record["stop_reason"] == {"complete": "no_recorded_trials", "error": "agent_exit_error", "exception": "agent_exception"}[exit_mode]
    assert record["agent_exit_code"] == int(exit_mode != "complete")
    assert record["trials_recorded"] == 0
    output_rows = agent_auto.research.journal_records(Path(record["agent_output"]))
    assert output_rows[0]["message"] == "Stopped: missing vendor evidence"
    assert record["agent_output_tail"]


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


def test_random_pool_includes_zero_score_and_sourceless_functions():
    result = agent_auto.plan([row("00401000", 99), row("00401010", 10),
        row("00401020", 0, source=""), row("00401030", 100),
        {**row("00401040", 0), "kind": "data"}, {**row("00401050", 0), "size": 1024}],
        records=[], random_targets=True)
    targets = {r["addr"]: r for area in result["areas"] for r in area["targets"]}
    assert set(targets) == {"00401000", "00401010", "00401020"}
    assert targets["00401020"]["source"] == "void func_00401020() {}\n"


def test_random_batches_sample_functions_before_grouping(monkeypatch):
    areas = [dict(client="2008-06", parked=False, targets=[
        dict(addr="near", group="a", group_parked=False, score=99),
        dict(addr="zero", group="b", group_parked=False, score=0),
        dict(addr="parked", group="b", group_parked=True, score=98)]),
        dict(client="2009-12", parked=False, targets=[
        dict(addr="other-client", group="b", group_parked=False, score=5)])]
    seen = []
    def draw(root, pool, n, scope, **kwargs):
        seen.extend(pool)
        return pool[-n:]
    monkeypatch.setattr(agent_auto.agent_recovery, "draw", draw)
    batches = agent_auto.random_batches({"areas": areas}, jobs=2, batch_size=1)
    assert [row["addr"] for row in seen] == ["near", "zero", "other-client"]
    assert [(area["client"], rows[0]["addr"]) for area, rows in batches] == [
        ("2008-06", "zero"), ("2009-12", "other-client")]


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
    monkeypatch.setattr(agent_auto.match, "ROOT", tmp_path)
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


def test_ranking_uses_verified_exacts_per_minute_and_close_sources():
    rows = [row("00401000", 94), row("00401010", 99), row("00401020", 99, imports=["IAT!f"])]
    records = [dict(kind="auto_batch", area="repair", outcome="improved", exacts_gained=2,
                    elapsed_seconds=60, gains=2, addresses=["00401000", "00401010"]),
               dict(kind="auto_batch", area="imports", outcome="improved", exacts_gained=1,
                    elapsed_seconds=600, gains=1, addresses=["00401020"])]
    area = agent_auto.plan(rows, records=records)["areas"][0]
    assert area["id"] == "repair" and area["verified_exacts_per_minute"] == 2
    assert area["targets"][0]["addr"] == "00401010"


def test_exhausted_batch_parks_across_models_until_source_changes():
    rows = [row("00401000")]
    target = agent_auto.plan(rows, records=[])["areas"][0]["targets"][0]
    record = dict(kind="auto_batch", area="repair", profile="claude:default", outcome="no_gain",
                  exhausted=True, group=target["group"], group_cohort=target["group_cohort"])
    assert agent_auto.plan(rows, profile="codex:default", records=[record])["areas"][0]["parked"]
    rows[0]["source"] += "int new_evidence;"
    assert not agent_auto.plan(rows, records=[record])["areas"][0]["parked"]


def test_every_trial_journals_failure_and_keeps_best(tmp_path, monkeypatch):
    path = make_task(tmp_path, monkeypatch)
    def check(client, addr, source, **kwargs):
        if source == "broken":
            raise agent_auto.match.CompileError("bad C++")
        return (100 if source == "winner" else 10), "f", "diff", []
    monkeypatch.setattr(agent_auto.match, "check_text", check)
    monkeypatch.setattr(agent_auto.match, "compile_text", lambda c, text: text.encode())
    monkeypatch.setattr(agent_auto.match, "target", lambda *a: (b"target", [], 0))
    assert agent_auto.trial("2008-06", "00401000", path, "import fix")["after"] == 100
    repeated = agent_auto.trial("2008-06", "00401000", path, "same edit")
    assert repeated["duplicate"] and repeated["after"] == 100
    path.write_text("loser")
    agent_auto.trial("2008-06", "00401000", path, "wrong constant")
    path.write_text("broken")
    result = agent_auto.trial("2008-06", "00401000", path, "invalid declaration")
    assert result["outcome"] == "compile_failed"
    assert agent_auto.trial("2008-06", "00401000", path, "same invalid declaration")["duplicate"]
    assert (path.parent / "best.cpp").read_text() == "winner"
    records = [json.loads(line) for line in (path.parent / "trials.jsonl").read_text().splitlines()]
    assert len(records) == 3 and records[1]["before"] == 100
    assert records[0]["compiler"] == 21022 and records[0]["source_hash"]
    with pytest.raises(ValueError):
        agent_auto.trial("2008-06", "00401010", path, "wrong target")
    with pytest.raises(ValueError):
        agent_auto.trial("2008-06", "00401000", tmp_path / "src.cpp", "shared file")


def test_run_reuses_before_models_and_assigns_explicit_targets(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent, "memory_prompt", lambda *args: "memory")
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: ["2008-06"])
    rows = [row("00401000"), row("00401010"), row("00401020", imports=["CRT!f"]),
            row("00401030", imports=["CRT!f"])]
    monkeypatch.setattr(agent_auto, "snapshot", lambda client, api: rows)
    monkeypatch.setattr(agent_auto.match, "check_text", lambda c, a, s: (98, "f", "diff", []))
    order, calls, paths, prompts = [], [], [], []
    class Api:
        def __init__(self, *args):
            pass
        def call(self, endpoint, body=None, **kwargs):
            calls.append((endpoint, body))
            if endpoint == "/v1/info":
                return {"clients": {"2008-06": {}}, "verify": ["2008-06"]}
            if endpoint == "/v1/lease":
                addr = body["targets"][0]["addr"]
                return {"job": dict(client="2008-06", addr=addr, source="int f() { return 1; }",
                                     score=98, lease=addr)}
            return {"ok": True}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    monkeypatch.setattr(agent_auto, "reuse", lambda task, portfolio, tried, swept=frozenset(): (order.append("reuse"), paths.append(task["path"])))
    monkeypatch.setattr(agent_auto.agent, "run_agent", lambda cli, prompt, *args, **kwargs:
                        (order.append("model"), prompts.append(prompt))[1] or 0)
    result = agent_auto.run("server", "me", workers=2, jobs=4, batch_size=2, log=lambda *args: None)
    assert order.count("reuse") == 4 and order.count("model") == 4
    assert all("ONE unresolved function" in prompt and "never their directory" in prompt for prompt in prompts)
    assert all("Read available project context" not in prompt for prompt in prompts)
    assert all('"diff": "diff"' in prompt for prompt in prompts)
    assert all("ONE unresolved function" in prompt and "agent-block" in prompt for prompt in prompts)
    assert all(isinstance(json.loads(prompt.split("\nAssignment:\n")[1]), dict) for prompt in prompts)
    assert order[:4] == ["model"] * 4 and order[4:] == ["reuse"] * 4
    assert len(set(paths)) == 4 and all("agent-auto" in path for path in paths)
    assert [call for call in calls if call[0] == "/v1/release"]  # batches free their server claims
    assert result["matched"] == 0 and result["errors"] == 0
    assert all(body["clients"] == ["2008-06"] and 1 <= len(body["targets"]) <= 32
               for endpoint, body in calls if endpoint == "/v1/lease")


def test_automatic_allows_independent_random_singletons(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent, "memory_prompt", lambda *a: "memory")
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda *a: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda *a: ["2008-06"])
    rows = [{**row("00401000"), "size": 96, "unit": "One"}, {**row("00401010"), "size": 96, "unit": "Two"}]
    monkeypatch.setattr(agent_auto, "snapshot", lambda *a, **kw: rows)
    monkeypatch.setattr(agent_auto.match, "check_text", lambda *a: (98, "f", "diff", []))
    monkeypatch.setattr(agent_auto, "reuse", lambda *a: None)
    prompts = []
    monkeypatch.setattr(agent_auto.agent, "run_agent", lambda cli, prompt, *a, **kw: prompts.append(prompt) or 0)

    class Api:
        def __init__(self, *a):
            pass

        def call(self, endpoint, body=None, **kw):
            if endpoint == "/v1/info":
                return {"clients": {"2008-06": {}}, "verify": ["2008-06"]}
            if endpoint == "/v1/lease":
                addr = body["targets"][0]["addr"]
                return {"job": dict(client="2008-06", addr=addr, source="int f(){return 1;}", score=98, lease=addr)}
            return {"ok": True}

    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    agent_auto.run_cycle("server", "tester", jobs=2, workers=2, batch_size=1, minutes=1, log=lambda *a: None)
    assert len(prompts) == 2
    assert all("ONE unresolved function" in prompt and "initial_evidence_file" in prompt for prompt in prompts)
    for prompt in prompts:
        assignment = json.loads(prompt.split("\nAssignment:\n")[1])
        initial = json.loads(Path(assignment["initial_evidence_file"]).read_text(encoding="utf-8"))
        full = json.loads(Path(assignment["evidence_file"]).read_text(encoding="utf-8"))
        assert initial["full_evidence_file"] == assignment["evidence_file"]
        assert initial.get("target_asm") == full.get("target_asm")
        assert "source" not in initial


def test_server_verified_reuse_is_counted_without_a_model(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: ["2008-06"])
    monkeypatch.setattr(agent_auto, "snapshot", lambda client, api: [row("00401000")])
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
                return {"clients": {"2008-06": {}}, "verify": ["2008-06"]}
            if endpoint == "/v1/lease":
                return {"job": None if Api.exact else dict(addr="00401000", score=98, lease="L")}
            if endpoint == "/v1/submit":
                Api.exact = True
                return dict(verified=True, score=100, stored=100, improved=True)
            return {}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    totals = agent_auto.run("server", "me", jobs=1, log=lambda *args: None)
    assert totals["matched"] == 1 and not model_calls


def test_unknown_client_is_rejected_before_reading(tmp_path, monkeypatch):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    with pytest.raises(ValueError, match="Unknown client"):
        agent_auto.snapshot("unknown-client")


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
                        lambda c, a, text, **kw: checked.append(text) or (95, "f", "diff", []))
    monkeypatch.setattr(agent_auto.match, "compile_text", lambda c, text: text.encode())
    monkeypatch.setattr(agent_auto.match, "target", lambda *a: (b"target", [], 0))
    task = dict(addr="00401000", path=str(path), source=source, donors=[], before=95)
    agent_auto.reuse(task, [], failed)
    # Skipped: the recorded failure, and the gate identical to the current source (21022 + keep).
    assert gates[0] not in checked and source not in checked and len(checked) == len(gates) - 2
    assert any("// roc-cl: 50727" in text for text in checked)
    assert agent_auto.known_failures([{"kind": "trial", "addresses": ["00401000"], "source_hash": "h",
                                       "outcome": "no_gain"}]) == {("00401000", "h")}
    assert path.read_text() == source  # best source restored after losing gates


def test_all_clients_keep_same_addresses_and_receipts_isolated(tmp_path, monkeypatch):
    names = ["2008-06", "2009-12"]
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    scopes = []
    monkeypatch.setattr(agent_auto.worker, "usable_clients",
        lambda info, log: scopes.append(sorted(info["clients"])) or sorted(info["clients"]))
    monkeypatch.setattr(agent_auto, "snapshot", lambda client, api: [row("00401000")])
    checked, paths, submitted = [], [], []
    monkeypatch.setattr(agent_auto.match, "check_text", lambda client, addr, source:
        checked.append(client) or (100 if source == "winner" else 98, "f", "diff", []))
    def reuse(task, portfolio, tried, swept=frozenset()):
        paths.append(task["path"])
        (Path(task["path"]).parent / "best.cpp").write_text("winner")
    monkeypatch.setattr(agent_auto, "reuse", reuse)
    def no_model(*args, **kwargs):
        return 0  # Random singleton gets its model attempt before compiler reuse.
    monkeypatch.setattr(agent_auto.agent, "run_agent", no_model)
    class Api:
        exact = set()
        def __init__(self, *args):
            pass
        def call(self, endpoint, body=None, **kwargs):
            if endpoint == "/v1/info":
                return {"clients": {name: {} for name in names}, "verify": names}
            if endpoint == "/v1/lease":
                client = body["clients"][0]
                assert all(target["client"] == client for target in body["targets"])
                return {"job": None if client in self.exact else dict(client=client,
                    addr="00401000", score=98, lease=client)}
            if endpoint == "/v1/submit":
                assert body["lease"] == body["client"]
                self.exact.add(body["client"])
                submitted.append(body["client"])
                return dict(verified=True, improved=True, score=100)
            return {}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    totals = agent_auto.run("server", "me", jobs=2, workers=2, log=lambda *args: None, client="all")
    assert totals["matched"] == 2 and totals["errors"] == 0
    assert sorted(submitted) == sorted(names) and set(checked) == set(names)
    assert len(set(paths)) == 2
    assert scopes == [sorted(names)]
    records = agent_auto.history()
    assert {record["client"] for record in records} == set(names)
    monkeypatch.setattr(agent_auto, "history", lambda: [])  # Isolate subsequent client-scope checks from no-gain parking.
    Api.exact.clear()
    submitted.clear()
    agent_auto.run("server", "me", jobs=1, log=lambda *args: None, client="2009-12")
    assert scopes[-1] == ["2009-12"] and submitted == ["2009-12"]
    Api.exact.clear()
    submitted.clear()
    agent_auto.run("server", "me", jobs=1, log=lambda *args: None)
    assert scopes[-1] == ["2008-06"] and submitted == ["2008-06"]


def test_parking_and_groups_are_client_specific():
    rows = [row("00401000")]
    first = agent_auto.plan(rows, records=[], client="2008-06")["areas"][0]["targets"][0]
    second = agent_auto.plan(rows, records=[], client="2009-12")["areas"][0]["targets"][0]
    assert first["group"] != second["group"]
    records = [dict(kind="auto_batch", client="2008-06", area="repair", phase="repair",
        profile="claude:default", group=second["group"], group_cohort=second["group_cohort"],
        outcome="no_gain") for _ in range(2)]
    assert not agent_auto.plan(rows, records=records, client="2009-12")["areas"][0]["parked"]


@pytest.mark.parametrize("leased_client,leased_addr", [("2009-12", "00401000"), ("2008-06", "00409999")])
def test_out_of_scope_lease_is_released_before_compile(tmp_path, monkeypatch, leased_client, leased_addr):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.agent.shutil, "which", lambda cli: "fake-cli")
    monkeypatch.setattr(agent_auto.worker, "usable_clients", lambda info, log: ["2008-06"])
    monkeypatch.setattr(agent_auto, "snapshot", lambda client, api: [row("00401000")])
    def forbidden(*args):
        raise AssertionError("Out-of-scope target must never compile or launch model")
    monkeypatch.setattr(agent_auto.match, "check_text", forbidden)
    monkeypatch.setattr(agent_auto.agent, "run_agent", forbidden)
    calls = []
    class Api:
        def __init__(self, *args):
            pass
        def call(self, endpoint, body=None, **kwargs):
            calls.append((endpoint, body))
            if endpoint == "/v1/info":
                return {"clients": {"2008-06": {}, "2009-12": {}}, "verify": ["2008-06", "2009-12"]}
            if endpoint == "/v1/lease":
                return {"job": dict(client=leased_client, addr=leased_addr, score=98, lease="wrong")}
            if endpoint == "/v1/submit":
                forbidden()
            return {}
    monkeypatch.setattr(agent_auto.worker, "Api", Api)
    result = agent_auto.run("server", "me", jobs=1, log=lambda *args: None, client="2008-06")
    assert result["errors"] == 2 and result["attempted"] == 0  # Both phases reject the bad lease.
    assert len([body for endpoint, body in calls if endpoint == "/v1/release" and body["lease"] == "wrong"]) == 2


def test_unlimited_plan_includes_large_functions():
    rows = [row("00401000")]
    rows[0]["size"] = 2_000_000
    assert not agent_auto.plan(rows, max_size=512, records=[])["areas"]
    result = agent_auto.plan(rows, max_size=0, records=[])
    assert result["areas"][0]["targets"][0]["size"] == 2_000_000


def test_continuous_stops_after_three_failed_cycles(monkeypatch):
    calls = []
    monkeypatch.setattr(agent_auto, "run_cycle", lambda *a: calls.append(a) or
                        dict(attempted=1, matched=0, improved=0, errors=1))
    monkeypatch.setattr(agent_auto.time, "sleep", lambda seconds: None)
    with pytest.raises(RuntimeError, match="Three consecutive"):
        agent_auto.run("server", "me", continuous=True, log=lambda *a: None)
    assert len(calls) == 3


def test_snapshot_pages_sources_and_keeps_three_donors(monkeypatch, tmp_path):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.match.clients, "load", lambda: {"C": {}})
    folder = tmp_path / "work" / "C"
    folder.mkdir(parents=True)
    functions = [dict(addr="%08x" % i, shape="same", size=20) for i in range(5)]
    (folder / "functions.jsonl").write_text("\n".join(json.dumps(r) for r in functions), encoding="utf-8")
    pages = [[dict(addr=r["addr"], score=100 if i<4 else 90, source="int f(){return %s;}" % i)
              for i,r in enumerate(functions[:3])],
             [dict(addr=functions[3]["addr"], score=100, source="unused donor"),
              dict(addr=functions[4]["addr"], score=90, source="repair me")], []]
    calls = []
    class Api:
        def call(self, path, timeout):
            calls.append(path)
            return pages.pop(0)
    rows = agent_auto.snapshot("C", Api())
    assert all("/v1/source-page?" in path for path in calls)
    assert "after=00000002" in calls[1]
    assert "after=00000004" in calls[2]
    assert rows[3]["score"] == 100 and rows[3]["source"] == ""
    assert rows[4]["source"] == "repair me"
    assert sum(bool(r["source"]) for r in rows if r["score"] == 100) == 3


def test_snapshot_bounds_behavior_metadata_before_planning(monkeypatch, tmp_path):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.match.clients, "load", lambda: {"C": {}})
    folder = tmp_path / "work" / "C"
    folder.mkdir(parents=True)
    (folder / "functions.jsonl").write_text(json.dumps(dict(addr="00000001", shape="same", size=20,
        callers=list(range(1000)), constants=list(range(100)), relocs=list(range(1000)))), encoding="utf-8")
    class Api:
        def call(self, *a, **kw):
            return []
    row = agent_auto.snapshot("C", Api())[0]
    assert row["callers"] == [0,1,2,3]
    assert row["constants"] == list(range(8))
    assert "relocs" not in row


def test_local_snapshot_accepts_source_without_saved_score(monkeypatch, tmp_path):
    monkeypatch.setattr(agent_auto, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto.match.clients, "load", lambda: {"C": {}})
    folder = tmp_path / "work/C"
    folder.mkdir(parents=True)
    (folder / "functions.jsonl").write_text(json.dumps(dict(addr="00401000", size=20)))
    source = tmp_path / "src/C/00401000.cpp"
    source.parent.mkdir(parents=True)
    source.write_text("void f() {}")
    row = agent_auto.snapshot("C")[0]
    assert row["score"] == 0 and row["source"] == "void f() {}"
