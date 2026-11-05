"""Record the default reflection asset on a disk place in a normal environment."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

from PIL import Image


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    root = Path(__file__).resolve().parents[3]
    output = root / 'work/2008-06' / sys.argv[1]
    output.mkdir(exist_ok=False)
    binary = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    fixture = root / 'rebuild/2008-06/tests/fixtures/reflective-sphere.rbxl'
    asset = binary.parent / 'Content/sky/skyspheremap.jpg'
    env = os.environ.copy()
    for name in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
        env.pop(name, None)
    args = [str(binary), '--frames', '2', '--inspect-place', str(fixture)]
    run = subprocess.run(args, cwd=output, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=30)
    (output / 'stdout.txt').write_bytes(run.stdout)
    stdout = run.stdout.decode(errors='replace')
    log = (output / 'player.log').read_text(errors='replace') if (output / 'player.log').exists() else ''
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
               'fixture_sha256': sha(fixture), 'original_external_asset_sha256': sha(asset),
               'observer_sha256': sha(Path(__file__)), 'command': args, 'cwd': str(output), 'exit': run.returncode,
               'scope': 'Default reflection texture on one authored sphere; not complete real-place rendering.'}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    assert run.returncode == 0, stdout[-2000:]
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in stdout
    assert 'Texture: skysphmap: Loading' in log
    pixels = Image.open(output / 'last.png').convert('RGB')
    foreground = sum(pixel != (255, 0, 255) for pixel in pixels.getdata())
    assert foreground > 100
    receipt['foreground_pixels'] = foreground
    receipt['output_sha256'] = {p.name: sha(p) for p in output.iterdir() if p.is_file() and p.name != 'receipt.json'}
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print('P4 reflection PASS', foreground, 'pixels')


if __name__ == '__main__':
    main()
