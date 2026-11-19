"""Compare pdb-class-layouts.json with native headers for classes that block remaining functions.
Writes pdb-layout-gaps.json: class -> {header, size, missing_members:[[name,type,off]], missing_methods}"""
import json, re, collections
from pathlib import Path
R = Path(__file__).resolve().parents[2]
H = R / 'rebuild/2008-06/native-headers'
L = json.load(open(Path(__file__).parent / 'pdb-class-layouts.json'))
rem = json.load(open(Path(__file__).parent / 'remaining-classified.json'))
plc = json.load(open(Path(__file__).parent / 'placeholder-lane/results.json'))
cands = collections.Counter()
for a, v in rem.items():
    n = v['name']
    if n.startswith('func_') or '$' in n:
        continue
    parts = n.split('@@')[0].lstrip('?').split('@')
    if len(parts) >= 2:
        cands['::'.join(reversed(parts[1:]))] += 1
for a, v in plc.items():
    if v['status'] in ('compile_failed', 'no-class-header', 'draft', 'rejected-header-add', 'rejected-invented') and v['class']:
        cands[v['class']] += 1
cands = {c: n for c, n in cands.items() if c in L}
idx = collections.defaultdict(list)
pat = re.compile(r'\b(?:class|struct)\s+(\w+)\b[^;{]*\{')
for f in H.rglob('*.h'):
    t = f.read_text(errors='ignore')
    for m in pat.finditer(t):
        i, d = m.end(), 1
        while d and i < len(t):
            d += (t[i] == '{') - (t[i] == '}'); i += 1
        idx[m.group(1)].append((f, t[m.end():i]))
out = {}
for c, n in sorted(cands.items(), key=lambda x: -x[1]):
    short = c.split('::')[-1]
    e = L[c]
    ent = {'blocked_functions': n, 'pdb_size': e['size'], 'header': None}
    if short in idx:
        f, body = max(idx[short], key=lambda x: len(x[1]))
        ids = set(re.findall(r'\w+', body))
        ent['header'] = str(f.relative_to(R))
        ent['missing_members'] = [m for m in e['members'] if m[0] not in ids]
        ent['missing_methods'] = [m for m in e['methods'] if m not in ids and not m.startswith('operator') and m != short and m != '~' + short]
        ent['bases_missing'] = [b[0] for b in e['bases'] if b[0].split('<')[0].split('::')[-1] not in ids and b[0].split('<')[0].split('::')[-1] not in set(re.findall(r'\w+', f.read_text(errors='ignore')))]
    out[c] = ent
(Path(__file__).parent / 'pdb-layout-gaps.json').write_text(json.dumps(out, indent=1))
print(len(out), 'classes;', sum(1 for e in out.values() if not e['header']), 'no header;',
      sum(1 for e in out.values() if e.get('missing_members')), 'with missing members')
