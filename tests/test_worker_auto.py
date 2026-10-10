"""Worker automatic policy, command entry points and logging regressions."""
import importlib.util
from pathlib import Path
from unittest.mock import patch

import pytest

from roc import gui_worker, link, providers, worker


def test_automatic_policy_keeps_explicit_overrides():
    assert worker.resolve_workers("auto", "deepseek:deepseek-flash") == 8
    assert worker.resolve_workers("auto", "openai:gpt-5-mini") == 4
    assert worker.resolve_workers("auto", "qwen2.5-coder:7b-instruct") == 2
    assert worker.resolve_workers("auto", "qwen2.5-coder:17b") == 1
    assert worker.resolve_workers("auto", "deepseek:deepseek-flash", source_only=True) == 1
    assert worker.resolve_workers(3, "deepseek:deepseek-flash") == 3
    assert worker.resolve_output_tokens({"size": 32, "calls": 0}, "auto") == 1024
    assert worker.resolve_output_tokens({"size": 32, "calls": 1}, "auto") == 2048
    assert worker.resolve_output_tokens({"size": 200}, "auto") == 2048
    assert worker.resolve_output_tokens({"size": 32}, 4096) == 4096


@pytest.mark.parametrize("model,size,thinking,expected", [
    ("deepseek:deepseek-flash", 200, "auto", "disabled"),
    ("openai:gpt-5-mini", 200, "auto", "auto"),
    ("openai:gpt-5-mini", 32, "auto", "disabled"),
    ("deepseek:deepseek-flash", 200, "enabled", "enabled")])
def test_generation_reasoning_policy(model, size, thinking, expected):
    from roc import draft
    options = dict(allow_cloud=True, thinking=thinking)
    with patch.object(draft, "_ask_context", return_value=("```cpp\nint f(){return 1;}\n```", None, {"finish_reason": "stop"})) as ask, \
         patch.object(draft.match, "target", return_value=(b"\xc3", [], {"size": size, "unit": "x"})), \
         patch.object(draft.match, "disasm", return_value=["ret "]), \
         patch.object(draft, "prompt_for", return_value="p"), \
         patch.object(draft.match, "check_text", return_value=(100, None, "", None)):
        draft.llm_rounds("C", "1", model, 1, provider_options=options, log=lambda _: None)
    assert ask.call_args.args[3]["thinking"] == expected


@pytest.mark.parametrize("workers,verbosity", [(3, "auto"), (2, "compact"), (4, "verbose")])
def test_concurrent_logging_finishes_correctly(workers, verbosity):
    output = []
    with patch.object(worker, "run"), patch.object(worker.setup, "compilers"), \
         patch("roc.refsource.build_index"):
        worker.run_concurrent("localhost:8765", "tester", workers=workers,
                              verbosity=verbosity, max_jobs=workers, log=output.append)
    assert any("finished |" in line and "matched" in line for line in output) == (verbosity != "verbose")


def test_gui_accepts_auto_and_resizes_with_model():
    with patch.object(providers, "available", return_value=True):
        config = gui_worker.validate(dict(server="localhost:8765", user="tester",
            model="deepseek:deepseek-flash", cloud_allowed=True, workers="auto",
            rounds="auto", max_tokens="auto", cloud_concurrency="auto", strategy="auto"))
        control = gui_worker.Control(config, lambda *args, **kwargs: None)
        assert control.workers == 8
        assert control.before_lease(7)["rounds"] == "auto"
        assert control.before_lease(8) is None
        control.command({"action": "update", "config": {"workers": 2, "rounds": 7}})
        assert control.before_lease(2) is None
        assert control.before_lease(0)["rounds"] == 7


def test_terminal_automatic_needs_no_knob_prompts():
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:7b"), \
         patch.object(worker, "save_settings") as saved, \
         patch("builtins.input", side_effect=["", "6"]) as prompts:
        assert link.choose_options({}) == ("qwen2.5-coder:7b", "auto", 512, False, "auto", "auto", "auto")
    assert prompts.call_count == 2
    assert saved.call_args.kwargs["worker_order"] == "auto"


def test_signed_launcher_keeps_auto_and_saved_output():
    model = "qwen2.5-coder:7b"
    settings = dict(model=model, worker_rounds="auto", worker_output_budget="auto",
                    worker_workers="auto", worker_max_size=512, worker_order="auto", worker_revng=False)
    with patch.object(worker, "resolve_model", return_value=(model, False)), \
         patch.object(worker, "load_settings", return_value=settings), \
         patch.object(worker, "save_settings"), patch.object(worker, "keep_awake"), \
         patch.object(worker, "run_concurrent") as run:
        worker.main_args(dict(user="tester", server="localhost:8765"), [])
    assert run.call_args.args[4:7] == ("auto", 512, False)
    assert run.call_args.kwargs["max_tokens"] == "auto"
    assert "auto" in link.knobs("auto", 512, False, "auto")


@pytest.mark.parametrize("extra,rounds,tokens,size,loops,order", [
    ([], "auto", "auto", 512, "auto", "auto"),
    (["--rounds", "3", "--output-budget", "4096", "--max-size", "96", "--workers", "2", "--order", "random"],
     3, 4096, 96, "2", "random"),
    (["--client", "all", "--output-budget", "32768"], "auto", 32768, 512, "auto", "auto")])
def test_cli_automatic_preserves_overrides(extra, rounds, tokens, size, loops, order):
    spec = importlib.util.spec_from_file_location("roc_worker_auto_cli", Path(__file__).resolve().parents[1] / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    with patch.object(cli, "settings", return_value={}), patch.object(worker, "save_settings"), \
         patch.object(worker, "run_concurrent") as run:
        cli.main(["worker", "--no-update", "--server", "localhost:8765", "--user", "tester",
                  "--source-only", "--preset", "automatic", *extra])
    assert run.call_args.args[4:8] == (rounds, size, False, None)
    assert run.call_args.args[8] == loops
    assert run.call_args.kwargs["max_tokens"] == tokens
    assert run.call_args.kwargs["order"] == order
    assert run.call_args.kwargs["cloud_min_size"] == 0
    assert run.call_args.kwargs["only"] is None


def test_concurrent_cloud_auto_uses_eight_loops():
    with patch.object(worker, "run") as run, patch.object(worker.setup, "compilers"), \
         patch("roc.refsource.build_index"):
        worker.run_concurrent("localhost:8765", "tester", model="deepseek:deepseek-flash",
                              workers="auto", max_jobs=8, log=lambda _: None)
    assert run.call_count == 8


@pytest.mark.parametrize("budget,expected", [("16384", 16384), ("auto", "auto")])
def test_launcher_accepts_saved_token_budget(budget, expected):
    with patch.object(worker, "resolve_model", return_value=("local", False)), \
         patch.object(worker, "load_settings", return_value={"worker_output_budget": budget}), \
         patch.object(worker, "save_settings"), patch.object(worker, "keep_awake"), \
         patch.object(worker, "run_concurrent") as run:
        worker.main_args(dict(user="tester", server="localhost:8765"), [])
    assert run.call_args.kwargs["max_tokens"] == expected


@pytest.mark.parametrize("extra", [["--rounds", "0"], ["--output-budget", "0"]])
def test_launcher_rejects_invalid_explicit_limits(extra):
    with patch.object(worker, "resolve_model", return_value=("local", False)), \
         patch.object(worker, "load_settings", return_value={}), \
         pytest.raises(SystemExit, match="must be"):
        worker.main_args(dict(user="tester", server="localhost:8765"), extra)


def test_budget_rejection_releases_lease_and_marks_stop(tmp_path):
    from roc import activity
    job = dict(client="C", addr="00401000", size=20, unit="U", score=0, lease="test", source=None)
    options = {}
    calls = []

    class Api:
        server, token = "http://localhost:8765", None

        def call(self, path, data=None):
            calls.append(path)
            return {}

    with patch.object(activity, "PATH", tmp_path / "history.sqlite"), \
         patch.object(worker.match, "target", side_effect=providers.ProviderError("cloud_budget", "cap reached")):
        assert worker.work_one(Api(), "tester", job, {"clients": {"C": {}}}, "roc repair", 2,
                               False, lambda _: None, provider_options=options) == 0
    assert options["budget_exhausted"]
    assert calls == ["/v1/release"]


def test_live_automatic_options_and_budget_stop_reach_worker():
    model = "deepseek:deepseek-flash"
    config = {**gui_worker.DEFAULTS, "server": "localhost:8765", "user": "tester",
              "model": model, "cloud_allowed": True, "workers": "auto", "rounds": "auto",
              "max_tokens": "auto", "max_size": 512, "order": "auto"}
    control = gui_worker.Control(config, lambda *args, **kwargs: None)
    calls = []
    job = dict(client="C", addr="00401000", size=32, calls=0, score=0)

    class Api:
        def __init__(self, *args):
            pass

        def call(self, path, data=None):
            calls.append((path, data))
            return {"clients": {"C": {}}} if path == "/v1/info" else {"job": job}

    def work(*args):
        assert args[5] == "auto"
        assert args[-1]["max_tokens"] == 1024
        assert args[-1]["thinking"] == "disabled"
        args[-1]["budget_exhausted"] = True
        return 0

    with patch.object(worker, "Api", Api), patch.object(worker, "usable_clients", return_value=["C"]), \
         patch.object(worker.draft, "pick_model", return_value=model), \
         patch.object(providers, "available", return_value=True), \
         patch.object(worker, "work_one", side_effect=work) as attempt, \
         patch.object(worker, "save_session_state"), patch.object(worker.metrics, "summary", return_value=""):
        worker.run("localhost:8765", "tester", model=model, cloud_allowed=True,
                   max_jobs=2, control=control, log=lambda _: None)
    assert attempt.call_count == 1
    assert calls[1][1]["order"] == "auto"
    assert calls[1][1]["max_size"] == 512
    assert control.stopping


@pytest.mark.parametrize("limits,usage", [({"max_cloud_tokens": 100}, "tokens"), ({"max_cloud_cost": 1}, "cost")])
def test_gui_stops_at_token_and_cost_caps(limits, usage):
    config = {**gui_worker.DEFAULTS, "source_only": True, **limits}
    control = gui_worker.Control(config, lambda *args, **kwargs: None)
    setattr(control.budget, usage, 100 if usage == "tokens" else 1)
    control.finished(0, dict(client="C", addr="00401000"), 0)
    assert control.stopping
