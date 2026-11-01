"""Record a user-supplied place run without publishing the place or script output."""
import csv
import gzip
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
EXE=ROOT/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
def sha(data): return hashlib.sha256(data).hexdigest()
def main():
    out=ROOT/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False);place=Path(sys.argv[2]);raw=place.read_bytes()
    decoded=gzip.decompress(raw) if raw[:2]==b'\x1f\x8b' else raw
    run=subprocess.run([str(EXE),'--play','--frames','30','--inspect-place',str(place)],cwd=out,capture_output=True,text=True,timeout=120)
    (out/'private-output.txt').write_text(run.stdout+run.stderr)
    assert run.returncode==0 and 'player camera subject: attached (0)' in run.stdout
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
    match=re.search(r'scene attached: (\d+) model\(s\)',run.stdout);assert match
    with (out/'place_snapshot.csv').open() as stream: rows=list(csv.DictReader(stream))
    statuses={str(i):sum(r['status']==str(i) for r in rows) for i in range(5)}
    receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             'exe_sha256':sha(EXE.read_bytes()),'observer_sha256':sha(Path(__file__).read_bytes()),
             'input_sha256':sha(raw),'decoded_sha256':sha(decoded),'decoded_bytes':len(decoded),
             'exit':run.returncode,'initial_models':int(match[1]),'final_models':len(rows),'statuses':statuses,
             'script_error_stacks':run.stdout.count('[output]    stack end'),
             'missing_member_messages':sum('is not a valid member of' in line for line in run.stdout.splitlines()),
             'P5_complete':False,'scope':'Thirty-frame local supplied-place load; script/asset fidelity and gameplay not established.'}
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print('supplied place loaded:',receipt['initial_models'],'models; script error stacks:',receipt['script_error_stacks'])
if __name__=='__main__':main()
