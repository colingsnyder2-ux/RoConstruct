import frida, time, os, ctypes, ctypes.wintypes as w
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid)
js = """let n=0; Interceptor.attach(ptr('0x004362c0'), { onEnter() { if (n++>3) return;
 const a = Array.from(new Uint32Array(this.context.esp.readByteArray(0x30))).map(x=>x.toString(16));
 let nodes=[]; try { let it = ptr('0x'+a[2]); for (let i=0;i<4;i++){ nodes.push(Array.from(new Uint32Array(it.readByteArray(0x18))).map(x=>x.toString(16))); } } catch(e) { nodes.push(''+e); }
 send({args:a, node:nodes}); } });"""
sc = s.create_script(js); out=[]; sc.on('message', lambda m,d: out.append(m.get('payload') or m)); sc.load(); frida.resume(pid)
time.sleep(10)
u=ctypes.WinDLL('user32'); P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM); hs=[]
def cb(h,_):
    q=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(q)); c=ctypes.create_unicode_buffer(64); u.GetClassNameW(h,c,64)
    if q.value==pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'): hs.append(h)
    return True
u.EnumWindows(P(cb),0)
if hs: u.PostMessageW(hs[0],0x111,0xE100,0)
time.sleep(8)
try: frida.kill(pid)
except Exception: pass
print("events", len(out))
for o in out: print(o)
