import struct

from roc import libs, match


def test_data_ref_starts_at_relocation_addend():
    # .text: mov eax, [table+4]  (addend 4 stored in the instruction); .data: table = 8 bytes.
    code = b"\xa1\x04\x00\x00\x00\xc3"
    data = b"AAAABBBB"
    text_ptr = 20 + 2 * 40
    data_ptr = text_ptr + len(code)
    reloc_ptr = data_ptr + len(data)
    sym_ptr = reloc_ptr + 10
    header = struct.pack("<HHIIIHH", 0x14c, 2, 0, sym_ptr, 2, 0, 0)
    text = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), text_ptr, reloc_ptr, 0, 1, 0, 0x60000020)
    sec_data = struct.pack("<8sIIIIIIHHI", b".data", 0, 0, len(data), data_ptr, 0, 0, 0, 0, 0xC0000040)
    reloc = struct.pack("<IIH", 1, 1, 6)  # DIR32 at offset 1 -> symbol 1 (table)
    syms = (struct.pack("<8sIhHBB", b"_f", 0, 1, 0x20, 2, 0)
            + struct.pack("<8sIhHBB", b"_table", 0, 2, 0, 3, 0))
    obj = header + text + sec_data + code + data + reloc + syms + struct.pack("<I", 4)
    assert match.coff_data_refs(obj, "_f") == [(1, b"BBBB", [])]


def test_file_literal_uses_original_build_spelling():
    recipe = {"file_names": {"G3Dcpp\\Stopwatch.cpp": ".\\g3dcpp\\Stopwatch.cpp",
                             "*": lambda p: ".\\" + p.replace("GLG3Dcpp\\", "glg3dcpp\\")}}
    src = "C:\\libs\\g3d\\GLG3Dcpp\\Shader.cpp"
    body = 'assert("C:\\\\libs\\\\g3d\\\\GLG3Dcpp\\\\Shader.cpp");'
    assert libs._file_literal(recipe, src, "GLG3Dcpp/Shader.cpp", body) == \
        'assert(".\\\\glg3dcpp\\\\Shader.cpp");'
    stop = 'f("C:\\\\libs\\\\g3d\\\\G3Dcpp\\\\Stopwatch.cpp");'
    assert libs._file_literal(recipe, "C:\\libs\\g3d\\G3Dcpp\\Stopwatch.cpp", "G3Dcpp/Stopwatch.cpp", stop) == \
        'f(".\\\\g3dcpp\\\\Stopwatch.cpp");'
    assert libs._file_literal({}, src, "x.cpp", body) == body
