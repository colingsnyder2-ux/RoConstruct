"""python retdiff.py [EXE MAP]: functions in our link whose stack cleanup (first `ret N`) differs from the original
function at the same identity (func_<addr>, or the registry's real name for that address). A mismatch unbalances every
caller's stack (a ret then pops garbage: the 1/30 s step float became the return address). Writes auto/retdiff.json,
prints mismatches (stubs excluded). Seconds."""
import json, re, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
O = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
Q = pefile.PE(exe, fast_load=True).get_memory_mapped_image()


def retn(img, a, n=0x3000):
    o = a - 0x400000
    for i in md.disasm(bytes(img[o:o + n]), a):
        if i.mnemonic == 'ret':
            return int(i.op_str, 16) if i.op_str else 0
        if i.mnemonic in ('jmp', 'int3'):
            return None   # tail jump / thunk / padding before any ret: the cleanup is the target's, unknown here
    return None


ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
byname = {}
for a, v in ff.items():
    n = (v or {}).get('name') or ''
    if n.startswith('?'):
        byname.setdefault(n, []).append(a)
out = []
seen = set()
for m in re.finditer(r'^\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(\S+)', open(mp, errors='replace').read(), re.M):
    name, va, obj = m.group(1), int(m.group(2), 16), m.group(3)
    if 'stubs' in obj or va in seen:
        continue
    f = re.fullmatch(r'(?:func_|@fn_|_fn_)([0-9a-f]{8})(?:@\d+)?', name)
    orig = f.group(1) if f else (byname[name][0] if len(byname.get(name, [])) == 1 else None)
    if not orig:
        continue
    seen.add(va)
    ro, rq = retn(O, int(orig, 16)), retn(Q, va)
    if ro is not None and rq is not None and ro != rq:
        out.append({'name': name, 'orig': orig, 'ours': '%08x' % va, 'obj': obj, 'orig_ret': ro, 'our_ret': rq})
(H / 'auto/retdiff.json').write_text(json.dumps(out, indent=1))
print('%d functions pop a different number of argument bytes than the original' % len(out))
for r in out[:25]:
    print('  %s ret%d vs ours ret%d  %-14s %s' % (r['orig'], r['orig_ret'], r['our_ret'], r['obj'][-14:], r['name'][:70]))
