"""Record disk-place/local-asset behavior. Original parity and audio stay open."""
import csv
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time

import numpy as np
from PIL import Image
import psutil


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    root = Path(__file__).resolve().parents[3]
    output = root / 'work/2008-06' / sys.argv[1]
    output.mkdir(exist_ok=False)
    binary = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    fixtures = root / 'rebuild/2008-06/tests/fixtures'
    content = binary.parent / 'Content'
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'observer_sha256': sha(Path(__file__)), 'loaded_dlls': {}, 'runs': {},
               'P4_complete': False, 'remaining': ['original-client asset/scene comparison', 'native sound path']}
    source = root / 'rebuild/2008-06'
    names = ['modules/player.json', 'patches/rbxgs-client.json', 'tests/PlayerBlockMesh.cpp',
             'tests/PlayerBlockMesh.h', 'tests/p2-recovered/Player2008.cpp',
             'tests/p2-recovered/PlayerEngine.cpp', 'tests/p2-recovered/PlayerScene.cpp',
             'tests/PlayerNativeTexture.cpp', 'tests/stage_demo_content.py']
    receipt['source_sha256'] = {name: sha(source / name) for name in names}
    receipt['content_sha256'] = {str(p.relative_to(content)): sha(p) for p in content.rglob('*') if p.is_file()}
    receipt['fixture_sha256'] = {name: sha(fixtures / name) for name in ('local-panel.rbxl', 'local-gallery.rbxl')}

    def save():
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')

    for name in ('panel', 'gallery', 'missing-mesh', 'missing-texture', 'bad-place'):
        folder = output / name
        folder.mkdir()
        fixture = fixtures / ('local-gallery.rbxl' if name == 'gallery' else 'local-panel.rbxl')
        args = ['--frames', '2', '--inspect-place', str(fixture)]
        if name.startswith('missing-'):
            # Only alter a new, owned copy. Never rename/delete staged external assets.
            local_content = folder / 'Content'
            shutil.copytree(content, local_content)
            (local_content / 'p4' / ('panel.mesh' if name == 'missing-mesh' else 'quadrants.png')).unlink()
            args.extend(['--content-root', str(local_content)])
        elif name == 'bad-place':
            args[-1] = str(folder / 'absent.rbxl')
        with (folder / 'stdout.txt').open('w') as stream:
            process = subprocess.Popen([str(binary), *args], cwd=folder, env=env,
                                       stdout=stream, stderr=subprocess.STDOUT)
            observer = psutil.Process(process.pid)
            while process.poll() is None:
                try:
                    for memory in observer.memory_maps():
                        path = Path(memory.path)
                        if path.name.lower() in ('rgmain.dll', 'rgdx.dll'):
                            receipt['loaded_dlls'][str(path)] = sha(path)
                except psutil.NoSuchProcess:
                    pass
                time.sleep(.01)
        run = {'command': [str(binary), *args], 'cwd': str(folder), 'exit': process.returncode}
        receipt['runs'][name] = run
        save()
        stdout = (folder / 'stdout.txt').read_text()
        assert process.returncode == (1 if name == 'bad-place' else 0), run
        if name == 'bad-place':
            assert 'could not read place:' in stdout and not (folder / 'last.png').exists()
        else:
            assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in stdout
            with (folder / 'place_snapshot.csv').open() as stream:
                rows = list(csv.DictReader(stream))
            run['models'] = rows
            image = np.array(Image.open(folder / 'last.png').convert('RGB'), dtype=np.int32)
            background = np.all(image == [255, 0, 255], axis=2)
            run['foreground_pixels'] = int((~background).sum())
            if name == 'missing-mesh':
                assert len(rows) == 1 and rows[0]['status'] == '3'
                assert background.all() and 'file mesh unavailable:' in stdout
            else:
                assert len(rows) == (2 if name == 'gallery' else 1)
                for row, x in zip(rows, [-2, 2] if name == 'gallery' else [0]):
                    assert row['status'] == '0' and float(row['x']) == x
                    assert float(row['y']) == float(row['z']) == 0
                assert rows[0]['source_indices'] == rows[0]['backend_indices'] == '6'
                assert rows[0]['kind'] == '0' and rows[0]['levels'] == '1'
                assert [float(rows[0][key]) for key in ('sx', 'sy', 'sz')] == [4, 4, 4]
                assert run['foreground_pixels'] > 100
                if name == 'gallery':
                    assert rows[1]['kind'] == '2' and rows[1]['backend_indices'] == '1296'
                    assert [float(rows[1][key]) for key in ('sx', 'sy', 'sz')] == [2, 2, 2]
                if name == 'missing-texture':
                    assert 'file texture unavailable:' in stdout
                    assert 'quadrants.png lit=1' not in stdout
                else:
                    assert 'quadrants.png lit=1' in stdout
                    # Sample interiors of all four UV quadrants, independently of telemetry.
                    xx, yy = ((89, 117), (106, 135)) if name == 'gallery' else ((131, 189), (91, 149))
                    samples = [image[y, x] for y in yy for x in xx]
                    red, green, blue, yellow = samples
                    assert red[0] > 2 * max(red[1:])
                    assert green[1] > 2 * max(green[0], green[2])
                    assert blue[2] > 2 * max(blue[:2])
                    assert min(yellow[:2]) > 2 * yellow[2]
                    run['quadrant_rgb'] = [value.tolist() for value in samples]
        run['files'] = {p.name: sha(p) for p in folder.iterdir() if p.is_file()}
        save()
        print(name, 'PASS', flush=True)
    assert {Path(p).name.lower() for p in receipt['loaded_dlls']} == {'rgmain.dll', 'rgdx.dll'}
    receipt['disk_asset_checks_pass'] = True
    save()


if __name__ == '__main__':
    main()
