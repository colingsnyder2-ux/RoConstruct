"""Path candidates for held native files: the classes each file defines (Class::member definitions), looked up in the
2007 rbxgs donor tree (which file defines Class::...). Evidence only; a weak, inferred-tier signal.
    python work/donorfree-route/donor_paths.py -> work/donorfree-route/donor_path_candidates.json"""
import json, re
from collections import Counter, defaultdict
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
DONOR = ROOT / 'tools/rbxgs/Client'
DEF = re.compile(r'^[\w:<>,\s\*&~]*?\b([A-Z]\w+)::(~?\w+)\s*\(', re.M)
held = json.loads((ROOT / 'work/donorfree-route/map_select.json').read_text())['held_rows']
held = [k for k, v in held.items() if not v.get('target_path')]
where = defaultdict(Counter)                       # class -> donor file counts
for f in DONOR.rglob('*.cpp'):
    if f.name.startswith('roc_'):
        continue
    rel = f.relative_to(DONOR).as_posix()
    for cls, _ in DEF.findall(f.read_text(errors='replace')):
        where[cls][rel] += 1
out = {}
for src in held:
    text = (ROOT / src).read_text(errors='replace')
    classes = Counter(c for c, _ in DEF.findall(text) if c not in ('RBX', 'G3D', 'std', 'boost', 'Reflection'))
    votes = Counter()
    for cls, n in classes.items():
        if where.get(cls):
            best, hits = where[cls].most_common(1)[0]
            votes[best] += n
    if votes:
        best, n = votes.most_common(1)[0]
        out[src] = {'donor_file': best, 'share': round(n / sum(classes.values()), 2), 'classes': dict(classes.most_common(4)),
                    'others': dict(votes.most_common(3)[1:])}
Path(ROOT / 'work/donorfree-route/donor_path_candidates.json').write_text(json.dumps(out, indent=1))
strong = {k: v for k, v in out.items() if v['share'] >= 0.8}
print('held', len(held), 'with donor candidate', len(out), 'strong (>=80% of defs)', len(strong))
for k, v in sorted(strong.items())[:40]:
    print('%-45s -> %s (%.0f%%)' % (Path(k).stem[:45], v['donor_file'], 100 * v['share']))
