import json
from pathlib import Path
from unittest.mock import patch

from roc import progress
from roc.server import Store, export


def test_live_snapshot_matches_digest_and_keeps_zero_scores():
    store = Store(":memory:", 7200)
    store.db.executemany("INSERT INTO funcs(client,addr,size,unit,score,source) VALUES(?,?,?,?,?,?)", [
        ("C", "00001000", 10, "U", 50, "candidate"),
        ("C", "00001010", 20, "U", 100, "// roc-lib: lib unit.cpp"),
        ("C", "00001020", 30, "U", 0, None),
        ("other", "00001000", 1, "U", 100, "candidate")])
    snapshot = store.progress_snapshot("C")
    stats = next(row for row in snapshot["clients"] if row["name"] == "C")
    assert (stats["matched"], stats["functions"], stats["matched_bytes"], stats["bytes"]) == store.display_progress("C")
    assert (stats["partial"], stats["partial_bytes"]) == (1, 10)
    assert snapshot["scores"] == {"00001000": 50, "00001010": 100, "00001020": 0}
    assert snapshot["functions"][0] == ("00001000", 10, 50, "U", 1)
    assert store.progress_snapshot()["scores"] is None
    store.db.close()


def test_published_server_scores_override_stale_local_exacts(tmp_path):
    work = tmp_path / "work/C"
    work.mkdir(parents=True)
    (work / "functions.jsonl").write_text("\n".join(json.dumps(dict(addr=a, size=10, unit="U"))
        for a in ("00001000", "00001010")))
    (work / "scores.json").write_text(json.dumps({"00001000": 100, "00001010": 100}))
    store = Store(":memory:", 7200)
    store.db.executemany("INSERT INTO funcs(client,addr,size,unit,score) VALUES(?,?,?,?,?)",
                        [("C", "00001000", 10, "U", 50), ("C", "00001010", 10, "U", 0)])
    docs = tmp_path / "docs"
    with patch.object(progress, "ROOT", tmp_path), patch.object(progress, "DOCS", docs), \
         patch.object(progress.clients, "load", return_value={"C": {"compiler": "MSVC"}}), \
         patch.object(progress, "library_meta", return_value={}), \
         patch.object(progress, "source_links", return_value={}), \
         patch.object(progress, "landmarks", return_value=[]):
        published = progress.build(remote=export(store))
        assert (published["clients"][0]["matched"], published["clients"][0]["partial"]) == (0, 1)
        assert [row[2] for row in json.loads((docs / "data/C.json").read_text())["funcs"]] == [50, 0]
        # Explicitly offline builds still support local-only research scores.
        assert progress.build()["clients"][0]["matched"] == 2
    store.db.close()
