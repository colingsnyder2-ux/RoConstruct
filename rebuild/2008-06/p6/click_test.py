"""Click a Part with the real mouse and confirm Explorer selection follows.
Needs a DESKTOP LOCK. Restores the cursor. Kills only the process it started."""
import ctypes, re, subprocess, sys, threading, time
from ctypes import wintypes

user = ctypes.windll.user32
PROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
exe, place, capture = sys.argv[1:4]
process = subprocess.Popen([exe, "-p6-visible", "-p6-capture", capture, place], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                           cwd=exe.rsplit(chr(92), 1)[0], errors="replace")
lines = []
ready = threading.Event()


def read():
    for line in process.stdout:
        lines.append(line.rstrip())
        if line.startswith("p6: view "):
            ready.set()


reader = threading.Thread(target=read)
reader.start()
if not ready.wait(20):
    process.kill()
    sys.exit("no view")
time.sleep(1)
frames, views = [], []
@PROC
def frame(hwnd, _):
    owner = wintypes.DWORD()
    user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
    title = ctypes.create_unicode_buffer(200)
    user.GetWindowTextW(hwnd, title, 200)
    if owner.value == process.pid and user.IsWindowVisible(hwnd) and title.value.startswith("Roblox"):
        frames.append(hwnd)
    return True
@PROC
def view(hwnd, _):
    name = ctypes.create_unicode_buffer(200)
    user.GetClassNameW(hwnd, name, 200)
    if user.GetDlgCtrlID(hwnd) == 0xe900 and name.value.startswith("AfxFrameOrView"):
        views.append(hwnd)
    return True
user.EnumWindows(frame, 0)
if len(frames) != 1:
    process.kill()
    sys.exit("no unique client frame")
user.ShowWindow(frames[0], 9)
user.keybd_event(0x10, 0, 0, 0)
user.SetForegroundWindow(frames[0])
user.keybd_event(0x10, 0, 2, 0)
time.sleep(0.1)
user.EnumChildWindows(frames[0], view, 0)
if len(views) != 1 or user.GetForegroundWindow() != frames[0]:
    process.kill()
    sys.exit("client view not ready or foreground")
rect, origin = wintypes.RECT(), wintypes.POINT()
user.GetClientRect(views[0], ctypes.byref(rect))
user.ClientToScreen(views[0], ctypes.byref(origin))
x, y, width, height = origin.x, origin.y, rect.right, rect.bottom
print("live view", x, y, width, height)
saved = wintypes.POINT()
user.GetCursorPos(ctypes.byref(saved))
user.SetCursorPos(x + int(width * 0.35), y + height // 2)
time.sleep(0.2)
user.mouse_event(2, 0, 0, 0, 0)
time.sleep(0.1)
user.SetCursorPos(x + int(width * 0.35) + 90, y + height // 2 + 20)
time.sleep(0.3)
user.mouse_event(4, 0, 0, 0, 0)
time.sleep(0.3)
user.SetCursorPos(saved.x, saved.y)
try:
    process.wait(timeout=15)
except subprocess.TimeoutExpired:
    process.kill()
    reader.join()
    print("\n".join(lines[-6:]))
    sys.exit("hung")
reader.join()
for line in lines:
    if line.startswith("p6:"):
        print(line)
selected = any(l.startswith("p6: properties") for l in lines)
print("selected", selected, "exit", process.returncode)
sys.exit(0 if selected and process.returncode == 0 else 1)
