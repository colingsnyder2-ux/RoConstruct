"""Pin the material/light integration run, including its changed lit pixel metric."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

from PIL import Image
import psutil

ROOT = Path(__file__).resolve().parents[3]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def record():
    output = Path(__file__).with_name('native-material-player-runtime')
    output.mkdir(exist_ok=True)
    binary = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    asset = ROOT / 'work/client2007/content/textures/SurfacesStrip.png'
    fixture = ROOT / 'rebuild/2008-06/tests/fixtures/cache-blocks.rbxl'
    env = os.environ.copy()
    env.pop('ROC_BUILD', None)
    env['ROC_TEXTURE_STRIP'] = str(asset)
    receipt = {
        'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        'scope': 'Recovered materials/lights integrated into isolated player; original scene bridge remains, P2 open',
        'ROC_BUILD': env.get('ROC_BUILD'), 'asset': str(asset), 'asset_sha256': sha(asset),
        'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
        'fixture_sha256': sha(fixture), 'runs': {}, 'loaded_dlls': {},
        'pixel_metric': 'G>50, G>2R, 2G>3B; unchanged area/noise gates and fixture',
        'previous_unlit_metric': 'G>120, R<90, B<90; retained per capture, no longer acceptance metric',
    }
    mapping = binary.with_suffix('.map').read_text()
    assert 'verified_sinks' not in mapping.lower()
    selected = ['?prepareBackend@', '?getMegaMaterial@', '?resolve@MegaTextureProxy@', '?apply@PlayerLighting@', '?populate@BlockMesh@', '?createSubEntity@RbxEntity@']
    receipt['selected_symbols'] = {key: [s.strip() for s in mapping.splitlines() if key in s and '__' not in s.split()[1]][:5] for key in selected}
    assert all(receipt['selected_symbols'].values())
    runs = [('selftest', ['--selftest']), ('cachetest', ['--cachetest', str(fixture)])]
    falling = ROOT / 'falling.rbxl'
    if falling.exists():
        runs.append(('falling-smoke', ['--frames', '240', str(falling)]))
        receipt['unversioned_falling_fixture_sha256'] = sha(falling)
    for name, args in runs:
        folder = output / name
        folder.mkdir(exist_ok=False)
        with (folder / 'stdout.txt').open('w') as stream:
            process = subprocess.Popen([str(binary), *args], cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
            observed = psutil.Process(process.pid)
            deadline = time.monotonic() + 60
            while process.poll() is None:
                assert time.monotonic() < deadline, f'Inspect live process {process.pid} before retrying'
                try:
                    for memory in observed.memory_maps():
                        path = Path(memory.path)
                        if path.name.lower() in ('rgmain.dll', 'rgdx.dll'):
                            receipt['loaded_dlls'][str(path)] = sha(path)
                except psutil.NoSuchProcess:
                    pass
                time.sleep(.005)
        assert process.returncode == 0, (name, process.returncode)
        stdout = (folder / 'stdout.txt').read_text()
        assert 'mesh cleanup: levels=0 refs=0 backends=0' in stdout
        assert 'texture=TextureAtlas lit=1' in stdout
        run = {'command': [str(binary), *args], 'cwd': str(folder), 'exit': process.returncode,
               'cleanup_zero': True, 'stdout_sha256': sha(folder / 'stdout.txt')}
        if name == 'selftest':
            result = json.loads((folder / 'selftest_result.json').read_text())
            assert result['failures'] == 0 and all(result[k]['pass'] for k in ('initial', 'moved', 'removed', 'empty'))
            run['pixels'] = result
            captures = {}
            for state in ('initial', 'moved', 'removed', 'empty'):
                path = folder / f'selftest_{state}.png'
                image = Image.open(path).convert('RGB')
                a, b = (110, 90, 210, 150), (240, 90, 320, 150)
                def count(box, lit):
                    pixels = image.crop(box).get_flattened_data()
                    return sum(g>50 and g>2*r and 2*g>3*b if lit else g>120 and r<90 and b<90 for r,g,b in pixels)
                captures[state] = {'sha256': sha(path), 'lit_A': count(a, True), 'lit_B': count(b, True),
                                   'legacy_unlit_A': count(a, False), 'legacy_unlit_B': count(b, False)}
                if state in ('initial', 'moved'):
                    assert captures[state]['lit_A'] == result[state]['greenA'] and captures[state]['lit_B'] == result[state]['greenB']
                else:
                    assert captures[state]['lit_A'] == result[state]['green'] == 0
            run['captures'] = captures
        elif name == 'cachetest':
            assert stdout.count('metadata/material baseline PASS') == 2
            run['passed_cycles'] = 2
        else:
            run['observation'] = next(s for s in stdout.splitlines() if s.startswith('after 240 frames:'))
        receipt['runs'][name] = run
    assert {Path(p).name.lower() for p in receipt['loaded_dlls']} == {'rgmain.dll', 'rgdx.dll'}
    sources = ['modules/p2-recovered-player.json', 'tests/p2-recovered/Player2008.cpp', 'tests/p2-recovered/PlayerScene.cpp',
               'tests/p2-recovered/PlayerScene.h', 'tests/p2-recovered/PlayerEngine.cpp', 'tests/p2-recovered/RbxEntity.h',
               'tests/p2-recovered/RbxEntityLocal.cpp', 'tests/PlayerNativeMaterial.cpp', 'tests/PlayerNativeTexture.cpp',
               'tests/PlayerMaterialBackend.cpp', 'tests/PlayerLighting.cpp', 'tests/PlayerBlockMesh.cpp']
    receipt['source_sha256'] = {f'rebuild/2008-06/{p}': sha(ROOT / 'rebuild/2008-06' / p) for p in sources}
    receipt['limits'] = ['Pixel classifier changed for native lit palette; original-threshold failure explicitly retained.',
                         'Default extra Lighting fields bridge the older donor model, complete native class ABI unproven.',
                         'Metadata parent, original bounds cache/shared-index/selector/child integration remain open.',
                         'Fall smoke uses unversioned fixture and one final observation, not full P0 stability proof.',
                         'Not a clean second-worktree run or original-client visual comparison.']
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({name: run.get('pixels', run.get('observation', run.get('passed_cycles'))) for name,run in receipt['runs'].items()}, indent=2))


if __name__ == '__main__':
    record()
