"""python mistarget_fix.py [--apply]: auto/calldiff.json (namediff.py) lists direct calls that land on a function whose body
differs from the original target. Where our name M always stands for one original address T (and T only for M) and T has a
byte-exact converted object, make that object define M (it is linked first, so the exact body replaces the native one) and
alias func_T to it. No compile: the object's symbol is renamed in place."""
import json, re, sys
from collections import defaultdict
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1] / 'work/native-client'))
import os; os.chdir(H.parents[1])
import rename as RN
R = H / 'renamed'
calls = json.load(open(H / 'auto/calldiff.json'))
res = json.load(open(R / 'rename.json'))
amap = json.load(open(R / 'addrmap.json'))
m2t, t2m = defaultdict(set), defaultdict(set)
try:   # names an import library provides (mfc90/CRT exports): never take them over with a converted object
    IMPORTED = set(json.load(open(H / 'linkexp/mfc90_names.json')))
except Exception:
    IMPORTED = set()
for c in calls:
    if c['kind'] == 'wrong':
        m2t[c['ours']].add(c['target']); t2m[c['target']].add(c['ours'])
done, skip = [], defaultdict(int)
for m, ts in sorted(m2t.items()):
    t = next(iter(ts))
    r = res.get(t) or {}
    obj = R / 'obj' / (t + '.obj')
    if len(ts) != 1 or len(t2m[t]) != 1:
        skip['ambiguous'] += 1
    elif not m.startswith('?') or 'keep_' in m or re.match(r'^\?\?(?:2|3|_U|_V)@Y', m) or m in IMPORTED:
        skip['unnamed/kept helper'] += 1
    elif r.get('status') != 'renamed' or not obj.exists():
        skip['no exact object (%s)' % r.get('status')] += 1
    elif r.get('symbol') == m:
        skip['already exact name (layout/other difference)'] += 1
    elif r.get('symbol') != 'func_' + t:
        skip['object has another real name'] += 1
    else:
        done.append((t, m))
print('fixable %d' % len(done), dict(skip))
if '--apply' in sys.argv:
    for t, m in done:
        obj = R / 'obj' / (t + '.obj')
        data = obj.read_bytes()
        idx = [i for i, n, sec, cls, v in RN.symtab(data)[0] if n == 'func_' + t]
        obj.write_bytes(RN.rename(data, {i: m for i in idx}))
        res[t]['symbol'] = m
        amap.pop('func_' + t, None); amap[m] = {'exact': [t]}
    (R / 'rename.json').write_text(json.dumps(res, indent=1))
    (R / 'addrmap.json').write_text(json.dumps(amap, indent=0))
    print('applied; run renamed_link.py + boot.py')
