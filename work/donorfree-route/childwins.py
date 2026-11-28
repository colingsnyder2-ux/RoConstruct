"""python childwins.py EXE [secs] [orig]: launch, File->New at 8 s, at `secs` list the main window's child tree (class, visible, size)."""
import ctypes, ctypes.wintypes as w, subprocess, sys, time, os
exe = sys.argv[1]; secs = float(sys.argv[2]) if len(sys.argv) > 2 else 20
p = subprocess.Popen([exe], cwd=os.path.dirname(os.path.abspath(exe)))
u = ctypes.WinDLL('user32'); CB = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def top():
    f = []
    def cb(h, l):
        pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid)); t = ctypes.create_unicode_buffer(128); u.GetWindowTextW(h, t, 128)
        if pid.value == p.pid and 'Roblox' in t.value and u.IsWindowVisible(h): f.append(h)
        return True
    u.EnumWindows(CB(cb), 0); return f
time.sleep(8)
for h in top(): u.PostMessageW(h, 0x111, 0xE100, 0)
time.sleep(max(1, secs - 8))
def dump(h, d=0):
    if d > 4: return
    kids = []
    def cb(c, l):
        if u.GetParent(c) == h: kids.append(c)
        return True
    u.EnumChildWindows(h, CB(cb), 0)
    for c in kids[:25]:
        cn = ctypes.create_unicode_buffer(64); u.GetClassNameW(c, cn, 64); t = ctypes.create_unicode_buffer(40); u.GetWindowTextW(c, t, 40)
        r = w.RECT(); u.GetWindowRect(c, ctypes.byref(r))
        print('  ' * d + '%s "%s" vis=%d %dx%d' % (cn.value, t.value, u.IsWindowVisible(c), r.right - r.left, r.bottom - r.top))
        dump(c, d + 1)
for h in top()[:1]: dump(h)
p.kill()
