"""python crashcont.py [EXE] [--ids auto/cmdcensus_ids.json] [--gap 1.5] [--skip-new]: crash-and-continue census.
ONE process: Frida saves esp/return address/SEH head at every USER32 DispatchMessageW/A entry on the UI thread; when
an access violation (or any fault) happens inside a dispatch, the exception handler records the command being
tested, pc, the nearest map symbol and a short backtrace, then rewinds the thread to that dispatch's return
(eax=0, esp after `ret 4`, SEH head restored) and the message loop continues with the next command.
Caveat: a recovered crash can leave state damaged; confirm crashed ids alone with cmdcensus.py --ids.
Writes auto/crashcont.json [{id, label, faults:[{pc, sym, bt}]}]."""
import bisect, ctypes, ctypes.wintypes as w, json, os, sys, time
from pathlib import Path
import frida
H = Path(__file__).parent
sys.path.insert(0, str(H))
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
idsf = args[args.index('--ids') + 1] if '--ids' in args else str(H / 'auto/cmdcensus_ids.json')
gap = float(args[args.index('--gap') + 1]) if '--gap' in args else 3.0   # cap per command (modal dialogs)
ids = json.load(open(idsf))
ids = [(r['id'] if isinstance(r, dict) else r, (r.get('label') or r.get('source') or '') if isinstance(r, dict) else '') for r in ids]
syms = []
mapf = H / 'linkexp/qt.map' if Path(exe).name == 'RobloxQT.exe' else None
if mapf:
    for l in open(mapf, errors='replace'):
        p = l.split()
        if len(p) >= 4 and p[0].startswith('0001:'):
            try:
                syms.append((int(p[2], 16), p[1]))
            except ValueError:
                pass
syms.sort(); ks = [v for v, _ in syms]
near = lambda v: (lambda j: '%s+%x' % (syms[j][1][:70], v - ks[j]) if j >= 0 and syms else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
JS = r"""
const teb = new NativeFunction(Module.getExportByName('ntdll.dll', 'NtCurrentTeb'), 'pointer', []);
let ui = 0; const stack = [];
for (const fn of ['DispatchMessageW', 'DispatchMessageA']) {
  Interceptor.attach(Module.getExportByName('user32.dll', fn), {
    onEnter(args) {
      if (ui === 0) ui = Process.getCurrentThreadId();
      if (Process.getCurrentThreadId() !== ui) return;
      this.rec = { esp: this.context.esp, ret: this.returnAddress, seh: teb().readPointer() };
      stack.push(this.rec);
    },
    onLeave(r) { if (this.rec) stack.pop(); }
  });
}
let cur = 0;
recv('cmd', function onCmd(m) { cur = m.id; recv('cmd', onCmd); });
Process.setExceptionHandler(function (d) {
  if (Process.getCurrentThreadId() !== ui || stack.length === 0) return false;
  if (d.type === 'breakpoint' || d.type === 'single-step') return false;
  const pc = d.context.pc.toUInt32();
  if (pc < 0x401000 || pc >= 0x3000000) return false;   // system-DLL first-chance faults are handled by their own SEH (ntdll probes)
  const top = stack.pop();
  let bt = [];
  try { bt = Thread.backtrace(d.context, Backtracer.FUZZY).slice(0, 8).map(a => a.toUInt32()); } catch (e) {}
  send({ fault: cur, type: d.type, pc: d.context.pc.toUInt32(), addr: d.memory ? d.memory.address.toUInt32() : 0, bt: bt });
  teb().writePointer(top.seh);           // SEH chain head as it was at the dispatch
  d.context.esp = top.esp.add(8);         // past return address + MSG* (stdcall ret 4)
  d.context.pc = top.ret;
  d.context.eax = ptr(0);
  return true;
});
send({ ready: 1 });
"""
import ieclean; t0 = time.time(); ieclean.clean()
pid = frida.spawn([exe], cwd=os.path.dirname(exe))
sess = frida.attach(pid)
scr = sess.create_script(JS)
faults = []
scr.on('message', lambda m, d: faults.append(m['payload']) if m.get('type') == 'send' and 'fault' in (m.get('payload') or {}) else print('frida:', m.get('payload') or m))
scr.load(); frida.resume(pid)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def frame():
    out = []
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            out.append(h)
        return True
    u.EnumWindows(P(cb), 0)
    return out[0] if out else None


def close_dialogs():
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and c.value == '#32770' and u.IsWindowVisible(h):
            u.PostMessageW(h, 0x0010, 0, 0)
        return True
    u.EnumWindows(P(cb), 0)


t1 = time.time()
while not frame() and time.time() - t1 < 30:
    time.sleep(0.5)
time.sleep(2)
alive = lambda: ctypes.WinDLL('kernel32').OpenProcess(0x1000, False, pid) and frida.get_local_device().enumerate_processes() and any(p.pid == pid for p in frida.get_local_device().enumerate_processes())
seq = [] if '--skip-new' in args else [(0xE100, 'File/New')]
done = []
for cid, lab in seq + ids:
    h = frame()
    if not h:
        print('main window gone after', len(done), 'commands'); break
    try:
        scr.post({'type': 'cmd', 'id': cid})
    except Exception:
        print('process gone after', len(done), 'commands'); break
    res = w.DWORD()
    # synchronous: returns when the handler is done (no fixed wait); a modal dialog blocks until the 3 s cap
    # POST the command (it goes through DispatchMessage: the crash handler can rewind to it), then a SENT WM_NULL
    # returns as soon as the thread pumps again = when the command finished; a modal dialog hits the cap
    u.PostMessageW(h, 0x111, cid, 0)
    if not u.SendMessageTimeoutW(h, 0x0000, 0, 0, 0x0002, int(gap * 1000), ctypes.byref(res)):
        close_dialogs(); time.sleep(0.2)
    close_dialogs()
    done.append(cid)
try:
    frida.kill(pid)
except Exception:
    pass
ieclean.clean(t0)
by = {}
for f in faults:
    by.setdefault(f['fault'], []).append({'type': f['type'], 'pc': '%08x' % f['pc'], 'sym': near(f['pc']), 'bt': [near(a) for a in f['bt']]})
lab = dict(seq + ids)
rows = [{'id': '%#x' % k, 'label': lab.get(k, ''), 'faults': v} for k, v in by.items()]
(H / 'auto/crashcont.json').write_text(json.dumps({'tested': len(done), 'rows': rows}, indent=0))
print('crashcont: commands tested %d in %.0fs, commands with faults %d' % (len(done), time.time() - t0, len(rows)))
for r in rows:
    print('  %-7s %-45s %s %s' % (r['id'], r['label'][:45], r['faults'][0]['sym'][:55], ('x%d' % len(r['faults'])) if len(r['faults']) > 1 else ''))
