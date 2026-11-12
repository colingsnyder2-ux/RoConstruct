import struct

import pytest

from roc import rebuild


def pe_image(machine=0x14c, marker=b"first"):
    data = bytearray(256)
    data[:2] = b"MZ"
    struct.pack_into("<I", data, 0x3c, 128)
    data[128:132] = b"PE\0\0"
    struct.pack_into("<H", data, 132, machine)
    data[160:160 + len(marker)] = marker
    return data


def test_support_import_library_is_keyed_by_dll_contents(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    monkeypatch.setattr(rebuild, "dll_exports", lambda path: ["SDL_Init"])
    monkeypatch.setattr(rebuild, "toolchain", lambda: {})
    calls = []

    def run(tc, tool, args, directory):
        calls.append(args)
        output = next(arg[5:] for arg in args if arg.startswith("/OUT:"))
        (directory / output).write_bytes(b"import library")
        return 0, ""

    monkeypatch.setattr(rebuild, "run", run)
    dll = tmp_path / "SDL.dll"
    dll.write_bytes(pe_image())
    first = rebuild.dll_import_lib("2008-06", dll.name, source=dll)
    assert first == rebuild.dll_import_lib("2008-06", dll.name, source=dll)
    assert len(calls) == 1
    assert "SDL_Init" in first.with_suffix(".def").read_text()
    dll.write_bytes(pe_image(marker=b"other"))
    assert rebuild.dll_import_lib("2008-06", dll.name, source=dll) != first
    assert len(calls) == 2


def test_support_import_rejects_wrong_architecture(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    dll = tmp_path / "SDL.dll"
    dll.write_bytes(pe_image(machine=0x8664))
    with pytest.raises(ValueError, match="x86 PE"):
        rebuild.dll_import_lib("2008-06", dll.name, source=dll)


def test_dependency_support_dll_is_copied_and_linked(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    source = tmp_path / "vendor" / "SDL.dll"
    source.parent.mkdir()
    source.write_bytes(b"vendor runtime")
    library = tmp_path / "SDL.lib"
    monkeypatch.setattr(rebuild, "dll_import_lib", lambda client, dll, source=None: library)
    specs = [{"name": "parent"}, {"name": "dependency", "import_support_dlls": ["vendor/SDL.dll"]}]
    assert rebuild._link_support("2008-06", specs, "fixture") == [library]
    assert (tmp_path / "out/tests/fixture/SDL.dll").read_bytes() == b"vendor runtime"


def test_conflicting_dependency_runtime_names_are_rejected(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, "ROOT", tmp_path)
    monkeypatch.setattr(rebuild, "workspace", lambda client: tmp_path)
    for directory, content in (("a", b"one"), ("b", b"two")):
        path = tmp_path / directory / "same.dll"
        path.parent.mkdir()
        path.write_bytes(content)
    specs = [{"runtime_files": ["a/same.dll"]}, {"runtime_files": ["b/same.dll"]}]
    with pytest.raises(ValueError, match="Conflicting runtime files"):
        rebuild._link_support("2008-06", specs, "fixture")
