"""python mewmerge.py [--apply]: take mew's new/changed native sources that are safe to merge.
Safe = file changed on mew's branch since the common base, unchanged here since that base (and no uncommitted edits),
not held by another worker's lease. New files absent here are taken too. Prints the list; --apply writes them to the
working tree (uncommitted) and writes work/donorfree-route/mew/taken.txt for the runner manifest."""
import subprocess, sys, json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
REF = 'refs/remotes/mew/optimistic-shannon'
P = ['rebuild/2008-06/native-classes', 'rebuild/2008-06/native-headers']
def git(*a):
    return subprocess.run(['git', *a], cwd=ROOT, capture_output=True, text=True).stdout
subprocess.run(['git', 'fetch', '-q', 'mew', 'claude/optimistic-shannon-0xccuy:' + REF], cwd=ROOT)
base = git('merge-base', 'HEAD', REF).strip()
# files mew changed since the base
changed = [l.split('\t') for l in git('diff', '--name-status', base, REF, '--', *P).splitlines()]
dirty = {l[3:].strip() for l in git('status', '--porcelain').splitlines()}
lease = subprocess.run([sys.executable, 'roc.py', 'lease', 'ls'], cwd=ROOT, capture_output=True, text=True).stdout
take = []
for st, f in [(c[0], c[-1]) for c in changed if len(c) >= 2]:
    if st[0] == 'D' or f in dirty: continue
    local = ROOT / f
    if local.exists():
        # unchanged here since base?
        if subprocess.run(['git', 'diff', '--quiet', base, 'HEAD', '--', f], cwd=ROOT).returncode != 0: continue
        if git('show', REF + ':' + f) == local.read_text(errors='replace') .replace('\r\n', '\n'): continue   # already identical
    if f in lease: continue
    take.append(f)
print(len(take), 'taken'); print('\n'.join(take))
if '--apply' in sys.argv:
    for f in take:
        data = subprocess.run(['git', 'show', REF + ':' + f], cwd=ROOT, capture_output=True).stdout
        (ROOT / f).parent.mkdir(parents=True, exist_ok=True); (ROOT / f).write_bytes(data)
    Path(ROOT / 'work/donorfree-route/mew').mkdir(exist_ok=True)
    (ROOT / 'work/donorfree-route/mew/taken.txt').write_text('\n'.join(take) + '\n')
