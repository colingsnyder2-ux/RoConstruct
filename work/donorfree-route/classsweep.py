"""python classsweep.py [EXE] [--secs 60]: crash-and-continue sweep of EVERY registered class in one client run.
After File->New, walks AbstractFactoryProduct<Instance>::getCreators() (std::map<const Name*, ICreator*>) and calls each
creator's create() (Creator vtable slot 0) from Frida; a native fault inside is turned into a JS error (Frida
exceptions: 'steal'), recorded with pc + nearest map symbol, and the sweep continues with the next class.
Result: auto/classsweep.json [{class, ok, null, fault, sym}] -- the whole list of broken classes from one run instead of
one crash per link. Instances are leaked on purpose (no destructor noise)."""
import bisect, ctypes, ctypes.wintypes as w, json, os, sys, time
from pathlib import Path
import frida
H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
rows = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            rows.append((int(p[2], 16), p[1]))
        except ValueError:
            pass
rows.sort(); ks = [r[0] for r in rows]
near = lambda v: (lambda j: '%s+%x' % (rows[j][1][:90], v - ks[j]) if j >= 0 else '%08x' % v)(bisect.bisect_right(ks, v) - 1)
gc = next(v for v, n in rows if n.startswith('?getCreators@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@KA'))
JS = r"""
function nameOf(nm) { try { return nm.add(0x1c).readU32() >= 16 ? nm.add(8).readPointer().readAnsiString(60) : nm.add(8).readAnsiString(60); } catch (e) { return '?'; } }
rpc.exports = {
  sweep() {
    const getCreators = new NativeFunction(ptr(%d), 'pointer', [], 'mscdecl');
    const map = getCreators();
    let head = null;
    for (const off of [4, 8, 0, 12]) {            // _Myhead: the node whose _Isnil (+0x15) is 1
      try { const h = map.add(off).readPointer(); if (h.add(0x15).readU8() === 1 && h.readPointer().add(0x15).readU8() <= 1) { head = h; break; } } catch (e) {}
    }
    const walk = [];
    if (head) {
      const isnil = n => n.add(0x15).readU8() !== 0;
      let n = head.readPointer();                  // head->_Left = leftmost (begin)
      let guard = 0;
      while (!isnil(n) && guard++ < 5000) {
        walk.push(n);
        let r = n.add(8).readPointer();
        if (!isnil(r)) { n = r; while (!isnil(n.readPointer())) n = n.readPointer(); }
        else { let p = n.add(4).readPointer(); while (!isnil(p) && n.equals(p.add(8).readPointer())) { n = p; p = p.add(4).readPointer(); } n = p; }
      }
    }
    const out = [];
    if (!head) { const w = []; for (let i = 0; i < 6; i++) { let v = map.add(4*i).readPointer(); let x = ''; try { x = ' isnil=' + v.add(0x15).readU8() + ' l=' + v.readPointer(); } catch (e) {} w.push(v + x); } return [{cls: '(debug map ' + map + ')', fault: w.join(' | ')}]; }
    for (const node of walk) {
      const name = nameOf(node.add(0xc).readPointer());
      const cr = node.add(0x10).readPointer();
      const rec = { cls: name };
      try {
        const create = new NativeFunction(cr.readPointer().readPointer(), 'pointer', ['pointer', 'pointer'], 'thiscall', { exceptions: 'steal' });
        const ret = Memory.alloc(8);
        create(cr, ret);
        rec.ok = !ret.readPointer().isNull();
      } catch (e) {
        rec.fault = '' + e; rec.pc = (e.context && e.context.pc) ? e.context.pc.toUInt32() : 0;
      }
      out.push(rec);
    }
    return out;
  }
};
""" % gc
pid = frida.spawn([exe], cwd=os.path.dirname(exe))
sess = frida.attach(pid); scr = sess.create_script(JS); scr.load(); frida.resume(pid)
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
    res = scr.exports_sync.sweep()
except Exception as e:
    res = [{'cls': '(sweep aborted)', 'fault': str(e)}]
try:
    frida.kill(pid)
except Exception:
    pass
for r_ in res:
    if r_.get('pc'):
        r_['sym'] = near(r_['pc'])
(H / 'auto/classsweep.json').write_text(json.dumps(res, indent=0))
ok = [r_['cls'] for r_ in res if r_.get('ok')]; nul = [r_['cls'] for r_ in res if r_.get('ok') is False]; flt = [r_ for r_ in res if 'fault' in r_]
print('classsweep: classes %d, created %d, NULL %d, faulted %d' % (len(res), len(ok), len(nul), len(flt)))
print('  NULL:', ' '.join(nul))
for r_ in flt:
    print('  FAULT %-22s %s %s' % (r_['cls'], r_.get('sym', ''), r_['fault'][:80]))
