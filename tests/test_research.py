import json
import threading
import time
from types import SimpleNamespace

from roc import research


def test_journal_recovers_concatenated_records_and_appends_missing_newline(tmp_path):
    path = tmp_path / "attempts.jsonl"
    path.write_text('{"kind":"trial"}{"kind":"finding"}')
    research.append(path, {"kind": "tool_suggestion"})
    assert [row["kind"] for row in research.journal_records(path)] == ["trial", "finding", "tool_suggestion"]


def test_provider_auth_disables_queued_calls_until_new_gate():
    from roc import providers
    gate = providers.CloudGate()
    gate.disable("test")
    gate.done("test", True)
    gate.reset("test")
    try:
        gate.enter("test")
    except providers.ProviderError as error:
        assert error.category == "provider_circuit"
    else:
        raise AssertionError("Disabled provider accepted another call")


def test_research_cli_background_and_completion(monkeypatch, tmp_path, capsys):
    import argparse
    import importlib.util
    from pathlib import Path
    spec = importlib.util.spec_from_file_location("research_cli_test", Path(__file__).resolve().parents[1] / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    monkeypatch.setattr(cli, "ROOT", tmp_path)
    monkeypatch.setattr(research, "recipes", lambda: {"test": {"op": "grid"}})
    monkeypatch.setattr(research, "plan", lambda name: {})
    launched = []
    import os
    monkeypatch.setattr(cli.subprocess, "Popen", lambda command, **kwargs:
                        launched.append((command, kwargs)) or argparse.Namespace(pid=os.getpid()))
    args = argparse.Namespace(action="run", name="test", more=[], server="https://server", jobs=2,
                              limit=1, force=False, background=True, job_state=None)
    cli.cmd_research(args)
    cli.cmd_research(args)
    assert len(launched) == 1
    command, options = launched[0]
    assert "--limit" in command and "--job-state" in command
    assert command[command.index("--client") + 1] == "2008-06"
    assert options["stdin"] == cli.subprocess.DEVNULL
    state = Path(command[command.index("--job-state") + 1])
    args.background, args.job_state = False, str(state)
    monkeypatch.setattr(research, "run", lambda *args, **kwargs: {"new_verified": 0})
    cli.cmd_research(args)
    assert json.loads(state.read_text())["state"] == "done"
    args.action = "status"
    cli.cmd_research(args)
    assert '"done"' in capsys.readouterr().out


def test_job_status_detects_dead_process(tmp_path):
    import os
    import subprocess
    import sys
    process = subprocess.Popen([sys.executable, "-c", "pass"])
    process.wait(timeout=10)
    path = tmp_path / "job.json"
    path.write_text(json.dumps(dict(state="running", pid=process.pid)))
    assert research.job_status(path)["state"] == "interrupted"
    path.write_text(json.dumps(dict(state="running", pid=os.getpid())))
    assert research.job_status(path)["state"] == "running"


def test_research_receipt_is_recorded_before_run_finishes(tmp_path, monkeypatch):
    campaign = research.Campaign.__new__(research.Campaign)
    campaign.campaign_id, campaign.root, campaign.user = "own", tmp_path, "tester"
    campaign.info = dict(clients={"2008-06": {}}, verify=["2008-06"])
    campaign.api = SimpleNamespace(call=lambda *args, **kwargs:
        dict(verified=True, improved=True, score=100, stored=100))
    monkeypatch.setattr(campaign, "current", lambda *args: dict(score=90))
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.match, "check_text", lambda *args, **kwargs: (100, "f", "", []))
    campaign.submit_exact("pilot", "2008-06", "00401000", "int f(){return 1;}")
    rows = research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")
    assert rows[0]["campaign_id"] == "own" and rows[0]["receipt"]["improved"]


def test_research_lock_blocks_other_process_and_recovers_after_exit(tmp_path):
    import subprocess
    import sys
    import pytest
    from pathlib import Path
    path = tmp_path / "job.lock"
    code = "from pathlib import Path; from roc import research; import sys; " \
           "lock=research.job_lock(Path(sys.argv[1])); lock.__enter__(); print('ready', flush=True); sys.stdin.read()"
    process = subprocess.Popen([sys.executable, "-u", "-c", code, str(path)],
                               cwd=Path(__file__).resolve().parents[1], stdin=subprocess.PIPE,
                               stdout=subprocess.PIPE, text=True)
    try:
        assert process.stdout.readline().strip() == "ready"
        with pytest.raises(research.ResearchJobBusy):
            with research.job_lock(path):
                raise AssertionError("Duplicate lock acquired")
    finally:
        process.communicate(timeout=10)
    with research.job_lock(path):
        pass


def test_research_run_respects_selected_client_and_isolates_outputs(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.clients, "load", lambda: {
        "2008-06": {"compiler_build": 21022}, "2009-12": {"compiler_build": 30729}})
    monkeypatch.setattr(research, "recipes", lambda: {"test": {"op": "grid", "client": "2009-12"}})
    calls = []
    monkeypatch.setattr(research, "_run", lambda *args: calls.append(args) or {"client": args[-2]})
    research.run("test", client="2008-06")
    assert [args[-2] for args in calls] == ["2008-06"]
    calls.clear()
    research.run("test", client="all")
    assert [args[-2] for args in calls] == ["2008-06", "2009-12"]
    assert calls[0][-1] != calls[1][-1]
    calls.clear()
    research.run("test")
    assert calls[0][-2] == "2009-12"


def test_research_run_lock_blocks_duplicate_before_experiments(tmp_path, monkeypatch):
    import pytest
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.clients, "load", lambda: {"2008-06": {}})
    monkeypatch.setattr(research, "recipes", lambda: {"test": {"op": "grid"}})
    monkeypatch.setattr(research, "_run", lambda *args: (_ for _ in ()).throw(AssertionError("must not start")))
    with research.job_lock(tmp_path / "work/research/test/.research-job.lock"):
        with pytest.raises(research.ResearchJobBusy):
            research.run("test")


def test_grid_dispatch_uses_selected_client_compiler_and_memory(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.clients, "load", lambda: {"2009-12": {"compiler_build": 30729}})
    monkeypatch.setattr(research, "recipes", lambda: {"test": {"op": "grid", "builds": [21022]}})
    queried, compiled = [], []
    campaign = SimpleNamespace(root=tmp_path, api=SimpleNamespace(
        call=lambda path, **kwargs: queried.append(path) or [], close=lambda: None))
    monkeypatch.setattr(research, "Campaign", lambda *args: campaign)
    monkeypatch.setattr(research, "select", lambda rows, spec, client: rows)
    monkeypatch.setattr(research, "grid", lambda *args, **kwargs: compiled.append((args, kwargs)) or [])
    research._run("test", client="2009-12", output=tmp_path, log=lambda line: None)
    assert queried == ["/v1/sources?client=2009-12"]
    assert compiled[0][0][3] == [30729] and compiled[0][1]["client"] == "2009-12"
    assert research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")[0]["client"] == "2009-12"


def test_assigned_scratch_check_cannot_bypass_trial_journal(tmp_path, monkeypatch):
    import importlib.util
    from pathlib import Path
    spec = importlib.util.spec_from_file_location("assigned_check_cli_test", Path(__file__).resolve().parents[1] / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    path = tmp_path / "00401000.cpp"
    (tmp_path / "task.json").write_text("{}")
    calls = []
    monkeypatch.setattr(research, "trial", lambda *args:
                        calls.append(args) or dict(after=86, symbol="f", diff="diff"))
    monkeypatch.setattr(research.match, "check", lambda *args:
                        (_ for _ in ()).throw(AssertionError("must use journal")))
    cli.cmd_check(SimpleNamespace(name="2008-06", addr="00401000", file=str(path)))
    assert len(calls) == 1 and calls[0][2] == "00401000" and calls[0][3] == path


def test_fanout_prefetch_keeps_serial_matching_and_journaling(monkeypatch):
    main = threading.get_ident()
    lock = threading.Lock()
    active = peak = 0
    seen = []

    def compile_text(client, source):
        nonlocal active, peak
        with lock:
            active += 1
            peak = max(peak, active)
        time.sleep(.02)
        with lock:
            active -= 1
        return source.encode()

    class Target:
        def match_obj(self, obj, source):
            assert threading.get_ident() == main and obj == source.encode()
            seen.append(source)
            return {}

    class Campaign:
        api = SimpleNamespace(call=lambda *args, **kwargs: [])

        def previous(self, stage):
            return []

        def record(self, stage, row):
            assert threading.get_ident() == main

    monkeypatch.setattr(research.match, "compile_text", compile_text)
    monkeypatch.setattr(research, "unresolved", lambda client, scores: Target())
    research.fanout(Campaign(), "test", [(str(i), i) for i in range(9)], jobs=3, log=lambda line: None)
    assert sorted(seen) == [str(i) for i in range(9)]
    assert 2 <= peak <= 3


def test_fanout_streams_ready_wins_and_deduplicates_sources(monkeypatch):
    release = threading.Event()
    compiled, logs, receipts = [], [], []

    def compile_text(client, source):
        compiled.append(source)
        if source == "slow":
            assert release.wait(3), "Fast win must stream before slow compile finishes"
        return source.encode()

    class Target:
        def match_obj(self, obj, source):
            return {"00401000" if source == "fast" else "00401010": (0, "f")}

    class Campaign:
        api = SimpleNamespace(call=lambda *a, **kw: [])

        def previous(self, stage):
            return []

        def submit_exact(self, stage, client, addr, source, obj=None):
            assert obj == source.encode()
            return dict(addr=addr, submission=dict(verified=True, improved=True, score=100))

        def record(self, stage, row):
            if stage.endswith("-wins"):
                receipts.append(row)

    def log(line):
        logs.append(line)
        if "00401000" in line:
            release.set()

    monkeypatch.setattr(research.match, "compile_text", compile_text)
    monkeypatch.setattr(research, "unresolved", lambda *a: Target())
    winners = research.fanout(Campaign(), "test", [("slow", 1), ("fast", 2), ("fast", 3)], jobs=2, log=log)
    assert compiled.count("fast") == 1 and len(winners) == len(receipts) == 2
    assert "00401000" in logs[0]


def test_variants_replace_settings_and_keep_flags(monkeypatch):
    monkeypatch.setattr(research.clients, "load", lambda: {"2008-06": {"compiler_build": 21022}})
    source = "// roc-cl: 21022\n// roc-flags: /O2 /GS /MD\nint f();\n"
    out = list(research.variants(source, builds=(50727,), profiles=("keep", "/O1"), append=("", " /fp:fast")))
    assert [flags for _, _, flags in out] == ["/O2 /GS /MD", "/O2 /GS /MD /fp:fast", "/O1", "/O1 /fp:fast"]
    assert all(text.count("// roc-cl: 50727\n") == 1 and text.endswith("int f();\n") for text, _, _ in out)


def test_select_filters_by_score_size_unit_and_lib(monkeypatch):
    functions = {"00401000": {"size": 50, "unit": "Ogre::Node"}, "00401100": {"size": 900, "unit": "Ogre::Node"},
                 "00401200": {"size": 60, "unit": "RBX::Part"}}
    monkeypatch.setattr(research.match, "_functions", lambda client: functions)
    rows = [{"addr": a, "score": 95, "source": "// roc-lib: ogre-1.4.5-dll x.cpp\n"} for a in functions]
    rows.append({"addr": "00401000", "score": 100, "source": "x"})
    chosen = research.select(rows, {"unit": "^Ogre::", "sizes": [0, 512], "lib": "ogre"})
    assert [row["addr"] for row in chosen] == ["00401000"]


def test_audit_counts_unique_verified_new_exacts_only(tmp_path):
    receipt = {"verified": True, "improved": True, "score": 100}
    rows = [{"addr": "00401000", "submission": receipt},
            {"winners": [{"addr": "00401000", "submission": receipt}, {"addr": "00402000", "submission": receipt}]},
            {"addr": "00403000", "submission": dict(receipt, improved=False)},
            {"addr": "00404000", "client": "2009-12", "submission": receipt},
            {"error": "compile failed"}]
    (tmp_path / "stage.jsonl").write_text("".join(json.dumps(row) + "\n" for row in rows) + '{"torn":')
    result = research.audit(tmp_path)
    assert result["unique_verified_exacts"] == 2 and sorted(result["winners"]) == ["00401000", "00402000"]
    assert result["error_rows"] == {"stage.jsonl": 1}


def test_every_recipe_is_well_formed():
    for name, spec in research.recipes().items():
        assert spec["op"] in ("grid", "fanout") and spec.get("hypothesis"), name
        assert spec.get("client", "2008-06") == "2008-06", name
        if spec["op"] == "fanout":
            assert all(item["recipe"] in research.libs.RECIPES for item in spec["sources"]), name
