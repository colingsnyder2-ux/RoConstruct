"""object_browser_profile.py [-v] PREFIX=ADDR ... : CObjectBrowser unit through the document-swap + XTP flags (preprocessed,
then compiled with the class-tree-view profile flags; no noinline needles needed), compare named functions."""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
from native_bind import XTP_FLAGS, flags, match, rebuild  # noqa: E402
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/object-browser'; OUT.mkdir(parents=True, exist_ok=True)
FLAGS = flags()
tool = rebuild.toolchain(21022)
def build(name='CObjectBrowser'):
    src = ROOT / 'rebuild/2008-06/native-classes' / (name + '.cpp')
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + XTP_FLAGS + ['/P', str(src)], OUT)
    assert code == 0, log[-3000:]
    body = (OUT / (name + '.i')).read_text(errors='replace')
    unit = OUT / ('Native' + name[1:] + 'Profile.cpp'); unit.write_text(body)
    obj = OUT / ('Native' + name[1:] + 'Profile.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj
if __name__ == '__main__':
    args = sys.argv[1:]; verbose = '-v' in args; args = [a for a in args if a != '-v']
    funcs = match.coff_functions(build().read_bytes())
    if not args:
        for f in funcs: print(len(f[1]), f[0])
    for spec in args:
        p, ad = spec.rsplit('=', 1)
        hits = [f for f in funcs if f[0].startswith(p)]
        if not hits: print('MISSING', p); continue
        n, b, r = hits[0]; t, tr, _ = match.target('2008-06', ad)
        ok = match.exact_match(t, tr, b, r)
        print('EXACT' if ok else 'DIFF ', ad, n[:70], len(b), len(t))
        if not ok and verbose: print(match.diff(t, tr, b, r)[:6000])
