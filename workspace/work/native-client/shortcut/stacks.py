"""Start EXE normally, wait, then print each thread's EIP and the exe-range code addresses on its stack (no debugger).
python stacks.py EXE MAP [wait_seconds]"""
import ctypes, ctypes.wintypes as w, re, subprocess, sys, struct, time, bisect, os
exe, mapf = sys.argv[1], sys.argv[2]; wait = float(sys.argv[3]) if len(sys.argv) > 3 else 8
txt = open(mapf, errors='replace').read(); syms = []
for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', txt, re.M): syms.append((int(m.group(2), 16), m.group(1)))
syms.sort(); keys = [s[0] for s in syms]
def near(a):
    i = bisect.bisect_right(keys, a) - 1
    return '%08x %s+%x' % (a, syms[i][1][:80], a - syms[i][0]) if i >= 0 else '%08x' % a
k = ctypes.WinDLL('kernel32', use_last_error=True)
proc = subprocess.Popen([exe], cwd=os.path.dirname(os.path.abspath(exe)))
time.sleep(wait)
import atexit; atexit.register(proc.kill)
class CTX(ctypes.Structure):
    _fields_ = [('Flags', w.DWORD)] + [(n, w.DWORD) for n in ('Dr0','Dr1','Dr2','Dr3','Dr6','Dr7')] + [('fc', ctypes.c_byte * 112)] + \
        [(n, w.DWORD) for n in ('SegGs','SegFs','SegEs','SegDs','Edi','Esi','Ebx','Edx','Ecx','Eax','Ebp','Eip','SegCs','EFlags','Esp','SegSs')] + [('ext', ctypes.c_byte * 512)]
class TE(ctypes.Structure):
    _fields_ = [('sz', w.DWORD), ('usage', w.DWORD), ('tid', w.DWORD), ('owner', w.DWORD), ('base', w.LONG), ('delta', w.LONG), ('flags', w.DWORD)]
snap = k.CreateToolhelp32Snapshot(4, 0); te = TE(); te.sz = ctypes.sizeof(te)
hp = k.OpenProcess(0x1fffff, False, proc.pid); ok = k.Thread32First(snap, ctypes.byref(te))
while ok:
    if te.owner == proc.pid:
        h = k.OpenThread(0x1fffff, False, te.tid); k.Wow64SuspendThread(h)
        c = CTX(); c.Flags = 0x10007
        if k.Wow64GetThreadContext(h, ctypes.byref(c)):
            buf = (ctypes.c_uint32 * 1024)(); n = ctypes.c_size_t()
            k.ReadProcessMemory(hp, ctypes.c_void_p(c.Esp), buf, 4096, ctypes.byref(n))
            print('thread %d eip %08x' % (te.tid, c.Eip), near(c.Eip) if 0x401000 <= c.Eip < 0x980000 else '')
            shown = 0
            for v in buf:
                if 0x401000 <= v < 0x980000 and shown < 30: print('    ', near(v)); shown += 1
        k.ResumeThread(h)
    ok = k.Thread32Next(snap, ctypes.byref(te))

proc.kill()
