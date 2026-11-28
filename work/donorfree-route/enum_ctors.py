"""List every EnumDescriptor(name,type_info) ctor call site (0056c590) in the 2008-06 exe with the pushed strings and addPair (0064d530) calls."""
import sys, struct, re
sys.path.insert(0, '.')
exec(open('work/donorfree-route/exe_dis.py').read().split("args = sys.argv")[0])
text = [(va, sz, ro) for va, sz, ro in secs][0]
tva, tsz, tro = text
code = exe[tro:tro + tsz]
T = 0x56c590
sites = []
for i in range(len(code) - 5):
    if code[i] == 0xe8:
        rel = struct.unpack_from('<i', code, i + 1)[0]
        if base + tva + i + 5 + rel == T: sites.append(base + tva + i)
print(len(sites), 'call sites')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
def cstr(v):
    o = off(v)
    if o is None: return None
    s = exe[o:o + 60].split(b'\0')[0]
    return s.decode('latin-1') if s and all(32 <= c < 127 for c in s) else None
for s in sites:
    st = s
    while exe[off(st) - 1] != 0xcc and exe[off(st) - 1] != 0x90: st -= 1   # int3 / nop padding before the function
    out = []
    for ins in md.disasm(exe[off(st):off(st) + 0x400], st):
        if ins.mnemonic == 'push' and ins.op_str.startswith('0x') and cstr(int(ins.op_str, 16)): out.append(repr(cstr(int(ins.op_str, 16))))
        elif ins.mnemonic == 'push' and ins.op_str.startswith('0x'): out.append(ins.op_str)
        elif ins.mnemonic == 'push' and ins.op_str.isdigit(): out.append(ins.op_str)
        elif ins.mnemonic == 'ret': break
    print('%08x' % st, ' '.join(out)[:900])
