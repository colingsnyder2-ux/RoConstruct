"""python dis_linked.py ADDR [N]: disasm the donor-free exe (link/donorfree.exe) with map symbols for call targets."""
import sys, re, struct, capstone, bisect
exe = open('work/donorfree-route/link/donorfree.exe', 'rb').read()
txt = open('work/donorfree-route/link/donorfree.map', errors='replace').read()
syms = sorted((int(m.group(2), 16), m.group(1)) for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', txt, re.M))
keys = [s[0] for s in syms]
def near(a):
    i = bisect.bisect_right(keys, a) - 1
    return '%08x %s+%x' % (a, syms[i][1][:80], a - syms[i][0]) if i >= 0 else '%08x' % a
pe = struct.unpack_from('<I', exe, 0x3c)[0]
nsec = struct.unpack_from('<H', exe, pe + 6)[0]; opt = struct.unpack_from('<H', exe, pe + 20)[0]
base = struct.unpack_from('<I', exe, pe + 24 + 28)[0]
secs = [struct.unpack_from('<IIII', exe, pe + 24 + opt + 40 * i + 8) for i in range(nsec)]
def off(v):
    r = v - base
    for vs, va, rs, ro in secs:
        if va <= r < va + max(vs, rs): return ro + r - va
a = int(sys.argv[1], 16); n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
print(near(a))
for i in capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(exe[off(a):off(a) + n], a):
    op = i.op_str
    if i.mnemonic == 'call' and op.startswith('0x'): op += '   ; ' + near(int(op, 16))
    print('%08x %s %s' % (i.address, i.mnemonic, op))
