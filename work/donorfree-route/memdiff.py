"""python memdiff.py [EXE] [--post 0xE100] [--wait 6]: global-memory snapshot diff vs the ORIGINAL at the same point.
Launches the original and ours (no debugger), waits for the main window, optionally posts commands, waits, then
reads the original's .data (0x928000..0x980000) and, for every original global address A, the place OUR build keeps
it: dat_<A> (stub/merged block), a natdata alias (dat_<A>=native global), or a natinit member (native global + off).
Per dword: orig non-zero / ours zero = NOT CONSTRUCTED (an initializer never ran: the 714-static class); both
non-pointer and different = VALUE DIFF; pointers are compared only for null-ness. Ranks globals by unconstructed
dwords and names them (registry, our symbol). Writes auto/memdiff.json."""
import ctypes, ctypes.wintypes as w, json, os, re, subprocess, sys, time, bisect, collections
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
orig_exe = os.path.abspath(str(H / 'run/RobloxOrig.exe'))
post = [int(x, 16) for x in (args[args.index('--post') + 1].split(',') if '--post' in args else [])]
wait = float(args[args.index('--wait') + 1]) if '--wait' in args else 6.0
k = ctypes.WinDLL('kernel32'); u = ctypes.WinDLL('user32')
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
LO, HI = 0x928000, 0x980000


def snapshot(path, ranges):
    import ieclean
    t0 = time.time(); ieclean.clean()
    p = subprocess.Popen([path], cwd=os.path.dirname(path))
    def frame():
        out = []
        def cb(h, _):
            pid = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(pid)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
            if pid.value == p.pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
                out.append(h)
            return True
        u.EnumWindows(P(cb), 0)
        return out[0] if out else None
    t1 = time.time()
    while not frame() and time.time() - t1 < 25 and p.poll() is None:
        time.sleep(0.3)
    time.sleep(2)
    for c in post:
        h = frame()
        if h:
            u.PostMessageW(h, 0x111, c, 0)
        time.sleep(4)
    time.sleep(wait)
    hp = k.OpenProcess(0x1F0FFF, False, p.pid)
    mem = {}
    for a, n in ranges:
        b = ctypes.create_string_buffer(n); r = ctypes.c_size_t()
        ok = k.ReadProcessMemory(hp, ctypes.c_void_p(a), b, n, ctypes.byref(r))
        mem[a] = b.raw[:r.value] if ok else b''
    alive = p.poll() is None
    try:
        p.kill()
    except Exception:
        pass
    ieclean.clean(t0)
    return mem, alive


# where OUR build keeps each original global
sym = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p_ = l.split()
    if len(p_) >= 4 and ':' in p_[0] and not p_[0].startswith('0000:'):
        try:
            sym.setdefault(p_[1], int(p_[2], 16))
        except ValueError:
            pass
place = {}   # orig addr -> our addr
for n, v in sym.items():
    m = re.fullmatch(r'dat_([0-9a-f]{8})', n)
    if m and LO <= int(m.group(1), 16) < HI:
        place[int(m.group(1), 16)] = v
for l in (H / 'aliases_natdata.txt').read_text().splitlines():
    if '=' in l:
        a_, t_ = l.split('=', 1)
        if t_ in sym and re.fullmatch(r'dat_[0-9a-f]{8}', a_) and LO <= int(a_[4:], 16) < HI:
            place[int(a_[4:], 16)] = sym[t_]
ni = json.loads((H / 'auto/natinit_plan.json').read_text()) if (H / 'auto/natinit_plan.json').exists() else {}
for a_, (t_, off) in ni.items():
    if t_ in sym:
        place[int(a_[4:], 16)] = sym[t_] + off
keys = sorted(place)
# extent of each original global: up to the next placed address (cap 0x200)
ext = {a: min((keys[i + 1] - a) if i + 1 < len(keys) else 0x40, 0x200) for i, a in enumerate(keys)}
orig_mem, oa = snapshot(orig_exe, [(LO, HI - LO)])
our_ranges = [(place[a], ext[a]) for a in keys]
ours_mem, qa = snapshot(exe, our_ranges)
om = orig_mem[LO]
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
qname = {v: n for n, v in sym.items()}
rows = []
for a in keys:
    n = ext[a]
    ob = om[a - LO:a - LO + n]
    qb = ours_mem.get(place[a], b'')
    if len(ob) < n or len(qb) < n:
        continue
    unc = diff = 0
    for i in range(0, n - 3, 4):
        x = int.from_bytes(ob[i:i + 4], 'little'); y = int.from_bytes(qb[i:i + 4], 'little')
        if x and not y:
            unc += 1
        elif x != y and not (0x10000 < x < 0x80000000 and 0x10000 < y < 0x80000000):
            diff += 1
    if unc or diff:
        rows.append({'orig': '%08x' % a, 'size': n, 'unconstructed': unc, 'valdiff': diff,
                     'name': ((reg.get('%08x' % a) or {}).get('name') or '')[:100], 'ours': qname.get(place[a], '')[:100]})
rows.sort(key=lambda r: (-r['unconstructed'], -r['valdiff']))
(H / 'auto/memdiff.json').write_text(json.dumps({'alive': {'orig': oa, 'ours': qa}, 'rows': rows}, indent=0))
print('memdiff: globals compared %d, with unconstructed dwords %d, value-diff only %d (orig alive %s, ours alive %s)'
      % (len(keys), sum(1 for r in rows if r['unconstructed']), sum(1 for r in rows if not r['unconstructed']), oa, qa))
for r in rows[:30]:
    print('  %s size %3x unc %3d diff %3d %s | %s' % (r['orig'], r['size'], r['unconstructed'], r['valdiff'], r['name'][:50], r['ours'][:40]))
