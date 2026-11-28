import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
lua=(root/'feature_test.lua').read_text()
code=chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe,'-script',code],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="""
Interceptor.attach(ptr('0x44b280'), {
  onEnter(args){ try{
    let o=this.context.ecx;
    let obj=o.add(0x84).readPointer();
    // find SoundServiceStatsItem: check field 344 (0x158) looks like service
    let svc=obj.add(0x158).readPointer();
    send({obj:obj.toString(), svc:svc.toString()});
    for(let off=0x120; off<=0x170; off+=4){
      try{ send({svcfield:off, val:svc.add(off).readPointer().toString()}); }catch(e){}
    }
    // log obj vtable
    send({obj_vtable:obj.readPointer().toString()});
  }catch(e){send({err:e.toString()})}
  }
});
"""
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
t0=time.time(); ran=False
while time.time()-t0 < 20 and proc.poll() is None:
    time.sleep(1)
    if not ran and time.time()-t0>8:
        for h in wins(): u.PostMessageW(h,0x111,32966,0)
        ran=True
print('exit=',proc.poll())
if proc.poll() is None: proc.kill(); proc.wait()