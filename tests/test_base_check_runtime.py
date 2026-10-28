import importlib.util
import subprocess
from pathlib import Path
from types import SimpleNamespace

import pytest


@pytest.mark.parametrize('output,code,error', [
    ('0 0\n1 4\n', 0, None),
    ('', 0xc0000005, '0xC0000005'),
    ('', 0, 'Incomplete probe output'),
    ('0 0\n', 0, 'Incomplete probe output'),
    ('unexpected output\n', 0, 'Invalid probe output'),
    (None, 0, 'timed out'),
])
def test_base_probe_reports_runtime_failure_without_inventing_offsets(tmp_path, monkeypatch, output, code, error):
    spec = importlib.util.spec_from_file_location('base_check_runtime',
        Path(__file__).resolve().parents[1] / 'rebuild/2008-06/base_check.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setitem(module.libs.RECIPES, 'rbxgs', {})
    monkeypatch.setattr(module.libs, 'fetch', lambda _: tmp_path)
    monkeypatch.setattr(module.setup, 'WINDOWS', True)
    def build(tc, tool, args, folder):
        if tool == 'link':
            (folder / 'probe.exe').touch()
        return 0, ''
    monkeypatch.setattr(module.rebuild, 'run', build)
    def run(*args, **kwargs):
        if output is None:
            raise subprocess.TimeoutExpired(args[0], kwargs['timeout'])
        return SimpleNamespace(returncode=code, stdout=output, stderr='')
    monkeypatch.setattr(module.subprocess, 'run', run)
    offsets, diagnostic = module.probe('gui/ScoreHud.h',
        [('ScoreHud', 'GuiItem', 0), ('ScoreHud', 'Instance', 4)], tmp_path, {})
    if error:
        assert offsets is None and error in diagnostic
    else:
        assert offsets == {0: 0, 1: 4} and diagnostic is None
