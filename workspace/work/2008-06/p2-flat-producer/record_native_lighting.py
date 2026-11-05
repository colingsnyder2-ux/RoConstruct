"""Normal-process evidence for the standalone recovered lighting prerequisite."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

import psutil

ROOT = Path(__file__).resolve().parents[3]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def record():
    folder = Path(__file__).with_name('native-lighting-runtime')
    folder.mkdir(exist_ok=True)
    binary = ROOT / 'rebuild/2008-06/out/tests/P2LightingTest/P2LightingTest.exe'
    env = os.environ.copy()
    env.pop('ROC_BUILD', None)
    loaded = {}
    with (folder / 'stdout.txt').open('w') as stream:
        process = subprocess.Popen([str(binary)], cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
        observed = psutil.Process(process.pid)
        deadline = time.monotonic() + 60
        while process.poll() is None:
            assert time.monotonic() < deadline, 'timeout: inspect this process before retrying'
            try:
                for memory in observed.memory_maps():
                    path = Path(memory.path)
                    if path.name.lower() in ('rgmain.dll', 'rgdx.dll'):
                        loaded[str(path)] = sha(path)
            except psutil.NoSuchProcess:
                pass
            time.sleep(.002)
    assert process.returncode == 0, process.returncode
    assert 'PASS: recovered lighting preset/defaults' in (folder / 'stdout.txt').read_text()
    assert any(Path(p).name.lower() == 'rgmain.dll' for p in loaded)
    mapping = binary.with_suffix('.map')
    assert 'verified_sinks' not in mapping.read_text().lower()
    sources = ['tests/PlayerLighting.h', 'tests/PlayerLighting.cpp', 'tests/P2LightingTest.cpp', 'modules/p2-lighting.json']
    receipt = {
        'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        'scope': 'Standalone recovered light state; not rendered player acceptance or P2 closure',
        'command': [str(binary)], 'cwd': str(folder), 'ROC_BUILD': env.get('ROC_BUILD'),
        'exit': process.returncode, 'exe_sha256': sha(binary), 'map_sha256': sha(mapping),
        'library_sha256': sha(ROOT / 'rebuild/2008-06/out/P2Lighting/linked/linked.lib'),
        'report_sha256': sha(ROOT / 'rebuild/2008-06/out/P2Lighting/report.json'),
        'stdout_sha256': sha(folder / 'stdout.txt'), 'loaded_dlls': loaded,
        'no_verified_sinks_in_map': True,
        'source_sha256': {f'rebuild/2008-06/{p}': sha(ROOT / 'rebuild/2008-06' / p) for p in sources},
        'target_evidence_sha256': sha(folder.parent / 'native-lighting-evidence.json'),
        'limits': ['No GL/GPU rendering exercised.', 'Complete Lighting/View/RenderScene ABI not established.', 'Sky environment map not exercised.', 'No new server exact-function credit.'],
    }
    (folder / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print('PASS: normal recovered lighting test, loaded DLL identity, source/output hashes')


if __name__ == '__main__':
    record()
