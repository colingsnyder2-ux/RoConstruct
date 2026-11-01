import ctypes,subprocess,time,sys,json
from pathlib import Path
from ctypes import wintypes
root=Path.cwd(); out=root/'work/2008-06/p6-close-investigation-20261101';out.mkdir(exist_ok=True)
exe=root/'rebuild/2008-06/out/p6/Roblox.exe';place=root/'rebuild/2008-06/tests/fixtures/lifetime-blocks.rbxl'
u=ctypes.windll.user32;proc=ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM); results=[]
for i in range(6):
 with (out/('run%d.log'%i)).open('wb') as f:
  p=subprocess.Popen([str(exe),str(place)],cwd=exe.parent,stdout=f,stderr=subprocess.STDOUT);time.sleep(4)
  def windows():
   found=[]
   def visit(h,_):
    pid=wintypes.DWORD();u.GetWindowThreadProcessId(h,ctypes.byref(pid))
    if pid.value==p.pid and u.IsWindowVisible(h):
     title=ctypes.create_unicode_buffer(512);cl=ctypes.create_unicode_buffer(256);u.GetWindowTextW(h,title,512);u.GetClassNameW(h,cl,256);found.append(dict(hwnd=h,title=title.value,cls=cl.value))
    return True
   u.EnumWindows(proc(visit),0);return found
  before=windows(); event=dict(run=i,pid=p.pid,before=before)
  if before:u.PostMessageW(before[0]['hwnd'],0x10,0,0)
  try:event['exit']=p.wait(timeout=10)
  except subprocess.TimeoutExpired:
   event['after']=windows();event['exit']='hung';p.kill();p.wait()
  results.append(event);print(json.dumps(event),flush=True)
(out/'results.json').write_text(json.dumps(results,indent=2))
