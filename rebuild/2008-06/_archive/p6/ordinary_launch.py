"""P6 gate: launch with only a place path, close the window normally, twice.
Needs a DESKTOP LOCK. Kills only the process it started."""
import ctypes, subprocess, sys, time
from ctypes import wintypes

user = ctypes.windll.user32
exe, place = sys.argv[1:3]
PROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
failed = 0
for run in (1, 2):
    process = subprocess.Popen([exe, place], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, cwd=exe.rsplit(chr(92), 1)[0])
    found = []

    def visit(hwnd, _):
        owner = wintypes.DWORD()
        user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
        if owner.value == process.pid and user.IsWindowVisible(hwnd):
            found.append(hwnd)
        return True

    time.sleep(4)
    user.EnumWindows(PROC(visit), 0)
    if not found:
        process.kill()
        print("run", run, "no window")
        failed = 1
        continue
    user.PostMessageW(found[0], 0x10, 0, 0)
    try:
        code = process.wait(timeout=10)
    except subprocess.TimeoutExpired:
        process.kill()
        code = "hung"
    print("run", run, "exit", code)
    failed |= code != 0
sys.exit(failed)
