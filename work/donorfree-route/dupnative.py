"""python dupnative.py: converted copies (ca_*/nx_* objects defining func_<A>) of functions whose registry name S is also
defined by a native object. Two live copies of one function split its state: Array::realloc allocated with the native
System::alignedMalloc and freed with the converted alignedFree (func_00507d20) -> G3D BufferPool heap corruption on
the first script-parented Part; Name::dictionary and EffectSettings::getToneMap would keep two singletons.
Plan (classdesc.py pattern): rename the converted definition func_<A> away (natbody_defrename.json) and alias
func_<A>=S (aliases_dupnative.txt), so every caller reaches the native copy. Skipped: ctors/dtors/special members
(layout-bound, ICF-ambiguous names), names on >2 registry addresses (folded identities), Lua (luarbx owns it), XTP."""
import collections, json, re
from pathlib import Path
H = Path(__file__).parent
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
nc = collections.Counter((v or {}).get('name') for v in reg.values())
m = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        m.setdefault(p[1], (p[2], p[-1]))
plan, al = {}, {}
for s, (va, o) in m.items():
    mm = re.fullmatch(r'func_([0-9a-f]{8})', s)
    if not mm or not re.match(r'(ca|nx)_', o) or o.startswith('ca_lc_'):
        continue
    n = (reg.get(mm.group(1)) or {}).get('name')
    if not n or nc[n] > 2 or n.startswith('??') or n not in m or m[n][0] == va or 'stubs' in m[n][1] or m[n][1].startswith('linked:'):
        continue
    plan.setdefault(re.sub(r'^.*?([0-9a-f]{8}\.obj)$', r'\1', o) if re.search(r'[0-9a-f]{8}\.obj$', o) else o, {})[s] = '__rocdup_' + s
    al[s] = n
pf = H / 'auto/natbody_defrename.json'
cur = json.loads(pf.read_text()) if pf.exists() else {}
for k, v in plan.items():
    cur.setdefault(k, {}).update(v)
pf.write_text(json.dumps(cur, indent=0))
af = H / 'aliases_dupnative.txt'
prev = dict(l.split('=', 1) for l in af.read_text().splitlines() if '=' in l) if af.exists() else {}
prev.update(al)
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(prev.items())))
print('dupnative: converted copies of natively defined functions rebound %d (total %d) e.g. %s' % (len(al), len(prev), sorted(al.items())[:3]))
