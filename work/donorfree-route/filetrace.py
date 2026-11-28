"""python filetrace.py EXE [--post 0xE100] [--secs 12]: list files the client opens (kernel32 CreateFileA/W, with the
result handle) during startup + the posted commands. Diff ours vs RobloxOrig.exe to find wrong content paths."""
import ctypes, ctypes.wintypes as w, os, sys, time
import frida
a = sys.argv[1:]
exe = os.path.abspath(a[0])
post = next((a[i + 1] for i, x in enumerate(a) if x == '--post'), '0xE100')
secs = float(next((a[i + 1] for i, x in enumerate(a) if x == '--secs'), '12'))
JS = """
for (const [fn, wide] of [['CreateFileW', 1], ['CreateFileA', 0]]) {
  Interceptor.attach(Module.getExportByName('kernelbase.dll', fn), {
    onEnter(x) { this.n = wide ? x[0].readUtf16String() : x[0].readAnsiString(); },
    onLeave(r) { send({ f: this.n, ok: r.toInt32() !== -1 }); } });
}
"""
pid = frida.spawn([exe], cwd=os.path.dirname(exe))
s = frida.attach(pid).create_script(JS)
ev = []
s.on('message', lambda m, d: ev.append(m.get('payload')))
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
seen = []
for e in ev:
    if isinstance(e, dict) and e.get('f'):
        k = ('OK  ' if e['ok'] else 'FAIL') + ' ' + e['f']
        if k not in seen:
            seen.append(k)
print('\n'.join(seen))
