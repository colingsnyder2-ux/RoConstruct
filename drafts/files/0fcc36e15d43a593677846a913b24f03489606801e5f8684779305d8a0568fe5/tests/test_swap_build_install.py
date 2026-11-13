import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("swap_build", ROOT / "rebuild/2008-06/swap_build.py")
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


def test_ogre_install_discards_incompatible_recipes_even_when_addresses_overlap(tmp_path):
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    live.mkdir()
    built.mkdir()
    old = [{"obj": "old.obj", "recipe": "ogre-1.4.5-dll", "keep": {"old": "a"}},
           {"obj": "bad.obj", "recipe": "ogre-1.7.0", "keep": {"bad": "a", "bad2": "b"}}]
    new = [{"obj": "new.obj", "recipe": "ogre-1.4.5-dll", "keep": {"new": "c"}}]
    (live / "swaps.json").write_text(json.dumps({"swaps": old}))
    (built / "swaps.json").write_text(json.dumps({"swaps": new}))
    for name in ("old.obj", "bad.obj"):
        (live / name).write_bytes(b"old")
    (built / "new.obj").write_bytes(b"new")
    assert "installed" in swap_build.install(live, built, allowed_prefix="ogre-1.4.5")
    rows = json.loads((live / "swaps.json").read_text())["swaps"]
    assert {row["recipe"] for row in rows} == {"ogre-1.4.5-dll"}
    assert swap_build.kept_addresses(live) == {"a", "c"}
    assert (live / "live-old.obj").read_bytes() == b"old"


def test_ogre_install_rejects_incompatible_new_layer(tmp_path):
    import pytest
    live, built = tmp_path / "verified", tmp_path / "verified.building"
    layer(live, ["a"])
    layer(built, ["b"])
    with pytest.raises(ValueError, match="incompatible recipe"):
        swap_build.install(live, built, allowed_prefix="ogre-1.4.5")
    assert swap_build.kept_addresses(live) == {"a"}
