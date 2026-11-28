"""python classtree.py [EXE]: after File->New, walk the reflection class tree from ClassDescriptor::rootDescriptor()
(derived-class vector at +0xb0 first / +0xb4 last / +0xb8 end) and flag every descriptor whose vector is
inconsistent with its heap block (_msize): last > end, or end beyond the allocation. Insert Object's populate read past
such a vector (page heap). Prints the bad descriptors' names, sizes and parents."""
import ctypes, ctypes.wintypes as w, os, sys, time
import frida
from pathlib import Path
H = Path(__file__).parent
exe = os.path.abspath(next((a for a in sys.argv[1:] if a.endswith('.exe')), str(H / 'run/RobloxQT.exe')))
root = next(int(l.split()[2], 16) for l in open(H / 'linkexp/qt.map', errors='replace') if ' ?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ ' in l)
JS = r"""
function nm(d) { try { const n = d.add(4).readPointer(); return n.add(0x1c).readU32() >= 16 ? n.add(8).readPointer().readAnsiString(50) : n.add(8).readAnsiString(50); } catch (e) { return '?'; } }
rpc.exports = { check() {
  const msize = new NativeFunction(Module.getExportByName('msvcr90.dll', '_msize'), 'uint', ['pointer']);
  const root = new NativeFunction(ptr(%d), 'pointer', [], 'mscdecl')();
  const out = [], seen = {}, q = [[root, '']];
  let n = 0;
  while (q.length && n++ < 3000) {
    const [d, par] = q.shift(); const k = d.toString(); if (seen[k]) { out.push({cls: nm(d), dup: 1, parent: par}); continue; } seen[k] = 1;
    let first, last, end;
    try { first = d.add(0xb0).readPointer(); last = d.add(0xb4).readPointer(); end = d.add(0xb8).readPointer(); } catch (e) { out.push({cls: nm(d), err: 'unreadable', parent: par}); continue; }
    if (first.isNull()) continue;
    let sz = -1; try { sz = msize(first); } catch (e) {}
    const used = last.sub(first).toInt32(), cap = end.sub(first).toInt32();
    if (used < 0 || used > cap || (sz >= 0 && cap > sz) || used %% 4) out.push({cls: nm(d), used: used, cap: cap, heap: sz, parent: par});
    for (let p = first; p.compare(last) < 0 && p.sub(first).toInt32() < Math.min(used, 4096); p = p.add(4)) {
      try { q.push([p.readPointer(), nm(d)]); } catch (e) { break; }
    }
  }
  return {n: n, bad: out, names: Object.keys(seen).map(k => nm(ptr(k))), raw: Object.keys(seen).map(k => [k, ptr(k).add(4).readPointer().toString(), nm(ptr(k))])};
}};
""" % root
pid = frida.spawn([exe], cwd=os.path.dirname(exe)); s = frida.attach(pid).create_script(JS); s.load(); frida.resume(pid)
u = ctypes.WinDLL('user32'); P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)


def frame():
    r = []
    def cb(h, _):
        p_ = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p_)); c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
        if p_.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
            r.append(h)
        return True
    u.EnumWindows(P(cb), 0); return r[0] if r else None


t = time.time()
while not frame() and time.time() - t < 25:
    time.sleep(0.5)
time.sleep(2); u.PostMessageW(frame(), 0x111, 0xE100, 0); time.sleep(6)
try:
    r = s.exports_sync.check()
except Exception as e:
    r = {'n': 0, 'bad': [{'cls': 'aborted', 'err': str(e)}]}
try:
    frida.kill(pid)
except Exception:
    pass
print('classtree: descriptors walked %d, inconsistent %d' % (r['n'], len(r['bad'])))
outf = next((a for a in sys.argv[1:] if a.endswith('.txt')), None)
if outf:
    Path(outf).write_text('\n'.join(sorted(r.get('names', []))))
import bisect
rows=[]
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try: rows.append((int(p[2], 16), p[1]))
        except ValueError: pass
rows.sort(); ks=[x[0] for x in rows]
for d, np_, n_ in r.get('raw', []):
    if not n_ or not n_.isprintable() or len(n_) < 3 or n_ in ('HtmlServ', 'ServiceProvi'):
        v = int(np_, 16); j = bisect.bisect_right(ks, v) - 1
        print('  badname desc %s name@%s %s+%x' % (d, np_, rows[j][1][:90], v - ks[j]))
for b in r['bad'][:40]:
    print('  ', b)
