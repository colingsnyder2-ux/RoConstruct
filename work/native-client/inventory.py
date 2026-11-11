"""Native 2008 client inventory (no P6, no RobloxShell, no Player2008): compile every MFC-side class in
rebuild/2008-06/native-classes against real MFC 9.0 / XTP 11.2.2 headers and the rbxgs-app engine headers
(overlay first), keep objects in work/native-client/obj, and summarize compile errors.
usage: python work/native-client/inventory.py [FILE.cpp ...]"""
import concurrent.futures as cf, json, re, sys, collections
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild
sys.path.insert(0, str(Path(__file__).resolve().parent))
from inventory_flags import *  # noqa: F401,F403  (ROOT, NC, OUT, DONOR, flags_for)


if len(sys.argv) > 1:
    sources = [Path(a) if Path(a).is_absolute() or '/' in a or '\\' in a else NC / a for a in sys.argv[1:]]
else:
    pat = re.compile(r'#include <afx|CWnd|CView\b|CDocument|CFrameWnd|XTP')
    sources = sorted(p for p in NC.glob('*.cpp') if pat.search(p.read_text(errors='replace'))) + sorted(DONOR.glob('*.cpp'))
    # plus every native-classes file the shell link already uses (objects compiled by hand, e.g. CRobloxAppInstance)
    shell_objs = {o.stem for o in (ROOT / 'work/native-client/obj').glob('*.obj')}
    sources += sorted(p for p in NC.glob('*.cpp') if p.stem in shell_objs and p not in sources)
    extra = [ROOT / 'work/native-client' / n for n in ('scintilla_ns.cpp', 'scintilla_view_ns.cpp')]
    sources += [p for p in extra if p.exists()]
tc = rebuild.toolchain(21022)


def one(src):
    text = src.read_text(errors='replace')
    # engine ABI: relative includes bypass the header mirror; inline re-definitions of members the
    # 2007 engine header already defines inline (Verb::getName) would clash
    patched = re.sub(r'^\s*inline\s+const\s+(?:RBX::)?Name\s*&\s*(?:RBX::)?Verb::getName\(\)\s*const\s*\{[^}]*\}\s*$', '',
                     text.replace('../native-headers/', ''), flags=re.M) if ENGINE_ABI else text
    if patched != text:
        tmp = OUT / 'src' / src.name
        tmp.parent.mkdir(exist_ok=True)
        tmp.write_text(patched)
        src = tmp
    code, text = rebuild.run(tc, 'cl', flags_for(src) + ['/Fo' + src.stem + '.obj', str(src)], OUT)
    errs = [l.strip() for l in text.splitlines() if ' error ' in l]
    return src.name, code, errs


res = {}
with cf.ThreadPoolExecutor(16) as pool:
    for name, code, errs in pool.map(one, sources):
        res[name] = {'ok': code == 0, 'errors': errs[:8], 'nerr': len(errs)}
ok = [n for n, r in res.items() if r['ok']]
bad = {n: r for n, r in res.items() if not r['ok']}
(ROOT / 'work/native-client/inventory.json').write_text(json.dumps(res, indent=1))
print('compiled', len(ok), 'of', len(res))
first = collections.Counter(re.sub(r'^.*?: (?:fatal )?error ', '', r['errors'][0])[:110] for r in bad.values() if r['errors'])
for k, v in first.most_common(25):
    print(v, k)
