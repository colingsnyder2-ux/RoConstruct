"""Launch the client visibly, hold W with real input, report actor movement.
Needs a DESKTOP LOCK. Kills only the process it started."""
import ctypes, subprocess, sys, time
from ctypes import wintypes
user = ctypes.windll.user32
exe, place = sys.argv[1], sys.argv[2]
process = subprocess.Popen([exe, "-p6-visible", place], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, cwd=exe.rsplit("\\", 1)[0], errors="replace")
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
user.keybd_event(0x12, 0, 0, 0)  # Alt press permits the foreground change
user.SetForegroundWindow(found[0])
user.keybd_event(0x12, 0, 2, 0)
time.sleep(0.2)
focused = user.GetForegroundWindow() == found[0]
user.keybd_event(0x57, 0x11, 0, 0)
time.sleep(1.5)
user.keybd_event(0x57, 0x11, 2, 0)
try:
    output, _ = process.communicate(timeout=15)
except subprocess.TimeoutExpired:
    process.kill()
    sys.exit("hung")
print("focused", focused, "exit", process.returncode)
print("\n".join(l for l in output.split("\n") if l.startswith("p6:") or "mesh cleanup" in l))
sys.exit(0 if focused and process.returncode == 0 else 1)
