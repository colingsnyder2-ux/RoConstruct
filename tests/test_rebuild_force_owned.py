from roc import rebuild


def test_force_uses_report_ownership_and_external_definitions(tmp_path, monkeypatch):
    linked = tmp_path / "linked"
    linked.mkdir()
    obj = linked / "one.obj"
    obj.write_bytes(b"object")
    cache = tmp_path / "cache"
    monkeypatch.setattr(rebuild, "coff_externals", lambda data: {
        "placed": True, "ambiguous": True, "internal": False,
    })
    seen = []

    def ownership(client, actual, cache_path, context):
        seen.append((client, actual, cache_path, context))
        return [("placed", 7, ["00401000"]),
                ("ambiguous", 7, ["00401000", "00402000"]),
                ("internal", 7, ["00403000"])], True

    monkeypatch.setattr(rebuild, "_ownership_rows", ownership)
    assert rebuild._forced_owned_symbols("2008-06", linked, cache, "context") == {"placed"}
    assert seen == [("2008-06", obj, cache / "one.obj.json", "context")]
