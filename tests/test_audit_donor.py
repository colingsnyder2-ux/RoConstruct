import json

from roc import analyze, matchers, fingerprint, match, worker


def test_exact_matches_replace_stale_partial_files(tmp_path, monkeypatch):
    for module in (fingerprint, match, worker):
        monkeypatch.setattr(module, "ROOT", tmp_path)
    monkeypatch.setattr(match, "template", lambda client, addr: "// roc c %s\n\nstub" % addr)
    src = tmp_path / "src" / "c"
    src.mkdir(parents=True)
    (tmp_path / "work" / "c").mkdir(parents=True)
    (src / "00401000.cpp").write_text("// from server: 86% by a\nold")
    (src / "00402000.cpp").write_text("// from server: 40% by a\nold")
    (src / "00403000.cpp").write_text("// my local edit\nmine")
    fingerprint.save("c", {"00401000": ("exact", "sym", [])}, "library x")
    assert "exact" in (src / "00401000.cpp").read_text()

    class Api:
        def __init__(self, server, token):
            pass

        def close(self):
            pass

        def call(self, path, timeout=None):
            return [{"addr": a, "score": 100, "user": "b", "source": "// roc\nnew"}
                    for a in ("00402000", "00403000", "00402010")]
    monkeypatch.setattr(worker, "Api", Api)
    (tmp_path / "work" / "c" / "functions.jsonl").write_text(
        "".join('{"addr": "%s"}\n' % a for a in ("00402000", "00403000")))
    worker.pull_files("s", "c", log=lambda *a: None)
    assert (src / "00402000.cpp").read_text() == "// from server: 100% by b\n// roc\nnew"
    assert (src / "00403000.cpp").read_text() == "// my local edit\nmine"
    assert not (src / "00402010.cpp").exists()  # retired by a boundary fix


def test_remote_score_hint_cannot_credit_a_kept_local_partial_on_startup(tmp_path, monkeypatch):
    from roc import server
    for module in (match, worker, server):
        monkeypatch.setattr(module, "ROOT", tmp_path)
    work = tmp_path / "work/c"
    source_dir = tmp_path / "src/c"
    work.mkdir(parents=True)
    source_dir.mkdir(parents=True)
    (work / "functions.jsonl").write_text('{"addr":"00401000","size":6,"kind":"code"}\n')
    local = "// roc-lib: vendor local.cpp\n"
    path = source_dir / "00401000.cpp"
    path.write_text(local)
    class Api:
        def __init__(self, *args):
            pass
        def close(self):
            pass
        def call(self, *args, **kwargs):
            return [dict(addr="00401000", score=100, user="remote", source="// roc-lib: vendor exact.cpp\n")]
    monkeypatch.setattr(worker, "Api", Api)
    monkeypatch.setattr(match, "function_starts", lambda client: {"00401000"})
    worker.pull_files("server", "c", log=lambda *args: None)
    assert path.read_text() == local  # Keep the user's local attempt.
    assert json.loads((work / "scores.json").read_text())["00401000"] == 100
    store = server.Store(":memory:", lease_seconds=1)
    store.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('c','00401000',6,'A')")
    store.db.commit()
    monkeypatch.setattr(server.clients, "load", lambda: {"c": {}})
    monkeypatch.setattr(matchers, "solve", lambda *args, **kwargs: {})
    checked = []
    def check(client, addr, text):
        checked.append(text)
        return 97, "f", "", []
    monkeypatch.setattr(match, "check_text", check)
    server.import_startup_matches(store, {"c"}, log=lambda *args: None)
    assert checked == [local]
    assert store.best("c", "00401000")["score"] == 0


def test_lint_flags_bad_files_and_overlaps(tmp_path, monkeypatch):
    monkeypatch.setattr(analyze, "ROOT", tmp_path)
    src = tmp_path / "src" / "c"
    src.mkdir(parents=True)
    (src / "00401000.cpp").write_text("// roc-cl: 21022\n// roc-lib: nosuch a.cpp\n")
    (src / "00409999.cpp").write_text("int f;\n")
    (src / "readme.cpp").write_text("")
    work = tmp_path / "work" / "c"
    work.mkdir(parents=True)
    (work / "scores.json").write_text(json.dumps({"00401010": 100}))
    (work / "data.json").write_text(json.dumps({"00401000": [[0x500000, 4], [0x500002, 4]]}))
    (work / "meta.json").write_text(json.dumps({"data_bytes": 60}))
    rows = {"00401000": {"addr": "00401000", "size": 0x20}, "00401010": {"addr": "00401010", "size": 4}}
    monkeypatch.setattr(match, "_functions", lambda client: rows)
    problems = analyze.lint("c", log=lambda *a: None)
    kinds = {k: v for k, v in problems.items()}
    assert kinds["error: roc-lib names an unknown recipe"] == ["00401000.cpp (nosuch)"]
    assert kinds["error: no function starts at this address"] == ["00409999.cpp"]
    assert kinds["error: file name is not an 8-digit lowercase address"] == ["readme.cpp"]
    assert kinds["error: function bodies overlap (roadmap)"] == ["00401000+32 > 00401010"]
    assert "00401010" in kinds["warning: scored 100 but no source file here (pull from the server)"]
    assert analyze.data_coverage("c").startswith("6 of 60 bytes")  # overlapping spans count once


def test_donor_reads_openrbx_csvs_and_markers(tmp_path):
    csvs = tmp_path / "reccmp"
    csvs.mkdir()
    (csvs / "webservice-stl.csv").write_text("address,size,type,symbol,name\n0x10001740,0x5,library,??1vec@@QAE@XZ,\n")
    (csvs / "webservice-globals.csv").write_text("address,type,symbol\n0x10227000,global,__imp__X@4\n")
    (csvs / "webservice-lua.csv").write_text("address,type,name\n0x100a8b60,library,luaA_pushobject\n")
    code = tmp_path / "Client" / "a.cpp"
    code.parent.mkdir()
    code.write_text("// FUNCTION: WEBSERVICE 0x10001000\nint f() { return 1; }\n// GLOBAL: WEBSERVICE 0x10300000\n")
    assert matchers.names(csvs) == {0x10001740: ("stl", "??1vec@@QAE@XZ"), 0x100a8b60: ("lua", "luaA_pushobject")}
    assert matchers.annotations(tmp_path) == {0x10001000: "Client/a.cpp:1"}
