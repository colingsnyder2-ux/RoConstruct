import json

from roc import rebuild


def test_failed_layer_invalidates_stale_success_without_linking(tmp_path, monkeypatch):
    source = tmp_path / "sources"
    source.mkdir()
    (source / "bad.cpp").write_text("not valid C++")
    out = tmp_path / "out" / "Example"
    out.mkdir(parents=True)
    previous = {"module": "Example", "linked": True, "test_exit": 0,
                "owned_addrs": ["00401000"]}
    (out / "report.json").write_text(json.dumps(previous))
    (out / "owned-symbols.json").write_text(json.dumps({"00401000": []}))
    spec = {"name": "Example", "test": "fixture", "layers": [
        {"name": "upstream", "mode": "direct", "dir": "sources",
         "files": "*.cpp", "flags": "/O2"}]}
    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    monkeypatch.setattr(rebuild, "load_module", lambda client, name: spec)
    monkeypatch.setattr(rebuild, "build_overlay", lambda *args: None)
    monkeypatch.setattr(rebuild, "compile_direct", lambda *args, **kwargs: {
        str(source / "bad.cpp"): (False, "compile failed")})

    def unexpected_link(*args, **kwargs):
        raise AssertionError("failed module must not link")

    monkeypatch.setattr(rebuild, "resolve_objects", unexpected_link)
    result = rebuild.build_module("2008-06", "example", log=lambda message: None)
    assert result["linked"] is False
    assert result["compile_errors"] == {"upstream": {"bad.cpp": "compile failed"}}
    assert result["owned_addrs"] == []
    assert json.loads((out / "report-before-compile-failure.json").read_text()) == previous
    assert json.loads((out / "owned-symbols-before-compile-failure.json").read_text()) == {"00401000": []}
    assert json.loads((out / "owned-symbols.json").read_text()) == {}


def test_dependency_readiness_requires_clean_layers(tmp_path):
    spec = {"layers": [{"name": "one"}]}
    (tmp_path / "linked").mkdir()
    (tmp_path / "linked" / "linked.lib").write_bytes(b"library")
    (tmp_path / "report.json").write_text('{"linked": true, "test_exit": 0}')
    layer = tmp_path / "layer-one"
    layer.mkdir()
    assert not rebuild._module_ready(tmp_path, spec)
    (layer / "errors.json").write_text('{"bad.cpp": "failed"}')
    assert not rebuild._module_ready(tmp_path, spec)
    (layer / "errors.json").write_text("{}")
    assert rebuild._module_ready(tmp_path, spec)


def test_missing_direct_sources_invalidate_previous_report(tmp_path, monkeypatch):
    out = tmp_path / "out" / "Example"
    out.mkdir(parents=True)
    (out / "report.json").write_text('{"linked": true, "test_exit": 0}')
    spec = {"name": "Example", "test": "fixture", "layers": [
        {"name": "upstream", "mode": "direct", "dir": "missing",
         "files": "*.cpp", "flags": "/O2"}]}
    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    monkeypatch.setattr(rebuild, "load_module", lambda client, name: spec)
    monkeypatch.setattr(rebuild, "build_overlay", lambda *args: None)
    result = rebuild.build_module("2008-06", "example", log=lambda message: None)
    assert result["linked"] is False
    assert "<sources>" in result["compile_errors"]["upstream"]
    assert json.loads((out / "report.json").read_text())["linked"] is False


def test_failed_dependency_invalidates_parent_even_with_stale_library(tmp_path, monkeypatch):
    for name in ("parent", "dependency"):
        directory = tmp_path / name
        directory.mkdir()
        (directory / "unit.cpp").write_text("source")
    dependency = tmp_path / "out" / "Dependency"
    (dependency / "linked").mkdir(parents=True)
    (dependency / "linked" / "linked.lib").write_bytes(b"stale")
    (dependency / "report.json").write_text('{"linked": true, "test_exit": 0}')
    parent = tmp_path / "out" / "Parent"
    parent.mkdir()
    (parent / "report.json").write_text('{"linked": true, "test_exit": 0}')

    def spec(name):
        result = {"name": name.title(), "test": "fixture", "layers": [
            {"name": "upstream", "mode": "direct", "dir": name,
             "files": "*.cpp", "flags": "/O2"}]}
        if name == "parent":
            result["depends"] = ["dependency"]
        return result

    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    monkeypatch.setattr(rebuild, "load_module", lambda client, name: spec(name))
    monkeypatch.setattr(rebuild, "build_overlay", lambda *args: None)
    monkeypatch.setattr(rebuild, "compile_direct", lambda client, sources, *args, **kwargs: {
        str(sources[0]): (sources[0].parent.name == "parent", "compile failed")})
    result = rebuild.build_module("2008-06", "parent", log=lambda message: None)
    assert result["linked"] is False
    assert result["dependency_errors"] == {"dependency": "dependency build failed"}
    assert json.loads((parent / "report.json").read_text())["linked"] is False
    assert json.loads((dependency / "report.json").read_text())["linked"] is False


def test_runtime_conflict_invalidates_prior_success(tmp_path, monkeypatch):
    out = tmp_path / "out" / "Example"
    out.mkdir(parents=True)
    (out / "report.json").write_text('{"linked": true, "test_exit": 0}')
    spec = {"name": "Example", "test": "fixture", "layers": []}
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    monkeypatch.setattr(rebuild, "load_module", lambda client, name: spec)
    monkeypatch.setattr(rebuild, "build_overlay", lambda *args: None)

    def conflict(*args):
        raise ValueError("Conflicting runtime files: SDL.dll")

    monkeypatch.setattr(rebuild, "_link_support", conflict)
    result = rebuild.build_module("2008-06", "example", log=lambda message: None)
    assert result["linked"] is False
    assert "SDL.dll" in result["dependency_errors"]["runtime"]
    assert json.loads((out / "report.json").read_text())["linked"] is False


def test_progress_excludes_stale_link_with_failed_source_layer(tmp_path, monkeypatch):
    module = tmp_path / "rebuild/2008-06/modules/example.json"
    module.parent.mkdir(parents=True)
    module.write_text(json.dumps({"name": "Example", "layers": [{"name": "upstream"}]}))
    out = tmp_path / "rebuild/2008-06/out/Example"
    (out / "linked").mkdir(parents=True)
    (out / "linked/linked.lib").write_bytes(b"stale")
    (out / "linked/old.obj").write_bytes(b"old")
    (out / "layer-upstream").mkdir()
    (out / "layer-upstream/errors.json").write_text('{"bad.cpp":"compile failed"}')
    (out / "report.json").write_text(json.dumps({"linked": True, "test_exit": 0,
        "owned_2008": 99, "object_functions": 100, "unresolved": []}))
    (tmp_path / "docs").mkdir()
    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "DOCS", tmp_path / "docs")
    monkeypatch.setattr(rebuild.match, "coff_functions", lambda data: (_ for _ in ()).throw(
        AssertionError("stale object must not be scanned")))
    result = rebuild.progress(log=lambda message: None, notify=False)
    assert result["modules"][0]["linked"] is False
    assert result["modules"][0]["exact"] == 0
    assert result["bars"]["exact"]["value"] == 0
