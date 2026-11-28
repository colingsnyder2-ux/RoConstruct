"""python shot.py [EXE] [secs]: run the client normally (no debugger), post File->New to its main frame, wait, and save a
screenshot of the main window to auto/shot.png (PrintWindow with full-content rendering, so a covered window still
captures; falls back to a screen grab of the window rectangle). Kills the client afterwards. Prints the window title
and any dialog captions seen (crash / error boxes)."""
import ctypes, ctypes.wintypes as w, os, subprocess, sys, time
from pathlib import Path
from PIL import Image, ImageGrab
H = Path(__file__).parent
exe = next((a for a in sys.argv[1:] if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe'))
secs = float(next((a for a in sys.argv[1:] if a.replace('.', '').isdigit()), '25'))
u = ctypes.WinDLL('user32'); g = ctypes.WinDLL('gdi32')
exe = os.path.abspath(exe)
_si = None
if os.environ.get('SHOT_FORCE_SHOW'):   # STARTF_USESHOWWINDOW + SW_SHOWNORMAL, as the debugger probe launches it
    _si = subprocess.STARTUPINFO(); _si.dwFlags |= 1; _si.wShowWindow = 1
_T0 = time.time(); import ieclean as _iec; _iec.clean()   # baseline: the user's own Edge windows
p = subprocess.Popen([exe], cwd=os.path.dirname(exe), startupinfo=_si)
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def windows():
    res = []
    def cb(h, _):
        pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid))
        if pid.value == p.pid and u.IsWindowVisible(h):
            t = ctypes.create_unicode_buffer(256); u.GetWindowTextW(h, t, 256)
            c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
            r = w.RECT(); u.GetWindowRect(h, ctypes.byref(r))
            res.append((h, t.value, c.value, (r.left, r.top, r.right, r.bottom)))
        return True
    u.EnumWindows(P(cb), 0)
    return res


main, posted, dialogs, t0 = None, False, set(), time.time()
while time.time() - t0 < secs and p.poll() is None:
    ws = windows()
    for h, t, c, r in ws:
        if c == '#32770':
            dialogs.add(t)
    frames = [x for x in ws if x[2] != '#32770' and (x[3][2] - x[3][0]) > 400]
    if frames and not posted and time.time() - t0 > 4:
        main = max(frames, key=lambda x: (x[3][2] - x[3][0]) * (x[3][3] - x[3][1]))
        u.PostMessageW(main[0], 0x111, 0xE100, 0)   # WM_COMMAND ID_FILE_NEW
        for _c in filter(None, os.environ.get('SHOT_POST', '').split(',')):   # more WM_COMMANDs after File->New (0x80c6 Run)
            time.sleep(4); u.PostMessageW(main[0], 0x111, int(_c, 16), 0)
        posted, tp = True, time.time()
    if posted and time.time() - tp > secs * 0.6:
        break
    time.sleep(0.5)
ws = windows()
frames = [x for x in ws if x[2] != '#32770' and (x[3][2] - x[3][0]) > 400]
out = H / 'auto/shot.png'
if frames:
    h, t, c, (l, tp_, rr, bb) = max(frames, key=lambda x: (x[3][2] - x[3][0]) * (x[3][3] - x[3][1]))
    wd, ht = rr - l, bb - tp_
    hdc = u.GetWindowDC(h); mdc = g.CreateCompatibleDC(hdc); bmp = g.CreateCompatibleBitmap(hdc, wd, ht)
    g.SelectObject(mdc, bmp)
    ok = u.PrintWindow(h, mdc, 2)   # PW_RENDERFULLCONTENT
    class BMI(ctypes.Structure):
        _fields_ = [('biSize', w.DWORD), ('biWidth', w.LONG), ('biHeight', w.LONG), ('biPlanes', w.WORD), ('biBitCount', w.WORD),
                    ('biCompression', w.DWORD), ('biSizeImage', w.DWORD), ('a', w.LONG), ('b', w.LONG), ('c', w.DWORD), ('d', w.DWORD)]
    bi = BMI(ctypes.sizeof(BMI), wd, -ht, 1, 32, 0, 0, 0, 0, 0, 0)
    buf = ctypes.create_string_buffer(wd * ht * 4)
    g.GetDIBits(mdc, bmp, 0, ht, buf, ctypes.byref(bi), 0)
    img = Image.frombuffer('RGBA', (wd, ht), buf, 'raw', 'BGRA', 0, 1).convert('RGB')
    if not ok or img.getextrema() == ((0, 0), (0, 0), (0, 0)):
        img = ImageGrab.grab((l, tp_, rr, bb))
    img.save(out)
    g.DeleteObject(bmp); g.DeleteDC(mdc); u.ReleaseDC(h, hdc)
    print('window: %r  size %dx%d  -> %s' % (t, wd, ht, out))
else:
    print('no main window (process %s)' % ('exited %s' % p.returncode if p.poll() is not None else 'running'))
print('dialogs seen: %s' % (sorted(dialogs) or 'none'))
print('process: %s' % ('exited code %s' % p.returncode if p.poll() is not None else 'still running after %.0fs' % (time.time() - t0)))
if p.poll() is None:
    p.kill()
import ieclean as _iec; _iec.clean(_T0)   # the client's IE pages open as Edge windows on Windows 11
