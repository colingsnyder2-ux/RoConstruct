"""python stub_reach.py [--depth N]: static crash forecast for the linked donor-free exe, no run.
Walks direct calls in link/donorfree.exe from File->New entry points (CIDEDocManager::OnFileNew, CRobloxView::OnInitialUpdate,
CRobloxWnd::OnCreate/createRenderer/setDataModel) and lists every reachable call into stubs.obj (an empty placeholder) or
to the image base (unresolved). Each line: depth, target, first caller chain. Writes auto/stub_reach.txt."""
import bisect, re, sys
from collections import deque
from pathlib import Path
import capstone, pefile

H = Path(__file__).parent
depth_max = int(sys.argv[sys.argv.index('--depth') + 1]) if '--depth' in sys.argv else 12
pe = pefile.PE(str(H / 'link/donorfree.exe'), fast_load=True)
img = pe.get_memory_mapped_image()
base = pe.OPTIONAL_HEADER.ImageBase
syms, obj_of = [], {}
for l in open(H / 'link/donorfree.map', errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)\s*$', l)
    if m:
        a = int(m.group(2), 16)
        syms.append((a, m.group(1)))
        obj_of.setdefault(a, m.group(3))
syms.sort()
starts = [a for a, _ in syms]
name_at = {}
for a, n in syms:
    name_at.setdefault(a, n)
roots = [a for a, n in syms if n.startswith(('?OnFileNew@CIDEDocManager', '?OnInitialUpdate@CRobloxView', '?OnCreate@CRobloxWnd',
                                            '?createRenderer@CRobloxWnd', '?setDataModel@CRobloxWnd',
                                            '?handle@CRobloxWnd', '?doRender', '?render@', '?OnPaint@CRobloxView', '?OnTimer@',
                                            '?runProc@RunService', '?step@'))]   # render loop too: timer -> doRender, paint, run service
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
seen = {r: (0, None) for r in roots}
q = deque(roots)
hits = {}
ABI = []
PREV = {}
while q:
    a = q.popleft()
    d, _ = seen[a]
    if d >= depth_max:
        continue
    i = bisect.bisect_right(starts, a)
    end = starts[i] if i < len(starts) else a + 0x1000
    o = a - base
    _prev = None
    for ins in md.disasm(img[o:o + min(end - a, 0x6000)], a):
        PREV[ins.address] = _prev; _prev = ins.mnemonic
        if ins.mnemonic != 'call' or not ins.op_str.startswith('0x'):
            continue
        t = int(ins.op_str, 16)
        if t < base + 0x1000:
            hits.setdefault(('UNRESOLVED', ins.address), (d + 1, a))
            continue
        if obj_of.get(t) == 'stubs.obj':
            hits.setdefault((name_at.get(t, hex(t)), t), (d + 1, a))
            # ABI check: caller cleanup (add esp after the call) vs the stub's own ret N
            try:
                nxt = next(md.disasm(img[ins.address + 5 - base:ins.address + 5 - base + 8], ins.address + 5))
                st = next(x for x in md.disasm(img[t - base:t - base + 16], t) if x.mnemonic == 'ret')
                rn = int(st.op_str, 16) if st.op_str else 0
                caller_cleans = nxt.mnemonic == 'add' and nxt.op_str.startswith('esp,')
                pushed = PREV.get(ins.address) == 'push'
                if (caller_cleans and rn) or (not caller_cleans and rn == 0 and pushed):
                    ABI.append('%s ret %d but caller cleans (%s) at %08x' % (name_at.get(t, hex(t))[:80], rn, nxt.op_str, ins.address))
            except StopIteration:
                pass
            continue
        if t not in seen and t in name_at:
            seen[t] = (d + 1, a)
            q.append(t)


def chain(a):
    out = []
    while a is not None and len(out) < 4:
        out.append(name_at.get(a, hex(a))[:50])
        a = seen.get(a, (0, None))[1]
    return ' <- '.join(out)


rows = sorted(hits.items(), key=lambda kv: kv[1][0])
lines = ['%2d  %-90s  via %s' % (d, n[:90], chain(caller)) for (n, _), (d, caller) in rows]
(H / 'auto/stub_reach.txt').write_text('\n'.join(lines) + '\n')
print('reachable functions %d; reachable stub/unresolved calls %d; stub ABI mismatches %d' % (len(seen), len(rows), len(ABI)))
for x in ABI[:20]:
    print('ABI', x)
print('\n'.join(lines[:15]))
