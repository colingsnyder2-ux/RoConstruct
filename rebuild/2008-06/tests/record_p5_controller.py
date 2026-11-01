"""P5 joined-character/controller tests; original movement parity remains open."""
import csv
import ctypes
from ctypes import wintypes
import hashlib
import json
import math
import re
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
FIXTURES = ROOT / 'rebuild/2008-06/tests/fixtures'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def fixed(out, name, fixture, extra):
    folder = out / name
    folder.mkdir()
    args = [str(EXE), '--p5-join', '--p5-play'] + extra + ['--frames','120','--inspect-place',str(FIXTURES/fixture)]
    run = subprocess.run(args, cwd=folder, capture_output=True, text=True, timeout=30)
    (folder/'stdout.txt').write_text(run.stdout+run.stderr)
    assert run.returncode == 0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout, (name, run.returncode)
    with (folder/'place_snapshot.csv').open() as stream:
        rows=list(csv.DictReader(stream))
    assert len(rows)==7 and all(row['status']=='0' for row in rows)
    positions=[[float(row[k]) for k in ('x','y','z')] for row in rows]
    torso=positions[1]
    expected=[(0,1.5,0),(-1.5,0,0),(1.5,0,0),(-.5,-2,0),(.5,-2,0)]
    for position,relative in zip(positions[2:],expected):
        assert max(abs(position[i]-torso[i]-relative[i]) for i in range(3))<.05, (name,positions)
    assert abs(torso[1]-2.8)<.06, (name,torso)
    return {'exit':run.returncode,'positions':positions,'fixture_sha256':sha(FIXTURES/fixture),
            'snapshot_sha256':sha(folder/'place_snapshot.csv')}


class MOUSEINPUT(ctypes.Structure):
    _fields_=[('dx',wintypes.LONG),('dy',wintypes.LONG),('mouseData',wintypes.DWORD),('dwFlags',wintypes.DWORD),('time',wintypes.DWORD),('dwExtraInfo',ctypes.c_size_t)]
class KEYBDINPUT(ctypes.Structure):
    _fields_=[('wVk',wintypes.WORD),('wScan',wintypes.WORD),('dwFlags',wintypes.DWORD),('time',wintypes.DWORD),('dwExtraInfo',ctypes.c_size_t)]
class HARDWAREINPUT(ctypes.Structure):
    _fields_=[('uMsg',wintypes.DWORD),('wParamL',wintypes.WORD),('wParamH',wintypes.WORD)]
class INPUTUNION(ctypes.Union):
    _fields_=[('mi',MOUSEINPUT),('ki',KEYBDINPUT),('hi',HARDWAREINPUT)]
class INPUT(ctypes.Structure):
    _anonymous_=('data',)
    _fields_=[('type',wintypes.DWORD),('data',INPUTUNION)]


def live(out):
    folder=out/'live'
    folder.mkdir()
    user32=ctypes.windll.user32
    user32.GetForegroundWindow.restype=wintypes.HWND
    held=set()
    def key(vk,down):
        event=INPUT(type=1,ki=KEYBDINPUT(wVk=vk,wScan=0,dwFlags=0 if down else 2,time=0,dwExtraInfo=0))
        assert user32.SendInput(1,ctypes.byref(event),ctypes.sizeof(event))==1
        if down:held.add(vk)
        else:held.discard(vk)
    with (folder/'stdout.txt').open('w') as log:
        run=subprocess.Popen([str(EXE),'--p5-join','--p5-play','--p5-control','--p5-live-observe',str(FIXTURES/'p5-humanoid-idle.rbxl')],cwd=folder,stdout=log,stderr=subprocess.STDOUT)
        forced=False
        try:
            windows=[]
            @ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM)
            def find(hwnd,_):
                pid=wintypes.DWORD();user32.GetWindowThreadProcessId(hwnd,ctypes.byref(pid))
                if pid.value==run.pid and user32.IsWindowVisible(hwnd):windows.append(hwnd)
                return True
            for _ in range(160):
                windows.clear();user32.EnumWindows(find,0)
                if windows:break
                assert run.poll() is None, 'player exited before window'
                time.sleep(.05)
            assert windows, 'player window unavailable'
            user32.SetForegroundWindow(windows[0]);time.sleep(.5)
            assert user32.GetForegroundWindow()==windows[0], 'player did not receive focus; no keys sent'
            key(ord('W'),True);key(ord('Q'),True);time.sleep(.8)
            key(ord('W'),False);key(ord('Q'),False);time.sleep(.4)
            assert user32.GetForegroundWindow()==windows[0], 'focus lost before exit'
            key(0x1b,True);time.sleep(.1);key(0x1b,False)
            run.wait(timeout=10)
        finally:
            for vk in list(held):key(vk,False)
            if run.poll() is None:
                forced=True;run.terminate();run.wait(timeout=5)
    assert not forced and run.returncode==0
    with (folder/'p5_live.csv').open() as stream: row=next(csv.DictReader(stream))
    data={key:float(value) for key,value in row.items()}
    assert data['actor_end_z']-data['actor_start_z'] < -3, data
    assert data['camera_end_y']-data['camera_start_y'] > 1, data
    assert abs(data['actor_end_y']-2.8)<.15, data
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in (folder/'stdout.txt').read_text()
    return {'exit':run.returncode,'forced':forced,'observation':data,'observation_sha256':sha(folder/'p5_live.csv')}


def main():
    out=ROOT/'work/2008-06'/sys.argv[1]
    out.mkdir(exist_ok=False)
    receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             'exe_sha256':sha(EXE),'observer_sha256':sha(Path(__file__)),'runs':{},'P5_complete':False,
             'scope':'Joined fixture with donor Humanoid forces, recovered controller behavior and Win32 input adapter.',
             'remaining':['Original movement/physics parity','Original input/window integration','Normal-launch spawn and camera synchronization']}
    folder=out/'checks';folder.mkdir()
    check=subprocess.run([str(EXE),'--p5-controller-check',str(FIXTURES/'p5-humanoid-idle.rbxl')],cwd=folder,capture_output=True,text=True,timeout=30)
    (folder/'stdout.txt').write_text(check.stdout+check.stderr)
    assert check.returncode==0 and 'controller checks: PASS' in check.stdout
    receipt['runs']['checks']={'exit':check.returncode}
    clock=out/'clock';clock.mkdir()
    timer=subprocess.run([str(EXE),'--p5-clock-check',str(FIXTURES/'p5-humanoid-idle.rbxl')],cwd=clock,capture_output=True,text=True,timeout=30)
    (clock/'stdout.txt').write_text(timer.stdout+timer.stderr)
    match=re.search(r'timer check: precision=([0-9a-f]+) delta=([0-9.eE+-]+) calls=(\d+)',timer.stdout)
    assert timer.returncode==0 and match and int(match.group(3))==1 and .009<float(match.group(2))<.011
    receipt['runs']['clock']={'exit':timer.returncode,'precision':match.group(1),'delta':float(match.group(2)),'calls':1}
    for name,fixture,extra in [('idle','p5-humanoid-idle.rbxl',['--p5-control']),
                               ('input','p5-humanoid-idle.rbxl',['--p5-input-test']),
                               ('script','p5-humanoid-probe.rbxl',[])]:
        receipt['runs'][name]=fixed(out,name,fixture,extra)
        print(name,'PASS',flush=True)
    assert abs(receipt['runs']['idle']['positions'][1][2])<.2
    assert receipt['runs']['input']['positions'][1][2]<-10
    assert receipt['runs']['script']['positions'][1][0]>10
    receipt['runs']['live']=live(out)
    print('live input PASS',flush=True)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')


if __name__=='__main__':
    main()
