"""python stubret_all.py: every `ret N` stub in our link vs the original function's own stack-pop count (first ret in its
body; a tail-jump body ending in `jmp reg/mem` = depends on the target). A stub reached through a function pointer or
vtable with the wrong N shifts the caller's stack (boost::function invoker func_005a19e0: ret 8 vs a tail jump ->
CValueItem resumed mid-function, TTD trace). Writes auto/stubret_all.json."""
import json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image(); B = 0x400000
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True); qi = q.get_memory_mapped_image(); qb = q.OPTIONAL_HEADER.ImageBase
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
byname = {v['name']: int(k, 16) for k, v in reg.items() if (v or {}).get('name') and re.fullmatch(r'[0-9a-f]{8}', k)}
def oret(a):
    for i in md.disasm(bytes(o[a - B:a - B + 0x2000]), a):
        if i.mnemonic == 'ret':
            return int(i.op_str, 0) if i.op_str else 0
        if i.mnemonic == 'jmp' and not i.op_str.startswith('0x'):
            return 'tailjmp'
        if i.mnemonic == 'int3':
            return None
    return None
bad = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) < 4 or not p[0].startswith('0001:') or 'stubs' not in p[-1]:
        continue
    n, va = p[1], int(p[2], 16)
    a = int(n[5:], 16) if re.fullmatch(r'func_[0-9a-f]{8}', n) else byname.get(n)
    if not a or not B + 0x1000 <= a < B + 0x400000:
        continue
    ins = list(md.disasm(bytes(qi[va - qb:va - qb + 12]), va))
    sret = next((int(i.op_str, 0) if i.op_str else 0 for i in ins if i.mnemonic == 'ret'), None)
    r = oret(a)
    if sret is not None and r is not None and r != sret:
        bad.append({'stub': n, 'orig': '%08x' % a, 'stub_ret': sret, 'orig_ret': r})
json.dump(bad, open(H / 'auto/stubret_all.json', 'w'), indent=0)
import collections
print('stubs with a wrong ret: %d (tail-jump originals %d)' % (len(bad), sum(1 for b in bad if b['orig_ret'] == 'tailjmp')))
print(collections.Counter((b['stub_ret'], b['orig_ret']) for b in bad).most_common(8))
