import struct
from contextlib import contextmanager
from pathlib import Path

from roc import libs, match


def test_library_metadata_comments_share_object_cache_but_settings_and_bodies_do_not(monkeypatch):
    from functools import lru_cache
    calls = []
    body = ["int vendor() { return 1; }"]
    monkeypatch.setattr(match.clients, "load", lambda: {"test": {"compiler_build": 21022}})
    monkeypatch.setattr(libs, "unit", lambda *args: body[0])
    @lru_cache(None)
    def compile_cached(text, flags, build, c_lang):
        calls.append((text, flags, build, c_lang))
        return str(len(calls)).encode()
    monkeypatch.setattr(match, "_compile", compile_cached)
    first = "// from server: 99% by first\n// roc-lib: test vendor.cpp\n"
    second = "// address 00401040\n// roc-lib: test vendor.cpp\n"
    assert match.compile_text("test", first) == match.compile_text("test", second)
    assert len(calls) == 1 and calls[0][0] == body[0]
    match.compile_text("test", second, flags="/O1")
    assert len(calls) == 2 and calls[-1][1] == "/O1"
    body[0] = "int vendor() { return 2; }"
    match.compile_text("test", first)
    assert len(calls) == 3 and calls[-1][0] == body[0]


def test_library_real_prelude_and_comment_continuation_are_preserved(monkeypatch):
    calls = []
    monkeypatch.setattr(match.clients, "load", lambda: {"test": {"compiler_build": 21022}})
    monkeypatch.setattr(libs, "unit", lambda *args: "int vendor;")
    monkeypatch.setattr(match, "_compile", lambda *args: calls.append(args) or b"obj")
    prelude = "// roc-lib: test vendor.cpp\nint local_value;\n"
    continuation = "// roc-lib: test vendor.cpp\n// folder\\\n"
    match.compile_text("test", prelude)
    match.compile_text("test", continuation)
    assert calls[0][0] == prelude + "\nint vendor;"
    assert calls[1][0] == continuation + "\nint vendor;"


def test_raw_library_prelude_include_failure_explains_managed_units(monkeypatch):
    import pytest
    monkeypatch.setattr(match.clients, "load", lambda: {"test": {"compiler_build": 21022}})
    monkeypatch.setattr(libs, "unit", lambda *args: "int vendor;")
    monkeypatch.setattr(match, "_cacheable", lambda text: False)
    def fail(*args):
        raise match.CompileError("source(1): fatal error C1083: Cannot open include file: G3D/ReferenceCount.h")
    monkeypatch.setattr(match, "_compile_uncached", fail)
    with pytest.raises(match.CompileError) as error:
        match.compile_text("test", "// roc-lib: test vendor.cpp\n#include <G3D/ReferenceCount.h>\n")
    assert "C1083" in str(error.value) and "libs.add_unit" in str(error.value)
    assert "recipe include paths" in str(error.value)


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


def test_expanded_units_bound_memory_reload_disk_and_invalidate_headers(tmp_path, monkeypatch):
    import os
    from pathlib import Path
    from roc import libs
    monkeypatch.setattr(libs, "_UNITS", {})
    header = tmp_path / "header.h"
    header.write_text("header1")
    paths = []
    for index in range(33):
        path = tmp_path / (str(index) + ".i")
        path.write_text("expanded" + str(index))
        libs._write_deps(path, "recipe", [header])
        assert libs._cached_unit(path, "recipe") == "expanded" + str(index)
        paths.append(path)
    assert len(libs._UNITS) == 32 and str(paths[0]) not in libs._UNITS
    original_read = Path.read_text
    reads = []
    def read(path, *args, **kwargs):
        if path.suffix == ".i": reads.append(path)
        return original_read(path, *args, **kwargs)
    monkeypatch.setattr(Path, "read_text", read)
    assert libs._cached_unit(paths[0], "recipe") == "expanded0"
    assert libs._cached_unit(paths[0], "recipe") == "expanded0"
    assert reads == [paths[0]] and len(libs._UNITS) == 32
    previous = header.stat()
    header.write_text("header2")
    os.utime(header, ns=(previous.st_atime_ns, previous.st_mtime_ns + 10000000))
    assert libs._cached_unit(paths[0], "recipe") is None
    assert libs._cached_unit(paths[0], "changed-recipe") is None


def test_data_relocation_range_keeps_both_boundaries_exact(monkeypatch):
    base = 0x400000
    image = b'xxxxABCDWXYZyyyy'
    monkeypatch.setattr(match, '_image', lambda _: (base, image))
    monkeypatch.setattr(match, '_base_relocs', lambda _: frozenset({base + 3, base + 4, base + 12}))
    code = (base + 4).to_bytes(4, 'little')
    # Relocation at start is masked; relocation at end must not extend the mask.
    assert match.data_check('client', '00400000', code, [(0, b'----WXYZ', [])])[1] == []
    assert match.data_check('client', '00400000', code, [(0, b'----FAIL', [])])[1]

