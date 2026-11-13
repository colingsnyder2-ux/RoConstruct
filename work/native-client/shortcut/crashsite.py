"""Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest
symbols from the link map. python crashsite.py EXE MAP [seconds]"""
import ctypes, ctypes.wintypes as w, re, subprocess, sys, struct, time
exe, mapf = sys.argv[1], sys.argv[2]
k = ctypes.WinDLL('kernel32', use_last_error=True)
class SI(ctypes.Structure):
    _fields_ = [('cb', w.DWORD)] + [(n, w.LPVOID) for n in ('r', 'd', 't')] + [(n, w.DWORD) for n in
        ('x', 'y', 'xs', 'ys', 'xc', 'yc', 'fill', 'flags')] + [('sw', w.WORD), ('cb2', w.WORD), ('r2', w.LPVOID),
        ('i', w.HANDLE), ('o', w.HANDLE), ('e', w.HANDLE)]
class PI(ctypes.Structure):
    _fields_ = [('hp', w.HANDLE), ('ht', w.HANDLE), ('pid', w.DWORD), ('tid', w.DWORD)]
si, pi = SI(), PI(); si.cb = ctypes.sizeof(si)
import os
if not k.CreateProcessW(exe, None, None, None, False, 1, None, os.path.dirname(os.path.abspath(exe)), ctypes.byref(si), ctypes.byref(pi)):
    raise SystemExit('create failed %d' % ctypes.get_last_error())
class CTX(ctypes.Structure):  # WOW64_CONTEXT
    _fields_ = [('Flags', w.DWORD)] + [(n, w.DWORD) for n in ('Dr0','Dr1','Dr2','Dr3','Dr6','Dr7')] + \
        [('fc', ctypes.c_byte * 112)] + [(n, w.DWORD) for n in ('SegGs','SegFs','SegEs','SegDs','Edi','Esi','Ebx','Edx','Ecx','Eax','Ebp','Eip','SegCs','EFlags','Esp','SegSs')] + [('ext', ctypes.c_byte * 512)]
import capstone
BPSYM = os.environ.get('BPFUNC')
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
def arm_bps():
    if not BPSYM: return
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
ev = EV(); deadline = time.time() + float(sys.argv[3] if len(sys.argv) > 3 else 20); first = True; ids = {}
while time.time() < deadline:
    if not k.WaitForDebugEvent(ctypes.byref(ev), 500):
        continue
    status = 0x10002
    if ev.code == 1:  # exception
        rec = bytes(ev.u[:24]); code, flags, _, addr = struct.unpack('<IIQQ', rec[:24])
        first_chance = struct.unpack('<I', bytes(ev.u[80:84]))[0] if False else None
        if code in (0x80000003, 0x4000001f):
            if code == 0x80000003 and not armed:
                armed = True; arm_bps()
            elif addr in bps:
                old, tgt = bps.pop(addr)
                k.WriteProcessMemory(pi.hp, ctypes.c_void_p(addr), (ctypes.c_ubyte * 1)(old), 1, ctypes.byref(ctypes.c_size_t()))
                h = k.OpenThread(0x1fffff, False, ev.tid); c2 = CTX(); c2.Flags = 0x10007
                k.Wow64GetThreadContext(h, ctypes.byref(c2)); c2.Eip = addr; k.Wow64SetThreadContext(h, ctypes.byref(c2))
                print('call', hex(addr), '->', tgt[:100], flush=True)
                k.ContinueDebugEvent(ev.pid, ev.tid, 0x10002); continue
        if code not in (0x80000003, 0x4000001f, 0x406d1388) and code != 0xe06d7363:
            h = k.OpenThread(0x1fffff, False, ev.tid); c = CTX(); c.Flags = 0x10007
            k.Wow64GetThreadContext(h, ctypes.byref(c))
            print('exception %08x at %s' % (code, near(c.Eip)))
            nm = ctypes.create_unicode_buffer(520)
            ctypes.WinDLL('psapi').GetMappedFileNameW(pi.hp, ctypes.c_void_p(c.Eip), nm, 520)
            mbi = (ctypes.c_byte * 48)(); k.VirtualQueryEx(pi.hp, ctypes.c_void_p(c.Eip), mbi, 48)
            allocbase = struct.unpack('<I', bytes(bytearray(b & 0xff for b in mbi))[8:12])[0]
            print('fault rva %08x' % (c.Eip - allocbase))
            print('fault module', nm.value, 'access', struct.unpack('<Q', bytes(ev.u[40:48]))[0], 'addr %08x' % struct.unpack('<Q', bytes(ev.u[48:56]))[0])
            print('eax %08x ecx %08x edx %08x esp %08x ebp %08x' % (c.Eax, c.Ecx, c.Edx, c.Esp, c.Ebp))
            buf = (ctypes.c_uint32 * 128)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(pi.hp, ctypes.c_void_p(c.Esp), buf, 512, ctypes.byref(n))
            for v in buf:
                if 0x401000 <= v < 0x980000: print('  stack', near(v))
            status = 0x80010001
            k.TerminateProcess(pi.hp, 1); break
        if code == 0xe06d7363: pass
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
    print('no crash within time; terminating'); k.TerminateProcess(pi.hp, 0)
