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
    assert agent.goal_targets("localhost", None, "C", {}) == rows


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
    assert "roc.py check c 00401000" in prompt and "src/c/00401000.cpp" in prompt


def test_regression_is_rolled_back_and_released(tmp_path, monkeypatch):
    result, text, calls, _ = run_job(tmp_path, monkeypatch, "start", "worse", job_score=40)
    assert result == 40 and text == "start"
    assert calls[-1][0] == "/v1/release"


def test_commands_read_prompt_from_stdin():
    claude = agent.command("claude", "haiku")
    assert claude[:4] == ["claude", "-p", "--model", "haiku"] and "acceptEdits" in claude and "stream-json" in claude
    assert "Read,Grep,Glob,Edit,Write,Bash,PowerShell" in claude
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


def test_goal_mode_allows_roc_commands_and_web(monkeypatch):
    tools = next(arg for arg in agent.command("claude", goal=True) if arg.startswith("Read,"))
    assert "WebSearch" in tools and "Bash,PowerShell" in tools
    seen = []
    monkeypatch.setattr(agent, "run_agent", lambda cli, prompt, model, minutes, log, goal: seen.append((prompt, goal)))
    agent.run_goal("claude", "match RakNet in 2008-06", minutes=5, log=lambda *a: None)
    assert "match RakNet in 2008-06" in seen[0][0] and seen[0][1] is True


def test_every_agent_prompt_requests_concision_and_fast_work(monkeypatch):
    prompts = []
    monkeypatch.setattr(agent, "fallbacks", lambda: [])
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, *a: prompts.append(prompt) or 0)
    for cli in agent.CLIS:
        assert agent.run_agent(cli, "Assigned target", minutes=1) == 0
    assert len(prompts) == 3
    for prompt in prompts:
        assert prompt.startswith("Be very concise.") and "Optimize tokens and wall time" in prompt
        assert "Reuse cached compiler results" in prompt and "Assigned target" in prompt
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
    for fields in ({"workers": 0}, {"jobs": 201}, {"batch_size": 0}, {"batch_minutes": 61},
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
    calls = []
    monkeypatch.setenv("ROC_AGENT_FALLBACKS", "opencode:opencode/big-pickle, codex")
    monkeypatch.setattr(agent, "_run_once", lambda cli, prompt, model, minutes, log, goal, switch:
                        calls.append((cli, model, bool(switch))) or (agent.RATE_LIMITED if len(calls) < 3 else 0))
    assert agent.run_agent("claude", "p", "sonnet", 30, lambda *a: None) == 0
    assert calls == [("claude", "sonnet", True), ("opencode", "opencode/big-pickle", True), ("codex", None, False)]
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
    assert calls.count("a") > 5 and calls[-1] == "opencode/other"  # ~5 minutes of retries, then the fallback


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
