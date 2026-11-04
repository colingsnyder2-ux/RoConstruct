import pytest
from roc import rebuild_package


def test_export_keeps_auxiliary_player_sources_and_fixtures(tmp_path):
    root = tmp_path / 'checkout'
    source = root / 'rebuild/2008-06'
    inputs = {
        'modules/player.json': '{"test":"P2RecoveredPlayer"}',
        'tests/P2RecoveredPlayer.cpp': '#include "p2-recovered/Player2008.cpp"\n',
        'tests/p2-recovered/Player2008.cpp': 'int main(){return 0;}\n',
        'tests/p2-recovered/PlayerEngine.cpp': 'void step(){}\n',
        'tests/PlayerSkybox.cpp': 'void sky(){}\n',
        'tests/fixtures/falling.rbxl': '<roblox/>\n',
        'tests/stage_demo_content.py': 'print("stage")\n',
        'tests/capture.png': 'generated capture must stay local',
    }
    for name, text in inputs.items():
        path = source / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
    package = tmp_path / 'package'
    manifest = rebuild_package.export(root, package)
    for name, text in inputs.items():
        if name.endswith('.png'):
            assert name not in manifest['files']
        else:
            exported = name.replace('modules/', 'config/')
            assert exported in manifest['files']
            assert (package / exported).read_text() == text


def test_export_uses_one_assembled_client_tree(tmp_path):
    root = tmp_path / 'checkout'
    raw = root / 'rebuild/2008-06/Source/App/unused.cpp'
    raw.parent.mkdir(parents=True)
    raw.write_text('raw source view')
    native = root / 'tools/rbxgs/Client/App/used.cpp'
    native.parent.mkdir(parents=True)
    native.write_text('void used() {}')
    package = tmp_path / 'package'
    manifest = rebuild_package.export(root, package)
    assert 'src/Client/App/used.cpp' in manifest['files']
    assert not any(name.startswith('Source/') for name in manifest['files'])


def test_package_file_walk_skips_windows_junction(tmp_path):
    import sys
    import pytest
    if sys.platform != 'win32':
        pytest.skip('Windows junction regression')
    import _winapi
    source = tmp_path / 'source'
    target = tmp_path / 'external'
    source.mkdir()
    target.mkdir()
    (source / 'owned.cpp').write_text('owned')
    (target / 'external.cpp').write_text('external')
    _winapi.CreateJunction(str(target), str(source / 'dependency'))
    assert [p.name for p in rebuild_package.files(source)] == ['owned.cpp']


@pytest.mark.parametrize('original_exists', [True, False])
def test_export_applies_native_world_adoption(tmp_path, original_exists):
    import json
    root = tmp_path / 'checkout'
    original = root / 'tools/rbxgs/Client/App/v8world/Assembly.cpp'
    original.parent.mkdir(parents=True)
    if original_exists:
        original.write_text('donor')
    native = root / 'rebuild/2008-06/native-world/App/v8world/Assembly.cpp'
    native.parent.mkdir(parents=True)
    native.write_text('native implementation')
    overlay = root / 'rebuild/2008-06/patches/rbxgs-client.json'
    overlay.parent.mkdir(parents=True)
    overlay.write_text(json.dumps({'App/v8world/Assembly.cpp': [['@replace', '../../../rebuild/2008-06/native-world/App/v8world/Assembly.cpp']]}))
    package = tmp_path / 'package'
    rebuild_package.export(root, package)
    assert (package / 'src/Client/App/v8world/Assembly.cpp').read_text() == 'native implementation'
