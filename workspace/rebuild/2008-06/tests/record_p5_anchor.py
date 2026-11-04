"""Exercise serialized runtime anchor transitions; original physics parity stays open."""
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURES = ROOT / 'rebuild/2008-06/tests/fixtures'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    out = ROOT / 'work/2008-06' / sys.argv[1]
    out.mkdir(exist_ok=False)
    fixture = FIXTURES / 'p5-anchor-cycle.rbxl'
    receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(),
               'exe_sha256': sha(EXE), 'fixture_sha256': sha(fixture), 'observer_sha256': sha(Path(__file__)),
               'scope': 'Fixed-step Lua-driven AnchorJoint/FreeJoint cycles through source-derived tree/assembly/sleep pipeline; heartbeat adapter remains.',
               'P5_complete': False, 'runs': {}, 'remaining': ['Original fixed-step physics comparison',
               'Complete June tree/assembly/sleep ABI and physics equivalence', 'Normal launch, character input and controller']}
    link_map = EXE.with_suffix('.map')
    text = link_map.read_text()
    assert 'glue_anchor_registry' not in text and '?getAnchorObject@Primitive@' not in text
    for name in ('CollisionStage.obj', 'SeparateStage.obj'):
        assert not (ROOT/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs'/name).exists()
        assert 'linked:'+name not in text
    assert not (ROOT/'rebuild/2008-06/out/RbxgsApp/layer-glue/glue_anchor_registry.obj').exists()
    prefixes=('?onPrimitiveAddedAnchor@ClumpStage@RBX@@','?onPrimitiveRemovingAnchor@ClumpStage@RBX@@')
    providers=[line.strip() for line in text.splitlines() if len(line.split())>1 and line.split()[1].startswith(prefixes)]
    assert len(providers)==2 and all('ClumpStage.obj' in line for line in providers)
    receipt.update(map_sha256=sha(link_map), providers=providers, retired_objects_absent=True)
    tracks = []
    for name, play, frames in [('edit',False,50),('cycle',True,600),('reopen',True,600),('overlap',True,600)]:
        fixture = FIXTURES / ('p5-anchor-overlap.rbxl' if name == 'overlap' else 'p5-anchor-cycle.rbxl')
        folder = out / name
        folder.mkdir()
        command = [str(EXE)] + (['--p5-play'] if play else []) + ['--frames',str(frames),'--anchor-trace',str(fixture)]
        run = subprocess.run(command, cwd=folder, capture_output=True, text=True, timeout=90)
        (folder/'stdout.txt').write_text(run.stdout + run.stderr)
        assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
        with (folder/'anchor_samples.csv').open() as stream:
            samples = list(csv.DictReader(stream))
        assert len(samples) == frames
        y = [float(row['brick_y']) for row in samples]
        anchored = [int(row['brick_anchored']) for row in samples]
        assert all(row['floor_anchored']=='1' and abs(float(row['floor_y'])+5)<.0001 for row in samples)
        dragging = [int(row['dragging']) for row in samples]
        aggregate = [int(row['aggregate']) for row in samples]
        assert all(a == (b or c) for a,b,c in zip(aggregate,anchored,dragging))
        if name == 'overlap':
            changes=[i+1 for i in range(1,len(anchored)) if (anchored[i],dragging[i])!=(anchored[i-1],dragging[i-1])]
            assert changes == [6,12,18], changes
            assert (anchored[0],dragging[0],aggregate[0]) == (0,1,1)
            assert (anchored[5],dragging[5],aggregate[5]) == (1,1,1)
            assert (anchored[11],dragging[11],aggregate[11]) == (1,0,1)
            assert (anchored[17],dragging[17],aggregate[17]) == (0,0,0)
            assert max(y[:18])-min(y[:18])<.0001 and y[30]<y[18]
            assert all(abs(value+3.8)<.01 for value in y[300:]) and max(y[300:])-min(y[300:])<.002
        elif not play:
            assert set(anchored)=={1} and max(y)-min(y)<.0001 and abs(y[0]-20)<.0001
            changes=[]
        else:
            changes=[i+1 for i in range(1,len(anchored)) if anchored[i]!=anchored[i-1]]
            assert changes==[6,16,26], changes
            assert anchored[:5]==[1]*5 and anchored[5:15]==[0]*10 and anchored[15:25]==[1]*10 and not any(anchored[25:])
            # Wake-pending may consume the first two free frames; the independent
            # original comparison already permits a +/-3-frame timing window.
            assert y[14]<y[8]<20 and max(y[15:26])-min(y[15:26])<.0001 and y[31]<y[26]
            assert all(abs(value+3.8)<.01 for value in y[300:]) and max(y[300:])-min(y[300:])<.002
            tracks.append(y)
        receipt['runs'][name]={'exit':run.returncode,'frames':frames,'transitions':changes,
            'first_y':y[0],'last_y':y[-1],'tail_min':min(y[-100:]),'tail_max':max(y[-100:]),
            'fixture_sha256':sha(fixture),'samples_sha256':sha(folder/'anchor_samples.csv')}
        print(name,'PASS',flush=True)
    flags = out / 'flags'
    flags.mkdir()
    run = subprocess.run([str(EXE),'--anchor-flags-test',str(FIXTURES/'p5-anchor-overlap.rbxl')],
                         cwd=flags,capture_output=True,text=True,timeout=30)
    (flags/'stdout.txt').write_text(run.stdout + run.stderr)
    assert run.returncode == 0 and 'anchor flags: PASS' in run.stdout
    assert 'ground joint swap: PASS' in run.stdout
    receipt['runs']['flags']={'exit':run.returncode,'combinations':8}
    print('flags PASS',flush=True)
    receipt['reopen_max_delta'] = max(abs(a-b) for a,b in zip(*tracks))
    assert receipt['reopen_max_delta'] < .0001
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')


if __name__ == '__main__':
    main()
