import subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
place=r'C:\Users\colin\.gemini\antigravity-cli\brain\ee296e4a-3adb-4799-a651-b977dfbce23a\scratch\Work_at_a_Pizza_Place.rbxl'
proc=subprocess.Popen([exe, place], cwd=str(root/'run'))
time.sleep(30)
u=ctypes.WinDLL('user32')
P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM)
allw=[]
def cb(h,_):
    pid=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(pid))
    if pid.value==proc.pid:
        c=ctypes.create_unicode_buffer(128); u.GetClassNameW(h,c,128)
        r=w.RECT(); u.GetWindowRect(h,ctypes.byref(r))
        allw.append((h,c.value,(r.right-r.left,r.bottom-r.top)))
    return True
u.EnumWindows(P(cb),0)
# also children of top-level
children=[]
for h,cls,sz in allw:
    if sz[0]>500 and sz[1]>300:
        def cb2(ch,_):
            c=ctypes.create_unicode_buffer(128); u.GetClassNameW(ch,c,128)
            r=w.RECT(); u.GetWindowRect(ch,ctypes.byref(r))
            children.append((ch,c.value,(r.right-r.left,r.bottom-r.top)))
            return True
        u.EnumChildWindows(h,P(cb2),0)
print('top:',allw)
print('children large:',[(c[1],c[2]) for c in children if c[2][0]>200])
proc.kill(); proc.wait()