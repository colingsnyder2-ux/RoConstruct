import json
import threading
import time
from types import SimpleNamespace

from roc import research


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
        logs.append(line)
        if "00401000" in line:
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
        assert spec["op"] in ("grid", "fanout") and spec.get("hypothesis"), name
        assert spec.get("client", "2008-06") == "2008-06", name
        if spec["op"] == "fanout":
            assert all(item["recipe"] in research.libs.RECIPES for item in spec["sources"]), name
