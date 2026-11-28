"""python xtpbuild.py [N]: compile every XTP 11.2.2 source file with the matched recipe (xtp-11.2.2-lib-strlen, its
first grid flags) into linkexp/xtplib/<file>.obj, N processes (default 12). Cached: an existing object is kept.
Input for libalias.py (stubbed unnamed XTP functions -> the compiled library function with the same body)."""
import os, sys
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
OUT = H / 'linkexp/xtplib'
RECIPE = 'xtp-11.2.2-lib-strlen'


def one(rel):
    from roc import libs, match
    o = OUT / (rel.replace('/', '__') + '.obj')
    if o.exists():
        return rel, 'cached'
    r = libs.RECIPES[RECIPE]
    flags = r.get('grid')[0]
    try:
        obj = match.compile_text('2008-06', libs.source_for(RECIPE, rel, 'cpp', 21022, flags), flags=flags, build=21022)
    except Exception as e:
        return rel, 'fail: %s' % str(e)[:80]
    o.write_bytes(obj)
    return rel, 'ok'


if __name__ == '__main__':
    OUT.mkdir(parents=True, exist_ok=True)
    src = ROOT / 'tools/libs/xtp-11.2.2'
    files = sorted(p.relative_to(src).as_posix() for p in (src / 'Source').rglob('*.cpp'))
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 12
    res = {'ok': 0, 'cached': 0, 'fail': 0}
    with ProcessPoolExecutor(n) as ex:
        for f in as_completed([ex.submit(one, rel) for rel in files]):
            rel, st = f.result()
            res[st.split(':')[0]] += 1
            if st.startswith('fail'):
                print(rel, st)
    print('xtpbuild: %s of %d files' % (res, len(files)))
