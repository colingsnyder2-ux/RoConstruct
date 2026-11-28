"""python spinsample.py [EXE] [warmup] [samples]: find where a hung-but-alive client spins. Starts the exe normally,
waits, then repeatedly suspends each thread, reads its EIP (Wow64GetThreadContext) and resumes. Prints the hottest
addresses per thread mapped to linkexp/qt.map symbols, plus a short stack scan (return addresses into the exe) of the
hottest thread. No debugger attached, so the run behaves like a real launch."""
import bisect, collections, ctypes, ctypes.wintypes as w, os, struct, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
nums = [a for a in args if a.isdigit()]
warm, nsamp = (int(nums[0]) if nums else 15), (int(nums[1]) if len(nums) > 1 else 60)
mp = str(H / ('linkexp/qt.map' if os.path.basename(exe) == 'RobloxQT.exe' else 'linkexp/qt%s.map' % os.path.basename(exe)[8:-4]))
syms = {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            syms.setdefault(int(p[2], 16), p[1])
        except ValueError:
            pass
ks = sorted(syms)
near = lambda v: (lambda j: '%s+%x' % (syms[ks[j]][:80], v - ks[j]) if j >= 0 and v - ks[j] < 0x10000 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
k = ctypes.WinDLL('kernel32')


class CTX(ctypes.Structure):   # WOW64_CONTEXT (x86)
    _fields_ = [('Flags', w.DWORD), ('Dr', w.DWORD * 6), ('Float', ctypes.c_byte * 112), ('Gs', w.DWORD), ('Fs', w.DWORD),
                ('Es', w.DWORD), ('Ds', w.DWORD), ('Edi', w.DWORD), ('Esi', w.DWORD), ('Ebx', w.DWORD), ('Edx', w.DWORD),
                ('Ecx', w.DWORD), ('Eax', w.DWORD), ('Ebp', w.DWORD), ('Eip', w.DWORD), ('Cs', w.DWORD), ('EFlags', w.DWORD),
                ('Esp', w.DWORD), ('Ss', w.DWORD), ('Ext', ctypes.c_byte * 512)]


_T0 = time.time(); import ieclean as _iec; _iec.clean()   # baseline: the user's own Edge windows
p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
if os.environ.get('SPIN_POST'):   # e.g. 0xE100: post File->New to the main frame first, then sample
    time.sleep(5)
    _u = ctypes.WinDLL('user32'); _P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM); _fr = []
    def _cb(hh, _):
        pid_ = w.DWORD(); _u.GetWindowThreadProcessId(hh, ctypes.byref(pid_)); c_ = ctypes.create_unicode_buffer(64); _u.GetClassNameW(hh, c_, 64)
        if pid_.value == p.pid and _u.IsWindowVisible(hh) and c_.value.startswith('Afx:'):
            _fr.append(hh)
        return True
    _u.EnumWindows(_P(_cb), 0)
    for _i, _c in enumerate(os.environ['SPIN_POST'].split(',')):   # several commands, 4 s apart
        if _i:
            time.sleep(4)
        for _h in _fr[:1]:
            _u.PostMessageW(_h, 0x111, int(_c, 0), 0)
time.sleep(warm)
hp = k.OpenProcess(0x1F0FFF, False, p.pid)


def threads():
    snap = k.CreateToolhelp32Snapshot(4, 0)
    class TE(ctypes.Structure):
        _fields_ = [('size', w.DWORD), ('u', w.DWORD), ('tid', w.DWORD), ('pid', w.DWORD), ('b', w.LONG), ('d', w.LONG), ('f', w.DWORD)]
    te = TE(); te.size = ctypes.sizeof(TE); out = []
    ok = k.Thread32First(snap, ctypes.byref(te))
    while ok:
        if te.pid == p.pid:
            out.append(te.tid)
        ok = k.Thread32Next(snap, ctypes.byref(te))
    k.CloseHandle(snap)
    return out


hits = collections.defaultdict(collections.Counter)
last_ctx = {}
for _ in range(nsamp):
    for tid in threads():
        ht = k.OpenThread(0x1FFFFF, False, tid)
        if not ht:
            continue
        k.SuspendThread(ht)
        c = CTX(); c.Flags = 0x10007
        if k.Wow64GetThreadContext(ht, ctypes.byref(c)):
            hits[tid][c.Eip] += 1
            last_ctx[tid] = (c.Eip, c.Esp)
        k.ResumeThread(ht); k.CloseHandle(ht)
    time.sleep(0.05)
hot = max(hits, key=lambda t: len(hits[t]))   # the thread whose EIP moves most (the spinning one)
for tid, cnt in sorted(hits.items(), key=lambda kv: -max(kv[1].values())):
    top = cnt.most_common(3)
    def _mod(v):
        if 0x400000 <= v < 0x3000000:
            return near(v)
        nm_ = ctypes.create_unicode_buffer(260)
        ok_ = ctypes.WinDLL('psapi').GetMappedFileNameW(hp, ctypes.c_void_p(v), nm_, 260)
        return '%08x %s' % (v, nm_.value.rsplit(chr(92), 1)[-1] if ok_ else '?')
    print('thread %5d: %s' % (tid, ' | '.join('%s x%d' % (_mod(e), n) for e, n in top)))
if os.environ.get('SPIN_ALL'):   # exe frames of EVERY thread (who holds the lock the UI waits for)
    for tid_, (e_, sp_) in last_ctx.items():
        b_ = (ctypes.c_uint32 * 1024)(); n2 = ctypes.c_size_t()
        k.ReadProcessMemory(hp, ctypes.c_void_p(sp_), b_, 4096, ctypes.byref(n2))
        fr = [near(v)[:70] for v in b_ if 0x401000 <= v < 0x900000][:8]
        if fr:
            print('T%d:' % tid_, ' <- '.join(fr))
eip, esp = last_ctx[hot]
buf = (ctypes.c_uint32 * 256)(); n_ = ctypes.c_size_t()
k.ReadProcessMemory(hp, ctypes.c_void_p(esp), buf, 1024, ctypes.byref(n_))
base = 0x400000
print('hottest thread %d stack (return addresses into the exe):' % hot)
shown = 0
for v in buf:
    if base + 0x1000 <= v < 0x900000 and shown < 14:
        print('   ' + near(v)); shown += 1
p.kill()
import ieclean as _iec; _iec.clean(_T0)   # the client's IE pages open as Edge windows on Windows 11
