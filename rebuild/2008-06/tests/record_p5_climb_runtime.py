"""Compare climb runtime against an otherwise identical noncollidable obstacle."""
import csv
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
EXE=ROOT/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURES=ROOT/'rebuild/2008-06/tests/fixtures'
def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    out=ROOT/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
    receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             'exe_sha256':sha(EXE),'observer_sha256':sha(Path(__file__)),'P5_complete':False,
             'scope':'Reconstructed climb state using recovered sensor, velocity and force formulas.',
             'remaining':['Original-client comparison','Native transition and solver parity','Full animation, sound and camera'],'cases':{}}
    for name,fixture,frames,pressed in [('climb','p5-climb-runtime-stable.rbxl',18,True),
                                         ('exit','p5-climb-runtime-stable.rbxl',30,True),
                                         ('control','p5-climb-runtime-stable-control.rbxl',18,True),
                                         ('idle','p5-climb-runtime-stable.rbxl',30,False)]:
        folder=out/name;folder.mkdir();path=FIXTURES/fixture
        args=[str(EXE),'--p5-climb-observe']+(['--p5-input-test'] if pressed else [])+['--frames',str(frames),'--inspect-place',str(path)]
        run=subprocess.run(args,cwd=folder,capture_output=True,text=True,timeout=60)
        (folder/'stdout.txt').write_text(run.stdout+run.stderr)
        match=re.search(r'climb events: (\d+) max_speed=([0-9.eE+-]+) detected=(-?\d+)',run.stdout)
        assert run.returncode==0 and match and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout, (name,run.returncode)
        with (folder/'place_snapshot.csv').open() as stream: rows=list(csv.DictReader(stream))
        assert len(rows)>=3 and all(row['status']=='0' for row in rows)
        receipt['cases'][name]={'events':int(match[1]),'max_speed':float(match[2]),'detected':int(match[3]),
                                'torso_y':float(rows[1]['y']),'torso_z':float(rows[1]['z']),
                                'fixture_sha256':sha(path),'snapshot_sha256':sha(folder/'place_snapshot.csv'),
                                'lua_signal': 'CLIMB_SIGNAL' in run.stdout}
    c=receipt['cases'];assert c['climb']['events']>0 and c['climb']['max_speed']>1 and c['climb']['lua_signal']
    assert c['control']['events']==0 and not c['control']['lua_signal']
    assert c['climb']['torso_y']>c['control']['torso_y']+.5
    assert c['exit']['events']==c['climb']['events'] and c['exit']['detected']==0
    assert c['idle']['max_speed']==0 and not c['idle']['lua_signal'] and abs(c['idle']['torso_y']-c['control']['torso_y'])<.8
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print('climb, exit, Lua event, noncollidable control, idle: PASS')
if __name__=='__main__': main()
