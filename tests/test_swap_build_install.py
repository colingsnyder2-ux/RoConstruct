import importlib.util
import json
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
script = ROOT / "rebuild/2008-06/swap_build.py"
if not script.is_file():
    pytest.skip("Legacy rebuild script requires the separate findings checkout", allow_module_level=True)
spec = importlib.util.spec_from_file_location("swap_build", script)
swap_build = importlib.util.module_from_spec(spec)
spec.loader.exec_module(swap_build)


def layer(folder, addrs):
    folder.mkdir(parents=True)
    (folder / "swaps.json").write_text(json.dumps({"swaps": [{"obj": "0000.obj", "keep": {"s%s" % a: a for a in addrs}}]}))
    (folder / "0000.obj").write_bytes(b"obj")


def test_new_layer_installed_only_when_it_loses_nothing_and_gains(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a", "b"])
    layer(built, ["a"])  # loses b
    assert "kept existing" in swap_build.install(live, built)
    assert swap_build.kept_addresses(live) == {"a", "b"} and not built.exists()
    layer(built, ["a", "b", "c"])
    assert "installed" in swap_build.install(live, built)
    assert swap_build.kept_addresses(live) == {"a", "b", "c"}
    assert not built.exists() and not (tmp_path / "verified.old").exists()


def test_first_layer_installs_when_none_exists(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(built, ["a"])
    assert "installed" in swap_build.install(live, built)
    assert (live / "0000.obj").exists()


@pytest.mark.parametrize('score', [100, 99])
def test_dll_recipe_replays_static_crt_flags_and_requires_exact_data(tmp_path, monkeypatch, score):
    source = tmp_path / 'src/2008-06/00401000.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('// roc-flags: /O2 /MT\n// roc-lib: ogre-test unit.cpp\n')
    monkeypatch.setattr(swap_build, 'ROOT', tmp_path)
    monkeypatch.setattr(swap_build, 'libs_recipes', lambda: {'ogre-test': {'defines': 'WIN32 _DLL'}})
    compiled = []
    monkeypatch.setattr(swap_build.match, 'compile_text', lambda client, text: compiled.append(text) or b'object')
    monkeypatch.setattr(swap_build.match, 'check_text', lambda *args, **kw: (score, '_fn', 'data mismatch', []))
    item, objects, error = swap_build.build_group(('Ogre', 0, {
        'recipe': 'ogre-test', 'file': 'unit.cpp', 'cl': '21022', 'flags': '/O2 /MT', 'addrs': ['00401000']}))
    assert error is None and item['flags'] == '/O2 /MD'
    assert '// roc-flags: /O2 /MD' in compiled[0] and '/MT' not in compiled[0]
    assert objects == ([(b'object', {'_fn': '00401000'})] if score == 100 else [])


def test_dll_twin_recheck_records_each_address_without_losing_twins(tmp_path, monkeypatch):
    src = tmp_path / 'src' / swap_build.CLIENT
    src.mkdir(parents=True)
    (src / 'a.cpp').write_text('// roc-lib: rbxgs unit.cpp\n')
    monkeypatch.setattr(swap_build, 'ROOT', tmp_path)
    monkeypatch.setattr(swap_build.match, 'compile_text', lambda client, text: b'object')

    def check(client, addr, text, **kwargs):
        assert '// roc-lib: rbxgs-dll unit.cpp' in text
        assert kwargs == {'obj': b'object', 'minimum': 99}
        return (None, None, 'no exact candidate', []) if addr == 'c' else (100, '_shared', '', [])

    monkeypatch.setattr(swap_build.match, 'check_text', check)
    item, objects, error = swap_build.build_group(('RbxgsApp', 0, {
        'recipe': 'rbxgs', 'file': 'unit.cpp', 'addrs': ['a', 'b', 'c'],
    }))
    assert error is None
    assert objects == [(b'object', {'_shared': 'a'})]
    assert [r['cause'] for r in item['results']] == [
        'exact', 'exact', 'not exact after _DLL twin recompile',
    ]
    assert [r['address'] for r in item['results']] == ['a', 'b', 'c']


def test_native_unit_replays_registered_source_without_a_mined_wrapper(tmp_path, monkeypatch):
    monkeypatch.setattr(swap_build, 'ROOT', tmp_path)
    monkeypatch.setattr(swap_build, 'libs_recipes', lambda: {'ogre-test': {'defines': '_DLL'}})
    monkeypatch.setattr(swap_build.libs, 'source_for', lambda *args: '// native registry source')
    compiled = []
    monkeypatch.setattr(swap_build.match, 'compile_text', lambda client, text: compiled.append(text) or b'object')
    monkeypatch.setattr(swap_build.match, 'check_text', lambda *args, **kw: (100, '_native', '', []))
    item, objects, error = swap_build.build_group(('Ogre', 0, {'recipe': 'ogre-test',
        'file': 'unit.cpp', 'cl': '21022', 'flags': '/O2 /MD', 'addrs': ['00401000'], 'native': True}))
    assert error is None and compiled == ['// native registry source']
    assert objects == [(b'object', {'_native': '00401000'})]


def test_native_storage_requires_real_definition_without_awarding_functions(tmp_path, monkeypatch):
    monkeypatch.setattr(swap_build, 'ROOT', tmp_path)
    monkeypatch.setattr(swap_build, 'libs_recipes', lambda: {'ogre-test': {'defines': '_DLL'}})
    monkeypatch.setattr(swap_build.libs, 'source_for', lambda *args: '// native storage')
    monkeypatch.setattr(swap_build.match, 'compile_text', lambda *args: b'object')
    monkeypatch.setattr(swap_build.rebuild, 'coff_externals', lambda _: {'_cache': True})
    job = ('Ogre', 0, {'recipe': 'ogre-test', 'file': 'unit.cpp', 'cl': '21022',
        'flags': '/O2 /MD', 'addrs': [], 'native': True, 'helper_symbols': ['_cache']})
    item, objects, error = swap_build.build_group(job)
    assert error is None and objects == [(b'object', {})] and item['results'] == []
    monkeypatch.setattr(swap_build.rebuild, 'coff_externals', lambda _: {'_cache': False})
    _, objects, error = swap_build.build_group(job)
    assert objects == [] and 'Missing declared native helpers: _cache' in error
