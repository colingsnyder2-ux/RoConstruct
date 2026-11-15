import importlib.util
from pathlib import Path


def load_discovery():
    path = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_target_discovery.py'
    spec = importlib.util.spec_from_file_location('native_target_discovery', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_discovery_keeps_unverified_identities_out_of_exact_progress(tmp_path, monkeypatch):
    discovery = load_discovery()
    monkeypatch.setattr(discovery, 'ROOT', tmp_path)
    source = tmp_path / 'rebuild/2008-06/native-classes/G3DTexture.cpp'
    source.parent.mkdir(parents=True)
    source.touch()
    symbol = '?load@Texture@G3D@@QAEXXZ'
    data = {'units': ['G3D::Texture', 'Other'], 'funcs': [
        [0x401000, 100, 100, 0, True, ['g3d-6.09', 'Texture.cpp', symbol]],
        [0x401100, 100, 100, 1, True, ['g3d-6.09', 'Texture.cpp', symbol]],
        [0x401200, 100, 100, 0, True, ['g3d-6.09', 'Texture.cpp', symbol]],
    ]}
    inactive = {'00401200': ['prior', True]}
    safe = discovery.discover(data, 'G3D', 'G3D', inactive)
    broad = discovery.discover(data, 'G3D', 'G3D', inactive, include_analogs=True)
    assert [r['addr'] for r in safe['jobs'][0]['checks']] == ['00401000']
    assert [r['addr'] for r in broad['jobs'][0]['checks']] == ['00401000', '00401100']
    assert all(r['review_only'] for r in broad['jobs'][0]['checks'])
