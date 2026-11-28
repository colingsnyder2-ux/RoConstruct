"""python ttdrec.py [EXE] [--post 0xE100] [--out DIR]: record a Time Travel Debugging trace of the client (TTD.exe from
the WinDbg package), post the WM_COMMANDs once the main frame shows (File->New = 0xE100), and wait for the process to
exit/crash. The .run file lands in DIR (default auto/ttd). Replay headless with ttdq.py (cdb -z)."""
import ctypes, ctypes.wintypes as w, glob, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
post = next((args[i + 1] for i, a in enumerate(args) if a == '--post'), '0xE100')
out = os.path.abspath(next((args[i + 1] for i, a in enumerate(args) if a == '--out'), str(H / 'auto/ttd')))
TTD = os.path.expandvars(r'%LOCALAPPDATA%\Microsoft\WindowsApps\ttd.exe')   # app-execution alias (the package dir is not executable)
os.makedirs(out, exist_ok=True)
for f in glob.glob(os.path.join(out, '*.run')) + glob.glob(os.path.join(out, '*.idx')) + glob.glob(os.path.join(out, '*.out')):
    os.remove(f)
p = subprocess.Popen([TTD, '-accepteula', '-out', out, '-launch', exe], cwd=os.path.dirname(exe), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def frame():
    hs = []
    def cb(h, _):
        c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            t = ctypes.create_unicode_buffer(128); u.GetWindowTextW(h, t, 128)
            if 'Roblox' in t.value:
                hs.append(h)
        return True
    u.EnumWindows(P(cb), 0)
    return hs[0] if hs else None


t0 = time.time()
while not frame() and time.time() - t0 < 120 and p.poll() is None:
    time.sleep(1)
time.sleep(4)
for c in post.split(','):
    h = frame()
    if h:
        u.PostMessageW(h, 0x111, int(c, 16), 0); print('posted', c, flush=True)
    time.sleep(6)
try:
    o, _ = p.communicate(timeout=120)
except subprocess.TimeoutExpired:
    subprocess.run(['taskkill', '/F', '/IM', os.path.basename(exe)], capture_output=True); o, _ = p.communicate()
print(o[-1500:])
print('traces:', glob.glob(os.path.join(out, '*.run')))
