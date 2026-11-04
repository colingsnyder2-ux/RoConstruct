"""Check contact cleanup and scripts removed before their queued start."""
import csv, hashlib, json, pathlib, subprocess, sys
root=pathlib.Path(__file__).resolve().parents[3]
exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
fixtures=root/'rebuild/2008-06/tests/fixtures'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
results={}
for name,fixture,flags in [('contact','p5-ball-block-miss.rbxl',[]),('removed-script','p5-script-removed.rbxl',['--p5-play'])]:
 folder=out/name;folder.mkdir();p=fixtures/fixture
 run=subprocess.run([str(exe),*flags,'--frames','10','--inspect-place',str(p)],cwd=folder,capture_output=True,text=True,timeout=90)
 assert run.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout, (name,run.returncode,run.stdout,run.stderr)
 if name=='removed-script':
  assert '[output] FIRST_PASS' in run.stdout and 'VICTIM_RAN' not in run.stdout
  with (folder/'place_snapshot.csv').open() as stream:rows=list(csv.DictReader(stream))
  assert len(rows)==1 and [float(rows[0][x]) for x in ('x','y','z')]==[3,4,5]
 results[name]={'exit':run.returncode,'fixture_sha256':sha(p)}
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'exe_sha256':sha(exe),'test_sha256':sha(pathlib.Path(__file__)),'cases':results,'scope':'Two authored regression cases; not original-client parity.'}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('contact and removed script PASS')
