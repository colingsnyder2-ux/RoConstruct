"""python fastcensus.py [EXE] [--ids auto/crashcont_ids.json] [--cap 3]: fast command census. One client runs the
commands back to back (PostMessage WM_COMMAND, then a SENT WM_NULL returns as soon as the command finished; a modal
dialog hits the cap and is closed). When the client dies or its window goes away, the command just posted is
recorded as the killer, the client is relaunched (File->New again) and the run continues with the next command.
No crash rewinding: every CRASH is real. Writes auto/fastcensus.json {killers:[{id,label,exit}], tested, secs}."""
import ctypes, ctypes.wintypes as w, json, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
ids = json.load(open(args[args.index('--ids') + 1] if '--ids' in args else H / 'auto/crashcont_ids.json'))
ids = [(r['id'], r.get('label', '')) if isinstance(r, dict) else (r, '') for r in ids]
cap = float(args[args.index('--cap') + 1]) if '--cap' in args else 3.0
u = ctypes.WinDLL('user32'); k = ctypes.WinDLL('kernel32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def wins(pid, cls_prefix):
    out = []
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith(cls_prefix):
            out.append(h)
        return True
    u.EnumWindows(P(cb), 0)
    return out


def launch():
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
    t = time.time()
    while not wins(p.pid, 'Afx:') and time.time() - t < 30 and p.poll() is None:
        time.sleep(0.3)
    time.sleep(1.5)
    h = wins(p.pid, 'Afx:')
    if not h:
        return p, None
    u.PostMessageW(h[0], 0x111, 0xE100, 0)   # File->New
    r = w.DWORD(); u.SendMessageTimeoutW(h[0], 0, 0, 0, 2, 15000, ctypes.byref(r)); time.sleep(1.5)
    return p, (wins(p.pid, 'Afx:') or [None])[0]


import ieclean
t0 = time.time(); ieclean.clean()
killers, tested, relaunch = [], 0, 0
p, h = launch()
i = 0
while i < len(ids):
    if h is None or p.poll() is not None:
        killers.append({'id': '%#x' % ids[i][0], 'label': 'File->New / startup before ' + ids[i][1], 'exit': '%#x' % ((p.returncode or 0) & 0xffffffff)})
        break
    cid, lab = ids[i]
    u.PostMessageW(h, 0x111, cid, 0)
    r = w.DWORD()
    ok = u.SendMessageTimeoutW(h, 0, 0, 0, 2, int(cap * 1000), ctypes.byref(r))
    for d in wins(p.pid, '#32770'):
        u.PostMessageW(d, 0x0010, 0, 0)
    tested += 1
    time.sleep(0.05)
    if p.poll() is not None or not wins(p.pid, 'Afx:'):
        time.sleep(0.5)
        code = p.poll()
        killers.append({'id': '%#x' % cid, 'label': lab, 'exit': ('%#x' % (code & 0xffffffff)) if code is not None else 'window closed'})
        try:
            p.kill()
        except Exception:
            pass
        relaunch += 1
        p, h = launch()
    i += 1
try:
    p.kill()
except Exception:
    pass
ieclean.clean(t0)
(H / 'auto/fastcensus.json').write_text(json.dumps({'tested': tested, 'secs': round(time.time() - t0), 'relaunches': relaunch, 'killers': killers}, indent=0))
print('fastcensus: %d commands in %.0fs, %d relaunches, killers %d' % (tested, time.time() - t0, relaunch, len(killers)))
for kk in killers:
    print('  %-7s %-50s %s' % (kk['id'], kk['label'][:50], kk['exit']))
