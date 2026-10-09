"""Regressions observed while running real bounded worker batches."""
import json
from concurrent.futures import ThreadPoolExecutor
from unittest.mock import patch

from roc import draft, match, metrics, mutate, repair


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
        result = draft.llm_rounds("C", "00401000", "local", 2, start=(baseline, 99), log=lambda _: None)
    assert "error C2065: missing" in prompts[1]
    assert broken in prompts[1]
    assert result[:2] == (99, baseline)


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
