import pytest
from types import SimpleNamespace

from roc import match, research, telemetry


@pytest.fixture
def candidates(monkeypatch):
    code = b"\x55\x8b\xec\xb8\x01\x00\x00\x00" + b"\x90" * 20 + b"\x5d\xc3"
    functions = [("near", code[:4] + b"\x02" + code[5:], []),
                 ("small", b"\x90\xc3", []),
                 ("different", b"\xcc" * 45, [])]
    monkeypatch.setattr(match, "target", lambda *args: (code, [], {}))
    monkeypatch.setattr(match, "compile_text", lambda *args: b"object")
    monkeypatch.setattr(match, "coff_functions", lambda *args: functions)
    monkeypatch.setattr(telemetry, "candidate", lambda *args: None)
    return code, functions


@pytest.mark.parametrize("minimum", [0, 20, 60, 90, 98, 99])
def test_improvement_bounds_preserve_best_result(candidates, minimum):
    full = match.check_text("2008-06", "00401000", "source")
    bounded = match.check_text("2008-06", "00401000", "source", minimum=minimum)
    if full[0] > minimum:
        assert bounded == full
    else:
        assert bounded[0] is None


def test_99_gate_skips_all_fuzzy_scoring(candidates, monkeypatch):
    monkeypatch.setattr(match, "score", lambda *args: pytest.fail("unnecessary fuzzy scoring"))
    assert match.check_text("2008-06", "00401000", "source", minimum=99)[0] is None


@pytest.mark.parametrize("bad_data", [False, True])
def test_bounded_exact_still_checks_referenced_data(candidates, monkeypatch, bad_data):
    code, functions = candidates
    functions.append(("exact", code, []))
    checked = []
    def data(client, addr, code, obj, exacts):
        checked.append(exacts)
        return exacts[0], [(1, 4)], ["wrong string"] if bad_data else []
    monkeypatch.setattr(match, "select_exact_data", data)
    result = match.check_text("2008-06", "00401000", "source", minimum=99)
    assert result[0] == (99 if bad_data else 100)
    assert checked


def test_improvement_resume_reuses_old_full_scores(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    research.append(tmp_path / "work/agent-memory/compiler-trials.jsonl",
                    dict(client="2008-06", terminal=True, evidence_key="same", score=90))
    monkeypatch.setattr(research, "compiler_evidence", lambda *args: "same")
    monkeypatch.setattr(research, "variants", lambda *args, **kwargs: iter([("variant", 21022, "/O2")]))
    monkeypatch.setattr(match, "check_text", lambda *args, **kwargs: pytest.fail("completed gate repeated"))
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage: [], record=lambda *args: None)
    stats = {}
    research.grid(campaign, "new", [dict(addr="00401000", score=95, source="source")],
                  reuse_history=True, improvement_only=True, stats=stats, log=lambda line: None)
    assert stats["skipped"] == 1 and stats["checks"] == 0


def test_bounded_scoring_agrees_on_varied_lengths_and_relocations(monkeypatch):
    import random
    rng = random.Random(310)
    monkeypatch.setattr(match, "compile_text", lambda *args: b"object")
    monkeypatch.setattr(match, "diff", lambda *args: "diff")
    monkeypatch.setattr(match, "rank_candidate", lambda a, ar, b, br: (match.score(a, ar, b, br), 0, 0))
    monkeypatch.setattr(match, "select_exact_data", lambda c, a, code, obj, exacts: (exacts[0], [], []))
    monkeypatch.setattr(telemetry, "candidate", lambda *args: None)
    for _ in range(40):
        code = rng.randbytes(rng.randrange(12, 60))
        relocs = [rng.randrange(len(code) - 4)]
        functions = []
        for index in range(8):
            candidate = bytearray(code[:rng.randrange(6, len(code) + 1)])
            for _ in range(rng.randrange(1, 6)):
                candidate[rng.randrange(len(candidate))] = rng.randrange(256)
            candidate.extend(rng.randbytes(rng.randrange(5)))
            functions.append((str(index), bytes(candidate), [rng.randrange(len(candidate) - 4)]))
        monkeypatch.setattr(match, "target", lambda *args: (code, relocs, {}))
        monkeypatch.setattr(match, "coff_functions", lambda *args: functions)
        full = match.check_text("2008-06", "00401000", "source")
        for minimum in (20, 65, 85, 99):
            bounded = match.check_text("2008-06", "00401000", "source", minimum=minimum)
            if full[0] > minimum:
                assert bounded[0] == full[0]
            else:
                assert bounded[0] is None


def test_portfolios_recover_sourceless_targets_and_isolate_clients(tmp_path, monkeypatch):
    from roc import brute
    monkeypatch.setattr(brute.libs, "RECIPES", {})
    stored = [dict(addr="donor", score=100, source="int f(){return 7;}"),
              dict(addr="open", score=70, source="int f(){return 8;}")]
    functions = {"donor": dict(kind="code", shape="same"),
                 "open": dict(kind="code", shape="same"),
                 "empty": dict(kind="code", shape="same"),
                 "data": dict(kind="data", shape="same")}
    other = tmp_path / "foreign"
    other.mkdir()
    (other / "best.cpp").write_text("int f(){return 2009;}")
    research.append(tmp_path / "work/agent-memory/attempts.jsonl", dict(kind="trial", client="2009-12",
                    addresses=["empty"], evidence=str(other / "trials.jsonl"), after=99))
    rows = brute.portfolios(tmp_path, "2008-06", stored, functions, {}, {})
    assert {row["addr"] for row in rows} == {"open", "empty"}
    empty = next(row for row in rows if row["addr"] == "empty")
    assert empty["score"] == 0 and empty["source"] == stored[0]["source"]
    assert all("2009" not in row["source"] for row in rows)


def test_portfolios_try_real_alternate_native_recipe(tmp_path, monkeypatch):
    from roc import brute
    folder = tmp_path / "tools/native"
    folder.mkdir(parents=True)
    (folder / "Method.cpp").write_text("int f(){return 1;}")
    monkeypatch.setattr(brute.libs, "LIBS", tmp_path / "tools")
    monkeypatch.setattr(brute.libs, "RECIPES", {
        "native": dict(src="native", grid=["/O2"]),
        "native-dll": dict(src="native", grid=["/O2 /MD"])})
    monkeypatch.setattr(brute.clients, "load", lambda: {"2008-06": dict(compiler_build=21022)})
    stored = [dict(addr="open", score=80, source="// roc-lib: native Method.cpp\n")]
    rows = brute.portfolios(tmp_path, "2008-06", stored,
                            {"open": dict(kind="code", shape="shape")}, {}, {})
    assert len(rows[0]["candidates"]) == 1
    assert "native-dll Method.cpp" in rows[0]["candidates"][0]["source"]


def test_grid_tries_source_portfolio_then_stops_on_exact(tmp_path, monkeypatch):
    calls = []
    monkeypatch.setattr(research, "variants", lambda source, *args, **kwargs: iter([(source, 21022, "/O2")]))
    monkeypatch.setattr(match, "check_text", lambda client, addr, source: calls.append(source) or
                        (100 if source == "winner" else 70, "fn", "", []))
    records = []
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage: [], record=lambda stage, row: records.append(row),
                               submit_exact=lambda *args: dict(submission=dict(verified=True, improved=True)))
    rows = [dict(addr="00401000", score=60, source="stored", candidates=[
        dict(source="winner", origin="native core"), dict(source="unused", origin="old partial")])]
    wins = research.grid(campaign, "portfolio", rows, log=lambda line: None)
    assert calls == ["stored", "winner"] and len(wins) == 1
    assert records[-1]["origin"] == "native core"


def test_context_profiles_preserve_vendor_defines_and_runtime():
    source = "// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD /D_VENDOR\nint f(){return 1;}"
    variants = list(research.variants(source, builds=[21022], profiles=["context"]))
    assert len(variants) >= 8
    assert all("/MD" in flags and "/D_VENDOR" in flags for _, _, flags in variants)
    assert any("/Ob1" in flags and "/Oy-" in flags for _, _, flags in variants)


def test_partial_submission_preserves_better_server_source(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    campaign = research.Campaign.__new__(research.Campaign)
    campaign.root, campaign.user = tmp_path, "tester"
    campaign.info = dict(clients={"2008-06": {}}, verify=["2008-06"])
    current, posted, records = [95], [], []
    campaign.current = lambda *args: dict(score=current[0])
    campaign.api = SimpleNamespace(call=lambda *args, **kwargs: posted.append((args, kwargs)) or
                                   dict(score=94, stored=94, verified=True, improved=True))
    campaign.record = lambda *args: records.append(args)
    source_path = tmp_path / "candidate.cpp"
    campaign.submit_partial("portfolio", "2008-06", "00401000", "int f(){}", 94, source_path)
    assert not posted
    current[0] = 90
    result = campaign.submit_partial("portfolio", "2008-06", "00401000", "int f(){}", 94, source_path)
    assert result["submission"]["improved"] and len(posted) == len(records) == 1
    memory = research.journal_records(tmp_path / "work/agent-memory/attempts.jsonl")
    assert memory[0]["after"] == 94 and memory[0]["exacts_gained"] == 0


def test_legacy_structured_evidence_does_not_break_portfolio(tmp_path, monkeypatch):
    from roc import brute
    monkeypatch.setattr(brute.libs, "RECIPES", {})
    research.append(tmp_path / "work/agent-memory/attempts.jsonl", dict(kind="trial", client="2008-06",
                    addresses=["open"], evidence={"receipt": "structured legacy evidence"}))
    rows = brute.portfolios(tmp_path, "2008-06", [dict(addr="open", score=60, source="int f(){return 1;}")],
                            {"open": dict(kind="code")}, {}, {})
    assert len(rows) == 1


def test_sourceless_native_class_source_is_a_candidate_not_layout_proof(tmp_path, monkeypatch):
    from roc import brute
    monkeypatch.setattr(brute.libs, "RECIPES", {"native": dict(src="native", grid=["/O2"])})
    monkeypatch.setattr(brute.fingerprint, "local_versions", lambda families: {
        ("roblox", "thingclass"): [("native", "ThingClass.cpp")]})
    monkeypatch.setattr(brute.clients, "load", lambda: {"2008-06": dict(compiler_build=21022)})
    rows = brute.portfolios(tmp_path, "2008-06", [], {
        "open": dict(kind="code", unit="RBX::ThingClass")}, {}, {})
    assert rows[0]["score"] == 0
    assert "native ThingClass.cpp" in rows[0]["source"]
    assert rows[0]["source_origin"].startswith("installed native class")


def test_identical_object_profiles_reuse_bound_without_skipping_changed_data(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research, "variants", lambda *args, **kwargs: iter([
        ("first", 21022, "a"), ("same", 21022, "b"), ("changed-data", 21022, "c")]))
    monkeypatch.setattr(match, "compile_text", lambda client, source: b"head" + b"time" +
                        (b"data2" if source == "changed-data" else b"data1"))
    calls = []
    monkeypatch.setattr(match, "check_text", lambda *args, **kwargs: calls.append(args[2]) or (80, "fn", "", []))
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage: [], record=lambda *args: None)
    stats = {}
    research.grid(campaign, "objects", [dict(addr="00401000", score=90, source="source")],
                  reuse_objects=True, stats=stats, log=lambda line: None)
    assert calls == ["first", "changed-data"] and stats["object_reuses"] == 1


def test_known_header_blocker_skips_flags_but_allows_new_native_core(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    def variants(source, *args, **kwargs):
        return iter([(source, 21022, "first"), (source, 21022, "second")])
    monkeypatch.setattr(research, "variants", variants)
    def evidence(client, row, source, build, flags, units):
        file = "bad.cpp" if "bad.cpp" in source else "core.cpp"
        units[("native", file, build)] = file
        return source + flags
    monkeypatch.setattr(research, "compiler_evidence", evidence)
    calls = []
    def check(client, addr, source):
        calls.append(source)
        if "bad.cpp" in source:
            raise match.CompileError("C2248: RBX::IRenderable::indexFunc2d private access")
        return 100, "fn", "", []
    monkeypatch.setattr(match, "check_text", check)
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage: [], record=lambda *args: None,
        submit_exact=lambda *args: dict(submission=dict(verified=True, improved=True)))
    stats = {}
    wins = research.grid(campaign, "native", [dict(addr="00401000", score=90,
        source="// roc-lib: native bad.cpp", candidates=[dict(source="// roc-lib: native core.cpp")])],
        reuse_history=True, stats=stats, log=lambda line: None)
    assert len(wins) == 1 and len(calls) == 2 and stats["skipped"] == 1


def test_portfolio_fanout_deduplicates_contexts_without_losing_distinct_data(monkeypatch):
    from roc import brute
    monkeypatch.setattr(research, "variants", lambda source, *args, **kwargs: iter([
        (source + "-normal", 21022, "/O2"), (source + "-fast", 21022, "/fp:fast")]))
    rows = [dict(addr="first", source="body", candidates=[dict(source="body", origin="donor")]),
            dict(addr="second", source="body"), dict(addr="third", source="other-data")]
    sources = list(brute.portfolio_sources(rows, "2008-06", [21022], ["context"], [""]))
    assert len(sources) == 4
    assert [evidence["seed_addr"] for _, evidence in sources[:2]] == ["first", "third"]
    assert {source for source, _ in sources} == {"body-normal", "body-fast", "other-data-normal", "other-data-fast"}
    assert all(evidence["seed_addr"] in {"first", "third"} for _, evidence in sources)


def test_portfolio_fanout_covers_targets_before_alternate_candidates(monkeypatch):
    from roc import brute
    monkeypatch.setattr(research, "variants", lambda source, *args, **kwargs: iter([(source, 21022, "/O2")]))
    rows = [dict(addr="first", source="first-body", candidates=[dict(source="alt-" + str(i)) for i in range(10)]),
            dict(addr="second", source="second-body"), dict(addr="third", source="third-body")]
    sources = list(brute.portfolio_sources(rows, "2008-06", [21022], ["keep"], [""]))
    assert [source for source, _ in sources[:3]] == ["first-body", "second-body", "third-body"]
    assert len(sources) == 13


def test_native_only_portfolio_excludes_direct_bodies(monkeypatch, tmp_path):
    from roc import brute
    monkeypatch.setattr(brute.libs, "RECIPES", {})
    stored = [dict(addr="direct", score=80, source="int f(){return 1;}"),
              dict(addr="native", score=80, source="// roc-lib: native File.cpp\n")]
    functions = {addr: dict(kind="code") for addr in ["direct", "native"]}
    rows = brute.portfolios(tmp_path, "2008-06", stored, functions, {}, dict(native_only=True))
    assert [row["addr"] for row in rows] == ["native"]


def test_portable_brute_uses_verified_bulk_passes_before_per_target_gates():
    for name in ["portable-bruteforce", "portable-bruteforce-deep"]:
        stages = research.recipes()[name]["stages"]
        assert stages[:2] == ["bruteforce-portfolio-fanout", "bruteforce-native-od-fanout"]
        assert stages.index("bruteforce-native-od-fanout") < stages.index("bruteforce-compiler-gates")


@pytest.mark.parametrize("bad_data", [False, True])
def test_exact_submission_skips_fuzzy_functions_but_verifies_data(candidates, monkeypatch, tmp_path, bad_data):
    code, functions = candidates
    functions.append(("exact", code, []))
    original_score = match.score
    def exact_score(target, relocs, body, body_relocs):
        assert body == code, "Exact submission must not fuzzy-score unrelated emitted functions"
        return original_score(target, relocs, body, body_relocs)
    monkeypatch.setattr(match, "score", exact_score)
    checked = []
    def data(client, addr, target, obj, exacts):
        checked.append(exacts)
        return exacts[0], [], ["wrong source constant"] if bad_data else []
    monkeypatch.setattr(match, "select_exact_data", data)
    submitted = []
    campaign = research.Campaign.__new__(research.Campaign)
    campaign.root, campaign.user, campaign.campaign_id = tmp_path, "tester", None
    campaign.info = dict(clients={"2008-06": {}}, verify=["2008-06"])
    campaign.current = lambda *a: dict(score=90)
    campaign.api = SimpleNamespace(call=lambda *a, **kw: submitted.append(a) or dict(verified=True, improved=True, score=100))
    result = campaign.submit_exact("exact", "2008-06", "00401000", "body")
    assert checked and result["score"] == (99 if bad_data else 100)
    assert bool(submitted) is not bad_data


def test_coff_function_extents_preserve_unsorted_aliases_sections_and_relocations():
    import struct
    first = b"\x90\xc3\xcc\xcc\xb8\x01\x00\x00\x00\xc3\xcc\xcc"
    second = b"\x33\xc0\xc3"
    rawptr = 20 + 2 * 40
    relptr = rawptr + len(first) + len(second)
    symbols = [(b"later", 4, 1), (b"alias", 0, 1), (b"start", 0, 1), (b"other", 0, 2)]
    header = struct.pack("<HHIIIHH", 0x14c, 2, 0, relptr + 10, len(symbols), 0, 0)
    section1 = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(first), rawptr, relptr, 0, 1, 0, 0x60000020)
    section2 = struct.pack("<8sIIIIIIHHI", b".text2", 0, 0, len(second), rawptr + len(first), 0, 0, 0, 0, 0x60000020)
    obj = header + section1 + section2 + first + second + struct.pack("<IIH", 5, 0, 6)
    obj += b"".join(struct.pack("<8sIhHBB", name, value, section, 0x20, 2, 0) for name, value, section in symbols)
    obj += struct.pack("<I", 4)
    assert match.coff_functions(obj) == [("later", first[4:10], [1]), ("alias", first[:2], []),
                                         ("start", first[:2], []), ("other", second, [])]


def test_compile_memory_eviction_reuses_persistent_object(tmp_path, monkeypatch):
    monkeypatch.setattr(match, "ROOT", tmp_path)
    monkeypatch.setattr(telemetry, "record", lambda *a, **kw: None)
    calls = []
    def compile_text(text, flags, build, c_lang):
        calls.append(text)
        return ("object:" + text).encode()
    monkeypatch.setattr(match, "_compile_uncached", compile_text)
    match._compile.cache_clear()
    try:
        for index in range(33):
            match._compile("unit" + str(index), "/O2", 21022, False)
        assert match._compile.cache_info().currsize == 32
        assert match._compile("unit0", "/O2", 21022, False) == b"object:unit0"
        assert len(calls) == 33
        assert match.coff_functions.cache_parameters()["maxsize"] == 32
    finally:
        match._compile.cache_clear()
