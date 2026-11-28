"""Colliding analog CODE names: twin of collidefix.py for CODE (0x401000..0x7c0000).
Converted objects reference generic analog function names (?initMoo@@YAXXZ, ?moo2@@YAAAVmutex@boost@@XZ,
??0Base@@QAE@XZ, ??$create@VPlayer@Network@RBX@@@..., ??0?$FactoryProduct@VScript@RBX@@...) that
renamed/rename.json maps to DIFFERENT original code addresses in different objects.
plan() -> {object basename: {name: 'func_%08x' % target_va}} (same shape as collidefix.plan() so
quicktest.py can merge codecollide.plan() into collidefix.plan()).
python codecollide.py: report."""
import collections
import json
from pathlib import Path

H = Path(__file__).parent


def plan():
    r = json.load(open(H / 'renamed/rename.json'))
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
            if not (0x401000 <= ti < 0x7c0000) or k2.startswith(('func_', 'dat_')):
                continue
            m[k2].add(ti)
            d[k2] = ti
        if d:
            per[a + '.obj'] = d
    lib = set()
    try:
        for l in open(H / 'linkexp/qt.map', errors='replace'):
            p = l.split()
            if len(p) >= 4 and ':' in p[-1] and ':' in p[0]:
                lib.add(p[1])
    except OSError:
        pass
    coll = {k for k, v in m.items() if len(v) > 1 and k not in lib}
    return {ob: {k: 'func_%08x' % t for k, t in d.items() if k in coll}
            for ob, d in per.items() if any(k in coll for k in d)}


if __name__ == '__main__':
    p = plan()
    syms = collections.Counter()
    for d in p.values():
        for k in d:
            syms[k] += 1
    print('codecollide: symbols %d, objects %d, renames %d' % (len(syms), len(p), sum(len(v) for v in p.values())))
    for k, cnt in syms.most_common(15):
        print('  %4d refs  %s' % (cnt, k[:90]))
