from roc import agent


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
    path.parent.mkdir(parents=True)
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
    assert any(arg.startswith("Read,Grep,Glob,Edit,Bash(") for arg in claude)
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
