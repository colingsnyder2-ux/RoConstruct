"""Parse the TPI stream of WebService.pdb (RBXGS Dec 2007) into class layouts.
  python pdb_types.py [PDB] [OUT.json]
Output: {class: {size, bases:[[name,off]], members:[[name,type,off]], methods:[names], vtable:bool}}
Forward-declared classes are skipped; duplicates keep the largest definition."""
import json, struct, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_pdb import streams

BASIC = {0: 'void', 3: 'void', 0x10: 'char', 0x20: 'uchar', 0x11: 'short', 0x21: 'ushort', 0x12: 'long',
         0x22: 'ulong', 0x13: 'int64', 0x23: 'uint64', 0x30: 'bool', 0x40: 'float', 0x41: 'double',
         0x70: 'char', 0x71: 'wchar_t', 0x74: 'int', 0x75: 'unsigned', 0x76: 'int64', 0x77: 'uint64',
         0x68: 'char', 0x69: 'uchar', 0x72: 'short', 0x73: 'ushort', 0x7a: 'wchar_t'}


def num(b, p):
    v = struct.unpack_from('<H', b, p)[0]
    if v < 0x8000:
        return v, p + 2
    sz = {0x8000: ('<b', 1), 0x8001: ('<h', 2), 0x8002: ('<H', 2), 0x8003: ('<i', 4), 0x8004: ('<I', 4),
          0x8009: ('<q', 8), 0x800a: ('<Q', 8)}[v]
    return struct.unpack_from(sz[0], b, p + 2)[0], p + 2 + sz[1]


def cstr(b, p):
    e = b.index(b'\0', p)
    return b[p:e].decode('latin-1'), e + 1


def records(t):
    hs = struct.unpack_from('<I', t, 4)[0]
    pos, idx, out = hs, 0x1000, {}
    while pos + 4 <= len(t):
        ln, leaf = struct.unpack_from('<HH', t, pos)
        out[idx] = (leaf, t[pos + 4:pos + 2 + ln])
        pos += ln + 2
        idx += 1
    return out


def main(pdb, outp):
    recs = records(streams(pdb)[2])
    cache = {}

    def tname(i, d=0):
        if i < 0x1000:
            base = BASIC.get(i & 0xff if i & 0xf00 == 0 else i & 0x80ff, 'T%x' % i)
            return base + ('*' if i & 0x700 else '')
        if i in cache:
            return cache[i]
        if d > 6 or i not in recs:
            return '?'
        leaf, b = recs[i]
        if leaf in (0x1504, 0x1505):
            r = cstr(b, num(b, 16)[1])[0]
        elif leaf == 0x1506:
            r = cstr(b, num(b, 8)[1])[0]
        elif leaf == 0x1001:
            r = ('const ' if struct.unpack_from('<H', b, 4)[0] & 1 else '') + tname(struct.unpack_from('<I', b)[0], d + 1)
        elif leaf == 0x1002:
            a = struct.unpack_from('<I', b, 4)[0]
            r = tname(struct.unpack_from('<I', b)[0], d + 1) + ('&' if (a >> 5) & 7 == 1 else '*')
        elif leaf == 0x1503:
            et, _, sz = struct.unpack_from('<II', b)[0], 0, num(b, 8)[0]
            r = '%s[%d bytes]' % (tname(et, d + 1), sz)
        elif leaf == 0x1507:
            r = 'enum ' + cstr(b, 16)[0]
        elif leaf == 0x1008 or leaf == 0x1009:
            r = 'fn'
        else:
            r = 'T%x' % leaf
        cache[i] = r
        return r

    def fields(fl, seen=None):
        res = {'bases': [], 'members': [], 'methods': [], 'vfunc': False}
        while fl in recs and recs[fl][0] == 0x1203:
            b, p, nxt = recs[fl][1], 0, None
            while p < len(b):
                if b[p] >= 0xf0:
                    p += b[p] & 0xf; continue
                k = struct.unpack_from('<H', b, p)[0]; p += 2
                if k == 0x1400 or k == 0x1401 or k == 0x1402:  # bclass
                    t = struct.unpack_from('<I', b, p + 2)[0]
                    if k == 0x1400:
                        off, p = num(b, p + 6)
                    else:
                        p += 10; _, p = num(b, p); off, p = num(b, p)
                        off = ('virtual', off)
                    res['bases'].append([tname(t), off])
                elif k == 0x150d:
                    t = struct.unpack_from('<I', b, p + 2)[0]
                    off, p = num(b, p + 6); n, p = cstr(b, p)
                    res['members'].append([n, tname(t), off])
                elif k == 0x150e:
                    p += 6; n, p = cstr(b, p)
                elif k == 0x150f:
                    p += 6; n, p = cstr(b, p); res['methods'].append(n)
                elif k == 0x1511:
                    attr = struct.unpack_from('<H', b, p)[0]; p += 6
                    if (attr >> 2) & 7 in (4, 6):
                        p += 4
                    n, p = cstr(b, p); res['methods'].append(n)
                elif k == 0x1409:
                    p += 6; res['vfunc'] = True
                elif k == 0x1502:
                    p += 2; _, p = num(b, p); n, p = cstr(b, p)
                elif k == 0x1510:
                    p += 6; n, p = cstr(b, p)
                elif k == 0x1404:
                    nxt = struct.unpack_from('<I', b, p + 2)[0]; p += 6
                else:
                    raise ValueError('field leaf %x' % k)
            if nxt is None:
                break
            fl = nxt  # continuation: merge
            r2 = fields(fl)
            for key in ('bases', 'members', 'methods'):
                res[key] += r2[key]
            res['vfunc'] |= r2['vfunc']
            break
        return res

    out = {}
    for i, (leaf, b) in recs.items():
        if leaf not in (0x1504, 0x1505):
            continue
        cnt, prop, fl, der, vs = struct.unpack_from('<HHIII', b)
        if prop & 0x80:  # fwdref
            continue
        size, p = num(b, 16)
        name, _ = cstr(b, p)
        f = fields(fl)
        ent = {'size': size, 'bases': f['bases'], 'members': f['members'],
               'methods': sorted(set(f['methods'])), 'vtable': bool(vs) or f['vfunc']}
        if name not in out or len(ent['members']) + len(ent['methods']) > len(out[name]['members']) + len(out[name]['methods']):
            out[name] = ent
    Path(outp).write_text(json.dumps(out, indent=1))
    print(len(recs), 'records', len(out), 'classes')


if __name__ == '__main__':
    a = sys.argv[1:]
    main(a[0] if a else str(Path(__file__).parent / 'layout/inputs/WebService.pdb'),
         a[1] if len(a) > 1 else str(Path(__file__).parent / 'pdb-class-layouts.json'))
