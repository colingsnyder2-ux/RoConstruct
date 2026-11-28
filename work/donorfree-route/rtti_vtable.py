"""Exe vtable of a class by its RTTI decorated name: python rtti_vtable.py '.?AV...' [slots]"""
import json, struct, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]; sys.path.insert(0, str(ROOT))
from roc import clients
exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
pe = struct.unpack_from('<I', exe, 0x3c)[0]; nsec = struct.unpack_from('<H', exe, pe + 6)[0]; opt = struct.unpack_from('<H', exe, pe + 20)[0]
secs = [struct.unpack_from('<8sIIII', exe, pe + 24 + opt + 40 * i) for i in range(nsec)]
def va(off):
    for _, vs, vaddr, rs, rp in secs:
        if rp <= off < rp + rs: return 0x400000 + vaddr + off - rp
def rd(v, n):
    r = v - 0x400000
    for _, vs, vaddr, rs, rp in secs:
        if vaddr <= r < vaddr + max(vs, rs): return exe[rp + r - vaddr: rp + r - vaddr + n]
def vtable(name):
    off = exe.find(name.encode() + bytes(1))
    if off < 0: return None
    td = va(off) - 8
    tdb = struct.pack('<I', td)
    pos = 0
    while True:
        pos = exe.find(tdb, pos + 1)
        if pos < 0: return None
        col = va(pos) - 12
        if struct.unpack_from('<I', rd(col, 4))[0] == 0 and struct.unpack_from('<I', rd(col + 4, 4))[0] == 0:
            cb = struct.pack('<I', col); vp = exe.find(cb)
            while vp >= 0:
                v = va(vp) + 4
                if 0x401000 <= struct.unpack_from('<I', rd(v, 4))[0] < 0x800000: return v
                vp = exe.find(cb, vp + 1)
if __name__ == '__main__':
    v = vtable(sys.argv[1]); slots = [int(x) for x in sys.argv[2:]] or list(range(14))
    print(hex(v) if v else None, ['%d:%08x' % (s, struct.unpack_from('<I', rd(v + 4 * s, 4))[0]) for s in slots] if v else '')
