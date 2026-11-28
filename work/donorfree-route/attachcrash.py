"""python attachcrash.py [EXE] [delay] [secs]: launch the client NORMALLY (no debugger at creation: no debug heap, no
IsDebuggerPresent at startup), attach with DebugActiveProcess after `delay` s, and report the first access violation
(eip, registers, symbolised return addresses on the stack). The debugger-created probe never crashed where the real
launch did (exit 0xC0000005 before the main window)."""
import re, bisect, ctypes, ctypes.wintypes as w, os, struct, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
a = sys.argv[1:]
exe = os.path.abspath(next((x for x in a if x.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
nums = [float(x) for x in a if x.replace('.', '', 1).isdigit()]
delay, secs = (nums + [0.4, 40][len(nums):])[:2]
syms = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            syms.setdefault(v, p[1])
ks = sorted(syms)
near = lambda v: (lambda j: '%s+%x' % (syms[ks[j]][:90], v - ks[j]) if j >= 0 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
k = ctypes.WinDLL('kernel32', use_last_error=True)


class CTX(ctypes.Structure):   # WOW64_CONTEXT
    _fields_ = [('Flags', w.DWORD), ('Dr', w.DWORD * 6), ('Float', ctypes.c_byte * 112), ('Gs', w.DWORD), ('Fs', w.DWORD),
                ('Es', w.DWORD), ('Ds', w.DWORD), ('Edi', w.DWORD), ('Esi', w.DWORD), ('Ebx', w.DWORD), ('Edx', w.DWORD),
                ('Ecx', w.DWORD), ('Eax', w.DWORD), ('Ebp', w.DWORD), ('Eip', w.DWORD), ('Cs', w.DWORD), ('EFlags', w.DWORD),
                ('Esp', w.DWORD), ('Ss', w.DWORD), ('Ext', ctypes.c_byte * 512)]


class EV(ctypes.Structure):
    _fields_ = [('code', w.DWORD), ('pid', w.DWORD), ('tid', w.DWORD), ('pad', w.DWORD), ('u', ctypes.c_byte * 160)]   # 64-bit DEBUG_EVENT


_T0 = time.time(); import ieclean as _iec; _iec.clean()   # baseline: the user's own Edge windows
p = subprocess.Popen([exe] + ([os.environ['ATTACH_ARGS_FILE'] and '-script', open(os.environ['ATTACH_ARGS_FILE']).read()] if os.environ.get('ATTACH_ARGS_FILE') else []), cwd=os.path.dirname(exe), creationflags=2 if os.environ.get('ATTACH_CREATE') else 0)   # ATTACH_ARGS_FILE: Lua for -script; ATTACH_CREATE=1: start under the debugger (crashes before an attach can land)
time.sleep(0 if os.environ.get('ATTACH_CREATE') else delay)
if not os.environ.get('ATTACH_CREATE') and not k.DebugActiveProcess(p.pid):
    print('attach failed', ctypes.get_last_error(), 'exit', p.poll()); sys.exit(1)
k.DebugSetProcessKillOnExit(True)
hp = k.OpenProcess(0x1F0FFF, False, p.pid)
print('attached after %.1fs' % delay, flush=True)
def _rd(a_, n_=4):
    b_ = (ctypes.c_char * n_)(); k.ReadProcessMemory(hp, ctypes.c_void_p(a_), b_, n_, ctypes.byref(ctypes.c_size_t())); return b_.raw


def _is_ret(v):   # a real return address: the bytes before it are a call (E8 rel32 / FF 15 [m32] / FF /2 reg+disp)
    b_ = _rd(v - 7, 7)
    return len(b_) == 7 and (b_[2] == 0xE8 or (b_[1] == 0xFF and b_[2] == 0x15) or (b_[5] == 0xFF and 0xD0 <= b_[6] <= 0xD7)
                             or (b_[4] == 0xFF and (b_[5] & 0x38) == 0x10) or (b_[3] == 0xFF and (b_[4] & 0x38) == 0x10) or (b_[1] == 0xFF and (b_[2] & 0x38) == 0x10))

def _exp(dll, name):
    import pefile as _pf
    ps = ctypes.WinDLL('psapi'); mods = (ctypes.c_void_p * 512)(); need = w.DWORD()
    ps.EnumProcessModulesEx(hp, mods, ctypes.sizeof(mods), ctypes.byref(need), 1)   # LIST_MODULES_32BIT
    for m_ in mods[:need.value // ctypes.sizeof(ctypes.c_void_p)]:
        nb = ctypes.create_unicode_buffer(260); ps.GetModuleBaseNameW(hp, ctypes.c_void_p(m_), nb, 260)
        if nb.value.lower() == dll.lower():
            _path = ctypes.create_unicode_buffer(520); ps.GetModuleFileNameExW(hp, ctypes.c_void_p(m_), _path, 520)
            pe_ = _pf.PE(_path.value, fast_load=True)
            pe_.parse_data_directories(directories=[_pf.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
            for e_ in pe_.DIRECTORY_ENTRY_EXPORT.symbols:
                if (e_.name and e_.name.decode() == name) or (name.startswith('#') and e_.ordinal == int(name[1:])):
                    return m_ + e_.address
    return None


def _arm_watch(tid_):   # ATTACH_WATCH=ADDR: hardware write watchpoint (4 bytes) on this thread
    h_ = k.OpenThread(0x1FFFFF, False, tid_); c_ = CTX(); c_.Flags = 0x10010
    k.SuspendThread(h_); k.Wow64GetThreadContext(h_, ctypes.byref(c_))
    c_.Dr[0] = int(os.environ['ATTACH_WATCH'], 16); c_.Dr[5] = (c_.Dr[5] & ~0xf00ff) | 0x000D0001; c_.Flags = 0x10010
    k.Wow64SetThreadContext(h_, ctypes.byref(c_)); k.ResumeThread(h_); k.CloseHandle(h_)


def _all_tids():
    class TE(ctypes.Structure):
        _fields_ = [('size', w.DWORD), ('u', w.DWORD), ('tid', w.DWORD), ('pid', w.DWORD), ('b', w.LONG), ('d', w.LONG), ('f', w.DWORD)]
    sn = k.CreateToolhelp32Snapshot(4, 0); te = TE(); te.size = ctypes.sizeof(TE); out = []
    ok = k.Thread32First(sn, ctypes.byref(te))
    while ok:
        if te.pid == p.pid:
            out.append(te.tid)
        ok = k.Thread32Next(sn, ctypes.byref(te))
    k.CloseHandle(sn); return out


ev = EV(); t0 = time.time(); seen_bp = False
_bps, _cnt, _rearm, _orig_byte, _msgs = {}, {}, {}, {}, {}
POST = os.environ.get('ATTACH_POST')   # e.g. 0xE100: WM_COMMAND to the main frame once it is visible (File->New)
posted = False
_queue = POST.split(',') if POST else []
_next_t, _cur = 4, None
u32 = ctypes.WinDLL('user32')


def _post():
    P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM); found = []
    def cb(h, _):
        pid = w.DWORD(); u32.GetWindowThreadProcessId(h, ctypes.byref(pid))
        if pid.value == p.pid and u32.IsWindowVisible(h):
            c_ = ctypes.create_unicode_buffer(64); u32.GetClassNameW(h, c_, 64)
            if c_.value == ('#32770' if _cur in ('close', 'items') else c_.value) and (_cur in ('close', 'items') or c_.value.startswith('Afx:')):
                found.append(h)
        return True
    u32.EnumWindows(P(cb), 0)
    for h in found:   # ATTACH_POST token `close`: IDCANCEL + WM_CLOSE to the open dialogs (featladder's insert_items exit)
        if _cur == 'items':   # featladder's insert_items read: LVM_GETITEMTEXTA of every list item (remote LVITEM)
            import struct as _sx
            kk = ctypes.WinDLL('kernel32'); kk.VirtualAllocEx.restype = ctypes.c_void_p
            kk.VirtualAllocEx.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_size_t, w.DWORD, w.DWORD]
            kk.WriteProcessMemory.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p]
            hp_ = kk.OpenProcess(0x1F0FFF, False, p.pid); mem_ = kk.VirtualAllocEx(hp_, None, 4096, 0x3000, 4)
            lv = []
            Pc = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
            def cb2(c, _):
                cn = ctypes.create_unicode_buffer(64); u32.GetClassNameW(c, cn, 64)
                if cn.value == 'SysListView32': lv.append(c)
                return True
            u32.EnumChildWindows(h, Pc(cb2), 0)
            r_ = ctypes.c_size_t(0)
            for l_ in lv:
                u32.SendMessageTimeoutW(l_, 0x1004, 0, 0, 2, 2000, ctypes.byref(r_)); n_ = r_.value
                for i_ in range(n_):
                    d_ = _sx.pack('<IiiIIIiiiI', 1, i_, 0, 0, 0, mem_ + 512, 256, 0, 0, 0)
                    kk.WriteProcessMemory(hp_, mem_, d_, len(d_), None)
                    u32.SendMessageTimeoutA(l_, 0x102D, i_, ctypes.c_ssize_t(mem_), 2, 2000, ctypes.byref(r_))
                print('read %d list items' % n_, flush=True)
            continue
        if _cur == 'close':
            u32.PostMessageW(h, 0x111, 2, 0); u32.PostMessageW(h, 0x10, 0, 0)
        else:
            u32.PostMessageW(h, 0x111, int(_cur, 0), 0)
    return bool(found)


while time.time() - t0 < secs:
    if POST and _queue and time.time() - t0 > _next_t:   # ATTACH_POST=0xE100,0x807f: one command every 5 s
        _cur = _queue[0]
        if _post():
            print('posted WM_COMMAND %s at %.1fs' % (_cur, time.time() - t0), flush=True)
            _queue.pop(0); _next_t = time.time() - t0 + 5
    if not k.WaitForDebugEvent(ctypes.byref(ev), 500):
        continue
    status = 0x10002   # DBG_CONTINUE
    if ev.code == 1:   # EXCEPTION
        code, = struct.unpack_from('<I', bytes(ev.u), 0)
        first = struct.unpack_from('<I', bytes(ev.u), 152)[0]   # EXCEPTION_RECORD64-sized record, then dwFirstChance
        if os.environ.get('ATTACH_WATCH') and code in (0x80000004, 0x4000001e) and ev.tid not in _rearm:
            hw_ = k.OpenThread(0x1FFFFF, False, ev.tid); cw_ = CTX(); cw_.Flags = 0x10017; k.Wow64GetThreadContext(hw_, ctypes.byref(cw_))
            if cw_.Dr[4] & 1:   # Dr6 B0: the watched dword was written; Eip is after the writing instruction
                sb_ = struct.unpack('<64I', _rd(cw_.Esp, 256))
                fr_ = [near(cw_.Eip)[:60]] + [near(v_)[:50] for v_ in sb_ if 0x401000 <= v_ < 0x900000][:3]
                kk_ = ('W', struct.unpack('<i', _rd(int(os.environ['ATTACH_WATCH'], 16)))[0] if False else 0) and None
                kk_ = tuple(fr_); _msgs[kk_] = _msgs.get(kk_, 0) + 1
                cw_.Dr[4] = 0; cw_.Flags = 0x10010; k.Wow64SetThreadContext(hw_, ctypes.byref(cw_))
            k.CloseHandle(hw_)
            k.ContinueDebugEvent(ev.pid, ev.tid, status); continue
        if code in (0x80000003, 0x4000001f) and (not seen_bp or code == 0x4000001f):   # the attach break-in (created: native + WOW64 loader breakpoints)
            seen_bp = True
            if os.environ.get('ATTACH_WATCH'):
                for t_ in _all_tids():
                    _arm_watch(t_)
            for a_ in filter(None, os.environ.get('ATTACH_BP', '').split(',')):   # one-shot int3s: report first hit
                # *ADDR: an import slot -- break on the DLL function it points to
                if '!' in a_:   # dll!Export (32-bit module in the target: base from the process, RVA from SysWOW64)
                    va_ = _exp(*a_.split('!'))
                    if not va_:
                        print('no export', a_); continue
                else:
                    va_ = struct.unpack('<I', _rd(int(a_[1:], 16)))[0] if a_.startswith('*') else int(a_, 16)
                ob_ = _rd(va_, 1)
                if k.WriteProcessMemory(hp, ctypes.c_void_p(va_), bytes([0xcc]), 1, ctypes.byref(ctypes.c_size_t())):
                    _bps[va_] = ob_; _orig_byte[va_] = ob_
        elif code in (0x80000003, 0x4000001f) and first and struct.unpack_from('<Q', bytes(ev.u), 16)[0] & 0xffffffff in _bps:
            va_ = struct.unpack_from('<Q', bytes(ev.u), 16)[0] & 0xffffffff
            k.WriteProcessMemory(hp, ctypes.c_void_p(va_), _bps.pop(va_), 1, ctypes.byref(ctypes.c_size_t()))
            h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c))
            c.Eip = va_
            if os.environ.get('ATTACH_COUNT'):   # count every hit: single-step over the restored byte, then re-arm
                _cnt[va_] = _cnt.get(va_, 0) + 1; c.EFlags |= 0x100; _rearm[ev.tid] = va_
                if os.environ.get('ATTACH_STK'):   # first exe frames on the stack (skip the hook manager)
                    sb_ = struct.unpack('<128I', _rd(c.Esp, 512)); fr_ = []
                    for v_ in sb_:
                        if 0x401000 <= v_ < 0x900000:
                            n_ = near(v_)
                            if 'HookWndProc' not in n_ and '__eh' not in n_:
                                fr_.append(n_[:60])
                        if len(fr_) == 3:
                            break
                    _msgs[tuple(fr_)] = _msgs.get(tuple(fr_), 0) + 1
                if os.environ.get('ATTACH_CWP'):   # CallWindowProc(prev, hwnd, msg, ...): tally (msg, prev proc)
                    pv_, hw_, msg_ = struct.unpack('<III', _rd(c.Esp + 4, 12))
                    nm_ = ctypes.create_unicode_buffer(260); ctypes.WinDLL('psapi').GetMappedFileNameW(hp, ctypes.c_void_p(pv_), nm_, 260)
                    k_ = (msg_, '%08x %s' % (pv_, near(pv_)[:50] if 0x401000 <= pv_ < 0x3000000 else nm_.value.rsplit(chr(92), 1)[-1]))
                    _msgs[k_] = _msgs.get(k_, 0) + 1
                if os.environ.get('ATTACH_HWNDMSG'):   # f(hwnd, msg, ...): tally (msg, class of hwnd)
                    hw_, msg_ = struct.unpack('<II', _rd(c.Esp + 4, 8))
                    cn_ = ctypes.create_unicode_buffer(64); ctypes.WinDLL('user32').GetClassNameW(hw_, cn_, 64)
                    tt_ = ctypes.create_unicode_buffer(64); ctypes.WinDLL('user32').GetWindowTextW(hw_, tt_, 64)
                    kk_ = (msg_, cn_.value[:30], tt_.value, '%x' % hw_)
                    _msgs[kk_] = _msgs.get(kk_, 0) + 1
                if os.environ.get('ATTACH_CALLER') and (not os.environ.get('ATTACH_ECX') or c.Ecx == int(os.environ['ATTACH_ECX'], 16)):   # tally the caller of each counted hit (ATTACH_ECX: only this `this`)
                    ra_ = struct.unpack('<I', _rd(c.Esp))[0]
                    _kc = ('%08x' % va_, ra_, near(ra_)[:70]); _msgs[_kc] = _msgs.get(_kc, 0) + 1
                if os.environ.get('ATTACH_REG'):   # tally a register's value at each counted hit (eax after a call)
                    _kr = ('%08x' % va_, os.environ['ATTACH_REG'], '%08x' % getattr(c, os.environ['ATTACH_REG'].capitalize())); _msgs[_kr] = _msgs.get(_kr, 0) + 1
                if os.environ.get('ATTACH_STRARG'):   # ESPOFF: tally printable text of the object *(esp+ESPOFF) points to (Name / std::string)
                    _pa = struct.unpack('<I', _rd(c.Esp + int(os.environ['ATTACH_STRARG'], 16)))[0]
                    _ob = _rd(_pa, 48) if 0x10000 < _pa < 0x7fff0000 else b''
                    _tx = re.sub(rb'[^ -~]+', b'|', _ob).decode()
                    for _w in struct.unpack('<12I', _ob) if len(_ob) == 48 else ():
                        if 0x10000 < _w < 0x7fff0000:
                            _t2 = _rd(_w, 24).split(bytes(1))[0]
                            if len(_t2) >= 3 and all(32 <= ch < 127 for ch in _t2):
                                _tx += ' *' + _t2.decode()
                    _kk = ('%08x' % va_, _tx[:80]); _msgs[_kk] = _msgs.get(_kk, 0) + 1
                if os.environ.get('ATTACH_VT'):   # tally (vtable symbol of *ecx, edx target): which class reaches which virtual
                    _vt = struct.unpack('<I', _rd(c.Ecx))[0]
                    _kv = ('%08x' % va_, near(_vt)[:70], near(c.Edx)[:50]); _msgs[_kv] = _msgs.get(_kv, 0) + 1
                if os.environ.get('ATTACH_MSG'):   # DispatchMessage(MSG*): tally (message, window class)
                    mp_ = struct.unpack('<I', _rd(c.Esp + 4))[0]
                    hw_, msg_ = struct.unpack('<II', _rd(mp_, 8))
                    cn_ = ctypes.create_unicode_buffer(64); ctypes.WinDLL('user32').GetClassNameW(hw_, cn_, 64)
                    tt_ = ctypes.create_unicode_buffer(64); ctypes.WinDLL('user32').GetWindowTextW(hw_, tt_, 64)
                    kk_ = (msg_, cn_.value[:30], tt_.value, '%x' % hw_)
                    _msgs[kk_] = _msgs.get(kk_, 0) + 1
            else:
                print('BP hit %08x %s ecx %08x eax %08x esi %08x edi %08x' % (va_, near(va_), c.Ecx, c.Eax, c.Esi, c.Edi), flush=True)
                if os.environ.get('ATTACH_BPSTK'):   # exe frames at the hit
                    for v_ in struct.unpack('<256I', _rd(c.Esp, 1024)):
                        if 0x401000 <= v_ < 0x7c0000 and not near(v_).startswith(('??_7', '__eh')):
                            print('    <-', near(v_)[:110])
            k.Wow64SetThreadContext(h, ctypes.byref(c))
        elif code in (0x80000004, 0x4000001e) and ev.tid in _rearm:   # single step after a counted hit
            va_ = _rearm.pop(ev.tid)
            k.WriteProcessMemory(hp, ctypes.c_void_p(va_), bytes([0xcc]), 1, ctypes.byref(ctypes.c_size_t()))
            _bps[va_] = _rd(va_, 1) if False else _orig_byte[va_]
        elif code == 0xe06d7363 and first:   # C++ throw: type name + exe frames, then let the app handle it
            u_ = bytes(ev.u); ti = struct.unpack_from('<Q', u_, 32 + 16)[0] & 0xffffffff
            cta = struct.unpack('<I', _rd(ti + 12))[0]; ct = struct.unpack('<I', _rd(cta + 4))[0]; td = struct.unpack('<I', _rd(ct + 4))[0]
            h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c))
            buf = (ctypes.c_uint32 * 1024)(); n = ctypes.c_size_t(); k.ReadProcessMemory(hp, ctypes.c_void_p(c.Esp), buf, 4096, ctypes.byref(n))
            print('C++ throw %s tid %d:' % (_rd(td + 8, 40).split(bytes(1))[0].decode('latin-1'), ev.tid), ' <- '.join(near(v)[:70] for v in buf if 0x401000 <= v < 0x900000)[:900], flush=True)
            status = 0x80010001
        elif code in (0xc0000005, 0xc00000fd, 0xc0000374) or (not first and code not in (0x80000003, 0x4000001f, 0x406d1388)) or (code in (0x80000003, 0x4000001f) and seen_bp and not os.environ.get('ATTACH_BP')):   # + verifier / heap breaks
            h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            print('exception %08x (%s chance) tid %d eip %08x %s' % (code, 'first' if first else 'SECOND', ev.tid, c.Eip, near(c.Eip)))
            print('eax %08x ebx %08x ecx %08x edx %08x esi %08x edi %08x ebp %08x esp %08x' % (c.Eax, c.Ebx, c.Ecx, c.Edx, c.Esi, c.Edi, c.Ebp, c.Esp))
            for rn in ('Ecx', 'Esi', 'Edi', 'Ebx', 'Ebp'):   # what each pointer register points at (object + its vtable)
                rv = getattr(c, rn); mb = _rd(rv, 16) if 0x10000 < rv < 0x7fff0000 else b''
                if len(mb) == 16:
                    d0 = struct.unpack('<4I', mb)
                    print('  [%s] %s | [0] -> %s' % (rn, ' '.join('%08x' % x for x in d0), near(d0[0]) if 0x401000 <= d0[0] < 0x3000000 else '%08x' % d0[0]))
            buf = (ctypes.c_uint32 * 1024)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(hp, ctypes.c_void_p(c.Esp), buf, 4096, ctypes.byref(n))
            shown = 0
            for v in buf:
                if 0x401000 <= v < 0x7c0000 and shown < int(os.environ.get('ATTACH_FRAMES', '30')) and not near(v).startswith(('??_7', '?GetInplaceList', '?OnBeforeInsert')) and _is_ret(v):
                    print('  stack', near(v)); shown += 1
            k.TerminateProcess(hp, 1); break
        else:
            status = 0x80010001   # DBG_EXCEPTION_NOT_HANDLED: let the app's handlers see it
    elif ev.code == 2 and os.environ.get('ATTACH_WATCH'):   # CREATE_THREAD: arm the new thread too
        _arm_watch(ev.tid)
    elif ev.code == 5:   # EXIT_PROCESS
        print('process exited'); break
    k.ContinueDebugEvent(ev.pid, ev.tid, status)
else:
    print('no access violation within %ds' % secs)
for _key, n_ in sorted(_msgs.items(), key=lambda kv: -kv[1])[:int(os.environ.get('ATTACH_TOP', '12'))]:
    print('MSG %7d  %s' % (n_, ' | '.join(str(x) for x in _key) if isinstance(_key, tuple) else _key))
for va_, n_ in sorted(_cnt.items(), key=lambda kv: -kv[1]):
    print('COUNT %7d  %08x %s' % (n_, va_, near(va_)))
    k.TerminateProcess(hp, 1)
time.sleep(0.5)
import ieclean as _iec; _iec.clean(_T0)   # the client's IE pages open as Edge windows on Windows 11
