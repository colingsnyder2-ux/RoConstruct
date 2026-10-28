from types import SimpleNamespace

from roc import native_sweep, providers


def block(old, new):
    return "<<<<<<< SEARCH\n%s\n=======\n%s\n>>>>>>> REPLACE\n" % (old, new)


def test_minimizer_keeps_called_helper_definition_but_drops_unused_helper(tmp_path):
    def compile_round(source, label):
        obj = tmp_path / (label + '.obj')
        obj.write_text(source)
        return {'ok': True, 'object': str(obj),
                'undefined_symbols': ['helper'] if 'call_helper' in source and 'define_helper' not in source else []}
    matcher = SimpleNamespace(scan=lambda data: [{'addr': '00000001'}] if b'call_helper' in data else [])
    edits = [['CALL', 'call_helper'], ['BODY', 'define_helper'], ['UNUSED', 'define_unused']]
    proposal = native_sweep.minimize('A.cpp', 'CALL BODY UNUSED', edits, {'00000001'}, set(),
                                      compile_round, matcher, 'helper', definitions={'helper', 'unused'})
    assert proposal['edits'] == edits[:2]


def test_model_proposal_feeds_back_until_new_exact_without_loss(tmp_path, monkeypatch):
    replies = iter([
        'not a block',
        block("return 1;", "return 2;"),   # compiles, loses owned 00000002
        "Fix:\r\n" + block("return 1;", "return 3;").replace("\n", "\r\n"),   # new exact 00000001, no loss
    ])
    seen = []
    monkeypatch.setattr(providers, "generate",
                        lambda model, messages, options: (seen.append(messages[-1]["content"]), SimpleNamespace(text=next(replies)))[1])
    hits = {"return 2;": [], "return 3;": ["00000001", "00000002"]}

    def compile_round(source, label):
        obj = tmp_path / (label + ".obj")
        obj.write_text(source)
        return {"ok": True, "object": str(obj), "mode": label, "error": None}

    matcher = SimpleNamespace(scan=lambda data: [{"addr": a, "symbol": "?f@A@@QAEHXZ"}
                                                 for key, addrs in hits.items() if key.encode() in data for a in addrs])
    proposal, trials = native_sweep.model_proposal(
        "App/v8datamodel/A.cpp", "int A::f() { return 1; }", ["00000001"], {"00000002"}, {"00000002"},
        "deepseek:x", 3, compile_round, matcher, lambda addr: {"addr": addr}, lambda *a: None)
    assert proposal["edits"] == [["return 1;", "return 3;"]]
    assert [w["addr"] for w in proposal["witnesses"]] == ["00000001"]
    assert "Rejected" in seen[1] and "Lost previously exact: ['00000002']" in seen[2]
    assert len(trials) == 3


def test_apply_edits_requires_unique_anchor():
    assert native_sweep.apply_edits("a b a", [["b", "c"]]) == "a c a"
    for bad in ([["a", "x"]], [["z", "x"]], [], [["", "x"]]):
        try:
            native_sweep.apply_edits("a b a", bad)
        except ValueError:
            continue
        raise AssertionError(bad)


def test_model_proposal_keeps_only_edits_the_new_exact_needs(tmp_path, monkeypatch):
    reply = block("return 1;", "return 3;") + block("int g()", "int g2()") + block("int h()", "int h()")
    monkeypatch.setattr(providers, "generate", lambda model, messages, options: SimpleNamespace(text=reply))

    def compile_round(source, label):
        obj = tmp_path / (label + ".obj")
        obj.write_text(source)
        return {"ok": True, "object": str(obj), "mode": label, "error": None}

    matcher = SimpleNamespace(scan=lambda data: [{"addr": "00000001", "symbol": "?f@A@@QAEHXZ"}] if b"return 3;" in data else [])
    proposal, _ = native_sweep.model_proposal(
        "App/v8datamodel/A.cpp", "int A::f() { return 1; } int g() {} int h() {}", ["00000001"], set(), set(),
        "deepseek:x", 1, compile_round, matcher, lambda addr: {"addr": addr}, lambda *a: None)
    assert proposal["edits"] == [["return 1;", "return 3;"]]
