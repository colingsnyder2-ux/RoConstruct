"""python stubret.py [EXE MAP]: callee-pop audit of STUBS, link-wide. A stub whose `ret N` differs from the function it
replaces skews its caller's stack (CMainFrame::onEvent(Heartbeat) popped 8 of 12 -> RunService thread crash).
Truth per stub, from the original binary:
  - vtable slots: every vt_orig vtable slot in our exe that points at a stub; the ORIGINAL vtable (same address in
    the original exe, vt_orig copies it) slot holds the original function -> its first `ret N` (thunks followed);
  - func_<X> stubs: the original at X.
Writes auto/stubret_override.json {stub name: N} (grow-only, read by quicktest._ret) and prints the mismatches."""
import json, struct, sys, collections
from pathlib import Path
import pefile
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
q = pefile.PE(exe, fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
stub_at, vt = {}, {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if 'stubs' in p[-1] and p[0].startswith('0001'):
            stub_at.setdefault(v, p[1])
        elif p[-1] == 'vt_orig.obj' and p[1].startswith('??_7'):
            vt[p[1]] = v
names = json.loads((H / 'vt_orig_names.json').read_text()) if (H / 'vt_orig_names.json').exists() else {}
# original address of each vt_orig vtable: vtorig.py records name -> original address
import pickle, re
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))   # (RTTI type name, COL offset) -> (original vtable address, slots)
by_t = collections.defaultdict(list)
for (tn, off), (oa, _sl) in vo.items():
    by_t[tn].append((off, oa))
vaddr = {}
for n in vt:   # ??_7X@@6B@ = primary (offset 0); ??_7X@@6BY@@@: unique secondary only
    m = re.match(r'^\?\?_7(.+?)@@6B(.*)$', n)
    if not m:
        continue
    lst = by_t.get('.?AV%s@@' % m.group(1)) or by_t.get('.?AU%s@@' % m.group(1)) or []
    if m.group(2) == '@':
        vaddr[n] = next((oa for off, oa in lst if off == 0), None)
    else:
        sec = [oa for off, oa in lst if off != 0]
        vaddr[n] = sec[0] if len(sec) == 1 else None


def stub_ret(a):
    b = q[a - B:a - B + 8]
    return (b[6] | b[7] << 8) if b[5] == 0xc2 else (0 if b[5] == 0xc3 else None)


truth = collections.defaultdict(collections.Counter)
slot_addr = collections.defaultdict(collections.Counter)   # stub -> original functions in its slots
for n, a in vt.items():
    oa = vaddr.get(n)
    if not oa:
        continue
    for s in range(0, 0x400, 4):
        t = struct.unpack_from('<I', q, a - B + s)[0]
        if t not in stub_at:
            if s and not (0x401000 <= t < 0x3000000):
                break
            continue
        ot = struct.unpack_from('<I', o, oa - B + s)[0]
        if 0x401000 <= ot < 0x7c0000:
            truth[stub_at[t]][ms.addr_ret_bytes(ot)] += 1
            slot_addr[stub_at[t]][ot] += 1
for a, n in stub_at.items():
    if n.startswith('func_') and len(n) == 13:
        truth[n][ms.addr_ret_bytes(int(n[5:], 16))] += 3
pf = H / 'auto/stubret_override.json'
try:
    ov = {}   # recomputed each run (deterministic): the grow-only file kept wrong slot-truth entries
except (OSError, ValueError):
    ov = {}
bad = []
for n, c in truth.items():
    want = c.most_common(1)[0][0]
    a = next(k for k, v in stub_at.items() if v == n)
    have = stub_ret(a)
    # a decorated name's own signature wins (vtable slots named by folded registry entries lied: the ??_E stub of a
    # GetRuntimeClass slot got ret 0 while its real ??_E callers need ret 4 -> crash at 2.5 s); slot truth only fills
    # names whose signature is unknown, and func_<X> (address truth)
    if n.startswith('?') and ms.signature_ret_bytes(n) is not None:
        ov.pop(n, None); continue
    if n.startswith('func_'):   # address truth only (quicktest._ret uses it already); slot votes of folded entries lied
        ov.pop(n, None)
        want = ms.addr_ret_bytes(int(n[5:], 16))
    if have is not None and have != want:
        bad.append((n, have, want)); ov[n] = want
pf.write_text(json.dumps(ov, indent=0, sort_keys=True))
# the original function a vtable-slot stub stands for (one candidate only): glue.py rebuilds trivial ones
_sa = H / 'auto/stubret_addr.json'
try:
    sa = json.loads(_sa.read_text())
except (OSError, ValueError):
    sa = {}
sa.update({n: '%08x' % next(iter(c)) for n, c in slot_addr.items() if len(c) == 1 and not n.startswith('func_')})
_sa.write_text(json.dumps(sa, indent=0, sort_keys=True))
print('stubs with an original-binary truth: %d (vtable %d vtables), wrong pop size: %d' % (len(truth), len(vaddr), len(bad)))
for x in bad[:15]:
    print('  %-90s ret %s -> %s' % (x[0][:90], x[1], x[2]))
