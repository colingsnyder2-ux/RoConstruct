import sqlite3
import threading
from roc.server import Store


def test_source_pages_preserve_sources_and_advance_by_address():
    store = Store.__new__(Store)
    store.lock = threading.Lock()
    store.db = sqlite3.connect(":memory:")
    store.db.execute("CREATE TABLE funcs(client,addr,score,user,source)")
    store.db.executemany("INSERT INTO funcs VALUES(?,?,?,?,?)", [
        ("C", "00000001", 100, "me", "exact body"),
        ("C", "00000002", 90, "me", "partial body"),
        ("C", "00000003", 50, "me", "other body"),
        ("D", "00000004", 99, "me", "different client")])
    page = store.source_page("C", limit=2)
    assert [r["addr"] for r in page] == ["00000001", "00000002"]
    assert page[0]["source"] == "exact body"
    next_page = store.source_page("C", after=page[-1]["addr"], limit=2)
    assert [r["addr"] for r in next_page] == ["00000003"]
    assert store.source_page("C", after=next_page[-1]["addr"]) == []
    store.db.close()
