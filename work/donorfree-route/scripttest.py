"""python scripttest.py [EXE] [--orig run/RobloxOrig.exe] [--lua FILE]: FEATURE_LADDER Tiers 3-4 without UI driving. Launches
the client with `-script "<lua>"` (the command line the app itself builds for Play Solo), the Lua records each check as a
StringValue named 'PASS <name>' / 'FAIL <name>' under Workspace, and the harness reads those names from the Explorer tree
(TreeView, Workspace expanded). Default Lua: feature_test.lua (FEATURE_LADDER.md). Runs the original too; writes
auto/scripttest.json."""
import ctypes, ctypes.wintypes as w, json, os, re, struct, subprocess, sys, time
from pathlib import Path
import ieclean
H = Path(__file__).parent
u, k = ctypes.WinDLL('user32'), ctypes.WinDLL('kernel32')
k.VirtualAllocEx.restype = ctypes.c_void_p
k.VirtualAllocEx.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_size_t, w.DWORD, w.DWORD]
k.WriteProcessMemory.argtypes = k.ReadProcessMemory.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p]
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
args = sys.argv[1:]
EXE = next((a for i, a in enumerate(args) if a.lower().endswith('.exe') and (i == 0 or args[i - 1] != '--orig')), str(H / 'run/RobloxQT.exe'))
ORIG = args[args.index('--orig') + 1] if '--orig' in args else str(H / 'run/RobloxOrig.exe')
LUA = Path(args[args.index('--lua') + 1]) if '--lua' in args else H / 'feature_test.lua'


def cls(h):
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128); return c.value


def snd(h, m, wp=0, lp=0, a=False):
    r = ctypes.c_size_t(0)
    f = u.SendMessageTimeoutA if a else u.SendMessageTimeoutW
    return r.value if f(h, m, ctypes.c_size_t(wp), ctypes.c_ssize_t(lp), 2, 3000, ctypes.byref(r)) else None


def run(exe, lua, wait=25):
    ieclean.clean(); exe = os.path.abspath(exe)
    code = chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
    p = subprocess.Popen([exe, '-script', code], cwd=os.path.dirname(exe))
    hp = k.OpenProcess(0x1F0FFF, False, p.pid); mem = k.VirtualAllocEx(hp, None, 4096, 0x3000, 4)
    def wins(pred):
        out = []
        def cb(h, _):
            q = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(q))
            if q.value == p.pid and u.IsWindowVisible(h) and pred(h): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out
    t0 = time.time(); ran = False
    while time.time() - t0 < wait and p.poll() is None:
        time.sleep(1)
        if not ran and time.time() - t0 > 8:   # Run (toolbar 32966): wait()/physics checks need game time
            for h in wins(lambda h: cls(h).startswith('Afx:')):
                u.PostMessageW(h, 0x111, 32966, 0); ran = True
    if p.poll() is not None:
        return {'_exit': 'CRASH 0x%08X' % (p.returncode & 0xFFFFFFFF)}
    def text(t, it):
        k.WriteProcessMemory(hp, mem, struct.pack('<IIIIIIIIII', 1, it, 0, 0, mem + 512, 256, 0, 0, 0, 0), 40, None)
        snd(t, 0x110C, 0, mem, a=True)
        b = ctypes.create_string_buffer(256); k.ReadProcessMemory(hp, mem + 512, b, 256, None); return b.value.decode('latin-1')
    names = []; roots = []
    for top in wins(lambda h: cls(h).startswith('Afx:')):
        tv = []
        def cb(c, _):
            if cls(c) == 'SysTreeView32': tv.append(c)
            return True
        u.EnumChildWindows(top, P(cb), 0)
        for t in tv:
            it = snd(t, 0x110A, 0, 0)   # root
            while it:
                root = text(t, it); roots.append(root)
                if root == 'Workspace':
                    snd(t, 0x1102, 2, it); time.sleep(0.5)   # TVM_EXPAND
                    c = snd(t, 0x110A, 4, it)
                    while c:
                        names.append(text(t, c)); c = snd(t, 0x110A, 1, c)
                it = snd(t, 0x110A, 1, it)
    p.kill()
    res = {}
    for n in names:
        m = re.match(r'(R\d) pass=(\d+) fail=(.*)', n)
        if m:
            res[m.group(1)] = {'pass': int(m.group(2)), 'fail': [x for x in m.group(3).split(',') if x]}
    res['_workspace'] = len(names)
    res['_roots'] = roots
    return res


if __name__ == '__main__':
    lua = LUA.read_text()
    print('== original'); o = run(ORIG, lua); print(o)
    print('== ours'); q = run(EXE, lua); print(q)
    of = set(sum((v['fail'] for kk, v in o.items() if not kk.startswith('_')), []))
    qf = set(sum((v['fail'] for kk, v in q.items() if not kk.startswith('_')), []))
    bad = sorted(qf - of) + ['stage %s missing' % s_ for s_ in ('R1', 'R2') if s_ in o and s_ not in q]
    if q.get('_exit'):
        bad.append(q['_exit'])
    elif not q.get('_workspace'):
        bad.append('no Workspace results')
    json.dump({'orig': o, 'ours': q, 'bad': bad}, open(H / 'auto/scripttest.json', 'w'), indent=1)
    print('scripttest: orig %s | ours %s | broken in ours: %s' % ({kk: v for kk, v in o.items() if kk[0] == 'R'},
          {kk: v for kk, v in q.items() if kk[0] == 'R'}, bad or q.get('_exit')))
