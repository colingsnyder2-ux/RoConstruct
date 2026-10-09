"""Deep-pass safety, prioritization and expansion without live compilers."""
import sqlite3
import json
from unittest.mock import patch

from roc import deep_fingerprint as deep


SOURCE = '// roc-lang: cpp\n// roc-cl: 21022\n// roc-flags: /O2 /GS- /EHsc /MD\n// roc-lib: xtp-11 Source/XTPReportControl.cpp'
RECIPE = {'src': 'xtp', 'langs': ['cpp'], 'builds': [21022, 30729]}


def test_flag_variants_preserve_abi_and_defines():
    source = SOURCE.replace('/O2 /GS-', '/O2 /Ob2 /Oy /GS- /DTEST=1')
    variants = list(deep.flag_variants(source))
    assert variants[0] == '/O2 /Ob2 /Oy /GS- /DTEST=1 /EHsc /MD'
    assert any('/O1' in flags for flags in variants)
    for flags in variants:
        assert '/GS-' in flags and '/DTEST=1' in flags and '/EHsc' in flags and '/MD' in flags
        assert len([flag for flag in flags.split() if flag.startswith('/Ob')]) == 1


def test_deep_expands_versions_builds_without_crossing_classes():
    db = sqlite3.connect(':memory:')
    db.execute('CREATE TABLE funcs(client,addr,unit,score,source)')
    db.executemany('INSERT INTO funcs VALUES(?,?,?,?,?)', [
        ('A', 'exact', 'CXTPReportControl', 100, SOURCE),
        ('B', 'high', 'CXTPReportControl', 99, SOURCE),
        ('B', 'lower', 'CXTPReportControl', 85, SOURCE),
        ('B', 'too_low', 'CXTPReportControl', 84, SOURCE),
        ('B', 'wrong_family', 'RBX::ReportControl', 99, SOURCE),
        ('B', 'wrong_class', 'CXTPReportRow', 99, SOURCE),
        ('B', 'unknown', 'seg_00400000', 99, SOURCE),
        ('B', 'subclass', 'CXTPDerivedReportControl', 99, SOURCE),
    ])
    with patch.object(deep, 'local_versions', return_value={('xtp', 'reportcontrol'): [('xtp-15', 'Source/XTPReportControl.cpp')]}), \
         patch.object(deep.libs, 'RECIPES', {'xtp-11': RECIPE, 'xtp-15': RECIPE}), \
         patch.object(deep.setup, 'compilers', return_value={21022: 'cl', 30729: 'cl'}), \
         patch.object(deep.clients, 'load', return_value={'B': {'compiler_build': 30729}}):
        planned = list(deep.plan(db))
    assert planned
    assert any('xtp-15 ' in source for _, source, _ in planned)
    assert 'xtp-15 ' in planned[1][1], 'sample another version before exhausting flags'
    assert any('// roc-cl: 30729' in source for _, source, _ in planned)
    assert all(client == 'B' and set(addrs) <= {'high', 'lower'} for client, _, addrs in planned)
    assert all(addrs == ['high', 'lower'] for _, _, addrs in planned)
    assert all(source != SOURCE for _, source, _ in planned)
    db.close()


def test_structural_family_overrides_wrong_exact_evidence():
    db = sqlite3.connect(':memory:')
    db.execute('CREATE TABLE funcs(client,addr,unit,score,source)')
    db.executemany('INSERT INTO funcs VALUES(?,?,?,?,?)', [
        ('A', 'exact', 'RBX::ReportControl', 100, SOURCE),
        ('B', 'target', 'RBX::ReportControl', 99, SOURCE),
    ])
    with patch.object(deep, 'local_versions', return_value={}), \
         patch.object(deep.setup, 'compilers', return_value={}), \
         patch.object(deep.clients, 'load', return_value={}):
        assert list(deep.plan(db)) == []
    db.close()


def test_runner_is_bounded_verified_and_checkpoints_pairs(tmp_path):
    (tmp_path / 'work').mkdir()
    sqlite3.connect(tmp_path / 'work/server.db').close()
    candidate = SOURCE.replace('/O2', '/O1')
    with patch.object(deep, 'ROOT', tmp_path), \
         patch.object(deep, 'plan', return_value=iter([('B', candidate, ['00400000']), ('B', candidate, ['00400010'])])), \
         patch.object(deep.worker, 'load_settings', return_value={'user': 'tester'}), \
         patch.object(deep.worker, 'Api') as api, \
         patch('sys.argv', ['deep', '--max-batches', '1']):
        api.return_value.call.return_value = {'verified': True, 'results': [
            {'addr': '00400000', 'score': 100, 'stored': 100, 'improved': True}]}
        deep.main()
        assert api.return_value.call.call_count == 1
        assert api.return_value.call.call_args.args[1]['model'] == 'roc deep fingerprint'
    state = json.loads((tmp_path / 'work/deep-fingerprint.json').read_text())
    assert state['last_run']['unique_improved'] == 1
    assert state['last_run']['new_exact'] == 1
    assert state['checked'][deep.key('B', candidate, [])] == ['00400000']
    assert len(state['done']) == 1
