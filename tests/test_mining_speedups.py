"""Mining pipeline speedups: portable Remill, ranking, claims, routing, packet,
batch experiments and the fixed A/B benchmark.

Nothing here compiles a real function, starts a worker, or touches the network:
each test uses a fake tool path, a temporary SQLite root, or a patched helper.
"""
import importlib.util
import json
import threading
import urllib.request
from http.server import ThreadingHTTPServer
from pathlib import Path

import pytest


@pytest.fixture
def cli():
    spec = importlib.util.spec_from_file_location(
        "roc_mining_cli", Path(__file__).resolve().parents[1] / "roc.py")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def _tools(tmp_path, remill="remill-lift-17", opt="opt-17"):
    folder = tmp_path / "bin"
    folder.mkdir(parents=True, exist_ok=True)
    exe = folder / remill
    opt_path = folder / opt
    exe.write_text("")
    opt_path.write_text("")
    return exe, opt_path


# ---------------------------------------------------------------- Remill resolver

def test_remill_env_override_wins_and_identifies_the_chain(monkeypatch, tmp_path):
    from roc import remill
    exe, opt = _tools(tmp_path)
    monkeypatch.setattr(remill, "REPO_ROOT", tmp_path / "repo")
    monkeypatch.setenv("ROC_REMILL_EXE", str(exe))
    monkeypatch.setenv("ROC_LLVM_OPT", str(opt))
    monkeypatch.delenv("ROC_LLVM_BIN", raising=False)
    tools = remill.resolve_tools(refresh=True)
    assert tools["available"]
    assert tools["exe_source"] == "env" and tools["opt_source"] == "env"
    assert tools["lifter_version"] == "17" and tools["llvm_version"] == "17"
    assert len(tools["cache_key"]) == 64
    assert Path(tools["exe"]) == exe


def test_remill_repo_tree_beats_path(monkeypatch, tmp_path):
    from roc import remill
    repo = tmp_path / "repo"
    exe = repo / "tools" / "remill" / "build" / "bin" / "remill-lift-17"
    opt = repo / "tools" / "llvm" / "bin" / "opt-17"
    exe.parent.mkdir(parents=True)
    opt.parent.mkdir(parents=True)
    exe.write_text("")
    opt.write_text("")
    monkeypatch.setattr(remill, "REPO_ROOT", repo)
    for key in ("ROC_REMILL_EXE", "ROC_LLVM_OPT", "ROC_LLVM_BIN"):
        monkeypatch.delenv(key, raising=False)
    monkeypatch.setattr(remill, "_which", lambda names: tmp_path / "path" / "decoy")
    tools = remill.resolve_tools(refresh=True)
    assert tools["available"] and tools["exe_source"] == "repo" and tools["opt_source"] == "repo"
    assert Path(tools["exe"]) == exe and Path(tools["opt"]) == opt


def test_remill_missing_is_clean_and_has_no_private_path(monkeypatch, tmp_path):
    from roc import remill
    monkeypatch.setattr(remill, "REPO_ROOT", tmp_path / "repo")
    monkeypatch.setattr(remill, "_which", lambda names: None)
    monkeypatch.setenv("ROC_REMILL_EXE", str(tmp_path / "gone" / "remill-lift-17"))
    monkeypatch.delenv("ROC_LLVM_OPT", raising=False)
    monkeypatch.delenv("ROC_LLVM_BIN", raising=False)
    tools = remill.resolve_tools(refresh=True)
    assert not tools["available"]
    message = remill.not_available_message(tools)
    assert "ROC_REMILL_EXE" in message and "ROC_LLVM_OPT" in message
    assert "Nothing is downloaded" in message
    assert str(tmp_path) not in message


def test_remill_version_mismatch_is_reported_not_hidden(monkeypatch, tmp_path):
    from roc import remill
    exe, opt = _tools(tmp_path, remill="remill-lift-17", opt="opt-16")
    monkeypatch.setattr(remill, "REPO_ROOT", tmp_path / "repo")
    monkeypatch.setenv("ROC_REMILL_EXE", str(exe))
    monkeypatch.setenv("ROC_LLVM_OPT", str(opt))
    tools = remill.resolve_tools(refresh=True)
    assert tools["available"]
    assert any("differ" in problem for problem in tools["problems"])


def test_doctor_reports_optional_remill_without_failing(monkeypatch):
    from roc import doctor, remill
    monkeypatch.setattr(remill, "resolve_tools",
                        lambda refresh=False: {"available": False, "reason": "not found", "problems": []})
    row = doctor.remill_check()
    assert row["name"] == "remill" and row["state"] == doctor.OK
    assert "optional" in row["detail"]
    assert row in doctor.all_checks(network=False)


# --------------------------------------------------------------------- Ranking

def _seed_slice(store, count=520, score=97):
    store.db.executemany(
        "INSERT INTO funcs(client,addr,size,unit,score,shape,family) VALUES(?,?,?,?,?,?,?)",
        [("C", "%08x" % (0x200000 + i * 16), 20, "U", score, "other-shape", None)
         for i in range(count)])
    store.db.commit()


def test_work_candidates_finds_a_twin_outside_the_score_slice():
    from roc.server import Store
    store = Store(":memory:", lease_seconds=10)
    _seed_slice(store)
    store.db.executemany(
        "INSERT INTO funcs(client,addr,size,unit,score,shape,family) VALUES(?,?,?,?,?,?,?)",
        [("C", "deadbeef", 24, "U", 100, "SHAPE-A", None),
         ("C", "0badf00d", 24, "U", 5, "SHAPE-A", None)])
    store.db.commit()
    rows = store.work_candidates("C", limit=20)
    assert rows and rows[0]["addr"] == "0badf00d"
    assert rows[0]["twin"] == "deadbeef" and rows[0]["recommendation"] == "reuse"
    assert "0badf00d" not in [row["addr"] for row in store.functions("C", limit=500)]


def test_legacy_functions_order_work_is_opt_in():
    from roc.server import Store
    store = Store(":memory:", lease_seconds=10)
    store.db.executemany(
        "INSERT INTO funcs(client,addr,size,unit,score) VALUES(?,?,?,?,?)",
        [("C", "00401000", 20, "U", 50), ("C", "00401010", 30, "U", 90)])
    store.db.commit()
    default = store.functions("C", limit=10)
    work = store.functions("C", limit=10, order="work")
    assert [row["score"] for row in default] == [90, 50]
    assert set(work[0]) == {"addr", "size", "unit", "score", "shape", "family", "attempts",
                            "source_confidence", "twin", "claimed"}


def test_shape_twin_precedes_family_twin_and_absent_mismatch_is_unknown():
    from roc import ranking
    row = {"addr": "00401000", "size": 40, "score": 70, "shape": "S1", "family": "F1",
           "attempts": 0, "source_confidence": 0}
    ranked = ranking.rank_one(row, twin="shape-donor", mismatch=None, profile_name="balanced")
    assert ranked["twin"] == "shape-donor" and ranked["recommendation"] == "reuse"
    assert ranked["mismatch_category"] is None
    via_family = {"addr": "00401010", "size": 40, "score": 70, "shape": None, "family": "F1",
                  "attempts": 0, "source_confidence": 0}
    ranked = ranking.rank_one(via_family, twin="family-donor", profile_name="balanced")
    assert ranked["twin"] == "family-donor"


def test_measured_residue_enables_a_patch_but_absent_residue_does_not():
    from roc import ranking
    row = {"addr": "00401000", "size": 80, "score": 60, "attempts": 0, "source_confidence": 0}
    measured = ranking.rank_one(row, mismatch="one constant")
    assert measured["recommendation"] == "patch" and "one-constant" in measured["difficulty_reason"]
    unknown = ranking.rank_one(row)
    assert unknown["recommendation"] == "structural"
    assert unknown["mismatch_category"] is None


def test_repeated_no_gain_and_claims_lower_the_rank():
    from roc import ranking
    clean = {"addr": "00401000", "size": 40, "score": 90, "attempts": 0,
             "source_confidence": 60, "has_source": True}
    tried = dict(clean, addr="00401010", attempts=3)
    claimed = dict(clean, addr="00401020", claimed=True, owner="bob")
    ranked = {row["addr"]: row for row in
              ranking.rank_candidates([clean, tried, claimed], limit=10)}
    assert ranked["00401000"]["rank"] > ranked["00401010"]["rank"]
    assert ranked["00401000"]["rank"] > ranked["00401020"]["rank"]
    assert any("attempt" in reason for reason in ranked["00401010"]["penalties"])


# ------------------------------------------------------------ Claims / cooldowns

def test_claim_tokens_are_not_released_by_a_guess_or_by_name(tmp_path):
    from roc import claims
    claims.save_claim("C", "0x401000", "lease-a", worker="alice", root=tmp_path)
    stored = claims.load_claim("C", "00401000", root=tmp_path)
    assert stored["lease"] == "lease-a" and stored["addr"] == "00401000"
    assert claims.clear_claim("C", "00401000", "lease-b", root=tmp_path) is False
    assert claims.load_claim("C", "00401000", root=tmp_path)["lease"] == "lease-a"
    assert claims.clear_claim("C", "00401000", "lease-a", root=tmp_path) is True
    assert claims.load_claim("C", "00401000", root=tmp_path) is None


def test_expired_claim_is_never_reused_as_ownership(tmp_path):
    from roc import claims
    claims.save_claim("C", "00401000", "old", worker="alice",
                      expires=claims.now() - 1, root=tmp_path)
    assert claims.load_claim("C", "00401000", root=tmp_path) is None
    stale = claims.load_claim("C", "00401000", root=tmp_path, include_expired=True)
    assert stale["expired"] is True


def test_cooldown_is_evidence_scoped_and_expires(tmp_path):
    from roc import claims
    claims.add_cooldown("C", "00401000", "hash-a", 60, reason="skipped", root=tmp_path)
    assert claims.cooling("C", "00401000", root=tmp_path)
    assert not claims.cooling("C", "00401000", evidence="hash-b", root=tmp_path)
    claims.add_cooldown("C", "00401000", "hash-b", 0, root=tmp_path)
    assert not claims.cooling("C", "00401000", evidence="hash-b", root=tmp_path)
    claims.switch_evidence("C", "00401000", "hash-c", root=tmp_path)
    assert not claims.cooling("C", "00401000", root=tmp_path)


def test_server_release_needs_the_exact_lease_token():
    from roc.server import Store
    store = Store(":memory:", lease_seconds=10)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('C','00401000',6,'A')")
    token = store.claim("C", "00401000", "alice")["lease"]
    assert store.release("guess", worker="alice", client="C", addr="00401000")["released"] is False
    assert store.release(token, worker="bob")["released"] is False
    assert store.release(token, worker="alice", client="C", addr="00401000")["released"] is True


def test_two_workers_never_hold_the_same_target():
    from roc.server import Store
    store = Store(":memory:", lease_seconds=10)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('C','00401000',6,'A')")
    first = store.claim("C", "00401000", "alice")
    assert first["lease"]
    assert store.claim("C", "00401000", "bob") is None
    assert store.release(first["lease"], worker="alice")["released"] is True
    assert store.claim("C", "00401000", "bob")["lease"]


def test_claimed_targets_are_excluded_when_the_caller_asks():
    from roc.server import Store
    store = Store(":memory:", lease_seconds=10)
    store.db.executemany(
        "INSERT INTO funcs(client,addr,size,unit,score) VALUES(?,?,?,?,?)",
        [("C", "00401000", 20, "U", 80), ("C", "00401010", 20, "U", 70)])
    store.db.commit()
    store.claim("C", "00401000", "alice")
    open_rows = store.work_candidates("C", limit=10, include_claimed=False)
    assert [row["addr"] for row in open_rows] == ["00401010"]
    all_rows = store.work_candidates("C", limit=10, include_claimed=True)
    owner = next(row for row in all_rows if row["addr"] == "00401000")
    assert owner["claimed"] and owner["owner"] == "alice"


# ----------------------------------------------------------------------- Scout

def test_scout_server_fetch_is_read_only(tmp_path):
    from roc import scout

    class FakeApi:
        def __init__(self):
            self.calls = []

        def call(self, path, payload=None, timeout=60):
            self.calls.append((path, payload))
            return [{"addr": "00401000", "score": 40, "size": 20, "attempts": 0}]

    api = FakeApi()
    rows, live, note = scout.candidates(api, "C", root=tmp_path)
    assert live and rows[0]["server_ranked"] is True
    assert [call[0] for call in api.calls] == [
        "/v1/work-candidates?client=C&limit=20&profile=quick&min_score=0&max_score=99&include_claimed=1"]
    assert all(call[1] is None for call in api.calls)


def test_scout_local_fallback_is_marked_stale(tmp_path):
    from roc import scout
    folder = tmp_path / "work" / "C"
    folder.mkdir(parents=True)
    rows = [{"addr": "00401000", "size": 20, "unit": "U", "kind": "code"},
            {"addr": "00401010", "size": 22, "unit": "U", "kind": "code"}]
    (folder / "functions.jsonl").write_text("\n".join(json.dumps(row) for row in rows))
    (folder / "scores.json").write_text(json.dumps({"00401000": 100, "00401010": 42}))
    got = scout.from_local("C", root=tmp_path)
    assert [row["addr"] for row in got] == ["00401010"]
    assert got[0]["server_ranked"] is False
    table = scout.format_table(got, live=False, note="no server configured")
    assert "stale" in table and "~42" in table


def test_scout_local_fallback_refuses_unanalyzed_client(tmp_path):
    from roc import scout
    with pytest.raises(ValueError, match="not analyzed"):
        scout.from_local("missing", root=tmp_path)


# ---------------------------------------------------------------- Server route

def test_work_candidates_http_route_and_legacy_order():
    from roc import server
    store = server.Store(":memory:", lease_seconds=10)
    store.db.executemany(
        "INSERT INTO funcs(client,addr,size,unit,score,shape,family) VALUES(?,?,?,?,?,?,?)",
        [("C", "deadbeef", 20, "U", 100, "S", None),
         ("C", "00401000", 20, "U", 30, "S", None)])
    store.db.commit()
    httpd = ThreadingHTTPServer(("127.0.0.1", 0), server.make_handler(store, None, {"C"}))
    thread = threading.Thread(target=httpd.serve_forever, daemon=True)
    thread.start()
    try:
        base = "http://127.0.0.1:%d" % httpd.server_port
        with urllib.request.urlopen(base + "/v1/work-candidates?client=C&limit=5", timeout=5) as response:
            assert response.status == 200
            rows = json.loads(response.read())
        assert rows[0]["addr"] == "00401000" and rows[0]["twin"] == "deadbeef"
        with urllib.request.urlopen(base + "/v1/functions?client=C&limit=5&order=work", timeout=5) as response:
            ordered = json.loads(response.read())
        assert ordered[0]["addr"] == "00401000" and set(ordered[0]) >= {"twin", "claimed"}
    finally:
        httpd.shutdown()
        httpd.server_close()


# ---------------------------------------------------------------------- Packet

def test_packet_fit_announces_every_truncation():
    from roc import packet
    built = {
        "format": "roconstruct-packet-v1", "client": "C", "address": "00401000",
        "target": {"asm": ["nop"] * 200, "size": 400},
        "source": {"origin": "local", "text": "int f() { return 0; } " * 300,
                   "score": 40, "confidence": "observed"},
        "diff": None, "similar": [], "lessons": [], "failed_hypotheses": [],
        "local_claim": None, "assumptions": [], "truncated": False, "omitted": [],
    }
    fitted = packet._fit(built, 700)
    assert fitted["truncated"] is True and fitted["omitted"]
    assert len(fitted["target"]["asm"]) >= 8
    assert fitted["estimated_tokens"] == max(1, fitted["chars"] // 4)


def test_packet_cli_reports_a_missing_target(cli, monkeypatch):
    from roc import packet
    monkeypatch.setattr(cli, "settings", lambda: {})
    monkeypatch.setattr(cli.clients, "load", lambda: {})
    monkeypatch.setattr(packet, "build", lambda *args, **kwargs: (_ for _ in ()).throw(
        SystemExit("C is not analyzed yet: run roc analyze C")))
    with pytest.raises(SystemExit) as error:
        cli.main(["packet", "C", "00401000"])
    assert "not analyzed" in str(error.value)


# ------------------------------------------------------------------ Check batch

def test_check_batch_reports_engine_failure_instead_of_dropping_it(cli, monkeypatch, tmp_path, capsys):
    from roc import match
    monkeypatch.setenv("ROC_CHECK_BATCH_JOURNAL", "0")
    monkeypatch.setattr(cli, "_refuse_matched", lambda *args: None)
    good = tmp_path / "a.cpp"
    bad = tmp_path / "b.cpp"
    good.write_text("int f() { return 1; }")
    bad.write_text("int f() { return 2; }")

    def fake_check(client, addr, text, *args, **kwargs):
        if "return 2" in text:
            raise RuntimeError("compiler toolchain missing")
        return 60, "f", "diff", []

    monkeypatch.setattr(match, "check_text", fake_check)
    cli.main(["check-batch", "C", "00401000", str(bad), str(good), "--json"])
    payload = json.loads(capsys.readouterr().out)
    assert payload["best_score"] == 60 and payload["authoritative"] is False
    failures = [row for row in payload["results"] if row["error"]]
    assert failures and "compiler toolchain missing" in failures[0]["error"]
    assert payload["winner"] == str(good)


def test_check_batch_dedupes_identical_sources_and_names_the_winner(cli, monkeypatch, tmp_path, capsys):
    from roc import match
    monkeypatch.setenv("ROC_CHECK_BATCH_JOURNAL", "0")
    monkeypatch.setattr(cli, "_refuse_matched", lambda *args: None)
    calls = []

    def fake_check(client, addr, text, *args, **kwargs):
        calls.append(text)
        return (100 if "return 7" in text else 80), "f", "", []

    monkeypatch.setattr(match, "check_text", fake_check)
    same = tmp_path / "same.cpp"
    same.write_text("int f() { return 7; }")
    copy = tmp_path / "copy.cpp"
    copy.write_text(same.read_text())
    other = tmp_path / "other.cpp"
    other.write_text("int f() { return 9; }")
    cli.main(["check-batch", "C", "00401000", str(same), str(copy), str(other), "--summary"])
    out = capsys.readouterr().out
    assert len(calls) == 2
    assert "duplicates:" in out and "%s=%s" % (copy, same) in out
    cli.main(["check-batch", "C", "00401000", str(same), "--summary"])
    assert "roc submit C 00401000 --file" not in capsys.readouterr().out
    cli.main(["check-batch", "C", "00401000", str(same)])
    assert "roc submit C 00401000 --file" in capsys.readouterr().out


# ------------------------------------------------------- Routing / heavy analysis

def test_weak_models_only_get_constrained_patch_work(monkeypatch):
    from roc import routing
    for key in ("ROC_WEAK_MODELS", "ROC_STRONG_MODELS"):
        monkeypatch.delenv(key, raising=False)
    small = routing.decide({"addr": "00401000", "size": 40, "score": 90,
                            "source": "int f() { return 0; }"}, "acme:free-model")
    assert small["model_class"] == "weak" and not small["skip"]
    assert small["rounds"] == routing.WEAK_MAX_ROUNDS
    assert small["variants"] == routing.WEAK_VARIANTS
    big = routing.decide({"addr": "00402000", "size": 400, "score": 10, "source": ""},
                         "acme:free-model")
    assert big["skip"] and big["needs_research"]
    assert big["reason"].startswith("weak model:")


def test_routing_has_no_hidden_paid_fallback(monkeypatch):
    from roc import routing
    job = {"addr": "00401000", "size": 400, "attempts_by_model": {"local": 5}}
    assert routing.escalate(job, "local", configured=None) is None
    assert routing.escalate(job, "local", configured="strong:model", after=3) == "strong:model"
    monkeypatch.setenv("ROC_WEAK_ROUTING", "0")
    route = routing.decide({"addr": "00401000", "size": 400, "source": ""}, "acme:free-model")
    assert route["skip"] is False and route["variants"] == 1


def test_remill_is_only_lifted_for_structural_uncertainty(monkeypatch):
    from roc import worker
    monkeypatch.delenv("ROC_FORCE_LIFT", raising=False)
    monkeypatch.delenv("ROC_DISABLE_REMILL", raising=False)
    small = worker.remill_worth_it({"size": 20}, {}, True)
    assert small[0] is False and "small target" in small[1]
    structural = worker.remill_worth_it({"size": 200}, {"branch_count": 6}, True)
    assert structural[0] is True
    disabled = worker.remill_worth_it({"size": 400}, {"branch_count": 6}, False)
    assert disabled[0] is False
    monkeypatch.setenv("ROC_FORCE_LIFT", "1")
    assert worker.remill_worth_it({"size": 20}, {}, True) == (True, "forced lift (debug)")


# ------------------------------------------------------- CLI / benchmark compat

def test_launch_forwards_remill_flags(cli):
    class Args:
        force_lift = True
        no_remill = True
        dry_run = False
        no_revng = False
        allow_cloud = False
        source_only = False

    forwarded = cli._forwarded(Args())
    assert "--force-lift" in forwarded and "--no-remill" in forwarded


def test_cli_still_accepts_legacy_commands_and_new_flags(cli):
    for argv, needle in ((["check-batch", "--help"], "--json"),
                         (["work", "--help"], "--skip"),
                         (["scout", "--help"], "--include-claimed"),
                         (["release", "--help"], "--cooldown"),
                         (["launch", "--help"], "--force-lift"),
                         (["benchmark-models", "--help"], "--ab")):
        with pytest.raises(SystemExit) as stop:
            cli.main(argv)
        assert stop.value.code == 0


def test_benchmark_ab_split_is_fixed_and_runs_nothing(cli, monkeypatch, capsys):
    from roc import telemetry
    corpus = [{"client": "C", "addr": addr, "size": 20, "unit": "U",
               "bucket": "tiny", "source_present": True}
              for addr in ("00401000", "00402000", "00403000", "00404000")]
    monkeypatch.setattr(telemetry, "build_hidden", lambda limit=8, persist=True: corpus)
    monkeypatch.setattr(telemetry, "run_local", lambda *args, **kwargs: pytest.fail("must not run"))
    cli.main(["benchmark-models", "--ab"])
    out = capsys.readouterr().out
    assert "Arm A" in out and "Arm B" in out and "Nothing was run" in out
    groups = telemetry.ab_split(corpus)
    assert {row["addr"] for row in groups["A"] + groups["B"]} == {
        "00401000", "00402000", "00403000", "00404000"}
    assert telemetry.ab_split(list(reversed(corpus))) == groups
    assert all(len(row["target_hash"]) == 16 for row in groups["A"] + groups["B"])


def test_ab_report_compares_measured_sessions(monkeypatch):
    from roc import telemetry
    sessions = {
        "a": [{"score": 100, "rounds": [{"compile_error": None}], "seconds": 4.0,
               "input_tokens": 10, "output_tokens": 5},
              {"score": 0, "rounds": [{"compile_error": None}], "seconds": 2.0,
               "input_tokens": 8, "output_tokens": 2}],
        "b": [{"score": 90, "rounds": [{"compile_error": None}], "seconds": 3.0,
               "input_tokens": 6, "output_tokens": 3}],
    }
    monkeypatch.setattr(telemetry, "_session_rows", lambda session: sessions.get(session, []))
    report = telemetry.compare_sessions("a", "b")
    assert report["A"]["jobs"] == 2 and report["B"]["jobs"] == 1
    assert report["delta"]["exact_matches"] == -1
    assert "not a significance test" in report["note"]
    assert "A/B benchmark report" in telemetry.format_compare(report)
