"""Record P3 block lifetime controls; non-box/reference gate stays open."""
import csv
import hashlib
import json
import os
from pathlib import Path
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
    fixture = root / 'rebuild/2008-06/tests/fixtures' / (sys.argv[2] if len(sys.argv)>2 else 'lifetime-blocks.rbxl')
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'fixture_sha256': sha(fixture), 'observer_sha256': sha(Path(__file__)),
               'loaded_dlls': {}, 'runs': {}, 'P3_complete': False,
               'remaining': 'Native non-box geometry and silhouette comparison against original client.'}
    runs = [('lifetime', ['--p3test', str(fixture)]), ('selftest', ['--selftest']),
            ('cachetest', ['--cachetest', str(root / 'rebuild/2008-06/tests/fixtures/cache-blocks.rbxl')])]
    for name, args in runs:
        folder = output / name
        folder.mkdir()
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
        receipt['runs'][name] = {'command': [str(binary), *args], 'cwd': str(folder), 'exit': process.returncode}
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
        assert process.returncode == 0, (name, process.returncode)
        stdout = (folder / 'stdout.txt').read_text()
        assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in stdout
        if name == 'lifetime':
            result = json.loads((folder / 'p3_result.json').read_text())
            assert result['block_lifetime_pass'] and not result['non_box_proven'] and result['cycles'] == 2
            rows = list(csv.DictReader((folder / 'p3_lifetime.csv').open()))
            assert len(rows) == 16 and all(row['stationary'] == row['pass'] == '1' for row in rows)
            audits = []
            for cycle in range(2):
                stages = ['loaded', 'transformed', 'reparented', 'detached', 'reattached', 'inserted', 'insert_removed', 'removed']
                images = {stage: np.array(Image.open(folder / f'p3_{cycle}_{stage}.png').convert('RGB'), dtype=np.int32) for stage in stages}
                def red(image):
                    r, g, b = image[:, :, 0], image[:, :, 1], image[:, :, 2]
                    return (r > 50) & (r > 2*g) & (2*r > 3*b)
                fixed = red(images['loaded'])
                assert fixed.sum() > 100
                for stage, expected in zip(stages, [2, 2, 2, 1, 2, 3, 2, 1]):
                    row = next(row for row in rows if int(row['cycle']) == cycle and row['stage'] == stage)
                    assert int(row['models']) == int(row['drawn']) == expected
                    assert int(row['red']) == red(images[stage]).sum()
                    assert np.array_equal(fixed, red(images[stage])), (cycle, stage, 'red silhouette moved')
                transform_delta = int(np.any(images['loaded'] != images['transformed'], axis=2).sum())
                insert_delta = int(np.any(images['reattached'] != images['inserted'], axis=2).sum())
                assert transform_delta > 100 and insert_delta > 100
                was_background = np.all(images['reattached'] == [255, 0, 255], axis=2)
                now_background = np.all(images['inserted'] == [255, 0, 255], axis=2)
                yy, xx = np.nonzero(was_background & ~now_background)
                assert len(xx) > 100 and xx.min() >= 70 and xx.max() <= 135 and yy.min() >= 145
                assert np.array_equal(images['reattached'], images['insert_removed'])
                empty = np.array(Image.open(folder / f'p3_{cycle}_empty.png').convert('RGB'), dtype=np.int32)
                assert not red(empty).any()
                audits.append({'cycle': cycle, 'stationary_red_mask_pixels': int(fixed.sum()),
                               'transform_changed_pixels': transform_delta, 'insert_changed_pixels': insert_delta,
                               'insert_new_foreground_pixels': len(xx),
                               'insert_foreground_bounds': [int(xx.min()), int(yy.min()), int(xx.max()), int(yy.max())],
                               'insert_removal_restores_exact_frame': True})
            assert stdout.count('mesh/material/texture/node baseline PASS') == 2
            receipt['runs'][name].update(result=result, independent_image_audit=audits)
        elif name == 'selftest':
            result = json.loads((folder / 'selftest_result.json').read_text())
            assert result['failures'] == 0 and all(result[state]['pass'] for state in ('initial', 'moved', 'removed', 'empty'))
            receipt['runs'][name]['result'] = result
        else:
            assert stdout.count('metadata/material baseline PASS') == 2
        receipt['runs'][name]['files'] = {p.name: sha(p) for p in folder.iterdir() if p.is_file()}
        print(name, 'PASS', flush=True)
    assert {Path(p).name.lower() for p in receipt['loaded_dlls']} == {'rgmain.dll', 'rgdx.dll'}
    source = root / 'rebuild/2008-06'
    names = ['modules/player.json', 'tests/p2-recovered/Player2008.cpp', 'tests/p2-recovered/PlayerEngine.cpp',
             'tests/p2-recovered/PlayerScene.cpp', 'tests/p2-recovered/PlayerScene.h', 'tests/p2-recovered/RbxEntity.h']
    receipt['source_sha256'] = {name: sha(source / name) for name in names}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')


if __name__ == '__main__':
    main()
