"""Installer shell failures must not masquerade as unsigned downloads."""
import os
from pathlib import Path
from types import SimpleNamespace

import pytest
from roc import setup


def test_shell_failure_reports_the_actual_error(monkeypatch):
    monkeypatch.setattr(setup.subprocess, "run", lambda *args, **kwargs: SimpleNamespace(
        returncode=1, stdout="|", stderr="Security module could not load\nadditional diagnostics"))
    with pytest.raises(SystemExit, match="Security module could not load"):
        setup.powershell("Get-AuthenticodeSignature")


@pytest.mark.skipif(os.name != "nt", reason="Windows PowerShell integration")
def test_signature_check_ignores_incompatible_parent_module_path(tmp_path, monkeypatch):
    module = tmp_path / "Microsoft.PowerShell.Security"
    module.mkdir()
    (module / "Microsoft.PowerShell.Security.psd1").write_text(
        "@{ModuleVersion='99.0';RootModule='missing-incompatible.dll'}")
    monkeypatch.setenv("PSModulePath", str(tmp_path))
    executable = Path(os.environ["SystemRoot"]) / "System32/WindowsPowerShell/v1.0/powershell.exe"
    result = setup.powershell("(Get-AuthenticodeSignature -LiteralPath '%s').Status" % executable)
    assert result == "Valid"


def test_iso_extraction_uses_installed_reader_when_disk_images_are_broken(tmp_path, monkeypatch):
    program_files = tmp_path / "Program Files"
    reader = program_files / "7-Zip" / "7z.exe"
    reader.parent.mkdir(parents=True)
    reader.write_bytes(b"reader")
    monkeypatch.setenv("ProgramFiles", str(program_files))
    monkeypatch.setattr(setup, "WINDOWS", True)
    monkeypatch.setattr(setup.shutil, "which", lambda name: None)
    monkeypatch.setattr(setup, "powershell", lambda command: pytest.fail("Disk-image service is unavailable"))

    def extract(command, **kwargs):
        assert command[0] == str(reader)
        output = Path(next(arg[2:] for arg in command if arg.startswith("-o")))
        selected = output / "VCExpress" / "Ixpvc.exe"
        selected.parent.mkdir()
        selected.write_bytes(b"compiler setup")
        return SimpleNamespace(returncode=0)

    monkeypatch.setattr(setup.subprocess, "run", extract)
    destination = tmp_path / "out" / "Ixpvc.exe"
    setup.copy_from_iso(tmp_path / "dvd.iso", r"VCExpress\Ixpvc.exe", destination)
    assert destination.read_bytes() == b"compiler setup"
