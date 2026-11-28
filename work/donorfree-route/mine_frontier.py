"""python mine_frontier.py: the functions that ACTUALLY need mining -- no source anywhere (ledger.py: not server-exact,
no native/findings/draft source) AND called by REAL code in our current link (a linked, non-stub object references the
placeholder). A placeholder only other placeholders call cannot run until those are written. Static initializers
(0x7c0000-0x800000) are reported separately (nameinit-style generation, not mining).
Writes auto/mine_frontier.txt (sorted by caller count) and auto/mine_frontier.json. Needs ledger.py run first."""
import collections, json, os, pickle, re
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
from shardcache import ShardCache
cache = ShardCache(H / 'linkexp/qt_ext_cache.pkl')
rsp = [l.strip().strip('"') for l in open(H / 'linkexp/qt.final.rsp') if l.strip().lower().endswith('.obj"')]
own = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        own.setdefault(p[1], p[-1])
stubn = {n for n, o in own.items() if 'stubs' in o}
rows = json.loads((H / 'auto/ledger.json').read_text())
nos = {a for a, r in rows.items() if r['link'] == 'STUB (placeholder)' and r['server'] != 'exact' and not r['other']}
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
byname = collections.defaultdict(set)
for a, v in reg.items():
    n = (v or {}).get('name')
    if n:
        byname[n].add(a)
ren = json.loads((H / 'renamed/rename.json').read_text())
refaddr = collections.defaultdict(set)
for x in ren.values():
    for k, v in (x.get('refs') or {}).items():
        if not k.startswith(('collide:', 'split:', 'rebound:')):
            refaddr[k].add(v)


def addr_of(n):
    m = re.match(r'^_?func_([0-9a-f]{8})$', n)
    if m:
        return {m.group(1)}
    s = byname.get(n) if len(byname.get(n, ())) == 1 else refaddr.get(n, set())
    return s if s and len(s) == 1 else set()


callers = collections.defaultdict(set)
scanned = 0
for p in rsp:
    if 'stubs' in p.lower():
        continue
    v = cache.get(p)
    if not v:
        continue
    scanned += 1
    for n in v[2]:
        if n in stubn:
            for a in addr_of(n):
                if a in nos:
                    callers[a].add(os.path.basename(p))
inits = sorted(a for a in callers if 0x7c0000 <= int(a, 16) < 0x800000)
real = sorted((a for a in callers if a not in inits), key=lambda a: -len(callers[a]))
nm = lambda a: (ff.get(a) or {}).get('name') or ''
print('objects scanned %d | no-source placeholders called by REAL linked code: %d (initializers %d, functions to mine %d)'
      % (scanned, len(callers), len(inits), len(real)))
kinds = collections.Counter('unnamed func_' if not nm(a) or nm(a).startswith('func_') else ('RBX::' if '@RBX@@' in nm(a) else 'other named') for a in real)
print(dict(kinds))
(H / 'auto/mine_frontier.txt').write_text(''.join('%s %s  <- %d callers e.g. %s\n' % (a, nm(a), len(callers[a]), sorted(callers[a])[0]) for a in real))
(H / 'auto/mine_frontier.json').write_text(json.dumps({'mine': real, 'initializers': inits}, indent=0))
print((H / 'auto/mine_frontier.txt').read_text()[:1200])
