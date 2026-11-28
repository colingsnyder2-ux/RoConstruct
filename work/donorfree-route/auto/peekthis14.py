import frida, time, os, ctypes, ctypes.wintypes as w, bisect, re
syms=[]
for l in open('run/RobloxLadder14.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and p[0][:4] in ('0001','0002','0003') and re.fullmatch('[0-9a-f]{8}',p[2]): syms.append((int(p[2],16),p[1]))
syms.sort(); ks=[s for s,_ in syms]
near=lambda v:(lambda j:'%s+%x'%(syms[j][1][:90],v-ks[j]) if j>=0 and v-ks[j]<0x4000 else '%08x'%v)(bisect.bisect_right(ks,v)-1)
exe = os.path.abspath('run/RobloxLadder14.exe')
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid)
js = """let n=0; Interceptor.attach(ptr('0x00436d10'), { onEnter() { if (n++>3) return; const c=this.context.ecx; let w=[]; try { w=Array.from(new Uint32Array(c.readByteArray(0x120))); } catch(e) {} send({ecx:c.toUInt32(), mem:w}); } });"""
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
import json; json.dump(out, open('auto/peekthis14.json','w'))
for o in out[:2]:
    print(hex(o['ecx']), [(i*4, near(v)) for i,v in enumerate(o['mem']) if 0x401000<=v<0x1400000][:20])
