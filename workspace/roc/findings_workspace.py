"""Publish immutable committed contributor workspaces and durable draft archives."""
import argparse
import hashlib
import io
import json
from pathlib import Path
import subprocess
import time
import zipfile

from roc.native_drafts import ROOT, Inbox, atomic, encoded, lock

BRANCH = 'codex/native-partial-search-20261029'
BASE_URL = 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/'


def committed_files(root, ref):
    """Read Git blobs, never the changing native working tree or another worker's index."""
    revision = subprocess.check_output(['git', 'rev-parse', ref + '^{commit}'], cwd=root).decode().strip()
    rows = subprocess.check_output(['git', 'ls-tree', '-r', '-z', revision], cwd=root).split(b'\0')
    entries = []
    for row in rows:
        if not row:
            continue
        meta, name = row.split(b'\t')
        mode, kind, sha = meta.split()
        name = name.decode()
        if mode not in (b'100644', b'100755') or kind != b'blob':
            raise ValueError('Non-regular workspace entry: ' + name)
        if (name.startswith(('clients/', 'tools/', 'local/', 'src/', '.github/'))
                and name not in ('clients/clients.json','clients/sources.json','clients/donor.json')):
            continue
        if name.endswith(('.key', '.db', '.exe', '.dll', '.obj', '.pdb')) or 'secrets' in name.lower():
            continue
        entries.append((name, sha.decode()))
    process = subprocess.run(['git','cat-file','--batch'], cwd=root,
                             input=('\n'.join(sha for _,sha in entries)+'\n').encode(),
                             capture_output=True, check=True)
    stream = io.BytesIO(process.stdout)
    files = {}
    for name, sha in entries:
        header = stream.readline().split()
        if header[0].decode() != sha or header[1] != b'blob':
            raise ValueError('Git snapshot identity mismatch')
        files[name] = stream.read(int(header[2]))
        if b'https://discord.com/api/webhooks/' in files[name] or b'https://discordapp.com/api/webhooks/' in files[name]:
            from roc.findings_publish import portable_text
            files[name] = portable_text(files[name])
        stream.read(1)
    return revision, files


def export(root, ref=BRANCH):
    root = Path(root)
    revision, files = committed_files(root, ref)
    if 'roc/native_drafts.py' not in files:
        raise ValueError('Draft workflow must be committed before workspace publication')
    folder = root / 'local/findings/data'
    folder.mkdir(parents=True, exist_ok=True)
    seed = folder / 'native-worker.zip'
    extras = {}
    if seed.exists():
        with zipfile.ZipFile(seed) as archive:
            # ABI evidence and generated adopted units may not be tracked in Git.
            for name in ('rebuild/2008-06/manifests/abi-evidence.json', 'research/native-units.json'):
                if name not in files and name in archive.namelist():
                    extras[name] = archive.read(name)
    files.update(extras)
    marker = dict(package='worker', revision=revision, native_workflow=True,
                  native_workflow_version=50, matching_workflow_version=4, draft_workflow_version=1)
    files['roconstruct-package.json'] = encoded(marker)
    inventory = {name: hashlib.sha256(data).hexdigest() for name,data in files.items()}
    provenance = dict(schema=1, source_commit=revision, files=inventory, draft_workflow_version=1,
                      baseline='reviewed-committed-source; incomplete candidates remain inactive',
                      toolchain='Use pinned roc install/client-fetch/lib-fetch recipes; reuse verified caches')
    files['workspace-manifest.json'] = encoded(provenance)
    output = io.BytesIO()
    with zipfile.ZipFile(output, 'w', zipfile.ZIP_DEFLATED) as archive:
        for name,data in sorted(files.items()):
            info = zipfile.ZipInfo(name, (2026,1,1,0,0,0))
            info.compress_type = zipfile.ZIP_DEFLATED
            archive.writestr(info, data)
    archive_bytes = output.getvalue()
    old = folder / 'native-worker.json'
    previous = json.loads(old.read_text()) if old.exists() else {}
    server = previous.get('server', 'https://colinpc.tail2879d0.ts.net')
    manifest = dict(schema=1, workflow_version=50, matching_workflow_version=4, draft_workflow_version=1,
                    source_commit=revision, url=BASE_URL+'native-worker.zip',
                    sha256=hashlib.sha256(archive_bytes).hexdigest(), size=len(archive_bytes),
                    guide=BASE_URL+'NATIVE_AGENT.md', matching_guide=BASE_URL+'MATCHING_AGENT.md',
                    native_clients=['2008-06'], invitation_required=False, server=server,
                    draft_server=previous.get('draft_server', 'https://colinpc.tail2879d0.ts.net/native-drafts'))
    for key in ('abi_manifest_sha256','abi_manifest_classes'):
        if key in previous:
            manifest[key] = previous[key]
    result = {'workspace/'+name:data for name,data in files.items()}
    result.update({'data/native-worker.zip':archive_bytes, 'data/native-worker.json':encoded(manifest),
                   'data/NATIVE_AGENT.md':files['docs/NATIVE_AGENT.md'],
                   'data/MATCHING_AGENT.md':files['docs/MATCHING_AGENT.md']})
    return revision, result


def publish(root, ref=BRANCH):
    from roc.findings_transport import publish_files
    root = Path(root)
    with lock(root / 'work/findings-workspace.lock'):
        if ref == BRANCH:
            subprocess.run(['git','fetch','--no-write-fetch-head','origin',
                            'refs/heads/'+BRANCH+':refs/remotes/origin/'+BRANCH],
                           cwd=root,capture_output=True,check=True,timeout=120)
            ref = subprocess.check_output(['git','rev-parse','refs/remotes/origin/'+BRANCH],cwd=root).decode().strip()
        revision, files = export(root, ref)
        files.update(Inbox(root).archive())
        def guard(parent):
            # A delayed exporter cannot roll back a newer published source revision.
            old = subprocess.run(['git','show',parent+':workspace/workspace-manifest.json'],cwd=root,capture_output=True)
            if old.returncode == 0:
                previous = json.loads(old.stdout)
                before = previous['source_commit']
                if before != revision:
                    p = subprocess.run(['git','merge-base','--is-ancestor',before,revision],cwd=root,capture_output=True)
                    if p.returncode:
                        raise ValueError('Published workspace is newer/diverged; refuse stale export')
                return ['workspace/'+name for name in previous['files'] if 'workspace/'+name not in files]
        result = publish_files(root, files, 'Publish committed native workspace and draft archive', guard=guard)
        atomic(root/'work/findings-workspace-status.json',dict(**result,source_commit=revision,last_success=time.time()))
        return result


def publish_loop(root, every=3600):
    while True:
        try:
            publish(root)
            delay = every
        except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
            atomic(root/'work/findings-workspace-status.json',dict(error=str(error),failed=time.time()))
            delay = 60
        for _ in range(delay):
            time.sleep(1)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--ref',default=BRANCH)
    args = parser.parse_args()
    print(json.dumps(publish(args.root,args.ref),indent=2))


if __name__ == '__main__':
    main()
