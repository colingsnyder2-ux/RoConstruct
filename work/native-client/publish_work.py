"""Publish the workflow files to the `work` branch: the published reviewed package plus this checkout's tools and guide.

  python work/native-client/publish_work.py [--push]

Builds one commit on top of origin/work (data/ guide+manifest+zip, workspace/ tool files), never touching other paths.
Without --push it only prints the commit id.
"""
import sys, io, json, zipfile, hashlib, subprocess, os
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, '.')
from roc import findings_workspace as fw
from roc.native_drafts import encoded
rev, mine = fw.committed_files('.', 'HEAD')
subprocess.run(['git', 'fetch', '-q', 'origin', 'work:refs/remotes/origin/work'], check=True)
old_zip = subprocess.check_output(['git', 'show', 'refs/remotes/origin/work:data/native-worker.zip'])
old = zipfile.ZipFile(io.BytesIO(old_zip))
files = {n: old.read(n) for n in old.namelist()}
overlay = {}
for n, d in mine.items():
    if n == 'docs/NATIVE_AGENT.md' or n.startswith(('work/native-client/', 'scripts/')):
        overlay[n] = d
    elif n.startswith(('rebuild/2008-06/native-classes/', 'rebuild/2008-06/native-headers/')) and n not in files:
        overlay[n] = d
overlay['roc/findings_workspace.py'] = mine['roc/findings_workspace.py']
changed = {n for n, d in overlay.items() if files.get(n) != d}
files.update(overlay)
print('overlay', len(overlay), 'changed/new', len(changed))
inv = {n: hashlib.sha256(d).hexdigest() for n, d in files.items() if n not in ('roconstruct-package.json', 'workspace-manifest.json')}
revision = hashlib.sha256(json.dumps(inv, sort_keys=True).encode()).hexdigest()
marker = json.loads(files['roconstruct-package.json']); marker.update(native_workflow_version=53, revision=revision)
files['roconstruct-package.json'] = encoded(marker)
wm = json.loads(files['workspace-manifest.json']); wm['source_revision'] = revision
wm['files'] = {n: hashlib.sha256(d).hexdigest() for n, d in files.items() if n != 'workspace-manifest.json'}
files['workspace-manifest.json'] = encoded(wm)
out = io.BytesIO()
with zipfile.ZipFile(out, 'w', zipfile.ZIP_DEFLATED) as z:
    for n, d in sorted(files.items()):
        i = zipfile.ZipInfo(n, (2026, 1, 1, 0, 0, 0)); i.compress_type = zipfile.ZIP_DEFLATED; z.writestr(i, d)
zb = out.getvalue()
man = json.loads(subprocess.check_output(['git', 'show', 'refs/remotes/origin/work:data/native-worker.json']))
man.update(workflow_version=53, sha256=hashlib.sha256(zb).hexdigest(), size=len(zb), source_revision=revision)
guide = mine['docs/NATIVE_AGENT.md']
upd = {'data/native-worker.zip': zb, 'data/native-worker.json': json.dumps(man, sort_keys=True, separators=(',', ':')).encode(), 'data/NATIVE_AGENT.md': guide}
for n in changed: upd['workspace/' + n] = overlay[n]
env = dict(os.environ, GIT_INDEX_FILE=os.path.abspath('.git/work-publish.index'))
def git(*a, inp=None): return subprocess.run(['git', *a], env=env, input=inp, capture_output=True, check=True).stdout
git('read-tree', 'refs/remotes/origin/work')
lines = b''
for n, d in upd.items():
    sha = subprocess.run(['git', 'hash-object', '-w', '--stdin'], input=d, capture_output=True, check=True).stdout.strip()
    lines += b'100644 %s\t%s\0' % (sha, n.encode())
    pass
git('update-index', '-z', '--add', '--index-info', inp=b''.join(b'0 0000000000000000000000000000000000000000\t' for _ in []) ) if False else None
for n, d in upd.items():
    sha = subprocess.run(['git', 'hash-object', '-w', '--stdin'], input=d, capture_output=True, check=True).stdout.decode().strip()
    git('update-index', '--add', '--cacheinfo', '100644,%s,%s' % (sha, n))
tree = git('write-tree').decode().strip()
parent = subprocess.check_output(['git', 'rev-parse', 'refs/remotes/origin/work']).decode().strip()
msg = 'Publish native workflow 53: tool bootstrap, RbxApp scope and queue, commit and census guards'
commit = subprocess.run(['git', 'commit-tree', tree, '-p', parent, '-m', msg], capture_output=True, check=True, text=True).stdout.strip()
print('commit', commit, 'zip', len(zb) // 1048576, 'MB', 'files', len(upd))
if '--push' in sys.argv:
    subprocess.run(['git', 'push', 'origin', commit + ':refs/heads/work'], check=True)
    print('pushed')
