"""Exercise original Novetus 2008 character animation and sound assets."""
import csv, hashlib, json, pathlib, shutil, subprocess, sys, xml.etree.ElementTree as ET
root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
fixture = root / 'rebuild/2008-06/tests/fixtures/p5-spawn-floor.rbxl'
content = pathlib.Path(sys.argv[2]).resolve()
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
assets = ['fonts/character.rbxm', 'fonts/humanoidAnimate.rbxm', 'fonts/humanoidHealth.rbxm', 'fonts/humanoidSound.rbxm', 'sounds/swoosh.wav']
asset_hashes = {name: sha(content / name) for name in assets}
# Negative control edits only an isolated local copy of the user's content.
control = out / 'disabled-content'
shutil.copytree(content, control)
animate = control / 'fonts/humanoidAnimate.rbxm'
tree = ET.parse(animate)
source = tree.find(".//string[@name='Source']")
assert source is not None and 'Humanoid.Running' in source.text
source.text = '-- Animation deliberately disabled for test control.'
tree.write(animate, encoding='utf-8', short_empty_elements=False)
cases = {}
for name, asset_root, moving in [('idle', content, False), ('walk', content, True), ('disabled', control, True)]:
    folder = out / name
    folder.mkdir()
    flags = ['--p5-input-test'] if moving else []
    run = subprocess.run([str(exe), '--content-root', str(asset_root), '--p5-animate-observe', *flags, '--frames', '300', '--inspect-place', str(fixture)], cwd=folder, capture_output=True, text=True, timeout=120)
    assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout, (name, run.returncode)
    assert '[output]    stack end' not in run.stdout
    with (folder / 'animate_samples.csv').open() as f:
        rows = list(csv.DictReader(f))
    assert len(rows) == 300
    def span(key, first, last):
        v = [float(row[key]) for row in rows[first-1:last]]
        return [min(v), max(v)]
    desired = span('right_hip_desired', 100, 210)
    current = span('right_hip_current', 100, 210)
    stopped = span('right_hip_desired', 240, 300)
    if name == 'walk':
        assert desired[0] < -.5 and desired[1] > .5 and current[1] - current[0] > .5, (name, desired, current)
        assert max(abs(v) for v in stopped) < .2, (name, stopped)
    else:
        assert max(abs(v) for v in desired + current) < .15, (name, desired, current)
    cases[name] = {'exit': run.returncode, 'hip_desired_range': desired, 'hip_current_range': current, 'stopped_desired_range': stopped, 'samples_sha256': sha(folder / 'animate_samples.csv')}
    print(name, 'PASS', flush=True)
assert asset_hashes == {name: sha(content / name) for name in assets}
check_dir = out / 'notifier'
check_dir.mkdir()
check = subprocess.run([str(exe), '--p5-notifier-check', str(root / 'rebuild/2008-06/tests/fixtures/p5-humanoid-idle.rbxl')], cwd=check_dir, capture_output=True, text=True, timeout=60)
assert check.returncode == 0 and 'notifier mutation: PASS (0)' in check.stdout
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), 'exe_sha256': sha(exe), 'fixture_sha256': sha(fixture), 'observer_sha256': sha(pathlib.Path(__file__)), 'assets_sha256': asset_hashes, 'cases': cases, 'notifier_mutation': 'PASS', 'scope': 'Original local Novetus 2008M asset scripts: movement, stop, disabled-script control, sound-path startup and listener mutation. Original-client animation and audible playback remain unverified.', 'P5_complete': False}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('notifier mutation PASS')
