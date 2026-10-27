import json
from types import SimpleNamespace

from roc import native_sweep, providers


def test_model_proposal_feeds_back_until_new_exact_without_loss(tmp_path, monkeypatch):
    replies = iter([
        'not json',
        json.dumps({"edits": [["return 1;", "return 2;"]]}),   # compiles, loses owned 00000002
        json.dumps({"edits": [["return 1;", "return 3;"]]}),   # new exact 00000001, no loss
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
