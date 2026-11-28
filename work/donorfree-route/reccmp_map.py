"""python reccmp_map.py [EXE MAP] [--only ADDR,...] [--top N]: reccmp's comparison engine without a PDB.
reccmp (isledecomp) normally learns recomp symbols from a PDB and original addresses from `// FUNCTION:` source
annotations. We already have both: the lld map (symbol -> our address) and the address claims of our names
(func_<A>, rename.json symbols, registry names unique to one address). Every claimed pair becomes a reccmp match;
FunctionComparator then diffs each pair with its name-aware placeholders (a call is compared by WHICH ENTITY it
reaches, so create<Team> vs create<GameSettings> differs even with identical bytes) and its effective-match fixups
(register/jump swaps). Static only: no link, no launch.
Writes auto/reccmp_map.json [{orig, name, ratio, effective}] and prints the worst pairs."""
import bisect, collections, json, logging, re, sys
from pathlib import Path
from reccmp.formats import detect_image
from reccmp.compare.db import EntityDb
from reccmp.compare.lines import LinesDb
from reccmp.compare.functions import FunctionComparator
from reccmp.compare.event import create_logging_wrapper
from reccmp.cvdump.types import CvdumpTypesParser
from reccmp.types import EntityType, ImageId
logging.basicConfig(level=logging.ERROR)
H = Path(__file__).parent
args = sys.argv[1:]
exe = next((a for a in args if a.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe'))
mp = next((a for a in args if a.lower().endswith('.map')), str(H / 'linkexp/qt.map'))
only = {int(x, 16) for x in (args[args.index('--only') + 1].split(',') if '--only' in args else [])}
top = int(args[args.index('--top') + 1]) if '--top' in args else 40
orig_bin = detect_image(str(H.parents[1] / 'clients/2008-06/Roblox.exe'))
recomp_bin = detect_image(exe)
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
rr = json.loads((H / 'renamed/rename.json').read_text())
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
regaddr = collections.defaultdict(set)
for a, v in reg.items():
    n = (v or {}).get('name') or ''
    if n and 0x401000 <= int(a, 16) < 0x7c0000:
        regaddr[n].add(int(a, 16))
sym, objof = {}, {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        sym.setdefault(p[1], v); objof.setdefault(p[1], p[-1])
qstarts = sorted(set(sym.values()))
db = EntityDb()
# original entities: every function start, named by the registry (placeholder names for call targets)
rows = []
for i, a in enumerate(ff):
    if 0x401000 <= a < 0x7c0000:
        nx = ff[i + 1] if i + 1 < len(ff) else a + 0x100
        rows.append((a, {'type': EntityType.FUNCTION, 'name': ((reg.get('%08x' % a) or {}).get('name') or 'func_%08x' % a), 'orig_size': min(nx - a, 0x4000)}))
db.bulk_insert(ImageId.ORIG, rows)
first = {}
for n, v in sym.items():
    first.setdefault(v, n)
rows = []
for j, v in enumerate(qstarts):
    nx = qstarts[j + 1] if j + 1 < len(qstarts) else v + 0x100
    rows.append((v, {'type': EntityType.FUNCTION, 'name': first[v], 'recomp_size': min(nx - v, 0x4000)}))
db.bulk_insert(ImageId.RECOMP, rows)
pairs = {}
for n, v in sym.items():
    if 'stubs' in objof[n] or ':' in objof[n]:
        continue
    m = re.fullmatch(r'func_([0-9a-f]{8})', n)
    A = int(m.group(1), 16) if m else (next(iter(regaddr[n])) if len(regaddr.get(n, ())) == 1 else None)
    if A and 0x401000 <= A < 0x7c0000:
        pairs.setdefault(A, v)
for a, x in rr.items():
    s = x.get('symbol')
    if x.get('status') == 'renamed' and s in sym and 'stubs' not in objof[s]:
        pairs.setdefault(int(a, 16), sym[s])
if only:
    pairs = {a: v for a, v in pairs.items() if a in only}
db.bulk_match(sorted(pairs.items()))
fc = FunctionComparator(db, LinesDb(), orig_bin, recomp_bin, create_logging_wrapper(logging.getLogger('r')), CvdumpTypesParser())
out = []
for A, v in sorted(pairs.items()):
    m = db.get_one_match(A)
    if m is None:
        continue
    try:
        r_ = fc.compare_function(m)
    except Exception as e:
        out.append({'orig': '%08x' % A, 'name': first.get(v), 'obj': objof.get(first.get(v)), 'ratio': -1, 'effective': False, 'err': str(e)[:80]}); continue
    out.append({'orig': '%08x' % A, 'name': first.get(v), 'obj': objof.get(first.get(v)), 'ratio': round(r_.match_ratio, 3), 'effective': r_.is_effective_match})
(H / 'auto/reccmp_map.json').write_text(json.dumps(out, indent=0))
ok = [o for o in out if o['ratio'] >= 0]
print('reccmp_map: pairs %d, 100%% %d, effective %d, >=90%% %d, <50%% %d, errors %d'
      % (len(out), sum(o['ratio'] == 1 for o in ok), sum(o['effective'] for o in ok), sum(o['ratio'] >= 0.9 for o in ok),
         sum(o['ratio'] < 0.5 for o in ok), len(out) - len(ok)))
conv = lambda ob: bool(re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob or ''))
print('  average ratio converted %.3f, native %.3f' % (
    sum(o['ratio'] for o in ok if conv(o['obj'])) / max(1, sum(1 for o in ok if conv(o['obj']))),
    sum(o['ratio'] for o in ok if not conv(o['obj'])) / max(1, sum(1 for o in ok if not conv(o['obj'])))))
for o in sorted(ok, key=lambda o: o['ratio'])[:top]:
    print('  %5.2f %s %s | %s' % (o['ratio'], o['orig'], (o['name'] or '')[:70], (o['obj'] or '')[:40]))
