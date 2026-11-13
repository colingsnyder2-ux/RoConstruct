"""python dis.py EXE ADDR [before] [after]: disassemble around a VA of a linked exe with call targets named from the map."""
import sys, struct, re, bisect, capstone
exe, va = sys.argv[1], int(sys.argv[2], 16); b = int(sys.argv[3]) if len(sys.argv) > 3 else 60; a = int(sys.argv[4]) if len(sys.argv) > 4 else 20
d = open(exe, 'rb').read(); pe = struct.unpack_from('<I', d, 0x3c)[0]
nsec = struct.unpack_from('<H', d, pe + 6)[0]; opt = struct.unpack_from('<H', d, pe + 20)[0]
for i in range(nsec):
    o = pe + 24 + opt + 40 * i; n = d[o:o + 8]; vs, rva, rs, rp = struct.unpack_from('<IIII', d, o + 8)
    if n.startswith(b'.text'): tr, tp = rva, rp
off = tp + (va - 0x400000) - tr
txt = open(exe.replace('.exe', '.map'), errors='replace').read(); syms = []
for m in re.finditer(r'^\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', txt, re.M): syms.append((int(m.group(2), 16), m.group(1)))
syms.sort(); keys = [s[0] for s in syms]
def nm(x):
    i = bisect.bisect_right(keys, x) - 1; return '%s+%x' % (syms[i][1][:80], x - syms[i][0]) if i >= 0 else ''
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for ins in md.disasm(d[off - b:off + a], va - b):
    t = ''
    if ins.mnemonic == 'call' and ins.op_str.startswith('0x'): t = '  ; ' + nm(int(ins.op_str, 16))
    print(hex(ins.address), ins.mnemonic, ins.op_str, t, '<<<' if ins.address == va else '')
