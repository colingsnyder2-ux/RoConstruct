"""Mislabeled destructors: dtoraudit.py finds, from the ORIGINAL's RTTI (COL -> vtable -> deleting destructor -> the ~T it
calls), the true ~T address of every polymorphic class; for 65 classes the identity registry gives ??1T to ANOTHER body
(PartInstance, Script, Message, Players, Joint, Decal ...). Our renamed objects export those registry names, so every
`delete` of such an object ran some other class's destructor (Insert Object close: ~Decal freed the string at +0x134 of a
Decal whose string lives at +0x144 -> 0xC0000374). plan(objs) -> {object path: {'??1T': 'Dtf_<true>'}} for every object
that REFERENCES (not defines) a mislabeled ??1T; aliases() -> {'Dtf_<true>': our link's definition of the true body}.
quicktest renames the references (callfix.patch) and adds the aliases. python dtorfix.py: report."""
import json
from pathlib import Path
H = Path(__file__).parent


def _fixes():
    a = json.load(open(H / 'auto/dtoraudit.json'))['mislabeled']
    reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
    defs = set()
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and 'stubs' not in p[-1]:
            defs.add(p[1])
    out = {}
    for r in a.values():
        t = r['true']
        n = (reg.get(t) or {}).get('name')
        tgt = next((c for c in (n, 'func_' + t) if c and c in defs), None)
        if tgt and tgt != r['dtor_name']:
            out[r['dtor_name']] = ('Dtf_' + t, tgt)
    return out


def aliases():
    return {k: v for k, v in _fixes().values()}


def plan(objs):
    f = _fixes()
    keys = {k.encode('latin-1'): k for k in f}
    import sys
    sys.path.insert(0, str(H.parents[1]))
    from roc import rebuild as rb
    out = {}
    cf = H / 'auto/dtorfix_cache.json'   # path -> [mtime, size, names found]: unchanged objects are not reread
    try:
        cache = json.load(open(cf)) if json.load(open(cf)).get('_keys') == sorted(f) else {'_keys': sorted(f)}
    except (OSError, ValueError):
        cache = {'_keys': sorted(f)}
    import os
    for o in objs:
        try:
            st = os.stat(o)
        except OSError:
            continue
        c = cache.get(o)
        if c and c[0] == st.st_mtime and c[1] == st.st_size:
            hit = c[2]
            if not hit:
                continue
            b = Path(o).read_bytes()
        else:
            b = Path(o).read_bytes()
            hit = [k for kb, k in keys.items() if kb in b]
            cache[o] = [st.st_mtime, st.st_size, hit]
            if not hit:
                continue
        und = {n for n, d in rb.coff_externals(b).items() if not d}
        r = {k: f[k][0] for k in hit if k in und}
        if r:
            out[o] = r
    json.dump(cache, open(cf, 'w'))
    return out


if __name__ == '__main__':
    f = _fixes()
    print('dtorfix: mislabeled destructors with a defined true body %d' % len(f))
    for k, (a, t) in list(f.items())[:10]:
        print('  %s -> %s = %s' % (k[:60], a, t[:60]))


def wrong_holders():
    """{object basename: {'??1T': 'Dtw_<reg>'}}: the object that DEFINES the mislabeled ??1T in the last link (plain
    definitions beat the native header-inline COMDAT ~T, so retargeting references alone left ??_GDecal on the wrong body)"""
    a = json.load(open(H / 'auto/dtoraudit.json'))['mislabeled']
    win = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and p[1].startswith('??1'):
            win.setdefault(p[1], p[-1])
    out = {}
    for r in a.values():
        o = win.get(r['dtor_name'])
        if o and r['reg'] in o:   # renamed/obj/<reg>.obj, ca_<reg>.obj ...: the registry-named original body
            out.setdefault(o, {})[r['dtor_name']] = 'Dtw_' + r['reg']
    sf = H / 'auto/dtorfix_holders.json'   # grow-only: once renamed, the next map no longer shows the wrong holder
    try:
        for o, rr in json.load(open(sf)).items():
            out.setdefault(o, {}).update(rr)
    except (OSError, ValueError):
        pass
    json.dump(out, open(sf, 'w'), indent=0)
    return out


def rename_defs(path, ren, outdir):
    """copy of the object with DEFINED external symbols renamed (string table appended); None if nothing matched"""
    import struct
    data = bytearray(Path(path).read_bytes())
    _, nsec, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    tail = bytearray(data[strtab + 4:])
    done, i = 0, 0
    while i < nsym:
        at = symptr + 18 * i
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIhHBB', data, at)
        if cls == 2 and secnum > 0:
            if raw[:4] == b'\0\0\0\0':
                s0 = strtab + struct.unpack_from('<I', raw, 4)[0]
                name = bytes(data[s0:data.find(b'\0', s0)]).decode('latin-1')
            else:
                name = raw.rstrip(b'\0').decode('latin-1')
            new = ren.get(name)
            if new:
                nb = new.encode('latin-1')
                if len(nb) <= 8:
                    data[at:at + 8] = nb.ljust(8, b'\0')
                else:
                    off = 4 + len(tail); tail += nb + b'\0'
                    data[at:at + 8] = struct.pack('<II', 0, off)
                done += 1
        i += 1 + naux
    if not done:
        return None
    out = bytes(data[:strtab]) + struct.pack('<I', 4 + len(tail)) + bytes(tail)
    dst = Path(outdir) / ('dtw_' + Path(path).name)
    dst.write_bytes(out)
    return str(dst)
