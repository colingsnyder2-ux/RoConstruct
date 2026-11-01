"""Open a saved place in the unmodified original client and capture its window.
Needs a DESKTOP LOCK. Terminates only the process it started."""
import ctypes, subprocess, sys, time
from ctypes import wintypes
from PIL import ImageGrab

user = ctypes.windll.user32
exe, place, out = sys.argv[1:4]
process = subprocess.Popen([exe, place], cwd=exe.rsplit(chr(92), 1)[0])
time.sleep(8)
found = []
PROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)


def visit(hwnd, _):
    owner = wintypes.DWORD()
    user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
    rect = wintypes.RECT()
    user.GetWindowRect(hwnd, ctypes.byref(rect))
    if owner.value == process.pid and user.IsWindowVisible(hwnd) and rect.right - rect.left > 300:
        found.append(hwnd)
    return True


user.EnumWindows(PROC(visit), 0)
print("alive", process.poll() is None, "windows", len(found))
if found:
    title = ctypes.create_unicode_buffer(200)
    user.GetWindowTextW(found[0], title, 200)
    print("title", title.value)
    user.keybd_event(0x12, 0, 0, 0)
    user.SetForegroundWindow(found[0])
    user.keybd_event(0x12, 0, 2, 0)
    time.sleep(1)
    rect = wintypes.RECT()
    user.GetWindowRect(found[0], ctypes.byref(rect))
    ImageGrab.grab((rect.left, rect.top, rect.right, rect.bottom), all_screens=True).save(out)
process.terminate()
process.wait(timeout=10)
