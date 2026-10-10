import pytest
import json

from benchmarks import library_branches
from benchmarks.library_branches import combination, numeric_variants, optimization_variants, recipe_variants, stage_lock, variants
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


def test_combo_codegen_includes_anonymous_targets_preserves_proven_flags(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches, 'ROOT', tmp_path)
    source = '// roc-cl: 21022\n// roc-flags: /O2 /GS /EHsc /MD\n'
    monkeypatch.setattr(library_branches, 'winning_sources', lambda **kwargs: [(source, 10)] if kwargs['combination_only'] else [])
    monkeypatch.setattr(library_branches, 'live', lambda campaign: {'c': {}})
    monkeypatch.setattr(library_branches, 'reserved_shapes', lambda: {'reserved'})
    monkeypatch.setattr(match, '_functions', lambda client: {
        'named': {'kind': 'code', 'size': 20, 'unit': 'CXTExample'},
        'anonymous': {'kind': 'code', 'size': 20},
        'excluded': {'kind': 'code', 'size': 20, 'shape': 'reserved'},
    })

    class CampaignStub:
        info = {'clients': {'c': {}}}

        def previous(self, stage):
            return []

        def record(self, stage, row):
            pass

    plans = library_branches.build_manifest(CampaignStub(), 'combo-codegen')
    assert len(plans) == 2
    for plan in plans:
        assert set(plan['rows']) == {'named', 'anonymous'}
        flags = match.directives(plan['source'])['flags'].split()
        assert all(v in flags for v in ['/GS', '/EHsc', '/MD', '/O2'])


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


def test_optimization_variants_keep_abi_and_remove_conflicting_flags():
    source = '// roc-flags: /O2 /GS /EHsc /MD /Gd /Ot /GF\n'
    trials = list(optimization_variants(source))
    assert len(trials) == 3
    for _, trial in trials:
        flags = match.directives(trial)['flags'].split()
        assert all(v in flags for v in ['/GS', '/EHsc', '/MD', '/Gd'])
        assert not ('/O1' in flags and '/O2' in flags)
        assert not ('/Os' in flags and '/Ot' in flags)
        assert not ('/GF' in flags and '/GF-' in flags)


def test_newfiles_require_unresolved_class_evidence(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches.libs, 'LIBS', tmp_path)
    monkeypatch.setattr(library_branches.libs, 'RECIPES', {'xtp-example': {'src': 'example', 'files': ['XTPKnown.cpp', 'XTPNew.cpp', 'XTPAbsent.cpp']}})
    folder = tmp_path / 'example'
    folder.mkdir()
    for name in ['XTPKnown.cpp', 'XTPNew.cpp', 'XTPAbsent.cpp']:
        (folder / name).write_text('void f() {}')
    source = '// roc-cl: 21022\n// roc-lang: cpp\n// roc-flags: /O2 /GS /EHsc /MD\n// roc-lib: xtp-example XTPKnown.cpp\n'
    monkeypatch.setattr(library_branches, 'winning_sources', lambda **kwargs: [(source, 10)])
    monkeypatch.setattr(library_branches, 'live', lambda campaign: {'c': {'exact': {'score': 100}}})
    monkeypatch.setattr(library_branches, 'reserved_shapes', lambda: {'reserved'})
    monkeypatch.setattr(match, '_functions', lambda client: {
        'new': {'kind': 'code', 'unit': 'CXTPNew'},
        'known': {'kind': 'code', 'unit': 'CXTPKnown'},
        'exact': {'kind': 'code', 'unit': 'CXTPAbsent'},
        'reserved': {'kind': 'code', 'unit': 'CXTPAbsent', 'shape': 'reserved'},
    })
    campaign = type('CampaignStub', (), {'info': {'clients': {'c': {}}}})()
    sources = library_branches.untested_files(campaign)
    assert len(sources) == 1
    candidate, support = sources[0]
    assert support == 1
    assert match.directives(candidate)['lib'] == 'xtp-example XTPNew.cpp'
    assert match.directives(candidate)['flags'] == '/O2 /GS /EHsc /MD'


def test_diverse_pilot_checks_twelve_new_files_across_all_clients(tmp_path, monkeypatch):
    monkeypatch.setattr(library_branches, 'ROOT', tmp_path)
    sources = [('// roc-flags: /O2 /GS /EHsc /MD\n// roc-lib: xtp-example File%d.cpp\n' % i, 100 - i) for i in range(16)]
    (tmp_path / 'combo-newfiles-manifest.json').write_text(json.dumps({'groups': [{'source': sources[0][0]}]}))
    monkeypatch.setattr(library_branches, 'winning_sources', lambda **kwargs: [])
    monkeypatch.setattr(library_branches, 'untested_files', lambda campaign: sources)
    monkeypatch.setattr(library_branches, 'live', lambda campaign: {c: {} for c in campaign.info['clients']})
    monkeypatch.setattr(library_branches, 'reserved_shapes', lambda: set())
    monkeypatch.setattr(match, '_functions', lambda client: {'a': {'kind': 'code', 'size': 20}})

    class CampaignStub:
        info = {'clients': {str(i): {} for i in range(7)}}

        def previous(self, stage):
            return []

        def record(self, stage, row):
            pass

    plans = library_branches.build_manifest(CampaignStub(), 'combo-newfiles-diverse')
    pilot = plans[:84]
    assert len(pilot) == 84
    assert len({p['source'] for p in pilot}) == 12
    assert all(p['source'] != sources[0][0] for p in plans)
    for source in {p['source'] for p in pilot}:
        assert len({p['client'] for p in pilot if p['source'] == source}) == 7


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
