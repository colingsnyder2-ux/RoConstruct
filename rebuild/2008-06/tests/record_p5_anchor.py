"""Exercise serialized runtime anchor transitions; original physics parity stays open."""
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURE = ROOT / 'rebuild/2008-06/tests/fixtures/p5-anchor-cycle.rbxl'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    out = ROOT / 'work/2008-06' / sys.argv[1]
    out.mkdir(exist_ok=False)
    receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(),
               'exe_sha256': sha(EXE), 'fixture_sha256': sha(FIXTURE), 'observer_sha256': sha(Path(__file__)),
               'scope': 'Fixed-step Lua-driven anchor cycle in rebuilt player with tracked anchor/heartbeat shims.',
               'P5_complete': False, 'runs': {}, 'remaining': ['Original fixed-step physics comparison',
               'Native AnchorJoint/FreeJoint integration', 'Normal launch, character input and controller']}
    tracks = []
    for name, play, frames in [('edit',False,50),('cycle',True,600),('reopen',True,600)]:
        folder = out / name
        folder.mkdir()
        command = [str(EXE)] + (['--p5-play'] if play else []) + ['--frames',str(frames),'--anchor-trace',str(FIXTURE)]
        run = subprocess.run(command, cwd=folder, capture_output=True, text=True, timeout=90)
        (folder/'stdout.txt').write_text(run.stdout + run.stderr)
        assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
        with (folder/'anchor_samples.csv').open() as stream:
            samples = list(csv.DictReader(stream))
        assert len(samples) == frames
        y = [float(row['brick_y']) for row in samples]
        anchored = [int(row['brick_anchored']) for row in samples]
        assert all(row['floor_anchored']=='1' and abs(float(row['floor_y'])+5)<.0001 for row in samples)
        if not play:
            assert set(anchored)=={1} and max(y)-min(y)<.0001 and abs(y[0]-20)<.0001
            changes=[]
        else:
            changes=[i+1 for i in range(1,len(anchored)) if anchored[i]!=anchored[i-1]]
            assert changes==[6,15,24], changes
            assert anchored[:5]==[1]*5 and anchored[5:14]==[0]*9 and anchored[14:23]==[1]*9 and not any(anchored[23:])
            assert y[13]<y[6]<20 and max(y[14:24])-min(y[14:24])<.0001 and y[29]<y[24]
            assert all(abs(value+3.8)<.01 for value in y[300:]) and max(y[300:])-min(y[300:])<.002
            tracks.append(y)
        receipt['runs'][name]={'exit':run.returncode,'frames':frames,'transitions':changes,
            'first_y':y[0],'last_y':y[-1],'tail_min':min(y[-100:]),'tail_max':max(y[-100:]),
            'samples_sha256':sha(folder/'anchor_samples.csv')}
        print(name,'PASS',flush=True)
    receipt['reopen_max_delta'] = max(abs(a-b) for a,b in zip(*tracks))
    assert receipt['reopen_max_delta'] < .0001
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')


if __name__ == '__main__':
    main()
