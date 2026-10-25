from roc import mutsearch


def edits(src):
    return {text.rsplit(")\n{", 1)[1].strip().rstrip("}").strip() for _, text in mutsearch.variants(src)}


def body(code):
    return "struct S { float a, b, c; int n; };\nfloat f(S* s, float x)\n{\n%s\n}\n" % code


def test_commutes_only_where_the_parse_survives():
    out = edits(body("    return x - s->a + s->b;"))
    assert "return x - s->b + s->a;" not in out
    out = edits(body("    return s->a + s->b * x;"))
    assert "return s->a + x * s->b;" in out
    assert "return s->b * x + s->a;" in out
    assert "return s->b + s->a * x;" not in out


def test_regroups_chains():
    out = edits(body("    return s->a + s->b + s->c;"))
    assert "return s->a + (s->b + s->c);" in out
    assert "return (s->a + s->b) + s->c;" in out


def test_swaps_independent_statements_only():
    out = edits(body("    s->a = x;\n    s->b = x * 2;\n    s->c = s->a;\n    return 0;"))
    assert any(e.startswith("s->b = x * 2;\n    s->a = x;") for e in out)
    out = edits(body("    s->a = x;\n    s->c = s->a;\n    return 0;"))
    assert not any(e.index("s->c = s->a") < e.index("s->a = x") for e in out)


def test_compound_round_trip_and_declarations_untouched():
    out = edits(body("    s->n = s->n + 3;\n    return 0;"))
    assert "s->n += 3;\n    return 0;" in out
    src = "struct T { int* p; };\nint g(T& t)\n{\n    int * q;\n    q = t.p;\n    return *q;\n}\n"
    assert not any("q * int" in text for _, text in mutsearch.variants(src))


def test_struct_member_order_is_never_touched():
    src = "struct V { float x;\n    float y; };\nvoid f(V* v)\n{\n    float a;\n    float b;\n    a = v->x;\n    b = v->y;\n    v->x = a + b;\n}\n"
    for _, text in mutsearch.variants(src):
        assert text.startswith("struct V { float x;\n    float y; };")


def test_regroups_whole_product_terms_of_a_sum():
    out = edits(body("    return s->a * s->a + s->b * s->b + s->c * s->c;"))
    assert "return s->a * s->a + (s->b * s->b + s->c * s->c);" in out


def test_inlines_a_single_use_local_unless_an_operand_changes():
    out = edits(body("    float t = s->a * x;\n    s->b = t + s->c;\n    return 0;"))
    assert "s->b = (s->a * x) + s->c;\n    return 0;" in out
    out = edits(body("    float t = s->a * x;\n    s->a = 1;\n    s->b = t;\n    return 0;"))
    assert not any("s->b = (s->a * x)" in e for e in out)


def test_gates_toggle_fp_fast_and_precise_off_on_the_unit():
    stub = "// roc-flags: /O2 /MD\n// roc-lib: r a.cpp\n"
    names = {name: state for name, state in mutsearch.gates(stub, "int f();\n")}
    assert names["toggle /fp:fast"][0].startswith("// roc-flags: /O2 /MD /fp:fast")
    assert names["toggle float_control"][1].startswith("#pragma float_control(precise,off,push)")


def test_search_mutates_the_unit_and_keeps_the_stub(monkeypatch):
    stub = "// roc-flags: /O2\n// roc-lib: r a.cpp\n"
    unit = "float f(float a, float b)\n{\n    return a * b;\n}\n"
    monkeypatch.setattr(mutsearch, "unit_of", lambda source: ("r", "a.cpp", None, unit))
    want = "return b * a;"
    check = lambda state: ((100, 100.0, "") if want in state[1] else (90, 90.0, ""))
    best = mutsearch.search("c", "00000000", stub, budget=20, jobs=1, check=check)
    assert best["score"] == 100 and best["source"] == stub and want in best["unit"]
    assert best["start"] == 90 and best["path"] == ["commute *"]
