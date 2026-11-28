"""Call-identity repair for converted objects (callaudit.py finds them): a converted func_<X>'s call to an analog
callee NAME that our link defines as real code of ANOTHER function (func_00792440 -> boost::basic_regex::compare,
original target the thunk 0078e6e0) is renamed, in that object only, to func_<original target>.
plan(map) -> {obj_basename: {old_symbol: new_symbol}}: only when every flagged use of the symbol in that function
names ONE original target.
patch(path, renames, outdir) -> path of a patched copy (undefined external renamed; string table appended)."""
import collections, json, struct
from pathlib import Path
H = Path(__file__).parent


def plan(mp=None):
    mp = mp or H / 'linkexp/qt.map'
    try:
        bad = json.loads((H / 'auto/callaudit.json').read_text())
    except (OSError, ValueError):
        return {}
    real = set()
    for l in open(mp, errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and 'stubs' not in p[-1] and p[2].strip('0'):
            real.add(p[1])
    out = {}
    for fn, lst in bad.items():
        tg = collections.defaultdict(set)
        for _, t, sym in lst:
            tg[sym].add(t)
        # func_<T> may be a stub (ret bytes match the original): returning 0 beats running an unrelated function
        r = {s: 'func_' + next(iter(ts)) for s, ts in tg.items() if len(ts) == 1}
        if r:
            out[fn[5:] + '.obj'] = r
    # grow-only: a fixed object links as ca_<X>.obj, so the next audit no longer reports it
    pf = H / 'auto/callfix_plan.json'
    try:
        prev = json.loads(pf.read_text())
    except (OSError, ValueError):
        prev = {}
    for k, v in out.items():
        prev.setdefault(k, {}).update(v)
    pf.write_text(json.dumps(prev, indent=0))
    return prev


_PATCH_CACHE = {}
_PATCH_DIRTY = set()


def _save_patch_caches():
    import pickle
    for d in list(_PATCH_DIRTY):
        try:
            pickle.dump(_PATCH_CACHE[d], open(Path(d) / '_ca_cache.pkl', 'wb'), protocol=4)
        except OSError:
            pass
    _PATCH_DIRTY.clear()


import atexit as _atexit
_atexit.register(_save_patch_caches)


def patch(path, renames, outdir):
    import hashlib, os, pickle
    od = str(Path(outdir))
    outp = Path(outdir) / ('ca_' + Path(path).name)
    try:
        st = os.stat(path)
        rk = hashlib.md5('\n'.join(sorted(f'{k}={v}' for k, v in renames.items())).encode('latin-1', 'replace')).hexdigest()[:12]
        ck = (st.st_mtime_ns, st.st_size, rk)
        if od not in _PATCH_CACHE:
            cf = Path(outdir) / '_ca_cache.pkl'
            try:
                _PATCH_CACHE[od] = pickle.load(open(cf, 'rb'))
            except Exception:
                _PATCH_CACHE[od] = {}
        ce = _PATCH_CACHE[od].get(str(path))
        if ce and ce[0] == ck:
            if ce[1] is None:
                return None
            if outp.exists():
                return str(outp)
    except OSError:
        ck = None
    data = bytearray(Path(path).read_bytes())
    _, nsec, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    tail = bytearray(data[strtab + 4:]) if len(data) >= strtab + 4 else bytearray()
    done, i = 0, 0
    addends = {}
    while i < nsym:
        at = symptr + 18 * i
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, at)
        if cls == 2 and secnum == 0:   # undefined external only: never rename a definition
            if raw[:4] == b'\0\0\0\0':
                s0 = strtab + struct.unpack_from('<I', raw, 4)[0]
                name = bytes(data[s0:data.find(b'\0', s0)]).decode('latin-1')
            else:
                name = raw.rstrip(b'\0').decode('latin-1')
            new = renames.get(name)
            if new:
                if '+0x' in new:
                    new, _ahex = new.rsplit('+0x', 1)
                    addends[i] = int(_ahex, 16)
                nb = new.encode('latin-1')
                if len(nb) <= 8:
                    data[at:at + 8] = nb.ljust(8, b'\0')
                else:
                    off = 4 + len(tail)
                    tail += nb + b'\0'
                    data[at:at + 8] = struct.pack('<II', 0, off)
                done += 1
        i += 1 + naux
    if addends:
        optsz = struct.unpack_from('<H', data, 16)[0]
        for k in range(nsec):
            sh = 20 + optsz + 40 * k
            rptr, relptr, nrel = struct.unpack_from('<II', data, sh + 20)[0], struct.unpack_from('<I', data, sh + 24)[0], struct.unpack_from('<H', data, sh + 32)[0]
            for r in range(nrel):
                rv, si, rt = struct.unpack_from('<IIH', data, relptr + 10 * r)
                if si in addends and rt == 6:
                    cur_v = struct.unpack_from('<I', data, rptr + rv)[0]
                    struct.pack_into('<I', data, rptr + rv, (cur_v + addends[si]) & 0xFFFFFFFF)
    # symbols DEFINED here (a foreign analog's own helper: SafeChat's call_once got the analog's initLocalScope):
    # append an undefined external func_<T> and point every relocation that used the helper at it
    defidx = {}
    i = 0
    while i < nsym:
        at = symptr + 18 * i
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, at)
        if 0 < secnum < 0xfffe and cls in (2, 3):
            if raw[:4] == b'\0\0\0\0':
                s0 = strtab + struct.unpack_from('<I', raw, 4)[0]
                name = bytes(data[s0:data.find(b'\0', s0)]).decode('latin-1')
            else:
                name = raw.rstrip(b'\0').decode('latin-1')
            if name in renames:
                defidx[i] = renames[name]
        i += 1 + naux
    if defidx:
        newsyms, newidx = bytearray(), {}
        for old_i, new in sorted(defidx.items()):
            if new not in newidx:
                nb = new.encode('latin-1')
                if len(nb) <= 8:
                    rawn = nb.ljust(8, b'\0')
                else:
                    rawn = struct.pack('<II', 0, 4 + len(tail)); tail += nb + b'\0'
                newidx[new] = nsym + len(newsyms) // 18
                newsyms += rawn + struct.pack('<IhHBB', 0, 0, 0x20, 2, 0)
        optsz = struct.unpack_from('<H', data, 16)[0]
        for k in range(nsec):
            sh = 20 + optsz + 40 * k
            relptr, nrel = struct.unpack_from('<I', data, sh + 24)[0], struct.unpack_from('<H', data, sh + 32)[0]
            for r in range(nrel):
                ro = relptr + 10 * r
                idx = struct.unpack_from('<I', data, ro + 4)[0]
                if idx in defidx:
                    struct.pack_into('<I', data, ro + 4, newidx[defidx[idx]]); done += 1
        data = data[:strtab] + newsyms + data[strtab:]
        strtab += len(newsyms)
        struct.pack_into('<I', data, 12, nsym + len(newsyms) // 18)
    if not done:
        if ck is not None:
            _PATCH_CACHE[od][str(path)] = (ck, None); _PATCH_DIRTY.add(od)
        return None
    data = data[:strtab] + struct.pack('<I', 4 + len(tail)) + tail
    outp = Path(outdir) / ('ca_' + Path(path).name)
    outp.write_bytes(bytes(data))
    if ck is not None:
        _PATCH_CACHE[od][str(path)] = (ck, True); _PATCH_DIRTY.add(od)
    return str(outp)


if __name__ == '__main__':
    p = plan()
    print('callfix plan: %d objects, %d symbol renames' % (len(p), sum(len(v) for v in p.values())))
    for k, v in list(p.items())[:8]:
        print(' ', k, v)
