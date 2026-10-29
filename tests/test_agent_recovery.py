import json
import threading
import time
from concurrent.futures import ThreadPoolExecutor

import pytest

from roc import agent, agent_auto, agent_recovery as recovery, match, research


def candidates(count=8):
    return [dict(client="C", addr="%08x" % i, source="int f(){}", evidence_hash="revision") for i in range(count)]


def test_initial_evidence_preserves_proof_and_defers_duplicate_bodies(tmp_path):
    evidence = dict(source="large assigned source", source_hash="proof", target_asm=["call native"],
        facts={"strings": ["identity"], "imports": ["API"]},
        native_type_headers=[{"path": "native.h", "excerpt": "class Native {};", "candidate_only": True}],
        rtti_type_refs=[{"type": "Native"}], extent_review={"normal_exit": "00401000"},
        neighbours=[{"addr": "00402000", "relation": "call_targets", "instructions": ["body"],
                     "facts": {"return_stack_bytes": [4]}}],
        siblings=[{"addr": "00403000", "score": 100, "matched_read_only": True, "source": "read only body"}])
    before = json.dumps(evidence, sort_keys=True)
    brief = recovery.initial_evidence(evidence, tmp_path / "evidence.json")
    assert "source" not in brief
    assert brief["target_asm"] == evidence["target_asm"]
    assert brief["facts"] == evidence["facts"]
    assert brief["native_type_headers"] == evidence["native_type_headers"]
    assert brief["extent_review"] == {"recorded_size": None, "normal_exit": "00401000",
                                       "inventory_owner": None, "reason": None}
    assert "source_hash" not in brief
    assert "rtti_type_refs" not in brief
    assert "neighbours" not in brief
    assert "siblings" not in brief
    assert brief["full_evidence_file"] == str(tmp_path / "evidence.json")
    assert json.dumps(evidence, sort_keys=True) == before


def test_persistent_queue_finishes_pool_before_repeating(tmp_path):
    rows = candidates()
    seen = []
    for _ in rows:
        picked = recovery.draw(tmp_path, rows, 1, "server")[0]
        seen.append(picked["addr"])
        recovery.release(tmp_path, picked, "server")
    assert len(set(seen)) == len(rows)
    assert recovery.draw(tmp_path, rows, 1, "server")[0]["addr"] in seen


def test_queue_claims_are_atomic_across_connections(tmp_path):
    rows = candidates()
    with ThreadPoolExecutor(max_workers=8) as pool:
        selected = list(pool.map(lambda _: recovery.draw(tmp_path, rows, 1), range(8)))
    assert len({picks[0]["addr"] for picks in selected}) == 8
    assert recovery.draw(tmp_path, rows, 1) == []


def test_queue_recovers_expired_claim_without_old_owner_releasing_new_claim(tmp_path):
    rows = candidates(1)
    old = recovery.draw(tmp_path, rows, 1, hold_seconds=-1)[0]
    current = recovery.draw(tmp_path, rows, 1)[0]
    recovery.release(tmp_path, old)
    assert recovery.draw(tmp_path, rows, 1) == []
    recovery.release(tmp_path, current)
    assert len(recovery.draw(tmp_path, rows, 1)) == 1


def test_queue_changed_evidence_gets_fresh_turn_and_server_scopes_are_separate(tmp_path):
    rows = candidates(2)
    for row in recovery.draw(tmp_path, rows, 2, "one"):
        recovery.release(tmp_path, row, "one")
    rows[1]["evidence_hash"] = "new"
    assert recovery.draw(tmp_path, rows, 1, "one")[0]["addr"] == rows[1]["addr"]
    assert len(recovery.draw(tmp_path, rows, 2, "two")) == 2


def task_folder(tmp_path):
    folder = tmp_path / "target"
    folder.mkdir()
    (folder / "task.json").write_text(json.dumps(dict(client="C", addr="00401000", evidence_hash="proof")))
    (folder / "00401000.cpp").write_text("source")
    return folder


def test_no_check_triage_saves_blocker_and_stops_process(tmp_path):
    folder = task_folder(tmp_path)
    killed = threading.Event()
    with recovery.session(tmp_path, folder, triage_seconds=0):
        watch = recovery.watch(killed.set, lambda message: None)
        assert killed.wait(2)
        watch[0].set()
    blocker = json.loads((folder / "blocker.json").read_text())
    assert blocker["addresses"] == ["00401000"] and blocker["evidence_hash"] == "proof"
    assert "No journaled experiment" in blocker["missing_evidence"]
    assert research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")[0] == blocker
    assert getattr(recovery.SESSION, "value", None) is None


def test_first_check_passes_triage_and_metrics_use_receipts(tmp_path):
    folder = task_folder(tmp_path)
    (folder / "trials.jsonl").write_text(json.dumps(dict(seconds_to_check=13.5, after=100)))
    killed = threading.Event()
    with recovery.session(tmp_path, folder, triage_seconds=0):
        watch = recovery.watch(killed.set, lambda message: None)
        watch[0].set()
    assert not killed.is_set()
    metrics = recovery.metrics(folder, 600, verified_gains=0, verified_exacts=0)
    assert metrics["first_check_seconds"] == 13.5
    assert metrics["verified_gains_per_hour"] == 0  # Local 100% is not a verified gain.
    assert recovery.metrics(folder, 600, 2, 1)["verified_gains_per_hour"] == 12


def test_unchanged_baseline_check_does_not_unlock_triage(tmp_path):
    folder = task_folder(tmp_path)
    (folder / "trials.jsonl").write_text(json.dumps(dict(source_hash="same", baseline_hash="same", seconds_to_check=1)))
    assert recovery.experiments(folder) == []
    assert recovery.metrics(folder, 10, 0, 0)["first_check_seconds"] is None
    with recovery.session(tmp_path, folder, triage_seconds=0):
        assert recovery.remaining() == 0


def test_metrics_report_excludes_legacy_and_local_similarity_counters(tmp_path):
    base = dict(profile="model", selection="persistent_random", wall_elapsed_seconds=600, matched=1, improved=1,
        recovery_metrics=[dict(first_check_seconds=10, blocked=False), dict(first_check_seconds=None, blocked=True)])
    for name, summary in (("new", base), ("old", dict(base, selection="ranked", matched=100))):
        folder = tmp_path / "work/agent-auto" / name
        folder.mkdir(parents=True)
        (folder / "summary.json").write_text(json.dumps(summary))
    report = recovery.report(tmp_path)
    assert report["completed_runs"] == 1
    assert report["coverage"] == dict(summary_files=2, eligible_runs=1, legacy_runs_excluded=1, unreadable_summaries=0)
    assert report["profiles"]["model"]["verified_gains_per_hour"] == 12
    assert report["profiles"]["model"]["median_first_check_seconds"] == 10
    assert report["profiles"]["model"]["blocked"] == 1


def test_metrics_coverage_scans_beyond_report_limit_and_counts_partial_json(tmp_path):
    current = json.dumps(dict(selection="persistent_random", profile="model", matched=0, improved=0,
                              wall_elapsed_seconds=10, recovery_metrics=[]))
    for name, text in (("old", '{"selection":"ranked"}'), ("writing", '{'),
                       ("new1", current), ("new2", current)):
        folder = tmp_path / "work/agent-auto" / name
        folder.mkdir(parents=True)
        (folder / "summary.json").write_text(text)
    report = recovery.report(tmp_path, limit=1)
    assert report["completed_runs"] == 1
    assert report["coverage"] == dict(summary_files=4, eligible_runs=2, legacy_runs_excluded=1, unreadable_summaries=1)


def test_metrics_report_distinguishes_repair_receipts_from_compiler_reuse(tmp_path):
    folder = tmp_path / "work/agent-auto/run"
    folder.mkdir(parents=True)
    summary = dict(selection="persistent_random", profile="model", matched=3, improved=2,
        wall_elapsed_seconds=600, recovery_metrics=[dict(first_check_seconds=15, blocked=False,
            verified_gains=2, verified_exacts=1), dict(first_check_seconds=None, blocked=True,
            verified_gains=0, verified_exacts=0)])
    (folder / "summary.json").write_text(json.dumps(summary))
    profile = recovery.report(tmp_path)["profiles"]["model"]
    assert profile["verified_gains_per_hour"] == 30
    assert profile["repair_verified_gains"] == 2
    assert profile["repair_verified_exacts"] == 1
    assert profile["repair_verified_gains_per_hour"] == 12
    assert profile["repair_targets"] == 2
    assert profile["checked_targets"] == 1
    assert profile["checked_target_fraction"] == .5  # Missing checks stay in the denominator.


def test_blocker_reasons_survive_metrics_and_backfill_older_summaries(tmp_path):
    folder = tmp_path / "work/agent-auto/run"
    target = folder / "repair/2008-06/00401000"
    target.mkdir(parents=True)
    (target / "blocker.json").write_text(json.dumps(dict(missing_evidence="No journaled experiment")))
    measured = recovery.metrics(target, 120, 0, 0)
    assert measured["blocked_reason"] == "No journaled experiment"
    summary = dict(selection="persistent_random", profile="model", matched=0, improved=0,
        wall_elapsed_seconds=120, recovery_metrics=[
            dict(measured, client="2008-06", addr="00401000"),
            dict(first_check_seconds=None, blocked=True, client="2008-06", addr="00401000"),
            dict(first_check_seconds=None, blocked=True)])
    (folder / "summary.json").write_text(json.dumps(summary))
    profile = recovery.report(tmp_path)["profiles"]["model"]
    assert profile["blocked"] == 3
    assert profile["blocked_reasons"] == {"No journaled experiment": 2, "unrecorded": 1}


def test_evidence_packet_contains_target_neighbours_headers_and_read_only_siblings(tmp_path, monkeypatch):
    from roc import libs
    folder = tmp_path / "vendor"
    folder.mkdir()
    (folder / "real.h").write_text("struct Authentic { int count; };")
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    monkeypatch.setattr(libs, "RECIPES", {"vendor": {"src": "vendor", "defines": "REAL", "include": []}})
    target = dict(addr="00401000", unit="Target", size=20, callers=["00402000"], call_targets=["00403000"],
                  imports=["API"], strings=["message"])
    rows = {target["addr"]: target, "00402000": {"unit": "Caller"}, "00403000": {"unit": "Callee"}}
    monkeypatch.setattr(match, "_functions", lambda client: rows)
    monkeypatch.setattr(match, "target", lambda client, addr: (b"asm", [], rows[addr]))
    monkeypatch.setattr(match, "disasm", lambda code, addr: ["instruction at %x" % addr])
    packet = recovery.packet(tmp_path, "C", target["addr"], "// roc-lib: vendor body.cpp",
        {"donors": [dict(addr="00404000", score=100, source="read only")]})
    assert packet["target_asm"] == ["instruction at 401000"]
    assert {row["unit"] for row in packet["neighbours"]} == {"Caller", "Callee"}
    assert packet["facts"]["imports"] == ["API"] and packet["facts"]["strings"] == ["message"]
    assert packet["authentic_headers"][0]["excerpt"] == "struct Authentic { int count; };"
    assert packet["siblings"][0]["matched_read_only"] is True


def test_evidence_packet_prioritizes_actual_nested_source_headers(tmp_path, monkeypatch):
    from roc import libs
    folder = tmp_path / "vendor"
    (folder / "src").mkdir(parents=True)
    (folder / "include/util").mkdir(parents=True)
    (folder / "src/body.cpp").write_text('#include "util/Actual.h"\n#include "missing.h"\n')
    (folder / "include/util/Actual.h").write_text("struct Actual {};")
    (folder / "noise.h").write_text("unrelated")
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    monkeypatch.setattr(libs, "RECIPES", {"vendor": {"src": "vendor", "include": ["vendor/include", "WINSDK"]}})
    target = dict(addr="00401000", size=1)
    monkeypatch.setattr(match, "_functions", lambda client: {target["addr"]: target})
    monkeypatch.setattr(match, "target", lambda client, addr: (b"x", [], target))
    monkeypatch.setattr(match, "disasm", lambda *args: [])
    packet = recovery.packet(tmp_path, "C", target["addr"], "// roc-lib: vendor src/body.cpp", {})
    assert packet["authentic_headers"][0]["path"] == str(folder / "include/util/Actual.h")
    assert packet["authentic_headers"][0]["excerpt"] == "struct Actual {};"
    assert len(packet["authentic_headers"]) == 1  # Do not pad actual includes with unrelated headers.
    assert packet["authentic_library"]["source_path"] == str((folder / "src/body.cpp").resolve())
    assert packet["authentic_library"]["candidate_only"]
    assert not packet["missing_evidence"]


def test_packet_includes_relocated_template_types_without_claiming_layout(tmp_path, monkeypatch):
    from roc import rtti
    target = dict(addr="00401000", size=5)
    refs = [dict(offset=1, address=0x500000,
        type=".?AV?$TypedPropertyDescriptor@H@Reflection@RBX@@")]
    monkeypatch.setattr(match, "_functions", lambda client: {target["addr"]: target})
    monkeypatch.setattr(match, "target", lambda client, addr: (b"\x68\0\0\x50\0", [1], target))
    monkeypatch.setattr(match, "disasm", lambda *args: [])
    monkeypatch.setattr(rtti, "vtable_stores", lambda *args: [])
    monkeypatch.setattr(rtti, "function_refs", lambda client, addr: refs)
    packet = recovery.packet(tmp_path, "C", target["addr"], "", {})
    assert packet["rtti_type_refs"] == refs
    assert not packet["rtti_vtable_stores"]

    monkeypatch.setattr(match, "target", lambda client, addr: (b"\xc3", [], target))
    monkeypatch.setattr(rtti, "function_refs", lambda *args: pytest.fail("No relocations: do not load image"))
    assert recovery.packet(tmp_path, "C", target["addr"], "", {})["rtti_type_refs"] == []


def test_library_header_excerpt_skips_license_and_preserves_full_path(tmp_path, monkeypatch):
    from roc import libs
    folder = tmp_path / "vendor"
    folder.mkdir()
    path = folder / "real.h"
    text = "/*" + "license " * 1000 + "*/\nstruct Authentic {" + "int member;\n" * 1000 + "};"
    path.write_text(text)
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    monkeypatch.setattr(libs, "RECIPES", {"vendor": {"src": "vendor", "include": []}})
    target = dict(addr="00401000", size=1)
    monkeypatch.setattr(match, "_functions", lambda client: {target["addr"]: target})
    monkeypatch.setattr(match, "target", lambda client, addr: (b"x", [], target))
    monkeypatch.setattr(match, "disasm", lambda *args: [])
    packet = recovery.packet(tmp_path, "C", target["addr"], "// roc-lib: vendor body.cpp", {})
    row = packet["authentic_headers"][0]
    assert row["path"] == str(path) and row["read_only"]
    assert len(row["excerpt"]) == 2400 and row["truncated"]
    assert "struct Authentic" in row["excerpt"]
    assert path.read_text() == text
    assert packet["authentic_library"]["candidate_only"]
    assert packet["authentic_library"]["source_path"] is None


@pytest.mark.parametrize("second_result", ["unverified", "not_improved", "error"])
def test_propagation_checks_full_match_and_only_counts_verified_improvements(tmp_path, monkeypatch, second_result):
    donor = dict(client="C", addr="00401000", shape="same")
    rows = [dict(addr="00402000", shape="same", score=90), dict(addr="00403000", shape="same", score=0),
            dict(addr="00404000", shape="same", score=100), dict(addr="00405000", shape="different", score=0)]
    compiled, checked, released = [], [], []
    monkeypatch.setattr(match, "compile_text", lambda *args: compiled.append(args) or b"object")
    def check(client, addr, source, obj):
        assert obj == b"object"
        checked.append(addr)
        return (100, "f", "", [])
    monkeypatch.setattr(match, "check_text", check)

    class Api:
        def call(self, endpoint, body, **kwargs):
            if endpoint == "/v1/lease":
                addr = body["targets"][0]["addr"]
                return {"job": dict(client="C", addr=addr, score=0, lease=addr)}
            if endpoint == "/v1/submit":
                if body["addr"] == "00402000":
                    return dict(verified=True, improved=True, score=100)
                if second_result == "error":
                    raise OSError("server disconnected")
                return dict(verified=second_result != "unverified", improved=second_result != "not_improved", score=100)
            released.append(body["lease"])
    result = recovery.propagate(tmp_path, Api(), "user", "worker", "model", donor, "source", rows, 512,
                                time.monotonic()+10, lambda message: None)
    assert [row["addr"] for row in result] == ["00402000"]
    assert checked == released == ["00402000", "00403000"] and len(compiled) == 1
    assert len(research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")) == 1


def test_blocked_target_waits_for_its_own_evidence_change():
    rows = [dict(client="2008-06", addr="00401000", size=50, unit="fn", score=0, source="", kind="code")]
    target = agent_auto.plan(rows, records=[], random_targets=True)["areas"][0]["targets"][0]
    records = [dict(kind="recovery_blocked", client="2008-06", addresses=["00401000"], evidence_hash=target["evidence_hash"])]
    assert agent_auto.plan(rows, records=records, random_targets=True)["areas"][0]["targets"][0]["group_parked"]
    records[0]["retry_at"] = time.time() - 1
    assert not agent_auto.plan(rows, records=records, random_targets=True)["areas"][0]["targets"][0]["group_parked"]
    records[0].pop("retry_at")
    rows[0]["strings"] = ["new proof"]
    assert not agent_auto.plan(rows, records=records, random_targets=True)["areas"][0]["targets"][0]["group_parked"]
