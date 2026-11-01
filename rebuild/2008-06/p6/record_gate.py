"""Repeat the scoped P6 gate against this checkout's merged client.
Caller holds DESKTOP LOCK. Existing input observers kill only their own PIDs.
"""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).parent
EXE = ROOT / 'rebuild/2008-06/out/p6/Roblox.exe'
OUT = ROOT / 'work/2008-06' / sys.argv[1]
OUT.mkdir(exist_ok=False)
FIXTURES = ROOT / 'rebuild/2008-06/tests/fixtures'
PLACE = FIXTURES / 'lifetime-blocks.rbxl'
PLAY = EXE.parent / 'Places/p5-playable.rbxl'
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
runs = {}


def run(name, command, expected=0):
    result = subprocess.run([str(value) for value in command], cwd=OUT,
                            capture_output=True, text=True, errors='replace', timeout=90)
    text = result.stdout + result.stderr
    (OUT / (name + '.txt')).write_text(text)
    runs[name] = dict(command=[str(value) for value in command], exit=result.returncode)
    assert result.returncode == expected, (name, result.returncode, text[-1000:])
    print(name, 'PASS', flush=True)
    return text


assert pefile.PE(str(EXE)).FILE_HEADER.Machine == 0x14c
link_map = EXE.with_suffix('.map')
text = link_map.read_text()
assert '_WinMain@16' in text and '?InitInstance@CRobloxApp@@' in text
saved = OUT / 'gate.rbxl'
edit = run('edit-save', [EXE, '-p6-autoclose', '-p6-select', 'Brick', '-p6-setprop', 'Name=Renamed',
                       '-p6-script', 'game.Workspace.Brick.CFrame = CFrame.new(3,4,5)',
                       '-p6-saveas', saved, PLACE])
assert 'p6: engine open 0' in edit and 'p6: save ok' in edit and 'p6: part 3 4 5' in edit
assert 'menus=8' in edit and 'p6-stage:' in edit and 'p6: ExitInstance' in edit
reopened = run('reopen', [EXE, '-p6-autoclose', '-p6-select', 'Renamed', saved])
assert 'p6: select Renamed found' in reopened and 'p6: part 3 4 5' in reopened
run('bad-path', [EXE, '-p6-autoclose', OUT / 'missing.rbxl'], expected=1)
commands = run('commands', [EXE, '-p6-autoclose', '-p6-script', 'print("p6-output-marker")',
                           '-p6-command', '32966,32967,32968,57664', PLACE])
assert all('p6: command '+value in commands for value in ('32966', '32967', '32968', '57664'))
assert 'marker=1' in commands and 'p6: about 2' in commands
ordinary = run('ordinary-launch-twice', [sys.executable, HERE / 'ordinary_launch.py', EXE, PLACE])
assert 'run 1 exit 0' in ordinary and 'run 2 exit 0' in ordinary
for index in range(3):
    movement = run('real-input-'+str(index), [sys.executable, HERE / 'input_test.py', EXE, PLAY])
    actor = re.findall(r'p6: actor (\S+) (\S+) (\S+)', movement)
    assert actor and float(actor[-1][2]) < 24.5 and abs(float(actor[-1][1])-3) < .2, actor
    assert 'held samples 30' in movement and 'lost focus False' in movement
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in movement
click = run('real-click-drag', [sys.executable, HERE / 'click_test.py', EXE, PLACE, OUT / 'click.png'])
assert 'selected True exit 0' in click
original = run('original-opens-save', [sys.executable, HERE / 'original_check.py',
               ROOT / 'work/2008-06/original-p4-reference/Roblox.exe', saved, OUT / 'original.png'])
assert 'alive True windows 1' in original and 'title Roblox - [gate.rbxl]' in original
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               exe_sha256=sha(EXE), map_sha256=sha(link_map), observer_sha256=sha(Path(__file__)),
               runtime_manifest_sha256=sha(EXE.parent / 'runtime-stage.json'),
               fixture_sha256=sha(PLACE), saved_sha256=sha(saved), runs=runs,
               P6_scoped_gate='PASS', P6_native_complete=False,
               scope='Merged MFC shell gate: x86, ordinary open/close twice, real input three times, edit/save/reopen, commands, selection, and original-client open control. Recovered CRobloxApp/CMainFrame and native layouts remain open.')
(OUT / 'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('P6 SCOPED GATE PASS', flush=True)
