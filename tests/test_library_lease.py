from roc.server import Store


def test_lease_filters_by_library_and_allows_shared_work():
    st = Store(":memory:", lease_seconds=60)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                      [("C", "00401000", 8, "RakPeer"), ("C", "00401010", 8, "CXTPCommandBar")])
    assert st.lease("u", "w1", ["C"], "ai", 256, library="RakNet")["addr"] == "00401000"
    assert st.lease("u", "w2", ["C"], "ai", 256, library="RakNet")["addr"] == "00401000"
    assert st.lease("u", "w3", ["C"], "ai", 256, library="XTP (Codejock)")["addr"] == "00401010"


def test_units_upload_is_validated_and_stored(tmp_path, monkeypatch):
    from roc import libs
    monkeypatch.setattr(libs, "ROOT", tmp_path)
    monkeypatch.setattr(libs, "UNITS_FILE", tmp_path / "units.json")
    src = next(r["src"] for r in libs.RECIPES.values() if r.get("src") and not r.get("generate"))
    assert libs.accept_units({src: {"roc_fork_x.cpp": "int a;"}}) == 1
    assert libs.accept_units({src: {"roc_fork_x.cpp": "int a;"}}) == 0
    for bad in ({"nope": {"roc_a.cpp": "x"}}, {src: {"../roc_a.cpp": "x"}}, {src: {"evil.cpp": "x"}}):
        try:
            libs.accept_units(bad)
        except ValueError:
            continue
        raise AssertionError("accepted %r" % bad)
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    recipe = next(n for n, r in libs.RECIPES.items() if r.get("src") == src)
    assert libs.units_used("// roc-lib: %s roc_fork_x.cpp\nint f(){}" % recipe) == {src: {"roc_fork_x.cpp": "int a;"}}
    assert libs.units_used("// roc-lib: %s vendor.cpp\n" % recipe) == {}


def test_on_disk_units_named_by_sources_are_captured(tmp_path, monkeypatch):
    from roc import libs
    monkeypatch.setattr(libs, "ROOT", tmp_path)
    monkeypatch.setattr(libs, "UNITS_FILE", tmp_path / "units.json")
    monkeypatch.setattr(libs, "LIBS", tmp_path)
    recipe, r = next((n, r) for n, r in libs.RECIPES.items() if r.get("src") and not r.get("generate"))
    tree = libs._case_path(tmp_path / r["src"])
    tree.mkdir(parents=True, exist_ok=True)
    (tree / "roc_disk_only.cpp").write_text("int b;")
    source = "// roc-lib: %s roc_disk_only.cpp\nint f(){}" % recipe
    assert libs.capture_source_units([source, source, "int g;"]) == {r["src"]: ["roc_disk_only.cpp"]}
    assert libs.generated_units() == {r["src"]: {"roc_disk_only.cpp": "int b;"}}
    assert libs.capture_source_units([source]) == {}


def test_bundled_native_units_install_without_local_cache(tmp_path, monkeypatch):
    import json
    from roc import libs
    monkeypatch.setattr(libs, 'ROOT', tmp_path)
    monkeypatch.setattr(libs, 'LIBS', tmp_path / 'tools/libs')
    monkeypatch.setattr(libs, 'UNITS_FILE', tmp_path / 'local/units/generated-units.json')
    monkeypatch.setitem(libs.RECIPES, 'native-fixture', {'src': 'native-fixture'})
    bundle = tmp_path / 'research/native-units.json'
    bundle.parent.mkdir()
    bundle.write_text(json.dumps({'native-fixture': {'roc_header.cpp': 'class NativeHeader {};'}}))
    folder = libs.LIBS / 'native-fixture'
    folder.mkdir(parents=True)
    assert libs.fetch('native-fixture') == folder
    assert (folder / 'roc_header.cpp').read_text() == 'class NativeHeader {};'
    assert not libs.UNITS_FILE.exists()
    libs.UNITS_FILE.parent.mkdir(parents=True)
    libs.UNITS_FILE.write_text(json.dumps({'native-fixture': {'roc_local.cpp': 'local work'}}))
    assert libs.generated_units()['native-fixture'] == {'roc_header.cpp': 'class NativeHeader {};', 'roc_local.cpp': 'local work'}


def test_source_install_uses_locked_revision_and_preserves_existing_tree(tmp_path, monkeypatch):
    import json
    import shutil
    import subprocess
    import pytest
    from roc import libs
    if not shutil.which('git'):
        pytest.skip('Git required')
    def git(folder, *args):
        return subprocess.check_output(['git', *args], cwd=folder, text=True).strip()
    seed = tmp_path / 'seed'
    seed.mkdir()
    git(seed, 'init', '-b', 'main')
    git(seed, 'config', 'user.email', 'test@example.invalid')
    git(seed, 'config', 'user.name', 'Test')
    (seed / 'source.h').write_text('pinned source')
    git(seed, 'add', '.')
    git(seed, 'commit', '-m', 'first')
    pinned = git(seed, 'rev-parse', 'HEAD')
    (seed / 'source.h').write_text('new upstream source')
    git(seed, 'commit', '-am', 'second')
    root = tmp_path / 'worker'
    (root / 'research').mkdir(parents=True)
    (root / 'research/native-source-lock.json').write_text(json.dumps({str(seed): pinned}))
    monkeypatch.setattr(libs, 'ROOT', root)
    target = root / 'tools/vendor'
    libs._clone_source(str(seed), target)
    assert git(target, 'rev-parse', 'HEAD') == pinned
    assert (target / 'source.h').read_text() == 'pinned source'
    (target / 'source.h').write_text('unsent local edit')
    libs._clone_source(str(seed), target)
    assert (target / 'source.h').read_text() == 'unsent local edit'
    with pytest.raises(SystemExit, match='inside tools'):
        libs._clone_source(str(seed), tmp_path / 'outside')
