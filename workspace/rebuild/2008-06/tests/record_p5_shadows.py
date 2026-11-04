"""Validate visible, moving, and removed stencil shadows against a no-shadow control."""
import hashlib, json, pathlib, subprocess, sys
import numpy as np
from PIL import Image
root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
fixtures = root / 'rebuild/2008-06/tests/fixtures'
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
cases = {}
for name, fixture, frames in [('center','p5-shadow-center.rbxl',3), ('sphere','p5-shadow-sphere.rbxl',3), ('cylinder','p5-shadow-cylinder.rbxl',3), ('empty','p5-shadow-empty.rbxl',3), ('before','p5-shadow-moving.rbxl',15), ('after','p5-shadow-moving.rbxl',60), ('removed','p5-shadow-remove.rbxl',60)]:
    images = {}
    for enabled in (True, False):
        folder = out / (name + ('-on' if enabled else '-off'))
        folder.mkdir()
        args = [str(exe), '--demo', '--p5-play', *([] if enabled else ['--no-shadows']), '--frames', str(frames), '--inspect-place', str(fixtures / fixture)]
        run = subprocess.run(args, cwd=folder, capture_output=True, text=True, timeout=90)
        assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout, (name, enabled, run.returncode)
        assert '[output]    stack end' not in run.stdout
        images[enabled] = np.array(Image.open(folder / 'last.png').convert('RGB'), dtype=np.int16)
    assert images[True].shape == images[False].shape == (600, 800, 3)
    diff = np.mean(images[False] - images[True], axis=2)
    mask = diff > 12
    mask[:250,:] = False
    mask[420:,:] = False
    y,x = np.where(mask)
    cases[name] = {'dark_pixels': int(len(x)), 'centroid_x': float(x.mean()) if len(x) else None, 'fixture_sha256': sha(fixtures / fixture), 'on_sha256': sha(out / (name+'-on/last.png')), 'off_sha256': sha(out / (name+'-off/last.png'))}
    print(name, 'dark pixels', len(x), flush=True)
assert 1000 < cases['center']['dark_pixels'] < 50000
assert cases['sphere']['dark_pixels'] > 500 and cases['cylinder']['dark_pixels'] > 500
assert cases['empty']['dark_pixels'] < 10 and cases['removed']['dark_pixels'] < 10
assert cases['before']['dark_pixels'] > 1000 and cases['after']['dark_pixels'] > 1000
assert cases['after']['centroid_x'] - cases['before']['centroid_x'] > 150
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), 'exe_sha256': sha(exe), 'observer_sha256': sha(pathlib.Path(__file__)), 'cases': cases, 'scope': 'Stencil shadow visibility on authored floor, moving and removed part, plus disabled-shadow and empty controls. Original-client shadow fidelity and large-mesh coverage remain open.', 'P5_complete': False}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('shadow controls PASS')
