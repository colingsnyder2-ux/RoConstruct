"""Combined input, collision, Lua and anchor transition check."""
import csv,hashlib,json,pathlib,subprocess,sys
import record_p5_play
root=pathlib.Path(__file__).resolve().parents[3];exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';fixture=root/'rebuild/2008-06/tests/fixtures/p5-combined-play.rbxl';out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();results={}
for name,pressed in [('idle',False),('play',True),('reopen',True)]:
 folder=out/name;folder.mkdir();x=subprocess.run([str(exe),'--play',*(['--p5-input-test'] if pressed else []),'--frames','360','--anchor-trace','--inspect-place',str(fixture)],cwd=folder,capture_output=True,text=True,timeout=90)
 (folder/'stdout.txt').write_text(x.stdout+x.stderr)
 assert x.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in x.stdout
 with (folder/'anchor_samples.csv').open() as f:rows=list(csv.DictReader(f))
 assert len(rows)==360
 y=[float(v['brick_y']) for v in rows];a=[int(v['brick_anchored']) for v in rows];trans=[i+1 for i in range(1,len(a)) if a[i]!=a[i-1]]
 assert all(v['floor_anchored']=='1' and abs(float(v['floor_y'])+1)<1e-4 for v in rows)
 markers=[x.stdout.count(s) for s in ('COMBINED_TRIGGER','COMBINED_ANCHOR','COMBINED_RELEASE')]
 if pressed:
  # Arrival depends on character physics. Require collision during held input,
  # one script sequence, and the existing scheduler's two wait intervals.
  assert markers==[1,1,1],markers
  assert len(trans)==3 and 12<trans[0]<72 and [trans[1]-trans[0],trans[2]-trans[1]]==[8,10],trans
  assert abs(y[-1]-1)<.01 and max(y[-60:])-min(y[-60:])<.002
 else:assert markers==[0,0,0] and not trans and abs(y[-1]-12)<1e-4
 with (folder/'p5_camera.csv').open() as f:camera={k:float(v) for k,v in next(csv.DictReader(f)).items()}
 if pressed:assert camera['actor_end_z']<camera['actor_start_z']-3
 results[name]={'exit':x.returncode,'transitions':trans,'end_y':y[-1],'tail_span':max(y[-60:])-min(y[-60:]),'actor_z_delta':camera['actor_end_z']-camera['actor_start_z'],'samples_sha256':sha(folder/'anchor_samples.csv')}
 print(name,'PASS',flush=True)
live=record_p5_play.live(out,'live',['--play','--p5-live-observe',str(fixture)],True)
text=(out/'live/stdout.txt').read_text(errors='replace');assert text.count('COMBINED_ANCHOR')==1 and text.count('COMBINED_RELEASE')==1
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'exe_sha256':sha(exe),'fixture_sha256':sha(fixture),'observer_sha256':sha(pathlib.Path(__file__)),'live_helper_sha256':sha(pathlib.Path(record_p5_play.__file__)),'fixed':results,'live':live,'P5_complete':False,'scope':'Combined authored collision/Lua/ground-joint fixture; frame/input remain adapted. Arrival is bounded by the held-input interval; original physics is checked separately.'}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('live PASS')
