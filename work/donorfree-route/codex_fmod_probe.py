import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
lua=(root/'feature_test.lua').read_text()
code=chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe,'-script',code],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="""
let fmod = Process.findModuleByName('fmodex.dll') || Module.load('fmodex.dll');
let getStats = new NativeFunction(fmod.getExportByName('FMOD_Memory_GetStats'), 'int', ['pointer', 'pointer'], 'stdcall');
let replacement = new NativeCallback(function(a, b) { return getStats(a, b); }, 'int', ['pointer', 'pointer'], 'stdcall');
Interceptor.replace(ptr('0x845d98'), replacement);
send({replacement: 'FMOD_Memory_GetStats', address: getStats.toString()});
Process.setExceptionHandler(function(e){
  if (e.type !== 'access-violation') return false;
  let c=e.context, info={type:e.type, address:e.address.toString(), memory:e.memory, eip:c.eip.toString(), esp:c.esp.toString(), ebp:c.ebp.toString(), eax:c.eax.toString(), ebx:c.ebx.toString(), ecx:c.ecx.toString(), edx:c.edx.toString(), esi:c.esi.toString(), edi:c.edi.toString()};
  try { info.stack=Thread.backtrace(c,Backtracer.ACCURATE).map(x=>x.toString()); } catch(x) {info.stackError=x.toString();}
  try {info.words=[];for(let i=0;i<24;i++) info.words.push(c.esp.add(i*4).readPointer().toString());}catch(x){}
  send(info); return false;
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
        pid=w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid))
        if pid.value == proc.pid and c.value.startswith('Afx:') and u.IsWindowVisible(h): out.append(h)
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