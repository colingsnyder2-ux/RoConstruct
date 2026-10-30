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


@pytest.mark.parametrize('directive', [
    '#pragma include_alias("native/Header.h", "private.cpp")',
    '#pragma include_alias(<native/Header.h>, <private.cpp>)',
])
def test_alias_header_gate_and_overlay_replay_support_both_delimiters(tmp_path, monkeypatch, directive):
    unit = tmp_path / 'roc_native.cpp'
    unit.write_text(directive + '\n#include "native/Header.h"\n')
    monkeypatch.setitem(swap_build.TREES, 'RbxgsApp', tmp_path)
    monkeypatch.setattr(swap_build, 'adopted', lambda module: {})
    assert not swap_build.compatible('RbxgsApp', unit.name)
    assert swap_build.overlay_candidate('RbxgsApp', unit.name)
    assert swap_build.ALIAS.sub('', unit.read_text()).strip() == '#include "native/Header.h"'
    monkeypatch.setattr(swap_build, 'adopted', lambda module: {'native/Header.h': 'private.cpp'})
    assert swap_build.compatible('RbxgsApp', unit.name)
    monkeypatch.setattr(swap_build.libs, 'fetch', lambda recipe: tmp_path)
    assert not swap_build.compatible('Ogre', unit.name, 'fixture')


@pytest.mark.parametrize('directive', [
    '#pragma include_alias(<native/Header.h>, "private.cpp")',
    '#pragma include_alias("native/Header.h", <private.cpp>)',
])
def test_mixed_alias_delimiters_never_authorize_a_header(tmp_path, monkeypatch, directive):
    unit = tmp_path / 'roc_native.cpp'
    unit.write_text(directive)
    monkeypatch.setitem(swap_build.TREES, 'RbxgsApp', tmp_path)
    monkeypatch.setattr(swap_build, 'adopted', lambda module: {'native/Header.h': 'private.cpp'})
    assert not swap_build.compatible('RbxgsApp', unit.name)
    assert not swap_build.overlay_candidate('RbxgsApp', unit.name)


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


@pytest.mark.parametrize('recipe,file,owner', [
    ('g3d-6.09-dll', 'G3Dcpp/Array.cpp', 'G3D'),
    ('g3d-6.09-rbx2008-dll', 'GLG3Dcpp/RenderDevice.cpp', 'G3D-GL'),
    ('g3d-6.09-dll', 'contrib/ArticulatedModel/ToneMap.cpp', 'G3D-GL'),
    ('g3d-6.09-png-dll', 'pngread.c', 'G3D-PNG'),
    ('g3d-6.09-ijg-dll', 'jdmainct.c', 'G3D'),
])
def test_g3d_swap_groups_have_one_native_owner(recipe, file, owner):
    assert [name for name in ('G3D', 'G3D-GL', 'G3D-PNG')
            if swap_build.of_module(name, recipe, file)] == [owner]


@pytest.mark.parametrize('registry_exact', [True, False])
def test_registry_replay_preserves_provenance_and_replaces_legacy_owner_only_when_exact(tmp_path, monkeypatch, registry_exact):
    out = tmp_path / 'out'
    out.mkdir()
    (out / 'swap-plan.json').write_text(json.dumps({'groups': [
        {'recipe': 'ogre-test', 'file': 'legacy.cpp', 'addrs': ['00401000']}]}))
    modules = tmp_path / 'rebuild/2008-06/modules'
    modules.mkdir(parents=True)
    unit = {'recipe': 'ogre-test', 'file': 'context.cpp', 'addrs': ['00401000'],
            'provenance': 'Analog outer layout; genuine G3D ownership'}
    (modules / 'ogre.json').write_text(json.dumps({'name': 'Ogre', 'native_units': [unit]}))
    monkeypatch.setattr(swap_build, 'ROOT', tmp_path)
    monkeypatch.setattr(swap_build, 'OUT', out)
    monkeypatch.setattr(swap_build, 'compatible', lambda *args: True)
    def build(job):
        item = job[2]
        objects = [] if item.get('native') and not registry_exact else [
            (b'obj', {'_scoped_owner' if item.get('native') else '_legacy_owner': '00401000'})]
        return item, objects, None
    monkeypatch.setattr(swap_build, 'build_group', build)
    real_install, refresh = swap_build.install, []
    def install(live, built, **kwargs):
        refresh.append(kwargs.get('refresh_native', False))
        return real_install(live, built, **kwargs)
    monkeypatch.setattr(swap_build, 'install', install)
    swap_build.main('Ogre')
    assert refresh == [registry_exact]
    saved = json.loads((out / 'Ogre/verified/swaps.json').read_text())
    assert len(saved['swaps']) == 1
    assert saved['swaps'][0]['keep'] == {'_scoped_owner' if registry_exact else '_legacy_owner': '00401000'}
    if registry_exact:
        assert saved['swaps'][0]['provenance'] == unit['provenance']
        results = json.loads((out / 'Ogre/swap-results.json').read_text())
        assert results['groups'][1]['covered_by_registry'] == ['00401000']


@pytest.mark.parametrize('data_exact', [True, False])
def test_bound_symbol_replay_cannot_select_an_identical_body_from_another_owner(monkeypatch, data_exact):
    monkeypatch.setattr(swap_build, 'libs_recipes', lambda: {'ogre-test': {'defines': '_DLL'}})
    monkeypatch.setattr(swap_build.libs, 'source_for', lambda *args: 'source')
    monkeypatch.setattr(swap_build.match, 'compile_text', lambda *args: b'object')
    monkeypatch.setattr(swap_build.match, 'coff_functions', lambda _: [('_wrong', b'\xc3', []), ('_right', b'\xc3', [])])
    monkeypatch.setattr(swap_build.rebuild, 'coff_externals', lambda _: {'_wrong': True, '_right': True})
    monkeypatch.setattr(swap_build.match, 'target', lambda *args: (b'\xc3', [], {}))
    checked = []
    monkeypatch.setattr(swap_build.match, 'coff_data_refs', lambda obj, sym: checked.append(sym) or [])
    monkeypatch.setattr(swap_build.match, 'data_check', lambda *args: ([], [] if data_exact else ['bad data']))
    def arbitrary_owner(*args, **kwargs):
        raise AssertionError('explicit binding must not fall back to an arbitrary exact body')
    monkeypatch.setattr(swap_build.match, 'check_text', arbitrary_owner)
    item, objects, error = swap_build.build_group(('Ogre', 0, {
        'native': True, 'recipe': 'ogre-test', 'file': 'unit.cpp', 'cl': '21022', 'flags': '/O2 /MD',
        'addrs': ['00401000'], 'symbols': {'00401000': '_right'}}))
    assert error is None and checked == ['_right']
    assert objects == ([(b'object', {'_right': '00401000'})] if data_exact else [])
    assert item['results'][0]['score'] == (100 if data_exact else 99)


def test_complete_native_context_refresh_preserves_omitted_old_addresses(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a", "b"])
    layer(built, ["a"])
    (built / "0000.obj").write_bytes(b"new native context")
    assert "kept existing" in swap_build.install(live, built)
    layer(built, ["a"])
    (built / "0000.obj").write_bytes(b"new native context")
    assert "installed" in swap_build.install(live, built, refresh_native=True)
    assert swap_build.kept_addresses(live) == {"a", "b"}
    assert (live / "0000.obj").read_bytes() == b"new native context"
    assert (live / "live-0000.obj").read_bytes() == b"obj"


@pytest.mark.parametrize("alias", [False, True])
def test_raknet_units_use_real_headers_and_reject_private_aliases(tmp_path, monkeypatch, alias):
    root = tmp_path / "raknet"
    root.mkdir()
    text = '#include "BitStream.h"\n'
    if alias:
        text = '#pragma include_alias("BitStream.h", "private.h")\n' + text
    fetched = []
    def fetch(recipe):
        fetched.append(recipe)
        (root / "roc_geometry.cpp").write_text(text)
        return root
    monkeypatch.setattr(swap_build.libs, "fetch", fetch)
    monkeypatch.setattr(swap_build.libs, "LIBS", tmp_path)
    monkeypatch.setitem(swap_build.libs.RECIPES, "openrbx-raknet", {"src": "raknet"})
    assert swap_build.compatible("RakNet", "roc_geometry.cpp", "openrbx-raknet") is not alias
    assert fetched == ["openrbx-raknet"]


def test_raknet_recipe_routing_excludes_app_families():
    assert swap_build.of_module("RakNet", "openrbx-raknet", "BitStream.cpp")
    assert not swap_build.of_module("RakNet", "openrbx-client", "Streaming.cpp")


def test_transient_access_denied_retries_without_losing_layer(tmp_path, monkeypatch):
    live, built = tmp_path / 'verified', tmp_path / 'verified.building'
    layer(live, ['a', 'b'])
    layer(built, ['a', 'b', 'c'])
    original, failures, delays = Path.rename, [], []

    def rename(path, target):
        if path == built and len(failures) < 2:
            failures.append(path)
            raise PermissionError('scanner lock')
        return original(path, target)

    monkeypatch.setattr(Path, 'rename', rename)
    monkeypatch.setattr(swap_build.time, 'sleep', delays.append)
    assert 'installed' in swap_build.install(live, built)
    assert swap_build.kept_addresses(live) == {'a', 'b', 'c'}
    assert len(delays) == 2 and not built.exists()


def test_failed_swap_restores_live_and_preserves_staged_layer(tmp_path, monkeypatch):
    live, built = tmp_path / 'verified', tmp_path / 'verified.building'
    layer(live, ['a', 'b'])
    layer(built, ['a', 'b', 'c'])
    original, attempts = Path.rename, []

    def rename(path, target):
        if path == built:
            attempts.append(path)
            raise PermissionError('persistent lock')
        return original(path, target)

    monkeypatch.setattr(Path, 'rename', rename)
    monkeypatch.setattr(swap_build.time, 'sleep', lambda _: None)
    with pytest.raises(PermissionError, match='persistent lock'):
        swap_build.install(live, built)
    assert len(attempts) == 5
    assert swap_build.kept_addresses(live) == {'a', 'b'}
    assert swap_build.kept_addresses(built) == {'a', 'b', 'c'}
    assert not live.with_name('verified.old').exists()


def test_blocked_backup_move_preserves_live_and_staged_layers(tmp_path, monkeypatch):
    live, built = tmp_path / 'verified', tmp_path / 'verified.building'
    layer(live, ['a'])
    layer(built, ['a', 'b'])
    original = Path.rename

    def rename(path, target):
        if path == live:
            raise PermissionError('backup move blocked')
        return original(path, target)

    monkeypatch.setattr(Path, 'rename', rename)
    monkeypatch.setattr(swap_build.time, 'sleep', lambda _: None)
    with pytest.raises(PermissionError, match='backup move blocked'):
        swap_build.install(live, built)
    assert swap_build.kept_addresses(live) == {'a'}
    assert swap_build.kept_addresses(built) == {'a', 'b'}


def test_blocked_rollback_reports_preserved_backup_and_staged_paths(tmp_path, monkeypatch):
    live, built = tmp_path / 'verified', tmp_path / 'verified.building'
    old = live.with_name('verified.old')
    layer(live, ['a'])
    layer(built, ['a', 'b'])
    original = Path.rename

    def rename(path, target):
        if target == live:
            raise PermissionError('destination blocked')
        return original(path, target)

    monkeypatch.setattr(Path, 'rename', rename)
    monkeypatch.setattr(swap_build.time, 'sleep', lambda _: None)
    with pytest.raises(RuntimeError) as error:
        swap_build.install(live, built)
    assert str(old) in str(error.value) and str(built) in str(error.value)
    assert swap_build.kept_addresses(old) == {'a'}
    assert swap_build.kept_addresses(built) == {'a', 'b'}

def test_replay_preserves_exclusions_and_remaps_retained_helpers(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a", "b"])
    layer(built, ["a", "c"])
    (live / "excluded.json").write_text('["bad_swap"]')
    (live / "vdrop.json").write_text('["bad_vtable"]')
    (live / "helpers.json").write_text(json.dumps({"helper": "0000.obj", "stale": "missing.obj"}))

    assert "installed" in swap_build.install(live, built)
    assert swap_build.kept_addresses(live) == {"a", "b", "c"}
    assert json.loads((live / "excluded.json").read_text()) == ["bad_swap"]
    assert json.loads((live / "vdrop.json").read_text()) == ["bad_vtable"]
    assert json.loads((live / "helpers.json").read_text()) == {"helper": "live-0000.obj"}
    assert (live / "live-0000.obj").read_bytes() == b"obj"


def test_replay_drops_changed_provider_but_keeps_identical_provider(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a"])
    layer(built, ["a", "b"])
    data = json.loads((built / "swaps.json").read_text())
    data["swaps"].append({"obj": "unchanged.obj", "keep": {}})
    (built / "swaps.json").write_text(json.dumps(data))
    (built / "0000.obj").write_bytes(b"replacement")
    for folder in (live, built):
        (folder / "unchanged.obj").write_bytes(b"same")
    (live / "helpers.json").write_text(json.dumps({"changed": "0000.obj", "same": "unchanged.obj"}))

    assert "installed" in swap_build.install(live, built)
    assert json.loads((live / "helpers.json").read_text()) == {"same": "unchanged.obj"}


def test_rejected_replay_keeps_live_resolution_metadata(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a", "b"])
    layer(built, ["a"])
    metadata = {"excluded.json": '["bad"]', "vdrop.json": '["vtable"]',
                "helpers.json": '{"helper": "0000.obj"}'}
    for name, content in metadata.items():
        (live / name).write_text(content)

    assert "kept existing" in swap_build.install(live, built)
    for name, content in metadata.items():
        assert (live / name).read_text() == content

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


def test_native_context_refresh_preserves_resolution_metadata_without_gain(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a"])
    layer(built, ["a"])
    (live / "excluded.json").write_text('["bad_swap"]')
    (live / "helpers.json").write_text('{"helper": "0000.obj"}')

    assert "installed" in swap_build.install(live, built, refresh_native=True)
    assert json.loads((live / "excluded.json").read_text()) == ["bad_swap"]
    assert json.loads((live / "helpers.json").read_text()) == {"helper": "0000.obj"}
