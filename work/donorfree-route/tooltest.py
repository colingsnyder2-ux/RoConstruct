"""python tooltest.py [EXE] [--orig run/RobloxOrig.exe]: FEATURE_LADDER Tier 2 smoke test. File->New, insert a Part
(Insert Object 'Part' is not offered: the place's baseplate is used when there is none), then for each tool (Drag,
Resize, Move on axis, Rotate, Tilt, Anchor, Lock, surface tools, Paint): select it by WM_COMMAND, press-drag-release in the
3D view with window messages, and record alive/crash plus how much of the view changed (PrintWindow pixel diff, %).
The original runs the same sequence for comparison. Writes auto/tooltest.json."""
import ctypes, ctypes.wintypes as w, json, os, subprocess, sys, time
from pathlib import Path
import ieclean
H = Path(__file__).parent
u, g, k = ctypes.WinDLL('user32'), ctypes.WinDLL('gdi32'), ctypes.WinDLL('kernel32')
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
args = sys.argv[1:]
EXE = next((a for i, a in enumerate(args) if a.lower().endswith('.exe') and (i == 0 or args[i - 1] != '--orig')), str(H / 'run/RobloxQT.exe'))
PLACE = str(H / 'run/tooltest_place.rbxl')   # copy of run/default.rbxl (made in the original: one Part); saved over by the test   # made in the original: one Part on the default place
ORIG = args[args.index('--orig') + 1] if '--orig' in args else str(H / 'run/RobloxOrig.exe')
TOOLS = [('select-click', None), ('Drag', 32867), ('Resize', 32869), ('MoveAxis', 32871), ('Rotate', 32835), ('Tilt', 32836),
         ('Anchor', 32884), ('Lock', 32883), ('Glue', 32887), ('Weld', 32889), ('Hinge', 32892), ('Paint', 32832),
         ('MoveUp', 32855), ('MoveDown', 32856), ('Run', 32966), ('Reset', 32968)]


def cls(h):
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128); return c.value


def grab(h):
    r = w.RECT(); u.GetClientRect(h, ctypes.byref(r)); W, Hh = r.right, r.bottom
    if W <= 0 or Hh <= 0:
        return None
    dc = u.GetDC(h); mdc = g.CreateCompatibleDC(dc); bmp = g.CreateCompatibleBitmap(dc, W, Hh); g.SelectObject(mdc, bmp)
    u.PrintWindow(h, mdc, 1)
    buf = ctypes.create_string_buffer(W * Hh * 4)
    bi = (ctypes.c_uint32 * 10)(40, W, (-Hh) & 0xffffffff, 1 | (32 << 16), 0, 0, 0, 0, 0, 0)
    g.GetDIBits(mdc, bmp, 0, Hh, buf, bi, 0)
    g.DeleteObject(bmp); g.DeleteDC(mdc); u.ReleaseDC(h, dc)
    return W, Hh, buf.raw


def diff(a, b):
    if not a or not b or a[:2] != b[:2]:
        return None
    x, y = a[2], b[2]; n = len(x) // 4
    return round(100.0 * sum(1 for i in range(0, len(x), 64) if x[i:i + 3] != y[i:i + 3]) / max(1, n // 16), 1)


def part_state():
    import re
    t = open(PLACE, errors='replace').read()
    m = re.search(r'<Item class="Part".*?</Item>', t, re.S)
    if not m:
        return None
    b = m.group(0)
    v = lambda tag: re.findall(r'<%s>([^<]+)</%s>' % (tag, tag), b)
    return {'xyz': v('X')[:1] + v('Y')[:1] + v('Z')[:1], 'size': re.findall(r'name="size">\s*<X>([^<]+)</X>\s*<Y>([^<]+)</Y>\s*<Z>([^<]+)', b)}


def mk(x, y):
    return (y << 16) | (x & 0xffff)


def run(exe):
    ieclean.clean(); exe = os.path.abspath(exe)
    import shutil; shutil.copy(H / 'run/default.rbxl', PLACE); before = part_state()
    p = subprocess.Popen([exe, PLACE], cwd=os.path.dirname(exe)); res = {}
    def wins(pred):
        out = []
        def cb(h, _):
            q = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(q))
            if q.value == p.pid and u.IsWindowVisible(h) and pred(h): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out
    e = time.time() + 30; main = None
    while time.time() < e and not main and p.poll() is None:
        main = (wins(lambda h: cls(h).startswith('Afx:')) or [None])[0]; time.sleep(0.3)
    if not main:
        p.kill(); return {'_error': 'no window'}
    time.sleep(8)
    views = []
    def cb(c, _):
        r = w.RECT(); u.GetClientRect(c, ctypes.byref(r))
        if u.IsWindowVisible(c) and r.right * r.bottom > 200 * 150 and cls(c).startswith('Afx:'): views.append((r.right * r.bottom, c))
        return True
    u.EnumChildWindows(main, P(cb), 0)
    if not views:
        p.kill(); return {'_error': 'no 3D view'}
    view = max(views)[1]
    r = w.RECT(); u.GetClientRect(view, ctypes.byref(r)); cx, cy = r.right // 2, int(r.bottom * 0.62)
    for name, cmd in TOOLS:
        if p.poll() is not None:
            res[name] = 'SKIP'; continue
        if cmd:
            u.PostMessageW(main, 0x111, cmd, 0); time.sleep(0.6)
        a = grab(view)
        u.PostMessageW(view, 0x200, 0, mk(cx, cy)); time.sleep(0.2)
        u.PostMessageW(view, 0x201, 1, mk(cx, cy)); time.sleep(0.3)
        for s in range(1, 9):
            u.PostMessageW(view, 0x200, 1, mk(cx + 12 * s, cy - 6 * s)); time.sleep(0.08)
        u.PostMessageW(view, 0x202, 0, mk(cx + 96, cy - 48)); time.sleep(1.2)
        if p.poll() is not None:
            res[name] = 'CRASH 0x%08X' % (p.returncode & 0xFFFFFFFF); continue
        res[name] = 'alive, view changed %s%%' % diff(a, grab(view))
        print('  %-12s %s' % (name, res[name]), flush=True)
    if p.poll() is None:
        u.PostMessageW(main, 0x111, 0xE103, 0); time.sleep(4)   # File->Save over the copy: the Part's state after the tools
        res['_part_before'], res['_part_after'] = before, part_state()
        p.kill()
    return res


if __name__ == '__main__':
    print('== original'); o = run(ORIG)
    print('== ours'); q = run(EXE)
    bad = {t: (q.get(t), o.get(t)) for t, _ in TOOLS if not str(q.get(t, '')).startswith('alive')}
    json.dump({'orig': o, 'ours': q, 'bad': bad}, open(H / 'auto/tooltest.json', 'w'), indent=1)
    print('tooltest: ours alive after %d/%d tools; crashes/skips: %s' % (sum(1 for v in q.values() if str(v).startswith('alive')), len(TOOLS), bad))
