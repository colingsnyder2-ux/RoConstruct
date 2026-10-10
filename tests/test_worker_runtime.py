"""Regressions observed while running real bounded worker batches."""
import json
from concurrent.futures import ThreadPoolExecutor
from unittest.mock import patch

import pytest

from roc import draft, match, metrics, mutate, repair, worker


def test_recent_metrics_tail_cache_append_and_corrupt_rows(tmp_path):
    path = tmp_path / "metrics.jsonl"
    rows = [dict(session="old", event="job", id=i, padding="é" * 100) for i in range(5010)]
    path.write_text("\n".join(json.dumps(row, ensure_ascii=False) for row in rows) + "\n", encoding="utf-8")
    with patch.object(metrics, "PATH", path):
        first = metrics.recent_rows()
        assert [row["id"] for row in first] == list(range(10, 5010))
        with patch.object(type(path), "open", side_effect=AssertionError("cache reopened file")):
            with ThreadPoolExecutor(max_workers=8) as pool:
                assert all(row is first for row in pool.map(lambda _: metrics.recent_rows(), range(8)))
        with path.open("a", encoding="utf-8") as out:
            out.write('broken row\n[]\n{"session":"new","event":"job","score":100,"improved":true,"input_tokens":5,"output_tokens":7}\n')
        assert metrics.session_totals("new")["jobs"] == 1
        assert metrics.session_totals("new")["input_tokens"] == 5
        assert "1 matched" in metrics.summary("new")
        path.write_text('{"session":"replacement","id":1}\n', encoding="utf-8")
        assert metrics.recent_rows() == [{"session": "replacement", "id": 1}]


def test_data_mismatch_is_not_reported_as_exact():
    code = b"\xc3"
    with patch.object(match, "target", return_value=(code, [], {})), \
         patch.object(match, "compile_text", return_value=b"obj"), \
         patch.object(match, "coff_functions", return_value=[("f", code, [])]), \
         patch.object(match, "coff_data_refs", return_value=[]), \
         patch.object(match, "data_check", return_value=([], ["constant differs"])):
        checked = match.check_text("C", "00401000", "void f(){}", include_diagnosis=True)
    assert checked[0] == 99
    assert checked[4]["exact"] is False
    assert checked[4]["code_exact"] is True
    assert checked[4]["mismatch_class"] == "referenced-data mismatch"


def test_failed_compile_feedback_overrides_high_scoring_baseline():
    baseline = "int f(){return 1;}"
    broken = "int f(){return missing();}"
    fixed = "int f(){return 2;}"
    prompts = []

    def ask(model, prompt, context=None, options=None, details=False):
        prompts.append(prompt)
        return ("```cpp\n%s\n```" % (broken if len(prompts) == 1 else fixed), None, {})

    def check(client, addr, source, flags=None, **options):
        score = 99 if source == baseline else 75
        if "missing()" in source:
            raise match.CompileError("error C2065: missing")
        result = (score, "f", "byte diff", [])
        return result + ({},) if options.get("include_diagnosis") else result

    with patch.object(match, "target", return_value=(b"\xc3", [], {"size": 16, "unit": "x"})), \
         patch.object(match, "disasm", return_value=["ret "]), \
         patch.object(match, "check_text", side_effect=check), \
         patch.object(draft, "prompt_for", side_effect=lambda *args, **kw: repr(args[5])), \
         patch.object(draft, "_ask_context", side_effect=ask), \
         patch.object(repair, "repair_loop", return_value=(0, broken, None, "", [], [], "error C2065: missing")), \
         patch.object(mutate, "improve", return_value=mutate.ImproveResult(99, baseline, 0)):
        result = draft.llm_rounds("C", "00401000", "local", 2, start=(baseline, 99),
                                 provider_options={"near_repair": True}, log=lambda _: None)
    assert "error C2065: missing" in prompts[1]
    assert broken in prompts[1]
    assert baseline in prompts[0] and "99" in prompts[0]
    assert result[:2] == (99, baseline)


def test_explicit_diversity_still_starts_independent_candidates():
    baseline = "int f(){return 1;}"
    for diversity, near, expected in ((1, True, (baseline, 75, "byte diff")),
                                      (2, True, None), (1, False, None)):
        with patch.object(match, "target", return_value=(b"\xc3", [], {"size": 128, "unit": "x"})), \
             patch.object(match, "disasm", return_value=["ret "]), \
             patch.object(match, "check_text", side_effect=[(75, "f", "byte diff", []), (100, "f", "", [])]), \
             patch.object(draft, "prompt_for", return_value="p") as prompt, \
             patch.object(draft, "_ask_context", return_value=("int f(){return 2;}", None, {})):
            draft.llm_rounds("C", "00401000", "local", 1, start=(baseline, 75),
                             provider_options={"diverse_candidates": diversity, "near_repair": near},
                             log=lambda _: None)
        assert prompt.call_args.args[5] == expected


def test_repair_baseline_uses_measured_score_and_discards_compile_failure():
    baseline, generated = "int f(){return 1;}", "int f(){return 2;}"
    for measured, generated_score, expected, source in (
            (40, 10, 40, baseline), (40, 70, 70, generated), (None, 70, 70, generated)):
        def check(client, addr, text, flags=None, **options):
            if text == baseline and measured is None:
                raise match.CompileError("error C2065: invalid baseline")
            score = measured if text == baseline else generated_score
            result = (score, "f", "byte diff", [])
            return result + ({},) if options.get("include_diagnosis") else result

        with patch.object(match, "target", return_value=(b"\xc3", [], {"size": 16, "unit": "x"})), \
             patch.object(match, "disasm", return_value=["ret "]), \
             patch.object(match, "check_text", side_effect=check), \
             patch.object(draft, "prompt_for", return_value="p") as prompt, \
             patch.object(draft, "_ask_context", return_value=(generated, None, {})), \
             patch.object(draft, "_diagnose_note", return_value=""), \
             patch.object(mutate, "improve", return_value=mutate.ImproveResult(expected, source, 0)):
            result = draft.llm_rounds("C", "00401000", "local", 1,
                                      start=(baseline, 99), provider_options={"near_repair": True},
                                      log=lambda _: None)
        assert result[0] == expected and result[1].strip() == source
        assert prompt.call_args.args[5][1] == (measured or 0)


def test_generated_compiler_directives_cannot_override_client():
    generated = '// roc-cl: 99999\n// roc-flags: /Od\n// roc-lib: mfc-9.0 wrong.cpp\nint f(){return 1;}'
    with patch.object(match, "target", return_value=(b"\xc3", [], {"size": 16, "unit": "x"})), \
         patch.object(match, "disasm", return_value=["ret "]), \
         patch.object(match, "check_text", return_value=(100, "f", "", [])) as checked, \
         patch.object(draft, "prompt_for", return_value="p"), \
         patch.object(draft, "_ask_context", return_value=(generated, None, {})):
        draft.llm_rounds("C", "00401000", "local", 1, log=lambda _: None)
    assert "roc-" not in checked.call_args.args[2]
    assert "int f(){return 1;}" in checked.call_args.args[2]


@pytest.mark.parametrize("family,strict,rewrite,score", [
    (True, True, True, 100), (True, True, False, 100),
    (True, True, False, 99), (True, True, False, 0), (True, True, False, None),
    (True, False, False, 100), (False, False, False, 100)])
def test_example_cache_preserves_family_provenance(family, strict, rewrite, score):
    calls, cache = [], {}
    source = "int f(){return 1;}"

    class Api:
        server, token = "http://localhost:8765", None

        def call(self, path, data=None):
            calls.append((path, data))
            if path.startswith("/v1/examples"):
                if family and not strict and "&family=" in path:
                    return []
                return [{"addr": "donor", "source": source}]
            return {"stored": data["score"]} if path == "/v1/submit" else {}

    job = dict(client="C", addr="00401000", size=32, unit="U", score=0, source=None, lease="test")
    with patch.object(match, "target", return_value=(b"\xc3", [], job)), \
         patch.object(match, "_functions", return_value={job["addr"]: job}), \
         patch.object(match, "disasm", return_value=["ret "]), \
         patch.object(match, "check_text", return_value=(score, "f", "", []),
                      side_effect=match.CompileError("bad donor") if score is None else None), \
         patch.object(draft, "facts_from_asm", return_value={}), \
         patch.object(draft, "target_data_facts", return_value={}), \
         patch("roc.families.fingerprint", return_value="family"), \
         patch("roc.abi_graph.target_evidence", return_value={}), \
         patch.object(worker, "callee_source_hints", return_value=[]), \
         patch.object(metrics, "quarantined_keys", return_value=set()), \
         patch("roc.auto.candidates", return_value=[]), \
         patch("roc.auto.family_propagate", return_value=source if rewrite else None) as propagate, \
         patch("roc.refsource.compile_candidates", return_value=None), \
         patch("roc.refsource.prompt_hints", return_value=[]), \
         patch.object(draft, "llm_rounds", return_value=(0, None)) as llm:
        for _ in range(2):
            result = worker.work_one(Api(), "tester", job, {"clients": {"C": {}}}, "local", 2,
                                     False, lambda _: None, examples_cache=cache,
                                     provider_options={"family_exemplars": family})
            assert result == (score if strict and score else 0)
        assert propagate.call_count == (2 if strict else 0)
        assert llm.call_count == (0 if strict and score else 2)
        if llm.called:
            assert llm.call_args.kwargs["provider_options"]["family_exemplars"] == strict
    assert sum(path.startswith("/v1/examples") for path, _ in calls) == (2 if family and not strict else 1)
    assert sum(path == "/v1/submit" for path, _ in calls) == (2 if strict and score else 0)
