import struct

from roc import analyze


def fixture():
    base = 0x400000
    image = bytearray(0x2000)
    handler, info, table, action = 0x401000, 0x400100, 0x400140, 0x401020
    image[handler-base:handler-base+10] = b"\xb8" + struct.pack("<I", info) + b"\xe9\0\0\0\0"
    struct.pack_into("<IiI", image, info-base, 0x19930522, 1, table)
    struct.pack_into("<iI", image, table-base, -1, action)
    image[action-base:action-base+7] = bytes.fromhex("8d8d40feffffc3")
    read = lambda addr, size: image[addr-base:addr-base+size] if base <= addr < base+len(image) else b""
    return image, read, {handler+1, info+8, table+4}, lambda addr: 0x401000 <= addr < 0x402000


def test_unwind_provenance_and_parent_frame_classification():
    _, read, relocs, in_text = fixture()
    actions = analyze.msvc_unwind_actions(read, relocs, in_text)
    assert actions[0x401020] == [dict(handler=0x401000, func_info=0x400100,
        unwind_map=0x400140, state=0, to_state=-1)]
    rows = [dict(addr="00401020", size=7, kind="code"),
            dict(addr="00401040", size=1, kind="code")]
    analyze.mark_unwind_actions(rows, actions, read)
    assert rows[0]["kind"] == "eh" and rows[0]["unwind_context"]
    assert rows[1]["kind"] == "code" and "unwind_context" not in rows[1]


def test_invalid_state_or_missing_action_relocation_rejects_map():
    image, read, relocs, in_text = fixture()
    assert analyze.msvc_unwind_actions(read, relocs - {0x400144}, in_text) == {}
    struct.pack_into("<i", image, 0x140, 0)
    assert analyze.msvc_unwind_actions(read, relocs, in_text) == {}


def test_map_reference_alone_does_not_reclassify_ordinary_code_or_data():
    _, read, relocs, in_text = fixture()
    actions = analyze.msvc_unwind_actions(read, relocs, in_text)
    rows = [dict(addr="00401020", size=7, kind="data")]
    analyze.mark_unwind_actions(rows, actions, read)
    assert rows == [dict(addr="00401020", size=7, kind="data")]
    rows = [dict(addr="00401020", size=1, kind="code")]
    analyze.mark_unwind_actions(rows, actions, lambda addr, size: b"\xc3")
    assert rows[0]["kind"] == "code"
