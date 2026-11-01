"""Record partial original-character spawn; script support remains open."""
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURE = ROOT / 'rebuild/2008-06/tests/fixtures/p5-spawn-floor.rbxl'
CONTENT = EXE.parent / 'Content/fonts'

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    out = ROOT / 'work/2008-06' / sys.argv[1]
    out.mkdir(exist_ok=False)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               'exe_sha256': sha(EXE), 'fixture_sha256': sha(FIXTURE), 'observer_sha256': sha(Path(__file__)),
               'assets_sha256': {name: sha(CONTENT / name) for name in ('character.rbxm','humanoidSound.rbxm','humanoidHealth.rbxm','humanoidAnimate.rbxm')},
               'P5_complete': False, 'remaining': ['Original sound and animation scripts', 'Normal launch, camera, physics and scheduler parity'], 'runs': {}}
    for name, flags in [('hash', ['--p5-hash-check']), ('idle', ['--p5-spawn']), ('input', ['--p5-spawn', '--p5-input-test'])]:
        folder = out / name
        folder.mkdir()
        args = [str(EXE)] + flags + ([] if name == 'hash' else ['--frames','120','--inspect-place',str(FIXTURE)])
        run = subprocess.run(args, cwd=folder, capture_output=True, text=True, timeout=60)
        (folder/'stdout.txt').write_text(run.stdout + run.stderr)
        assert run.returncode == 0, (name, run.returncode)
        if name == 'hash':
            assert 'MD5 vectors: PASS (0)' in run.stdout
        else:
            assert 'scene attached: 7 model(s)' in run.stdout
            assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
            assert 'FreeFalling is not a valid member of Humanoid' in run.stdout
            with (folder/'place_snapshot.csv').open() as stream:
                rows = list(csv.DictReader(stream))
            assert len(rows) == 7 and all(r['status'] == '0' for r in rows)
            assert int(rows[1]['source_indices']) == 1944 and int(rows[1]['backend_indices']) == 2916
            assert 'native mesh: producer=00500180' in run.stdout
            torso = [float(rows[2][k]) for k in ('x','y','z')]
            assert abs(torso[1] - 2.8) < .1
            assert (24 < torso[2] < 27) if name == 'idle' else (8 < torso[2] < 11)
            receipt['runs'][name] = {'exit': run.returncode, 'torso': torso, 'head_mesh_status': 0, 'snapshot_sha256': sha(folder/'place_snapshot.csv')}
            continue
        receipt['runs'][name] = {'exit': run.returncode}
    (out/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print('MD5 and partial spawn/movement: PASS; scripts remain open')

if __name__ == '__main__':
    main()
