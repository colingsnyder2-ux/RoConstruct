"""Measure original and rebuilt jumps; vertical parity is not assumed."""
import csv,ctypes,hashlib,json,pathlib,statistics,struct,subprocess,sys,time
from ctypes import wintypes
root=pathlib.Path(__file__).resolve().parents[3];original=root/'work/2008-06/original-p4-reference/Roblox.exe';player=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';mode=sys.argv[2] if len(sys.argv)>2 else 'grounded';assert mode in ('grounded','early','airborne');fixture=root/'rebuild/2008-06/tests/fixtures'/({'grounded':'p5-original-jump.rbxl','early':'p5-original-jump-early.rbxl','airborne':'p5-original-jump-airborne.rbxl'}[mode]);out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False);sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();rebuilt={}
for frames in (15,30,45,60,75,90,105,120,150,180,240):
 folder=out/str(frames);folder.mkdir();run=subprocess.run([str(player),'--p5-join','--p5-play','--frames',str(frames),'--inspect-place',str(fixture)],cwd=folder,capture_output=True,text=True,timeout=90)
 assert run.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout and '[output]    stack end' not in run.stdout
 with (folder/'place_snapshot.csv').open() as f:rows=list(csv.DictReader(f))
 assert len(rows)==7 and all(v['status']=='0' for v in rows)
 torso=[float(rows[1][k]) for k in ('x','y','z')];head=[float(rows[2][k]) for k in ('x','y','z')]
 assert max(abs(head[i]-torso[i]-(1.5 if i==1 else 0)) for i in range(3))<.05
 rebuilt[frames]={'torso':torso,'head':head,'floor':[float(rows[0][k]) for k in ('x','y','z')],'snapshot_sha256':sha(folder/'place_snapshot.csv')}
u=ctypes.windll.user32;k=ctypes.windll.kernel32;k.OpenProcess.restype=wintypes.HANDLE;k.VirtualQueryEx.restype=ctypes.c_size_t
class MBI(ctypes.Structure):
 _fields_=[('BaseAddress',ctypes.c_void_p),('AllocationBase',ctypes.c_void_p),('AllocationProtect',wintypes.DWORD),('PartitionId',wintypes.WORD),('RegionSize',ctypes.c_size_t),('State',wintypes.DWORD),('Protect',wintypes.DWORD),('Type',wintypes.DWORD)]
x=subprocess.Popen([str(original),str(fixture)],cwd=original.parent,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL);windows=[];handle=None;forced=False
@ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM)
def find(h,_):
 pid=wintypes.DWORD();u.GetWindowThreadProcessId(h,ctypes.byref(pid))
 if pid.value==x.pid and u.IsWindowVisible(h):windows.append(h)
 return True
try:
 for _ in range(120):
  windows.clear();u.EnumWindows(find,0)
  if windows:break
  assert x.poll() is None;time.sleep(.1)
 assert windows;time.sleep(8);h=windows[0];handle=k.OpenProcess(0x410,False,x.pid);assert handle
 def read(addr,n):
  buf=ctypes.create_string_buffer(n);got=ctypes.c_size_t();ok=k.ReadProcessMemory(handle,ctypes.c_void_p(addr),buf,n,ctypes.byref(got));return buf.raw[:got.value] if ok else b''
 needles=[struct.pack('<3f',137.25,y,71.75) for y in ((30,31.5) if mode=='airborne' else (5,6.5))];hits=[[] for _ in needles];addr=0;mbi=MBI()
 while addr<0x80000000 and k.VirtualQueryEx(handle,ctypes.c_void_p(addr),ctypes.byref(mbi),ctypes.sizeof(mbi)):
  start=mbi.BaseAddress or 0;size=mbi.RegionSize
  if mbi.State==0x1000 and not mbi.Protect&0x101 and (mbi.Protect&0xff) in (2,4,8,0x20,0x40,0x80) and size<=64*1024*1024:
   data=read(start,size)
   for j,needle in enumerate(needles):
    pos=data.find(needle)
    while pos>=0:hits[j].append(start+pos);pos=data.find(needle,pos+1)
  addr=start+size
 assert all(len(group)>=2 for group in hits)
 u.SetForegroundWindow(h);time.sleep(.4);rect=wintypes.RECT();assert u.GetWindowRect(h,ctypes.byref(rect)) and u.GetForegroundWindow()==h and rect.right-rect.left>=800 and rect.bottom-rect.top>=600
 u.SetCursorPos(rect.left+390,rect.top+70);u.mouse_event(2,0,0,0,0);u.mouse_event(4,0,0,0,0);start=time.monotonic();history=[]
 while time.monotonic()-start<4.3:
  groups=[]
  for group in hits:
   vals=[]
   for address in group:
    data=read(address,12)
    if len(data)==12:
     xyz=struct.unpack('<3f',data);vals.append(xyz if abs(xyz[2]-71.75)<1 and -100<xyz[1]<100 and 100<xyz[0]<200 else None)
    else:vals.append(None)
   groups.append(vals)
  history.append((time.monotonic()-start,groups));time.sleep(.01)
 assert x.poll() is None
 end=min(history,key=lambda v:abs(v[0]-4))[1];active=[[i for i,v in enumerate(end[j]) if v is not None and v[1] < (4.5 if j==0 else 6)] for j in range(len(hits))];assert all(len(v)>=2 for v in active)
 comparisons=[]
 for frames in (15,30,45,60,75,90,105,120,150,180,240):
  target=frames/60.;candidates=[]
  for actual,groups in history:
   if abs(actual-target)>.035:continue
   positions=[]
   for j in range(len(hits)):
    vals=[groups[j][i] for i in active[j] if groups[j][i] is not None]
    if len(vals)<2 or any(max(v[q] for v in vals)-min(v[q] for v in vals)>.03 for q in range(3)):break
    positions.append([statistics.median(v[q] for v in vals) for q in range(3)])
   if len(positions)==len(hits) and max(abs(positions[1][i]-positions[0][i]-(1.5 if i==1 else 0)) for i in range(3))<.05:candidates.append((actual,positions))
  assert candidates,frames
  actual,positions=min(candidates,key=lambda z:abs(z[0]-target));delta=[positions[0][i]-rebuilt[frames]['torso'][i] for i in range(3)]
  assert abs(delta[0]) < .05 and abs(delta[2]) < .05, (frames,delta)
  check={'frame':frames,'original_time':actual,'original_torso':positions[0],'original_head':positions[1],'delta':delta}
  comparisons.append(check)
 if mode=='early':
  assert max(abs(sample['delta'][1]) for sample in comparisons)<.6, comparisons
finally:
 if handle:k.CloseHandle(handle)
 if windows:u.PostMessageW(windows[0],0x10,0,0)
 try:x.wait(timeout=4)
 except subprocess.TimeoutExpired:forced=True;x.terminate();x.wait(timeout=5)
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'original_sha256':sha(original),'player_sha256':sha(player),'fixture_sha256':sha(fixture),'observer_sha256':sha(pathlib.Path(__file__)),'candidate_counts':[len(v) for v in hits],'moving_copies':[len(v) for v in active],'rebuilt':rebuilt,'comparisons':comparisons,'original_exit':x.returncode,'original_forced_termination':forced,'mode':mode,'scope':'Original wall time vs rebuilt fixed steps +/-35ms; joint construction differs. Early mode checks vertical error under 0.6 studs; other modes are observational.','P5_complete':False}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('jump observations recorded:',mode,'max vertical delta',max(abs(x['delta'][1]) for x in comparisons))
