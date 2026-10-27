import struct

from roc import standins


def coff(code, relocs, names):
    """One .text section holding `code` for symbol names[0]; relocs [(offset, symbol index, type)]."""
    strtab = b""
    symbols = b""
    for i, name in enumerate(names):
        raw = name.encode()
        if len(raw) > 8:
            raw, strtab = struct.pack("<II", 0, 4 + len(strtab)), strtab + raw + b"\0"
        symbols += struct.pack("<8sIhHBB", raw.ljust(8, b"\0"), 0, 1 if i == 0 else 0, 0x20, 2, 0)
    data, relptr = 20 + 40, 20 + 40 + len(code)
    symptr = relptr + 10 * len(relocs)
    head = struct.pack("<HHIIIHH", 0x14c, 1, 0, symptr, len(names), 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), data, relptr, 0, len(relocs), 0, 0x60000020)
    table = b"".join(struct.pack("<IIH", *r) for r in relocs)
    return head + section + code + table + symbols + struct.pack("<I", 4 + len(strtab)) + strtab


def test_relocations_name_each_placeholder_with_its_offset():
    code = b"\xe8\0\0\0\0\xa1\0\0\0\0\xc3"  # call placeholder; mov eax, [global]; ret
    obj = coff(code, [(1, 1, standins.REL32), (6, 2, standins.DIR32)], ["?f@@YAXXZ", "?callee_standin@@YAXXZ", "_g"])
    assert standins.obj_relocations(obj, "?f@@YAXXZ") == [
        (1, "?callee_standin@@YAXXZ", standins.REL32), (6, "_g", standins.DIR32)]
    assert standins.obj_relocations(obj, "missing") == []
