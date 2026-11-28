import frida, time, os, ctypes, ctypes.wintypes as w, bisect, re
syms=[]
for l in open('linkexp/qt.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and p[0][:4] in ('0001','0002','0003') and re.fullmatch('[0-9a-f]{8}',p[2]): syms.append((int(p[2],16),p[1]))
syms.sort(); ks=[s for s,_ in syms]
near=lambda v:(lambda j:'%s+%x'%(syms[j][1][:90],v-ks[j]) if j>=0 and v-ks[j]<0x4000 else '%08x'%v)(bisect.bisect_right(ks,v)-1)
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid)
js = """let n=0; Interceptor.attach(ptr('0x004362c0'), { onEnter() { if (n++>3) return; const sp=this.context.esp;
 let node=sp.add(12).readPointer(), last=sp.add(20).readPointer();
 const isnil = x => x.add(0x15).readU8() !== 0; let g=0;
 while (!node.equals(last) && g++<200) { let it=node.add(0xc).readPointer(); let vt=0,s0=0; try { vt=it.readPointer().toUInt32(); s0=it.readPointer().readPointer().toUInt32(); } catch(e) {} send([it.toUInt32(),vt,s0]);
   let r=node.add(8).readPointer(); if (!isnil(r)) { node=r; while (!isnil(node.readPointer())) node=node.readPointer(); } else { let p=node.add(4).readPointer(); while (!isnil(p) && node.equals(p.add(8).readPointer())) { node=p; p=p.add(4).readPointer(); } node=p; } }
 } });"""
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
import collections
c=collections.Counter((near(v),near(s0)) for _,v,s0 in [o for o in out if isinstance(o,list)])
for k,n in c.most_common(12): print(n,k)
print(out[:3])
