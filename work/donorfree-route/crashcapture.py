import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
lua=(root/'feature_test.lua').read_text()
code=chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe,'-script',code],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="""
let last={};
Interceptor.attach(ptr('0x44b260'), {
  onEnter(args){ try{
    let o=this.context.ecx;
    let shared=o.add(0x7c).readPointer();
    let ctrl=o.add(0x80).readPointer();
    let obj=o.add(0x84).readPointer();
    last={ecx:o.toString(), shared:shared.toString(), ctrl:ctrl.toString(), obj:obj.toString()};
    // read obj+0x138 as 16 bytes
    let b=[];
    for(let i=0;i<16;i++){ try{ b.push(obj.add(0x138+i).readU8()); }catch(e){ b.push(-1);} }
    last.bytes138=b;
    // service ptr if obj has +0x158
    try{ last.svc=obj.add(0x158).readPointer().toString(); }catch(e){ last.svc='ERR'; }
  }catch(e){ last={err:e.toString()}; }
  },
  onLeave(ret){ last.ret=ret.toString(); }
});
Process.setExceptionHandler(function(e){
  let info={crash:true, eip:e.context.eip.toString(), addr:e.address, memory:e.memory, last:last};
  try{ info.stack=Thread.backtrace(e.context,Backtracer.FUZZY).map(x=>x.toString()); }catch(x){}
  send(info);
  return false;
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