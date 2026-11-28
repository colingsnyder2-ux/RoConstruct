"""Exercise explosion rendering and observe its particle texture being opened."""
import ctypes
import ctypes.wintypes as w
import os
import re
import sys
import time
from pathlib import Path
import frida
root = Path(__file__).resolve().parents[1]
exe = Path(sys.argv[1] if len(sys.argv) > 1 else root / 'run/RobloxQT.exe').resolve()
if exe.name.lower() == 'robloxorig.exe':
    address = 0x675360
else:
    symbol = '?explosion@AdornRbxGfx@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z'
    line = next(l for l in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines() if len(l.split()) >= 3 and l.split()[1] == symbol)
    address = int(line.split()[2], 16)
lua = 'while true do local e=Instance.new("Explosion") e.Position=Vector3.new(0,5,0) e.BlastRadius=0 e.Parent=workspace wait(3) end'
device = frida.get_local_device()
device.on('output', lambda *args: None)
pid = device.spawn([str(exe), '-script', lua], cwd=str(exe.parent), stdio='pipe')
session = device.attach(pid)
events = set()
script = session.create_script('''var seen={};
Interceptor.attach(ptr('%s'),{onEnter(){if(!seen.draw){seen.draw=1;send('draw');}}});
Interceptor.attach(Module.getExportByName('kernelbase.dll','CreateFileW'),{onEnter(a){try{var p=a[0].readUtf16String();if(p.toLowerCase().indexOf('explosion.png')>=0&&!seen.file){seen.file=1;send('texture');}}catch(e){}}});''' % hex(address))
script.on('message', lambda m, d: events.add(m['payload']) if m.get('type') == 'send' else None)
script.load()
device.resume(pid)
u = ctypes.WinDLL('user32')
callback = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def frame():
    found = []
    def visit(h, _):
        owner = w.DWORD()
        u.GetWindowThreadProcessId(h, ctypes.byref(owner))
        cls = ctypes.create_unicode_buffer(128)
        u.GetClassNameW(h, cls, 128)
        if owner.value == pid and u.IsWindowVisible(h) and cls.value.startswith('Afx:'):
            found.append(h)
        return True
    u.EnumWindows(callback(visit), 0)
    return found[0] if found else None
start = time.monotonic()
posted = False
try:
    while time.monotonic() - start < 50 and events != {'draw', 'texture'}:
        time.sleep(.25)
        h = frame()
        if not posted and h and time.monotonic() - start > 12:
            u.PostMessageW(h, 0x111, 32966, 0)
            posted = True
finally:
    try:
        device.kill(pid)
    except frida.ProcessNotFoundError:
        pass
print('explosion:', sorted(events), 'run posted:', posted)
sys.exit(0 if events == {'draw', 'texture'} else 1)
