import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="Process.setExceptionHandler(function(e){ send({type:e.type, address:e.address, memory:e.memory, stack:Thread.backtrace(e.context,Backtracer.FUZZY).map(x=>x.toString())}); return false; });"
script=session.create_script(js)
script.on('message', lambda m,d: print(ascii(m), flush=True))
script.load()
u=ctypes.WinDLL('user32'); P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM)
def wins():
    out=[]
    def cb(h,_):
        c=ctypes.create_unicode_buffer(128); u.GetClassNameW(h,c,128)
        if c.value.startswith('Afx:') and u.IsWindowVisible(h): out.append(h)
        return True
    u.EnumWindows(P(cb),0); return out
time.sleep(6)
hs=wins()
print('windows',hs)
if hs:
    u.PostMessageW(hs[0],0x111,0xe106,0)
for i in range(20):
    time.sleep(1)
    for h in wins():
        u.PostMessageW(h,0x10,0,0)
print('exit=',proc.poll())
if proc.poll() is None: proc.kill(); proc.wait()