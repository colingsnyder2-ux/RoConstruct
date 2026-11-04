"""Exercise recovered force adaptation on ordinary and low-friction floors."""
import csv,hashlib,json,pathlib,subprocess,sys
root=pathlib.Path(__file__).resolve().parents[3];exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';fixtures=root/'rebuild/2008-06/tests/fixtures';out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False);sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();cases={}
for name,fixture,frames,pressed,climb in [('low','p5-nativeforce-low.rbxl',120,1,0),('normal','p5-nativeforce-normal.rbxl',120,1,0),('rung_idle','p5-climb-runtime-stable.rbxl',180,0,1),('control_idle','p5-climb-runtime-stable-control.rbxl',180,0,1)]:
 folder=out/name;folder.mkdir();p=fixtures/fixture
 flags=['--p5-climb-observe'] if climb else ['--p5-join','--p5-play']
 x=subprocess.run([str(exe),*flags,*(['--p5-input-test'] if pressed else []),'--frames',str(frames),'--inspect-place',str(p)],cwd=folder,capture_output=True,text=True,timeout=90)
 assert x.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in x.stdout
 with (folder/'place_snapshot.csv').open() as f:rows=list(csv.DictReader(f))
 assert len(rows)>=7 and all(v['status']=='0' for v in rows)
 pos=[float(rows[1][k]) for k in ('x','y','z')];assert abs(pos[1]-3)<.05,(name,pos)
 cases[name]={'exit':x.returncode,'torso':pos,'fixture_sha256':sha(p),'snapshot_sha256':sha(folder/'place_snapshot.csv')}
 assert 'CLIMB_SIGNAL' not in x.stdout if not pressed else True
 print(name,'PASS',flush=True)
for name,fixture in [('moving','p5-moving-floor.rbxl'),('stationary','p5-moving-floor-control.rbxl')]:
 folder=out/name;folder.mkdir();p=fixtures/fixture
 x=subprocess.run([str(exe),'--p5-join','--p5-play','--frames','60','--inspect-place',str(p)],cwd=folder,capture_output=True,text=True,timeout=90)
 assert x.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in x.stdout
 with (folder/'place_snapshot.csv').open() as f: rows=list(csv.DictReader(f))
 assert len(rows)==8 and all(v['status']=='0' for v in rows)
 floor=float(rows[0]['x']);torso=float(rows[1]['x'])
 if name=='moving':assert 3.5<floor<4.5 and 2.5<torso<4.5 and abs(floor-torso)<1
 else:assert abs(floor)<.1 and abs(torso)<.1
 cases[name]={'exit':x.returncode,'floor_x':floor,'torso_x':torso,'fixture_sha256':sha(p),'snapshot_sha256':sha(folder/'place_snapshot.csv')}
 print(name,'PASS',flush=True)
assert cases['normal']['torso'][2]<-10 and -5<cases['low']['torso'][2]<-.2
assert abs(cases['rung_idle']['torso'][1]-cases['control_idle']['torso'][1])<.02
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'exe_sha256':sha(exe),'observer_sha256':sha(pathlib.Path(__file__)),'cases':cases,'scope':'Adapted 00666550 force path on donor ABI; moving-floor scale, rotation, and full original humanoid parity remain unproven.','P5_complete':False}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
