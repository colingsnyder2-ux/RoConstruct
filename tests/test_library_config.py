"""Library configurations must replay their own preprocessed declarations."""
from unittest.mock import patch
import subprocess

from roc import libs


def test_compile_directory_is_writable_and_cleaned_on_failure():
    from pathlib import Path
    import pytest
    from roc import match
    with pytest.raises(RuntimeError):
        with match.compile_directory() as directory:
            path = Path(directory)
            (path / "f.cpp").write_text("int f() { return 1; }")
            assert (path / "f.cpp").read_text() == "int f() { return 1; }"
            raise RuntimeError("failed compile")
    assert not path.exists()


def test_shared_mfc_recipe_uses_real_macros_and_dynamic_crt():
    recipe = libs.RECIPES['xtp-11.2.2-shared-mfc']
    assert recipe['src'] == libs.RECIPES['xtp-11.2.2']['src']
    assert set(recipe['defines'].split()) == {'_AFXDLL', '_XTP_STATICLINK', '_DLL'}
    assert all('/MD' in flags.split() and '/MT' not in flags.split() for flags in recipe['grid'])
    assert 'defines' not in libs.RECIPES['xtp-11.2.2']
    mfc = libs.RECIPES['mfc-9.0-shared']
    assert set(mfc['defines'].split()) == {'_AFXDLL', '_DLL'}
    assert mfc['src'] == libs.RECIPES['mfc-9.0']['src']
    assert libs.RECIPES['xtp-13.2.1-shared-mfc']['src'] == 'xtp-13.2.1'
    assert libs.RECIPES['xtp-11.2.2-vc8-shared-mfc']['builds'] == [50727]
    assert libs.RECIPES['xtp-15.2.1-shared-mfc']['src'] == 'xtp-15.2.1'


def test_macro_configuration_has_separate_preprocessing_cache(tmp_path):
    folder = tmp_path / 'vendor'
    folder.mkdir()
    (folder / 'test.cpp').write_text('int f() { return 1; }')
    with patch.object(libs, 'ROOT', tmp_path), patch.object(libs, 'fetch', return_value=folder), \
            patch.object(libs, 'winsdk_include', return_value='sdk'), \
            patch.object(libs, 'preprocess', side_effect=['static declarations', 'shared declarations']) as preprocess:
        assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'static declarations'
        assert libs.unit('xtp-11.2.2-shared-mfc', 'test.cpp', 30729) == 'shared declarations'
        assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'static declarations'
        assert libs.unit('xtp-11.2.2-shared-mfc', 'test.cpp', 30729) == 'shared declarations'
    assert preprocess.call_count == 2
    assert preprocess.call_args_list[0].args[3] == ''
    assert preprocess.call_args_list[1].args[3] == '_AFXDLL _XTP_STATICLINK _DLL'


def test_preprocessed_unit_tracks_real_header_contents(tmp_path, monkeypatch):
    folder = tmp_path / 'vendor'
    folder.mkdir()
    (folder / 'test.cpp').write_text('#include "h.h"\n')
    header = folder / 'h.h'
    header.write_text('#define X 1\n')
    calls = []

    def preprocess(build, path, include, defines, deps):
        calls.append(path)
        deps.append(str(header))
        return 'int x = %s;' % header.read_text().split()[-1]

    monkeypatch.setattr(libs, 'ROOT', tmp_path)
    monkeypatch.setattr(libs, 'fetch', lambda name: folder)
    monkeypatch.setattr(libs, 'winsdk_include', lambda: 'sdk')
    monkeypatch.setattr(libs, 'preprocess', preprocess)
    assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'int x = 1;'
    header.touch()  # same content, new timestamp: still a hit
    assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'int x = 1;'
    assert len(calls) == 1
    header.write_text('#define X 2\n')  # edited vendor header: rebuilt, not replayed
    assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'int x = 2;'
    assert len(calls) == 2
    monkeypatch.setitem(libs.RECIPES['xtp-11.2.2'], 'defines', '_CHANGED')  # recipe edit: rebuilt
    assert libs.unit('xtp-11.2.2', 'test.cpp', 30729) == 'int x = 2;'
    assert len(calls) == 3


def test_compile_errors_are_keyed_on_expanded_library_text(tmp_path, monkeypatch):
    from roc import match
    body = {'text': 'broken'}
    monkeypatch.setattr(libs, 'unit', lambda *a: body['text'])
    monkeypatch.setattr(match, 'COMPILE_ERRORS', tmp_path / 'errors.json')
    monkeypatch.setattr(match, '_COMPILE_ERRORS', {})
    runs = []

    def fake_run(argv, **kw):
        runs.append(argv)
        source = [a for a in argv if a.endswith('f.cpp')][0]
        bad = 'broken' in open(source).read()
        if not bad:
            open([a[3:] for a in argv if a.startswith('/Fo')][0], 'wb').write(b'OBJ')
        return subprocess.CompletedProcess(argv, int(bad), '', 'error C2143' if bad else '')

    monkeypatch.setattr(match.setup, 'compilers', lambda: {21022: 'cl'})
    monkeypatch.setattr(match.setup, 'cl_env', lambda cl: {})
    monkeypatch.setattr(match.setup, 'cl_command', lambda cl: ['cl'])
    monkeypatch.setattr(match.setup, 'cl_path', str)
    monkeypatch.setattr(match.subprocess, 'run', fake_run)
    match.compile_text.cache_clear()
    text = '// roc-cl: 21022\n// roc-flags: /O2\n// roc-lib: xtp-11.2.2 test.cpp\n'
    for _ in range(2):
        try:
            match.compile_text('2008-06', text)
        except match.CompileError:
            pass
    assert len(runs) == 1  # unchanged expansion: remembered error, no recompile
    body['text'] = 'fixed'
    assert match.compile_text('2008-06', text) == b'OBJ'  # changed header text: no stale error
    assert len(runs) == 2
    match.compile_text.cache_clear()


def test_shared_mfc_source_descriptor_preserves_configuration():
    source = libs.source_for('xtp-11.2.2-shared-mfc',
                            'Source/ReportControl/XTPReportControl.cpp', 'cpp', 30729, '/O2 /GS- /MD')
    assert '// roc-lib: xtp-11.2.2-shared-mfc Source/ReportControl/XTPReportControl.cpp' in source


def test_shared_preprocess_forces_md_when_macro_env_has_no_runtime_flag(tmp_path):
    seen = {}
    def fake_run(argv, **kwargs):
        seen['cl'] = kwargs['env']['CL']
        return subprocess.CompletedProcess(argv, 0, 'int x;', '')
    with patch.object(libs.setup, 'compilers', return_value={30729: 'cl'}), \
            patch.object(libs.setup, 'cl_env', return_value={'CL': '', 'INCLUDE': ''}), \
            patch.object(libs.setup, 'cl_command', return_value=['cl']), \
            patch.object(libs.setup, 'cl_path', side_effect=str), \
            patch.object(libs.subprocess, 'run', side_effect=fake_run):
        libs.preprocess(30729, tmp_path / 'x.cpp', 'inc', '_AFXDLL _DLL')
    assert '/D_AFXDLL' in seen['cl'] and '/D_DLL' in seen['cl']
    assert '/MD' in seen['cl'] and '/MT' not in seen['cl']


def test_fetch_units_merges_downloads_and_keeps_local_additions(tmp_path, monkeypatch):
    import json
    remote = tmp_path / "remote.json"
    remote.write_text(json.dumps({"vendor/src": {"roc_a.cpp": "shared", "roc_b.cpp": "also shared"}}))
    cache = tmp_path / "local" / "units" / "generated-units.json"
    cache.parent.mkdir(parents=True)
    cache.write_text(json.dumps({"vendor/src": {"roc_b.cpp": "local copy wins", "roc_c.cpp": "mine"}}))
    monkeypatch.setattr(libs, "UNITS_FILE", cache)
    logs = []
    assert libs.fetch_units(logs.append, remote.as_uri()) == 1
    merged = json.loads(cache.read_text())["vendor/src"]
    assert merged == {"roc_a.cpp": "shared", "roc_b.cpp": "local copy wins", "roc_c.cpp": "mine"}
    assert libs.fetch_units(logs.append, (tmp_path / "missing.json").as_uri()) == 0  # offline: no error
    assert "using the local copy" in logs[-1] and json.loads(cache.read_text())["vendor/src"] == merged
