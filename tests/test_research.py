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


def test_journal_keeps_bom_prefixed_records(tmp_path):
    path = tmp_path / "attempts.jsonl"
    path.write_text('\ufeff{"kind":"trial"}\n\ufeff{"kind":"finding"}\n', encoding="utf-8")
    assert [row["kind"] for row in research.journal_records(path)] == ["trial", "finding"]


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
    assert options["env"]["PYTHONIOENCODING"] == "utf-8"
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
    cli.cmd_check(SimpleNamespace(name="2008-06", addr="00401000", file=str(path), context=0))
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
        line.encode("cp1252")  # Redirected Windows consoles must not interrupt accepted wins.
        logs.append(line)
        if "00401000" in line:
            assert any(row["addr"] == "00401000" for row in receipts)
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
        assert spec["op"] in ("grid", "fanout", "sweep", "mutate") and spec.get("hypothesis"), name
        assert spec.get("client", "2008-06") == "2008-06", name
        if spec["op"] == "sweep":
            stages = spec.get("stages", []) + [stage for group in spec.get("stages_by_client", {}).values() for stage in group]
            assert all(stage in research.recipes() and research.recipes()[stage]["op"] != "sweep" for stage in stages), name
        if spec["op"] == "fanout":
            assert spec.get("portfolio") is not None or spec.get("sources"), name
            assert all(item["recipe"] in research.libs.RECIPES for item in spec.get("sources", [])), name


def test_grid_parallel_targets_stop_at_exact_and_serialize_receipts(tmp_path, monkeypatch):
    barrier = threading.Barrier(2)
    receipt_active = threading.Lock()
    calls, records, receipts = [], [], []
    def check(client, addr, source):
        calls.append((addr, source))
        if source == "first":
            barrier.wait(timeout=5)
        return (100, "fn", "", [])
    def submit(stage, client, addr, source):
        assert receipt_active.acquire(blocking=False)
        try:
            time.sleep(.01)
            receipts.append(addr)
            return {"submission": {"verified": True, "improved": True}}
        finally:
            receipt_active.release()
    campaign = SimpleNamespace(previous=lambda stage: [], submit_exact=submit,
                               record=lambda stage, row: records.append(row))
    monkeypatch.setattr(research, "variants", lambda *a, **kw: iter([
        ("first", 21022, "normal"), ("unused", 50727, "fast")]))
    monkeypatch.setattr(research.match, "check_text", check)
    rows = [dict(addr=addr, score=90, source="starter") for addr in ("00401000", "00402000")]
    wins = research.grid(campaign, "parallel", rows, jobs=2, log=lambda line: None)
    assert sorted(calls) == [(row["addr"], "first") for row in rows]
    assert len(wins) == len(records) == len(receipts) == 2
    assert all(row["receipt"]["submission"]["verified"] for row in records)


def test_sweep_runs_only_selected_client_stages(tmp_path, monkeypatch):
    specs = {"all": dict(op="sweep", stages=["gates"], stages_by_client={
        "2008-06": ["native08"], "2009-12": ["native09"]}),
        "gates": dict(op="grid"), "native08": dict(op="fanout"), "native09": dict(op="fanout")}
    monkeypatch.setattr(research, "recipes", lambda: specs)
    calls = []
    monkeypatch.setattr(research, "run", lambda *args: calls.append(args) or dict(new_verified=1))
    result = research._run("all", jobs=3, client="2009-12", output=tmp_path, log=lambda line: None)
    assert [args[0] for args in calls] == ["native09", "gates"]
    assert all(args[-1] == "2009-12" and args[2] == 3 for args in calls)
    assert result["new_verified"] == 2


def test_compiler_evidence_changes_with_dependencies_target_and_client(monkeypatch):
    dependency, target = ["header one"], [b"code one"]
    monkeypatch.setattr(research.libs, "unit", lambda *args: dependency[0])
    monkeypatch.setattr(research.clients, "load", lambda: {
        "2008-06": dict(sha256="08"), "2009-12": dict(sha256="09")})
    monkeypatch.setattr(research.match, "target", lambda *args: (target[0], [], {}))
    row = dict(addr="00401000")
    source = "// roc-lib: native unit.cpp\n"
    def key(client="2008-06"):
        return research.compiler_evidence(client, row, source, 21022, "/O2", {})
    initial = key()
    assert key() == initial and key("2009-12") != initial
    dependency[0] = "header two"
    assert key() != initial
    dependency[0] = "header one"
    target[0] = b"code two"
    assert key() != initial


def test_grid_resume_across_campaigns_retries_changed_evidence_and_unverified_exact(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    key, score, checks = ["initial"], [90], []
    monkeypatch.setattr(research, "compiler_evidence", lambda *args: key[0])
    monkeypatch.setattr(research, "variants", lambda *args, **kwargs: iter([("variant", 21022, "/O2")]))
    monkeypatch.setattr(research.match, "check_text", lambda *args: checks.append(args) or (score[0], "fn", "", []))
    def rejected(*args):
        raise ValueError("verification unavailable")
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage: [], record=lambda *args: None, submit_exact=rejected)
    rows = [dict(addr="00401000", score=80, source="source")]
    def run(stage):
        research.grid(campaign, stage, rows, reuse_history=True, log=lambda line: None)
    run("first")
    run("other-campaign")
    assert len(checks) == 1
    key[0], score[0] = "changed", 100
    run("changed")
    run("retry-unverified")
    assert len(checks) == 3


def test_variants_do_not_duplicate_existing_precision_suffix():
    source = "// roc-flags: /O2 /fp:fast\nint f(){return 1;}"
    variants = list(research.variants(source, builds=[21022], profiles=["keep"], append=[" /fp:fast"]))
    assert variants[0][2] == "/O2 /fp:fast"


def test_fanout_failed_verification_restores_all_pending_hits(monkeypatch):
    from collections import defaultdict
    class Target:
        index = defaultdict(list, {6: ["first", "second"]})
        def match_obj(self, obj, source):
            hits = {addr: (source, "fn") for addr in self.index[6]}
            self.index[6].clear()
            return hits
    target, records, attempts = Target(), [], []
    class Campaign:
        api = SimpleNamespace(call=lambda *a, **kw: [])
        def previous(self, stage):
            return [dict(key=research.digest("retry"), retryable=True)]
        def submit_exact(self, stage, client, addr, source, obj=None):
            attempts.append((source, addr))
            if source == "retry":
                raise RuntimeError("verification unavailable")
            return dict(addr=addr, submission=dict(verified=True, improved=True, score=100))
        def record(self, stage, row):
            records.append((stage, row))
    monkeypatch.setattr(research, "unresolved", lambda *a: target)
    monkeypatch.setattr(research.match, "compile_text", lambda *a: b"obj")
    monkeypatch.setattr(research.match, "target", lambda *a: (b"123456", [], {}))
    wins = research.fanout(Campaign(), "retry-test", [("retry", {}), ("working", {})], log=lambda line: None)
    assert {addr for source, addr in attempts if source == "working"} == {"first", "second"}
    assert records[0][1]["retryable"]
    assert len([w for w in wins if w.get("submission", {}).get("verified")]) == 2
    assert target.index[6] == []


def test_fanout_identical_objects_skip_match_but_changed_data_does_not(monkeypatch):
    checked, records = [], []
    class Target:
        def match_obj(self, obj, source):
            checked.append(source)
            return {}
    class Campaign:
        api = SimpleNamespace(call=lambda *a, **kw: [])
        def previous(self, stage): return []
        def record(self, stage, row): records.append(row)
    monkeypatch.setattr(research, "unresolved", lambda *a: Target())
    monkeypatch.setattr(research.match, "compile_text", lambda client, source:
        b"COFF" + (b"time" if source == "first" else b"date") + (b"other-data" if source == "changed" else b"same-data"))
    research.fanout(Campaign(), "objects", [(source, {}) for source in ["first", "repeat", "changed"]], log=lambda line: None)
    assert checked == ["first", "changed"]
    assert records[1]["object_reused"] and not records[2]["object_reused"]


def test_fanout_resume_tracks_compiled_data_and_target_inventory(monkeypatch):
    rows, checked, compiled = [], [], []
    data, size = [b"data-one"], [6]
    class Target:
        def match_obj(self, obj, source):
            checked.append(obj)
            return {}
    class Campaign:
        api = SimpleNamespace(call=lambda *a, **kw: [])
        def previous(self, stage): return list(rows)
        def record(self, stage, row): rows.append(row)
    def compile_text(*args):
        compiled.append(args)
        return b"COFFtime" + data[0]
    monkeypatch.setattr(research, "unresolved", lambda *a: Target())
    monkeypatch.setattr(research.match, "compile_text", compile_text)
    monkeypatch.setattr(research.clients, "load", lambda: {"2008-06": dict(sha256="binary")})
    monkeypatch.setattr(research.match, "_functions", lambda *a: {"00401000": dict(size=size[0], relocs=[])})
    def run():
        research.fanout(Campaign(), "resume", [("same-source-header-changed", {})], evidence_resume=True, log=lambda line: None)
    run(); run()
    assert len(checked) == 1 and len(compiled) == 2
    data[0] = b"data-two"
    run()
    assert len(checked) == 2
    size[0] += 1
    run()
    assert len(checked) == 3


def test_fanout_recipe_streams_inputs_and_counts_limited_contexts(tmp_path, monkeypatch):
    produced = []
    monkeypatch.setattr(research, "recipes", lambda: {"stream": dict(op="fanout", sources=[])})
    monkeypatch.setattr(research, "Campaign", lambda *a: SimpleNamespace(root=tmp_path, api=SimpleNamespace(close=lambda: None)))
    def sources(*a, **kw):
        for index in range(20):
            produced.append(index)
            yield str(index), {}
    def fanout(campaign, stage, inputs, *a, **kw):
        assert produced == []
        assert [source for source, _ in inputs] == ["0", "1"]
        return []
    monkeypatch.setattr(research, "recipe_sources", sources)
    monkeypatch.setattr(research, "fanout", fanout)
    monkeypatch.setattr(research, "remember", lambda *a: None)
    result = research._run("stream", limit=2, output=tmp_path, log=lambda line: None)
    assert result["tried"] == 2 and produced == [0, 1]
def test_recipe_source_evidence_distinguishes_c_and_cpp(tmp_path, monkeypatch):
    from roc import libs, match

    monkeypatch.setattr(libs, "RECIPES", {"native": {"src": "native", "langs": ["c", "cpp"]}})
    monkeypatch.setattr(libs, "fetch", lambda name: tmp_path)
    item = dict(recipe="native", files=["owned.cpp"], builds=[21022], flags=["/O2"])
    rows = list(research.recipe_sources([item]))
    assert [evidence["lang"] for _, evidence in rows] == ["c", "cpp"]
    assert [match.directives(source)["lang"] for source, _ in rows] == ["c", "cpp"]
    assert rows[0][0] != rows[1][0]
    rows = list(research.recipe_sources([{**item, "langs": ["cpp"]}]))
    assert len(rows) == 1 and rows[0][1]["lang"] == "cpp"
