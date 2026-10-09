"""Library configurations must replay their own preprocessed declarations."""
from unittest.mock import patch
import subprocess

from roc import libs


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
            patch.object(libs.setup, 'cl_env', return_value={'CL': ''}), \
            patch.object(libs.setup, 'cl_command', return_value=['cl']), \
            patch.object(libs.setup, 'cl_path', side_effect=str), \
            patch.object(libs.subprocess, 'run', side_effect=fake_run):
        libs.preprocess(30729, tmp_path / 'x.cpp', 'inc', '_AFXDLL _DLL')
    assert '/D_AFXDLL' in seen['cl'] and '/D_DLL' in seen['cl']
    assert '/MD' in seen['cl'] and '/MT' not in seen['cl']
