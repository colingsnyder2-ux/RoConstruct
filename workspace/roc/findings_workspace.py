"""Findings main/workspace is the native source authority; publish downloads and drafts."""
import argparse
import hashlib
import io
import json
from pathlib import Path
import subprocess
import time
import zipfile

from roc.native_drafts import ROOT, Inbox, atomic, digest, encoded, lock, safe_path

BASE_URL = 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/'
AUTHORITY = 'RoConstruct-findings/main/workspace'


def git(root, *args):
    return subprocess.check_output(['git', *args], cwd=root).decode().strip()


def fetch(root):
    subprocess.run(['git','fetch','--no-write-fetch-head','findings',
                    'refs/heads/main:refs/remotes/findings/main'],cwd=root,capture_output=True,check=True,timeout=120)
    return git(root,'rev-parse','refs/remotes/findings/main')


def committed_files(root, ref, prefix=''):
    """Read immutable Git blobs, never the changing working tree or another worker's index."""
    revision = git(root,'rev-parse',ref+'^{commit}')
    rows = subprocess.check_output(['git','ls-tree','-r','-z',revision,'--',prefix or '.'],cwd=root).split(b'\0')
    entries = []
    for row in rows:
        if not row:
            continue
        meta,name=row.split(b'\t');mode,kind,sha=meta.split();name=name.decode()
        if prefix:
            if not name.startswith(prefix):
                continue
            name=name[len(prefix):]
        if mode not in (b'100644',b'100755') or kind != b'blob':
            raise ValueError('Non-regular workspace entry: '+name)
        if name.startswith(('tools/','local/','src/','.github/')) or name.endswith(('.key','.db','.exe','.dll','.obj','.pdb')) or 'secrets' in name.lower():
            continue
        entries.append((name,sha.decode()))
    result=subprocess.run(['git','cat-file','--batch'],cwd=root,
                          input=('\n'.join(sha for _,sha in entries)+'\n').encode(),capture_output=True,check=True)
    stream=io.BytesIO(result.stdout);files={}
    for name,sha in entries:
        header=stream.readline().split()
        if header[0].decode()!=sha or header[1]!=b'blob':
            raise ValueError('Git snapshot identity mismatch')
        files[name]=stream.read(int(header[2]));stream.read(1)
    return revision,files


def source_files(root, ref):
    _,files=committed_files(root,ref,'workspace/')
    for name in ('roconstruct-package.json','workspace-manifest.json'):
        files.pop(name,None)
    if 'roc/native_drafts.py' not in files:
        raise ValueError('Findings workspace lacks draft tooling; initialize reviewed workspace first')
    return files


def source_revision(files):
    return digest({name:hashlib.sha256(data).hexdigest() for name,data in files.items()})


def export(root, ref):
    files=source_files(root,ref)
    revision=source_revision(files)
    files['roconstruct-package.json']=encoded(dict(package='worker',revision=revision,authority=AUTHORITY,
        native_workflow=True,native_workflow_version=51,matching_workflow_version=4,draft_workflow_version=1))
    inventory={name:hashlib.sha256(data).hexdigest() for name,data in files.items()}
    provenance=dict(schema=1,authority=AUTHORITY,source_revision=revision,files=inventory,
                    draft_workflow_version=1,baseline='reviewed findings source; incomplete candidates stay inactive')
    files['workspace-manifest.json']=encoded(provenance)
    output=io.BytesIO()
    with zipfile.ZipFile(output,'w',zipfile.ZIP_DEFLATED) as archive:
        for name,data in sorted(files.items()):
            info=zipfile.ZipInfo(name,(2026,1,1,0,0,0));info.compress_type=zipfile.ZIP_DEFLATED
            archive.writestr(info,data)
    archive_bytes=output.getvalue()
    manifest=dict(schema=1,authority=AUTHORITY,workflow_version=51,matching_workflow_version=4,
                  draft_workflow_version=1,source_revision=revision,url=BASE_URL+'native-worker.zip',
                  sha256=hashlib.sha256(archive_bytes).hexdigest(),size=len(archive_bytes),
                  guide=BASE_URL+'NATIVE_AGENT.md',matching_guide=BASE_URL+'MATCHING_AGENT.md',
                  native_clients=['2008-06'],invitation_required=False,
                  server='https://colinpc.tail2879d0.ts.net',
                  draft_server='https://colinpc.tail2879d0.ts.net/native-drafts')
    # Packages update metadata/downloads only. Native files are never mirrored from origin.
    return revision,{'workspace/workspace-manifest.json':encoded(provenance),
        'workspace/roconstruct-package.json':files['roconstruct-package.json'],
        'data/native-worker.zip':archive_bytes,'data/native-worker.json':encoded(manifest),
        'data/NATIVE_AGENT.md':files['docs/NATIVE_AGENT.md'],
        'data/MATCHING_AGENT.md':files['docs/MATCHING_AGENT.md']}


def publish(root, ref=None):
    from roc.findings_transport import publish_files
    root=Path(root)
    with lock(root/'work/findings-workspace.lock'):
        parent=ref or fetch(root)
        revision,files=export(root,parent)
        inbox=Inbox(root);files.update(inbox.archive())
        files['coordination/notes.json']=encoded(inbox.notes())
        def guard(current):
            if source_revision(source_files(root,current))!=revision:
                raise ValueError('Findings workspace advanced; retry publication against current source')
        result=publish_files(root,files,'Refresh findings native downloads and draft archive',guard=guard)
        atomic(root/'work/findings-workspace-status.json',dict(**result,authority=AUTHORITY,
               source_revision=revision,last_success=time.time(),error=None))
        return result


def integrate(root, base, files, message):
    """Commit explicit reviewed paths directly to findings, without moving local HEAD/index."""
    from roc.findings_transport import publish_files
    from roc.fork_merge import preservation_losses
    root=Path(root)
    git(root,'rev-parse',base+':workspace')
    if not files or len({name.casefold() for name in files})!=len(files):
        raise ValueError('Empty or case-colliding reviewed path set')
    for name in files:
        safe_path(name)
    payload={'workspace/'+name:data for name,data in files.items()}
    def blob(ref,name):
        p=subprocess.run(['git','rev-parse','--verify',ref+':workspace/'+name],cwd=root,capture_output=True)
        return p.stdout if p.returncode==0 else None
    def guard(parent):
        if subprocess.run(['git','merge-base','--is-ancestor',base,parent],cwd=root,capture_output=True).returncode:
            raise ValueError('Findings integration base is not canonical ancestry')
        for name in files:
            if blob(base,name)!=blob(parent,name):
                raise ValueError('Canonical file advanced; review three-way conflict: '+name)
    def verify(parent,candidate):
        before=git(root,'rev-parse',parent+':workspace')
        after=git(root,'rev-parse',candidate+':workspace')
        losses=preservation_losses(root,before,after)
        receipt=dict(base=parent,candidate=candidate,base_workspace=before,candidate_workspace=after,
                     losses=losses,passed=not losses,paths=sorted(files),authority=AUTHORITY)
        atomic(root/'work/findings-integration'/('preservation-'+candidate+'.json'),receipt)
        if losses:
            raise ValueError('Findings integration loses native source/proofs: '+json.dumps(losses))
    return publish_files(root,payload,message,guard=guard,verify=verify)


def publish_loop(root,every=3600):
    while True:
        try:
            if not (root/'work/findings-workspace-paused.json').exists():
                publish(root)
            delay=every
        except (OSError,ValueError,RuntimeError,subprocess.SubprocessError) as error:
            atomic(root/'work/findings-workspace-status.json',dict(error=str(error),failed=time.time(),authority=AUTHORITY))
            delay=60
        for _ in range(delay):
            time.sleep(1)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    sub=parser.add_subparsers(dest='action')
    action=sub.add_parser('integrate')
    action.add_argument('--manifest',type=Path,required=True)
    action.add_argument('--message',required=True)
    args=parser.parse_args()
    if args.action=='integrate':
        spec=json.loads(args.manifest.read_text())
        files={name:Path(path).read_bytes() for name,path in spec['files'].items()}
        result=integrate(args.root,spec['base'],files,args.message)
    else:
        result=publish(args.root)
    print(json.dumps(result,indent=2))


if __name__=='__main__':
    main()
