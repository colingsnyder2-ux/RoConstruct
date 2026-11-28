"""Class-name spelling splits template instantiations: Described<PartInstance, sPart> exists as $1?sPart@2@3PADA (native
char[]) AND $1?sPart@2@3PBDB / 3QBDB (analog pointer spellings). Each is its own instantiation with its own function-local
static: 19 classes had TWO ClassDescriptors (the second registered lazily at File->New, appending to the base's derived
vector while Insert Object iterated it -> use-after-free, 0xC0000374), duplicate creators/RTTI (409 twin groups).
plan(objs) -> {object: {variant: canonical}}: every symbol whose only difference is the class-name spelling inside a
template argument (@3PBDB/@3QBDB -> @3PADA; the class-name variables themselves are never touched, pointer and array
are different types). quicktest renames the references (callfix.patch) and the COMDAT definitions (rename_comdat) so the
linker keeps ONE instantiation; plain definitions stay (renaming them would duplicate). python spellunify.py: report."""
import collections, re, struct
from pathlib import Path
H = Path(__file__).parent
GLOBAL = re.compile(r'^\?s\w+@(?:\w+@)*@3(?:PADA|PBDB|QBDB)$')
SPELL = re.compile(r'(\$1\?s\w+@(?:[\w$?]+@)*?3)(PBDB|QBDB)')


FAMILY = re.compile(r'classDescriptor')   # only the per-class descriptor (create/creator unification broke create<Hint>)   # what splits per-class state;
# RTTI / deleting-destructor names (??_R ??_E ??_G) stay: unifying those mixed layouts (Hint delete -> shared_ptr ctor)


def canon(n):
    if GLOBAL.match(n) or '$1?s' not in n or not FAMILY.search(n) or n.startswith(('??_R', '??_E', '??_G')):
        return n
    return SPELL.sub(r'\1PADA', n)


def renames():
    """{variant: canonical} for names the last link defines or references whose canonical spelling is DEFINED"""
    defs, seen = set(), set()
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0]:
            seen.add(p[1])
            if 'stubs' not in p[-1]:
                defs.add(p[1])
    out = {}
    for n in seen:
        c = canon(n)
        if c != n and c in defs:
            out[n] = c
    import json
    sf = H / 'auto/spellunify_state.json'   # grow-only: once unified, the variants leave the map (renames shrank 249 -> 26)
    try:
        for k, v in json.load(open(sf)).items():
            out.setdefault(k, v)
    except (OSError, ValueError):
        pass
    json.dump(out, open(sf, 'w'))
    return out


def _names(data):
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    return nsec, symptr, nsym, optsz


def rename_comdat(path, ren, outdir):
    """copy with every DEFINED external whose section is COMDAT renamed (the linker then merges the instantiations);
    UNDEFINED references renamed too. None when nothing matched."""
    import hashlib, os
    dst = Path(outdir) / ('su_' + Path(path).name)
    _rk = getattr(rename_comdat, '_rk', None)
    if _rk is None or _rk[0] is not ren:
        _rk = (ren, hashlib.md5('\n'.join(sorted(f'{k}={v}' for k, v in ren.items())).encode()).hexdigest()[:12])
        rename_comdat._rk = _rk
    _sf = Path(outdir) / '_ren_key.txt'
    if not _sf.exists() or _sf.read_text(errors='ignore') != _rk[1]:
        _sf.write_text(_rk[1])
    elif dst.exists() and dst.stat().st_mtime >= max(os.path.getmtime(path), _sf.stat().st_mtime):
        return str(dst)
    data = bytearray(Path(path).read_bytes())
    nsec, symptr, nsym, optsz = _names(data)
    strtab = symptr + nsym * 18
    tail = bytearray(data[strtab + 4:])
    flags = [struct.unpack_from('<I', data, 20 + optsz + 40 * i + 36)[0] for i in range(nsec)]
    done, i = 0, 0
    while i < nsym:
        at = symptr + 18 * i
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIhHBB', data, at)
        if cls == 2 and (secnum == 0 or (0 < secnum <= nsec and flags[secnum - 1] & 0x1000)):
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
    dst = Path(outdir) / ('su_' + Path(path).name)
    dst.write_bytes(bytes(data[:strtab]) + struct.pack('<I', 4 + len(tail)) + bytes(tail))
    return str(dst)


def plan(objs, ren):
    """objects mentioning a pointer class-name spelling; byte scan cached by (mtime, size) in auto/spellunify_scan.pkl"""
    import os, pickle
    keys = re.compile(b'@3(?:PBDB|QBDB)')
    cf = H / 'auto/spellunify_scan.pkl'
    try:
        cache = pickle.load(open(cf, 'rb'))
    except Exception:
        cache = {}
    out, dirty = [], False
    for o in objs:
        try:
            st = os.stat(o)
        except OSError:
            continue
        c = cache.get(o)
        if not c or c[0] != (st.st_mtime, st.st_size):
            try:
                hit = bool(keys.search(Path(o).read_bytes()))
            except OSError:
                continue
            cache[o] = c = ((st.st_mtime, st.st_size), hit); dirty = True
        if c[1]:
            out.append(o)
    if dirty:
        pickle.dump(cache, open(cf, 'wb'))
    return out


if __name__ == '__main__':
    r = renames()
    print('spellunify: variant names whose canonical (3PADA) spelling is defined: %d' % len(r))
    print(collections.Counter(re.match(r'^[?]+[_$]?[A-Za-z]{0,14}', k).group(0) for k in r).most_common(10))
    assert canon('?sPart@RBX@@3QBDB') == '?sPart@RBX@@3QBDB'
    assert canon('?classDescriptor@?$Described@VPartInstance@RBX@@$1?sPart@2@3PBDBV?$FactoryProduct@X') == '?classDescriptor@?$Described@VPartInstance@RBX@@$1?sPart@2@3PADAV?$FactoryProduct@X'
