"""Exercise ordinary harness launch, collision, Lua touch and clean reopen."""
import csv
import ctypes
from ctypes import wintypes
import hashlib
import gzip
import json
from pathlib import Path
import subprocess
import sys
import time
from record_p5_controller import INPUT,KEYBDINPUT

ROOT=Path(__file__).resolve().parents[3]
EXE=ROOT/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURE=ROOT/'rebuild/2008-06/tests/fixtures/p5-playable.rbxl'
STAGED=EXE.parent/'Places/p5-playable.rbxl'
def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def fixed(out,name,pressed,explicit,place=None):
    folder=out/name;folder.mkdir()
    args=[str(EXE),'--play']+(['--p5-input-test'] if pressed else [])+['--frames','180','--inspect-place']+([str(place or FIXTURE)] if explicit else [])
    run=subprocess.run(args,cwd=folder,capture_output=True,text=True,timeout=60);(folder/'stdout.txt').write_text(run.stdout+run.stderr)
    assert run.returncode==0 and 'player camera subject: attached (0)' in run.stdout
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
    assert run.stdout.count('TRIGGER_FIRED')==(1 if pressed else 0)
    with (folder/'place_snapshot.csv').open() as stream: rows=list(csv.DictReader(stream))
    assert len(rows)==9 and all(r['status']=='0' for r in rows)
    target=float(rows[2]['y']);torso=float(rows[4]['z'])
    assert abs(target-(4 if pressed else 1))<1e-4
    assert 18.8<torso<19.3 if pressed else abs(torso-25.5)<.01
    with (folder/'p5_camera.csv').open() as stream: camera={k:float(v) for k,v in next(csv.DictReader(stream)).items()}
    assert max(abs(camera['camera_end_'+a]-camera['native_'+a]) for a in 'xyz')<1e-5
    return {'exit':run.returncode,'signal_y':target,'torso_z':torso,'camera':camera,
            'snapshot_sha256':sha(folder/'place_snapshot.csv')}

def live(out,name,args,observe):
    folder=out/name;folder.mkdir();u=ctypes.windll.user32;u.GetForegroundWindow.restype=wintypes.HWND;held=set()
    def key(vk,down):
        event=INPUT(type=1,ki=KEYBDINPUT(wVk=vk,wScan=0,dwFlags=0 if down else 2,time=0,dwExtraInfo=0))
        assert u.SendInput(1,ctypes.byref(event),ctypes.sizeof(event))==1
        if down:held.add(vk)
        else:held.discard(vk)
    with (folder/'stdout.txt').open('w') as log:
        run=subprocess.Popen([str(EXE)]+args,cwd=folder,stdout=log,stderr=subprocess.STDOUT);forced=False
        try:
            windows=[]
            @ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM)
            def find(hwnd,_):
                pid=wintypes.DWORD();u.GetWindowThreadProcessId(hwnd,ctypes.byref(pid))
                if pid.value==run.pid and u.IsWindowVisible(hwnd):windows.append(hwnd)
                return True
            for _ in range(160):
                windows.clear();u.EnumWindows(find,0)
                if windows:break
                assert run.poll() is None,'player exited before window'
                time.sleep(.05)
            assert windows,'player window unavailable'
            u.SetForegroundWindow(windows[0]);time.sleep(.9)
            assert u.GetForegroundWindow()==windows[0],'player did not receive focus'
            key(ord('W'),True);time.sleep(1.2);key(ord('W'),False)
            key(0x25,True);time.sleep(.6);key(0x25,False);time.sleep(.2)
            assert u.GetForegroundWindow()==windows[0],'focus lost before exit'
            key(0x1b,True);time.sleep(.1);key(0x1b,False);run.wait(timeout=10)
        finally:
            for vk in list(held):key(vk,False)
            if run.poll() is None:forced=True;run.terminate();run.wait(timeout=5)
    text=(folder/'stdout.txt').read_text(errors='replace')
    assert not forced and run.returncode==0 and text.count('TRIGGER_FIRED')==1
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in text
    result={'exit':run.returncode,'forced':forced,'touch_event_count':1}
    if observe:
        with (folder/'p5_live.csv').open() as stream: row={k:float(v) for k,v in next(csv.DictReader(stream)).items()}
        assert row['actor_end_z']-row['actor_start_z'] < -3
        assert abs(row['look_end_x']-row['look_start_x'])>.2
        result.update(observation=row,observation_sha256=sha(folder/'p5_live.csv'))
    return result

def main():
    out=ROOT/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
    assert sha(FIXTURE)==sha(STAGED)
    receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             'exe_sha256':sha(EXE),'observer_sha256':sha(Path(__file__)),'fixture_sha256':sha(FIXTURE),'P5_complete':False,
             'scope':'Standalone harness default and --play launch using a local authored place and staged original character assets.',
             'remaining':['Original-client fixed-step comparison','Native frame loop, physics and input parity','Full P5 acceptance','P6 executable startup'], 'cases':{}}
    c=receipt['cases'];c['idle']=fixed(out,'idle',False,False);c['move']=fixed(out,'move',True,False);c['explicit']=fixed(out,'explicit',True,True)
    compressed=out/'authored.rbxl.gz';compressed.write_bytes(gzip.compress(FIXTURE.read_bytes(),mtime=0))
    c['gzip']=fixed(out,'gzip',True,True,compressed)
    bad=out/'truncated.rbxl.gz';bad.write_bytes(compressed.read_bytes()[:40])
    failure=subprocess.run([str(EXE),'--play','--frames','1',str(bad)],cwd=out,capture_output=True,text=True,timeout=30)
    assert failure.returncode!=0 and 'could not read place' in failure.stdout
    c['truncated']={'exit':failure.returncode}
    c['normal1']=live(out,'normal1',[],False);c['normal2']=live(out,'normal2',[],False);c['observed']=live(out,'observed',['--play','--p5-live-observe'],True)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('default launch twice, input, collision, Lua touch, camera and reopen: PASS')
if __name__=='__main__':main()
