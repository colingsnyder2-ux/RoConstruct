"""python stubhits.py [EXE] [--post 0xE100,0x807f,0x80c6] [--secs 30]: Frida stub-hit tracer. Hooks every `return 0`
stub our link generated (qt_stubs*.obj symbols in linkexp/qt.map), launches the exe, posts the WM_COMMANDs to the main
frame 5 s apart, and ranks the stubs actually CALLED with hit counts and first callers (nearest map symbol). That is
the ranked fix list for the features being exercised. Writes auto/stubhits.json."""
import bisect, collections, json, os, subprocess, sys, time, ctypes, ctypes.wintypes as w
from pathlib import Path
import frida
H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
post = next((args[i + 1] for i, a in enumerate(args) if a == '--post'), '0xE100,0x807f,0x80c6')
secs = float(next((args[i + 1] for i, a in enumerate(args) if a == '--secs'), '30'))
syms, stubs = [], {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        syms.append((v, p[1]))
        if 'stubs' in p[-1]:
            stubs.setdefault(v, p[1])
syms.sort()
ks = [v for v, _ in syms]
near = lambda v: (lambda j: '%s+%x' % (syms[j][1][:80], v - ks[j]) if j >= 0 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
JS = """
const base = Process.enumerateModules()[0].base;
const counts = {}, callers = {};
const addrs = %s;
let ok = 0;
for (const a of addrs) {
  try {
    Interceptor.attach(ptr(a), { onEnter(args) {
      const k = a; counts[k] = (counts[k] || 0) + 1;
      if (counts[k] <= 3) { const r = this.returnAddress.toUInt32(); (callers[k] = callers[k] || []).push(r); send({hit: k, ret: r, n: counts[k]}); }
    }}); ok++;
  } catch (e) {}
}
send({armed: ok});
rpc.exports = { dump() { return {counts, callers}; } };
""" % json.dumps(['0x%x' % a for a in sorted(stubs)])
import ieclean; t0 = time.time(); ieclean.clean()
pid = frida.spawn([exe], cwd=os.path.dirname(exe))
sess = frida.attach(pid)
scr = sess.create_script(JS)
LIVE = collections.defaultdict(list)


def _on(m, d):
    pl = m.get('payload') or {}
    if isinstance(pl, dict) and 'hit' in pl:
        LIVE[pl['hit']].append(pl['ret'])   # streamed: survives the client crashing before the final dump
    else:
        print('frida:', pl or m)


scr.on('message', _on)
scr.load()
frida.resume(pid)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def frame():
    out = []
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            out.append(h)
        return True
    u.EnumWindows(P(cb), 0)
    return out[0] if out else None


t1 = time.time()
while not frame() and time.time() - t1 < 20:
    time.sleep(0.5)
time.sleep(2)
for c in post.split(','):
    h = frame()
    if h:
        u.PostMessageW(h, 0x111, int(c, 16), 0); print('posted', c)
    time.sleep(5)
time.sleep(max(0, secs - 5 * len(post.split(','))))
try:
    d = scr.exports_sync.dump()
except Exception as e:
    d = {'counts': {k_: len(v_) for k_, v_ in LIVE.items()}, 'callers': dict(LIVE)}; print('dump failed (process died?), using streamed hits:', e)
try:
    frida.kill(pid)
except Exception:
    pass
ieclean.clean(t0)
rows = sorted(((n, int(a, 16)) for a, n in d['counts'].items()), reverse=True)
res = [{'stub': stubs[a], 'addr': '%08x' % a, 'hits': n, 'callers': [near(c) for c in d['callers'].get('0x%x' % a, [])]} for n, a in rows]
(H / 'auto/stubhits.json').write_text(json.dumps(res, indent=0))
print('stubs hooked %d, stubs called %d' % (len(stubs), len(res)))
for r_ in res[:40]:
    print('%7d  %-40s <- %s' % (r_['hits'], r_['stub'][:40], r_['callers'][0][:70] if r_['callers'] else ''))
