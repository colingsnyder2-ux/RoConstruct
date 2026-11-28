"""python watchfield.py CTOR_SYMBOL OFFSET [--post 0xE100] [--secs 15] [--max 3]: who WRITES object field +OFFSET?
Hooks the constructor (map symbol) of the first few objects; on return arms a hardware write watchpoint (Frida
Thread.setHardwareWatchpoint, all threads) on this+OFFSET; every write reports pc + backtrace resolved via
linkexp/qt.map, then the watchpoint is re-armed after single-stepping. For layout bugs where converted and native code
disagree about a field (a float landed in GuiItem's shared_ptr count at +0x138)."""
import bisect, ctypes, ctypes.wintypes as w, os, sys, time
import frida
from pathlib import Path
H = Path(__file__).parent
a = sys.argv[1:]
ctor, off = a[0], int(a[1], 16)
post = next((a[i + 1] for i, x in enumerate(a) if x == '--post'), '0xE100')
secs = float(next((a[i + 1] for i, x in enumerate(a) if x == '--secs'), '15'))
mx = int(next((a[i + 1] for i, x in enumerate(a) if x == '--max'), '3'))
syms = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            syms.append((int(p[2], 16), p[1]))
        except ValueError:
            pass
syms.sort(); ks = [s[0] for s in syms]
near = lambda v: (lambda j: '%s+%x' % (syms[j][1][:90], v - ks[j]) if j >= 0 and v - ks[j] < 0x8000 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
ca = next(v for v, n in syms if n == ctor)
JS = """
let n = 0; const OFF = %d, MAX = %d;
Interceptor.attach(ptr(%d), { onEnter(a) { this.obj = this.context.ecx; }, onLeave(r) {
  if (n >= MAX) return; const slot = n++;
  const addr = this.obj.add(OFF);
  send({ ctor: this.obj.toUInt32(), slot: slot, val: addr.readU32() });
  for (const t of Process.enumerateThreads()) { try { Thread.setHardwareWatchpoint ? 0 : 0; } catch (e) {} }
  Process.enumerateThreads().forEach(t => { try { Process.getCurrentThreadId(); } catch (e) {} });
  try { Process.setHardwareWatchpoint ? 0 : 0; } catch (e) {}
  // per-thread debug registers via the thread object (Frida 16.5: Thread#setHardwareWatchpoint)
  Process.enumerateThreads().forEach(t => { try { t.setHardwareWatchpoint(slot, addr, 4, 'w'); } catch (e) { send({err: '' + e}); } });
}});
Process.setExceptionHandler(function (d) {
  if (d.type !== 'single-step' && d.type !== 'breakpoint') return false;
  send({ hit: d.context.pc.toUInt32(), bt: Thread.backtrace(d.context, Backtracer.FUZZY).slice(0, 8).map(x => x.toUInt32()),
         eax: d.context.eax.toUInt32(), ecx: d.context.ecx.toUInt32() });
  return true;
});
""" % (off, mx, ca)
exe = os.path.abspath(str(H / 'run/RobloxQT.exe'))
pid = frida.spawn([exe], cwd=os.path.dirname(exe))
s = frida.attach(pid).create_script(JS)
ev = []
s.on('message', lambda m, d: ev.append(m.get('payload') if m.get('type') == 'send' else m))
s.load(); frida.resume(pid)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def frame():
    r = []
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            r.append(h)
        return True
    u.EnumWindows(P(cb), 0); return r[0] if r else None


t = time.time()
while not frame() and time.time() - t < 25:
    time.sleep(0.5)
time.sleep(2)
for c in post.split(','):
    if frame():
        u.PostMessageW(frame(), 0x111, int(c, 16), 0)
    time.sleep(4)
time.sleep(max(0, secs - 4))
try:
    frida.kill(pid)
except Exception:
    pass
for e in ev[:40]:
    if isinstance(e, dict) and 'hit' in e:
        print('WRITE at', near(e['hit']), 'eax %08x ecx %08x' % (e['eax'], e['ecx']))
        for b in e['bt'][:6]:
            print('      ', near(b))
    else:
        print(e)
