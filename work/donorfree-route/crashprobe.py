import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root = Path(__file__).parent
lua = (root / 'feature_test.lua').read_text()
code = chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
exe = str(root / 'run' / 'RobloxQT.exe')
proc = subprocess.Popen([exe, '-script', code], cwd=str(root / 'run'))
session = frida.attach(proc.pid)
js = "Process.setExceptionHandler(function(e){ if(e.type==='access-violation') send({fault:e.address.toString(), memory:e.memory, stack:Thread.backtrace(e.context,Backtracer.FUZZY).map(x=>x.toString())}); return false; });"
script = session.create_script(js)
script.on('message', lambda m, data: print(ascii(m), flush=True))
script.load()
u = ctypes.WinDLL('user32')
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def wins():
    out=[]
    def cb(h,_):
        c=ctypes.create_unicode_buffer(128); u.GetClassNameW(h,c,128)
        if c.value.startswith('Afx:') and u.IsWindowVisible(h): out.append(h)
        return True
    u.EnumWindows(P(cb),0); return out
t0=time.time(); ran=False
while time.time()-t0 < 22 and proc.poll() is None:
    time.sleep(1)
    if not ran and time.time()-t0>8:
        for h in wins(): u.PostMessageW(h,0x111,32966,0)
        ran=True
print('exit=', proc.poll(), flush=True)
if proc.poll() is None:
    proc.kill(); proc.wait()