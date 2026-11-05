"""Exercise joint-owner cleanup when actor starts in contact with the floor."""
import csv, hashlib, json, pathlib, subprocess, sys
root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
fixture = root / 'rebuild/2008-06/tests/fixtures/p5-initial-joint-contact.rbxl'
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
runs = []
for n in (1, 2):
    folder = out / str(n)
    folder.mkdir()
    run = subprocess.run([str(exe), '--p5-join', '--p5-play', '--frames', '120', '--inspect-place', str(fixture)], cwd=folder, capture_output=True, text=True, timeout=90)
    assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
    with (folder / 'place_snapshot.csv').open() as f:
        rows = list(csv.DictReader(f))
    assert len(rows) == 7 and all(row['status'] == '0' for row in rows)
    runs.append({'exit': run.returncode, 'snapshot_sha256': sha(folder / 'place_snapshot.csv')})
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), 'exe_sha256': sha(exe), 'fixture_sha256': sha(fixture), 'observer_sha256': sha(pathlib.Path(__file__)), 'runs': runs, 'scope': 'Repeated initial-contact lifecycle and clean shutdown; native joint parity unproven.', 'P5_complete': False}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('initial-contact lifecycle PASS')
