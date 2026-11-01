"""Launch the client visibly, hold W with real input, report actor movement.
Needs a DESKTOP LOCK. Kills only the process it started."""
import ctypes, subprocess, sys, threading, time
from ctypes import wintypes
user = ctypes.windll.user32
exe, place = sys.argv[1], sys.argv[2]
process = subprocess.Popen([exe, "-p6-visible", "-p6-play", place], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, cwd=exe.rsplit("\\", 1)[0], errors="replace")
lines = []
ready = threading.Event()
def read():
    for line in process.stdout:
        lines.append(line.rstrip())
        if "engine open" in line:
            ready.set()
reader = threading.Thread(target=read)
reader.start()
found = []
PROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
def visit(hwnd, _):
    owner = wintypes.DWORD()
    user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
    if owner.value == process.pid and user.IsWindowVisible(hwnd):
        found.append(hwnd)
    return True
deadline = time.time() + 3
while not found and time.time() < deadline:
    user.EnumWindows(PROC(visit), 0)
    time.sleep(0.05)
if not found:
    process.kill()
    sys.exit("no window")
user.keybd_event(0x10, 0, 0, 0)  # Shift, not Alt: Alt arms menu mnemonics and W would open Window
user.SetForegroundWindow(found[0])
user.keybd_event(0x10, 0, 2, 0)
if not ready.wait(20):
    process.kill()
    sys.exit("engine not ready")
time.sleep(2.0)  # spawn falls and lands first
focused = user.GetForegroundWindow() == found[0]
user.keybd_event(0x57, 0x11, 0, 0)
held = 0
foreground = set()
for _ in range(30):
    time.sleep(0.05)
    foreground.add(user.GetForegroundWindow())
    held += (user.GetAsyncKeyState(0x57) & 0x8000) != 0
user.keybd_event(0x57, 0x11, 2, 0)
print("held samples", held, "foreground windows", len(foreground), "lost focus", foreground != {found[0]})
try:
    process.wait(timeout=15)
except subprocess.TimeoutExpired:
    process.kill()
    sys.exit("hung")
reader.join()
print("focused", focused, "exit", process.returncode)
for line in lines:
    if line.startswith("p6:") or "mesh cleanup" in line:
        print(line)
sys.exit(0 if focused and process.returncode == 0 else 1)
