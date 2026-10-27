"""EXE copies of imported Ogre methods need EXE flags, not the DLL recipe."""
from types import SimpleNamespace
from pathlib import Path

from roc import libs, research


def unit(tmp_path, monkeypatch, text):
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    recipe = libs.RECIPES["ogre-1.4.5-dll"]
    folder = tmp_path / recipe["src"]
    folder.mkdir(parents=True)
    (folder / "method.cpp").write_text(text)
    return folder, recipe


def test_client_import_adds_exe_profiles_without_mutating_dll_recipe(tmp_path, monkeypatch):
    folder, recipe = unit(tmp_path, monkeypatch, "#undef OGRE_NONCLIENT_BUILD\n#include <Ogre.h>\n")
    original = list(recipe["grid"])
    flags = libs.compile_profiles("2008-06", "ogre-1.4.5-dll", "method.cpp")
    assert len(flags) == len(set(flags)) == 4
    assert all("/O2" in flag.split() for flag in flags[:2])
    assert flags[2:] == original == recipe["grid"]
    assert libs.compile_profiles("2009-06", "ogre-1.4.5-dll", "missing.cpp") == original
    (folder / "method.cpp").write_text('#include "OgreStableHeaders.h"\n')
    assert libs.compile_profiles("2008-06", "ogre-1.4.5-dll", "method.cpp") == original


def test_normal_automatic_library_compilation_uses_client_profiles(tmp_path, monkeypatch):
    folder, recipe = unit(tmp_path, monkeypatch, "#undef OGRE_NONCLIENT_BUILD\n")
    compiled = []
    monkeypatch.setattr(libs.match, "compile_text", lambda client, source, **kw:
                        compiled.append((source, kw["flags"])) or b"object")
    result = libs._compile_variants("2008-06", "ogre-1.4.5-dll", "method.cpp", "cpp", 21022, recipe)
    assert len(result) == 4
    assert "/O2" in compiled[0][1].split()
    assert all("ogre-1.4.5-dll method.cpp" in source for source, flags in compiled)


def test_research_inherits_profiles_but_preserves_explicit_overrides(tmp_path, monkeypatch):
    folder, recipe = unit(tmp_path, monkeypatch, "#undef OGRE_NONCLIENT_BUILD\n")
    monkeypatch.setattr(libs, "fetch", lambda name: folder)
    spec = {"recipe": "ogre-1.4.5-dll", "files": ["method.cpp"], "builds": [21022]}
    rows = list(research.recipe_sources([spec], client="2008-06"))
    assert len(rows) == 4 and "/O2" in rows[0][1]["flags"].split()
    explicit = list(research.recipe_sources([dict(spec, flags=["/O1"])], client="2008-06"))
    assert [row[1]["flags"] for row in explicit] == ["/O1"]


def test_fanout_requests_only_scores(monkeypatch):
    calls = []
    campaign = SimpleNamespace(
        api=SimpleNamespace(call=lambda path, **kw: calls.append(path) or []),
        previous=lambda stage: [], record=lambda *args: None)
    monkeypatch.setattr(research, "unresolved", lambda *args: None)
    assert research.fanout(campaign, "pilot", [], log=lambda line: None) == []
    assert calls == ["/v1/sources?scores=1&client=2008-06"]


def test_large_low_score_pool_excludes_near_matches_exact_stubs_and_data(monkeypatch):
    monkeypatch.setattr(research.fingerprint, "Target", lambda client: SimpleNamespace(index={}))
    rows = {"open": {"kind": "code", "size": 4000},
            "partial": {"kind": "code", "size": 5000},
            "near": {"kind": "code", "size": 6000},
            "exact": {"kind": "code", "size": 7000},
            "small": {"kind": "code", "size": 100},
            "data": {"kind": "data", "size": 4096},
            "catch": {"kind": "eh", "size": 4000}}
    monkeypatch.setattr(research.match, "_functions", lambda client: rows)
    target = research.unresolved("2008-06", {"partial": 39, "near": 40, "exact": 100},
                                 {"sizes": [3476, 1000000], "scores": [0, 39]})
    assert dict(target.index) == {4000: ["open"], 5000: ["partial"]}


def test_recovered_units_outside_vendor_glob_are_auto_discovered(tmp_path, monkeypatch):
    (tmp_path / "vendor").mkdir()
    (tmp_path / "vendor/stock.cpp").write_text("void stock() {}")
    (tmp_path / "roc_recovered.cpp").write_text("void recovered() {}")
    monkeypatch.setattr(libs, "generated_units", lambda: {"library": {
        "roc_recovered.cpp": "code", "missing.cpp": "code", "unused.h": "header"}})
    recipe = {"src": "library", "files": "vendor/*.cpp"}
    assert libs.files_of(recipe, tmp_path) == [str(Path("vendor/stock.cpp"))]
    assert libs.matching_files(recipe, tmp_path) == ["roc_recovered.cpp", "vendor/stock.cpp"]


def test_research_generated_discovery_keeps_explicit_file_selection(tmp_path, monkeypatch):
    (tmp_path / "stock.cpp").write_text("void stock() {}")
    (tmp_path / "roc_recovered.cpp").write_text("void recovered() {}")
    monkeypatch.setattr(libs, "fetch", lambda name: tmp_path)
    monkeypatch.setattr(libs, "generated_units", lambda: {"library": {"roc_recovered.cpp": "code"}})
    monkeypatch.setitem(libs.RECIPES, "discovery-test", {
        "src": "library", "files": ["stock.cpp"], "langs": ["cpp"], "builds": [21022], "grid": ["/O2"]})
    spec = {"recipe": "discovery-test", "generated": True, "match": "^roc_"}
    assert [row[1]["file"] for row in research.recipe_sources([spec], "2008-06")] == ["roc_recovered.cpp"]
    explicit = dict(spec, files=["stock.cpp"], match="stock")
    assert [row[1]["file"] for row in research.recipe_sources([explicit], "2008-06")] == ["stock.cpp"]


def test_inherited_tree_erase_is_generated_and_gets_scoped_unoptimized_gate(monkeypatch):
    name = "templates-boost-1_34_1"
    recipe = libs.RECIPES[name]
    original = list(recipe["grid"])
    sources = libs.template_units()
    assert "return tree.erase(position);" in sources["tree_erase_map_int.cpp"]
    assert sources["tree_erase_map_int.cpp"].startswith("#define _DLL\n")
    assert libs.compile_profiles("2008-06", name, "tree_erase_map_int.cpp") == [
        "/Od /Ob0 /GS /EHsc /MD", *original]
    assert libs.compile_profiles("2009-06", name, "tree_erase_map_int.cpp") == original
    assert libs.compile_profiles("2008-06", name, "map_int_int.cpp") == original
    assert recipe["grid"] == original


def test_imported_sky_gets_x87_fast_gate_without_changing_other_sources():
    name = "rbxgs-g3d-dll"
    recipe = libs.RECIPES[name]
    original = list(recipe["grid"])
    assert "_DLL" in recipe["defines"].split()
    assert libs.compile_profiles("2008-06", name, "GLG3Dcpp/Sky.cpp") == [
        "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast", *original]
    assert libs.compile_profiles("2008-06", name, "GLG3Dcpp\\Draw.cpp") == [
        "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast", *original]
    assert libs.compile_profiles("2008-06", name, "GLG3Dcpp/ToneMap.cpp") == [
        "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast", *original]
    assert libs.compile_profiles("2009-06", name, "GLG3Dcpp/Sky.cpp") == original
    assert libs.compile_profiles("2008-06", name, "GLG3Dcpp/Texture.cpp") == original
    assert libs.compile_profiles("2008-06", "rbxgs-g3d", "GLG3Dcpp/Sky.cpp") == original
    assert recipe["grid"] == original


def test_verified_native_handles_reaches_fast_profile_before_four_losing_gates():
    name = "rbxgs-dll"
    file = "roc_handles3d_410275e979a30584.cpp"
    original = list(libs.RECIPES[name]["grid"])
    flags = libs.compile_profiles("2008-06", name, file)
    assert flags[0] == "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast"
    assert len(flags) == len(set(flags))
    assert set(flags) == set(original)
    assert libs.compile_profiles("2009-06", name, file) == original
    assert libs.compile_profiles("2008-06", name, "other.cpp") == original
    assert libs.RECIPES[name]["grid"] == original
