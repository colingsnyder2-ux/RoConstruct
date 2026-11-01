"""Compare original real-time anchor cycle with reconstructed fixed-step samples.

Original is a local staged 2008 executable; read-only process memory observations
are corroborated by multiple position copies. This does not claim step control.
"""
import csv,ctypes,hashlib,json,pathlib,statistics,struct,subprocess,sys,time
from ctypes import wintypes
root=pathlib.Path(__file__).resolve().parents[3];original=root/'work/2008-06/original-p4-reference/Roblox.exe';player=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe';fixture=root/'rebuild/2008-06/tests/fixtures/p5-original-anchor.rbxl';out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
run=subprocess.run([str(player),'--p5-play','--frames','600','--anchor-trace',str(fixture)],cwd=out,capture_output=True,text=True,timeout=90)
assert run.returncode==0 and 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
with (out/'anchor_samples.csv').open() as f: rows=list(csv.DictReader(f))
assert len(rows)==600 and all(v['floor_anchored']=='1' and abs(float(v['floor_y'])+5)<1e-4 for v in rows)
rebuilt=[float(v['brick_y']) for v in rows];states=[int(v['brick_anchored']) for v in rows];trans=[i+1 for i in range(1,len(states)) if states[i]!=states[i-1]];assert states[0]==1 and states[-1]==0 and trans==[6,16,26];u=ctypes.windll.user32;k=ctypes.windll.kernel32;k.OpenProcess.restype=wintypes.HANDLE;k.VirtualQueryEx.restype=ctypes.c_size_t
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
 specs=[(137.25,20),(157.25,50),(177.25,60),(197.25,70)];needles=[struct.pack('<3f',a,b,71.75) for a,b in specs];hits=[[] for _ in specs];addr=0;mbi=MBI()
 while addr<0x80000000 and k.VirtualQueryEx(handle,ctypes.c_void_p(addr),ctypes.byref(mbi),ctypes.sizeof(mbi)):
  start=mbi.BaseAddress or 0;size=mbi.RegionSize
  if mbi.State==0x1000 and not mbi.Protect&0x101 and (mbi.Protect&0xff) in (2,4,8,0x20,0x40,0x80) and size<=64*1024*1024:
   data=read(start,size)
   for n,needle in enumerate(needles):
    idx=data.find(needle)
    while idx>=0:hits[n].append(start+idx);idx=data.find(needle,idx+1)
  addr=start+size
 assert all(len(group)>=2 for group in hits)
 u.SetForegroundWindow(h);time.sleep(.4);rect=wintypes.RECT();assert u.GetWindowRect(h,ctypes.byref(rect)) and u.GetForegroundWindow()==h
 # The run toolbar button's location is checked against this known 816x638 window.
 assert rect.right-rect.left>=800 and rect.bottom-rect.top>=600
 u.SetCursorPos(rect.left+390,rect.top+70);u.mouse_event(2,0,0,0,0);u.mouse_event(4,0,0,0,0)
 start=time.monotonic();history=[]
 while time.monotonic()-start<4.5:
  vals=[]
  for group,(xpos,_) in zip(hits,specs):
   groupvals=[]
   for addr in group:
    data=read(addr,12)
    if len(data)==12:
     a,b,c=struct.unpack('<3f',data);groupvals.append(b if abs(a-xpos)<.01 and abs(c-71.75)<.01 and -100<b<100 else None)
    else:groupvals.append(None)
   vals.append(groupvals)
  history.append((time.monotonic()-start,vals));time.sleep(.01)
 assert x.poll() is None
 active=[[i for i,v in enumerate(history[-1][1][j]) if v is not None and abs(v-specs[j][1])>.5] for j in range(4)]
 assert all(len(group)>=2 for group in active),[len(group) for group in active]
 def observe(t):
  actual,values=min(history,key=lambda v:abs(v[0]-t));values=[values[0][i] for i in active[0] if values[0][i] is not None];assert len(values)>=2 and max(values)-min(values)<.06
  return actual,statistics.median(values)
 checks=[]
 marker_times=[]
 for group in range(1,4):
  events=[t for t,vals in history if all(vals[group][i] is not None and abs(vals[group][i]-(specs[group][1]+1))<.01 for i in active[group])]
  assert events;marker_times.append(events[0])
 assert .05<marker_times[0]<.2 and .2<marker_times[1]<.4 and .35<marker_times[2]<.6,marker_times
 for t in (.1,.2,.3,.4,.5,.6,.8,1.,1.5,2.,3.,4.):
  actual,value=observe(t);frame=max(1,min(600,round(actual*60)));lo=max(1,frame-3);hi=min(600,frame+3);error=min(abs(value-rebuilt[n-1]) for n in range(lo,hi+1));assert error<.25,(t,actual,value,frame,error);checks.append({'time':actual,'original_y':value,'fixed_frame_window':[lo,hi],'best_error':error})
 endtime,end=observe(4.);assert abs(end-rebuilt[-1])<.01 and abs(end+3.8)<.01
finally:
 if handle:k.CloseHandle(handle)
 if windows:u.PostMessageW(windows[0],0x10,0,0)
 try:x.wait(timeout=4)
 except subprocess.TimeoutExpired:forced=True;x.terminate();x.wait(timeout=5)
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'original_sha256':sha(original),'player_sha256':sha(player),'fixture_sha256':sha(fixture),'observer_sha256':sha(pathlib.Path(__file__)),'original_candidate_counts':[len(v) for v in hits],'agreeing_moving_copies':[len(v) for v in active],'original_marker_times':marker_times,'rebuilt_anchor_transitions':trans,'comparisons':checks,'original_final_y':end,'rebuilt_final_y':rebuilt[-1],'final_difference':abs(end-rebuilt[-1]),'original_exit':x.returncode,'original_forced_termination':forced,'player_exit':run.returncode,'scope':'One authored anchor cycle, original real-time samples versus rebuilt fixed steps, with +/-3 frame timing tolerance. Not direct original single stepping or full physics parity.','P5_complete':False}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print('anchor cycle PASS; final difference',receipt['final_difference'],'original forced',forced)
