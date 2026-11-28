"""python startcheck.py [EXE] [secs]: fast standalone health check, no debugger (~15 s): start the client, post File->New
when its window shows, and report OK (window up, no crash dialog), CRASH-DIALOG (the client's own 'ROBLOX Crash'),
EXITED, or NO-WINDOW. Use the debugger probe (probe.py / multiprobe.py) only when this says something is wrong."""
import ctypes, ctypes.wintypes as w, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 and sys.argv[1].lower().endswith('.exe') else str(H / 'run/RobloxQT.exe')
secs = float(sys.argv[-1]) if len(sys.argv) > 1 and sys.argv[-1].replace('.', '').isdigit() else 15
u = ctypes.WinDLL('user32')
p = subprocess.Popen([exe], cwd=os.path.dirname(os.path.abspath(exe)))


def wins():
    out = []
    CB = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)

    def cb(h, l):
        pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid))
        if pid.value == p.pid and u.IsWindowVisible(h):
            t = ctypes.create_unicode_buffer(256); u.GetWindowTextW(h, t, 256)
            out.append((h, t.value))
        return True
    u.EnumWindows(CB(cb), 0)
    return out


t0, posted, verdict = time.time(), False, None
while time.time() - t0 < secs:
    time.sleep(0.5)
    if p.poll() is not None:
        verdict = 'EXITED (code %s) after %.1fs' % (p.returncode, time.time() - t0); break
    ws = wins()
    if any('ROBLOX Crash' in t for _, t in ws):
        verdict = 'CRASH-DIALOG after %.1fs' % (time.time() - t0); break
    _cls = lambda h_: (lambda b_: (u.GetClassNameW(h_, b_, 64), b_.value)[1])(ctypes.create_unicode_buffer(64))
    main = [h for h, t in ws if t.startswith('Roblox') and _cls(h) != '#32770']   # the frame, never a message box
    if main and not posted:
        u.PostMessageW(main[0], 0x111, 0xE100, 0); posted = time.time()
if verdict is None:
    ws = wins()
    # message boxes (dialog class #32770) are failures too: 'Failed to create empty document.' looked like OK
    msgs = []
    for h_, t_ in ws:
        cn = ctypes.create_unicode_buffer(64); u.GetClassNameW(h_, cn, 64)
        if cn.value == '#32770':
            txt = []
            CB2 = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
            def cb2(c, l):
                b = ctypes.create_unicode_buffer(512); u.GetWindowTextW(c, b, 512)
                if b.value.strip() and b.value not in ('OK', 'Cancel', '&Yes', '&No'):
                    txt.append(b.value.strip())
                return True
            u.EnumChildWindows(h_, CB2(cb2), 0)
            msgs.append(' / '.join(txt) or t_)
    if msgs:
        verdict = 'DIALOG: %s (File->New sent %.1fs in)' % (' | '.join(msgs)[:200], (posted - t0) if posted else -1)
    else:
        verdict = ('OK: window %r up, File->New sent %.1fs in, no crash' % (next((t for _, t in ws if t.startswith('Roblox')), '?'), posted - t0)
                   if posted else 'NO-WINDOW after %.0fs' % secs)
print(verdict)
p.kill()
