import hashlib
from types import SimpleNamespace

from roc import native_sweep as sweep


def test_no_applicable_edit_skips_baseline_compile(tmp_path, monkeypatch):
    tree = tmp_path / "tree"
    source = tree / "App/Noop.cpp"
    source.parent.mkdir(parents=True)
    source.write_text("void A::noop() {}\n")
    generator = tmp_path / "rebuild/2008-06/patches/make_rbxgs_client.py"
    generator.parent.mkdir(parents=True)
    generator.write_text("# baseline\n")
    generator.with_name("rbxgs-client.json").write_text("{}")
    base = {"generator": hashlib.sha256(generator.read_bytes()).hexdigest(),
            "overlay": {}, "revision": "baseline"}
    calls = []

    class Api:
        def call(self, path, body=None):
            calls.append(path)
            return base if path.endswith("/base") else {"jobs": []}

        def close(self):
            pass

    def unexpected_compile(*args, **kwargs):
        raise AssertionError("Unchanged source must not compile")

    monkeypatch.setattr(sweep, "ROOT", tmp_path)
    monkeypatch.setattr(sweep.worker, "load_settings", lambda: {"user": "tester", "server": "http://test"})
    monkeypatch.setattr(sweep.worker, "Api", lambda *args: Api())
    monkeypatch.setattr(sweep.integration, "native_token", lambda: None)
    monkeypatch.setattr(sweep.rebuild, "toolchain", lambda: {})
    monkeypatch.setattr(sweep, "native_context", lambda *args: SimpleNamespace(
        tree=tree, overlay=tmp_path / "overlay", includes=[], defines="", flags="",
        by_addr={}, owned=set(), targets=set(), matcher=None, names={}, integrated=set()))
    monkeypatch.setattr(sweep, "compile_unit", unexpected_compile)
    result = sweep.run({"native_sweep": {"files": ["App/*.cpp"], "modes": ["nonempty"],
                                        "apply": False, "submit": False}}, "noop", log=lambda _: None)
    assert result["tried"] == 0 and result["proposed_files"] == 0
    assert result["state"] == "no-proposals"
    assert not any(path.endswith("/claim") for path in calls)
