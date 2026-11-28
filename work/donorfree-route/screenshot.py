import subprocess, time, ctypes, ctypes.wintypes as w
from PIL import Image
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
place=r'C:\Users\colin\.gemini\antigravity-cli\brain\ee296e4a-3adb-4799-a651-b977dfbce23a\scratch\Work_at_a_Pizza_Place.rbxl'
proc=subprocess.Popen([exe, place], cwd=str(root/'run'))
time.sleep(45)
u=ctypes.WinDLL('user32'); g=ctypes.WinDLL('gdi32')
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
if not target:
    proc.kill(); raise SystemExit('no render window')
u.SetWindowPos(target, -1, 0,0,0,0, 0x0003)  # topmost, no move/size? SWP_NOMOVE|SWP_NOSIZE
rect=w.RECT(); u.GetWindowRect(target,ctypes.byref(rect))
width=rect.right-rect.left; height=rect.bottom-rect.top
print('rect',rect.left,rect.top,width,height)
u.SetForegroundWindow(target); time.sleep(4)
screen_dc=u.GetDC(0)
memdc=g.CreateCompatibleDC(screen_dc)
bmp=g.CreateCompatibleBitmap(screen_dc,width,height)
g.SelectObject(memdc,bmp)
g.BitBlt(memdc,0,0,width,height,screen_dc,rect.left,rect.top,0x00CC0020)
class BITMAPINFOHEADER(ctypes.Structure):
    _fields_=[('biSize',ctypes.c_uint32),('biWidth',ctypes.c_int32),('biHeight',ctypes.c_int32),
              ('biPlanes',ctypes.c_uint16),('biBitCount',ctypes.c_uint16),('biCompression',ctypes.c_uint32),
              ('biSizeImage',ctypes.c_uint32),('biXPelsPerMeter',ctypes.c_int32),('biYPelsPerMeter',ctypes.c_int32),
              ('biClrUsed',ctypes.c_uint32),('biClrImportant',ctypes.c_uint32)]
bih=BITMAPINFOHEADER(); bih.biSize=ctypes.sizeof(BITMAPINFOHEADER); bih.biWidth=width; bih.biHeight=-height; bih.biPlanes=1; bih.biBitCount=32; bih.biCompression=0
buf=ctypes.create_string_buffer(width*height*4)
g.GetDIBits(memdc,bmp,0,height,buf,ctypes.byref(bih),0)
img=Image.frombuffer('RGBA',(width,height),buf,'raw','BGRA',0,1)
out=root/'run'/'pizza_place.png'
img.save(out)
print('saved',out)
px=img.load(); import collections; c=collections.Counter()
for y in range(0,height,10):
  for x in range(0,width,10):
    c[px[x,y][:3]]+=1
print('colors',c.most_common(6))
g.DeleteObject(bmp); g.DeleteDC(memdc); u.ReleaseDC(0,screen_dc)
u.SetWindowPos(target, 1, 0,0,0,0, 0x0003)
proc.kill(); proc.wait()