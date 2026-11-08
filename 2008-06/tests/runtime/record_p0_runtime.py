"""Record direct P0 processes from an explicitly selected checkout."""
import csv
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

import psutil


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    root = Path(sys.argv[1]).resolve()
    output = root / 'work/2008-06' / sys.argv[2]
    output.mkdir(exist_ok=False)
    binary = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    fixture = root / 'rebuild/2008-06/tests/fixtures/falling.rbxl'
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    receipt = {
        'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
        'checkout': str(root), 'exe_sha256': sha(binary),
        'map_sha256': sha(binary.with_suffix('.map')), 'fixture_sha256': sha(fixture),
        'environment_removed': ['ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'],
        'runs': {}, 'loaded_dlls': {},
        'scope': 'Direct runtime evidence only; source export and clean-build provenance require separate audit.',
    }
    runs = [('selftest', ['--selftest'], 0),
            ('falling240', ['--frames', '240', str(fixture)], 0),
            ('stability600', ['--frames', '600', '--stability-test', str(fixture)], 0),
            ('missing-place', ['--frames', '240', str(output / 'absent.rbxl')], 1)]
    for name, args, expected_exit in runs:
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
        run = {'command': [str(binary), *args], 'cwd': str(folder), 'exit': process.returncode}
        receipt['runs'][name] = run
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
        assert process.returncode == expected_exit, run
        if name == 'selftest':
            result = json.loads((folder / 'selftest_result.json').read_text())
            assert result['failures'] == 0
            assert all(result[state]['pass'] for state in ('initial', 'moved', 'removed', 'empty'))
            run['result'] = result
        elif name == 'stability600':
            result = json.loads((folder / 'stability_result.json').read_text())
            samples = list(csv.DictReader((folder / 'stability_samples.csv').open()))
            assert result['pass'] and len(samples) == 600
            assert all(int(s['anchored']) == 1 for s in samples)
            assert all(abs(float(s['floor_y']) + 5) < .0001 for s in samples)
            assert all(abs(float(s['expected_y']) + 3.8) < .0001 for s in samples)
            tail = [float(s['brick_y']) for s in samples[300:]]
            assert all(abs(y + 3.8) <= .01 for y in tail)
            assert max(tail) - min(tail) <= .002
            run['result'] = result
            run['independent_csv_audit'] = {'samples': len(samples), 'tail': len(tail),
                                            'min': min(tail), 'max': max(tail)}
        run['files'] = {p.name: sha(p) for p in folder.iterdir() if p.is_file()}
        print(name, process.returncode, flush=True)
    assert {Path(p).name.lower() for p in receipt['loaded_dlls']} == {'rgmain.dll', 'rgdx.dll'}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')


if __name__ == '__main__':
    main()
