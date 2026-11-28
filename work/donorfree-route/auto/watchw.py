import frida, time, os, ctypes, ctypes.wintypes as w, bisect, re, sys
ADDR = int(sys.argv[1], 16)
syms=[]
for l in open('linkexp/qt.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and p[0][:4]=='0001' and re.fullmatch('[0-9a-f]{8}',p[2]): syms.append((int(p[2],16),p[1]))
syms.sort(); ks=[s for s,_ in syms]
near=lambda v:(lambda j:'%s+%x'%(syms[j][1][:80],v-ks[j]) if j>=0 and v-ks[j]<0x4000 else '%08x'%v)(bisect.bisect_right(ks,v)-1)
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid)
js = """
const A = ptr('%s'); let n = 0;
function arm() { for (const t of Process.enumerateThreads()) { try { t.setHardwareWatchpoint(0, A, 4, 'w'); } catch (e) {} } }
Process.setExceptionHandler(function (d) {
  if (d.type !== 'single-step' && d.type !== 'breakpoint') return false;
  let v = 0; try { v = A.readU32(); } catch (e) {}
  if (n++ < 40) send({pc: d.context.pc.toUInt32(), val: v, st: Array.from(new Uint32Array(d.context.esp.readByteArray(0x200)))});
  return true;
});
arm(); setInterval(arm, 200);
""" % hex(ADDR)
sc = s.create_script(js); out=[]; sc.on('message', lambda m,d: out.append(m.get('payload') or m)); sc.load(); frida.resume(pid)
time.sleep(10)
u=ctypes.WinDLL('user32'); P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM); hs=[]
def cb(h,_):
    q=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(q)); c=ctypes.create_unicode_buffer(64); u.GetClassNameW(h,c,64)
    if q.value==pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'): hs.append(h)
    return True
u.EnumWindows(P(cb),0)
if hs: u.PostMessageW(hs[0],0x111,0xE100,0)
time.sleep(6)
try: frida.kill(pid)
except Exception: pass
print('events', len(out))
for o in out:
    if not isinstance(o, dict) or 'pc' not in o: print(o); continue
    print('== pc', near(o['pc']), 'val %08x' % o['val']); print('   ', [near(v) for v in o['st'] if 0x401000<=v<0x8f0000][:8])
