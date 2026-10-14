import pytest

from roc import agent


@pytest.fixture(autouse=True)
def offline_memory(monkeypatch):
    """Never sync test attempts with the real group server."""
    synced = []
    monkeypatch.setattr(agent, "sync_memory", lambda *args, **kwargs: synced.append(args) or {})
    return synced


def test_goal_and_interactive_sessions_sync_shared_memory(monkeypatch, offline_memory):
    monkeypatch.setattr(agent, "run_agent", lambda *args, **kwargs: 0)
    agent.run_goal("claude", "match zlib", minutes=1, log=lambda *a: None)
    monkeypatch.setattr(agent.shutil, "which", lambda cli: "/bin/" + cli)
    monkeypatch.setattr(agent.subprocess, "call", lambda argv, cwd: 0)
    agent.interactive("claude", "match zlib")
    assert len(offline_memory) == 4  # before and after each session


def test_continuous_goal_refreshes_memory_and_changes_strategy(monkeypatch, offline_memory):
    prompts = []

    def run(cli, prompt, model, minutes, log, goal):
        prompts.append(prompt)
        log("No gain: rejected previous hypothesis")
        return 0

    def pause(seconds):
        if len(prompts) == 2:
            raise KeyboardInterrupt

    monkeypatch.setattr(agent, "run_agent", run)
    monkeypatch.setattr(agent.time, "sleep", pause)
    with pytest.raises(KeyboardInterrupt):
        agent.run_goal("codex", "Match Ogre", continuous=True, log=lambda *a: None)
    assert len(offline_memory) == 4
    assert "Current strategy: Use fresh target diffs" in prompts[0]
    assert "Current strategy: Inspect vendor build preludes" in prompts[1]
    assert "No gain: rejected previous hypothesis" in prompts[1]


def test_goal_shortlist_skips_blocked_revision_until_evidence_changes(monkeypatch):
    from roc import agent_auto
    rows = [dict(client="C", addr="00401000", unit="Unit", score=99, size=500,
                 priority=80, group_parked=False, evidence_hash="revision", source_hash="source")]
    monkeypatch.setattr(agent_auto, "history", lambda: [dict(kind="goal_blocked", client="C",
                        addresses=["00401000"], cohort="revision")])
    monkeypatch.setattr(agent_auto, "portfolio", lambda *a, **kw: {"areas": [{"targets": rows}]})
    assert agent.goal_targets("localhost", None, "C", {}) == []
    rows[0]["evidence_hash"] = "new-evidence"
    assert agent.goal_targets("localhost", None, "C", {})[0]["addr"] == rows[0]["addr"]


class FakeApi:
    servers, token = ["http://x"], None

    def __init__(self):
        self.calls = []

    def call(self, path, body=None):
        self.calls.append((path, body))
        return {"stored": body.get("score")} if path == "/v1/submit" else {}


def run_job(tmp_path, monkeypatch, start, edited, job_score=0):
    monkeypatch.setattr(agent, "ROOT", tmp_path)
    path = tmp_path / "src" / "c" / "00401000.cpp"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(start)
    scores = {"start": 40, "better": 90, "worse": 10}
    monkeypatch.setattr(agent, "score", lambda c, a, p: scores[p.read_text()])
    monkeypatch.setattr(agent.match, "save_score", lambda *a: None)
    prompts = []
    monkeypatch.setattr(agent, "run_agent", lambda cli, prompt, *a: (prompts.append(prompt), path.write_text(edited)))
    api = FakeApi()
    job = {"client": "c", "addr": "00401000", "lease": "L", "score": job_score, "size": 8, "unit": "u"}
    result = agent.work_one(api, "me", "agent-1", job, "claude", None, 1, lambda *a: None)
    return result, path.read_text(), api.calls, prompts[0]


def test_improvement_is_submitted(tmp_path, monkeypatch):
    result, text, calls, prompt = run_job(tmp_path, monkeypatch, "start", "better")
    assert result == 90 and text == "better"
    assert calls[-1][0] == "/v1/submit" and calls[-1][1]["score"] == 90 and calls[-1][1]["source"] == "better"
    assert 'roc.py" check c 00401000' in prompt and "src/c/00401000.cpp" in prompt


def test_regression_is_rolled_back_and_released(tmp_path, monkeypatch):
    result, text, calls, _ = run_job(tmp_path, monkeypatch, "start", "worse", job_score=40)
    assert result == 40 and text == "start"
    assert calls[-1][0] == "/v1/release"


def test_commands_read_prompt_from_stdin():
    claude = agent.command("claude", "haiku")
    assert claude[:4] == ["claude", "-p", "--model", "haiku"] and "acceptEdits" in claude and "stream-json" in claude
    assert "Read,Grep,Glob,Edit,Write,Bash,PowerShell,mcp__ghidra__*" in claude
    assert agent.command("codex")[-1] == "-"
    assert agent.command("opencode", "opencode/big-pickle")[-2:] == ["-m", "opencode/big-pickle"]
    assert "--standalone" in agent.command("opencode") and "--thinking" in agent.command("opencode")
    lines = []
    agent.show('{"type":"tool_use","part":{"tool":"shell","state":{"input":{"command":"echo hi"}}}}', lines.append)
    agent.show('{"type":"text","part":{"text":"done"}}', lines.append)
    assert lines == ["  > shell echo hi", "done"]


def test_opencode_keeps_thinking_and_tool_outputs():
    import json
    lines = []
    agent.show(json.dumps({"type": "reasoning", "part": {"text": "Inspect target diff."}}), lines.append)
    agent.show(json.dumps({"type": "tool_use", "part": {"tool": "shell", "state": {
        "input": {"command": "roc check C 00401000"}, "output": "99%", "time": {"start": 1000, "end": 39000}}}}), lines.append)
    assert lines == ["Thinking · Inspect target diff.", "  > shell roc check C 00401000",
                     "Command finished · exit 0\n99%", "  < 38.0s shell roc check C 00401000"]


def test_opencode_powershell_failure_is_not_reported_as_exit_zero():
    import json
    lines = []
    agent.show(json.dumps({"type": "tool_use", "part": {"tool": "shell", "state": {
        "input": {"command": "head -40"}, "output": "head : not recognized\n    + FullyQualifiedErrorId : CommandNotFoundException"}}}), lines.append)
    assert lines[1].startswith("Command finished · exit 1")


def test_goal_mode_allows_roc_commands_and_web(monkeypatch):
    tools = next(arg for arg in agent.command("claude", goal=True) if arg.startswith("Read,"))
    assert "WebSearch" in tools and "Bash,PowerShell" in tools
    seen = []
    monkeypatch.setattr(agent, "run_agent", lambda cli, prompt, model, minutes, log, goal: seen.append((prompt, goal)))
    agent.run_goal("claude", "match RakNet in 2008-06", minutes=5, log=lambda *a: None)
    assert "match RakNet in 2008-06" in seen[0][0] and seen[0][1] is True


def test_goal_shortlist_mixes_near_large_and_random(monkeypatch):
    from roc import agent_auto
    rows = [dict(client="C", addr="%08x" % n, unit="Unit", score=99 if n < 30 else 30,
                 size=n*100, priority=100-n, group_parked=False, evidence_hash=str(n), source_hash=str(n)) for n in range(70)]
    monkeypatch.setattr(agent_auto, "history", lambda: [])
    monkeypatch.setattr(agent_auto, "portfolio", lambda *a, **kw: {"areas": [{"targets": rows}]})
    targets = agent.goal_targets("localhost", None, "C", {})
    assert [sum(row["selection"] == label for row in targets) for label in ("near-miss", "large", "explore")] == [14,7,3]
    assert len({row["addr"] for row in targets}) == 24
    assert any(row["score"] < 70 for row in targets)


def test_function_evidence_resolves_neighbors_without_inventing_semantics():
    row = dict(callers=["00401000"], call_targets=["00402000", "00403000"],
               strings=["a"*300], this_writes=[16], calling_convention="callee")
    evidence = agent.function_evidence(row, {"00401000": {"unit": "RBX::Load"}, "00402000": {"unit": "operator new"}})
    assert evidence["callers"][0]["unit"] == "RBX::Load"
    assert evidence["call_targets"][1]["unit"] == "unknown"
    assert evidence["this_writes"] == [16] and len(evidence["strings"][0]) == 160
    assert "likely_behavior" not in evidence


def test_goal_seeds_candidate_and_supplies_runnable_commands(tmp_path, monkeypatch):
    from roc import agent_auto
    monkeypatch.setattr(agent, "ROOT", tmp_path)
    monkeypatch.setattr(agent_auto, "prepare_clients", lambda *a: None)
    monkeypatch.setattr(agent, "goal_targets", lambda *a: [dict(client="C", addr="00401000", unit="Unit", size=500,
        score=99, selection="near-miss", source="int f(){return 1;}", evidence_hash="revision", source_hash="source")])
    prompts = []
    monkeypatch.setattr(agent, "run_agent", lambda cli, prompt, *a, **kw: prompts.append(prompt) or 0)
    assert agent.run_goal("opencode", "match", server="localhost", user="tester", log=lambda *a: None) == 0
    files = list((tmp_path / "work" / "agent-goals").glob("*/C/00401000.cpp"))
    assert len(files) == 1 and files[0].read_text() == "int f(){return 1;}"
    assert "Candidate files already exist" in prompts[0] and "--file" in prompts[0]


def test_every_agent_prompt_requests_concision_and_fast_work(monkeypatch):
    prompts = []
    monkeypatch.setattr(agent, "fallbacks", lambda: [])
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, *a: prompts.append(prompt) or 0)
    for cli in agent.CLIS:
        assert agent.run_agent(cli, "Assigned target", minutes=1) == 0
    assert len(prompts) == 3
    for prompt in prompts:
        assert "Be very concise." in prompt and "Optimize tokens and wall time" in prompt
        assert "Reuse cached compiler results" in prompt and "Assigned target" in prompt
        assert "libs.source_for" in prompt and "g3d-6.09-ijg jidctflt.c" in prompt
        assert "two materially different approaches" in prompt and "Infer likely function behavior" in prompt
        assert "caveman" not in prompt.lower()


def test_dashboard_agent_command_args():
    import pytest
    from roc.gui import command_args
    assert command_args({"command": "agent", "cli": "codex", "goal": "match zlib", "minutes": 30}) == [
        "agent", "codex", "--goal", "match zlib", "--minutes", "30"]
    for bad in ({"cli": "bash", "goal": "x"}, {"cli": "claude", "goal": " "}, {"cli": "claude", "goal": "x", "minutes": 0}):
        with pytest.raises(ValueError):
            command_args({"command": "agent", **bad})
    automatic = command_args({"command": "agent", "cli": "codex", "automatic": True,
                              "workers": 3, "model": "chosen-model", "individual": True})
    assert "--automatic" in automatic and "--goal" not in automatic
    assert automatic[automatic.index("--workers") + 1] == "3"
    assert automatic[-2:] == ["--model", "chosen-model"] and "--individual" in automatic
    for fields in ({"workers": 0}, {"jobs": 201}, {"batch_size": 0}, {"batch_minutes": 121},
                   {"max_size": -1}, {"model": "--bad"}):
        with pytest.raises(ValueError):
            command_args({"command": "agent", "cli": "claude", "automatic": True, **fields})


def test_stream_events_become_console_lines():
    lines = []
    agent.show('{"type":"assistant","message":{"content":[{"type":"text","text":"Trying zlib."},'
               '{"type":"tool_use","name":"Bash","input":{"command":"roc check 2008-06 00401000\\nmore"}}]}}', lines.append)
    agent.show('{"type":"result","num_turns":7,"is_error":false}', lines.append)
    agent.show("plain text\n", lines.append)
    assert lines == ["Trying zlib.", "  > Bash roc check 2008-06 00401000\nmore", "Agent finished after 7 turns.", "plain text"]


def test_slow_tool_calls_are_timed_and_remembered(tmp_path, monkeypatch):
    import json
    clock = iter([100.0, 310.0])
    monkeypatch.setattr(agent.time, "monotonic", lambda: next(clock))
    monkeypatch.setattr(agent, "SLOW_LOG", tmp_path / "slow.jsonl")
    lines = []
    agent.show(json.dumps({"type": "assistant", "message": {"content": [
        {"type": "tool_use", "id": "t1", "name": "Bash", "input": {"command": "roc mass 2008-06"}}]}}), lines.append)
    agent.show(json.dumps({"type": "user", "message": {"content": [
        {"type": "tool_result", "tool_use_id": "t1", "content": "ok"}]}}), lines.append)
    assert lines == ["  > Bash roc mass 2008-06", "Command finished · exit 0\nok", "  < 210.0s SLOW Bash roc mass 2008-06"]
    assert agent.memory()["slow_commands"][0]["seconds"] == 210


def test_codex_stream_hides_prompt_and_keeps_commands_results_errors():
    import json
    lines = []
    events = [
        {"type": "thread.started", "thread_id": "test"},
        {"type": "item.completed", "item": {"type": "user_message", "text": "huge prompt"}},
        {"type": "item.started", "item": {"type": "command_execution", "command": "roc check"}},
        {"type": "item.completed", "item": {"type": "command_execution", "exit_code": 0, "aggregated_output": "98%"}},
        {"type": "item.completed", "item": {"type": "agent_message", "text": "G3D checked"}},
        {"type": "turn.failed", "error": {"message": "test failure"}},
    ]
    for event in events:
        agent.show(json.dumps(event), lines.append)
    assert lines == ["Agent session started.", "  > roc check", "Command finished · exit 0\n98%", "G3D checked", "Agent error: test failure"]
    assert "--json" in agent.command("codex")


def test_interactive_sends_one_safe_line(monkeypatch):
    seen = []
    monkeypatch.setattr(agent.shutil, "which", lambda cli: "/bin/" + cli)
    monkeypatch.setattr(agent.subprocess, "call", lambda argv, cwd: seen.append(argv) or 0)
    agent.interactive("claude", 'match "RakNet"\n100% of 2008', "sonnet")
    argv = seen[0]
    assert argv[:3] == ["/bin/claude", "--model", "sonnet"] and "\n" not in argv[3] and '"' not in argv[3]
    assert "%" not in argv[3] and "CLAUDE.md" in argv[3]


def test_session_and_setup_open_a_terminal(monkeypatch):
    import pytest
    opened = []
    monkeypatch.setattr(agent, "_terminal", lambda argv: opened.append(argv))
    monkeypatch.setattr(agent.shutil, "which", lambda name: None)
    agent.open_session("codex", "match zlib", "gpt-5")
    assert opened[0][2:] == ["agent", "codex", "--interactive", "--goal", "match zlib", "--model", "gpt-5"]
    agent.open_setup("claude")
    assert "npm install -g @anthropic-ai/claude-code" in " ".join(opened[1])
    agent.open_setup("opencode")
    assert "opencode auth login" in " ".join(opened[2]) and "npm install -g opencode-ai" in " ".join(opened[2])
    for bad in (("bash", "x"), ("claude", " "), ("claude", "x" * 2001)):
        with pytest.raises(ValueError):
            agent.open_session(*bad)
    with pytest.raises(ValueError):
        agent.open_setup("bash")


def test_memory_ranks_evidence_and_keeps_negative_results(tmp_path, monkeypatch):
    import json
    monkeypatch.setattr(agent, "ROOT", tmp_path)
    (tmp_path / "research").mkdir()
    (tmp_path / "research" / "lessons.json").write_text(json.dumps([
        {"id": "rejected", "exacts_gained": 0}, {"id": "winner", "exacts_gained": 321}]))
    path = tmp_path / "work" / "agent-memory" / "attempts.jsonl"
    path.parent.mkdir(parents=True)
    path.write_text("\n".join(json.dumps({"after": n}) for n in range(25)) + '\n{"incomplete":')
    data = agent.memory()
    assert [item["id"] for item in data["lessons"]] == ["winner", "rejected"]
    assert len(data["recent"]) == 7 and data["recent"][-1]["after"] == 24
    assert "winner" in agent.memory_prompt() and "Record EVERY trial" in agent.memory_prompt()


def test_memory_prompt_bounds_context_and_prioritizes_family():
    data = {"lessons": [{"id": "xtp-%d" % n, "client": "2008-06"} for n in range(10)] +
            [{"id": "ogre-rejected", "client": "2008-06", "outcome": "rejected"},
             {"id": "other-client", "client": "2009-12"}],
            "recent": [{"client": "2009-12"}], "shared_recent": [], "slow_commands": []}
    prompt = agent.memory_prompt(data, "2008-06", "ogre-1.4.5/ogrenew")
    assert "ogre-rejected" in prompt and "other-client" not in prompt
    assert "xtp-4" in prompt and "xtp-5" not in prompt
    assert len(data["lessons"]) == 12  # Rendering must not change shared memory.


def test_session_memory_records_rollback_and_server_result(tmp_path, monkeypatch):
    import json
    run_job(tmp_path, monkeypatch, "start", "worse", job_score=40)
    run_job(tmp_path, monkeypatch, "start", "better", job_score=40)
    records = [json.loads(line) for line in
               (tmp_path / "work" / "agent-memory" / "attempts.jsonl").read_text().splitlines()]
    assert records[0]["outcome"] == "rolled_back"
    assert records[0]["candidate"] == 10 and records[0]["after"] == 40
    assert records[0]["before_hash"] == records[0]["after_hash"]
    assert records[1]["server_stored"] == 90 and records[1]["outcome"] == "improved"


@pytest.mark.parametrize("cli", ["claude", "codex"])
def test_early_cli_exit_logs_real_error_and_returns_failure(monkeypatch, cli):
    import io
    from unittest.mock import Mock
    class ClosedInput:
        def write(self, text):
            raise BrokenPipeError("child exited")
        def close(self):
            raise BrokenPipeError("child exited")
    process = Mock(stdin=ClosedInput(), stdout=io.StringIO("error: rejected CLI argument\n"))
    process.wait.return_value = 2
    monkeypatch.setattr(agent.shutil, "which", lambda cli: cli)
    monkeypatch.setattr(agent.subprocess, "Popen", lambda *a, **kw: process)
    lines = []
    assert agent.run_agent(cli, "prompt", log=lines.append) == 2
    assert "error: rejected CLI argument" in lines
    assert process.stdout.closed
    process.wait.assert_called_once()


def test_codex_launch_uses_supported_sandbox_flags():
    args = agent.command("codex", "selected-model")
    assert "--full-auto" not in args
    assert args[args.index("--sandbox") + 1] == "workspace-write"
    assert 'approval_policy="never"' in args
    assert args[args.index("--model") + 1] == "selected-model"


def test_goal_cli_propagates_failed_agent_exit(monkeypatch):
    import importlib.util
    from pathlib import Path
    spec = importlib.util.spec_from_file_location("roc_agent_exit_test", Path(__file__).resolve().parents[1] / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    monkeypatch.setattr(agent, "run_goal", lambda *a, **kw: 2)
    with pytest.raises(SystemExit) as error:
        cli.main(["agent", "codex", "--goal", "Match G3D", "--client", "2008-06"])
    assert error.value.code == 2


def test_rate_limited_agent_switches_to_the_next_model(monkeypatch):
    calls, clock = [], [0.0]
    monkeypatch.setattr(agent.time, "sleep", lambda seconds: clock.__setitem__(0, clock[0] + seconds))
    monkeypatch.setattr(agent.time, "monotonic", lambda: clock[0])
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:opencode/big-pickle, codex")
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, model, minutes, log, goal, switch:
                        calls.append((cli, model, bool(switch))) or (agent.RATE_LIMITED if cli != "codex" else 0))
    assert agent.run_agent("claude", "p", "sonnet", 30, lambda *a: None) == 0
    assert calls == [("claude", "sonnet", True), ("claude", "sonnet", True),
                     ("opencode", "opencode/big-pickle", True), ("opencode", "opencode/big-pickle", True), ("codex", None, False)]
    assert clock[0] == 360
    assert agent.DEAD.search("Model exo-free has been deprecated.") and not agent.DEAD.search("Upstream request failed: Model is unavailable.") and agent.RATE.search("Upstream request failed: Model is unavailable.")
    assert agent.RATE.search("Error: 429 rate limit reached") and not agent.RATE.search("ran 429 tests")


def test_transient_upstream_failure_retries_before_switching(monkeypatch):
    calls, clock = [], [0.0]
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:opencode/other")
    monkeypatch.setattr(agent.time, "sleep", lambda s: clock.__setitem__(0, clock[0] + s))
    monkeypatch.setattr(agent.time, "monotonic", lambda: clock[0])
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, model, minutes, log, goal, switch:
                        calls.append(model) or (agent.TRANSIENT if model == "a" else 0))
    assert agent.run_agent("opencode", "p", "a", 60, lambda *a: None) == 0
    assert calls == ["a", "a", "opencode/other"] and clock[0] == 180


def test_short_batch_reserves_time_for_fallback(monkeypatch):
    calls, clock = [], [0.0]
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:opencode/other")
    monkeypatch.setattr(agent.time, "monotonic", lambda: clock[0])
    monkeypatch.setattr(agent.time, "sleep", lambda seconds: clock.__setitem__(0, clock[0] + seconds))

    def run(cli, prompt, model, minutes, log, goal, switch):
        calls.append((model, minutes, switch))
        return agent.TRANSIENT if model == "a" else 0

    monkeypatch.setattr(agent, "_run_once", run)
    assert agent.run_agent("opencode", "p", "a", 5, lambda *a: None) == 0
    assert calls[0][2] == 2.5
    assert calls[-1][0] == "opencode/other" and calls[-1][1] >= 2


def test_subminute_batch_still_runs(monkeypatch):
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", " ")
    calls = []
    monkeypatch.setattr(agent, "_run_once", lambda *args: calls.append(args) or 0)
    assert agent.run_agent("codex", "p", minutes=0.5) == 0
    assert len(calls) == 1


def test_rate_limit_recovery_keeps_same_model_after_three_minutes(monkeypatch):
    clock, calls, sleeps = [0.0], [], []
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:other")
    monkeypatch.setattr(agent.time, "monotonic", lambda: clock[0])
    def sleep(seconds):
        sleeps.append(seconds)
        clock[0] += seconds
    monkeypatch.setattr(agent.time, "sleep", sleep)
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, model, *args:
                        calls.append(model) or (agent.RATE_LIMITED if len(calls) == 1 else 0))
    assert agent.run_agent("opencode", "p", "cat-jam", 10, lambda *args: None) == 0
    assert calls == ["cat-jam", "cat-jam"] and clock[0] == 180
    assert max(sleeps) <= 30


def test_retry_wait_respects_remaining_agent_budget(monkeypatch):
    clock, calls = [0.0], []
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:other")
    monkeypatch.setattr(agent.time, "monotonic", lambda: clock[0])
    monkeypatch.setattr(agent.time, "sleep", lambda seconds: clock.__setitem__(0, clock[0] + seconds))
    monkeypatch.setattr(agent, "_run_once", lambda *args: calls.append(args) or agent.RATE_LIMITED)
    assert agent.run_agent("opencode", "p", "cat-jam", 2, lambda *args: None) == 1
    assert len(calls) == 1 and clock[0] == 120


def test_rate_limit_ignores_tool_output_but_sees_api_errors():
    import json
    tool = json.dumps({"type": "user", "message": {"content": [{"type": "tool_result", "tool_use_id": "t",
        "content": "error C2668: ambiguous call to overloaded function; rate limit table"}]}})
    assert not agent.RATE.search(agent._error_text(tool))
    api = json.dumps({"type": "assistant", "message": {"model": "<synthetic>", "content": [
        {"type": "text", "text": "API Error: 429 rate_limit_error"}]}})
    assert agent.RATE.search(agent._error_text(api))
    assert agent.RATE.search(agent._error_text(json.dumps({"type": "result", "is_error": True,
                                                           "result": "Claude usage limit reached"})))
    assert agent.RATE.search(agent._error_text("Error: 429 Too Many Requests\n"))


def test_evidence_marks_matched_neighbours_read_only():
    row = {"callers": ["a", "b", "c"]}
    evidence = agent.function_evidence(row, {"a": {"unit": "u", "score": 100}, "b": {"unit": "u", "score": 80}})
    assert evidence["callers"][0] == {"addr": "a", "unit": "u", "score": 100, "matched_read_only": True}
    assert evidence["callers"][1] == {"addr": "b", "unit": "u", "score": 80}
    assert evidence["callers"][2] == {"addr": "c", "unit": "unknown"}  # unknown score is not shown as 0


def test_agent_check_refuses_server_matched_function(monkeypatch, capsys):
    import importlib.util
    from pathlib import Path
    from roc import worker
    spec = importlib.util.spec_from_file_location("roc_agent_check_test", Path(__file__).resolve().parents[1] / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    monkeypatch.setattr(cli, "settings", lambda: {"server": "http://x"})
    monkeypatch.setattr(worker.Api, "call", lambda self, path, *a, **kw: {"score": 100})
    with pytest.raises(SystemExit) as error:
        cli.main(["agent-check", "2008-06", "00401000", "x.cpp", "--hypothesis", "h"])
    assert error.value.code == 3 and "already matched" in capsys.readouterr().out


def test_goal_targets_skip_functions_failed_in_earlier_sessions(monkeypatch):
    from roc import agent_auto
    rows = [dict(client="c", addr=addr, score=99, priority=1, size=10, group_parked=False, evidence_hash="h")
            for addr in ("a", "b")]
    monkeypatch.setattr(agent_auto, "history", lambda: [])
    monkeypatch.setattr(agent_auto, "portfolio", lambda *a, **kw: {"areas": [{"targets": [dict(r) for r in rows]}]})
    monkeypatch.setattr(agent.worker, "Api", lambda *a: None)
    failed = [dict(kind="agent_check", client="c", addresses=["a"], after=90, date="2026-10-%02dT10:00" % day)
              for day in (1, 2, 3)]
    failed += [dict(kind="trial", client="c", addresses=[["a"]], after=[90], date="2026-10-04T10:00"),
               dict(kind="session", client="c", addresses="a", date="2026-10-05T10:00")]  # malformed shared rows
    picked = agent.goal_targets("s", None, "c", {"records": failed})
    assert [row["addr"] for row in picked] == ["b"]
    once = agent.goal_targets("s", None, "c", {"records": failed[:1]})
    assert [row["addr"] for row in once][0] == "b" and once[1]["prior_sessions"] == 1


def test_reuse_gate_sweep_runs_once_per_source(tmp_path, monkeypatch):
    from roc import research
    calls = []
    monkeypatch.setattr(research, "variants", lambda source, **kw: calls.append(source) or [])
    monkeypatch.setattr(research, "trial", lambda *a, **kw: {"after": 0})
    path = tmp_path / "00401000.cpp"
    path.write_text("int f;")
    (tmp_path / "best.cpp").write_text("int f;")
    task = {"client": "2008-06", "addr": "00401000", "path": str(path), "donors": [], "before": 95, "source": "int f;"}
    research.reuse(tmp_path, task, [])
    swept = research.gate_sweeps([__import__("json").loads(line) for line in
                                  (tmp_path / "work" / "agent-memory" / "attempts.jsonl").read_text().splitlines()])
    research.reuse(tmp_path, task, [], swept=swept)
    assert len(calls) == 1


def test_unavailable_variant_retries_with_model_default(monkeypatch):
    calls = []
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, model, *args:
                        calls.append(model) or (agent.VARIANT_UNAVAILABLE if "#" in model else 0))
    assert agent.run_agent("opencode", "p", "opencode/space-bunny-free#minimal", 10, lambda *a: None) == 0
    assert calls == ["opencode/space-bunny-free#minimal", "opencode/space-bunny-free"]
    lines = []
    agent.show('{"type":"error","error":{"name":"UnknownError","data":{"message":"Variant unavailable for x: minimal"}}}',
               lines.append)
    assert lines == ["Agent error: Variant unavailable for x: minimal"]
    assert agent.VARIANT.search(agent._error_text('{"type":"error","error":{"data":{"message":"Variant unavailable"}}}'))
