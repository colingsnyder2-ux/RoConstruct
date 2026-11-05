"""Pin native sphere unit/GPU/hardware-identity evidence; reference gate stays open."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time

import numpy as np
from PIL import Image
import psutil

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    output = ROOT / 'work/2008-06' / sys.argv[1]
    output.mkdir(exist_ok=False)
    binary = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    unit = ROOT / 'rebuild/2008-06/out/tests/P3SphereMeshTest/P3SphereMeshTest.exe'
    fixture = ROOT / 'rebuild/2008-06/tests/fixtures/sphere.rbxl'
    env = os.environ.copy()
    for key in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(key, None)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'unit_sha256': sha(unit), 'fixture_sha256': sha(fixture), 'observer_sha256': sha(Path(__file__)),
               'loaded_dlls': {}, 'runs': {}, 'reference_client_compared': False,
               'limits': ['Native enclosing texture context absent: harness mipmaps enabled, AA mode0.',
                          'Mixed-shape lifetime and reference silhouette remain open; P3 not complete.']}

    def run(name, command):
        folder = output / name
        folder.mkdir()
        with (folder / 'stdout.txt').open('w') as stream:
            process = subprocess.Popen(command, cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
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
        receipt['runs'][name] = {'command': command, 'cwd': str(folder), 'exit': process.returncode}
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
        assert process.returncode == 0, (name, process.returncode)
        return folder, (folder / 'stdout.txt').read_text()

    folder, text = run('unit', [str(unit)])
    assert 'PASS: 294 native sphere vertices/864 retained quad indices/1296 GPU indices' in text
    folder, text = run('normal', [str(binary), '--frames', '2', str(fixture)])
    assert 'producer=004fcfb0' in text and 'block_calls=0 indices=1296' in text
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in text and 'shadeTex lit=1' in text
    pixels = np.array(Image.open(folder / 'last.png').convert('RGB'))
    mask = np.any(pixels != [255, 0, 255], axis=2)
    yy, xx = np.nonzero(mask)
    bounds = [int(xx.min()), int(yy.min()), int(xx.max()), int(yy.max())]
    fill = float(mask.sum()) / ((xx.max()-xx.min()+1)*(yy.max()-yy.min()+1))
    assert len(xx) > 8000 and .74 < fill < .85
    assert abs((xx.max()-xx.min())-(yy.max()-yy.min())) <= 2
    receipt['sphere_image'] = {'pixels': int(mask.sum()), 'bounds': bounds, 'fill': fill,
                               'sha256': sha(folder / 'last.png'), 'scope': 'Round silhouette sanity; not original-client comparison.'}

    build = output / 'observer-build'
    build.mkdir()
    source = ROOT / 'rebuild/2008-06/tests/support/TraceNativeMesh.cpp'
    observer = build / 'TraceNativeMesh.exe'
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl',
        ['/nologo', '/O2', '/GS-', '/EHsc', '/MD', str(source), '/Fe'+str(observer), '/link', 'kernel32.lib'], build)
    (build / 'build.log').write_text(log)
    assert code == 0, log
    rows = [re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\b', line) for line in binary.with_suffix('.map').read_text().splitlines()]
    keys = ['??0SphereMesh@PlayerBlockMesh@@', '?upload@Level@PlayerBlockMesh@@',
            '?createSubEntity@RbxEntity@Ogre@@', '??1RbxEntity@Ogre@@', '?getRenderOperation@RbxSubEntity@Ogre@@']
    selected = {}
    for key in keys:
        found = [(m[1], m[2]) for m in rows if m and m[1].startswith(key)]
        assert len(found) == 1, (key, found)
        selected[key] = {'symbol': found[0][0], 'address': found[0][1]}
    folder, text = run('hardware', [str(observer), str(binary), *[selected[key]['address'] for key in keys], str(fixture)])
    events = []
    for line in text.splitlines():
        if line.startswith('TRACE_'):
            events.append({'event': line.split()[0], **dict(re.findall(r'(\w+)=([0-9a-f]+)', line))})
    def one(kind):
        found = [event for event in events if event['event'] == kind]
        assert len(found) == 1, (kind, found)
        return found[0]
    producer = one('TRACE_PRODUCER_RETURN')
    assert producer['levels'] == '1' and producer['level1'] == '00000000'
    assert producer['level0'] == one('TRACE_UPLOAD_ENTRY')['receiver'] != '00000000'
    upload, created, returned, operation, destroyed = [one(kind) for kind in (
        'TRACE_UPLOAD_RETURN', 'TRACE_ENTITY_CREATE', 'TRACE_ENTITY_CREATED', 'TRACE_RENDER_OPERATION', 'TRACE_ENTITY_DESTROY')]
    assert upload['level'] == producer['level0']
    assert upload['backend'] == created['submesh'] == operation['submesh'] != '00000000'
    assert created['entity'] == returned['entity'] == destroyed['entity'] != '00000000'
    assert returned['subentity'] == operation['subentity'] != '00000000'
    assert created['lod'] == operation['lod'] == '0' and one('TRACE_EXIT')['code'] == '0'
    assert all(event['code'] == '406d1388' for event in events if event['event'] == 'TRACE_EXCEPTION')
    assert sha(binary) == receipt['exe_sha256']
    receipt['hardware'] = {'selected': selected, 'events': events, 'observer_source_sha256': sha(source),
                           'identity_chain_pass': True, 'target_exe_unchanged': True}
    for name, run in receipt['runs'].items():
        folder = Path(run['cwd'])
        run['files'] = {p.name: sha(p) for p in folder.iterdir() if p.is_file()}
    names = ['tests/PlayerBlockMesh.cpp', 'tests/PlayerBlockMesh.h', 'tests/PlayerNativeTexture.cpp',
             'tests/p2-recovered/Player2008.cpp', 'tests/p2-recovered/PlayerScene.cpp']
    receipt['source_sha256'] = {name: sha(ROOT / 'rebuild/2008-06' / name) for name in names}
    receipt['assets_sha256'] = {name: sha(binary.parent / 'Content/textures' / name) for name in ('Surfaces.png', 'SurfacesStrip.png')}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({'sphere_image': receipt['sphere_image'], 'identity_chain_pass': True}))


if __name__ == '__main__':
    main()
