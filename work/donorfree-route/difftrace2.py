"""python difftrace2.py --post 0xE100,0x807f [--secs 25] [--max 3000]
First-divergence finder: one-shot entry int3s on N converted functions (original address A in RobloxOrig.exe, our address
from linkexp/qt.map in RobloxQT.exe), same posted WM_COMMANDs in both, compare ORDER of first hits (main thread).
Writes auto/difftrace2.json. Debug loop reused from attachcrash.py (launch normally, DebugActiveProcess, WOW64 context)."""
import argparse, bisect, ctypes, ctypes.wintypes as w, json, os, re, struct, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
ap = argparse.ArgumentParser()
ap.add_argument('--post', default=''); ap.add_argument('--secs', type=float, default=25); ap.add_argument('--max', type=int, default=3000)
ap.add_argument('--delay', type=float, default=0.4); ap.add_argument('--gap', type=float, default=4.5)
args = ap.parse_args()
k = ctypes.WinDLL('kernel32', use_last_error=True); u32 = ctypes.WinDLL('user32')
reg = json.load(open(H / '../2008-06/identity-registry.json'))
name_of = lambda a: (reg.get('%08x' % a) or {}).get('name', '?')[:70]

# --- map: original address A -> our VA (converted main functions: func_A defined in A.obj / ca_A.obj)
ours, syms = {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if not v:
            continue
        syms.setdefault(v, p[1])
        m = re.fullmatch(r'func_([0-9a-f]{8})', p[1])
        if m and re.search(r'(?:^|[\\/:])(?:ca_)?%s\.obj$' % m.group(1), p[-1]) and 0x401000 <= int(m.group(1), 16) < 0x7c0000:
            ours.setdefault(int(m.group(1), 16), v)
ks = sorted(syms)
def near(v):
    j = bisect.bisect_right(ks, v) - 1
    if j < 0:
        return '%08x' % v
    s = syms[ks[j]]; m = re.fullmatch(r'func_([0-9a-f]{8})', s)
    return '%s+%x%s' % (s[:70], v - ks[j], ' [%s]' % name_of(int(m.group(1), 16)) if m else '')

# --- choose N: name-priority first (half), rest evenly; drop A's sharing one of our VAs (ICF) so both runs arm the same set
import pefile
_pe = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True); _ib = _pe.OPTIONAL_HEADER.ImageBase
def clean_start(v):   # entry must follow padding/ret: otherwise it is an overlapped symbol inside another body (an int3 there corrupts that instruction)
    b = _pe.get_data(v - _ib - 3, 3)
    return b[2] in (0xcc, 0x90, 0xc3) or b[0] == 0xc2
seen_va, cand = set(), []
for a in sorted(ours):
    if ours[a] not in seen_va and clean_start(ours[a]):
        seen_va.add(ours[a]); cand.append(a)
PRI = re.compile(r'Instance|Insert|Document|Factory|Create|Part|Workspace|DataModel|Stream|Reflect|Serial|Load|Selection', re.I)
pri = [a for a in cand if PRI.search(name_of(a))][:args.max // 2]
rest = [a for a in cand if a not in set(pri)]
need = args.max - len(pri)
step = max(1, len(rest) / max(need, 1))
chosen = sorted(set(pri + [rest[int(i * step)] for i in range(min(need, len(rest)))]))
if not os.environ.get('ONLY'): print('%d converted functions, %d chosen (%d name-priority)' % (len(cand), len(chosen), len(pri)), flush=True)


class CTX(ctypes.Structure):   # WOW64_CONTEXT
    _fields_ = [('Flags', w.DWORD), ('Dr', w.DWORD * 6), ('Float', ctypes.c_byte * 112), ('Gs', w.DWORD), ('Fs', w.DWORD),
                ('Es', w.DWORD), ('Ds', w.DWORD), ('Edi', w.DWORD), ('Esi', w.DWORD), ('Ebx', w.DWORD), ('Edx', w.DWORD),
                ('Ecx', w.DWORD), ('Eax', w.DWORD), ('Ebp', w.DWORD), ('Eip', w.DWORD), ('Cs', w.DWORD), ('EFlags', w.DWORD),
                ('Esp', w.DWORD), ('Ss', w.DWORD), ('Ext', ctypes.c_byte * 512)]
class EV(ctypes.Structure):
    _fields_ = [('code', w.DWORD), ('pid', w.DWORD), ('tid', w.DWORD), ('pad', w.DWORD), ('u', ctypes.c_byte * 160)]


def run(exe, addr_of):
    """addr_of: {A: va in this exe}. Returns dict(hits=[(tid, A)], main_tid, crash=str|None, exited)."""
    import ieclean
    t0 = time.time(); ieclean.clean()
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
    time.sleep(args.delay)
    if not k.DebugActiveProcess(p.pid):
        print('attach failed', ctypes.get_last_error()); return dict(hits=[], main_tid=None, crash='attach failed')
    k.DebugSetProcessKillOnExit(True)
    hp = k.OpenProcess(0x1F0FFF, False, p.pid)
    def rd(a_, n_=4):
        b_ = (ctypes.c_char * n_)(); k.ReadProcessMemory(hp, ctypes.c_void_p(a_), b_, n_, ctypes.byref(ctypes.c_size_t())); return b_.raw
    def wr(a_, b_):
        return k.WriteProcessMemory(hp, ctypes.c_void_p(a_), b_, len(b_), ctypes.byref(ctypes.c_size_t()))
    va2a = {v: a for a, v in addr_of.items()}
    bps, done, hits, crash = {}, set(), [], None
    queue = [c for c in args.post.split(',') if c]; nxt = None; main_tid = None; last_post = None
    armed = False; ev = EV(); ts = time.time(); win_t = None; mark = None

    def find_win():
        P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM); found = []
        def cb(h, _):
            pid = w.DWORD(); tid = u32.GetWindowThreadProcessId(h, ctypes.byref(pid))
            if pid.value == p.pid and u32.IsWindowVisible(h):
                c_ = ctypes.create_unicode_buffer(64); u32.GetClassNameW(h, c_, 64)
                if c_.value.startswith('Afx:'):
                    found.append((h, tid))
            return True
        u32.EnumWindows(P(cb), 0); return found

    while time.time() - ts < args.secs:
        now = time.time()
        if armed and win_t is None:
            f = find_win()
            if f:
                win_t = now; main_tid = f[0][1]; nxt = now + args.gap; print('  main window up at %.1fs (tid %d)' % (now - ts, main_tid), flush=True)
        if win_t and queue and now >= nxt:
            for h, _ in find_win():
                u32.PostMessageW(h, 0x111, int(queue[0], 0), 0)
            mark = len(hits) if mark is None else mark
            print('  posted %s at %.1fs' % (queue.pop(0), now - ts), flush=True); nxt = now + args.gap; last_post = now
        if win_t and not queue and last_post and now - last_post > args.gap + 1.5:
            break
        if not k.WaitForDebugEvent(ctypes.byref(ev), 200):
            continue
        status = 0x10002
        if ev.code == 1:
            ub = bytes(ev.u); code, = struct.unpack_from('<I', ub, 0); first = struct.unpack_from('<I', ub, 152)[0]
            eaddr = struct.unpack_from('<Q', ub, 16)[0] & 0xffffffff
            if code in (0x80000003, 0x4000001f):
                if not armed:
                    armed = True; n = 0
                    for a_, va_ in addr_of.items():
                        ob = rd(va_, 1)
                        if len(ob) == 1 and wr(va_, b'\xcc'):
                            bps[va_] = ob; n += 1
                    print('  armed %d/%d breakpoints' % (n, len(addr_of)), flush=True)
                elif eaddr in bps:
                    ob = bps.pop(eaddr); done.add(eaddr); wr(eaddr, ob)
                    h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c))
                    c.Eip = eaddr; k.Wow64SetThreadContext(h, ctypes.byref(c)); k.CloseHandle(h)
                    hits.append((ev.tid, va2a[eaddr]))
                elif eaddr in done:   # another thread raced onto the same int3: rewind
                    h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c))
                    c.Eip = eaddr; k.Wow64SetThreadContext(h, ctypes.byref(c)); k.CloseHandle(h)
            elif code in (0xc0000005, 0xc00000fd):
                if crash is None or not first:
                    h = k.OpenThread(0x1FFFFF, False, ev.tid); c = CTX(); c.Flags = 0x10007; k.Wow64GetThreadContext(h, ctypes.byref(c))
                    sb = struct.unpack('<256I', rd(c.Esp, 1024).ljust(1024, b'\0'))
                    fr = [near(v)[:100] for v in sb if 0x401000 <= v < 0x7c0000][:8]
                    info = struct.unpack_from('<QQ', ub, 32 + 16) if False else (struct.unpack_from('<Q', ub, 40)[0], struct.unpack_from('<Q', ub, 48)[0])
                    msg = 'AV %s chance tid %d eip %08x %s access %d addr %08x\n    stack: %s' % (
                        'first' if first else 'SECOND', ev.tid, c.Eip, near(c.Eip), info[0], info[1] & 0xffffffff, '\n           '.join(fr))
                    k.CloseHandle(h)
                    if crash is None:
                        crash = msg
                        print('  ' + msg, flush=True)
                if not first:
                    k.TerminateProcess(hp, 1); break
                status = 0x80010001
            elif code not in (0x80000004, 0x4000001e):
                if code not in (0xe06d7363, 0x406d1388) and os.environ.get('DT_VERBOSE'):
                    print('  exception %08x chance %d at %08x' % (code, first, eaddr), flush=True)
                status = 0x80010001
        elif ev.code == 5:
            print('  process exited code %x at %.1fs' % (struct.unpack_from('<I', bytes(ev.u), 0)[0], time.time() - ts), flush=True); break
        k.ContinueDebugEvent(ev.pid, ev.tid, status)
    k.TerminateProcess(hp, 1); k.WaitForSingleObject(hp, 5000); time.sleep(2.5)
    try:
        ieclean.clean(t0)
    except Exception:
        pass
    if main_tid is None and hits:   # window never seen: busiest thread
        main_tid = max({t for t, _ in hits}, key=lambda t: sum(1 for x, _ in hits if x == t))
    return dict(hits=hits, main_tid=main_tid, crash=crash, mark=mark or 0)


ONLY = os.environ.get('ONLY')
res = {}
if ONLY:   # child: one exe, result to auto/difftrace2_<tag>.json
    for _try in range(5):   # the attach races startup: a launch that died before posting anything (e.g. c000041d at 0.2s) is retried
        r = run(str(H / ('run/RobloxOrig.exe' if ONLY == 'orig' else 'run/RobloxQT.exe')), {a: a if ONLY == 'orig' else ours[a] for a in chosen})
        if r['mark'] or r['crash']:
            break
        print('  never reached the first command; retry', flush=True); time.sleep(2)
    r['seq'] = [a for t, a in r['hits'][r['mark']:] if t == r['main_tid']]   # only hits after the first posted command (startup differs by attach timing)
    print('  %d hits, %d on main thread' % (len(r['hits']), len(r['seq'])), flush=True)
    (H / 'auto').mkdir(exist_ok=True); json.dump(r, open(H / ('auto/difftrace2_%s.json' % ONLY), 'w'))
    sys.exit(0)
for tag in ('orig', 'ours'):   # each exe in a fresh python process (a second launch in one process exited with code 1)
    print('== %s ==' % tag, flush=True)
    subprocess.run([sys.executable, __file__] + sys.argv[1:], env=dict(os.environ, ONLY=tag), check=False)
    res[tag] = json.load(open(H / ('auto/difftrace2_%s.json' % tag)))
    time.sleep(2)
so, sq = res['orig']['seq'], res['ours']['seq']
i = next((j for j in range(min(len(so), len(sq))) if so[j] != sq[j]), min(len(so), len(sq)))
fmt = lambda a: '%08x %s' % (a, name_of(a))
print('\nfirst divergence at index %d (orig len %d, ours len %d)' % (i, len(so), len(sq)))
for tag, s in (('ORIG', so), ('OURS', sq)):
    print('-- %s around %d' % (tag, i))
    for j in range(max(0, i - 4), min(len(s), i + 6)):
        print('  %s%4d %s' % ('>' if j == i else ' ', j, fmt(s[j])))
only_o = [a for a in dict.fromkeys(so) if a not in set(sq)]
only_q = [a for a in dict.fromkeys(sq) if a not in set(so)]
print('-- in orig, never in ours (%d, first 40 by hit order):' % len(only_o))
for a in only_o[:40]:
    print('   %4d %s' % (so.index(a), fmt(a)))
print('-- in ours, never in orig (%d, first 40):' % len(only_q))
for a in only_q[:40]:
    print('   %4d %s' % (sq.index(a), fmt(a)))
for tag in ('orig', 'ours'):
    if res[tag]['crash']:
        print('\nCRASH %s: %s' % (tag, res[tag]['crash']))
out = dict(post=args.post, chosen=len(chosen), diverge_index=i, orig=so, ours=sq, only_orig=only_o, only_ours=only_q,
           crash={t: res[t]['crash'] for t in res}, main_tid={t: res[t]['main_tid'] for t in res})
(H / 'auto').mkdir(exist_ok=True)
json.dump(out, open(H / 'auto/difftrace2.json', 'w'), indent=1)
