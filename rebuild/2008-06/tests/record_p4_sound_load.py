"""Record Sound deserialization against authored fixtures."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'work/2008-06' / sys.argv[1]
OUT.mkdir(exist_ok=False)
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def run(name, fixture):
    result = subprocess.run([str(EXE), '--load-only', str(fixture)], cwd=OUT,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, timeout=60)
    (OUT / (name + '.txt')).write_text(result.stdout)
    assert result.returncode == 0
    direct = re.search(r'humanoids=(\d+); closing', result.stdout)
    named = re.search(r'named humanoids=(\d+) sounds=(\d+)', result.stdout)
    assert direct and named and direct.group(1) == named.group(1), result.stdout
    return {'humanoids': int(direct.group(1)), 'sounds': int(named.group(2)), 'fixture_sha256': sha(fixture)}


sound = run('sound', ROOT / 'rebuild/2008-06/tests/fixtures/sound-load.rbxl')
control = run('humanoid', ROOT / 'rebuild/2008-06/tests/fixtures/humanoid-load.rbxl')
assert sound['sounds'] == 1 and control['humanoids'] == 1
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
           'exe_sha256': sha(EXE), 'sound_fixture': sound, 'humanoid_control': control,
           'result': 'Sound fixture retains its serialized Sound; full P4 audio remains open.'}
(OUT / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(receipt['result'])
