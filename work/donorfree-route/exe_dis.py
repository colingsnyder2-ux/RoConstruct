"""python exe_dis.py ADDR [ADDR...] [-n BYTES]  -> capstone disasm of the 2008-06 exe at virtual addresses (any start, not only function starts)."""
import sys, struct
sys.path.insert(0, '.')
from roc import clients
import capstone
exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
pe = struct.unpack_from('<I', exe, 0x3c)[0]
nsec = struct.unpack_from('<H', exe, pe + 6)[0]; opt = struct.unpack_from('<H', exe, pe + 20)[0]
base = struct.unpack_from('<I', exe, pe + 24 + 28)[0]
secs = []
for i in range(nsec):
    o = pe + 24 + opt + 40 * i
    vs, va, rs, ro = struct.unpack_from('<IIII', exe, o + 8)
    secs.append((va, max(vs, rs), ro))
def off(v):
    r = v - base
    for va, sz, ro in secs:
        if va <= r < va + sz: return ro + r - va
args = sys.argv[1:]; n = 0x100
if '-n' in args:
    i = args.index('-n'); n = int(args[i + 1], 0); del args[i:i + 2]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for a in args:
    v = int(a, 16); print('==', a)
    for ins in md.disasm(exe[off(v):off(v) + n], v):
        print('%08x %s %s' % (ins.address, ins.mnemonic, ins.op_str))
        if ins.mnemonic == 'ret' and ins.address > v + 8: break
