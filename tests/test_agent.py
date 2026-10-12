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
    assert any(arg.startswith("Read,Grep,Glob,Edit,Write,Bash(") for arg in claude)
    assert agent.command("codex")[-1] == "-"


def test_goal_mode_allows_roc_commands_and_web(monkeypatch):
    tools = next(arg for arg in agent.command("claude", goal=True) if arg.startswith("Read,"))
    assert "WebSearch" in tools and tools.endswith('roc.py *)') and "check" not in tools
    seen = []
    monkeypatch.setattr(agent, "run_agent", lambda cli, prompt, model, minutes, log, goal: seen.append((prompt, goal)))
    agent.run_goal("claude", "match RakNet in 2008-06", minutes=5, log=lambda *a: None)
    assert "match RakNet in 2008-06" in seen[0][0] and seen[0][1] is True


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
                   {"max_size": 0}, {"model": "--bad"}):
        with pytest.raises(ValueError):
            command_args({"command": "agent", "cli": "claude", "automatic": True, **fields})


def test_stream_events_become_console_lines():
    lines = []
    agent.show('{"type":"assistant","message":{"content":[{"type":"text","text":"Trying zlib."},'
               '{"type":"tool_use","name":"Bash","input":{"command":"roc check 2008-06 00401000\\nmore"}}]}}', lines.append)
    agent.show('{"type":"result","num_turns":7,"is_error":false}', lines.append)
    agent.show("plain text\n", lines.append)
    assert lines == ["Trying zlib.", "  > Bash roc check 2008-06 00401000", "Agent finished after 7 turns.", "plain text"]


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
    assert len(data["recent"]) == 19 and data["recent"][-1]["after"] == 24
    assert "winner" in agent.memory_prompt() and "Record EVERY trial" in agent.memory_prompt()


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
