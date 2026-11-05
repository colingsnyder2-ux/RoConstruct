"""Record opt-in play transition and Lua scheduling controls, not P5 completion."""
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURES = ROOT / 'rebuild/2008-06/tests/fixtures'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    out = ROOT / 'work/2008-06' / sys.argv[1]
    out.mkdir(exist_ok=False)
    cases = [('edit', 'p5-script-baseline.rbxl', False, 10, [0, 0, 0]),
             ('play', 'p5-script-baseline.rbxl', True, 10, [3, 4, 5]),
             ('wait-early', 'p5-script-wait.rbxl', True, 1, [0, 0, 0]),
             ('wait-complete', 'p5-script-wait.rbxl', True, 10, [3, 4, 5]),
             ('disabled', 'p5-script-disabled.rbxl', True, 10, [0, 0, 0])]
    receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(),
               'exe_sha256': sha(EXE), 'observer_sha256': sha(Path(__file__)), 'cases': {},
               'P5_complete': False,
               'scope': 'Serialized Script, opt-in RunService transition and shimmed fixed-step heartbeat.',
               'remaining': ['Original frame-loop and scheduler parity', 'Normal-launch controls and character movement',
                             'Runtime anchor transitions and original fixed-step comparison']}
    for name, fixture, play, frames, expected in cases:
        folder = out / name
        folder.mkdir()
        command = [str(EXE)] + (['--p5-play'] if play else []) + ['--frames',str(frames),'--inspect-place',str(FIXTURES / fixture)]
        run = subprocess.run(command, cwd=folder, capture_output=True, text=True, timeout=90)
        (folder / 'stdout.txt').write_text(run.stdout + run.stderr)
        assert run.returncode == 0, (name, run.returncode)
        assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
        with (folder / 'place_snapshot.csv').open() as stream:
            rows = list(csv.DictReader(stream))
        assert len(rows) == 1 and [float(rows[0][x]) for x in ('x','y','z')] == expected, (name, rows)
        receipt['cases'][name] = {'fixture_sha256': sha(FIXTURES / fixture), 'position': expected,
                                  'frames': frames, 'play': play, 'exit': run.returncode}
        print(name, 'PASS')
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')


if __name__ == '__main__':
    main()
