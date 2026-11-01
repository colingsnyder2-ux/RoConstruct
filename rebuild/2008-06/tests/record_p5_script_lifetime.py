"""Exercise repeated removal of queued scripts and their containing model."""
import hashlib,json,pathlib,subprocess,sys
root=pathlib.Path(__file__).resolve().parents[3];exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
fixtures=root/'rebuild/2008-06/tests/fixtures';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();cases={}
for name in ['p5-script-removed.rbxl','p5-script-subtree-removed.rbxl']:
 p=fixtures/name;exits=[]
 for i in range(8):
  x=subprocess.run([str(exe),'--p5-play','--frames','10',str(p)],cwd=out,capture_output=True,text=True,timeout=90)
  assert x.returncode==0 and '[output] FIRST_PASS' in x.stdout and 'VICTIM_RAN' not in x.stdout and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in x.stdout,(name,i,x.returncode)
  exits.append(x.returncode)
 cases[name]={'fixture_sha256':sha(p),'exits':exits}
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'exe_sha256':sha(exe),'test_sha256':sha(pathlib.Path(__file__)),'cases':cases,'scope':'Repeated detached script shutdown cases; not proof of native parity.'}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('detached scripts: 16 clean runs')
