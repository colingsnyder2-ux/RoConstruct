"""Clone clusters among the remaining functions (no model).  Functions whose bodies are byte-identical once relocation
fields are masked are the same source shape (template instances, per-class boilerplate).  Solving ONE member of a
cluster gives the pattern for all of them (clone_propagate.py then finishes the rest mechanically), so clusters are
where one solved function pays most.
  python work/native-client/cluster_survey.py   -> remaining-clusters.json (largest first) + printed summary"""
import collections
import hashlib
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
from roc import integration_site, match  # noqa: E402
import native_llm as m  # noqa: E402

reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
for _try in range(4):
    try:
        inactive = integration_site.inactive_code(ROOT)
        break
    except FileNotFoundError:
        pass
exact = {a for a, v in inactive.items() if v[1]}


def masked(addr):
    body, relocs = match.target('2008-06', addr)[:2]
    data = bytearray(body)
    for r in relocs or []:
        off = r if isinstance(r, int) else r[0] if isinstance(r, (list, tuple)) else r.get('offset', 0)
        for i in range(off, min(off + 4, len(data))):
            data[i] = 0
    return hashlib.sha1(bytes(data)).hexdigest()[:16], len(body)


groups = collections.defaultdict(list)
for addr in cl:
    if addr in exact:
        continue
    try:
        key, size = masked(addr)
    except Exception:                                            # noqa: BLE001
        continue
    groups[(key, size)].append(addr)
# does an already-exact function share the masked body?  (then clone_propagate can do the whole cluster now)
solved = collections.defaultdict(list)
want = {k for k, v in groups.items() if len(v) >= 2 or k[1] >= 24}
by_size = collections.defaultdict(set)
for k in want:
    by_size[k[1]].add(k)
sizes = json.loads((ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()[0]) and None
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if not line.strip():
        continue
    f = json.loads(line)
    if f['addr'] in exact and f.get('size') in by_size:
        try:
            key, size = masked(f['addr'])
        except Exception:                                        # noqa: BLE001
            continue
        if (key, size) in want:
            solved[(key, size)].append(f['addr'])
rows = []
for (key, size), addrs in sorted(groups.items(), key=lambda kv: -len(kv[1]) * kv[0][1]):
    if len(addrs) < 2 and not solved.get((key, size)):
        continue
    rows.append({'size': size, 'count': len(addrs), 'addresses': sorted(addrs), 'exact_twins': solved.get((key, size), [])[:5],
                 'names': sorted({((reg.get(a) or {}).get('signature') or (reg.get(a) or {}).get('name') or '')[:90] for a in addrs})[:3]})
(HERE / 'remaining-clusters.json').write_text(json.dumps(rows, indent=1))
multi = [r for r in rows if r['count'] >= 2]
print('remaining not exact:', sum(len(v) for v in groups.values()))
print('clusters with >= 2 members: %d clusters, %d functions' % (len(multi), sum(r['count'] for r in multi)))
print('functions with an already-exact masked twin: %d (in %d groups)' % (sum(r['count'] for r in rows if r['exact_twins']),
                                                                        sum(1 for r in rows if r['exact_twins'])))
for r in multi[:25]:
    print('%3d x %4d B  twins-exact=%d  %s' % (r['count'], r['size'], len(r['exact_twins']), (r['names'] or [''])[0][:95]))
