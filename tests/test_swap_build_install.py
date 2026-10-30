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
