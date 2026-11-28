import frida, time, os, sys, bisect, re, ctypes, ctypes.wintypes as w
syms=[]
for l in open('linkexp/qt.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and re.fullmatch('[0-9a-f]{8}',p[2]) and p[0][:4] in ('0001','0002','0003'): syms.append((int(p[2],16),p[1]))
syms.sort(); ks=[s for s,_ in syms]
near=lambda v:(lambda j:'%s+%x'%(syms[j][1][:70],v-ks[j]) if j>=0 and v-ks[j]<0x1000 else '%08x'%v)(bisect.bisect_right(ks,v)-1)
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe, '-script', open('auto/one.lua').read()], cwd=os.path.dirname(exe))
s = frida.attach(pid)
js = """Process.setExceptionHandler(function (d) { if (d.type !== 'access-violation') return false;
 const r = {}; for (const k of ['eax','ebx','ecx','edx','esi','edi','ebp']) { const v = d.context[k]; let mem = []; try { mem = Array.from(new Uint32Array(v.readByteArray(0x60))); } catch (e) {} r[k] = [v.toUInt32(), mem]; }
 const mo = Process.findModuleByAddress(d.context.pc); let st = []; try { st = Array.from(new Uint32Array(d.context.esp.readByteArray(0x400))); } catch (e) {} send({pc: d.context.pc.toUInt32(), mod: mo ? mo.name + '+' + d.context.pc.sub(mo.base).toString(16) : '?', addr: d.memory ? d.memory.address.toString() + ' ' + d.memory.operation : '?', r: r, st: st}); return false; });"""
sc = s.create_script(js); out = []
sc.on('message', lambda m, d: out.append(m.get('payload') or m))
sc.load(); frida.resume(pid); time.sleep(8)
if '--run' in sys.argv:
    u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
    def cb(h, _):
        p = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p))
        c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128)
        if p.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            u.PostMessageW(h, 0x111, 32966, 0)
        return True
    u.EnumWindows(P(cb), 0)
time.sleep(10 if '--run' in sys.argv else 2)
try: frida.kill(pid)
except Exception: pass
if not out:
    print('no access violation captured'); sys.exit(1)
o = out[0]; print('pc', near(o['pc']), o['mod'], o['addr']); print('stack', [near(v) for v in o['st'] if 0x401000 <= v < 0x8f0000][:25])
for k,(v,mem) in o['r'].items():
    print(k, near(v), ' '.join(near(x) if 0x400000<=x<0x1400000 else '%x'%x for x in mem[:24]))
