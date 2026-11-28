"""python behavior_oracle.py [--max 600] [--secs 15]: behavioral differential test orig vs rebuilt exe.
Hooks non-byte-exact functions (auto/reccmp_map.json ratio<1) in run/RobloxOrig.exe and run/RobloxQT.exe, records
ecx/4 stack args/eax for first 30 calls (pointers normalized to their pointee bytes), posts File->New, diffs.
Writes auto/behavior_oracle.json and prints a ranking."""
import json, os, sys, time, ctypes, ctypes.wintypes as w
from pathlib import Path
import frida
import ieclean
H = Path(__file__).parent
A = sys.argv[1:]
opt = lambda n, d: next((A[i + 1] for i, a in enumerate(A) if a == n), d)
MAXN, SECS = int(opt('--max', 600)), float(opt('--secs', 15))
NCALL = 30
mp = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try: mp.setdefault(p[1], int(p[2], 16))
        except ValueError: pass
pairs = []
for x in json.load(open(H / 'auto/reccmp_map.json')):
    o = int(x['orig'], 16)
    if x['ratio'] < 1.0 and 0x401000 <= o < 0x7c0000 and x['name'] in mp:
        pairs.append((o, mp[x['name']]))
pairs = sorted(set(pairs))[:MAXN]
print('pairs', len(pairs))
try: reg = json.load(open(H / '../2008-06/identity-registry.json'))
except Exception: reg = {}
nm = lambda o: (reg.get('%08x' % o) or {}).get('name') or ''

JS = """
const addrs = %s, N = %d, rec = {}, cnt = {};
function isp(v) { return v >= 0x10000 && Process.findRangeByAddress(ptr(v)) !== null; }
function pb(v) { try { const u = new Uint32Array(ptr(v).readByteArray(16)); let s = '';
  for (const q of u) s += (isp(q) ? 'PPPPPPPP' : ('0000000' + q.toString(16)).slice(-8)); return s; } catch (e) { return null; } }
function norm(v) { v = v >>> 0; if (isp(v)) { const b = pb(v); return b ? 'P:' + b : 'P'; } return v.toString(16); }
for (const [k, a] of addrs) {
  try { Interceptor.attach(ptr(a), {
    onEnter(args) { cnt[k] = (cnt[k] || 0) + 1; this.r = null;
      if (cnt[k] <= N) { const c = this.context, sp = c.esp;
        const r = {c: norm(c.ecx.toUInt32()), a: []};
        for (let i = 1; i <= 4; i++) { try { r.a.push(norm(sp.add(4 * i).readU32())); } catch (e) { r.a.push('?'); } }
        (rec[k] = rec[k] || []).push(r); this.r = r; } },
    onLeave(ret) { if (this.r) this.r.e = norm(ret.toUInt32()); }
  }); } catch (e) {}
}
rpc.exports = { dump() { return {rec, cnt}; } };
""" % (json.dumps([['%08x' % o, '0x%x' % n] for o, n in pairs]) if False else '__ADDRS__', NCALL)

u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def run(exe, which):
    addrs = [[('%08x' % o), '0x%x' % (o if which == 0 else n)] for o, n in pairs]
    js = JS.replace('__ADDRS__', json.dumps(addrs))
    exe = str(exe); t0 = time.time(); ieclean.clean()
    pid = frida.spawn([exe], cwd=os.path.dirname(exe))
    sess = frida.attach(pid); st = {'dead': False}
    sess.on('detached', lambda r, c=None: st.update(dead=True, why=str(r)))
    scr = sess.create_script(js); scr.load(); frida.resume(pid)
    def frame():
        out = []
        def cb(h, _):
            p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
            if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'): out.append(h)
            return True
        u.EnumWindows(P(cb), 0); return out[0] if out else None
    last = {'rec': {}, 'cnt': {}}
    def snap():
        nonlocal last
        if not st['dead']:
            try: last = scr.exports_sync.dump()
            except Exception: pass
    t1 = time.time(); fa = None
    while not st['dead'] and time.time() - t1 < 25:
        fa = frame()
        if fa: break
        time.sleep(0.5)
    tw = time.time(); posted = False; end = None
    while not st['dead']:
        now = time.time()
        if fa and not posted and now - tw >= 4:
            u.PostMessageW(frame() or fa, 0x111, 0xE100, 0); posted = True; end = now + SECS
        if (posted and now > end) or (not fa and now - t1 > 40): break
        time.sleep(2); snap()
    snap()
    crash = st.get('why') if st['dead'] else None
    try: frida.kill(pid)
    except Exception: pass
    ieclean.clean(t0)
    print(which and 'ours' or 'orig', 'funcs called', len(last['cnt']), 'crash:', crash)
    return last, crash

ro, co = run(H / 'run/RobloxOrig.exe', 0)
rq, cq = run(H / 'run/RobloxQT.exe', 1)
res = []
for o, n in pairs:
    k = '%08x' % o
    oc, qc = ro['cnt'].get(k, 0), rq['cnt'].get(k, 0)
    if not oc and not qc: continue
    a, b = ro['rec'].get(k, []), rq['rec'].get(k, [])
    mm = []
    for i in range(min(len(a), len(b))):
        d = [f for f, x, y in [('ecx', a[i]['c'], b[i]['c'])] + [('arg%d' % j, a[i]['a'][j], b[i]['a'][j]) for j in range(4)] if x != y]
        ra, rb = a[i].get('e'), b[i].get('e')
        if ra != rb: d.append('ret')
        if d: mm.append({'call': i, 'fields': d, 'orig': a[i], 'ours': b[i]})
    res.append({'orig': k, 'name': nm(o), 'ours_addr': '%08x' % n, 'orig_calls': oc, 'ours_calls': qc,
                'never_in_ours': bool(oc and not qc), 'only_in_ours': bool(qc and not oc),
                'ret_mismatch': sum('ret' in m['fields'] for m in mm), 'arg_mismatch': sum(any(f != 'ret' for f in m['fields']) for m in mm),
                'compared': min(len(a), len(b)), 'mismatches': mm[:5]})
(H / 'auto/behavior_oracle.json').write_text(json.dumps({'orig_crash': co, 'ours_crash': cq, 'results': res}, indent=1))
print('crash orig=%s ours=%s' % (co, cq))
res.sort(key=lambda r: (not r['never_in_ours'], -r['ret_mismatch'], -r['arg_mismatch'], -r['orig_calls']))
print('never-in-ours: %d, ret-mismatch: %d, arg-mismatch: %d, compared: %d' % (
    sum(r['never_in_ours'] for r in res), sum(r['ret_mismatch'] > 0 for r in res), sum(r['arg_mismatch'] > 0 for r in res), len(res)))
for r in res[:30]:
    print('%s %-60s oc=%-5d qc=%-5d %s ret=%d/%d arg=%d' % (r['orig'], r['name'][:60], r['orig_calls'], r['ours_calls'],
          'NEVER' if r['never_in_ours'] else ('ONLYOURS' if r['only_in_ours'] else '      '), r['ret_mismatch'], r['compared'], r['arg_mismatch']))
