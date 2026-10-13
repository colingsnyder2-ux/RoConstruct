from roc.server import Store


def test_lease_filters_by_library_and_allows_shared_work():
    st = Store(":memory:", lease_seconds=60)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                      [("C", "00401000", 8, "RakPeer"), ("C", "00401010", 8, "CXTPCommandBar")])
    assert st.lease("u", "w1", ["C"], "ai", 256, library="RakNet")["addr"] == "00401000"
    assert st.lease("u", "w2", ["C"], "ai", 256, library="RakNet")["addr"] == "00401000"
    assert st.lease("u", "w3", ["C"], "ai", 256)["addr"] == "00401010"


def test_units_upload_is_validated_and_stored(tmp_path, monkeypatch):
    from roc import libs
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
