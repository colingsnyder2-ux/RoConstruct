"""Exercise existing linked tracker ownership before generalizing native SimJob."""
import hashlib
import json
import pathlib
import subprocess
import sys

root = pathlib.Path(__file__).resolve().parents[3]
exe = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
run = subprocess.run([str(exe), '--p5-job-tracker-check'], cwd=out,
                     capture_output=True, text=True, timeout=30)
(out / 'stdout.txt').write_text(run.stdout + run.stderr)
assert run.returncode == 0 and 'job tracker ownership: PASS (0)' in run.stdout
assert 'SimJob base size=36' in run.stdout
assert 'SimJob stage lifecycle: PASS' in run.stdout
link_map = exe.with_suffix('.map')
provider = [line.strip() for line in link_map.read_text().splitlines()
            if '?transferTrackers@MechanismTracker@RBX@@' in line]
assert len(provider) == 1 and 'Mechanism.obj' in provider[0]
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               exe_sha256=sha(exe), observer_sha256=sha(pathlib.Path(__file__)),
               map_sha256=sha(link_map), provider=provider[0], exit=run.returncode,
               base_size=36,
               scope='Shared SimJob tracker lifetime, stage list insertion, middle removal, wraparound, final detach and selected provider. Native assembly binding and no-physics state integration remain open; no byte identity claim.',
               P5_complete=False)
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('linked tracker ownership PASS')
