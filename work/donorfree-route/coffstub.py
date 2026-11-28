"""Write stubs.obj directly (no MASM): .text with one stub per function (mov eax,imm32; ret [n]), .data with data stubs.
write(path, funcs=[(name, imm, ret_n)], data=[(name, initial_bytes, size)] or [(name, initial_bytes, size, relocs)])
relocs = [(offset_in_item, symbol_name)]: a DIR32 pointer to that symbol (function tables inside dat_ placeholders: boost
function managers, callback tables; a zeroed pointer there is a guaranteed null call). i386 COFF, external symbols."""
import struct


def write(path, funcs, data):
    text = bytearray()
    syms = []                       # (name, section, value, type, class)
    trel = []                       # (offset in .text, target symbol, type 6 DIR32 / 0x14 REL32)
    for item in funcs:
        name, imm, n = item[:3]
        syms.append((name, 1, len(text), 0x20, 2))
        for off_, sym_, ty_ in (item[3] if len(item) > 3 else ()):   # relocations inside a custom body
            trel.append((len(text) + off_, sym_, ty_))
        text += bytes(imm) if isinstance(imm, (bytes, bytearray)) else (b'\xb8' + struct.pack('<I', imm & 0xffffffff))   # bytes: custom body
        if n != -1:   # -1: the body ends itself (jmp thunk)
            text += (b'\xc2' + struct.pack('<H', n)) if n else b'\xc3'
        while len(text) % 4:
            text += b'\xcc'
    dat = bytearray()
    rel = []                        # (offset in .data, target symbol name)
    for item in data:
        name, init, size = item[:3]
        relocs = item[3] if len(item) > 3 else ()
        aliases = item[4] if len(item) > 4 else ()   # [(symbol, offset in this item)]: several globals in one block
        while len(dat) % 16:
            dat += b'\0'
        base = len(dat)
        syms.append((name, 2, base, 0, 2))
        for an, ao in aliases:
            syms.append((an, 2, base + ao, 0, 2))
        blob = bytearray(bytes(init[:size]) + bytes(max(0, size - len(init))))
        for off, target in relocs:
            if 0 <= off <= size - 4:
                blob[off:off + 4] = bytes(4)   # DIR32 adds the stored value: keep it 0
                rel.append((base + off, target))
        dat += blob
    ext = {}
    for _, t, _ty in trel:
        ext.setdefault(t, None)
    for _, t in rel:                # referenced targets: undefined externals unless defined here
        if t not in ext and not any(s[0] == t for s in syms[:0]):
            ext[t] = None
    defined = {s[0]: i for i, s in enumerate(syms)}
    for t in ext:
        if t not in defined:
            defined[t] = len(syms)
            syms.append((t, 0, 0, 0x20, 2))
    hdr_end = 20 + 40 * 2
    text_ptr = hdr_end
    data_ptr = text_ptr + len(text)
    trel_ptr = data_ptr + len(dat)
    trelbytes = b''.join(struct.pack('<IIH', off, defined[t], ty) for off, t, ty in trel)
    rel_ptr = trel_ptr + len(trelbytes)
    relbytes = b''.join(struct.pack('<IIH', off, defined[t], 0x06) for off, t in rel)
    sym_ptr = rel_ptr + len(relbytes)
    nrel = len(rel)
    strtab = bytearray(4)
    st = bytearray()
    for name, sec, val, typ, cls in syms:
        nb = name.encode('latin-1')
        if len(nb) <= 8:
            raw = nb.ljust(8, b'\0')
        else:
            raw = struct.pack('<II', 0, len(strtab))
            strtab += nb + b'\0'
        st += raw + struct.pack('<IhHBB', val, sec, typ, cls, 0)
    struct.pack_into('<I', strtab, 0, len(strtab))
    dch = 0xC0500040 | (0x01000000 if nrel > 0xffff else 0)
    out = bytearray(struct.pack('<HHIIIHH', 0x14c, 2, 0, sym_ptr, len(syms), 0, 0))
    out += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, len(text), text_ptr, trel_ptr if trel else 0, 0, len(trel), 0, 0x60500020)   # code, 16-byte align, r-x
    out += struct.pack('<8sIIIIIIHHI', b'.data', 0, 0, len(dat), data_ptr, rel_ptr if nrel else 0, 0,
                       min(nrel, 0xffff), 0, dch)
    if nrel > 0xffff:   # IMAGE_SCN_LNK_NRELOC_OVFL: the real count sits in the first relocation's VirtualAddress
        relbytes = struct.pack('<IIH', nrel + 1, 0, 0) + relbytes
        sym_ptr += 10
        struct.pack_into('<I', out, 8, sym_ptr)
    out += text + dat + trelbytes + relbytes + st + strtab
    open(path, 'wb').write(out)


if __name__ == '__main__':   # self-check: round-trip symbol names, stub bytes, one data relocation
    import os, tempfile
    p = os.path.join(tempfile.gettempdir(), 'coffstub_test.obj')
    write(p, [('?f@@YAXXZ', 0, 4), ('_g', 1, 0)], [('dat_00401000', b'\x01\x02\x03\x04\x05\x06\x07\x08', 16, [(4, '?f@@YAXXZ')])])
    b = open(p, 'rb').read()
    assert b[:2] == b'\x4c\x01' and b'?f@@YAXXZ' in b and b'\xb8\x00\x00\x00\x00\xc2\x04\x00' in b
    nrel = struct.unpack_from('<H', b, 20 + 40 + 32)[0]
    assert nrel == 1, nrel
    write(p, [('_t', b'\x83\xc1\xe0\xe9\0\0\0\0', -1, [(4, '_tgt', 0x14)]), ('_tgt', 0, 0)], [])
    b = open(p, 'rb').read()
    assert struct.unpack_from('<H', b, 20 + 32)[0] == 1 and b'\x83\xc1\xe0\xe9\0\0\0\0\xb8' in b
    print('ok', len(b))
