import pytest
import json

from benchmarks import library_branches
from benchmarks.library_branches import combination, numeric_variants, recipe_variants, stage_lock, variants
from roc import match


def test_library_variants_change_one_group_preserving_pins():
    source = '// roc-lang: cpp\n// roc-cl: 21022\n// roc-flags: /O2 /GS- /MD\n// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPVC80Helpers.cpp\n'
    trials = list(variants(source))
    assert len(trials) == 4
    for reason, trial in trials:
        d = match.directives(trial)
        assert reason
        assert d['cl'] == '21022' and d['lang'] == 'cpp'
        assert d['lib'] == match.directives(source)['lib']
        assert '/MD' in d['flags'] and '/O2' in d['flags']
        assert not ('/GS ' in d['flags'] and '/GS-' in d['flags'])


def test_existing_settings_not_repeated():
    source = '// roc-flags: /O2 /GS /MD /EHsc /Oy- /Ob2\n'
    assert list(variants(source)) == []


def test_stage_lock_prevents_duplicate_worker(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches, 'ROOT', tmp_path)
    with stage_lock('pilot'):
        with pytest.raises(OSError):
            with stage_lock('pilot'):
                raise AssertionError('second worker acquired same stage')
    with stage_lock('pilot'):
        pass


def test_combination_preserves_non_experiment_options():
    source = '// roc-cl: 21022\n// roc-flags: /O2 /GS- /MD /GF /EHa\n'
    d = match.directives(combination(source))
    assert d['cl'] == '21022'
    assert d['flags'] == '/O2 /MD /GF /GS /EHsc'


def test_transfer_keeps_parent_manifest_and_deduplicates_plans(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches, 'ROOT', tmp_path)
    parent = tmp_path / 'settings-combination-manifest.json'
    parent.write_text(json.dumps({'targets': {'c': ['a']}, 'groups': []}))
    before = parent.read_bytes()
    source = '// roc-cl: 21022\n// roc-flags: /O2 /GS- /MD\n'
    monkeypatch.setattr(library_branches, 'winning_sources', lambda **kwargs: [(source, 2), (source, 2)])
    monkeypatch.setattr(library_branches, 'live', lambda campaign: {'c': {}})
    monkeypatch.setattr(library_branches, 'reserved_shapes', lambda: set())
    monkeypatch.setattr(match, '_functions', lambda client: {'a': {'kind': 'code', 'size': 20, 'unit': 'CXTExample'}})

    class CampaignStub:
        info = {'clients': {'c': {}}}

        def previous(self, stage):
            return []

        def record(self, stage, row):
            pass

    plans = library_branches.build_manifest(CampaignStub(), 'combo-transfer')
    assert len(plans) == 1
    assert parent.read_bytes() == before
    assert (tmp_path / 'combo-transfer-manifest.json').exists()


def test_numeric_flags_preserve_cookie_exception_and_abi():
    source = '// roc-flags: /O2 /GS /EHsc /MD /Gd /Oi-\n'
    trials = list(numeric_variants(source))
    assert len(trials) == 2
    for _, trial in trials:
        flags = match.directives(trial)['flags'].split()
        assert all(v in flags for v in ['/GS', '/EHsc', '/MD', '/Gd'])
        assert not ('/Oi' in flags and '/Oi-' in flags)


def test_recipe_neighbors_require_installed_same_path(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches.libs, 'LIBS', tmp_path)
    monkeypatch.setattr(library_branches.libs, 'RECIPES', {
        'xtp-old-shared-mfc': {'src': 'old'},
        'xtp-other-shared-mfc': {'src': 'other'},
        'xtp-missing-shared-mfc': {'src': 'missing'},
    })
    (tmp_path / 'other').mkdir()
    (tmp_path / 'other' / 'unit.cpp').write_text('void f() {}')
    source = '// roc-cl: 21022\n// roc-flags: /O2 /GS /EHsc /MD\n// roc-lib: xtp-old-shared-mfc unit.cpp\n'
    trials = list(recipe_variants(source))
    assert len(trials) == 1
    d = match.directives(trials[0][1])
    assert d['lib'] == 'xtp-other-shared-mfc unit.cpp'
    assert d['cl'] == '21022' and d['flags'] == '/O2 /GS /EHsc /MD'
