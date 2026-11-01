"""Record original-derived climb sensor controls; state and forces remain open."""
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
    receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               'exe_sha256': sha(EXE), 'observer_sha256': sha(Path(__file__)), 'P5_complete': False,
               'scope': 'Diagnostic port of original candidate box and ray sweep using rebuilt contact manager.',
               'remaining': ['Original-client comparison', 'Filtering parity', 'Climb state and forces'], 'cases': {}}
    for name,fixture,expected in [('empty','p5-humanoid-idle.rbxl',0),('rung','p5-climb-rung.rbxl',1),
                                  ('distant','p5-climb-distant.rbxl',0),('tall','p5-climb-tall.rbxl',0),
                                  ('behind','p5-climb-behind.rbxl',0),('self','p5-climb-self.rbxl',0)]:
        path=FIXTURES/fixture
        run=subprocess.run([str(EXE),'--p5-climb-probe',str(path)],cwd=out,capture_output=True,text=True,timeout=30)
        (out/(name+'.txt')).write_text(run.stdout+run.stderr)
        assert run.returncode==0 and f'climb probe: {expected}' in run.stdout, (name,run.returncode,run.stdout)
        receipt['cases'][name]={'exit':run.returncode,'detected':expected,'fixture_sha256':sha(path)}
        print(name,'PASS')
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')

if __name__=='__main__':
    main()
