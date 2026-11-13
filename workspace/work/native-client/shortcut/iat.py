"""python iat.py EXE VA...: name/ordinal of the import whose IAT slot is at each VA"""
import struct, sys
d = open(sys.argv[1], 'rb').read(); want = {int(a, 16) for a in sys.argv[2:]}
pe = struct.unpack_from('<I', d, 0x3c)[0]; nsec = struct.unpack_from('<H', d, pe + 6)[0]; opt = struct.unpack_from('<H', d, pe + 20)[0]
secs = [struct.unpack_from('<IIII', d, pe + 24 + opt + 40 * i + 8) for i in range(nsec)]
base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
def at(r):
    for vs, b, rs, rp in secs:
        if b <= r < b + max(vs, rs): return rp + r - b
tab = struct.unpack_from('<I', d, pe + 24 + 104)[0]
while True:
    ot, _, _, nm, ft = struct.unpack_from('<IIIII', d, at(tab))
    if not nm: break
    dll = d[at(nm):d.index(b'\0', at(nm))].decode(); i = 0
    while True:
        e = struct.unpack_from('<I', d, at(ot or ft) + 4 * i)[0]
        if not e: break
        if base + ft + 4 * i in want:
            print(hex(base + ft + 4 * i), dll, 'ord %d' % (e & 0xffff) if e & 0x80000000 else d[at(e) + 2:d.index(b'\0', at(e) + 2)].decode())
        i += 1
    tab += 20
