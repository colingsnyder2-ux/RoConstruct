"""Read frozen Lua simulation-time/torso samples from original and rebuilt clients."""
import csv,ctypes,hashlib,json,pathlib,statistics,struct,subprocess,sys,time
from ctypes import wintypes
root=pathlib.Path(__file__).resolve().parents[3]
original=root/'work/2008-06/original-p4-reference/Roblox.exe'
player=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
mode=sys.argv[2] if len(sys.argv)>2 else 'fall'
assert mode in ('fall','jump','air','jumpvelocity','jumpflag')
fixture=root/'rebuild/2008-06/tests/fixtures'/('p5-simtime-'+mode+'.rbxl')
out=root/'work/2008-06'/sys.argv[1];out.mkdir(exist_ok=False)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
run=subprocess.run([str(player),'--p5-join','--p5-play','--frames','246','--inspect-place',str(fixture)],cwd=out,capture_output=True,text=True,timeout=90)
(out/'stdout.txt').write_text(run.stdout+run.stderr)
assert run.returncode==0 and '[output]    stack end' not in run.stdout
with (out/'place_snapshot.csv').open() as f:rows=list(csv.DictReader(f))
assert len(rows)==20
rebuilt=[(float(r['x'])-177.25,float(r['y'])) for r in rows[7:]]
assert all(t>0 for t,y in rebuilt)
u=ctypes.windll.user32;k=ctypes.windll.kernel32;k.OpenProcess.restype=wintypes.HANDLE;k.VirtualQueryEx.restype=ctypes.c_size_t
class MBI(ctypes.Structure):
 _fields_=[('BaseAddress',ctypes.c_void_p),('AllocationBase',ctypes.c_void_p),('AllocationProtect',wintypes.DWORD),('PartitionId',wintypes.WORD),('RegionSize',ctypes.c_size_t),('State',wintypes.DWORD),('Protect',wintypes.DWORD),('Type',wintypes.DWORD)]
x=subprocess.Popen([str(original),str(fixture)],cwd=original.parent,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL);windows=[];handle=None;forced=False
(out/'original-pid.txt').write_text(str(x.pid))
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
 needles=[struct.pack('<3f',177.25,50,100+j*3) for j in range(13)];hits=[[] for _ in needles];addr=0;mbi=MBI()
 while addr<0x80000000 and k.VirtualQueryEx(handle,ctypes.c_void_p(addr),ctypes.byref(mbi),ctypes.sizeof(mbi)):
  start=mbi.BaseAddress or 0;size=mbi.RegionSize
  if mbi.State==0x1000 and not mbi.Protect&0x101 and (mbi.Protect&0xff) in (2,4,8,0x20,0x40,0x80) and size<=64*1024*1024:
   data=read(start,size)
   for j,needle in enumerate(needles):
    pos=data.find(needle)
    while pos>=0:hits[j].append(start+pos);pos=data.find(needle,pos+1)
  addr=start+size
 assert all(len(group)>=2 for group in hits)
 u.ShowWindow(h,9);u.SetForegroundWindow(h);time.sleep(.4);rect=wintypes.RECT();assert u.GetWindowRect(h,ctypes.byref(rect)) and u.GetForegroundWindow()==h and rect.right-rect.left>=800 and rect.bottom-rect.top>=600
 u.SetCursorPos(rect.left+390,rect.top+70);u.mouse_event(2,0,0,0,0);u.mouse_event(4,0,0,0,0);time.sleep(4.5)
 records=[]
 for j,group in enumerate(hits):
  values=[]
  for address in group:
   d=read(address,12)
   if len(d)==12:
    mx,y,z=struct.unpack('<3f',d)
    if 177.25<mx<182 and ((100<y<250) if mode=='air' else ((-100<y<100) if mode=='jumpvelocity' else (-10<y<40))) and abs(z-(100+j*3))<.01:values.append((mx-177.25,y))
  assert len(values)>=2,(j,values)
  assert max(v[0] for v in values)-min(v[0] for v in values)<.0001
  assert max(v[1] for v in values)-min(v[1] for v in values)<.001
  t,y=map(statistics.median,zip(*values));bt,by=rebuilt[j]
  records.append(dict(sample=j,original_time=t,rebuilt_time=bt,aligned=abs(t-bt)<.0001,original_y=y,rebuilt_y=by,delta_y=y-by,copies=len(values)))
 assert all(r['aligned'] for r in records), records
 if mode=='fall':assert max(abs(r['delta_y']) for r in records)<.1, records
 if mode=='air':assert max(abs(r['delta_y']) for r in records if r['original_time']<=1.0001)<.01, records
 if mode=='jump':assert max(abs(r['delta_y']) for r in records)<.12, records
 if mode=='jumpvelocity':assert max(abs(r['delta_y']) for r in records if r['original_time']>1.05)<.12, records
finally:
 if handle:k.CloseHandle(handle)
 if windows:u.PostMessageW(windows[0],0x10,0,0)
 try:x.wait(timeout=4)
 except subprocess.TimeoutExpired:forced=True;x.terminate();x.wait(timeout=5)
receipt=dict(mode=mode,measured_coordinate='torso x' if mode=='air' else ('torso velocity y' if mode=='jumpvelocity' else ('Jump flag' if mode=='jumpflag' else 'torso y')),revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),original_sha256=sha(original),player_sha256=sha(player),fixture_sha256=sha(fixture),observer_sha256=sha(pathlib.Path(__file__)),records=records,original_forced_termination=forced,scope='Frozen Stepped callback samples with encoded simulation time. Different joint construction; comparisons are observational.',P5_complete=False)
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
for r in records:print(r['sample'],r['original_time'],r['rebuilt_time'],r['delta_y'])
