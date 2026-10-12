import struct

from roc import libs, match


def test_string_recipe_preserves_baseline_and_buffer_conversion(tmp_path, monkeypatch):
    source = tmp_path / "Source" / "Test.cpp"
    source.parent.mkdir()
    source.write_text("// source fixture\n")
    baseline = ("bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );\n\t}\n"
                "operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );\n\t}\n"
                "operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszBuffer );\n\t}\n")
    calls = []
    monkeypatch.setattr(libs, "ROOT", tmp_path)
    monkeypatch.setattr(libs, "fetch", lambda name: tmp_path)
    monkeypatch.setattr(libs, "winsdk_include", lambda: "")
    monkeypatch.setattr(libs, "preprocess", lambda *args: calls.append(args) or baseline)

    adjusted = libs.unit("xtp-11.2.2-shared-mfc-string-calls", "Source/Test.cpp", 21022)
    assert adjusted.count("__declspec(noinline)") == 2
    assert "operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszBuffer );" in adjusted
    assert libs.unit("xtp-11.2.2-shared-mfc", "Source/Test.cpp", 21022) == baseline
    assert libs.unit("xtp-11.2.2-shared-mfc-string-calls", "Source/Test.cpp", 21022) == adjusted
    assert len(calls) == 2


def test_private_header_recipe_wraps_source_without_editing_it(tmp_path, monkeypatch):
    source = tmp_path / "Source" / "Test.cpp"
    source.parent.mkdir()
    source.write_text("// original translation unit\n")
    wrappers = []
    monkeypatch.setattr(libs, "ROOT", tmp_path)
    monkeypatch.setattr(libs, "fetch", lambda name: tmp_path)
    monkeypatch.setattr(libs, "winsdk_include", lambda: "")

    def preprocess(build, path, include, defines, deps=None):
        wrappers.append(path.read_text())
        assert "mfc-9.0" in include
        assert defines == "_AFXDLL _XTP_STATICLINK _DLL"
        return "// preprocessed fixture\n"

    monkeypatch.setattr(libs, "preprocess", preprocess)
    result = libs.unit("xtp-11.2.2-shared-mfc-internals", "Source/Test.cpp", 21022)
    assert result == "// preprocessed fixture\n"
    assert wrappers == ['#include "XTToolkitPro.h"\n#include "afximpl.h"\n#include "'
                        + source.as_posix() + '"\n']
    assert source.read_text() == "// original translation unit\n"
    assert libs.unit("xtp-11.2.2-shared-mfc-internals", "Source/Test.cpp", 21022) == result
    assert len(wrappers) == 1


def test_compiled_functions_drop_trailing_int3_like_analyzer():
    # One .text section holding "push ebp; call rel32; int3; int3", one function symbol.
    body = b"\x55\xe8\x00\x00\x00\x00\xcc\xcc"
    header = struct.pack("<HHIIIHH", 0x14c, 1, 0, 20 + 40 + len(body) + 10, 1, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(body), 60, 60 + len(body), 0, 1, 0, 0)
    reloc = struct.pack("<IIH", 2, 0, 0x14)
    symbol = struct.pack("<8sIhHBB", b"_f", 0, 1, 0x20, 2, 0)
    obj = header + section + body + reloc + symbol + struct.pack("<I", 4)
    assert match.coff_functions(obj) == [("_f", body[:6], [2])]


def test_proven_extent_drops_inner_starts_and_splits_tail():
    from roc import analyze
    # 0: nop; nop; ret | 3: ret (tiny merged function) | pad | 16: nop; ret
    code = b"\x90\x90\xc3\xc3" + b"\xcc" * 12 + b"\x90\xc3"
    seeds = {0x1000, 0x1001, 0x1010}  # 0x1001 is a spurious start
    plain = analyze.find_functions(code, 0x1000, seeds, [])
    assert [(f["addr"], f["size"]) for f in plain] == [("00001000", 1), ("00001001", 3), ("00001010", 2)]
    fixed = analyze.find_functions(code, 0x1000, seeds, [], [(0x1000, 3)])
    assert [(f["addr"], f["size"]) for f in fixed] == [("00001000", 3), ("00001003", 1), ("00001010", 2)]
