import importlib.util
import json
import threading
import time
from pathlib import Path

import pytest


@pytest.fixture
def cli():
    spec = importlib.util.spec_from_file_location("roc_batch_cli", Path(__file__).resolve().parents[1] / "roc.py")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_batch_checks_concurrently_after_all_server_checks(cli, monkeypatch, capsys):
    from roc import agent_auto
    checked = set()
    barrier = threading.Barrier(2)
    monkeypatch.setattr(cli, "_refuse_matched", lambda client, addr: checked.add(addr))

    def trial(client, addr, path, hypothesis):
        assert checked == {"00401000", "00402000"}
        assert hypothesis == "shared fix"
        barrier.wait(timeout=5)
        return {"after": 98, "outcome": "improved", "diff": "residue"}

    monkeypatch.setattr(agent_auto, "trial", trial)
    cli.main(["agent-check-batch", "2008-06", "00401000.cpp", "00402000.cpp",
              "--hypothesis", "shared fix"])
    assert capsys.readouterr().out.count("98% improved") == 2


@pytest.mark.parametrize("paths", [["00401000.cpp", "other/00401000.cpp"], ["wrong.cpp"]])
def test_batch_rejects_ambiguous_targets(cli, paths):
    with pytest.raises(SystemExit):
        cli.main(["agent-check-batch", "2008-06", *paths, "--hypothesis", "fix"])


def test_batch_server_exact_aborts_before_trials(cli, monkeypatch):
    from roc import agent_auto

    def refuse(client, addr):
        if addr == "00402000":
            raise SystemExit(3)

    monkeypatch.setattr(cli, "_refuse_matched", refuse)
    monkeypatch.setattr(agent_auto, "trial", lambda *args: pytest.fail("must not start trials"))
    with pytest.raises(SystemExit) as error:
        cli.main(["agent-check-batch", "2008-06", "00401000.cpp", "00402000.cpp",
                  "--hypothesis", "fix"])
    assert error.value.code == 3


def test_batch_preserves_both_best_sources_and_trial_journals(cli, monkeypatch, tmp_path):
    from roc import agent_auto, match, research
    paths = []
    for addr in ("00401000", "00402000"):
        folder = tmp_path / addr
        folder.mkdir()
        path = folder / (addr + ".cpp")
        path.write_text("int f() { return 7; }")
        (folder / "task.json").write_text(json.dumps(dict(
            client="2008-06", addr=addr, area="test", profile="test", best_score=90,
            model_started_at=time.time()-5, baseline_hash="old")))
        paths.append(path)
    monkeypatch.setattr(cli, "_refuse_matched", lambda *args: None)
    monkeypatch.setattr(agent_auto, "trial", lambda *args: research.trial(tmp_path, *args))
    monkeypatch.setattr(match, "compile_text", lambda *args: b"object")
    monkeypatch.setattr(match, "target", lambda *args: (b"target", [], {}))
    monkeypatch.setattr(match, "check_text", lambda *args, **kwargs: (99, "f", "diff", []))
    monkeypatch.setattr(match, "save_score", lambda *args: 99)
    cli.main(["agent-check-batch", "2008-06", *map(str, paths), "--hypothesis", "shared fix"])
    for path in paths:
        assert (path.parent / "best.cpp").read_text() == path.read_text()
        assert json.loads((path.parent / "task.json").read_text())["best_score"] == 99
        trial = json.loads((path.parent / "trials.jsonl").read_text())
        assert trial["after"] == 99 and trial["seconds_to_check"] >= 5
    records = [json.loads(line) for line in (tmp_path / "work/agent-memory/attempts.jsonl").read_text().splitlines()]
    assert {r["addresses"][0] for r in records} == {p.stem for p in paths}


def test_agent_context_reads_evidence_and_preserved_source_without_compiling(cli, monkeypatch, tmp_path, capsys):
    from roc import match
    path = tmp_path / "00401000.cpp"
    path.write_text("current")
    (tmp_path / "best.cpp").write_text("preserved")
    (tmp_path / "task.json").write_text(json.dumps(dict(client="2008-06", addr=path.stem, best_score=99)))
    (tmp_path / "trials.jsonl").write_text("\n".join(json.dumps(dict(hypothesis=str(i), after=95)) for i in range(7)))
    monkeypatch.setattr(match, "target", lambda *args: (b"target", [], {"unit": "known", "size": 6}))
    monkeypatch.setattr(match, "disasm", lambda *args: ["ret"])
    monkeypatch.setattr(match, "compile_text", lambda *args: pytest.fail("context must not compile"))
    before = {p.name: p.read_bytes() for p in tmp_path.iterdir()}
    cli.main(["agent-context", "2008-06", str(path)])
    result = json.loads(capsys.readouterr().out)[0]
    assert result["source"] == "current" and result["best_source"] == "preserved"
    assert result["target_asm"] == ["ret"]
    assert [r["hypothesis"] for r in result["recent_trials"]] == [str(i) for i in range(2, 7)]
    assert {p.name: p.read_bytes() for p in tmp_path.iterdir()} == before


@pytest.mark.parametrize("option", ["--json", "--summary"])
def test_batch_compact_results_keep_full_trial_rows(cli, monkeypatch, capsys, option):
    from roc import agent_auto
    monkeypatch.setattr(cli, "_refuse_matched", lambda *args: None)
    monkeypatch.setattr(agent_auto, "trial", lambda *args: dict(after=98, outcome="improved", diff="full residue"))
    cli.main(["agent-check-batch", "2008-06", "00401000.cpp", "--hypothesis", "fix", option])
    output = capsys.readouterr().out
    if option == "--json":
        assert json.loads(output)[0]["diff"] == "full residue"
    else:
        assert "98% improved" in output and "full residue" not in output
