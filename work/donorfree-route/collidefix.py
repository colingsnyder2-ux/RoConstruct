"""Colliding analog DATA names: converted objects reference generic analog names (?flag@@3JA, ?G@@3DA, ??_7S@@6B@,
?g_value@@3HA ...) that renamed/rename.json maps to DIFFERENT original addresses in different objects. Linked as one
symbol, unrelated code shared one variable: 163 objects shared the function-local-static guard ?flag@@3JA, so the
first initializer set the bit and every other function skipped constructing its static (empty creators map,
classes missing from Insert Object). plan() -> {object basename: {name: dat_<original address>}} for every name with
more than one original address (refs, 'rebound:' prefix stripped) that the object references but does not define;
quicktest renames them in each object (callfix.patch) before natinit/hardaddr, which then pair the dat_ placeholders
with native globals or real data where they can. python collidefix.py: report."""
import collections, json, sys
from pathlib import Path
H = Path(__file__).parent


def plan():
    import os, pickle
    rf_p = H / 'renamed/rename.json'
    mp_p = H / 'linkexp/qt.map'
    cf_p = H / 'auto/collidefix_cache.pkl'
    try:
        st_r = os.stat(rf_p)
        st_m = os.stat(mp_p) if mp_p.exists() else None
        ck = (st_r.st_mtime_ns, st_r.st_size, st_m.st_mtime_ns if st_m else 0, st_m.st_size if st_m else 0)
        if cf_p.exists():
            old = pickle.load(open(cf_p, 'rb'))
            if old[0] == ck:
                return old[1]
    except Exception:
        ck = None
    r = json.load(open(rf_p))
    m = collections.defaultdict(set)
    per = {}
    for a, v in r.items():
        rf = v.get('refs') or {}
        if isinstance(rf, str):
            continue
        d = {}
        for k, t in rf.items():
            if k.startswith('collide:'):
                continue
            k2 = k[len('rebound:'):] if k.startswith('rebound:') else k
            try:
                ti = int(t, 16)
            except (TypeError, ValueError):
                continue
            if ti < 0x7c0000 or k2.startswith(('func_', 'dat_')):   # data only; placeholders are already per-address
                continue
            m[k2].add(ti)
            d[k2] = ti
        if d:
            per[a + '.obj'] = d
    lib = set()   # names a LIBRARY / DLL defines in the last link (msvcp90's std vtables): those are real, keep them
    try:
        for l in open(H / 'linkexp/qt.map', errors='replace'):
            p = l.split()
            if len(p) >= 4 and ':' in p[-1] and ':' in p[0]:
                lib.add(p[1])
    except OSError:
        pass
    coll = {k for k, v in m.items() if len(v) > 1 and k not in lib}
    res = {ob: {k: 'dat_%08x' % t for k, t in d.items() if k in coll} for ob, d in per.items() if any(k in coll for k in d)}
    if ck is not None:
        try:
            pickle.dump((ck, res), open(cf_p, 'wb'), protocol=4)
        except OSError:
            pass
    return res


if __name__ == '__main__':
    p = plan()
    print('collidefix: objects %d, renames %d' % (len(p), sum(len(v) for v in p.values())))
    for k, v in list(p.items())[:5]:
        print(' ', k, list(v.items())[:3])
