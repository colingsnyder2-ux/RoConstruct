import subprocess, time, ctypes, ctypes.wintypes as w, os, glob
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
place=r'C:\Users\colin\.gemini\antigravity-cli\brain\ee296e4a-3adb-4799-a651-b977dfbce23a\scratch\Work_at_a_Pizza_Place.rbxl'
proc=subprocess.Popen([exe, place], cwd=str(root/'run'))
time.sleep(45)
u=ctypes.WinDLL('user32')
P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM)
target=None
def cb(h,_):
    global target
    pid=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(pid))
    if pid.value==proc.pid:
        c=ctypes.create_unicode_buffer(128); u.GetClassNameW(h,c,128)
        if c.value=='ROBLOX-ATOM':
            target=h
    return True
u.EnumWindows(P(cb),0)
print('target',target)
if target:
    u.SetForegroundWindow(target)
    time.sleep(2)
    # send PrintScreen
    u.keybd_event(0x2C,0,0,0)
    time.sleep(0.2)
    u.keybd_event(0x2C,0,2,0)
    print('sent PrintScreen')
time.sleep(8)
# search for new screenshots
candidates=[]
for base in [os.path.expanduser('~'), r'C:\Users\colin\OneDrive', r'C:\Users\colin']:
    for pat in ['**\\Roblox*.png','**\\Roblox*.jpg','**\\Screenshots\\*.png']:
        candidates += glob.glob(os.path.join(base, pat), recursive=True)
print('found', len(candidates))
for f in sorted(candidates, key=os.path.getmtime, reverse=True)[:10]:
    print(f, os.path.getmtime(f))
proc.kill(); proc.wait()