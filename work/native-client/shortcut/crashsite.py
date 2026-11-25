"""Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest
symbols from the link map. python crashsite.py EXE MAP [seconds]"""
import os, ctypes, ctypes.wintypes as w, re, subprocess, sys, struct, time
exe, mapf = sys.argv[1], sys.argv[2]
k = ctypes.WinDLL('kernel32', use_last_error=True)
class SI(ctypes.Structure):
    _fields_ = [('cb', w.DWORD)] + [(n, w.LPVOID) for n in ('r', 'd', 't')] + [(n, w.DWORD) for n in
        ('x', 'y', 'xs', 'ys', 'xc', 'yc', 'fill', 'flags')] + [('sw', w.WORD), ('cb2', w.WORD), ('r2', w.LPVOID),
        ('i', w.HANDLE), ('o', w.HANDLE), ('e', w.HANDLE)]
class PI(ctypes.Structure):
    _fields_ = [('hp', w.HANDLE), ('ht', w.HANDLE), ('pid', w.DWORD), ('tid', w.DWORD)]
si, pi = SI(), PI(); si.cb = ctypes.sizeof(si)
if os.environ.get('ROC_HIDE_WINDOW'):   # old behaviour: SW_HIDE (Direct3D9 then refuses a device: "Not available")
    si.flags |= 0x1; si.sw = 0
elif not os.environ.get('ROC_SHOW_WINDOW'):
    # shown but kept behind every other window: Direct3D9 needs a really shown, non-layered, on-screen window
    # (SW_HIDE, off-screen positions and layered windows all give "Not available").
    si.flags |= 0x1; si.sw = 4   # SW_SHOWNOACTIVATE
    def _ghost():   # normal window kept at the bottom of the z-order and never activated (layered/off-screen/hidden all break D3D9)
        _u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
        def cb(h, _):
            p = w.DWORD(); _u.GetWindowThreadProcessId(h, ctypes.byref(p))
            if p.value == pi.pid and _u.IsWindowVisible(h):
                _u.SetWindowPos(h, w.HWND(1), 0, 0, 0, 0, 0x1 | 0x2 | 0x10)   # HWND_BOTTOM, NOSIZE | NOMOVE | NOACTIVATE
            return True
        cbp = P(cb)
        while True:
            try: _u.EnumWindows(cbp, 0)
            except Exception: pass
            time.sleep(0.02)
    import threading
    threading.Thread(target=_ghost, daemon=True).start()
try:   # IE is intentional in the client; the harness only cleans it up before and after each launch (work/ie_cleanup.py)
    sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
    import ie_cleanup, atexit
    ie_cleanup.close_all_ie(); atexit.register(ie_cleanup.close_all_ie)
    if not os.environ.get('ROC_IE_ALLOW'):   # keep IE from opening during probes: kill iexplore.exe as soon as it appears (client stays authentic)
        import threading, time as _t
        def _ie_watch():
            while True:
                try: ie_cleanup.close_all_ie(verbose=False)
                except Exception: pass
                _t.sleep(0.5)
        threading.Thread(target=_ie_watch, daemon=True).start()
except Exception as _e:
    print('ie cleanup unavailable:', _e)
if not os.environ.get("ROC_PROBE_VISIBLE"):  # hidden desktop: no window on the user's screen; this thread joins it
    _u = ctypes.WinDLL('user32'); _u.CreateDesktopW.restype = w.HANDLE
    _hd = _u.CreateDesktopW('RocProbe', None, None, 0, 0x10000000, None); _u.SetThreadDesktop(w.HANDLE(_hd))
    _dname = ctypes.create_unicode_buffer('RocProbe'); si.d = ctypes.cast(_dname, w.LPVOID)
import os
if not k.CreateProcessW(exe, None, None, None, False, 1, None, os.path.dirname(os.path.abspath(exe)), ctypes.byref(si), ctypes.byref(pi)):
    raise SystemExit('create failed %d' % ctypes.get_last_error())
class CTX(ctypes.Structure):  # WOW64_CONTEXT
    _fields_ = [('Flags', w.DWORD)] + [(n, w.DWORD) for n in ('Dr0','Dr1','Dr2','Dr3','Dr6','Dr7')] + \
        [('fc', ctypes.c_byte * 112)] + [(n, w.DWORD) for n in ('SegGs','SegFs','SegEs','SegDs','Edi','Esi','Ebx','Edx','Ecx','Eax','Ebp','Eip','SegCs','EFlags','Esp','SegSs')] + [('ext', ctypes.c_byte * 512)]
import capstone
BPSYM = os.environ.get('BPFUNC') or os.environ.get('BPENTRY') or os.environ.get('TRACE_ENTRY') or os.environ.get('BPSTUBS')
if os.environ.get('TRACE_ENTRY') and not os.environ.get('BPENTRY'):
    os.environ['BPENTRY'] = os.environ['TRACE_ENTRY']
syms = []
txt = open(mapf, errors='replace').read()
base = int(re.search(r'Preferred load address is ([0-9a-f]+)', txt).group(1), 16)
for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', txt, re.M):
    syms.append((int(m.group(2), 16), m.group(1)))
syms.sort()
import bisect
keys = [s[0] for s in syms]
# The exe is not DYNAMIC_BASE, but when its preferred range is taken (a 50 MB image) the loader relocates it: every map
# address is then off by `delta` (set from CREATE_PROCESS_DEBUG_EVENT). Breakpoints written at map addresses went into
# whatever occupied 0x400000+ and the probe corrupted the process. Map-space in, process-space out: va + delta.
delta = 0
_code_end = base + 0x1000 + max([int(o, 16) + int(l, 16) for o, l in re.findall(
    r'^\s*0001:([0-9a-f]{8})\s+([0-9a-f]+)H\s+\S+\s+CODE\s*$', txt, re.M)] or [0x57f000])
def inexe(v):
    return base + 0x1000 + delta <= v < _code_end + delta
def near(a):
    a -= delta
    i = bisect.bisect_right(keys, a) - 1
    return '%08x %s+%x' % (a, syms[i][1][:90], a - syms[i][0]) if i >= 0 else '%08x' % a
class EV(ctypes.Structure):
    _fields_ = [('code', w.DWORD), ('pid', w.DWORD), ('tid', w.DWORD), ('pad', w.DWORD), ('u', ctypes.c_ubyte * 160)]
bps = {}
trace_tid = None
trace = []

def apply_patches():
    """PATCH='spec;spec': test a fix in the live process before relinking. spec forms (addresses: hex or symbol[+0xoff]
    from the map, after delta):  ADDR:HEXBYTES (raw bytes)  |  ADDR=SYMBOL (4-byte pointer to SYMBOL)  |
    ADDR->SYMBOL (re-target the 5-byte call/jmp rel32 at ADDR)"""
    def res(x):
        x = x.strip()
        m_ = re.fullmatch(r'(?:0x)?([0-9a-fA-F]{6,8})', x)
        if m_:
            return int(m_.group(1), 16) + delta   # hex addresses are map-space, like BPLIST/BPENTRY
        nm_, _, off_ = x.partition('+')
        hit_ = [v for v, n_ in syms if n_ == nm_]
        if not hit_:
            raise ValueError('PATCH: %r not in map' % nm_)
        return hit_[0] + delta + (int(off_, 0) if off_ else 0)
    for spec in filter(None, os.environ.get('PATCH', '').split(';')):
        try:
            if '->' in spec:
                a_, t_ = spec.split('->', 1); a_ = res(a_); t_ = res(t_)
                op = (ctypes.c_ubyte * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(a_), op, 1, ctypes.byref(ctypes.c_size_t()))
                b_ = bytes([op[0]]) + struct.pack('<i', t_ - (a_ + 5))
            elif '=' in spec:
                a_, t_ = spec.split('=', 1); a_ = res(a_); b_ = struct.pack('<I', res(t_))
            else:
                a_, h_ = spec.split(':', 1); a_ = res(a_); b_ = bytes.fromhex(h_)
            old_ = w.DWORD()
            k.VirtualProtectEx(pi.hp, ctypes.c_void_p(a_), len(b_), 0x40, ctypes.byref(old_))
            ok_ = k.WriteProcessMemory(pi.hp, ctypes.c_void_p(a_), b_, len(b_), ctypes.byref(ctypes.c_size_t()))
            k.VirtualProtectEx(pi.hp, ctypes.c_void_p(a_), len(b_), old_.value, ctypes.byref(w.DWORD()))
            print('PATCH %s -> %08x %s %s' % (spec.strip()[:80], a_, b_.hex(), 'ok' if ok_ else 'FAILED'), flush=True)
        except Exception as e_:
            print('PATCH %s failed: %s' % (spec.strip()[:80], e_), flush=True)


def live_stubfix():
    """LIVE_STUBFIX=1: every map stub (qt_*stubs*.obj function symbol) whose name a loaded DLL exports gets a jmp to the
    real export -- library functions the link stubbed by mistake work without a relink. Logged to auto/live_stubfix.txt"""
    import pefile, json as _js
    ps_ = ctypes.WinDLL('psapi')
    arr = (ctypes.c_void_p * 1024)(); need = w.DWORD()
    if not ps_.EnumProcessModulesEx(pi.hp, arr, ctypes.sizeof(arr), ctypes.byref(need), 0x01):
        print('LIVE_STUBFIX: cannot list modules'); return
    try:
        om = _js.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'donorfree-route', 'renamed', 'ordinals.json'))).get('mfc90.dll', {})
    except Exception:
        om = {}
    exports = {}
    for i in range(need.value // 8):
        nm_ = ctypes.create_unicode_buffer(300); ps_.GetModuleFileNameExW(pi.hp, ctypes.c_void_p(arr[i]), nm_, 300)
        low = nm_.value.lower()
        if low.endswith('.exe') or os.sep + 'system32' + os.sep in low:
            continue
        try:
            pe_ = pefile.PE(nm_.value, fast_load=True)
            pe_.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
            xsec = [(s_.VirtualAddress, s_.VirtualAddress + s_.Misc_VirtualSize) for s_ in pe_.sections if s_.Characteristics & 0x20000000]
            for e_ in (pe_.DIRECTORY_ENTRY_EXPORT.symbols if hasattr(pe_, 'DIRECTORY_ENTRY_EXPORT') else []):
                if not any(lo_ <= e_.address < hi_ for lo_, hi_ in xsec):
                    continue   # data export (vtable, static): never write a jmp over a data stub
                n_ = e_.name.decode() if e_.name else (om.get(str(e_.ordinal)) if 'mfc90' in low else None)
                if n_ and n_ not in exports:
                    exports[n_] = (arr[i] + e_.address, os.path.basename(nm_.value))
        except Exception:
            continue
    STUBSYMS = []
    for _ml in open(mapf, errors='replace'):
        _mp = _ml.split()
        if len(_mp) >= 4 and ':' in _mp[0] and re.fullmatch(r'[0-9a-f]{8}', _mp[2]) and 'stubs' in _mp[-1].lower():
            STUBSYMS.append((int(_mp[2], 16), _mp[1], _mp[-1]))
    fixed, log = 0, []
    for v_, n_, own in STUBSYMS:
        cands = [n_]
        if not n_.startswith('?'):
            b_ = n_[1:] if n_.startswith('_') else n_
            cands += [re.sub(r'@\d+$', '', b_), b_]
        t_ = next((exports[c] for c in cands if c in exports), None)
        if not t_:
            continue
        a_ = v_ + delta
        b5 = bytes([0xE9]) + struct.pack('<i', t_[0] - (a_ + 5))
        old_ = w.DWORD()
        k.VirtualProtectEx(pi.hp, ctypes.c_void_p(a_), 5, 0x40, ctypes.byref(old_))
        if k.WriteProcessMemory(pi.hp, ctypes.c_void_p(a_), b5, 5, ctypes.byref(ctypes.c_size_t())):
            fixed += 1; log.append('%08x %s -> %s!%08x' % (a_, n_, t_[1], t_[0]))
        k.VirtualProtectEx(pi.hp, ctypes.c_void_p(a_), 5, old_.value, ctypes.byref(w.DWORD()))
    try:
        open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'donorfree-route', 'auto', 'live_stubfix.txt'), 'w').write(chr(10).join(log) + chr(10))
    except Exception:
        pass
    print('LIVE_STUBFIX: %d stubs redirected to real DLL exports (auto/live_stubfix.txt)' % fixed, flush=True)

def arm_imports():
    """BPIMP=name,name: break on the CRT functions an import slot points to (e.g. _invalid_parameter_noinfo, which ends the
    process with 0xC0000417 and no exception event) and print the caller stack. Imports are bound at the loader breakpoint."""
    n = ctypes.c_size_t()
    if os.environ.get('SKIPAV'):   # invalid CRT parameter -> log + return (as a returning _set_invalid_parameter_handler would)
        for v, s_ in syms:
            if s_ == '__imp___invalid_parameter_noinfo':   # msvcr90 base from this slot; CRT code calls _invalid_parameter directly
                p_ = (ctypes.c_uint32 * 1)(); old = (ctypes.c_ubyte * 1)()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(v + delta), p_, 4, ctypes.byref(n))
                tgts = [p_[0]] if p_[0] else []
                try:
                    mb_ = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(p_[0]), mb_, 48)
                    mb = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mb_))[8:12])[0]
                    def rd(a_, n_):
                        b_ = ctypes.create_string_buffer(n_); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(a_), b_, n_, ctypes.byref(n)); return b_.raw
                    ed = struct.unpack('<I', rd(mb + struct.unpack('<I', rd(mb + 0x3c, 4))[0] + 0x78, 4))[0]
                    nf, nn_, af, an, ao = struct.unpack('<5I', rd(mb + ed + 0x14, 20))[0:5]
                    names = struct.unpack('<%dI' % nn_, rd(mb + an, 4 * nn_))
                    for i_, na in enumerate(names):
                        if rd(mb + na, 20).split(b'\0')[0] == b'_invalid_parameter':
                            o_ = struct.unpack('<H', rd(mb + ao + 2 * i_, 2))[0]
                            tgts.append(mb + struct.unpack('<I', rd(mb + af + 4 * o_, 4))[0])
                except Exception as e_:
                    print('INVPARAM export lookup failed', e_)
                for t_ in tgts:
                    if t_ not in bps and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(t_), old, 1, ctypes.byref(n)):
                        bps[t_] = (old[0], 'INVPARAM')
                        k.WriteProcessMemory(pi.hp, ctypes.c_void_p(t_), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
                print('SKIPAV: invalid CRT parameters return EINVAL instead of ending the process', [hex(t_) for t_ in tgts], flush=True)
    for nm in filter(None, os.environ.get('BPIMP', '').split(',')):
        slot = [v for v, s_ in syms if s_ in ('__imp_' + nm, '__imp__' + nm)]
        if not slot:
            continue
        p_ = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(slot[0] + delta), p_, 4, ctypes.byref(n))
        tgt = p_[0]; old = (ctypes.c_ubyte * 1)()
        if tgt and tgt not in bps and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(tgt), old, 1, ctypes.byref(n)):
            bps[tgt] = (old[0], 'ENTRY'); k.WriteProcessMemory(pi.hp, ctypes.c_void_p(tgt), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
            print('armed import breakpoint', nm, hex(tgt))
hit_once = set()   # one-shot breakpoints already restored: a second thread's queued int3 there needs the same EIP rewind
def arm(va, label, real=False):
    """Arm one one-shot int3. An address armed twice (ICF-folded functions, duplicate list lines) keeps its first entry:
    re-reading it would save the 0xCC we wrote as the 'original' byte and corrupt the code when restored."""
    if not real:
        va += delta
    if va in bps or va in hit_once:
        return 0
    old = (ctypes.c_ubyte * 1)(); n = ctypes.c_size_t()
    if not k.ReadProcessMemory(pi.hp, ctypes.c_void_p(va), old, 1, ctypes.byref(n)):
        return 0
    if not k.WriteProcessMemory(pi.hp, ctypes.c_void_p(va), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n)):
        return 0
    bps[va] = (old[0], label); return 1
def arm_bps():
    if os.environ.get('BPLIST'):   # one-shot entry breakpoints 'ADDR LABEL' per line: first-call order trace (difftrace.py)
        n = ctypes.c_size_t(); cnt = 0
        for line in open(os.environ['BPLIST']):
            parts = line.split()
            if len(parts) < 2:
                continue
            cnt += arm(int(parts[0], 16), 'STUB HIT ' + parts[1])
        print('armed', cnt, 'trace breakpoints'); return
    if os.environ.get('BPSTUBS'):
        n = ctypes.c_size_t(); cnt = 0
        # code sections only: ~16k stub symbols are data (section 0003); a 0xCC there corrupted globals
        code_seg = set(re.findall(r'^\s*([0-9a-f]{4}):[0-9a-f]{8}\s+[0-9a-f]+H\s+\S+\s+CODE\s*$', txt, re.M))
        for m in re.finditer(r'^\s*([0-9a-f]{4}):[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})(?: f)?(?: i)?\s+(?:\S+:)?\S*stubs\d?\.obj\s*$', txt, re.M):   # qt_stubs / qt_base_stubs / qt_stubs2 too
            if m.group(1) in code_seg:
                cnt += arm(int(m.group(3), 16), 'STUB ' + m.group(2))
        print('armed', cnt, 'stub breakpoints'); return
    if not BPSYM: return
    if os.environ.get('BPENTRY'):
        _be = os.environ['BPENTRY']
        ent = [int(_be, 16)] if re.fullmatch(r'(?:0x)?[0-9a-fA-F]{6,8}', _be) else [v for v, n in syms if n == _be]
        if not ent: print('BPENTRY not in map'); return
        old = (ctypes.c_ubyte * 1)(); n = ctypes.c_size_t()
        ent = [ent[0] + delta]
        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(ent[0]), old, 1, ctypes.byref(n))
        bps[ent[0]] = (old[0], 'ENTRY')
        k.WriteProcessMemory(pi.hp, ctypes.c_void_p(ent[0]), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
        print('armed entry breakpoint'); return
    start = [v for v, n in syms if n == BPSYM]
    if not start: print('BPFUNC not in map'); return
    st = start[0]; nxt = [v for v, n in syms if v > st]; end = min(nxt[0], st + 0x2000) if nxt else st + 0x2000
    raw = (ctypes.c_ubyte * (end - st))(); n = ctypes.c_size_t()
    st += delta; end += delta
    k.ReadProcessMemory(pi.hp, ctypes.c_void_p(st), raw, end - st, ctypes.byref(n))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for ins in md.disasm(bytes(raw), st):
        if ins.mnemonic == 'call':
            tgt = near(int(ins.op_str, 16)) if ins.op_str.startswith('0x') else ins.op_str
            old = (ctypes.c_ubyte * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(ins.address), old, 1, ctypes.byref(n))
            bps[ins.address] = (old[0], tgt)
            k.WriteProcessMemory(pi.hp, ctypes.c_void_p(ins.address), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
    print('armed', len(bps), 'call breakpoints in', BPSYM[:60])
armed = False
cxx_seen = 0
T_START = time.time()
ev = EV(); deadline = time.time() + float(sys.argv[3] if len(sys.argv) > 3 else 20); first = True; ids = {}
posted = False; posted_n = 0; pending = []; t_start = time.time()
u32 = ctypes.WinDLL('user32')
def post_cmd(cmd):
    found = []
    CB = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
    def cb(h, l):
        pid = w.DWORD(); u32.GetWindowThreadProcessId(h, ctypes.byref(pid))
        if pid.value == pi.pid and (u32.IsWindowVisible(h) or not os.environ.get('ROC_SHOW_WINDOW')):
            t_ = ctypes.create_unicode_buffer(64); u32.GetWindowTextW(h, t_, 64)
            if 'Roblox' in t_.value: found.append(h)
        return True
    u32.EnumWindows(CB(cb), 0)
    print('POSTCMD to', [hex(x) for x in found], flush=True)
    for h in found: u32.PostMessageW(h, 0x111, cmd, 0)
while time.time() < deadline:
    # POSTCMD may be a comma list (e.g. File New then Insert Object), posted 5 s apart after an 8 s start
    pending = [int(c, 0) for c in os.environ.get('POSTCMD', '').split(',') if c] if not posted else pending
    if pending and armed and time.time() - t_start > 8 + 5 * posted_n:
        post_cmd(pending.pop(0)); posted_n += 1; t_last_post = time.time()
    posted = True
    # PROBE_IDLE=N: every command posted and N s without a crash -> stop early (the 40 s budget was mostly idle waiting)
    if os.environ.get('PROBE_IDLE') and posted_n and not pending and time.time() - globals().get('t_last_post', 1e18) > float(os.environ['PROBE_IDLE']):
        deadline = time.time()
    if not k.WaitForDebugEvent(ctypes.byref(ev), 500):
        continue
    status = 0x10002
    if ev.code == 1:  # exception
        rec = bytes(ev.u[:24]); code, flags, _, addr = struct.unpack('<IIQQ', rec[:24])
        first_chance = struct.unpack('<I', bytes(ev.u[80:84]))[0] if False else None
        if code in (0x80000003, 0x4000001f):
            if code == 0x4000001f and not globals().get('imp_armed'):   # WoW64 loader breakpoint: 32-bit imports now bound
                imp_armed = True; arm_imports()
                if not armed:   # after the 32-bit loader relocated the exe: reading 'original' bytes earlier saved pre-fixup bytes
                    armed = True; arm_bps()
                    if os.environ.get('PATCH'):
                        apply_patches()
                    if os.environ.get('LIVE_STUBFIX'):
                        live_stubfix()
                if os.environ.get('WATCH'):   # hardware write watchpoint: armed at the exe entry (set at the loader break it is lost)
                    watch_hits = 0
                    _ea = [v + delta for v, n_ in syms if n_ in ('_WinMainCRTStartup', '_wWinMainCRTStartup')]
                    if _ea:
                        _ob = (ctypes.c_ubyte * 1)(); _nn = ctypes.c_size_t()
                        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_ea[0]), _ob, 1, ctypes.byref(_nn))
                        bps[_ea[0]] = (_ob[0], 'WATCHARM')
                        k.WriteProcessMemory(pi.hp, ctypes.c_void_p(_ea[0]), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(_nn))
                if addr not in bps:
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
            if code in (0x80000003, 0x4000001f) and armed and globals().get('imp_armed') and os.environ.get('STOP_ON_BP') and addr not in bps and addr not in hit_once and globals().get('_bp_seen', 0) >= 0:
                # an int3 we did not plant (page-heap / verifier stop, __debugbreak): report where and stop
                hb = k.OpenThread(0x1fffff, False, ev.tid); cb = CTX(); cb.Flags = 0x10007; k.Wow64GetThreadContext(hb, ctypes.byref(cb))
                print('BREAKPOINT (unplanned) at %s eip %08x tid %d' % (near(cb.Eip)[:90], cb.Eip, ev.tid), flush=True)
                sb = (ctypes.c_uint32 * 2048)(); nb = ctypes.c_size_t()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cb.Esp), sb, 8192, ctypes.byref(nb))
                _sh = 0
                for v in sb:
                    if 0x401000 <= v < 0x980000 and _sh < 40: print('  stack', near(v)); _sh += 1
                k.TerminateProcess(pi.hp, 1); break
            if code == 0x80000003 and not armed:
                pass   # 64-bit initial breakpoint: the 32-bit exe is not relocated yet; arm at the WoW64 loader breakpoint
            elif addr in hit_once and addr not in bps:   # raced: another thread executed this int3 before we restored it
                h = k.OpenThread(0x1fffff, False, ev.tid); c2 = CTX(); c2.Flags = 0x10007
                k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
            elif addr in bps and bps[addr][1] == 'INVPARAM':   # persistent: never executed, the int3 stays; fake cdecl 'ret'
                h = k.OpenThread(0x1fffff, False, ev.tid); c2 = CTX(); c2.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c2))
                sb_ = (ctypes.c_uint32 * 64)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), sb_, 256, ctypes.byref(ctypes.c_size_t()))
                globals()['_inv_n'] = globals().get('_inv_n', 0) + 1
                if _inv_n <= 20:
                    print('INVPARAM #%d (returning) <- %s' % (_inv_n, ' <- '.join(near(v_)[:70] for v_ in sb_ if inexe(v_))[:300]), flush=True)
                c2.Eip = sb_[0]; c2.Esp += 4; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
            elif addr in bps:
                old, tgt = bps.pop(addr)
                if not tgt.startswith(('ENTRY', 'WATCHARM')):
                    hit_once.add(addr)   # ENTRY re-arms itself via _rearm
                k.WriteProcessMemory(pi.hp, ctypes.c_void_p(addr), (ctypes.c_ubyte * 1)(old), 1, ctypes.byref(ctypes.c_size_t()))
                h = k.OpenThread(0x1fffff, False, ev.tid); c2 = CTX(); c2.Flags = 0x10007
                k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                if tgt == 'WATCHARM':
                    c2.Flags = 0x10017; k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr
                    c2.Dr0 = int(os.environ['WATCH'], 16); c2.Dr7 = 0x000D0001; c2.Flags = 0x10017
                    print('watch armed', os.environ['WATCH'], bool(k.Wow64SetThreadContext(h, ctypes.byref(c2))), flush=True)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt.startswith('RET '):   # BPRET: first return of a watched function -> its eax
                    print('RET', tgt[4:90], '%08x' % c2.Eax, flush=True)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt.startswith('STUB '):
                    rb = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), rb, 4, ctypes.byref(ctypes.c_size_t()))
                    print('STUB', tgt[5:], '<-', near(rb[0])[:90], flush=True)   # full name: stubhits.py maps it to an address
                    if os.environ.get('BPRET') and tgt.startswith('STUB HIT '):   # one-shot return breakpoint
                        arm(rb[0], 'RET ' + tgt[9:], real=True)
                    if os.environ.get('TRACE_AFTER') and os.environ['TRACE_AFTER'] in tgt:
                        c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2)); trace_tid = ev.tid; trace = []
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY' and os.environ.get('TRACE_ENTRY'):   # single-step from this entry to the crash
                    c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2)); trace_tid = ev.tid; trace = []
                    print('ENTRY hit: tracing', flush=True)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY' and os.environ.get('ENTRY_LOG'):   # log every hit (caller + 3 stack args), keep running
                    _sb = (ctypes.c_uint32 * 4)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), _sb, 16, ctypes.byref(ctypes.c_size_t()))
                    globals()['_elog'] = globals().get('_elog', 0) + 1
                    if _elog <= int(os.environ['ENTRY_LOG']):
                        _ab = (ctypes.c_uint32 * 6)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_sb[1]), _ab, 24, ctypes.byref(ctypes.c_size_t()))
                        print('HIT #%d ecx %08x args %08x %08x %08x <- %s | [arg1] %s' % (_elog, c2.Ecx, _sb[1], _sb[2], _sb[3], near(_sb[0])[:60],
                              ' '.join('%08x' % x for x in _ab)), flush=True)
                    c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                    globals().setdefault('_rearm', {})[ev.tid] = (addr, old)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY' and os.environ.get('ENTRY_IF'):   # conditional: ENTRY_IF='edx!=00452040' (== or !=)
                    _m = re.fullmatch(r'(\w+)\s*(==|!=)\s*(?:0x)?([0-9a-fA-F]+)', os.environ['ENTRY_IF'].strip())
                    _v = getattr(c2, _m.group(1).capitalize()); _w = int(_m.group(3), 16)
                    if (_v == _w) != (_m.group(2) == '=='):   # not this hit: step over, re-arm on the single-step
                        c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                        globals().setdefault('_rearm', {})[ev.tid] = (addr, old)
                        k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY':
                    n2 = ctypes.c_size_t(); buf = (ctypes.c_uint32 * 256)()
                    k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), buf, 1024, ctypes.byref(n2))
                    print('ENTRY hit (eip %08x) eax %08x ecx %08x edx %08x esi %08x edi %08x ebp %08x' % (addr, c2.Eax, c2.Ecx, c2.Edx, c2.Esi, c2.Edi, c2.Ebp))
                    print('crash after %.2fs' % (time.time() - T_START))
                    for rn in ('Ecx', 'Esi', 'Edi', 'Ebp'):   # 24 bytes at each pointer register, and what its first word points at
                        rv = getattr(c2, rn); mb = (ctypes.c_uint32 * 6)()
                        if 0x10000 < rv < 0x7fff0000 and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(rv), mb, 24, ctypes.byref(n2)):
                            mb2 = (ctypes.c_uint32 * 4)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(mb[0]), mb2, 16, ctypes.byref(n2))
                            print('   [%s] %s | [[%s]] %s' % (rn, ' '.join('%08x' % x for x in mb), rn, ' '.join('%08x' % x for x in mb2)))
                    for _em in (os.environ.get('ENTRY_MEM') or '').split(','):   # ENTRY_MEM=ecx+0x178,esi: 32 bytes each
                        _deref = len(_em.strip()) - len(_em.strip().lstrip('*'))   # *ecx+0x178: the dword stored there, then 32 bytes at it
                        _mm = re.fullmatch(r'\s*\**(\w+)\s*(?:\+\s*(0x[0-9a-fA-F]+|\d+))?\s*', _em)
                        if _mm and _em.strip():
                            _a = getattr(c2, _mm.group(1).capitalize()) + (int(_mm.group(2), 0) if _mm.group(2) else 0)
                            for _d in range(_deref):   # **ecx+0x10: follow the pointer chain
                                _pv = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_a), _pv, 4, ctypes.byref(ctypes.c_size_t())); _a = _pv[0]
                            _mb = (ctypes.c_uint32 * 8)(); _n3 = ctypes.c_size_t()
                            if k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_a), _mb, 32, ctypes.byref(_n3)):
                                print('   mem %s @%08x: %s' % (_em.strip(), _a, ' '.join('%08x' % x for x in _mb)))
                            else:
                                print('   mem %s @%08x: unreadable' % (_em.strip(), _a))
                    if os.environ.get('CXXSTACK'):   # DLL frames too (module+offset)
                        for i_, v_ in enumerate(buf[:200]):
                            nm2 = ctypes.create_unicode_buffer(260)
                            if v_ > 0x10000 and not inexe(v_) and ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(v_), nm2, 260):
                                mb2 = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(v_), mb2, 48)
                                ab2 = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mb2))[8:12])[0]
                                print('    esp+%03x %08x %s+%x' % (4 * i_, v_, nm2.value.rsplit(chr(92), 1)[-1], v_ - ab2))
                    print('code addresses on stack:'); shown = 0
                    for v in buf:
                        if inexe(v) and shown < 40: print('   ', near(v)); shown += 1
                    k.TerminateProcess(pi.hp, 1); break
                print('call', hex(addr), '->', tgt[:100], flush=True)
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code in (0x80000004, 0x4000001e) and ev.tid in globals().get('_rearm', {}):   # ENTRY_IF: re-arm after the step
            _a, _o = _rearm.pop(ev.tid)
            bps[_a] = (_o, 'ENTRY')
            k.WriteProcessMemory(pi.hp, ctypes.c_void_p(_a), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(ctypes.c_size_t()))
            k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code in (0x80000004, 0x4000001e) and os.environ.get('WATCH') and trace_tid != ev.tid:
            hw = k.OpenThread(0x1fffff, False, ev.tid); cw = CTX(); cw.Flags = 0x10017; k.Wow64GetThreadContext(hw, ctypes.byref(cw))
            if cw.Dr6 & 1:
                watch_hits += 1
                sb = (ctypes.c_uint32 * 64)(); nn = ctypes.c_size_t(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cw.Esp), sb, 256, ctypes.byref(nn))
                vb = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(int(os.environ['WATCH'], 16)), vb, 4, ctypes.byref(nn))
                print('WATCH write #%d new %08x at %s <- %s' % (watch_hits, vb[0], near(cw.Eip)[:80], ' <- '.join(near(v)[:60] for v in sb if inexe(v))[:600]), flush=True)
                cw.Dr6 = 0; cw.Flags = 0x10010; k.Wow64SetThreadContext(hw, ctypes.byref(cw))
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code in (0x80000004, 0x4000001e) and trace_tid == ev.tid:
            h = k.OpenThread(0x1fffff, False, ev.tid); c3 = CTX(); c3.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c3)); trace.append(c3.Eip); del trace[:-int(os.environ.get('TRACE_KEEP', '60'))]
            c3.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c3))
            k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code == 0xc0000005 and os.environ.get('FASTFWD') and globals().get('ff_n', 0) < int(os.environ.get('FASTFWD') or 0):
            # fast-forward: a call into a null/low address (unresolved symbol, zeroed pointer) -> fake "return 0" to the
            # caller and keep running, logging the site, so one probe shows the next crashes too (diagnostic only)
            hf = k.OpenThread(0x1fffff, False, ev.tid); cf = CTX(); cf.Flags = 0x10007; k.Wow64GetThreadContext(hf, ctypes.byref(cf))
            if cf.Eip < 0x10000:
                rb_ = (ctypes.c_uint32 * 1)(); nn_ = ctypes.c_size_t()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cf.Esp), rb_, 4, ctypes.byref(nn_))
                if inexe(rb_[0]) and globals().get('ff_total', 0) < 2000:
                    globals()['ff_total'] = globals().get('ff_total', 0) + 1
                    _sites = globals().setdefault('ff_sites', set())
                    if rb_[0] not in _sites:   # only NEW sites count toward the limit (a loop repeating one site used it up)
                        _sites.add(rb_[0])
                        globals()['ff_n'] = globals().get('ff_n', 0) + 1
                        print('FASTFWD #%d null call (eip %08x) from %s; faking return 0' % (ff_n, cf.Eip, near(rb_[0] - 5)[:110]), flush=True)
                    cf.Eip = rb_[0]; cf.Esp += 4; cf.Eax = 0; cf.Flags = 0x10007
                    k.Wow64SetThreadContext(hf, ctypes.byref(cf))
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code == 0xc0000005 and os.environ.get('SKIPAV') and globals().get('sk_n', 0) < int(os.environ['SKIPAV']):
            # SKIPAV=N: log the AV site, skip the faulting instruction (a load's destination register := 0) and keep going,
            # so one probe lists the next N crash sites (diagnostic only: state after a skip is not trustworthy)
            hs = k.OpenThread(0x1fffff, False, ev.tid); cs = CTX(); cs.Flags = 0x10007; k.Wow64GetThreadContext(hs, ctypes.byref(cs))
            if inexe(cs.Eip):
                import capstone
                ib = (ctypes.c_ubyte * 16)(); nn_ = ctypes.c_size_t()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cs.Eip), ib, 16, ctypes.byref(nn_))
                ins = next(capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(bytes(ib), cs.Eip), None)
                if ins is not None:
                    _ss = globals().setdefault('sk_sites', set())
                    if cs.Eip not in _ss:
                        _ss.add(cs.Eip); globals()['sk_n'] = globals().get('sk_n', 0) + 1
                        st_ = (ctypes.c_uint32 * 64)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cs.Esp), st_, 256, ctypes.byref(nn_))
                        cl_ = [near(v_)[:80] for v_ in st_ if inexe(v_)][:3]
                        print('SKIPAV #%d %s  [%s %s]  <- %s' % (sk_n, near(cs.Eip)[:100], ins.mnemonic, ins.op_str, ' <- '.join(cl_)), flush=True)
                    dst = ins.op_str.split(',')[0].strip()
                    if ins.mnemonic in ('mov', 'movzx', 'movsx', 'lea', 'add', 'sub', 'and', 'or', 'xor', 'cmp', 'test') and dst in (
                            'eax', 'ecx', 'edx', 'ebx', 'esi', 'edi'):
                        setattr(cs, dst.capitalize(), 0) if ins.mnemonic not in ('cmp', 'test') else None
                    cs.Eip = cs.Eip + ins.size; cs.Flags = 0x10007
                    k.Wow64SetThreadContext(hs, ctypes.byref(cs))
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
            else:   # AV inside the CRT/STL DLLs (a stub's garbage std::string etc.): fake 'return 0' to the nearest exe caller
                _nm = ctypes.create_unicode_buffer(260); ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(cs.Eip), _nm, 260)
                _dll = _nm.value.rsplit(chr(92), 1)[-1].lower()
                st_ = (ctypes.c_uint32 * 256)(); nn_ = ctypes.c_size_t()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cs.Esp), st_, 1024, ctypes.byref(nn_))
                _i = next((i_ for i_, v_ in enumerate(st_) if inexe(v_)), None)
                _any = os.environ.get('SKIPAV_ANY')   # crashlist mode: also a call into NULL and an AV in ANY DLL (rgmain, mfc90...)
                if cs.Eip < 0x10000 and _any and inexe(st_[0]):
                    # `call [vptr+X]` with a null slot / a null function pointer: the return address is on top of the stack
                    globals()['sk_n'] = globals().get('sk_n', 0) + 1
                    print('SKIPAV #%d call to %08x (null) -> fake return 0 to %s' % (sk_n, cs.Eip, near(st_[0])[:100]), flush=True)
                    cs.Eip = st_[0]; cs.Esp += 4; cs.Eax = 0; cs.Flags = 0x10007
                    k.Wow64SetThreadContext(hs, ctypes.byref(cs))
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if (_dll in ('msvcp90.dll', 'msvcr90.dll') or (_any and _dll)) and _i is not None:
                    globals()['sk_n'] = globals().get('sk_n', 0) + 1
                    print('SKIPAV #%d %08x [%s]  -> fake return 0 to %s' % (sk_n, cs.Eip, _dll, near(st_[_i])[:100]), flush=True)
                    cs.Eip = st_[_i]; cs.Esp += 4 * _i + 4; cs.Eax = 0; cs.Flags = 0x10007   # ebp-framed callers restore esp
                    k.Wow64SetThreadContext(hs, ctypes.byref(cs))
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code == 0xc0000005 and os.environ.get('SECOND_CHANCE_ONLY') and struct.unpack('<I', bytes(ev.u[152:156]))[0] == 1:
            hh = k.OpenThread(0x1fffff, False, ev.tid); cc = CTX(); cc.Flags = 0x10007; k.Wow64GetThreadContext(hh, ctypes.byref(cc))
            print('first-chance AV (left to the app) at', near(cc.Eip), flush=True)
            k.ContinueDebugEvent(ev.pid, ev.tid, 0x80010001); continue
        if code not in (0x80000003, 0x4000001f, 0x406d1388, 0x80000004, 0x4000001e) and code != 0xe06d7363:
            h = k.OpenThread(0x1fffff, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            print('exception %08x at %s (tid %d, main %d)' % (code, near(c.Eip), ev.tid, pi.tid))
            print('crash after %.2fs' % (time.time() - T_START))
            nm = ctypes.create_unicode_buffer(520)
            ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(c.Eip), nm, 520)
            mbi = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(c.Eip), mbi, 48)
            allocbase = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mbi))[8:12])[0]
            print('fault rva %08x' % (c.Eip - allocbase))
            print('fault module', nm.value, 'access', struct.unpack('<Q', bytes(ev.u[40:48]))[0], 'addr %08x' % struct.unpack('<Q', bytes(ev.u[48:56]))[0])
            print('eax %08x ecx %08x edx %08x esp %08x ebp %08x ebx %08x esi %08x edi %08x' % (c.Eax, c.Ecx, c.Edx, c.Esp, c.Ebp, c.Ebx, c.Esi, c.Edi))
            for rn_, rv_ in (('eax', c.Eax), ('ecx', c.Ecx), ('edx', c.Edx), ('ebx', c.Ebx), ('esi', c.Esi), ('edi', c.Edi)):
                w_ = (ctypes.c_uint32 * 4)(); nn_ = ctypes.c_size_t()   # first words at each register: object vtables
                if rv_ > 0x10000 and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(rv_), w_, 16, ctypes.byref(nn_)):
                    print('  [%s] %s' % (rn_, ' '.join('%08x %s' % (v_, near(v_)[:70]) for v_ in w_)))
            if os.environ.get('STACKPRE'):   # words just BELOW esp: the popped return address and the callee's leftovers
                sp_ = (ctypes.c_uint32 * 32)(); nn_ = ctypes.c_size_t()
                if k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp - 0x60), sp_, 128, ctypes.byref(nn_)):
                    for i_, v_ in enumerate(sp_):
                        print('  pre %+04x %08x %s' % (i_ * 4 - 0x60, v_, near(v_)[:90] if inexe(v_) else ''))
            if os.environ.get('STACKMODS'):   # every stack dword that points into a loaded module: module+offset (which DLL jumped where)
                sb = (ctypes.c_uint32 * 512)(); nn = ctypes.c_size_t()
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), sb, 2048, ctypes.byref(nn))
                for i_, v_ in enumerate(sb):
                    if v_ < 0x10000:
                        continue
                    nm2 = ctypes.create_unicode_buffer(520)
                    if ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(v_), nm2, 520):
                        mb2 = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(v_), mb2, 48)
                        ab2 = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mb2))[8:12])[0]
                        pr2 = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mb2))[36:40])[0]
                        if pr2 & 0xF0:   # executable page
                            print('  smod esp+%03x %08x %s+%x' % (4 * i_, v_, nm2.value.rsplit(chr(92), 1)[-1], v_ - ab2))
            try:   # SEH chain of the faulting thread (WOW64: TEB32 = TEB64 + WowTebOffset at +0x180c)
                class TBI(ctypes.Structure): _fields_ = [('st', ctypes.c_long), ('teb', ctypes.c_uint64), ('pid', ctypes.c_uint64), ('tid', ctypes.c_uint64), ('aff', ctypes.c_uint64), ('pri', ctypes.c_long), ('bpri', ctypes.c_long)]
                tbi = TBI(); ctypes.WinDLL('ntdll').NtQueryInformationThread(h, 0, ctypes.byref(tbi), ctypes.sizeof(tbi), None)
                def rd32(a):
                    b_ = ctypes.c_uint32(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(a), ctypes.byref(b_), 4, ctypes.byref(ctypes.c_size_t())); return b_.value
                wow = rd32(tbi.teb + 0x180c); teb32 = (tbi.teb + wow - (1 << 32)) if wow > 0x7fffffff else tbi.teb + wow
                rec = rd32(teb32); n_ = 0
                print('seh chain (teb32 %x):' % teb32)
                while rec not in (0, 0xffffffff) and n_ < 24:
                    print('   rec %08x next %08x handler %s' % (rec, rd32(rec), near(rd32(rec + 4)))); rec = rd32(rec); n_ += 1
            except Exception as e_: print('seh chain failed', e_)
            _cache = {}
            def _mod(a_):
                k_ = a_ >> 16
                if k_ not in _cache:
                    nm_ = ctypes.create_unicode_buffer(260)
                    _cache[k_] = (nm_.value.split(chr(92))[-1] if ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(a_), nm_, 260) else 'heap/none')
                return _cache[k_]
            for a_ in trace: print('  trace', near(a_) if inexe(a_) else '%08x [%s]' % (a_, _mod(a_)))
            for pk in filter(None, os.environ.get('PEEK', '').split(',')):
                pb = (ctypes.c_uint32 * 64)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Eip if pk == 'eip' else (c.Esp if pk == 'esp' else int(pk, 16))), pb, 256, ctypes.byref(ctypes.c_size_t()))
                print('peek', pk, ' '.join('%08x' % v for v in pb))
            buf = (ctypes.c_uint32 * 2048)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), buf, 8192, ctypes.byref(n))
            shown = 0
            for v in buf:
                if inexe(v) and shown < 60: print('  stack', near(v)); shown += 1
            status = 0x80010001
            k.TerminateProcess(pi.hp, 1); break
        if code == 0xe06d7363 and cxx_seen < 12:
            cxx_seen += 1
            h = k.OpenThread(0x1fffff, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            buf = (ctypes.c_uint32 * 2048)(); n = ctypes.c_size_t()   # 8 KB: throws from inside the CRT sit deep
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), buf, 8192, ctypes.byref(n))
            # thrown type: ExceptionInformation[2] = ThrowInfo -> CatchableTypeArray -> first CatchableType -> TypeDescriptor
            _tn = '?'
            try:
                _w = struct.unpack('<40I', bytes(ev.u[:160]))
                _mi = next(i for i, x in enumerate(_w) if x in (0x19930520, 0x19930521, 0x19930522))   # magic, then object, then ThrowInfo
                _st = 2 if (_mi + 2 < len(_w) and _w[_mi + 1] == 0) else 1   # 64-bit ULONG_PTR slots (high half 0)
                _ti = _w[_mi + 2 * _st]
                _r4 = lambda a_: (lambda b_: (k.ReadProcessMemory(pi.hp, ctypes.c_void_p(a_), b_, 4, ctypes.byref(ctypes.c_size_t())), b_[0])[1])((ctypes.c_uint32 * 1)())
                _cta = _r4(_ti + 12); _ct = _r4(_cta + 4); _td = _r4(_ct + 4)
                _nb = ctypes.create_string_buffer(120)
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_td + 8), _nb, 120, ctypes.byref(ctypes.c_size_t()))
                _tn = _nb.raw.split(b'\0', 1)[0].decode('latin-1')
                # the thrown OBJECT's text (Ogre::Exception description/source, std::exception what): ASCII runs inline
                # (std::string short buffers) and behind any pointer field (heap strings)
                _ob = _w[_mi + _st]
                _obb = ctypes.create_string_buffer(0x80)
                k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_ob), _obb, 0x80, ctypes.byref(ctypes.c_size_t()))
                _txt = [m_.group(0).decode('latin-1') for m_ in re.finditer(rb'[ -~]{6,}', _obb.raw)]
                for _o in range(0, 0x80, 4):
                    _p = struct.unpack_from('<I', _obb.raw, _o)[0]
                    if _p > 0x10000:
                        _sb = ctypes.create_string_buffer(240)
                        if k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_p), _sb, 240, ctypes.byref(ctypes.c_size_t())):
                            _m = re.match(rb'[ -~\t\r\n]{6,}', _sb.raw)
                            if _m:
                                _txt.append(_m.group(0).decode('latin-1'))
                _tn += (' text: ' + ' | '.join(_txt)[:600]) if _txt else ''
            except Exception:
                pass
            print('C++ throw #%d (type %s, thread %d%s); code addresses on stack:' % (cxx_seen, _tn, ev.tid, ' main' if ev.tid == pi.tid else ''))
            shown = 0
            for v in buf:
                if inexe(v) and shown < 14: print('   ', near(v)); shown += 1
            if os.environ.get('CXXSTACK'):   # also DLL frames (module+offset): throws from MFC/MSVCP DLLs show no exe frame
                _p = ctypes.WinDLL('psapi')
                for i_, v_ in enumerate(buf[:600]):
                    nm2 = ctypes.create_unicode_buffer(260)
                    if v_ > 0x10000 and not (inexe(v_)) and _p.GetMappedFileNameW(pi.hp, ctypes.c_void_p(v_), nm2, 260):
                        print('    esp+%03x %08x %s' % (4 * i_, v_, nm2.value.rsplit(chr(92), 1)[-1]))
        status = 0x10002 if code in (0x80000003, 0x4000001f, 0x406d1388) else 0x80010001
    elif ev.code == 8:  # OUTPUT_DEBUG_STRING_INFO: pointer, unicode flag, length
        ptr, uni, ln = struct.unpack('<QHH', bytes(ev.u[:12]))   # 64-bit debugger: the string pointer is 8 bytes
        buf = ctypes.create_string_buffer(ln * (2 if uni else 1)); n = ctypes.c_size_t()
        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(ptr), buf, len(buf), ctypes.byref(n))
        print('DEBUGSTR:', buf.raw.decode('utf-16le' if uni else 'latin-1', 'replace').strip()[:300])
    elif ev.code == 3:   # CREATE_PROCESS_DEBUG_INFO: hFile, hProcess, hThread, lpBaseOfImage
        delta = struct.unpack('<Q', bytes(ev.u[24:32]))[0] - base
        print('image base %08x (delta %+x)' % (base + delta, delta), flush=True)
    elif ev.code == 5:
        print('process exited', struct.unpack('<I', bytes(ev.u[:4]))[0]); break
    k.ContinueDebugEvent(ev.pid, ev.tid, status)
else:
    for a_ in trace: print('  trace', near(a_))   # single-step trace tail when the run ends without a crash
    try:   # where is every thread when the run ends?
        snap = ctypes.WinDLL('kernel32').CreateToolhelp32Snapshot(4, 0)
        class TE(ctypes.Structure): _fields_ = [('sz', w.DWORD), ('us', w.DWORD), ('tid', w.DWORD), ('owner', w.DWORD), ('bp', w.LONG), ('dp', w.LONG), ('fl', w.DWORD)]
        te = TE(); te.sz = ctypes.sizeof(te); ok_ = ctypes.WinDLL('kernel32').Thread32First(snap, ctypes.byref(te))
        while ok_:
            if te.owner == pi.pid:
                ht_ = k.OpenThread(0x1fffff, False, te.tid); cx_ = CTX(); cx_.Flags = 0x10007
                k.SuspendThread(ht_); k.Wow64GetThreadContext(ht_, ctypes.byref(cx_))
                nm_ = ctypes.create_unicode_buffer(260); ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(cx_.Eip), nm_, 260)
                print('thread %d%s eip %08x %s esp %08x' % (te.tid, ' (main)' if te.tid == pi.tid else '', cx_.Eip, nm_.value.split(chr(92))[-1], cx_.Esp))
                if te.tid == pi.tid:
                    sb = (ctypes.c_uint32 * 512)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cx_.Esp), sb, 2048, ctypes.byref(ctypes.c_size_t()))
                    sh = 0; shm = 0; psp = ctypes.WinDLL('psapi')
                    for v_ in sb[:400]:
                        if v_ > 0x10000 and v_ < 0x7ff00000 and not (inexe(v_)) and shm < 24:
                            nm2 = ctypes.create_unicode_buffer(260)
                            if psp.GetMappedFileNameW(pi.hp, ctypes.c_void_p(v_), nm2, 260) and nm2.value.lower().endswith('.dll'):
                                print('     main stack mod %08x %s' % (v_, nm2.value.split(chr(92))[-1])); shm += 1
                    for v_ in sb:
                        if inexe(v_) and sh < 14: print('     main stack', near(v_)); sh += 1
            ok_ = ctypes.WinDLL('kernel32').Thread32Next(snap, ctypes.byref(te))
    except Exception as e_: print('thread dump failed', e_)
    try:   # list this process's top-level windows on the probe desktop
        CB2 = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM); rows_ = []
        def cb2(h, l):
            p_ = w.DWORD(); u32.GetWindowThreadProcessId(h, ctypes.byref(p_))
            if p_.value == pi.pid:
                t_ = ctypes.create_unicode_buffer(128); c_ = ctypes.create_unicode_buffer(64); u32.GetWindowTextW(h, t_, 128); u32.GetClassNameW(h, c_, 64)
                rows_.append('%x vis=%d class=%s title=%r' % (h, u32.IsWindowVisible(h), c_.value, t_.value))
            return True
        u32.EnumDesktopWindows(_hd, CB2(cb2), 0) if not os.environ.get('ROC_PROBE_VISIBLE') else u32.EnumWindows(CB2(cb2), 0)
        print('windows:'); [print('  ' + r_) for r_ in rows_]
    except Exception as e_: print('window list failed', e_)
    print('no crash within time; terminating'); k.TerminateProcess(pi.hp, 0)
