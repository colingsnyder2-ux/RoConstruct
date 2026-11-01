"""Click a Part with the real mouse and confirm Explorer selection follows.
Needs a DESKTOP LOCK. Restores the cursor. Kills only the process it started."""
import ctypes, re, subprocess, sys, threading, time
from ctypes import wintypes

user = ctypes.windll.user32
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
x, y, width, height = map(int, re.match(r"p6: view (\S+) (\S+) (\S+) (\S+)", [l for l in lines if l.startswith("p6: view ")][0]).groups())
time.sleep(1)
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
    sys.exit("hung")
reader.join()
for line in lines:
    if line.startswith("p6:"):
        print(line)
selected = any(l.startswith("p6: properties") for l in lines)
print("selected", selected, "exit", process.returncode)
sys.exit(0 if selected and process.returncode == 0 else 1)
