"""python throwtrace.py [EXE] [--post 0xE100] [--secs 15]: Frida tracer for error dialogs and C++ throws. Hooks
user32 MessageBoxA/W/IndirectA/W and kernel32 RaiseException (C++ throws = 0xE06D7363), launches the exe, posts the
WM_COMMANDs, and prints each event's text/code with a backtrace resolved through linkexp/qt.map (RobloxQT only).
The message boxes are answered automatically (IDOK). Writes auto/throwtrace.json."""
import bisect, ctypes, ctypes.wintypes as w, json, os, sys, time
from pathlib import Path
import frida
H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
post = next((args[i + 1] for i, a in enumerate(args) if a == '--post'), '0xE100')
secs = float(next((args[i + 1] for i, a in enumerate(args) if a == '--secs'), '15'))
syms = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            syms.append((int(p[2], 16), p[1]))
        except ValueError:
            pass
syms.sort(); ks = [v for v, _ in syms]
near = lambda v: (lambda j: '%s+%x' % (syms[j][1][:90], v - ks[j]) if j >= 0 and v - ks[j] < 0x4000 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
JS = r"""
function bt(ctx) { try { return Thread.backtrace(ctx, Backtracer.ACCURATE).slice(0, 14).map(a => a.toUInt32()); } catch (e) { return []; } }
for (const [fn, wide] of [['MessageBoxW', 1], ['MessageBoxA', 0]]) {
  Interceptor.replace(Module.getExportByName('user32.dll', fn), new NativeCallback(function (h, text, cap, type) {
    send({ ev: fn, text: wide ? text.readUtf16String() : text.readAnsiString(), cap: cap.isNull() ? '' : (wide ? cap.readUtf16String() : cap.readAnsiString()), bt: bt(this.context) });
    return 1;
  }, 'int', ['pointer', 'pointer', 'pointer', 'uint'], 'stdcall'));
}
for (const fn of ['MessageBoxIndirectW', 'MessageBoxIndirectA']) {
  Interceptor.replace(Module.getExportByName('user32.dll', fn), new NativeCallback(function (p) {
    const t = p.add(12).readPointer();
    send({ ev: fn, text: t.isNull() ? '' : (fn.endsWith('W') ? t.readUtf16String() : t.readAnsiString()), bt: bt(this.context) });
    return 1;
  }, 'int', ['pointer'], 'stdcall'));
}
Interceptor.attach(Module.getExportByName('kernel32.dll', 'RaiseException'), { onEnter(a) {
  const code = a[0].toUInt32();
  if (code === 0x406D1388 || code === 0x40010006) return;   // thread naming, OutputDebugString
  let type = '', what = '';
  try {   // C++ throw: args = [magic, object, ThrowInfo*]; ThrowInfo+12 -> CatchableTypeArray -> [0]+4 -> TypeDescriptor+8
    if (code === 0xE06D7363 && a[2].toUInt32() >= 3) {
      const ap = a[3], obj = ap.add(4).readPointer(), ti = ap.add(8).readPointer();
      const cta = ti.add(12).readPointer(), ct = cta.add(4).readPointer();
      type = ct.add(4).readPointer().add(8).readAnsiString();
      try { const w = obj.add(4).readPointer(); if (!w.isNull()) what = w.readAnsiString().slice(0, 160); } catch (e) {}
      if (!what) { try {   // msvcp90 runtime_error: std::string _Str at +0xC {aux*, buf/ptr[16], size, cap}
        const cap = obj.add(0x24).readU32(), sz = obj.add(0x20).readU32();
        what = 'str:' + (cap >= 16 ? obj.add(0x10).readPointer() : obj.add(0x10)).readAnsiString(Math.min(sz, 200));
      } catch (e) {} }
    }
  } catch (e) {}
  send({ ev: 'RaiseException', code: code, type: type, what: what, bt: bt(this.context) });
}});
// dynamic_cast on an object whose vtable has no RTTI locator at vtable[-1] (__non_rtti_object): report the vtable once
const badvt = {};
for (const fn of ['__RTDynamicCast', '__RTtypeid']) {
  const f = Module.findExportByName('msvcr90.dll', fn);
  if (!f) continue;
  Interceptor.attach(f, { onEnter(a) {
    try {
      const obj = a[0]; if (obj.isNull()) return;
      const vt = obj.readPointer(); const col = vt.sub(4).readPointer();
      let ok = false;
      try { ok = col.readU32() === 0 && col.add(12).readPointer().add(8).readU8() === 0x2e; } catch (e) {}
      const k = vt.toString();
      if (!ok && !badvt[k]) { badvt[k] = 1; send({ ev: 'NO-RTTI ' + fn, text: 'vtable ' + vt + ' col ' + col, bt: [vt.toUInt32()].concat(bt(this.context)) }); }
    } catch (e) {}
  }});
}
for (const fn of ['_invalid_parameter_noinfo', '_invalid_parameter', '_invoke_watson', '_purecall', 'abort', 'terminate']) {   // CRT fatal paths that never raise
  const f = Module.findExportByName('msvcr90.dll', fn) || (fn === 'terminate' ? Module.findExportByName('msvcr90.dll', '?terminate@@YAXXZ') : null);
  if (f) Interceptor.attach(f, { onEnter(a) { let st = []; try { st = Thread.backtrace(this.context, Backtracer.ACCURATE).slice(0, 24).map(x => x.toUInt32()); } catch (e) {} let raw = []; try { raw = Array.from(new Uint32Array(this.context.esp.readByteArray(0x800))); } catch (e) {} send({ ev: 'CRT ' + fn, bt: st, raw: raw }); } });
}
Process.setExceptionHandler(function (d) {   // report faults (first chance), let the process handle them
  if (d.type === 'breakpoint' || d.type === 'single-step') return false;
  send({ ev: 'FAULT ' + d.type, code: 0, text: 'pc ' + d.context.pc + ' addr ' + (d.memory ? d.memory.address : '?') + ' eax ' + d.context.eax + ' ecx ' + d.context.ecx + ' esi ' + d.context.esi,
         pc: d.context.pc.toUInt32(), bt: [d.context.pc.toUInt32()].concat(bt(d.context)) });
  return false;
});
send({ ready: 1 });
"""
import ieclean; t0 = time.time(); ieclean.clean()
pid = frida.spawn([exe] + (['-script', open(os.environ['ATTACH_ARGS_FILE']).read()] if os.environ.get('ATTACH_ARGS_FILE') else []), cwd=os.path.dirname(exe))   # ATTACH_ARGS_FILE: Lua for -script
scr = frida.attach(pid).create_script(JS)
ev = []
scr.on('message', lambda m, d: ev.append(m['payload']) if m.get('type') == 'send' and 'ev' in (m.get('payload') or {}) else print('frida:', m.get('payload') or m))
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


t1 = time.time()
while not frame() and time.time() - t1 < 25:
    time.sleep(0.5)
time.sleep(2)
for c in post.split(','):
    h = frame()
    if h:
        u.PostMessageW(h, 0x111, int(c, 16), 0); print('posted', c, flush=True)
    time.sleep(4)
time.sleep(max(0, secs - 4 * len(post.split(','))))
alive = frame() is not None
try:
    frida.kill(pid)
except Exception:
    pass
ieclean.clean(t0)
rows = [dict(e, code=('%#x' % e['code']) if 'code' in e else None, bt=[near(a) for a in e['bt']], raw=[near(v) for v in e.get('raw', []) if 0x401000 <= v < 0x8f0000]) for e in ev]
(H / 'auto/throwtrace.json').write_text(json.dumps(rows, indent=0))
print('events %d, main window alive at end: %s' % (len(rows), alive))
for r in rows[:30]:
    print('== %s %s %s %s %s' % (r['ev'], r.get('code') or '', r.get('type') or '', r.get('what') or '', (r.get('text') or '')[:120].replace('\n', ' | ')))
    for b in r['bt'][:10]:
        print('     ', b)
