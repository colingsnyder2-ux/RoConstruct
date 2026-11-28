"""python ieloop.py: forever, every 1 s, close the IE pages the client opens: every visible iexplore.exe window and
Edge windows showing a Roblox/IE-redirect page (WM_CLOSE, graceful). Never kills ielowutil.exe (the client's IE COM
broker): killing it under a live client blocked the client's pending COM call -> "Server Busy / program is busy"."""
import ctypes, ctypes.wintypes as w, sys, time
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1]))
import ie_cleanup
u = ctypes.WinDLL('user32'); k = ctypes.WinDLL('kernel32')
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def ie_windows():
    out = []
    def cb(h, _):
        if u.IsWindowVisible(h):
            pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid))
            hp = k.OpenProcess(0x1000, False, pid.value)
            nm = ctypes.create_unicode_buffer(260); n = w.DWORD(260)
            if hp and k.QueryFullProcessImageNameW(hp, 0, nm, ctypes.byref(n)) and nm.value.lower().endswith('iexplore.exe'):
                out.append(h)
            if hp:
                k.CloseHandle(hp)
        return True
    u.EnumWindows(P(cb), 0)
    return out


while True:
    try:
        for h in ie_windows():
            u.PostMessageW(h, 0x0010, 0, 0)   # WM_CLOSE
        for h, t, m in ie_cleanup._edge_windows():
            if m:
                u.PostMessageW(h, 0x0010, 0, 0)
    except Exception as e:
        print('ieloop:', e, flush=True)
    time.sleep(1)
