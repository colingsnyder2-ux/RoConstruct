import hashlib,json,subprocess,time
from pathlib import Path
root=Path.cwd();out=root/'work/2008-06/p5-controller-stress-1f22f9eb1c';exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';fixture=root/'rebuild/2008-06/tests/fixtures/p5-humanoid-idle.rbxl'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'exe_sha256':sha(exe),'fixture_sha256':sha(fixture),'observer_sha256':sha(out/'stress.py'),'runs':[],'scope':'Eight separate fixed-step controller starts after D3D9 precision fix; not a long-duration soak.'}
for i in range(8):
 folder=out/str(i);folder.mkdir();mode='--p5-input-test' if i%2 else '--p5-control';t=time.monotonic()
 try:
  run=subprocess.run([str(exe),'--p5-join','--p5-play',mode,'--frames','120',str(fixture)],cwd=folder,capture_output=True,text=True,timeout=12)
  result={'mode':mode,'exit':run.returncode,'seconds':round(time.monotonic()-t,3)}
  assert run.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
 except subprocess.TimeoutExpired:
  result={'mode':mode,'timeout':True};receipt['runs'].append(result);(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');raise
 receipt['runs'].append(result);print(i,mode,'PASS',flush=True)
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
