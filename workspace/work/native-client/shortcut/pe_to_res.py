"""Convert a PE file's .rsrc tree into a Win32 .res file the linker accepts.  python pe_to_res.py EXE OUT.res"""
import struct, sys
data = open(sys.argv[1], 'rb').read()
pe = struct.unpack_from('<I', data, 0x3c)[0]
nsec, opt = struct.unpack_from('<H', data, pe + 6)[0], struct.unpack_from('<H', data, pe + 20)[0]
secs = [struct.unpack_from('<IIII', data, pe + 24 + opt + 40 * i + 8) for i in range(nsec)]
rsrc_rva = struct.unpack_from('<I', data, pe + 24 + 96 + 16)[0]
def at(rva):
    for vs, base, rs, rp in secs:
        if base <= rva < base + max(vs, rs): return rp + rva - base
    raise ValueError(rva)
root = at(rsrc_rva)
def entries(off):
    _, _, _, nn, ni = struct.unpack_from('<IIHHHH', data, off)[0:5] if False else (0, 0, 0, *struct.unpack_from('<HH', data, off + 12))
    out = []
    for i in range(nn + ni):
        name, ptr = struct.unpack_from('<II', data, off + 16 + 8 * i)
        out.append((name, ptr))
    return out
def ident(v):
    if v & 0x80000000:
        o = root + (v & 0x7fffffff); n = struct.unpack_from('<H', data, o)[0]
        return data[o + 2:o + 2 + 2 * n].decode('utf-16le')
    return v
def idbytes(v):
    if isinstance(v, int): return struct.pack('<HH', 0xffff, v)
    return (v.upper() + '\0').encode('utf-16le')
out = bytearray()
def emit(type_, name, lang, blob):
    hdr = idbytes(type_) + idbytes(name)
    hdr += b'\0' * (-len(hdr) % 4)
    size = 8 + len(hdr) + 16
    body = struct.pack('<II', len(blob), size) + hdr + struct.pack('<IHHII', 0, 0x1030, lang, 0, 0)
    # note: memory flags/language order per .res spec: DataVersion(4) MemoryFlags(2) LanguageId(2) Version(4) Characteristics(4)
    out.extend(body[:8 + len(hdr)] + struct.pack('<IHHII', 0, 0x1030, lang, 0, 0))
    out.extend(blob); out.extend(b'\0' * (-len(out) % 4))
out.extend(struct.pack('<II', 0, 32) + struct.pack('<HHHH', 0xffff, 0, 0xffff, 0) + struct.pack('<IHHII', 0, 0, 0, 0, 0))
count = 0
for tv, tp in entries(root):
    t = ident(tv)
    for nv, np_ in entries(root + (tp & 0x7fffffff)):
        n = ident(nv)
        for lv, lp in entries(root + (np_ & 0x7fffffff)):
            rva, size = struct.unpack_from('<II', data, root + lp)
            emit(t, n, lv if isinstance(lv, int) else 0, data[at(rva):at(rva) + size]); count += 1
open(sys.argv[2], 'wb').write(out); print(count, 'resources', len(out), 'bytes')
