"""python who_defines.py SUBSTRING -- closure analog objects defining a symbol that contains SUBSTRING."""
import glob, os, sys
sys.path.insert(0, '.')
from roc.rebuild import coff_externals
for o in glob.glob('work/native-client/shortcut/closure/renamed/*.obj'):
    d = {s for s, v in coff_externals(open(o, 'rb').read()).items() if v}
    hit = [s[:70] for s in d if sys.argv[1] in s]
    if hit:
        print(os.path.basename(o), hit[:3])
