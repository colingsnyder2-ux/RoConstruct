"""python pathdiff.py ORIG_ADDR OUR_ADDR [--depth N]: walk the original exe and our linked exe in parallel from a pair of
function addresses, following direct calls/jumps pairwise, and report every function whose instruction stream differs
(operands holding addresses are masked). Finds where our build behaves differently without running it."""
import re, sys
import capstone, pefile
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
po = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe')); bo = bytes(po.get_memory_mapped_image())
import os
pn = pefile.PE(os.environ.get('PD_EXE') or str(H / 'link/donorfree.exe')); bn = bytes(pn.get_memory_mapped_image())
names = {}
for l in open(os.environ.get('PD_MAP') or (H / 'link/donorfree.map'), errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
    if m:
        names.setdefault(int(m.group(2), 16), m.group(1))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
depth = int(sys.argv[sys.argv.index('--depth') + 1]) if '--depth' in sys.argv else 6
MASK = re.compile(r'0x[0-9a-f]{5,8}')


def body(b, a):
    out = []
    try:
        for i in md.disasm(b[a - 0x400000:a - 0x400000 + 0x1000], a):
            out.append(i)
            if i.mnemonic in ('ret', 'int3') or (i.mnemonic == 'jmp' and not i.op_str.startswith('0x')):
                break
            if len(out) > 400:
                break
    except Exception:
        pass
    return out


seen = set()


def walk(a, c, d):
    if (a, c) in seen or d > depth:
        return
    seen.add((a, c))
    A, B = body(bo, a), body(bn, c)
    sa = [i.mnemonic + ' ' + MASK.sub('X', i.op_str) for i in A]
    sb = [i.mnemonic + ' ' + MASK.sub('X', i.op_str) for i in B]
    if sa != sb:
        k = next((j for j in range(min(len(sa), len(sb))) if sa[j] != sb[j]), min(len(sa), len(sb)))
        print('DIFF depth %d: orig %08x vs ours %08x %s' % (d, a, c, names.get(c, '')[:80]))
        print('   at insn %d: orig "%s" | ours "%s"' % (k, sa[k] if k < len(sa) else '-', sb[k] if k < len(sb) else '-'))
        return
    for x, y in zip(A, B):
        if x.mnemonic in ('call', 'jmp') and x.op_str.startswith('0x') and y.op_str.startswith('0x'):
            ta, tc = int(x.op_str, 16), int(y.op_str, 16)
            if not (a <= ta < a + 0x1000 and c <= tc < c + 0x1000 and x.mnemonic == 'jmp'):   # skip intra-function jumps
                walk(ta, tc, d + 1)


walk(int(sys.argv[1], 16), int(sys.argv[2], 16), 0)
print('compared %d function pairs' % len(seen))
