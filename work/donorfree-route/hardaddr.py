"""Hard-coded original DATA addresses in converted objects. A converted source like 00467550.cpp passes
`(const void*)0x85012c` (GUID_SysMouse) and `(const void*)0x84ff0c` (c_dfDIMouse2) to DirectInput: in the original
those are data, in our exe they are stub code -> CreateDevice E_INVALIDARG -> AtlThrow -> "The parameter is
incorrect" and File->New aborts setDataModel. Such a cast compiles to an absolute immediate WITHOUT a relocation.

scan()  -> auto/hardaddr.json {obj addr: [data addresses cast to pointers in src/2008-06/<addr>.cpp]}
plan()  -> auto/hardaddr_plan.json {data addr: our symbol}: registry name defined in our map, else the natdata alias,
           else our dat_<addr> copy of the original data, else a data symbol of ours whose first 16 bytes equal the original's (GUIDs, DIDATAFORMATs, literals; unique
           matches only). Unresolved addresses are listed, never guessed.
patch(path, {addr: sym}, outdir) -> patched copy: each un-relocated 4-byte occurrence of the address in a section is
           zeroed and gets a DIR32 relocation to the symbol (appended undefined external).
python hardaddr.py: scan + plan + report (no link)."""
import bisect, glob, json, os, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
LO, HI = 0x802000, 0xa00000


def scan():
    res = {}
    for f in glob.glob(str(ROOT / 'src/2008-06/*.cpp')):
        vals = set()
        for m in re.finditer(r'\(\s*(?:const\s+)?[\w:<> ]+?\s*\*+\s*\)\s*\(?\s*(0x[0-9a-fA-F]{6,8})', open(f, errors='replace').read()):
            v = int(m.group(1), 16)
            if LO <= v < HI:
                vals.add('%08x' % v)
        if vals:
            res[Path(f).stem[:8]] = sorted(vals)
    (H / 'auto/hardaddr.json').write_text(json.dumps(res, indent=0))
    return res


def plan(scanres=None):
    import pefile
    scanres = scanres or json.loads((H / 'auto/hardaddr.json').read_text())
    addrs = sorted({a for v in scanres.values() for a in v})
    reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
    ours = {}   # defined data symbol -> rva+base
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and re.match(r'^000[2-9]:', p[0]):
            try:
                ours.setdefault(p[1], int(p[2], 16))
            except ValueError:
                pass
    nat = {}
    for l in open(H / 'aliases_natdata.txt', errors='replace'):
        if '=' in l:
            k, v = l.strip().split('=', 1)
            nat[k] = v
    o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
    q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
    by16 = {}
    for s, v in ours.items():
        b = bytes(q[v - 0x400000:v - 0x400000 + 16])
        if len(b) == 16 and b.count(0) <= 12:
            by16.setdefault(b, set()).add(s)
    out, why, unres = {}, {}, []
    for a in addrs:
        A = int(a, 16)
        n = (reg.get(a) or {}).get('name')
        if n and n in ours:
            out[a], why[a] = n, 'registry'
        elif len({x for x in by16.get(bytes(o[A - 0x400000:A - 0x400000 + 16]), ()) if not x.startswith(('dat_', '$SG'))}) == 1:
            out[a] = next(x for x in by16[bytes(o[A - 0x400000:A - 0x400000 + 16])] if not x.startswith(('dat_', '$SG')))
            why[a] = 'bytes16-real'   # a real library/our definition beats a qt_stubs dat_ copy (c_dfDIMouse2 pointer)
        elif 'dat_' + a in ours:
            out[a], why[a] = 'dat_' + a, 'datcopy'
        elif 'dat_' + a in nat and nat['dat_' + a] in ours:
            out[a], why[a] = nat['dat_' + a], 'natdata'
        else:
            c = by16.get(bytes(o[A - 0x400000:A - 0x400000 + 16]), set())
            if len(c) == 1:
                out[a], why[a] = next(iter(c)), 'bytes16'
            else:
                unres.append({'addr': a, 'registry': n, 'byte_candidates': sorted(c)[:4]})
    (H / 'auto/hardaddr_plan.json').write_text(json.dumps({'map': out, 'why': why, 'unresolved': unres}, indent=0))
    return out, why, unres


def patch(path, amap, outdir):
    data = bytearray(Path(path).read_bytes())
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    tail = bytearray(data[strtab + 4:]) if len(data) >= strtab + 4 else bytearray()
    want = {struct.pack('<I', int(a, 16)): s for a, s in amap.items()}
    newsym, newrel, done = {}, {}, 0
    for k in range(nsec):
        sh = 20 + optsz + 40 * k
        name = bytes(data[sh:sh + 8]).rstrip(b'\0')
        size, praw, prel = struct.unpack_from('<III', data, sh + 16)
        nrel = struct.unpack_from('<H', data, sh + 32)[0]
        ch = struct.unpack_from('<I', data, sh + 36)[0]
        if not praw or name.startswith(b'.debug') or ch & 0x80:
            continue
        covered = set()
        for r in range(nrel):
            va = struct.unpack_from('<I', data, prel + 10 * r)[0]
            covered.update(range(va, va + 4))
        for imm, sym in want.items():
            st = 0
            while True:
                j = data.find(imm, praw + st, praw + size)
                if j < 0:
                    break
                off = j - praw
                st = off + 1
                if covered & set(range(off, off + 4)):
                    continue
                if sym not in newsym:
                    newsym[sym] = nsym + len(newsym)
                data[j:j + 4] = b'\0\0\0\0'
                newrel.setdefault(k, []).append(struct.pack('<IIH', off, newsym[sym], 6))   # IMAGE_REL_I386_DIR32
                covered.update(range(off, off + 4)); done += 1
    if not done:
        return None
    body, symtab = data[:symptr], data[symptr:strtab]
    for k, rels in newrel.items():   # relocation arrays move to the end of the section/raw area
        sh = 20 + optsz + 40 * k
        prel, = struct.unpack_from('<I', data, sh + 24)
        nrel = struct.unpack_from('<H', data, sh + 32)[0]
        old = bytes(data[prel:prel + 10 * nrel]) if nrel else b''
        struct.pack_into('<I', body, sh + 24, len(body))
        struct.pack_into('<H', body, sh + 32, nrel + len(rels))
        body += old + b''.join(rels)
    for sym in sorted(newsym, key=newsym.get):
        nb = sym.encode('latin-1')
        raw = nb.ljust(8, b'\0') if len(nb) <= 8 else struct.pack('<II', 0, 4 + len(tail))
        if len(nb) > 8:
            tail += nb + b'\0'
        symtab += raw + struct.pack('<IhHBB', 0, 0, 0, 2, 0)
    struct.pack_into('<I', body, 8, len(body))
    struct.pack_into('<I', body, 12, nsym + len(newsym))
    outp = Path(outdir) / ('ha_' + Path(path).name)
    outp.write_bytes(bytes(body + symtab + struct.pack('<I', 4 + len(tail)) + tail))
    return str(outp)


if __name__ == '__main__':
    s = scan()
    m, why, un = plan(s)
    import collections
    print('hardaddr: sources %d, addresses %d, resolved %d %s, unresolved %d'
          % (len(s), len({a for v in s.values() for a in v}), len(m), dict(collections.Counter(why.values())), len(un)))
    for a in ('0085012c', '0084ff0c'):
        print('  %s -> %s' % (a, m.get(a)))
    for u in un[:25]:
        print('  UNRESOLVED', u)


def stub_aliases():
    """Every dat_<X> the link fills with a qt_stubs copy of the original bytes: when a real (library / our) data
    symbol has the same first 16 bytes and is unique, alias dat_<X> to it. The copy's internal pointers are only as
    good as data_relocs; the real definition is right (c_dfDIMouse2: copied rgodf pointer -> CreateDevice/SetDataFormat
    E_INVALIDARG). Writes aliases_hardaddr.txt (quicktest alias list)."""
    import pefile
    stubs, real = {}, {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and re.match(r'^000[2-9]:', p[0]):
            try:
                v = int(p[2], 16)
            except ValueError:
                continue
            if re.match(r'^dat_[0-9a-f]{8}$', p[1]) and 'stubs' in p[-1]:
                stubs[p[1]] = v
            elif not p[1].startswith(('dat_', '$SG', 'func_', '__imp_', '_g_')) and '$' not in p[1] and 'stubs' not in p[-1]:   # no EH tables: 16 bytes too weak
                real.setdefault(p[1], v)
    o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
    q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
    by16 = {}
    for s, v in real.items():
        b = bytes(q[v - 0x400000:v - 0x400000 + 16])
        if len(b) == 16 and b.count(0) <= 12:
            by16.setdefault(b, []).append(s)
    out = {}
    for d in stubs:
        A = int(d[4:], 16)
        c = by16.get(bytes(o[A - 0x400000:A - 0x400000 + 16]), [])
        if len(set(c)) == 1:
            out[d] = c[0]
    try:   # grow-only: a map read while a link rewrites it gave 0 entries once and wiped the file
        for l in open(H / 'aliases_hardaddr.txt'):
            if '=' in l:
                k, v = l.strip().split('=', 1)
                out.setdefault(k, v)
    except OSError:
        pass
    # a target must be ONE external definition: names the map lists several times are per-object statics
    # (_whitespaces: the renamed reference resolved to a zero stub copy -> skipWhitespace missed '	' -> every XML parse
    # threw "tag expected"), and a name only qt_stubs defines is a placeholder, not real data
    _cnt = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and re.match(r'^000[1-9]:', p[0]):
            _cnt[p[1]] = _cnt.get(p[1], 0) + (0 if 'stubs' in p[-1] else 1)
    out = {k: v for k, v in out.items() if _cnt.get(v, 0) == 1}
    try:   # targets that came out at address 0 (file-local statics: zlib static_ltree) are no real symbol: keep the copy
        _z = set(json.loads((H / 'auto/alias_zero.json').read_text()))
        out = {k: v for k, v in out.items() if k not in _z and v not in _z}
    except (OSError, ValueError):
        pass
    (H / 'aliases_hardaddr.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(out.items())))
    return stubs, out


def rename_plan(objs):
    """{obj path: {dat_X: real}} for every linked object that references an aliases_hardaddr.txt key. Renaming the
    reference in the object itself beats any stub/alias ordering (a stub copy of dat_0084ff0c kept winning over the
    /alternatename). Byte scan cached by (mtime, size) in auto/hardaddr_refs.pkl."""
    import mmap, pickle
    al = dict(l.strip().split('=', 1) for l in open(H / 'aliases_hardaddr.txt') if '=' in l)
    keys = [k.encode() for k in al]
    cf = H / 'auto/hardaddr_refs.pkl'
    try:
        cache = pickle.load(open(cf, 'rb'))
    except Exception:
        cache = {}
    import zlib, re as _re
    sig = zlib.crc32(chr(10).join(sorted(al)).encode())   # hash() of str is randomized per process: the cache never hit
    kre = _re.compile(b'|'.join(_re.escape(k) for k in sorted(keys, key=len, reverse=True))) if keys else None
    out, dirty = {}, False
    for p in objs:
        try:
            st = os.stat(p)
        except OSError:
            continue
        c = cache.get(p)
        if not c or c[0] != (st.st_mtime, st.st_size, sig):
            with open(p, 'rb') as f:
                try:
                    m = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
                except ValueError:
                    continue
                hit = sorted({x.decode() for x in kre.findall(m)}) if kre is not None and m.find(b'dat_') >= 0 else []
                m.close()
            cache[p] = c = ((st.st_mtime, st.st_size, sig), hit)
            dirty = True
        if c[1]:
            out[p] = {k: al[k] for k in c[1]}
    if dirty:
        pickle.dump(cache, open(cf, 'wb'))
    return out
