from unittest.mock import patch

from roc import matchers, match


def test_native_objects_compile_once_and_fan_out_to_every_destination():
    source = "// roc-cl: 21022\n// roc-flags: /O2\n// roc-lib: vendor native.cpp"
    reg = {"A": {"compiler_build": 21022}, "B": {"compiler_build": 21022}, "C": {"compiler_build": 21022}}
    probes = {client: object() for client in ("A", "B")}
    with patch.object(matchers.fingerprint, "Target", side_effect=lambda c: probes[c]), \
         patch.object(match, "compile_text", return_value=b"obj") as compile_text, \
         patch.object(matchers, "_match_batch", return_value={}) as scan:
        assert matchers.native_fanout(["A", "B"], [(source, [("C", "addr")])], reg, 2,
            False, True, False, None, lambda _: None) == {"A": (0, 0), "B": (0, 0)}
    assert compile_text.call_count == 1
    assert {call.args[3] for call in scan.call_args_list} == {"A", "B"}


def test_object_reuse_keeps_cross_client_eligibility_per_destination():
    prefix = "// roc-cl: 21022\n// roc-flags: /O2\n// roc-lib: vendor "
    sources = [(prefix + "one.cpp", [("A", "one")]), (prefix + "two.cpp", [("B", "two")])]
    reg = {"A": {"compiler_build": 21022}, "B": {"compiler_build": 21022}}
    with patch.object(matchers.fingerprint, "Target", return_value=object()), \
         patch.object(match, "compile_text", return_value=b"same object"), \
         patch.object(matchers, "_match_batch", return_value={}) as scan:
        matchers.native_fanout(list(reg), sources, reg, 2, False, True, False, None, lambda _: None)
    assert sorted(call.args[3] for call in scan.call_args_list) == ["A", "B"]


def test_authoritative_scores_lower_stale_exacts_without_losing_other_rows(tmp_path):
    with patch.object(match, "ROOT", tmp_path):
        match.save_scores("A", {"one": 100, "two": 90})
        assert match.save_scores("A", {"one": 80})["one"] == 100
        assert match.save_scores("A", {"one": 80}, authoritative=True) == {"one": 80, "two": 90}


def test_cache_replace_retries_windows_reader_conflict():
    with patch.object(match.os, "name", "nt"), \
         patch.object(match.os, "replace", side_effect=[PermissionError("busy"), None]) as replace, \
         patch.object(match.time, "sleep"):
        match._replace_cache("source", "destination")
    assert replace.call_count == 2


def test_fanout_saves_score_batch_after_sources_exist(tmp_path):
    found = {"00401000": ("void a() {}", "a", []), "00401010": ("void b() {}", "b", [])}
    def save_scores(client, values):
        assert values == {addr: 100 for addr in found}
        assert all((tmp_path / "src" / client / (addr + ".cpp")).exists() for addr in found)
    with patch.object(matchers.fingerprint, "ROOT", tmp_path), \
         patch.object(match, "template", return_value="// header\n\nunused"), \
         patch.object(match, "save_data"), patch.object(match, "save_scores", side_effect=save_scores) as save:
        assert matchers.fingerprint.save("A", found, "copy") == 2
    assert save.call_count == 1


def test_authoritative_donors_need_no_local_sources_or_scores(tmp_path):
    class Api:
        def __init__(self, *args):
            self.pages = iter([[dict(addr="00401000", score=100, source="void f() {}"),
                                dict(addr="00401010", score=90, source="void partial() {}")], []])

        def call(self, path, **kwargs):
            return next(self.pages)

        def close(self):
            pass

    with patch.object(matchers, "ROOT", tmp_path), \
         patch.object(matchers.clients, "load", return_value={"A": {}}), \
         patch("roc.worker.Api", Api), patch("roc.worker.load_settings", return_value={}):
        assert matchers.matched_sources(log=lambda _: None, exact_only=True, source_server="http://local") == [
            ("void f() {}", [("A", "00401000")])]


def test_masked_index_preserves_relocation_checks_and_retirement():
    target = object.__new__(matchers.fingerprint.Target)
    target.base = 0x1000
    target.image = bytes.fromhex("a111223344c3") + b"\xcc" * 10 + bytes.fromhex("a255667788c3")
    target.relocs = [0x1001, 0x1011]
    target.index = {6: ["00001000", "00001010"]}
    target._masked_index = {}
    code = bytes.fromhex("a199999999c3")
    assert target.candidates(code, [1]) == ["00001000"]
    assert target.candidates(code, []) == []
    target.index[6].remove("00001000")
    assert target.candidates(code, [1]) == []


def test_batch_preserves_distinct_functions_and_calls():
    source = "void func_00401000() {}\nvoid func_00401010() { func_00401000(); }"
    for text in (matchers._batch_cpp([(source, [])])[0], matchers._batch_alone(source)[0]):
        assert text.count("fn_ROCX000000_00401000") == 2
        assert text.count("fn_ROCX000000_00401010") == 1
    assert matchers.needs_global_scope("void* operator new(unsigned int n, void* p) { return p; }")
    assert matchers.needs_global_scope("namespace ns_ROCX000001 { void fn_ROCX000001() {} }")


def test_source_declarations_before_blank_survive(tmp_path):
    folder = tmp_path / "src" / "A"
    folder.mkdir(parents=True)
    source = "struct S { int f(); };\n\nint S::f() { return 1; }"
    (folder / "00401000.cpp").write_text(source)
    with patch.object(matchers, "ROOT", tmp_path), \
         patch.object(matchers.clients, "load", return_value={"A": {}}):
        assert matchers.matched_sources(log=lambda _: None) == [(source, [("A", "00401000")])]


def test_library_filter_and_target_compiler_variant(tmp_path):
    folder = tmp_path / "src" / "A"
    folder.mkdir(parents=True)
    source = "// roc-cl: 21022\n// roc-lib: vendor native.cpp"
    (folder / "00401000.cpp").write_text(source)
    (folder / "00401010.cpp").write_text("void plain() {}")
    (folder / "00401020.cpp").write_text("// roc-cl: 21022\n// different address comment\n// roc-lib: vendor native.cpp")
    with patch.object(matchers, "ROOT", tmp_path), \
         patch.object(matchers.clients, "load", return_value={"A": {}}):
        assert matchers.matched_sources(log=lambda _: None, libraries_only=True) == [
            (source, [("A", "00401000"), ("A", "00401020")])]

    class Probe:
        index = {6: ["target"]}

    compiled = []
    with patch.object(matchers.clients, "load", return_value={"A": {"compiler_build": 50727}}), \
         patch.object(matchers, "matched_sources", return_value=[(source, [("B", "donor")])]), \
         patch.object(matchers.fingerprint, "Target", return_value=Probe()), \
         patch.object(matchers, "_matched_count", return_value=0), \
         patch.object(matchers, "compile_batch", side_effect=lambda c, rows, *args: compiled.extend(rows) or []):
        matchers.run(targets=["A"], retarget=True, log=lambda _: None)
    assert {body for body, _ in compiled} == {source, "// roc-cl: 50727\n// roc-lib: vendor native.cpp"}


def test_twins_cross_compilers_and_relocated_addresses():
    class Probe:
        index = {6: ["target"]}

    binaries = {
        ("A", "target"): (b"\xa1\x11\x22\x33\x44\xc3", [1], {}),
        ("B", "donor"): (b"\xa1\x55\x66\x77\x88\xc3", [1], {}),
        ("C", "other"): (b"\xa2\x55\x66\x77\x88\xc3", [1], {}),
    }
    sources = [("own", [("A", "target")]), ("twin", [("B", "donor")]),
               ("different", [("C", "other")])]
    with patch.object(matchers.match, "target", side_effect=lambda c, a: binaries[c, a]):
        assert matchers.twin_candidates("A", sources, Probe()) == [sources[1]]
        variants = matchers.twin_candidates("A", sources, Probe(), {
            "A": {"compiler_build": 21022, "flags": "/O2 /GS-"},
            "B": {"compiler_build": 50727, "flags": "/O2 /GS"},
        })
    assert variants[0] == sources[1]
    assert variants[1][0] == "// roc-cl: 50727\n// roc-flags: /O2 /GS\ntwin"


def test_cross_only_includes_other_compiler_sources(tmp_path):
    reg = {"A": {"compiler_build": 21022}, "B": {"compiler_build": 50727}}
    with patch.object(matchers.clients, "load", return_value=reg), \
         patch.object(matchers, "matched_sources", return_value=[]) as sources:
        assert matchers.run(targets=["A"], cross_only=True, log=lambda _: None) == {}
    assert sources.call_args.kwargs["client_names"] == ["B"]


def test_parallel_twins_save_only_checked_hits():
    class Probe:
        index = {6: ["target"]}

    sources = [("source", [("B", "donor")])]
    hit = {"target": ("source", "symbol", [])}
    with patch.object(matchers.clients, "load", return_value={"A": {}}), \
         patch.object(matchers, "matched_sources", return_value=sources), \
         patch.object(matchers.fingerprint, "Target", return_value=Probe()), \
         patch.object(matchers, "twin_candidates", return_value=sources), \
         patch.object(matchers, "compile_batch", return_value=[(b"obj", {})]), \
         patch.object(matchers, "_match_batch", return_value=hit), \
         patch.object(matchers, "_matched_count", side_effect=[0, 1]), \
         patch.object(matchers.fingerprint, "save", return_value=1) as save:
        assert matchers.run(targets=["A"], twins=True, jobs=2, log=lambda _: None) == {"A": (1, 1)}
    assert save.call_args.args[1] == hit
