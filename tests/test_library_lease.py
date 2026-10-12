from roc.server import Store


def test_lease_filters_by_library():
    st = Store(":memory:", lease_seconds=60)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                      [("C", "00401000", 8, "RakPeer"), ("C", "00401010", 8, "CXTPCommandBar")])
    assert st.lease("u", "w1", ["C"], "ai", 256, library="RakNet")["addr"] == "00401000"
    assert st.lease("u", "w2", ["C"], "ai", 256, library="RakNet") is None
    assert st.lease("u", "w3", ["C"], "ai", 256)["addr"] == "00401010"
