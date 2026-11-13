"""python findsym.py REGEX... -- which engine/native objects define a symbol matching each regex."""
import glob, re, sys, os
sys.path.insert(0, '.')
from roc.rebuild import coff_externals
pats = [re.compile(p) for p in sys.argv[1:]]
objs = glob.glob('rebuild/2008-06/out/RbxgsApp/linked/*.obj') + glob.glob('work/native-client/obj-engine-abi/*.obj') + glob.glob('work/native-client/obj/*.obj')
found = {}
for o in objs:
    for s, d in coff_externals(open(o, 'rb').read()).items():
        if d and any(p.search(s) for p in pats):
            found.setdefault(s, []).append(os.path.basename(o))
for k, v in sorted(found.items()):
    print(k[:120], v[:2])
