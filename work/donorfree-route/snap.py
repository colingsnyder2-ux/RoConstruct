"""python snap.py EXE OUT.png [secs]: launch EXE (no debugger), File->New at 8 s, capture its main window (PrintWindow) at `secs`, kill."""
import ctypes, ctypes.wintypes as w, subprocess, sys, time, os
from PIL import Image
exe, out = sys.argv[1], sys.argv[2]
secs = float(sys.argv[3]) if len(sys.argv) > 3 else 20
p = subprocess.Popen([exe], cwd=os.path.dirname(os.path.abspath(exe)))
u, g = ctypes.WinDLL('user32'), ctypes.WinDLL('gdi32')
def wins():
    found = []
    CB = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
    def cb(h, l):
        pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid))
        t = ctypes.create_unicode_buffer(128); u.GetWindowTextW(h, t, 128)
        if pid.value == p.pid and 'Roblox' in t.value and u.IsWindowVisible(h): found.append(h)
        return True
    u.EnumWindows(CB(cb), 0)
    return found
time.sleep(8)
for h in wins(): u.PostMessageW(h, 0x111, 0xE100, 0)
time.sleep(max(1, secs - 8))
alive = p.poll() is None
hs = wins()
if hs:
    h = hs[0]; r = w.RECT(); u.GetWindowRect(h, ctypes.byref(r)); W, H = r.right - r.left, r.bottom - r.top
    hdc = u.GetWindowDC(h); mdc = g.CreateCompatibleDC(hdc); bmp = g.CreateCompatibleBitmap(hdc, W, H); g.SelectObject(mdc, bmp)
    u.PrintWindow(h, mdc, 2)   # PW_RENDERFULLCONTENT: DWM copy, includes D3D content, no focus needed
    print('hung' if u.IsHungAppWindow(h) else 'responsive')
    class BIH(ctypes.Structure):
        _fields_ = [('a', w.DWORD), ('w', w.LONG), ('h', w.LONG), ('p', w.WORD), ('b', w.WORD), ('c', w.DWORD), ('s', w.DWORD), ('x', w.LONG), ('y', w.LONG), ('u', w.DWORD), ('i', w.DWORD)]
    bi = BIH(40, W, -H, 1, 32, 0, 0, 0, 0, 0, 0); buf = ctypes.create_string_buffer(W * H * 4)
    g.GetDIBits(mdc, bmp, 0, H, buf, ctypes.byref(bi), 0)
    im = Image.frombuffer('RGBA', (W, H), buf.raw, 'raw', 'BGRA', 0, 1).convert('RGB')
    im.save(out)
    # acceptance: the 3D view area (window centre) must not be one flat colour (black / unpainted)
    from PIL import ImageStat
    c = im.crop((W // 4, H // 3, 3 * W // 4, 5 * H // 6))
    sd = sum(ImageStat.Stat(c).stddev) / 3
    title = ctypes.create_unicode_buffer(200); u.GetWindowTextW(h, title, 200)
    print('title %r | view stddev %.1f -> %s' % (title.value, sd, 'RENDERED' if sd > 8 else 'FLAT (not rendering)'))
print('alive' if alive else 'exited %s' % p.returncode, 'windows', len(hs))
p.kill()
