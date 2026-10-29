from pathlib import Path

from roc import libs, rebuild, setup


def test_shared_scan_matches_recursive_globs_and_preserves_order(tmp_path):
    tools=tmp_path/'tools'
    for name in ('a/version/VC/bin/cl.exe','z/deeper/version/VC/bin/cl.exe','not-a-compiler/cl.exe'):
        path=tools/name
        path.parent.mkdir(parents=True,exist_ok=True)
        path.write_text('fixture')
    for name in ('a/version/WinSDK/Include','z/version/WinSDK/Include','top-sdk/WinSDK/Include'):
        (tools/name).mkdir(parents=True)
    expected_compilers=tuple(sorted(tools.glob('*/**/VC/bin/cl.exe')))
    expected_sdks=tuple(sorted(tools.glob('*/**/WinSDK')))
    assert setup.toolchain_paths(tools)==(expected_compilers,expected_sdks)


def test_library_and_rebuild_sdk_share_one_scan(tmp_path,monkeypatch):
    tools=tmp_path/'tools'
    sdk=tools/'compiler/version/WinSDK'
    (sdk/'Include').mkdir(parents=True)
    monkeypatch.setattr(setup,'TOOLS',tools)
    original=setup.os.walk
    walks=[]
    def walk(path):
        walks.append(Path(path))
        return original(path)
    monkeypatch.setattr(setup.os,'walk',walk)
    assert libs.winsdk_include()==str(sdk/'Include')
    assert rebuild.sdk_roots(tools)==(sdk,)
    assert setup.toolchain_paths(tools)[1]==(sdk,)
    assert walks==[tools/'compiler']


def test_install_invalidates_shared_discovery_and_sdk_cache(tmp_path,monkeypatch):
    tools=tmp_path/'tools'
    tools.mkdir()
    monkeypatch.setattr(setup,'TOOLS',tools)
    assert rebuild.sdk_roots(tools)==()
    sdk=tools/'compiler/WinSDK'
    monkeypatch.setattr(setup,'missing_builds',lambda:[21022])
    monkeypatch.setattr(setup,'step_done',lambda _:False)
    monkeypatch.setitem(setup.FETCHERS,21022,lambda:(sdk/'Include').mkdir(parents=True))
    monkeypatch.setattr(setup,'mark_done',lambda *args,**kwargs:None)
    setup.install_compilers(assume_yes=True)
    assert libs.winsdk_include()==str(sdk/'Include')
    assert rebuild.sdk_roots(tools)==(sdk,)


def test_explicit_sdk_refresh_clears_shared_discovery(tmp_path,monkeypatch):
    tools=tmp_path/'tools'
    tools.mkdir()
    monkeypatch.setattr(setup,'TOOLS',tools)
    assert rebuild.sdk_roots(tools)==()
    sdk=tools/'compiler/WinSDK'
    (sdk/'Include').mkdir(parents=True)
    rebuild.sdk_roots.cache_clear()
    assert libs.winsdk_include()==str(sdk/'Include')
    assert rebuild.sdk_roots(tools)==(sdk,)
