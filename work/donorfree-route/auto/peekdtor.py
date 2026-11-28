import frida, time, os, ctypes, ctypes.wintypes as w, sys, bisect, re
addrs = sys.argv[1:]
syms=[]
for l in open('linkexp/qt.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and p[0].startswith('0001:') and re.fullmatch('[0-9a-f]{8}',p[2]): syms.append((int(p[2],16),p[1]))
syms.sort(); ks=[s for s,_ in syms]
near=lambda v:(lambda j:'%s+%x'%(syms[j][1][:80],v-ks[j]) if j>=0 and v-ks[j]<0x3000 else '%08x'%v)(bisect.bisect_right(ks,v)-1)
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid)
js = "const A=%s; for (const a of A) Interceptor.attach(ptr(a), { onEnter() { send({a:a, ecx:this.context.ecx.toString(), st:Array.from(new Uint32Array(this.context.esp.readByteArray(0x300)))}); } });" % repr(addrs)
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
print('events',len(out))
for o in out[:4]:
    print('==',o['a'],o['ecx']); print('  ',[near(v) for v in o['st'] if 0x401000<=v<0x8f0000][:22])
