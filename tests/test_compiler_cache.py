import hashlib

from roc import setup


def test_reuses_verified_sibling_iso_without_network(tmp_path, monkeypatch):
    root = tmp_path / 'RoConstruct-new'
    root.mkdir()
    cache = tmp_path / 'RoConstruct-old/tools/dl/DVD1.ISO'
    cache.parent.mkdir(parents=True)
    cache.write_bytes(b'verified compiler media')
    monkeypatch.setattr(setup, 'ROOT', root)
    monkeypatch.setattr(setup, 'DL', root / 'tools/dl')
    monkeypatch.setattr(setup, 'VS2008_SHA1', hashlib.sha1(cache.read_bytes()).hexdigest())
    monkeypatch.setattr(setup.Path, 'home', lambda: tmp_path)
    monkeypatch.delenv('ROC_DOWNLOAD_CACHE', raising=False)

    def no_network(*args, **kwargs):
        raise AssertionError('existing verified ISO must not be downloaded')

    monkeypatch.setattr(setup.urllib.request, 'urlopen', no_network)
    assert setup.download(setup.VS2008_URL, setup.DL / 'VS2008Express2007.iso') == cache
    assert not setup.DL.exists()


def test_rejects_wrong_hash_and_partial_cache(tmp_path, monkeypatch):
    root = tmp_path / 'RoConstruct'
    root.mkdir()
    cache = tmp_path / 'cache'
    cache.mkdir()
    invalid = cache / 'VC2005Express.iso'
    invalid.write_bytes(b'wrong media')
    partial = cache / 'Micorosft_Visual_C++_2005_Express.iso.part'
    partial.write_bytes(b'partial')
    monkeypatch.setattr(setup, 'ROOT', root)
    monkeypatch.setattr(setup, 'DL', root / 'tools/dl')
    monkeypatch.setattr(setup.Path, 'home', lambda: tmp_path)
    monkeypatch.setenv('ROC_DOWNLOAD_CACHE', str(cache))
    assert setup.cached_compiler_bundle(setup.VS2005_URL, setup.DL / invalid.name) is None
    assert invalid.read_bytes() == b'wrong media'
    assert partial.read_bytes() == b'partial'


def test_reuses_explicit_msi_cache_with_sha256(tmp_path, monkeypatch):
    root = tmp_path / 'RoConstruct'
    root.mkdir()
    cache = tmp_path / 'shared'
    cache.mkdir()
    msi = cache / 'VCForPython27.msi'
    msi.write_bytes(b'compiler msi')
    monkeypatch.setattr(setup, 'ROOT', root)
    monkeypatch.setattr(setup, 'DL', root / 'tools/dl')
    monkeypatch.setattr(setup.Path, 'home', lambda: tmp_path)
    monkeypatch.setattr(setup, 'VCPY_SHA256', hashlib.sha256(msi.read_bytes()).hexdigest())
    monkeypatch.setenv('ROC_DOWNLOAD_CACHE', str(cache))
    assert setup.cached_compiler_bundle(setup.VCPY_URL, setup.DL / msi.name) == msi
    assert setup.cached_compiler_bundle('https://example.com/unpinned.msi', setup.DL / msi.name) is None
