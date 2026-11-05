import sys, json; sys.path.insert(0, '.')
from pathlib import Path
from roc import match, rebuild
units = [r for r in json.load(open('rebuild/2008-06/manifests/functions.json')) if r.get('unit') == 'CMainFrame']
want = {r['addr']: r['size'] for r in units}
base = json.loads(Path('work/2008-06/shared-layouts/view-init.json').read_text())
out = Path('rebuild/2008-06/out/native-layouts').resolve()
from roc import libs
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + v for v in recipe['defines'].split()]
flags += ['/I' + str(Path('rebuild/2008-06/native-headers').resolve()), '/I' + str(Path('tools/libs/mfc-9.0-rtm/atlmfc/include').resolve())]
flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
flags += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(Path('tools/libs/xtp-11.2.2/Source').resolve())]
files = sorted(Path('rebuild/2008-06/native-classes').glob('CMainFrame*.cpp'))
got = {}
for f in files:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fomf_' + f.stem + '.obj', str(f.resolve())], out)
    if code: print(f.name, 'COMPILE ERROR', log[-150:].replace('\n', ' ')); continue
    raw = (out / ('mf_' + f.stem + '.obj')).read_bytes()
    funcs = match.coff_functions(raw)
    for a in want:
        t, tr, _ = match.target('2008-06', a)
        for n, b, r in funcs:
            if len(b) == len(t) and match.exact_match(t, tr, b, r): got.setdefault(a, (f.stem, n[:40]))
print('exact', len(got), 'of', len(want), 'bytes', sum(want[a] for a in got), 'of', sum(want.values()))
for a in sorted(set(want) - set(got)): print('missing', a, want[a])
