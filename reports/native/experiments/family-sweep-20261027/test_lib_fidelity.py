import struct
from contextlib import contextmanager
from pathlib import Path

from roc import libs, match


def test_data_relocation_range_keeps_both_boundaries_exact(monkeypatch):
    base = 0x400000
    image = b'xxxxABCDWXYZyyyy'
    monkeypatch.setattr(match, '_image', lambda _: (base, image))
    monkeypatch.setattr(match, '_base_relocs', lambda _: frozenset({base + 3, base + 4, base + 12}))
    code = (base + 4).to_bytes(4, 'little')
    # Relocation at start is masked; relocation at end must not extend the mask.
    assert match.data_check('client', '00400000', code, [(0, b'----WXYZ', [])])[1] == []
    assert match.data_check('client', '00400000', code, [(0, b'----FAIL', [])])[1]


def test_library_patched_copy_uses_acl_safe_compile_directory(tmp_path, monkeypatch):
    source = tmp_path / "source"
    source.mkdir()
    (source / "unit.cpp").write_text("old")
    safe = tmp_path / "safe"
    used = []

    @contextmanager
    def compile_directory():
        safe.mkdir()
        used.append(True)
        yield safe

    monkeypatch.setitem(libs.RECIPES, "test", {"patches": {"unit.cpp": [["old", "new"]]}})
    monkeypatch.setattr(libs, "fetch", lambda name: source)
    monkeypatch.setattr(match, "compile_directory", compile_directory)
    monkeypatch.setattr(libs, "preprocess", lambda build, path, include, defines, deps: Path(path).read_text())
    monkeypatch.setattr(libs, "ROOT", tmp_path)
    assert "new" in libs.unit("test", "unit.cpp", 21022)
    assert used


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
    # Same symbols, different immutable object data must never share referenced bytes.
    changed = obj.replace(b"AAAABBBB", b"AAAACCCC")
    assert match.coff_data_refs(changed, "_f") == [(1, b"CCCC", [])]
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
