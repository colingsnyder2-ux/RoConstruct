"""Read public symbols (S_PUB32) from an MSF 7.00 PDB and map them to image addresses.

  python identity_unlock_pdb.py PDB DLL OUT.json
Writes {"%08x" va: decorated name} for every public symbol in a code section of DLL, and
OUT-procs.json {"%08x" va: [[qualified name, length, global|static], ...]} from module streams.
Used for WebService.pdb (RBXGS 0.3.676, Dec 2007), which ships in tools/rbxgs_msi/rbxgs676.msi.
"""
import json
from identity_unlock_common import dump_json  # noqa: E402
import struct
import sys

import pefile


def streams(path):
    data = open(path, 'rb').read()
    assert data.startswith(b'Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0')
    bs, _, nblocks, dirsize, _, mapaddr = struct.unpack_from('<6I', data, 32)
    nb = (dirsize + bs - 1) // bs
    dir_blocks = struct.unpack_from('<%dI' % nb, data, mapaddr * bs)
    d = b''.join(data[b * bs:(b + 1) * bs] for b in dir_blocks)[:dirsize]
    n = struct.unpack_from('<I', d, 0)[0]
    sizes = struct.unpack_from('<%dI' % n, d, 4)
    pos, out = 4 + 4 * n, []
    for sz in sizes:
        if sz == 0xffffffff:
            out.append(b'')
            continue
        k = (sz + bs - 1) // bs
        blocks = struct.unpack_from('<%dI' % k, d, pos)
        pos += 4 * k
        out.append(b''.join(data[b * bs:(b + 1) * bs] for b in blocks)[:sz])
    return out


def publics(pdb):
    st = streams(pdb)
    dbi = st[3]
    sym_rec = struct.unpack_from('<H', dbi, 20)[0]
    rec, pos, out = st[sym_rec], 0, []
    while pos + 4 <= len(rec):
        ln, kind = struct.unpack_from('<HH', rec, pos)
        if kind == 0x110e:  # S_PUB32: flags, offset, segment, name
            flags, off, seg = struct.unpack_from('<IIH', rec, pos + 4)
            name = rec[pos + 14:rec.index(b'\0', pos + 14)].decode('latin-1')
            out.append((seg, off, flags, name))
        pos += ln + 2
    return out


def procs(pdb):
    """(seg, offset, length, kind, name) of every S_GPROC32 / S_LPROC32 in the module symbol
    streams (statics and folded functions included; names are qualified but undecorated)."""
    st = streams(pdb)
    dbi = st[3]
    mod_size = struct.unpack_from('<i', dbi, 24)[0]
    pos, end, out = 64, 64 + mod_size, []
    while pos < end:
        mstream, symsize = struct.unpack_from('<HI', dbi, pos + 34)
        p = pos + 64
        p = dbi.index(b'\0', p) + 1  # module name
        p = dbi.index(b'\0', p) + 1  # object file name
        pos = (p + 3) & ~3
        if mstream == 0xffff or mstream >= len(st):
            continue
        rec, q = st[mstream], 4
        while q + 4 <= min(symsize, len(rec)):
            ln, kind = struct.unpack_from('<HH', rec, q)
            if ln < 2:
                break
            if kind in (0x1110, 0x110f):  # S_GPROC32, S_LPROC32
                plen, = struct.unpack_from('<I', rec, q + 16)
                off, seg = struct.unpack_from('<IH', rec, q + 32)
                name = rec[q + 39:rec.index(b'\0', q + 39)].decode('latin-1')
                out.append((seg, off, plen, 'global' if kind == 0x1110 else 'static', name))
            q += ln + 2
    return out


def main(pdb, dll, outp):
    pe = pefile.PE(dll, fast_load=True)
    secs = pe.sections
    res = {}
    for seg, off, flags, name in publics(pdb):
        if not 1 <= seg <= len(secs):
            continue
        s = secs[seg - 1]
        if not s.Characteristics & 0x20000000:  # executable sections only
            continue
        res['%08x' % (pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress + off)] = name
    dump_json(res, outp)
    print('code publics', len(res))
    pr = {}
    for seg, off, plen, kind, name in procs(pdb):
        if 1 <= seg <= len(secs):
            pr.setdefault('%08x' % (pe.OPTIONAL_HEADER.ImageBase + secs[seg - 1].VirtualAddress + off),
                          []).append([name, plen, kind])
    dump_json(pr, outp.replace('.json', '-procs.json'))
    print('procs', sum(len(v) for v in pr.values()), 'addresses', len(pr),
          'not public', len(set(pr) - set(res)))


if __name__ == '__main__':
    main(*sys.argv[1:4])
