"""Verify a disk place retains its Humanoid through deserialization and shutdown."""
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
    binary = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    fixture = root / 'rebuild/2008-06/tests/fixtures/humanoid-load.rbxl'
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    args = [str(binary), '--load-only', str(fixture)]
    run = subprocess.run(args, cwd=output, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=30)
    (output / 'stdout.txt').write_bytes(run.stdout)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'fixture_sha256': sha(fixture), 'observer_sha256': sha(Path(__file__)),
               'command': args, 'cwd': str(output), 'exit': run.returncode,
               'scope': 'Humanoid deserialization and shutdown; no character play or animation claim.'}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    assert run.returncode == 0, run.stdout[-1500:]
    assert b'load-only: humanoids=1; closing' in run.stdout and b'load-only: complete' in run.stdout
    print('Humanoid deserialization PASS: one Humanoid retained; clean exit')


if __name__ == '__main__':
    main()
