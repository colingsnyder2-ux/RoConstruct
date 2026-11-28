"""Count physics pipeline calls during the falling-part reproduction."""
import ctypes, ctypes.wintypes as w, os, re, sys, time
from pathlib import Path
import frida

root = Path(__file__).resolve().parent.parent
orig = '--orig' in sys.argv
symbols = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = line.split()
    if len(p) >= 4 and re.fullmatch(r'[0-9a-fA-F]{8}', p[2]): symbols[p[1]] = int(p[2], 16)
functions = {
    'start': ('?start@RunService@RBX@@AAEXXZ', 0x556520),
    'runProc': ('func_00555190', 0x555190),
    'workspaceStep': ('?step@Workspace@RBX@@QAEMM@Z', 0x5a2580),
    'worldStep': ('?step@World@RBX@@QAEMM@Z', 0x5e9fd0),
    'kernelStep': ('?stepWorld@Kernel@RBX@@UAEXHH_N@Z', 0x5fb3f0),
    'insertPrimitive': ('?insertPrimitive@World@RBX@@QAEXPAVPrimitive@2@@Z', 0x5e98f0),
    'ticklePrimitive': ('?ticklePrimitive@World@RBX@@QAEXPAVPrimitive@2@_N@Z', 0x5e9410),
    'clumpAdd': ('func_0064cae0', 0x64cae0),
    'treeAdd': ('func_00668d30', 0x668d30),
    'cleanEdge': ('func_0064a4d0', 0x64a4d0),
    'simEdge': ('?onEdgeAdded@SimJobStage@RBX@@UAEXPAVEdge@2@@Z', 0x64d060),
    'jointEdge': ('?onEdgeAdded@JointStage@RBX@@UAEXPAVEdge@2@@Z', 0x6683b0),
    'worldEdge': ('?onEdgeAdded@IWorldStage@RBX@@UAEXPAVEdge@2@@Z', 0x669cf0),
}
addresses = {name: original if orig else symbols[symbol] for name, (symbol, original) in functions.items()}
exe = str(root / ('run/RobloxOrig.exe' if orig else 'run/RobloxQT.exe'))
source = (root / 'auto/focus_physics.lua').read_text()
pid = frida.spawn([exe, '-script', source], cwd=os.path.dirname(exe))
session = frida.attach(pid)
js = '''
const counts = {}, maxCounts = {array1: 0, array2: 0}; for (const [name, address] of Object.entries(ADDRESSES)) {
  counts[name] = 0; Interceptor.attach(ptr(address), {onEnter() {
    counts[name]++;
    if (name === 'kernelStep') { try {
      const state = this.context.ecx.add(0x10).readPointer();
      maxCounts.array1 = Math.max(maxCounts.array1, state.add(0x1c).readS32());
      maxCounts.array2 = Math.max(maxCounts.array2, state.add(0x28).readS32());
    } catch (e) {} }
  }});
}
rpc.exports = { counts() { return {counts, maxCounts}; } };
'''.replace('ADDRESSES', str(addresses))
script = session.create_script(js); script.load(); frida.resume(pid)
time.sleep(8)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def cb(h, _):
    p = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p))
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128)
    if p.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
        u.PostMessageW(h, 0x111, 32966, 0)
    return True
u.EnumWindows(P(cb), 0); time.sleep(6)
print('physics calls:', script.exports_sync.counts(), flush=True)
frida.kill(pid)
