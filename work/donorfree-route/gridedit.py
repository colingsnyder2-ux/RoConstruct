"""python gridedit.py [EXE] [--orig] [--class Part] [--rows N]: property-grid EDIT test (FEATURE_LADDER T1 "change a property
in the Properties grid"). Launches the client with a -script that inserts one object named GE_<class> into Workspace,
selects it in the Explorer tree (TVM_SELECTITEM -> CSelectionPropGrid fills), then walks the grid's list rows: select
row i (LB_SETCURSEL), type a value (WM_CHAR) to open the in-place editor, press Enter (commit -> PropertyDescriptor::
setStringValue path). Reports the first row whose edit kills the client. --orig runs the original too.
Writes auto/gridedit.json."""
import ctypes, ctypes.wintypes as w, json, os, struct, subprocess, sys, time
from pathlib import Path
import ieclean
FAULTS = []
H = Path(__file__).parent
u, k = ctypes.WinDLL('user32'), ctypes.WinDLL('kernel32')
k.VirtualAllocEx.restype = ctypes.c_void_p
k.VirtualAllocEx.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_size_t, w.DWORD, w.DWORD]
k.WriteProcessMemory.argtypes = k.ReadProcessMemory.argtypes = [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p]
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
a = sys.argv[1:]
EXE = os.path.abspath(next((x for x in a if x.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
CLS = a[a.index('--class') + 1] if '--class' in a else 'Part'
SETUP = {'Part': 'o.Anchored=true o.Position=Vector3.new(0,6,0)'}


def cls(h):
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128); return c.value


def snd(h, m, wp=0, lp=0, a_=False):
    r = ctypes.c_size_t(0)
    f = u.SendMessageTimeoutA if a_ else u.SendMessageTimeoutW
    return r.value if f(h, m, ctypes.c_size_t(wp), ctypes.c_ssize_t(lp), 2, 3000, ctypes.byref(r)) else None


def children(top):
    out = []
    def cb(c, _):
        out.append(c); return True
    u.EnumChildWindows(top, P(cb), 0); return out


def run(exe, klass, maxrows=80, dump=False):
    ieclean.clean()
    lua = 'local o=Instance.new("%s") o.Name="GE_%s" %s o.Parent=workspace' % (klass, klass, SETUP.get(klass, ''))
    p = subprocess.Popen([exe, '-script', lua], cwd=os.path.dirname(exe))
    if '--frida' in a:
        import frida
        global _fs
        EXTRA = open(os.environ['GE_HOOK']).read() if os.environ.get('GE_HOOK') else ''
        _fs = frida.attach(p.pid).create_script('var EXTRA=' + json.dumps(EXTRA) + ';' + '''Process.setExceptionHandler(function(e){ if(e.type!=='access-violation') return false;
          var st=Thread.backtrace(e.context, Backtracer.FUZZY).map(function(x){return x.toString();});
          var raw=[]; for(var i=0;i<64;i++){ try{ raw.push(e.context.esp.add(i*4).readU32().toString(16)); }catch(_){} }
          var mm=Process.findModuleByAddress(e.address); send({mod: mm? mm.name+'+'+e.address.sub(mm.base): null, pc:e.address.toString(), ecx:e.context.ecx.toString(), eax:e.context.eax.toString(), esi:e.context.esi.toString(), edi:e.context.edi.toString(), mem:e.memory?e.memory.address.toString():null, st:st, raw:raw}); return false; });
          if (EXTRA) eval(EXTRA);''')
        _fs.on('message', lambda m, d: FAULTS.append(m.get('payload', m)))
        _fs.load()
    hp = k.OpenProcess(0x1F0FFF, False, p.pid); mem = k.VirtualAllocEx(hp, None, 4096, 0x3000, 4)
    def tops():
        out = []
        def cb(h, _):
            q = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(q))
            if q.value == p.pid and u.IsWindowVisible(h) and cls(h).startswith('Afx:'): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out
    def text(t, it):
        k.WriteProcessMemory(hp, mem, struct.pack('<IIIIIIIIII', 1, it, 0, 0, mem + 512, 256, 0, 0, 0, 0), 40, None)
        snd(t, 0x110C, 0, mem, a_=True)
        b = ctypes.create_string_buffer(256); k.ReadProcessMemory(hp, mem + 512, b, 256, None); return b.value.decode('latin-1')
    time.sleep(10)
    if p.poll() is not None:
        return {'exit': 'CRASH 0x%08X before edit' % (p.returncode & 0xFFFFFFFF)}
    sel = False; grid = None; allc = []
    for top in tops():
        allc = children(top)
        for t in [c for c in allc if cls(c) == 'SysTreeView32']:
            it = snd(t, 0x110A, 0, 0)
            while it:
                if text(t, it) == 'Workspace':
                    snd(t, 0x1102, 2, it); time.sleep(0.5)
                    c = snd(t, 0x110A, 4, it)
                    while c:
                        if text(t, c) == 'GE_' + klass:
                            snd(t, 0x110B, 9, c); sel = True   # TVM_SELECTITEM TVGN_CARET
                        c = snd(t, 0x110A, 1, c)
                it = snd(t, 0x110A, 1, it)
    time.sleep(1.5)
    if dump:
        for c in allc:
            r = w.RECT(); u.GetWindowRect(c, ctypes.byref(r))
            print('%08x %-40s vis=%d %dx%d count=%s' % (c, cls(c), u.IsWindowVisible(c), r.right - r.left, r.bottom - r.top, snd(c, 0x018B)))
    lists = [c for c in allc if u.IsWindowVisible(c) and 'xtppropertygridview' in cls(c).lower()] or \
            [c for c in allc if u.IsWindowVisible(c) and cls(c).lower() == 'listbox']
    res = {'selected': sel, 'grid': [cls(c) for c in lists], 'rows': [], 'exit': None}
    if not lists:
        p.kill(); return res
    grid = lists[0]
    n = snd(grid, 0x018B) or 0   # LB_GETCOUNT
    res['count'] = n
    for i in range(int(a[a.index('--from') + 1]) if '--from' in a else 0, min(n, maxrows)):
        if p.poll() is not None:
            break
        snd(grid, 0x0186, i)      # LB_SETCURSEL
        u.PostMessageW(grid, 0x0102, ord('1'), 0)   # WM_CHAR opens the in-place edit with '1'
        time.sleep(0.4)
        for e in [c for c in children(grid) if cls(c) in ('Edit', 'RichEdit20A', 'ComboBox')] or [grid]:
            u.PostMessageW(e, 0x0100, 0x0D, 0); u.PostMessageW(e, 0x0101, 0x0D, 0)   # Enter
        time.sleep(0.8)
        res['rows'].append(i)
        if p.poll() is not None:
            res['exit'] = 'CRASH 0x%08X at row %d' % (p.returncode & 0xFFFFFFFF, i); break
    if p.poll() is None:
        p.kill()
    return res


if __name__ == '__main__':
    out = {}
    if '--dump' in a:
        print(run(EXE, CLS, 0, dump=True)); sys.exit()
    out['ours'] = run(EXE, CLS)
    time.sleep(1)
    if FAULTS:
        import bisect, re
        rows = []
        for l in open(H / 'linkexp/qt.map', errors='replace'):
            q = l.split()
            if len(q) >= 4 and q[0].startswith('0001:') and re.fullmatch('[0-9a-f]{8}', q[2]): rows.append((int(q[2], 16), q[1]))
        rows.sort(); ks = [r[0] for r in rows]
        def sym(v):
            v = int(v, 16); j = bisect.bisect_right(ks, v) - 1
            return '%08x %s+%x' % (v, rows[j][1][:100], v - ks[j]) if j >= 0 and 0x401000 <= v < 0x8f0000 else '%08x' % v
        for f in FAULTS:
            if 'hook' in f: print('HOOK', f)
        FAULTS[:] = [f for f in FAULTS if 'hook' not in f] or [{'pc': '0', 'mem': None, 'ecx': '', 'eax': '', 'esi': '', 'st': [], 'raw': []}]
        f = FAULTS[0]; print('mod', f.get('mod'));print('FAULT pc', sym(f['pc']), 'mem', f['mem'], 'ecx', f['ecx'], 'eax', f['eax'], 'esi', f['esi'])
        for x in f['st']: print('  bt', sym(x))
        print('  stack:'); [print('   ', sym(x)) for x in f['raw'] if 0x401000 <= int(x, 16) < 0x8f0000]
        out['fault'] = f
    print('ours', out['ours'])
    if '--orig' in a:
        out['orig'] = run(str(H / 'run/RobloxOrig.exe'), CLS); print('orig', out['orig'])
    (H / 'auto/gridedit.json').write_text(json.dumps(out, indent=1))
