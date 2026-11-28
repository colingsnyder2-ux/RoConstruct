"""python grab_branches.py: copy native class sources that exist on ANY fetched remote branch (any path ending in
native-classes/<file>.cpp, plus findings/main drafts/files) but in neither rebuild/2008-06/native-classes nor
native-findings, into rebuild/2008-06/native-findings-new/ (newest commit wins per file name). Never overwrites."""
import json, os, subprocess
from pathlib import Path
R = Path(__file__).resolve().parents[2]
os.chdir(R)
git = lambda *a: subprocess.run(['git'] + list(a), capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
have = set(os.listdir('rebuild/2008-06/native-classes')) | set(os.listdir('rebuild/2008-06/native-findings'))
best = {}
for ref in git('for-each-ref', '--format=%(refname:short) %(committerdate:unix)', 'refs/remotes').split('\n'):
    if not ref.strip() or ref.endswith('HEAD') or 'gh-pages' in ref:
        continue
    r, t = ref.rsplit(' ', 1)
    for p in git('ls-tree', '-r', '--name-only', r).split('\n'):
        b = os.path.basename(p)
        if b.endswith('.cpp') and '/native-classes/' in '/' + p and '2008' in p and b not in have:
            if b not in best or int(t) > best[b][0]:
                best[b] = (int(t), r, p)
out = Path('rebuild/2008-06/native-findings-new')
out.mkdir(exist_ok=True)
n = 0
for b, (t, r, p) in sorted(best.items()):
    data = subprocess.run(['git', 'show', '%s:%s' % (r, p)], capture_output=True).stdout
    if data and not (out / b).exists():
        (out / b).write_bytes(data); n += 1
json.dump({b: [r, p] for b, (t, r, p) in best.items()}, open('work/donorfree-route/auto/grab_branches.json', 'w'), indent=1)
from collections import Counter
print('%d new native class files copied to %s; by branch: %s' % (n, out, dict(Counter(v[1] for v in best.values()))))
