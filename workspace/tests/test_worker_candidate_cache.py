from roc import draft, mutate


def test_compiling_zero_score_duplicate_keeps_valid_status_and_diff(monkeypatch):
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 9, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret"])
    prompts = []
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kw: prompts.append(args[5]) or "prompt")
    monkeypatch.setattr(draft, "_ask_context", lambda *args, **kw: (
        "```cpp\nint f() { return 1; }\n```", None, {"output_tokens": 10}))
    checks = []

    def check(*args, **kwargs):
        checks.append(args)
        return 0, "f", "target uses different operations", [], {}

    monkeypatch.setattr(draft.match, "check_text", check)
    monkeypatch.setattr(mutate, "improve", lambda *args, **kw: mutate.ImproveResult(0, args[2], 0))
    stats = []
    draft.llm_rounds("C", "1", "m", 3, stats=stats, log=lambda _: None)
    assert len(checks) == 1
    assert stats[1]["duplicate"] and stats[1]["compile_error"] is None
    assert prompts[2][2] == "target uses different operations"
