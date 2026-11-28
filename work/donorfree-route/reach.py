"""python reach.py [ROOT_ADDR ...] [--depth N]: direct-call reachability over the original 2008-06 exe from File->New roots,
classified against the donor-free link. Writes auto/reach.json and auto/reach_missing.txt (missing addresses, BFS order).
missing = reachable function whose name is not defined by any linked object, has no native index entry and no draft.
Indirect (vtable) calls are not followed; vtable-only callees show up later as stub hits."""
import bisect, json, re, sys
from collections import deque
from pathlib import Path
import capstone, pefile

H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import clients
exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
pe = pefile.PE(data=exe, fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
names = {int(a, 16): (r.get('name') or '') for a, r in ff.items()}
starts = sorted(names)
defined = set(json.loads((H / 'link/defined_cache.json').read_text()))
idx = json.loads((H / 'auto/native_index.json').read_text())
drafts = {p.stem[-8:] for p in (ROOT / 'rebuild/2008-06/native-classes').glob('AutoRecover_*.cpp')}
aliases = {}
for f in ('aliases.txt', 'aliases_auto.txt'):
    for l in (H / f).read_text().splitlines():
        m = re.search(r'_([0-9a-f]{8})(?:@|$)', l.split('=')[0])
        if m and '=' in l:
            aliases[m.group(1)] = l.split('=', 1)[1]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
args = [a for i, a in enumerate(sys.argv[1:], 1) if not a.startswith('--') and sys.argv[i - 1] != '--depth']
depth = int(sys.argv[sys.argv.index('--depth') + 1]) if '--depth' in sys.argv else 6
VTABLES = '--vtables' in sys.argv
# File->New: CIDEDocManager::OnFileNew 0040c..., CRobloxView::OnInitialUpdate, CRobloxWnd::setDataModel + message map handlers
roots = [int(a, 16) for a in args] or [a for a, n in names.items() if n.startswith(('?OnFileNew@CIDEDocManager', '?OnInitialUpdate@CRobloxView'))] + \
    [0x45f7b0, 0x45d550, 0x45fd80, 0x45aff0, 0x45eaa0, 0x45d7c0, 0x45cba0, 0x45b5d0, 0x45bf30, 0x45bf80,
     0x555190, 0x45beb0, 0x45c890] + [a for a, n in names.items() if n.startswith(('?render@', '?doRender', '?step@', '?runProc@'))]   # run thread + render loop


def callees(a):
    i = bisect.bisect_right(starts, a)
    end = starts[i] if i < len(starts) else a + 0x400
    o = pe.get_offset_from_rva(a - base)
    out = []
    for ins in md.disasm(exe[o:o + min(end - a, 0x4000)], a):
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x'):
            t = int(ins.op_str, 16)
            if t in names:
                out.append(t)
        elif VTABLES and ins.mnemonic == 'mov' and ins.op_str.startswith('dword ptr [') and '], 0x' in ins.op_str:
            out += vtable_entries(int(ins.op_str.rsplit('0x', 1)[1], 16))   # constructor installs a vtable: its slots are reachable
        if ins.mnemonic == 'int3':
            break
    return out


def vtable_entries(v):
    """slots of a vtable at v (an .rdata array of >= 2 known function starts), else []."""
    if not (0x700000 <= v < 0x900000):
        return []
    try:
        o = pe.get_offset_from_rva(v - base)
    except Exception:
        return []
    out = []
    for k in range(200):
        p = int.from_bytes(exe[o + 4 * k:o + 4 * k + 4], 'little')
        if p not in names:
            break
        out.append(p)
    return out if len(out) >= 2 else []


def status(a):
    h, n = '%08x' % a, names.get(a, '')
    if n in defined or (h in aliases and aliases[h] in defined):
        return 'native'
    if h in idx:
        return 'native-indexed'
    if h in drafts:
        return 'draft'
    if n.startswith('?') and re.search(r'@(boost|std|G3D|Ogre|ATL)@|CXTP|^\?\?\$|CWnd|CString', n):
        return 'vendor'
    return 'missing'


seen = {r: 0 for r in roots}
q = deque(roots)
order = []
while q:
    a = q.popleft()
    order.append(a)
    st = status(a)
    if seen[a] >= depth or st == 'vendor':
        continue
    for t in callees(a):
        if t not in seen and 0x401000 <= t < 0x6a0000:
            seen[t] = seen[a] + 1
            q.append(t)
rows = [{'addr': '%08x' % a, 'depth': seen[a], 'status': status(a), 'name': names.get(a, '')[:100]} for a in order]
(H / 'auto/reach.json').write_text(json.dumps(rows, indent=0))
miss = [r['addr'] for r in rows if r['status'] == 'missing']
(H / 'auto/reach_missing.txt').write_text('\n'.join(miss) + '\n')
from collections import Counter
print('reachable %d (depth <= %d): %s' % (len(rows), depth, dict(Counter(r['status'] for r in rows))))
print('missing by depth: %s' % dict(sorted(Counter(r['depth'] for r in rows if r['status'] == 'missing').items())))
print('first missing:', ' '.join(miss[:25]))
