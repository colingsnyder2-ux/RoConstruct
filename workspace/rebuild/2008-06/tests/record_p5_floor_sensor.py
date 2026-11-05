"""Check floor sensing at the torso corner and beyond all corners."""
import csv, hashlib, json, pathlib, subprocess, sys
root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
cases = {}
for name in ('edge', 'outside'):
    fixture = root / ('rebuild/2008-06/tests/fixtures/p5-floor-' + name + '.rbxl')
    folder = out / name
    folder.mkdir()
    run = subprocess.run([str(exe), '--p5-join', '--p5-play', '--frames', '120', '--inspect-place', str(fixture)], cwd=folder, capture_output=True, text=True, timeout=90)
    assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
    with (folder / 'place_snapshot.csv').open() as f:
        rows = list(csv.DictReader(f))
    assert len(rows) >= 7 and all(row['status'] == '0' for row in rows)
    torso = [float(rows[1][key]) for key in ('x', 'y', 'z')]
    assert abs(torso[1] - 3) < 0.1 if name == 'edge' else torso[1] < -10, (name, torso)
    cases[name] = {'torso': torso, 'fixture_sha256': sha(fixture), 'snapshot_sha256': sha(folder / 'place_snapshot.csv')}
    print(name, 'PASS', flush=True)
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), 'exe_sha256': sha(exe), 'observer_sha256': sha(pathlib.Path(__file__)), 'cases': cases, 'scope': 'Adapted 00644000 floor rays on donor ABI; native parity and P5 completion remain unproven.', 'P5_complete': False}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
