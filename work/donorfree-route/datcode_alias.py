"""python datcode_alias.py: dat_<A> placeholders whose A is in the original's CODE section (??__F atexit functions at
007fa230..., callback pointers in copied tables): referenced as data, they became 4 KB of zero data, so whatever called
through them jumped to 0. Each gets an alias to our link's definition of the function at A (registry name or func_<A>,
whichever the last map defines). Covers the map's stubs and linkexp/qt_und2.txt. Writes aliases_datcode.txt (grow-only)."""
import json, re
from pathlib import Path
H = Path(__file__).parent
reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
cand = {s for s in stubs if re.fullmatch(r'dat_[0-9a-f]{8}', s)}
try:
    cand |= {s for s in (H / 'linkexp/qt_und2.txt').read_text().split() if re.fullmatch(r'dat_[0-9a-f]{8}', s)}
except OSError:
    pass
import collections
_nc = collections.Counter((v or {}).get('name') for v in reg.values())   # a name on several addresses is a mislabel
al = {}
for s in cand:
    a = s[4:]
    if not 0x401000 <= int(a, 16) < 0x801ad0:   # .text of the 2008-06 exe
        continue
    n = (reg.get(a) or {}).get('name')
    t = next((c for c in ('func_' + a, n if n and _nc[n] == 1 else None) if c and c in defs), None)
    if t:
        al[s] = t
old = {}
try:
    old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_datcode.txt') if '=' in l)
except OSError:
    pass
old.update(al)
(H / 'aliases_datcode.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('datcode_alias: code-address dat_ placeholders %d, aliased to their function %d' % (sum(1 for s in cand if 0x401000 <= int(s[4:], 16) < 0x801ad0), len(al)))
