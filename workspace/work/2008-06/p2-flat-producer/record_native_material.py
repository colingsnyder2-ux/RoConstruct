"""Record normal-process material prerequisite evidence for the checked-in source."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

import psutil
from audit_native_material import audit, ROOT


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def record():
    output = Path(__file__).with_name(sys.argv[1] if len(sys.argv)>1 else 'native-material-runtime')
    output.mkdir(exist_ok=True)
    env = os.environ.copy()
    env.pop('ROC_BUILD', None)
    asset = ROOT / 'work/client2007/content/textures/SurfacesStrip.png'
    env['ROC_TEXTURE_STRIP'] = str(asset)
    receipt = {
        'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        'ROC_BUILD': env.get('ROC_BUILD'),
        'asset': str(asset), 'asset_sha256': sha(asset),
        'scope': 'Standalone ownership/ABI prerequisite, not P2 player acceptance',
        'runs': {}, 'loaded_dlls': {},
    }
    source_files = [
        'tests/PlayerNativeMaterial.h', 'tests/PlayerNativeMaterial.cpp',
        'tests/PlayerNativeTexture.cpp', 'tests/P2NativeMaterialTest.cpp',
        'tests/PlayerMaterialBackend.cpp',
        'tests/P2TextureInteropTest.cpp', 'tests/PlayerTextureAtlas.cpp',
        'tests/PlayerTextureAtlas.h', 'modules/p2-native-material.json',
        'modules/p2-texture-interop.json', 'modules/p2-image-core.json',
    ]
    receipt['source_sha256'] = {f'rebuild/2008-06/{p}': sha(ROOT / 'rebuild/2008-06' / p) for p in source_files}
    for test, module in [('P2TextureInteropTest', 'P2TextureInterop'), ('P2NativeMaterialTest', 'P2NativeMaterial')]:
        folder = output / test
        folder.mkdir(exist_ok=True)
        binary = ROOT / 'rebuild/2008-06/out/tests' / test / (test + '.exe')
        mapping = binary.with_suffix('.map')
        assert 'verified_sinks' not in mapping.read_text().lower()
        with (folder / 'stdout.txt').open('w') as stream:
            process = subprocess.Popen([str(binary)], cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
            observed = psutil.Process(process.pid)
            deadline = time.monotonic() + 60
            while process.poll() is None:
                assert time.monotonic() < deadline, 'runtime timeout; inspect live process before retrying'
                try:
                    for memory in observed.memory_maps():
                        path = Path(memory.path)
                        if path.name.lower() in ('rgmain.dll', 'rgdx.dll'):
                            receipt['loaded_dlls'][str(path)] = sha(path)
                except psutil.NoSuchProcess:
                    pass
                time.sleep(.005)
        assert process.returncode == 0, (test, process.returncode)
        stdout = (folder / 'stdout.txt').read_text()
        assert ('PASS: native proxy/Level dispatch' if test == 'P2NativeMaterialTest' else 'failures=0') in stdout
        library = ROOT / 'rebuild/2008-06/out' / module / 'linked/linked.lib'
        receipt['runs'][test] = {
            'exit': process.returncode, 'exe': str(binary), 'cwd': str(folder),
            'exe_sha256': sha(binary), 'map_sha256': sha(mapping),
            'library_sha256': sha(library), 'no_verified_sinks_in_map': True,
            'report_sha256': sha(ROOT / 'rebuild/2008-06/out' / module / 'report.json'),
            'stdout_sha256': sha(folder / 'stdout.txt'),
        }
    assert {Path(p).name.lower() for p in receipt['loaded_dlls']} == {'rgmain.dll', 'rgdx.dll'}
    receipt['vtable_audit'] = audit()
    player = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    receipt['unchanged_player_sha256'] = sha(player)
    receipt['limits'] = [
        'Generic GL file/shade resolver not runtime validated; mega Ogre side effect validated.',
        'No new server-verified exact-function credit claimed.',
        'Original renderer/light integration and final P2 acceptance remain open.',
        'External strip matches August2007/May2008 sources, exact June distribution unproven.',
    ]
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print('PASS: normal interop/material runs, loaded DLLs, hashes and independent slot audit')


if __name__ == '__main__':
    record()
