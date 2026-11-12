from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import shutil
import threading

import pytest

from roc import libs, rebuild


def tree_fixture(tmp_path, monkeypatch):
    source = tmp_path / 'vendor'
    source.mkdir()
    (source / 'unit.cpp').write_text('int f(){return 1;}')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path / 'private')
    monkeypatch.setattr(libs, 'LIBS', tmp_path)
    monkeypatch.setitem(libs.RECIPES, 'test-tree', {
        'src': 'vendor', 'patches': {'unit.cpp': [['return 1;', 'return 2;']]}})
    return source


def test_patched_tree_retries_windows_directory_lock_without_recopy(tmp_path, monkeypatch):
    source = tree_fixture(tmp_path, monkeypatch)
    rename = Path.rename
    calls = []
    def locked_once(path, target):
        calls.append(path)
        if len(calls) == 1:
            error = PermissionError('scanner has directory open')
            error.winerror = 5
            raise error
        return rename(path, target)
    monkeypatch.setattr(Path, 'rename', locked_once)
    monkeypatch.setattr(rebuild.time, 'sleep', lambda _: None)
    tree = rebuild.patched_tree('2008-06', 'test-tree')
    assert len(calls) == 2 and calls[0] == calls[1]
    assert (tree / 'unit.cpp').read_text() == 'int f(){return 2;}'
    assert (source / 'unit.cpp').read_text() == 'int f(){return 1;}'
    assert rebuild.patched_tree('2008-06', 'test-tree') == tree
    assert len(calls) == 2


def test_concurrent_tree_builders_do_not_delete_each_others_temporary_source(tmp_path, monkeypatch):
    tree_fixture(tmp_path, monkeypatch)
    copy = shutil.copytree
    barrier = threading.Barrier(2)
    temporary = []
    def copying(source, target, **kwargs):
        result = copy(source, target, **kwargs)
        temporary.append(target)
        barrier.wait(timeout=5)
        return result
    monkeypatch.setattr(shutil, 'copytree', copying)
    with ThreadPoolExecutor(2) as pool:
        results = list(pool.map(lambda _: rebuild.patched_tree('2008-06', 'test-tree'), range(2)))
    assert results[0] == results[1]
    assert len(set(temporary)) == 2
    assert (results[0] / 'unit.cpp').read_text() == 'int f(){return 2;}'


def test_real_permissions_failure_stays_visible_with_diagnostic_copy(tmp_path, monkeypatch):
    tree_fixture(tmp_path, monkeypatch)
    def denied(*_):
        raise PermissionError('permanent access denial')
    monkeypatch.setattr(Path, 'rename', denied)
    with pytest.raises(PermissionError, match='permanent'):
        rebuild.patched_tree('2008-06', 'test-tree')
    copies = list((rebuild.workspace('2008-06') / 'out/trees').glob('*.tmp'))
    assert len(copies) == 1
    assert (copies[0] / 'unit.cpp').read_text() == 'int f(){return 2;}'


def test_private_build_skips_public_progress_scan(monkeypatch):
    monkeypatch.setenv('ROC_INTEGRATOR_PRIVATE', '1')
    monkeypatch.setattr(rebuild, 'workspace', lambda _: pytest.fail('private build scanned public progress'))
    assert rebuild.progress() is None
