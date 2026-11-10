import struct
import json

import pytest

from roc import analyze, server


def fixture():
    base = 0x400000
    image = bytearray(0x2000)
    thunk, info, table, handlers, entry = 0x401000, 0x400100, 0x400140, 0x400180, 0x401020
    image[thunk-base:thunk-base+10] = b"\xb8"+struct.pack("<I", info)+b"\xe9\0\0\0\0"
    struct.pack_into("<IiIiI", image, info-base, 0x19930522, 4, 0, 1, table)
    struct.pack_into("<iiiiI", image, table-base, 0, 1, 3, 1, handlers)
    struct.pack_into("<IIiI", image, handlers-base, 0x40, 0, 0, entry)
    image[entry-base:entry-base+9] = bytes.fromhex("8b45fcb820104000c3")
    read = lambda address, count: image[address-base:address-base+count] if base <= address < base+len(image) else b""
    return image, read, {thunk+1, info+16, table+16, handlers+12}, lambda a: 0x401000 <= a < 0x402000


def test_catch_table_proves_parent_frame_handler():
    _, read, sites, in_text = fixture()
    contexts = analyze.msvc_catch_handlers(read, sites, in_text)
    assert contexts[0x401020][0]["func_info"] == 0x400100
    assert contexts[0x401020][0]["catch_type"] == 0
    row = dict(addr="00401020", size=9, kind="code")
    analyze.mark_catch_handlers([row], contexts, read)
    assert row["kind"] == "eh" and row["catch_context"] == contexts[0x401020]


@pytest.mark.parametrize("site", [0x401001, 0x400110, 0x400150, 0x40018c])
def test_missing_pointer_relocations_reject_map(site):
    _, read, sites, in_text = fixture()
    assert not analyze.msvc_catch_handlers(read, sites-{site}, in_text)


@pytest.mark.parametrize("address,value", [(0x40010c, 5000), (0x400144, 5), (0x40014c, 0), (0x40018c, 0x400080)])
def test_invalid_counts_states_or_handler_reject_map(address, value):
    image, read, sites, in_text = fixture()
    struct.pack_into("<I", image, address-0x400000, value)
    assert not analyze.msvc_catch_handlers(read, sites, in_text)


def test_typed_catch_requires_type_pointer_relocation():
    image, read, sites, in_text = fixture()
    struct.pack_into("<I", image, 0x184, 0x400200)
    assert not analyze.msvc_catch_handlers(read, sites, in_text)
    sites.add(0x400184)
    assert analyze.msvc_catch_handlers(read, sites, in_text)[0x401020][0]["catch_type"] == 0x400200


def test_data_and_independent_frames_remain_unchanged():
    _, read, sites, in_text = fixture()
    contexts = analyze.msvc_catch_handlers(read, sites, in_text)
    row = dict(addr="00401020", size=9, kind="data")
    analyze.mark_catch_handlers([row], contexts, read)
    assert row == dict(addr="00401020", size=9, kind="data")
    row = dict(addr="00401020", size=4, kind="code")
    analyze.mark_catch_handlers([row], contexts, lambda a, n: bytes.fromhex("558becc3"))
    assert row["kind"] == "code" and row["catch_context"]


def test_reclassified_exact_catch_leaves_mining_pool(tmp_path, monkeypatch):
    _, read, sites, in_text = fixture()
    contexts = analyze.msvc_catch_handlers(read, sites, in_text)
    folder = tmp_path / "work/C"
    folder.mkdir(parents=True)
    rows = [dict(addr="00401000", size=8, kind="code", unit="Parent"),
            dict(addr="00401020", size=9, kind="code", unit="Catch")]
    inventory = folder / "functions.jsonl"
    def save():
        inventory.write_text("".join(json.dumps(row)+"\n" for row in rows))
    save()
    monkeypatch.setattr(server, "ROOT", tmp_path)
    store = server.Store(":memory:", 600)
    try:
        store.seed("C")
        store.submit("C", "00401020", "test", 100, "old catch source")
        analyze.mark_catch_handlers(rows, contexts, read)
        analyze.mark_matched_code(rows, {"00401020"})
        assert rows[1]["kind"] == "eh"
        save()
        store.seed("C")
        assert store.best("C", "00401000") is not None
        assert store.best("C", "00401020") is None
        assert store.lease("test", "worker", ["C"], "", 1000,
                           targets=[{"client": "C", "addr": "00401020"}]) is None
        with pytest.raises(ValueError, match="unknown function"):
            store.submit("C", "00401020", "test", 100, "old catch source")
    finally:
        store.db.close()
