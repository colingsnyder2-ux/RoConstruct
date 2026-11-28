"""python funcdefaudit.py: native drafts that DEFINE a func_<A> name for code that is not the original at A.
A SpawnLocation draft labelled its own onServiceProvider `func_00490c30`; the original 0x490c30 is find<Service>, so the
converted DataModel::clearContents "found" a SpawnLocation and cleared a std::list inside it -> heap corruption on
Reset. When a converted body for A is in the link and the draft's func_<A> body (masked) differs from the original
at A, the draft definition is renamed (__rocmis_func_<A>) through quicktest's defrename step
(auto/natbody_defrename.json, keyed by object basename; ambiguous basenames skipped)."""
import collections, json, re, sys
from pathlib import Path
H = Path(__file__).parent
sys.argv = sys.argv[:1]
import importlib.util
_s = importlib.util.spec_from_file_location('nca', H / 'natcallaudit.py')   # body(), images
src = (H / 'natcallaudit.py').read_text(encoding='utf-8').split('ff = sorted(')[0]
g = {'__file__': str(H / 'natcallaudit.py')}
exec(compile(src, 'natcallaudit_head', 'exec'), g)
body, q, o, B = g['body'], g['q'], g['o'], g['B']
rr = json.loads((H / 'renamed/rename.json').read_text())
rsp_names = collections.Counter()
conv = set()
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    p = l.strip().strip('"')
    if p.lower().endswith('.obj'):
        b = Path(p).name
        while b[:3] in ('ca_', 'nx_', 'cf_', 'dr_'):
            b = b[3:]
        rsp_names[b] += 1
        m = re.fullmatch(r'([0-9a-f]{8})\.obj', b)
        if m and 'renamed' in p.replace('\\', '/') or (m and 'callfix' in p):
            conv.add(m.group(1))
rows = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            rows.append((int(p[2], 16), p[1], p[-1]))
        except ValueError:
            pass
rows.sort()
starts = [v for v, _, _ in rows]
bad = []
for i, (v, n, ob) in enumerate(rows):
    m = re.fullmatch(r'func_([0-9a-f]{8})', n)
    if not m or re.fullmatch(r'(?:(?:ca|cf|dr|nx)_)*(?:ca_)?[0-9a-f]{8}\.obj', ob) or ':' in ob or 'stubs' in ob or ob.startswith('pre'):
        continue
    A = int(m.group(1), 16)
    if not 0x401000 <= A < 0x7c0000:   # with no converted body the stub (return 0) beats foreign code (find<> -> null)
        continue
    nx = next((s for s in starts[i + 1:] if s > v), v + 0x200)
    sq = body(q, v, nx, 0x400000, 0x3000000)[0]
    so = body(o, A, A + 0x1800, 0x400000, 0x9a0000)[0]
    if sq != so:
        base = ob
        while base[:3] in ('ca_', 'nx_', 'cf_', 'dr_'):
            base = base[3:]
        bad.append([base, n, rsp_names.get(base, 0)])
pf = H / 'auto/natbody_defrename.json'
plan = json.loads(pf.read_text()) if pf.exists() else {}
nadd = 0
for base, n, cnt in bad:
    if cnt == 1 and n not in plan.get(base, {}):
        plan.setdefault(base, {})[n] = '__rocmis_' + n; nadd += 1
pf.write_text(json.dumps(plan, indent=0))
print('funcdefaudit: native-defined func_<A> with a converted body for A and a different body: %d (added %d, ambiguous %d)'
      % (len(bad), nadd, sum(1 for b in bad if b[2] != 1)))
for b in bad[:12]:
    print('  ', b[1], b[0][:70])
