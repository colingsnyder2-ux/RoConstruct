"""Pin the native Sound asset prerequisite. Does not close the service/audio gate."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    root = Path(__file__).resolve().parents[3]
    output = root / 'work/2008-06' / sys.argv[1]
    output.mkdir(exist_ok=False)
    binary = root / 'rebuild/2008-06/out/tests/P4SoundAssetTest/P4SoundAssetTest.exe'
    content = root / 'rebuild/2008-06/tests/fixtures/p4-assets'
    names = ['rebuild/2008-06/tests/PlayerNativeSound.cpp', 'rebuild/2008-06/tests/PlayerNativeSoundService.cpp',
             'rebuild/2008-06/tests/P4SoundAssetTest.cpp',
             'rebuild/2008-06/modules/p4-sound-asset.json', 'rebuild/2008-06/tests/record_p4_sound.py',
             'rebuild/2008-06/glue/rbxgs/glue_link_stubs.cpp',
             'rebuild/2008-06/patches/rbxgs-client.json',
             'rebuild/2008-06/out/P4SoundAsset/overlay/App/include/util/Sound.h',
             'rebuild/2008-06/out/P4SoundAsset/overlay/App/include/v8tree/Instance.h',
             'tools/rbxgs/Client/App/include/util/Sound.h', 'tools/rbxgs/Client/App/include/util/ContentProvider.h',
             'tools/openrbx/3rdparty/fmod/api/inc/fmod.h', 'tools/openrbx/3rdparty/fmod/api/inc/fmod.hpp',
             'tools/openrbx/3rdparty/fmod/api/inc/fmod_errors.h']
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    command = [str(binary), str(content)]
    run = subprocess.run(command, cwd=output, env=env, capture_output=True, text=True, timeout=30)
    stdout = run.stdout + run.stderr
    (output / 'stdout.txt').write_text(stdout)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'sources_sha256': {name: sha(root / name) for name in names},
               'tone_sha256': sha(content / 'tone.wav'), 'command': command, 'cwd': str(output),
               'exit': run.returncode, 'P4_complete': False,
               'scope': 'Native Sound memory loader, decoded PCM and ownership; NOSOUND diagnostic.',
               'remaining': ['Sound service/factory/reflection/heartbeat integration', 'audible output and original audio comparison']}
    lines = [line.removeprefix('fmod loaded: ') for line in stdout.splitlines() if line.startswith('fmod loaded: ')]
    if lines:
        dll = Path(lines[0])
        receipt['actual_fmod_dll'] = {'path': str(dll), 'sha256': sha(dll)}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    assert run.returncode == 0, stdout
    assert len(lines) == 1 and sha(dll) == sha(root / 'clients/2008-06/fmodex.dll')
    assert 'P4 Sound loader PASS version=00041406 cycles=16 pcm_bytes=11024 samples=5512 2D/3D/cache/detach/missing' in stdout
    print('P4 Sound asset prerequisite PASS; service/audible gate open')


if __name__ == '__main__':
    main()
