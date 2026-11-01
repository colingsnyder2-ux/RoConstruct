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
