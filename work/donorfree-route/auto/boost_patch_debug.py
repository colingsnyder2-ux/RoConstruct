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
def near(a):
    i = bisect.bisect_right(keys, a) - 1
    return '%08x %s+%x' % (a, syms[i][1][:90], a - syms[i][0]) if i >= 0 else '%08x' % a
class EV(ctypes.Structure):
    _fields_ = [('code', w.DWORD), ('pid', w.DWORD), ('tid', w.DWORD), ('pad', w.DWORD), ('u', ctypes.c_ubyte * 160)]
bps = {}
trace_tid = None
trace = []
def arm_imports():
    """BPIMP=name,name: break on the CRT functions an import slot points to (e.g. _invalid_parameter_noinfo, which ends the
    process with 0xC0000417 and no exception event) and print the caller stack. Imports are bound at the loader breakpoint."""
    n = ctypes.c_size_t()
    for nm in filter(None, os.environ.get('BPIMP', '').split(',')):
        slot = [v for v, s_ in syms if s_ in ('__imp_' + nm, '__imp__' + nm)]
        if not slot:
            continue
        p_ = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(slot[0]), p_, 4, ctypes.byref(n))
        tgt = p_[0]; old = (ctypes.c_ubyte * 1)()
        if tgt and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(tgt), old, 1, ctypes.byref(n)):
            bps[tgt] = (old[0], 'ENTRY'); k.WriteProcessMemory(pi.hp, ctypes.c_void_p(tgt), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
            print('armed import breakpoint', nm, hex(tgt))
def arm_bps():
    if os.environ.get('BPLIST'):   # one-shot entry breakpoints 'ADDR LABEL' per line: first-call order trace (difftrace.py)
        n = ctypes.c_size_t(); cnt = 0
        for line in open(os.environ['BPLIST']):
            parts = line.split()
            if len(parts) < 2:
                continue
            va = int(parts[0], 16); old = (ctypes.c_ubyte * 1)()
            if k.ReadProcessMemory(pi.hp, ctypes.c_void_p(va), old, 1, ctypes.byref(n)):
                bps[va] = (old[0], 'STUB HIT ' + parts[1]); cnt += 1
                k.WriteProcessMemory(pi.hp, ctypes.c_void_p(va), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
        print('armed', cnt, 'trace breakpoints'); return
    if os.environ.get('BPSTUBS'):
        n = ctypes.c_size_t(); cnt = 0
        for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})(?: f)?(?: i)?\s+(?:\S+:)?stubs\.obj', txt, re.M):
            va = int(m.group(2), 16); old = (ctypes.c_ubyte * 1)()
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(va), old, 1, ctypes.byref(n))
            if va in bps: continue
            bps[va] = (old[0], 'STUB ' + m.group(1)); cnt += 1
            k.WriteProcessMemory(pi.hp, ctypes.c_void_p(va), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
        print('armed', cnt, 'stub breakpoints'); return
    if not BPSYM: return
    if os.environ.get('BPENTRY'):
        _be = os.environ['BPENTRY']
        ent = [int(_be, 16)] if re.fullmatch(r'(?:0x)?[0-9a-fA-F]{6,8}', _be) else [v for v, n in syms if n == _be]
        if not ent: print('BPENTRY not in map'); return
        old = (ctypes.c_ubyte * 1)(); n = ctypes.c_size_t()
        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(ent[0]), old, 1, ctypes.byref(n))
        bps[ent[0]] = (old[0], 'ENTRY')
        k.WriteProcessMemory(pi.hp, ctypes.c_void_p(ent[0]), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(n))
        print('armed entry breakpoint'); return
    start = [v for v, n in syms if n == BPSYM]
    if not start: print('BPFUNC not in map'); return
    st = start[0]; nxt = [v for v, n in syms if v > st]; end = min(nxt[0], st + 0x2000) if nxt else st + 0x2000
    raw = (ctypes.c_ubyte * (end - st))(); n = ctypes.c_size_t()
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
        post_cmd(pending.pop(0)); posted_n += 1
    posted = True
    if not k.WaitForDebugEvent(ctypes.byref(ev), 500):
        continue
    status = 0x10002
    if ev.code == 1:  # exception
        rec = bytes(ev.u[:24]); code, flags, _, addr = struct.unpack('<IIQQ', rec[:24])
        first_chance = struct.unpack('<I', bytes(ev.u[80:84]))[0] if False else None
        if code in (0x80000003, 0x4000001f):
            if code == 0x4000001f and not globals().get('imp_armed'):   # WoW64 loader breakpoint: 32-bit imports now bound
                imp_armed = True; arm_imports()
                k.VirtualProtectEx.argtypes=[w.HANDLE,ctypes.c_void_p,ctypes.c_size_t,w.DWORD,ctypes.POINTER(w.DWORD)]
                oldprot=w.DWORD(); k.VirtualProtectEx(pi.hp,ctypes.c_void_p(0x0080e67c),4,0x40,ctypes.byref(oldprot))
                for addr, value in ((0x00bc1560,0x00589610),(0x00bc1564,0x00589600),(0x0080e67c,0x00614860),(0x0080e678,0x00614740),(0x00ccf560,1)):
                    v=ctypes.c_uint32(value); nw=ctypes.c_size_t(); ok=k.WriteProcessMemory(pi.hp,ctypes.c_void_p(addr),ctypes.byref(v),4,ctypes.byref(nw)); print('diagnostic table',hex(addr),hex(value),ok,flush=True)
                if os.environ.get('WATCH'):   # hardware write watchpoint: armed at the exe entry (set at the loader break it is lost)
                    watch_hits = 0
                    _ea = [v for v, n_ in syms if n_ in ('_WinMainCRTStartup', '_wWinMainCRTStartup')]
                    if _ea:
                        _ob = (ctypes.c_ubyte * 1)(); _nn = ctypes.c_size_t()
                        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(_ea[0]), _ob, 1, ctypes.byref(_nn))
                        bps[_ea[0]] = (_ob[0], 'WATCHARM')
                        k.WriteProcessMemory(pi.hp, ctypes.c_void_p(_ea[0]), (ctypes.c_ubyte * 1)(0xCC), 1, ctypes.byref(_nn))
                if addr not in bps:
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
            if code == 0x80000003 and not armed:
                armed = True; arm_bps()
            elif addr in bps:
                old, tgt = bps.pop(addr)
                k.WriteProcessMemory(pi.hp, ctypes.c_void_p(addr), (ctypes.c_ubyte * 1)(old), 1, ctypes.byref(ctypes.c_size_t()))
                h = k.OpenThread(0x1fffff, False, ev.tid); c2 = CTX(); c2.Flags = 0x10007
                k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                if tgt == 'WATCHARM':
                    c2.Flags = 0x10017; k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr
                    c2.Dr0 = int(os.environ['WATCH'], 16); c2.Dr7 = 0x000D0001; c2.Flags = 0x10017
                    print('watch armed', os.environ['WATCH'], bool(k.Wow64SetThreadContext(h, ctypes.byref(c2))), flush=True)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt.startswith('STUB '):
                    rb = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), rb, 4, ctypes.byref(ctypes.c_size_t()))
                    print('STUB', tgt[5:90], '<-', near(rb[0])[:90], flush=True)
                    if os.environ.get('TRACE_AFTER') and os.environ['TRACE_AFTER'] in tgt:
                        c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2)); trace_tid = ev.tid; trace = []
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY' and os.environ.get('TRACE_ENTRY'):   # single-step from this entry to the crash
                    c2.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c2)); trace_tid = ev.tid; trace = []
                    print('ENTRY hit: tracing', flush=True)
                    k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
                if tgt == 'ENTRY':
                    n2 = ctypes.c_size_t(); buf = (ctypes.c_uint32 * 256)()
                    k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c2.Esp), buf, 1024, ctypes.byref(n2))
                    print('ENTRY hit (eip %08x) eax %08x ecx %08x edx %08x esi %08x edi %08x ebp %08x' % (addr, c2.Eax, c2.Ecx, c2.Edx, c2.Esi, c2.Edi, c2.Ebp))
                    for rn in ('Ecx', 'Esi', 'Edi', 'Ebp'):   # 24 bytes at each pointer register, and what its first word points at
                        rv = getattr(c2, rn); mb = (ctypes.c_uint32 * 6)()
                        if 0x10000 < rv < 0x7fff0000 and k.ReadProcessMemory(pi.hp, ctypes.c_void_p(rv), mb, 24, ctypes.byref(n2)):
                            mb2 = (ctypes.c_uint32 * 4)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(mb[0]), mb2, 16, ctypes.byref(n2))
                            print('   [%s] %s | [[%s]] %s' % (rn, ' '.join('%08x' % x for x in mb), rn, ' '.join('%08x' % x for x in mb2)))
                    print('code addresses on stack:'); shown = 0
                    for v in buf:
                        if 0x401000 <= v < 0x980000 and shown < 40: print('   ', near(v)); shown += 1
                    k.TerminateProcess(pi.hp, 1); break
                print('call', hex(addr), '->', tgt[:100], flush=True)
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code in (0x80000004, 0x4000001e) and os.environ.get('WATCH') and trace_tid != ev.tid:
            hw = k.OpenThread(0x1fffff, False, ev.tid); cw = CTX(); cw.Flags = 0x10017; k.Wow64GetThreadContext(hw, ctypes.byref(cw))
            if cw.Dr6 & 1:
                watch_hits += 1
                sb = (ctypes.c_uint32 * 64)(); nn = ctypes.c_size_t(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(cw.Esp), sb, 256, ctypes.byref(nn))
                vb = (ctypes.c_uint32 * 1)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(int(os.environ['WATCH'], 16)), vb, 4, ctypes.byref(nn))
                print('WATCH write #%d new %08x at %s <- %s' % (watch_hits, vb[0], near(cw.Eip)[:80], ' <- '.join(near(v)[:60] for v in sb if 0x401000 <= v < 0x980000)[:600]), flush=True)
                cw.Dr6 = 0; cw.Flags = 0x10010; k.Wow64SetThreadContext(hw, ctypes.byref(cw))
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code in (0x80000004, 0x4000001e) and trace_tid == ev.tid:
            h = k.OpenThread(0x1fffff, False, ev.tid); c3 = CTX(); c3.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c3)); trace.append(c3.Eip); del trace[:-int(os.environ.get('TRACE_KEEP', '60'))]
            c3.EFlags |= 0x100; k.Wow64SetThreadContext(h, ctypes.byref(c3))
            k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code == 0xc0000005 and os.environ.get('SECOND_CHANCE_ONLY') and struct.unpack('<I', bytes(ev.u[152:156]))[0] == 1:
            hh = k.OpenThread(0x1fffff, False, ev.tid); cc = CTX(); cc.Flags = 0x10007; k.Wow64GetThreadContext(hh, ctypes.byref(cc))
            print('first-chance AV (left to the app) at', near(cc.Eip), flush=True)
            k.ContinueDebugEvent(ev.pid, ev.tid, 0x80010001); continue
        if code not in (0x80000003, 0x4000001f, 0x406d1388, 0x80000004, 0x4000001e) and code != 0xe06d7363:
            h = k.OpenThread(0x1fffff, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            print('exception %08x at %s (tid %d, main %d)' % (code, near(c.Eip), ev.tid, pi.tid))
            nm = ctypes.create_unicode_buffer(520)
            ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(c.Eip), nm, 520)
            mbi = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(c.Eip), mbi, 48)
            allocbase = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mbi))[8:12])[0]
            print('fault rva %08x' % (c.Eip - allocbase))
            print('fault module', nm.value, 'access', struct.unpack('<Q', bytes(ev.u[40:48]))[0], 'addr %08x' % struct.unpack('<Q', bytes(ev.u[48:56]))[0])
            print('eax %08x ecx %08x edx %08x esp %08x ebp %08x' % (c.Eax, c.Ecx, c.Edx, c.Esp, c.Ebp))
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
            for a_ in trace: print('  trace', near(a_) if 0x401000 <= a_ < 0x980000 else '%08x [%s]' % (a_, _mod(a_)))
            for pk in filter(None, os.environ.get('PEEK', '').split(',')):
                pb = (ctypes.c_uint32 * 64)(); k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Eip if pk == 'eip' else (c.Esp if pk == 'esp' else int(pk, 16))), pb, 256, ctypes.byref(ctypes.c_size_t()))
                print('peek', pk, ' '.join('%08x' % v for v in pb))
            buf = (ctypes.c_uint32 * 2048)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), buf, 8192, ctypes.byref(n))
            shown = 0
            for v in buf:
                if 0x401000 <= v < 0x980000 and shown < 60: print('  stack', near(v)); shown += 1
            status = 0x80010001
            k.TerminateProcess(pi.hp, 1); break
        if code == 0xe06d7363 and cxx_seen < 12:
            cxx_seen += 1
            h = k.OpenThread(0x1fffff, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            buf = (ctypes.c_uint32 * 192)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), buf, 768, ctypes.byref(n))
            print('C++ throw #%d; code addresses on stack:' % cxx_seen)
            shown = 0
            for v in buf:
                if 0x401000 <= v < 0x980000 and shown < 14: print('   ', near(v)); shown += 1
        status = 0x10002 if code in (0x80000003, 0x4000001f, 0x406d1388) else 0x80010001
    elif ev.code == 8:  # OUTPUT_DEBUG_STRING_INFO: pointer, unicode flag, length
        ptr, uni, ln = struct.unpack('<IHH', bytes(ev.u[:8]))
        buf = ctypes.create_string_buffer(ln * (2 if uni else 1)); n = ctypes.c_size_t()
        k.ReadProcessMemory(pi.hp, ctypes.c_void_p(ptr), buf, len(buf), ctypes.byref(n))
        print('DEBUGSTR:', buf.raw.decode('utf-16le' if uni else 'latin-1', 'replace').strip()[:300])
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
                        if v_ > 0x10000 and v_ < 0x7ff00000 and not (0x401000 <= v_ < 0x980000) and shm < 24:
                            nm2 = ctypes.create_unicode_buffer(260)
                            if psp.GetMappedFileNameW(pi.hp, ctypes.c_void_p(v_), nm2, 260) and nm2.value.lower().endswith('.dll'):
                                print('     main stack mod %08x %s' % (v_, nm2.value.split(chr(92))[-1])); shm += 1
                    for v_ in sb:
                        if 0x401000 <= v_ < 0x980000 and sh < 14: print('     main stack', near(v_)); sh += 1
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
