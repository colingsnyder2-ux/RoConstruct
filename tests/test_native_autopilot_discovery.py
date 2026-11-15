import importlib.util
import json
from pathlib import Path


def load_discovery():
    path = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_autopilot_discovery.py'
    spec = importlib.util.spec_from_file_location('native_autopilot_discovery', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def setup_discovery(tmp_path, monkeypatch, files):
    discovery = load_discovery()
    (tmp_path / 'docs/data').mkdir(parents=True)
    native = tmp_path / 'rebuild/2008-06/native-classes'
    native.mkdir(parents=True)
    for name in files:
        (native / (name + '.cpp')).touch()
    monkeypatch.setattr(discovery, '_tracked_sources', lambda root: {
        p.stem.casefold(): [p.resolve()] for p in native.glob('*.cpp')
    })
    monkeypatch.setattr(discovery, '_inactive', lambda root: {})
    from roc import libs
    monkeypatch.setattr(libs, 'RECIPES', {'g3d-6.09': {}, 'xtp-11.2.2': {}})
    return discovery


def write_data(root, funcs, units=None):
    path = root / 'docs/data/2008-06.json'
    path.write_text(json.dumps({'funcs': funcs, 'units': units or ['G3D::Texture']}), encoding='utf-8')


def test_discovers_known_library_sources_review_only_and_dedupes(tmp_path, monkeypatch):
    discovery = setup_discovery(tmp_path, monkeypatch, ['G3DTexture', 'XTPReportControl'])
    g3d_symbol = '?load@Texture@G3D@@QAEXXZ'
    xtp_symbol = '?Create@CXTPReportControl@@QAEHXZ'
    write_data(tmp_path, [
        [0x401000, 96, 100, 0, True, ['g3d-6.09', 'Texture.cpp', g3d_symbol]],
        [0x401000, 96, 100, 0, True, ['g3d-6.09', 'Texture.cpp', g3d_symbol]],
        [0x401100, 80, 100, 0, True, ['xtp-11.2.2', 'XTPReportControl.cpp', xtp_symbol]],
    ])

    result = discovery.discover(tmp_path)

    assert [(Path(job['source']).name, [c['addr'] for c in job['checks']]) for job in result['jobs']] == [
        ('G3DTexture.cpp', ['00401000']), ('XTPReportControl.cpp', ['00401100'])]
    checks = [check for job in result['jobs'] for check in job['checks']]
    assert all(check['review_only'] for check in checks)
    assert len(checks[0]['provenance']) == 1
    assert checks[0]['provenance'][0]['recipe_source'] == 'Texture.cpp'
    assert result['issues'] == []


def test_excludes_receipt_backed_exact_and_keeps_unproven_candidate(tmp_path, monkeypatch):
    discovery = setup_discovery(tmp_path, monkeypatch, ['G3DTexture'])
    monkeypatch.setattr(discovery, '_inactive', lambda root: {
        '00401000': ['old-symbol', True], '00401100': ['draft', False],
    })
    symbol = '?load@Texture@G3D@@QAEXXZ'
    write_data(tmp_path, [
        [0x401000, 96, 100, 0, True, ['g3d-6.09', 'Texture.cpp', symbol]],
        [0x401100, 96, 100, 0, True, ['g3d-6.09', 'Texture.cpp', symbol]],
    ])

    result = discovery.discover(tmp_path)

    assert [c['addr'] for c in result['jobs'][0]['checks']] == ['00401100']
    assert result['jobs'][0]['checks'][0]['review_only'] is True


def test_reports_source_ambiguity_and_cross_source_identity_conflict(tmp_path, monkeypatch):
    discovery = setup_discovery(tmp_path, monkeypatch, ['G3DTexture', 'Texture'])
    monkeypatch.setattr(discovery, '_tracked_sources', lambda root: {
        'g3dtexture': [(tmp_path / 'rebuild/2008-06/native-classes/G3DTexture.cpp').resolve()],
        'texture': [(tmp_path / 'rebuild/2008-06/native-classes/Texture.cpp').resolve()],
    })
    symbol = '?load@Texture@G3D@@QAEXXZ'
    write_data(tmp_path, [
        [0x401000, 96, 100, 0, True, ['g3d-6.09', 'Texture.cpp', symbol]],
        [0x401000, 96, 100, 0, True, ['g3d-6.09', 'G3DTexture.cpp', symbol]],
    ])

    result = discovery.discover(tmp_path)

    assert result['jobs'] == []
    assert any(issue['reason'] == 'identity_conflict' for issue in result['issues'])


def test_ignores_unknown_recipe_even_if_symbol_and_source_name_match(tmp_path, monkeypatch):
    discovery = setup_discovery(tmp_path, monkeypatch, ['G3DTexture'])
    write_data(tmp_path, [[0x401000, 96, 100, 0, True,
                           ['unreviewed-recipe', 'Texture.cpp', '?load@Texture@G3D@@QAEXXZ']]])

    result = discovery.discover(tmp_path)

    assert result == {'jobs': [], 'issues': [], 'inventory': {}}


def test_small_mismatches_are_inventoried_not_skipped(tmp_path, monkeypatch):
    discovery = setup_discovery(tmp_path, monkeypatch, ['G3DTexture'])
    write_data(tmp_path, [[0x401000, 8, 23.75, 0, True,
                           ['g3d-6.09', 'Texture.cpp', '?load@Texture@G3D@@QAEXXZ']]])
    result = discovery.discover(tmp_path)
    assert result['jobs'][0]['checks'][0]['addr'] == '00401000'
    assert result['inventory']['g3d-6.09']['candidates'] == 1
