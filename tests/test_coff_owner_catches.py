import struct

from roc import match


def test_owner_includes_only_its_embedded_catches_and_continuation():
    code = bytes.fromhex("eb04b800000000c333c0c3cccc90c3")
    symbols = [("__catch$_owner$0", 2), ("_owner", 0), ("_next", 13)]
    strings = b""
    records = b""
    for name, value in symbols:
        encoded = name.encode()
        if len(encoded) > 8:
            raw = struct.pack("<II", 0, 4 + len(strings))
            strings += encoded + b"\0"
        else:
            raw = encoded.ljust(8, b"\0")
        records += struct.pack("<8sIhHBB", raw, value, 1, 0x20, 2, 0)
    relptr = 60 + len(code)
    header = struct.pack("<HHIIIHH", 0x14c, 1, 0, relptr + 10, len(symbols), 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), 60, relptr, 0, 1, 0, 0x60000020)
    obj = header + section + code + struct.pack("<IIH", 3, 0, 6)
    obj += records + struct.pack("<I", 4 + len(strings)) + strings

    functions = dict((name, (body, relocs)) for name, body, relocs in match.coff_functions(obj))
    assert functions["_owner"] == (code[:11], [3])
    assert functions["__catch$_owner$0"] == (code[2:11], [1])
    assert functions["_next"] == (code[13:], [])

    # A catch owned by another function remains a boundary.
    other = obj.replace(b"__catch$_owner$0", b"__catch$_other$0")
    assert dict((name, body) for name, body, _ in match.coff_functions(other))["_owner"] == code[:2]
