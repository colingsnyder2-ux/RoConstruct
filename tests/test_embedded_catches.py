import struct

from roc import analyze


def fixture(called=False, bad_exit=False):
    base, handler, normal = 0x1000, 0x1033, 0x1050
    code = bytearray(b"\x90" * 0x56)
    prefix = bytes.fromhex("558bec6aff688010000064a100000000506489250000000083ec20")
    code[:len(prefix)] = prefix
    continuation = base + len(prefix)
    if called:
        code[len(prefix):len(prefix) + 5] = b"\xe8" + struct.pack("<i", handler - continuation - 5)
        continuation += 5
    offset = continuation - base
    code[offset:offset + 5] = b"\xe9" + struct.pack("<i", normal - continuation - 5)
    offset = handler - base
    code[offset:offset + 9] = b"\x8b\x4d\xfc\xb8" + struct.pack("<I", continuation) + b"\xc3"
    code[normal - base:] = bytes.fromhex("8be55dc20800")
    if bad_exit:
        # An unrelated early return cannot borrow an unreachable later epilogue.
        code[normal - base - 1] = 0xC3
        code[len(prefix) + 1:len(prefix) + 5] = struct.pack("<i", normal - continuation - 6)
    return bytes(code), base, handler, {handler + 4}


def rows(code, base, handler, relocs, **kwargs):
    return analyze.find_functions(code, base, {base, handler}, sorted(relocs), keep={base}, **kwargs)


def test_catch_and_shared_normal_exit_belong_to_parent():
    code, base, handler, relocs = fixture()
    result = rows(code, base, handler, relocs)
    assert [(r["addr"], r["size"]) for r in result] == [("00001000", len(code))]
    assert result[0]["embedded_catches"][0]["handler"] == "00001033"


def test_directly_called_handler_is_not_absorbed():
    code, base, handler, relocs = fixture(called=True)
    assert "00001033" in {r["addr"] for r in rows(code, base, handler, relocs)}


def test_exact_or_proven_extents_are_unchanged():
    code, base, handler, relocs = fixture()
    for locked in ({base}, {handler}):
        assert "00001033" in {r["addr"] for r in rows(code, base, handler, relocs, locked=locked)}
    result = rows(code, base, handler, relocs, proven=[(base, handler - base)])
    assert result[0]["size"] == handler - base


def test_unrelocated_pointer_and_unreachable_epilogue_do_not_merge():
    code, base, handler, relocs = fixture()
    assert "00001033" in {r["addr"] for r in rows(code, base, handler, set())}
    code, base, handler, relocs = fixture(bad_exit=True)
    assert "00001033" in {r["addr"] for r in rows(code, base, handler, relocs)}


def test_independently_framed_handler_is_preserved():
    code, base, handler, relocs = fixture()
    code = bytearray(code)
    code[handler - base:handler - base + 3] = bytes.fromhex("558bec")
    assert "00001033" in {r["addr"] for r in rows(bytes(code), base, handler, relocs)}


def test_partial_instruction_before_handler_is_not_boundary_proof():
    code, base, handler, relocs = fixture()
    code = bytearray(code)
    code[handler - base - 1] = 0x0F
    assert "00001033" in {r["addr"] for r in rows(bytes(code), base, handler, relocs)}
