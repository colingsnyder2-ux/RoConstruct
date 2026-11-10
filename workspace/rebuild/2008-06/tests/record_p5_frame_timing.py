"""Verify simulation ticks under zero, fractional, and accumulated frame times."""
import hashlib, json, pathlib, subprocess, sys
root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
fixture = root / 'rebuild/2008-06/tests/fixtures/p5-humanoid-idle.rbxl'
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
run = subprocess.run([str(exe), '--p5-timing-check', str(fixture)], cwd=out, capture_output=True, text=True, timeout=90)
assert run.returncode == 0 and 'timing check: PASS half=0.000000 one=0.033333 three=0.100000' in run.stdout
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), 'exe_sha256': sha(exe), 'fixture_sha256': sha(fixture), 'observer_sha256': sha(pathlib.Path(__file__)), 'result': 'half=0 one=0.033333 three=0.100000', 'scope': 'Harness batching and zero-time behavior; native scheduler and run-mode parity unproven.', 'P5_complete': False}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('frame timing PASS')
