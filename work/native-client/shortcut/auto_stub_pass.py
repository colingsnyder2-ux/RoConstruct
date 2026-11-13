"""Automatic stub pass.  For every symbol the stub-backed link still leaves undefined, use the server's byte-exact analog of the
function at its exe address (rename.py -> link/renamed/ADDR.obj, same bytes, real mangled name) instead of a zero stub.
usage: python auto_stub_pass.py            # writes chosen_auto.json (chosen.json + renamed analogs that define a stub symbol)
then:  python relink_big.py chosen_auto.json
Prereq: rename.py ADDR... for the addresses (symbol -> address from the identity closure; add the pairs to link/addrmap.json)."""
import glob, json, sys
sys.path.insert(0, '.')
from roc.rebuild import coff_externals
H = 'work/native-client/shortcut/'
un = set(json.load(open(H + 'unresolved12.json')))
chosen = json.load(open(H + 'chosen.json'))
add = []
for o in sorted(glob.glob('work/native-client/link/renamed/*.obj')):
    defined = {s for s, v in coff_externals(open(o, 'rb').read()).items() if v}
    if defined & un:
        add.append(o.replace(chr(92), '/'))
print('renamed analogs defining a stub symbol:', len(add))
json.dump(chosen + [a for a in add if a not in chosen], open(H + 'chosen_auto.json', 'w'), indent=0)
