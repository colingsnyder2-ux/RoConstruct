"""Linux support: the Wine platform layer and the non-Windows install paths.

These tests run on any OS: they patch roc.setup.WINDOWS to False rather than
depending on the host, so the Linux branches are exercised on Windows CI too.
"""
import os
import struct
import sys
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))


def test_refresh_path_is_a_noop_off_windows():
    from roc import setup
    with patch("roc.setup.WINDOWS", False), patch.dict("os.environ", {"PATH": "/usr/bin"}):
        assert setup.refresh_path() == "/usr/bin"


def test_wine_paths_are_z_drive_windows_paths():
    from roc import setup
    with patch("roc.setup.WINDOWS", False):
        assert setup.to_wine_path("/tmp/a b/f.cpp") == "z:\\tmp\\a b\\f.cpp"
        assert setup.cl_path("/tmp/f.cpp") == "z:\\tmp\\f.cpp"
        with patch.dict("os.environ", {"ROC_WINE_DRIVE": "d:"}):
            assert setup.to_wine_path("/src/x.cpp") == "d:\\src\\x.cpp"


def test_cl_command_uses_wine_on_linux():
    from roc import setup
    with patch("roc.setup.WINDOWS", False), \
         patch("roc.setup.wine_exe", return_value="/usr/bin/wine"):
        assert setup.cl_command("/tools/vc/VC/bin/cl.exe") == ["/usr/bin/wine", "/tools/vc/VC/bin/cl.exe"]
    with patch("roc.setup.WINDOWS", False), patch("roc.setup.wine_exe", return_value=None):
        try:
            setup.cl_command("/tools/vc/VC/bin/cl.exe")
            assert False, "missing Wine must be an error, not a silent fallback"
        except SystemExit as error:
            assert "Wine" in str(error)
    with patch("roc.setup.WINDOWS", True):
        assert setup.cl_command("/tools/vc/VC/bin/cl.exe") == ["/tools/vc/VC/bin/cl.exe"]


def test_compilers_returns_empty_without_wine():
    from roc import setup
    setup.compilers.cache_clear()
    with patch("roc.setup.WINDOWS", False), patch("roc.setup.wine_exe", return_value=None):
        assert setup.compilers() == {}
    setup.compilers.cache_clear()


def test_cl_env_under_wine_uses_windows_include_and_winepath(tmp_path):
    from roc import setup
    if os.name == "nt":
        return  # Wine paths only exist on a Unix host; tmp paths here are C:\-shaped
    cl = tmp_path / "VC" / "bin" / "cl.exe"
    (tmp_path / "VC" / "include").mkdir(parents=True)
    (tmp_path / "Common7" / "IDE").mkdir(parents=True)
    setup._cached_cl_env.cache_clear()
    with patch("roc.setup.WINDOWS", False):
        env = setup.cl_env(cl)
    assert env["WINEPATH"].startswith("z:\\")
    assert ";" in env["WINEPATH"], "Wine needs Windows-style PATH separators"
    assert env["INCLUDE"] == setup.to_wine_path(tmp_path / "VC" / "include")
    assert env["WINEPREFIX"]
    setup._cached_cl_env.cache_clear()


def test_ensure_wine_prefix_is_cheap_once_created(tmp_path):
    from roc import setup
    prefix = tmp_path / "wineprefix"
    prefix.mkdir()
    (prefix / "system.reg").write_text("")
    with patch("roc.setup.WINDOWS", False), \
         patch("roc.setup.WINE_PREFIX", prefix), \
         patch("roc.setup.wine_exe", return_value="/usr/bin/wine"), \
         patch("roc.setup.subprocess.run") as run:
        assert setup.ensure_wine_prefix(log=lambda _line: None) is True
        assert not run.called, "an existing prefix must not be re-created"


def test_install_refuses_to_start_without_wine(capsys):
    from roc import setup
    with patch("roc.setup.compiler_ready", return_value=False), \
         patch("roc.setup.ensure_packages"):
        assert setup.install(ask=lambda _q: "y") is False
    assert "Wine" in capsys.readouterr().out


def test_local_ai_linux_explains_how_to_install_ollama(capsys):
    from roc import setup
    with patch("roc.setup.WINDOWS", False), patch("roc.setup.find_exe", return_value=None):
        assert setup.local_ai(ask=lambda _q: "y") is False
    out = capsys.readouterr().out
    assert "ollama" in out.lower() and "roc local-ai" in out


def test_local_ai_linux_pulls_only_after_asking():
    from roc import setup
    asked = []
    with patch("roc.setup.WINDOWS", False), \
         patch("roc.setup.find_exe", return_value="/usr/bin/ollama"), \
         patch("roc.setup.ensure_ollama", return_value=["qwen2.5-coder:14b"]), \
         patch("roc.setup.mark_done"), \
         patch("roc.setup.subprocess.run") as run:
        assert setup.local_ai(ask=lambda q: asked.append(q) or "n") is True
    assert asked, "a model download is a question"
    assert not run.called, "declining must not pull anything"


def test_cloudflared_url_matches_the_platform():
    from roc import setup
    with patch("roc.setup.platform.machine", return_value="x86_64"):
        with patch("roc.setup.WINDOWS", True):
            assert setup.cloudflared_url().endswith("windows-amd64.exe")
        with patch("roc.setup.WINDOWS", False), patch("roc.setup.sys.platform", "linux"):
            assert setup.cloudflared_url().endswith("linux-amd64")
        with patch("roc.setup.WINDOWS", False), patch("roc.setup.sys.platform", "linux"), \
             patch("roc.setup.platform.machine", return_value="aarch64"):
            assert setup.cloudflared_url().endswith("linux-arm64")
        with patch("roc.setup.WINDOWS", False), patch("roc.setup.sys.platform", "linux"), \
             patch("roc.setup.platform.machine", return_value="armv7l"):
            assert setup.cloudflared_url().endswith("linux-arm"), "32-bit Pi must not get amd64"
        with patch("roc.setup.WINDOWS", False), patch("roc.setup.sys.platform", "darwin"):
            assert setup.cloudflared_url() is None, "darwin ships a .tgz we do not unpack"


def test_has_compiler_detects_partial_extraction(tmp_path):
    from roc import setup
    (tmp_path / "VC" / "bin").mkdir(parents=True)
    assert setup._has_compiler(tmp_path) is False
    (tmp_path / "VC" / "bin" / "cl.exe").write_bytes(b"MZ")
    assert setup._has_compiler(tmp_path) is True


def test_msi_admin_extract_prefers_wine_on_linux(tmp_path):
    from roc import setup
    target = tmp_path / "out"

    def fake_run(cmd, **kwargs):
        target.mkdir(parents=True, exist_ok=True)
        (target / "cl.exe").write_bytes(b"MZ")
        class Done:
            returncode = 0
            stdout = stderr = ""
        return Done()

    with patch("roc.setup.WINDOWS", False), \
         patch("roc.setup.ensure_wine_prefix", return_value=True), \
         patch("roc.setup.wine_exe", return_value="/usr/bin/wine"), \
         patch("roc.setup.subprocess.run", side_effect=fake_run) as run:
        setup.msi_admin_extract(tmp_path / "x.msi", target)
    assert run.call_args.args[0][:3] == ["/usr/bin/wine", "msiexec", "/a"]


def test_copy_from_iso_unix_extracts_one_file(tmp_path):
    from roc import setup
    iso = tmp_path / "dvd.iso"
    iso.write_bytes(b"iso")
    dest = tmp_path / "out" / "Ixpvc.exe"

    def fake_run(cmd, **kwargs):
        out = next((Path(part[2:]) for part in cmd if isinstance(part, str) and part.startswith("-o")), None)
        if out:
            found = out / "VCExpress" / "Ixpvc.exe"
            found.parent.mkdir(parents=True, exist_ok=True)
            found.write_bytes(b"MZ")

        class Done:
            returncode = 0
        return Done()

    with patch("roc.setup.shutil.which", side_effect=lambda name: "/usr/bin/7z" if name == "7z" else None), \
         patch("roc.setup.subprocess.run", side_effect=fake_run):
        setup.copy_from_iso_unix(iso, r"VCExpress\Ixpvc.exe", dest)
    assert dest.read_bytes() == b"MZ"


def test_wine_exe_honors_roc_wine_override():
    from roc import setup
    with patch.dict("os.environ", {"ROC_WINE": "/opt/box86-wine"}):
        assert setup.wine_exe() == "/opt/box86-wine"
    with patch.dict("os.environ", {"ROC_WINE": ""}), \
         patch("roc.setup.shutil.which", return_value="/usr/bin/wine"):
        assert setup.wine_exe() == "/usr/bin/wine"


def test_msi_string_pool_decodes_ids():
    from roc import setup
    # entry 0 is the codepage; later entries are (length, refcount) pairs, with an
    # empty entry still consuming a string id.
    pool = (struct.pack("<HH", 0, 0) + struct.pack("<HH", 4, 1) + struct.pack("<HH", 5, 1)
            + struct.pack("<HH", 0, 0) + struct.pack("<HH", 3, 1))
    strings, strref = setup._msi_strings(pool, b"NameTableabc")
    assert strref == 2
    assert strings[1] == "Name" and strings[2] == "Table"
    assert 3 not in strings and strings[4] == "abc"


def test_msi_table_rows_are_column_major():
    from roc import setup
    schema = setup.MSI_LAYOUT_TABLES["Directory"]  # three 2-byte string columns
    strings = {0: "", 1: "root", 2: "child", 3: "PARENT", 4: "sub", 5: "x"}
    raw = b"".join(struct.pack("<H", v) for v in [1, 2, 0, 3, 4, 5])
    rows = setup._msi_table_rows(raw, schema, strings, 2)
    assert rows[0] == {"Directory": "root", "Directory_Parent": "", "DefaultDir": "sub"}
    assert rows[1] == {"Directory": "child", "Directory_Parent": "PARENT", "DefaultDir": "x"}


def test_msi_schemas_take_widths_from_the_columns_table():
    from roc import setup
    # VS2008 stores the File table's numeric columns as i4 (including Sequence);
    # hardcoding i2 made the row size wrong and the 7z path silently fall back.
    rows = [
        {"Table": "File", "Number": 1, "Name": "File", "Type": 0x2D48},        # string
        {"Table": "File", "Number": 4, "Name": "FileSize", "Type": 0x0104},    # i4
        {"Table": "File", "Number": 7, "Name": "Attributes", "Type": 0x1502},  # i2
        {"Table": "File", "Number": 8, "Name": "Sequence", "Type": 0x0104},    # i4
        {"Table": "Directory", "Number": 1, "Name": "Directory", "Type": 0x2D48},
    ]
    schemas = setup._msi_schemas(rows, ["File", "Directory"])
    assert schemas["File"] == [("File", "s"), ("FileSize", "i4"),
                               ("Attributes", "i2"), ("Sequence", "i4")]
    assert schemas["Directory"] == [("Directory", "s")]


def test_msi_table_ignores_msiinfo_header_rows(tmp_path):
    from roc import setup
    # `msiinfo export` writes the column names, the column types, then the table
    # name plus its primary keys before the data. Those header lines have fewer
    # fields than a row and used to be read as data (KeyError: 'DefaultDir').
    out = ("Directory\tDirectory_Parent\tDefaultDir\r\n"
           "s72\ts72\tl255\r\n"
           "Directory\tDirectory\r\n"
           "root\t\tSourceDir\r\n"
           "child\troot\tsub\r\n")

    class Done:
        returncode = 0
        stdout = out
        stderr = ""

    with patch("roc.setup.subprocess.run", return_value=Done()):
        rows = setup.msi_table(tmp_path / "x.msi", "Directory")
    assert rows == [
        {"Directory": "root", "Directory_Parent": "", "DefaultDir": "SourceDir"},
        {"Directory": "child", "Directory_Parent": "root", "DefaultDir": "sub"},
    ]


def test_handoff_launch_command_off_windows():
    from roc import handoff
    with patch("roc.handoff.os.name", "posix"):
        command = handoff.launch_command()
    assert command[0] == sys.executable
    assert command[1].endswith("roc.py") and command[2] == "launch"


def test_link_install_is_a_noop_off_windows(capsys):
    from roc import link
    with patch("roc.link.os.name", "posix"):
        assert link.install() is False
        assert link.installed() is False
    assert "Windows-only" in capsys.readouterr().out