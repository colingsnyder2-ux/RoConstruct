"""Print the compiler's vftable layout of a class as the rbxgs-app engine sees it (overlay headers first, then rbxgs),
or with --native the native 2008 headers first.  python engine_vtable.py CLASS HEADER [--native]"""
import re, sys
sys.path.insert(0, '.')
from pathlib import Path
from roc import libs, rebuild
R = rebuild.ROOT
cls, header = sys.argv[1], sys.argv[2]
recipe = libs.RECIPES['rbxgs']
src = R / 'work/native-client/shortcut/_vt.cpp'
src.write_text('#include "%s"\n' % header)
inc = []
if '--native' in sys.argv:
    inc.append(R / 'rebuild/2008-06/native-headers')
inc += [R / 'rebuild/2008-06/out/RbxgsApp/overlay/App/include']
inc += [(libs.LIBS / v).resolve() for v in recipe['include'] if v != 'WINSDK']
flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD', '/DBOOST_ALL_NO_LIB'] + ['/D' + v for v in recipe['defines'].split()]
flags += ['/I' + str(p) for p in inc] + ['/d1reportSingleClassLayout' + cls, '/Fo' + str(R / 'work/native-client/shortcut/_vt.obj'), str(src)]
code, text = rebuild.run(rebuild.toolchain(21022), 'cl', flags, R)
out, on = [], False
for line in text.splitlines():
    if re.match(r'^%s::\$vftable@' % re.escape(cls), line) or re.match(r'^%s::\$vftable@.*:$' % re.escape(cls), line):
        on = True
    if on:
        out.append(line)
        if not line.strip():
            on = False
print(code)
print('\n'.join(out[:80]) if out else text[-2000:])
src.unlink(); (R / 'work/native-client/shortcut/_vt.obj').unlink(missing_ok=True)
