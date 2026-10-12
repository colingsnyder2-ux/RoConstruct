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
