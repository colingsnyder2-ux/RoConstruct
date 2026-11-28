"""python analogmap.py ADDR [ADDR...]: for converted objects renamed/obj/<ADDR>.obj, line up the function's call
relocations with the ORIGINAL function's call instructions (same offsets in an exact object) and print which ORIGINAL
target each analog callee name stands for. An analog name (?skipWhitespace@TextXmlParser@@) that our link binds to a
native draft runs the draft's code instead of the original target. Prints rename lines NAME -> func_<target>."""
import json, struct, sys
import capstone, pefile
from pathlib import Path
H = Path(__file__).parent
reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def fn_calls(path, sym):
    d = open(path, 'rb').read()
    _, ns, _, sp, nsym, opt, _ = struct.unpack_from('<HHIIIHH', d, 0); st = sp + nsym * 18

    def nm(i):
        o_ = sp + 18 * i; r = d[o_:o_ + 8]
        if r[:4] == b'\0\0\0\0':
            s = st + struct.unpack_from('<I', r, 4)[0]; return d[s:d.find(b'\0', s)].decode('latin1')
        return r.rstrip(b'\0').decode('latin1')
    sec = None; i = 0
    while i < nsym:
        if nm(i) == sym:
            sec = struct.unpack_from('<h', d, sp + 18 * i + 12)[0]
        i += 1 + d[sp + 18 * i + 17]
    if not sec or sec < 1:
        return None, []
    sh = 20 + opt + 40 * (sec - 1)
    size, praw, prel = struct.unpack_from('<III', d, sh + 16); nrel = struct.unpack_from('<H', d, sh + 32)[0]
    res = []
    for r in range(nrel):
        va, si, ty = struct.unpack_from('<IIH', d, prel + 10 * r)
        if ty == 0x14 and va >= 1 and d[praw + va - 1] == 0xe8:
            res.append((va - 1, nm(si)))
    return size, sorted(res)


if __name__ == '__main__':
    out = {}
    for a in sys.argv[1:]:
        A = int(a, 16)
        size, cc = fn_calls(H / 'renamed/obj' / (a + '.obj'), 'func_' + a)
        if size is None:
            print(a, 'no func_ symbol'); continue
        oc = {i.address - A: int(i.op_str, 16) for i in md.disasm(bytes(o[A - 0x400000:A - 0x400000 + size]), A)
              if i.mnemonic == 'call' and i.op_str.startswith('0x')}
        for off, n in cc:
            t = oc.get(off)
            if t and not n.startswith('func_') and not n.startswith('__imp_'):
                out.setdefault(n, set()).add('func_%08x' % t)
    for n, v in sorted(out.items()):
        print('%s -> %s' % (n, ','.join(sorted(v))))
