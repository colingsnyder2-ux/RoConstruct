"""python insertsweep.py [EXE] [--orig run/RobloxOrig.exe] [--only A,B]: FEATURE_LADDER Tier 1.2. Inserts every Insert
Object class one at a time through the real dialog (File->New, Insert->Object, select the item, OK) and records per class:
ok / CRASH <exit> / HUNG / no-dialog / missing. After a crash the client is relaunched and the sweep continues with the
next class. The same sweep runs on the original for comparison. Writes auto/insertsweep.json."""
import ctypes, ctypes.wintypes as w, json, os, struct, subprocess, sys, time
from pathlib import Path
import ieclean
H = Path(__file__).parent
u, k = ctypes.WinDLL('user32'), ctypes.WinDLL('kernel32')
k.VirtualAllocEx.restype = ctypes.c_void_p
k.VirtualAllocEx.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_size_t, w.DWORD, w.DWORD]
k.WriteProcessMemory.argtypes = k.ReadProcessMemory.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p]
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
args = sys.argv[1:]
EXE = next((a for a in args if a.lower().endswith('.exe') and args[max(0, args.index(a) - 1)] != '--orig'), str(H / 'run/RobloxQT.exe'))
ORIG = args[args.index('--orig') + 1] if '--orig' in args else str(H / 'run/RobloxOrig.exe')
ONLY = set(args[args.index('--only') + 1].split(',')) if '--only' in args else None


def cls(h):
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128); return c.value


def title(h):
    t = ctypes.create_unicode_buffer(256); u.GetWindowTextW(h, t, 256); return t.value


def snd(h, m, wp=0, lp=0, a=False):
    r = ctypes.c_size_t(0)
    f = u.SendMessageTimeoutA if a else u.SendMessageTimeoutW
    return r.value if f(h, m, ctypes.c_size_t(wp), ctypes.c_ssize_t(lp), 2, 3000, ctypes.byref(r)) else None


def kids(h, want):
    out = []
    def cb(c, _):
        if cls(c) == want: out.append(c)
        return True
    u.EnumChildWindows(h, P(cb), 0); return out


class Client:
    def __init__(self, exe):
        ieclean.clean()
        exe = os.path.abspath(exe); self.p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
        self.hp = k.OpenProcess(0x1F0FFF, False, self.p.pid)
        self.mem = k.VirtualAllocEx(self.hp, None, 4096, 0x3000, 4)
        self.main = self.wait(lambda h: cls(h).startswith('Afx:'), 30)
        if self.main:
            u.PostMessageW(self.main, 0x111, 0xE100, 0); time.sleep(5)

    def alive(self):
        return self.p.poll() is None

    def wins(self, pred):
        out = []
        def cb(h, _):
            q = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(q))
            if q.value == self.p.pid and u.IsWindowVisible(h) and pred(h): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out

    def wait(self, pred, t):
        e = time.time() + t
        while time.time() < e and self.alive():
            r = self.wins(pred)
            if r: return r[0]
            time.sleep(0.25)

    def rd(self, n=256):
        b = ctypes.create_string_buffer(n); k.ReadProcessMemory(self.hp, self.mem + 512, b, n, None); return b.value.decode('latin-1')

    def wr(self, data):
        k.WriteProcessMemory(self.hp, self.mem, data, len(data), None)

    def dialog(self):
        u.PostMessageW(self.main, 0x111, 0x807f, 0)
        return self.wait(lambda h: cls(h) == '#32770' and title(h) == 'Insert Object', 6)

    def items(self, d):
        lv = (kids(d, 'SysListView32') or [None])[0]
        out = []
        for i in range(snd(lv, 0x1004) or 0):
            self.wr(struct.pack('<IiiIIIiiiI', 1, i, 0, 0, 0, self.mem + 512, 256, 0, 0, 0)); snd(lv, 0x102D, i, self.mem, a=True)
            out.append(self.rd())
        return lv, out

    def insert(self, name):
        d = self.dialog()
        if not d:
            return 'no-dialog' if self.alive() else 'CRASH 0x%08X' % (self.p.returncode & 0xFFFFFFFF)
        lv, names = self.items(d)
        if name not in names:
            u.PostMessageW(d, 0x111, 2, 0); time.sleep(0.5); return 'missing'
        i = names.index(name)
        self.wr(struct.pack('<IiiIIIiiiI', 0x8, i, 0, 3, 3, 0, 0, 0, 0, 0)); snd(lv, 0x102B, i, self.mem)   # LVM_SETITEMSTATE selected|focused
        u.PostMessageW(d, 0x111, 1, 0)                                                                     # IDOK
        e = time.time() + 6
        while time.time() < e and self.alive() and u.IsWindow(d):
            time.sleep(0.2)
        time.sleep(1.5)
        if not self.alive():
            return 'CRASH 0x%08X' % (self.p.returncode & 0xFFFFFFFF)
        if u.IsWindow(d):
            u.PostMessageW(d, 0x111, 2, 0); time.sleep(0.5); return 'HUNG-dialog'
        return 'ok' if snd(self.main, 0) is not None else 'HUNG'

    def close(self):
        try:
            self.p.kill()
        except OSError:
            pass


def sweep(exe, names=None):
    c = Client(exe); res = {}
    if names is None:
        d = c.dialog()
        if not d:
            c.close(); return {'_error': 'no dialog'}
        names = c.items(d)[1]; u.PostMessageW(d, 0x111, 2, 0); time.sleep(1)
    for n in names:
        if ONLY and n not in ONLY:
            continue
        if not c.alive():
            c.close(); c = Client(exe)
        res[n] = c.insert(n)
        print('  %-24s %s' % (n, res[n]), flush=True)
    c.close()
    return res


if __name__ == '__main__':
    print('== original'); o = sweep(ORIG)
    print('== ours'); q = sweep(EXE, [n for n in o if not n.startswith('_')])
    bad = {n: q.get(n) for n in o if not n.startswith('_') and o[n] == 'ok' and q.get(n) != 'ok'}
    json.dump({'orig': o, 'ours': q, 'bad': bad}, open(H / 'auto/insertsweep.json', 'w'), indent=1)
    print('insertsweep: %d classes, ours ok %d, orig ok %d; broken in ours: %s'
          % (len(o), sum(1 for v in q.values() if v == 'ok'), sum(1 for v in o.values() if v == 'ok'), bad))
