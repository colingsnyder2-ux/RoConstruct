"""python featladder.py [EXE] [--orig run/RobloxOrig.exe] [--json out.json]
Feature-ladder scoreboard: drives each exe through startup/File->New/idle CPU/Explorer/Insert Object/Run/Reset
via WM_COMMAND and prints step | ours | orig | ok. JSON -> auto/featladder.json. Run from work/donorfree-route."""
import ctypes, ctypes.wintypes as w, json, os, re, struct, subprocess, sys, time
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent)); import ieclean
H = Path(__file__).parent
k = ctypes.WinDLL('kernel32'); u = ctypes.WinDLL('user32'); k.VirtualAllocEx.restype = ctypes.c_void_p
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
class FT(ctypes.Structure): _fields_ = [('lo', w.DWORD), ('hi', w.DWORD)]
STEPS = ['startup', 'file_new', 'cpu_idle', 'explorer_roots', 'insert_dialog', 'insert_items', 'run', 'game_time', 'reset']

def cls(h):
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128); return c.value
def title(h):
    t = ctypes.create_unicode_buffer(256); u.GetWindowTextW(h, t, 256); return t.value
def snd(h, m, wp=0, lp=0, a=False):
    """SendMessageTimeout (2 s, abort-if-hung); returns int or None on hang."""
    r = ctypes.c_size_t(0)
    f = u.SendMessageTimeoutA if a else u.SendMessageTimeoutW
    ok = f(h, m, ctypes.c_size_t(wp), ctypes.c_ssize_t(lp), 2, 2000, ctypes.byref(r))
    return r.value if ok else None
def kids(h, want):
    out = []
    def cb(c, _):
        if cls(c) == want: out.append(c)
        return True
    u.EnumChildWindows(h, P(cb), 0); return out
def cpu(h):
    a, b, c, d = FT(), FT(), FT(), FT(); k.GetProcessTimes(h, *[ctypes.byref(x) for x in (a, b, c, d)])
    return ((c.hi << 32 | c.lo) + (d.hi << 32 | d.lo)) / 1e7

def run(exe):
    R, ids = {}, {}
    exe = os.path.abspath(exe); t0 = time.time(); ieclean.clean()
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe)); pid = p.pid
    hp = k.OpenProcess(0x1F0FFF, False, pid); mem = k.VirtualAllocEx(hp, None, 4096, 0x3000, 4)
    def rd(n=256):
        b = ctypes.create_string_buffer(n); k.ReadProcessMemory(hp, ctypes.c_void_p(mem + 512), b, n, None); return b.value.decode('latin-1')
    def wr(data): k.WriteProcessMemory(hp, ctypes.c_void_p(mem), data, len(data), None)
    def wins(pred):
        out = []
        def cb(h, _):
            q = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(q))
            if q.value == pid and u.IsWindowVisible(h) and pred(h): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out
    def waitwin(pred, t):
        e = time.time() + t
        while time.time() < e and p.poll() is None:
            r = wins(pred)
            if r: return r[0]
            time.sleep(0.25)
    def sbtext(top):
        sb = kids(top, 'msctls_statusbar32')
        for s in sb:
            n = snd(s, 0x406, 0, 0) or 1
            for i in range(min(n, 8)):
                wr(b'\0' * 256); snd(s, 0x402, i, mem + 512, a=True)
                m = re.search(r't\s*(\d+(?:\.\d+)?)', rd())
                if m: return float(m.group(1))
    main = None
    def step(name, fn):
        nonlocal main
        if p.poll() is not None:
            R[name] = 'SKIP'; return
        try: R[name] = fn()
        except Exception as ex: R[name] = 'ERR %s' % ex
        if R[name] is None: R[name] = 'HUNG'
        if p.poll() is not None and '_crash' not in R:
            R['_crash'] = 'CRASH 0x%08X' % (p.returncode & 0xFFFFFFFF); R[name] = R['_crash']
    def alive(t):
        time.sleep(t); return 'alive' if p.poll() is None else 'dead'
    def s_start():
        nonlocal main
        main = waitwin(lambda h: cls(h).startswith('Afx:'), 8)
        return ('ok %.1fs' % (time.time() - t0)) if main else 'no window'
    def s_new():
        u.PostMessageW(main, 0x111, 0xE100, 0); r = alive(5)
        return '%s "%s"' % (r, title(main))
    def s_cpu():
        h = k.OpenProcess(0x1000, False, pid); c0 = cpu(h); time.sleep(4); return '%d%%' % round((cpu(h) - c0) / 4 * 100)
    def s_tree():
        names = []
        for t in kids(main, 'SysTreeView32'):
            it = snd(t, 0x110A, 0, 0)
            while it:
                wr(struct.pack('<IIIIIIIIII', 1, it, 0, 0, mem + 512, 256, 0, 0, 0, 0)); snd(t, 0x110C, 0, mem, a=True)
                names.append(rd()); it = snd(t, 0x110A, 1, it)
        return names
    def s_dlg():
        u.PostMessageW(main, 0x111, 0x807f, 0)
        d = waitwin(lambda h: cls(h) == '#32770' and title(h) == 'Insert Object', 4)
        ids['dlg'] = d; return 'visible' if d else 'missing'
    def s_items():
        d = ids.get('dlg'); items = []
        if not d: return 'n/a'
        for lv in kids(d, 'SysListView32'):
            for i in range(snd(lv, 0x1004, 0, 0) or 0):
                wr(struct.pack('<IiiIIIiiiI', 1, i, 0, 0, 0, mem + 512, 256, 0, 0, 0)); snd(lv, 0x102D, i, mem, a=True); items.append(rd())
        u.PostMessageW(d, 0x111, 2, 0); u.PostMessageW(d, 0x10, 0, 0); time.sleep(1)
        return items
    def s_run():
        u.PostMessageW(main, 0x111, 0x80c6, 0)
        time.sleep(2); ids['t0'] = sbtext(main); r = alive(3); ids['t1'] = sbtext(main); return r
    def s_gt():
        a, b = ids.get('t0'), ids.get('t1')
        if a is None and b is None: return 'n/a'
        return 'advanced' if (b or 0) > (a or 0) else 'stuck %s' % b
    def s_reset():
        u.PostMessageW(main, 0x111, 0x80c8, 0); return alive(5)
    for n, f in zip(STEPS, [s_start, s_new, s_cpu, s_tree, s_dlg, s_items, s_run, s_gt, s_reset]):
        if n == 'startup': R[n] = f() if True else 0;
        else: step(n, f)
        if n == 'startup' and not main:
            for m in STEPS[1:]: R[m] = 'SKIP'
            break
    if p.poll() is None: p.kill()
    else: R.setdefault('_crash', 'CRASH 0x%08X' % (p.returncode & 0xFFFFFFFF))
    ieclean.clean(t0)
    return R

def fmt(v): return ', '.join(v) if isinstance(v, list) else str(v)
def same(s, a, b):
    if isinstance(a, list) and isinstance(b, list):
        ms, ex = sorted(set(b) - set(a)), sorted(set(a) - set(b))
        return 'ok' if not ms and not ex else 'missing=%s extra=%s' % (ms, ex)
    if s == 'cpu_idle':
        try: return 'ok' if abs(int(a.rstrip('%')) - int(b.rstrip('%'))) < 25 else 'DIFF'
        except Exception: pass
    if s in ('startup',): return 'ok' if str(a).startswith('ok') == str(b).startswith('ok') else 'DIFF'
    return 'ok' if a == b else 'DIFF'

if __name__ == '__main__':
    A = sys.argv[1:]
    orig, js = 'run/RobloxOrig.exe', str(H / 'auto/featladder.json')
    if '--orig' in A: i = A.index('--orig'); orig = A[i + 1]; del A[i:i + 2]
    if '--json' in A: i = A.index('--json'); js = A[i + 1]; del A[i:i + 2]
    ours_exe = A[0] if A else 'run/RobloxQT.exe'
    ours = run(ours_exe)
    _rc = H / 'auto/featladder_orig_cache.json'   # the original never changes: reuse its run (cpu_idle/timing rows aside)
    try:
        _c = json.load(open(_rc))
        ref = _c['ref'] if _c.get('mtime') == os.path.getmtime(orig) and '--fresh-orig' not in A else None
    except (OSError, ValueError, KeyError):
        ref = None
    if ref is None:
        ref = run(orig)
        if ref.get('file_new', '').startswith('alive'):
            json.dump({'mtime': os.path.getmtime(orig), 'ref': ref}, open(_rc, 'w'))
    rows = [(s, ours.get(s, '-'), ref.get(s, '-')) for s in STEPS]
    print('%-16s | %-34s | %-34s | ok' % ('step', 'ours', 'orig'))
    out = []
    for s, a, b in rows:
        o = same(s, a, b); out.append({'step': s, 'ours': a, 'orig': b, 'ok': o})
        print('%-16s | %-34s | %-34s | %s' % (s, fmt(a)[:34], fmt(b)[:34], o))
    print('score: %d/%d' % (sum(r['ok'] == 'ok' for r in out), len(out)))
    os.makedirs(os.path.dirname(js), exist_ok=True)
    json.dump({'ours_exe': ours_exe, 'orig_exe': orig, 'rows': out}, open(js, 'w'), indent=1)
