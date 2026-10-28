import struct

from roc import match


def make_object(code, symbols, relocs=()):
    relptr = 60 + len(code)
    header = struct.pack("<HHIIIHH", 0x14c, 1, 0, relptr + 10 * len(relocs), len(symbols), 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), 60, relptr, 0,
                          len(relocs), 0, 0x60000020)
    records = b"".join(struct.pack("<8sIhHBB", name.encode().ljust(8, b"\0"), value, 1, 0x20, 2, 0)
                       for name, value in symbols)
    return (header + section + code + b"".join(struct.pack("<IIH", offset, 0, kind)
                                               for offset, kind in relocs)
            + records + struct.pack("<I", 4))


def test_local_branch_closure_preserves_original_slices_and_relocations():
    # Entry branches past a second entry into a shared tail. The tail itself
    # branches into a fourth entry; unrelated code after that stays excluded.
    code = bytes.fromhex("7403c390c3b800000000eb00c390c3")
    obj = make_object(code, [("_entry", 0), ("_other", 3), ("_tail", 5),
                             ("_last", 12), ("_next", 13)], [(6, 6)])
    entries = [(body, relocs) for name, body, relocs in match.coff_functions(obj) if name == "_entry"]
    assert entries == [(code[:13], [6]), (code[:3], [])]


def test_relocated_tail_jump_does_not_absorb_another_linker_function():
    code = bytes.fromhex("e900000000c3")
    obj = make_object(code, [("_entry", 0), ("_other", 5)], [(1, 20)])
    assert [(body, relocs) for name, body, relocs in match.coff_functions(obj) if name == "_entry"] == [
        (code[:5], [1])]


def test_call_does_not_absorb_callee():
    code = bytes.fromhex("e801000000c3c3")
    obj = make_object(code, [("_entry", 0), ("_callee", 6)])
    assert [(body, relocs) for name, body, relocs in match.coff_functions(obj) if name == "_entry"] == [
        (code[:6], [])]
