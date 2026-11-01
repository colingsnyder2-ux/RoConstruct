"""Verify the DataModel camera drives Ogre and follows controlled characters."""
import csv
import ctypes
from ctypes import wintypes
import hashlib
import json
import math
from pathlib import Path
import subprocess
import sys
import time
from record_p5_controller import INPUT, KEYBDINPUT

ROOT=Path(__file__).resolve().parents[3]
EXE=ROOT/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURES=ROOT/'rebuild/2008-06/tests/fixtures'
def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def fixed(out,name,flags,fixture):
    folder=out/name;folder.mkdir();path=FIXTURES/fixture
    run=subprocess.run([str(EXE)]+flags+['--frames','120',str(path)],cwd=folder,capture_output=True,text=True,timeout=60)
    (folder/'stdout.txt').write_text(run.stdout+run.stderr)
    assert run.returncode==0 and 'player camera subject: attached (0)' in run.stdout
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
    with (folder/'p5_camera.csv').open() as stream: row={k:float(v) for k,v in next(csv.DictReader(stream)).items()}
    assert max(abs(row['camera_end_'+a]-row['native_'+a]) for a in 'xyz')<1e-5 and row['rotation_error']<1e-5
    assert abs(row['renderer_fov_y']-2*math.atan(math.tan(row['native_fov_x']/2)/row['aspect']))<1e-5
    assert abs(row['near_clip']-1.25)<1e-5 and abs(row['far_clip']-5000)<1e-2
    return {'exit':run.returncode,'observation':row,'fixture_sha256':sha(path),'observation_sha256':sha(folder/'p5_camera.csv')}

def live(out):
    folder=out/'live';folder.mkdir();u=ctypes.windll.user32;u.GetForegroundWindow.restype=wintypes.HWND;held=set()
    def key(vk,down):
        event=INPUT(type=1,ki=KEYBDINPUT(wVk=vk,wScan=0,dwFlags=0 if down else 2,time=0,dwExtraInfo=0))
        assert u.SendInput(1,ctypes.byref(event),ctypes.sizeof(event))==1
        if down:held.add(vk)
        else:held.discard(vk)
    with (folder/'stdout.txt').open('w') as log:
        run=subprocess.Popen([str(EXE),'--p5-spawn','--p5-native-camera','--p5-live-observe',str(FIXTURES/'p5-spawn-floor.rbxl')],cwd=folder,stdout=log,stderr=subprocess.STDOUT)
        forced=False
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
            u.SetForegroundWindow(windows[0]);time.sleep(.8)
            assert u.GetForegroundWindow()==windows[0],'player did not receive focus'
            key(ord('W'),True);time.sleep(.8);key(ord('W'),False)
            key(0x25,True);time.sleep(.6);key(0x25,False);time.sleep(.3)
            assert u.GetForegroundWindow()==windows[0],'focus lost before exit'
            key(0x1b,True);time.sleep(.1);key(0x1b,False);run.wait(timeout=10)
        finally:
            for vk in list(held):key(vk,False)
            if run.poll() is None:forced=True;run.terminate();run.wait(timeout=5)
    assert not forced and run.returncode==0
    with (folder/'p5_live.csv').open() as stream: row={k:float(v) for k,v in next(csv.DictReader(stream)).items()}
    assert row['actor_end_z']-row['actor_start_z'] < -2
    assert abs(row['look_end_x']-row['look_start_x'])>.2
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in (folder/'stdout.txt').read_text()
    return {'exit':run.returncode,'forced':forced,'observation':row,'observation_sha256':sha(folder/'p5_live.csv')}

def main():
    out=ROOT/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
    receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             'exe_sha256':sha(EXE),'observer_sha256':sha(Path(__file__)),'P5_complete':False,
             'scope':'Existing DataModel character camera drives Ogre pose and projection through an opt-in adapter.',
             'remaining':['Original camera parity','Native frame loop and window input','Normal launch','Full P5 acceptance'],'cases':{}}
    cases=receipt['cases']
    cases['idle']=fixed(out,'idle',['--p5-join','--p5-native-camera'],'p5-humanoid-idle.rbxl')
    cases['move']=fixed(out,'move',['--p5-join','--p5-native-camera','--p5-input-test'],'p5-humanoid-idle.rbxl')
    cases['turn']=fixed(out,'turn',['--p5-join','--p5-camera-turn-test'],'p5-humanoid-idle.rbxl')
    cases['spawn']=fixed(out,'spawn',['--p5-spawn','--p5-native-camera'],'p5-spawn-floor.rbxl')
    idle=cases['idle']['observation'];move=cases['move']['observation'];turn=cases['turn']['observation']
    assert move['actor_end_z'] < -10
    assert abs((move['camera_end_z']-idle['camera_end_z'])-(move['actor_end_z']-idle['actor_end_z']))<.1
    assert abs(turn['look_end_x']-idle['look_end_x'])>.3
    cases['live']=live(out)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print('camera follow, turn, projection, spawn and focused live input: PASS')
if __name__=='__main__': main()
