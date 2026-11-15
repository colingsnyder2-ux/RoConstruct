"""Thin main checkout: launch a verified Worker without overwriting existing work."""
import hashlib
import io
import json
from pathlib import Path
import subprocess
import sys
from urllib.error import URLError
from urllib.request import urlopen
import uuid
import zipfile

MANIFEST = 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.json'
AUTHORITY = 'RoConstruct/work/workspace'


def prepare(root, manifest_url=MANIFEST):
    cache=Path(root)/'local/workers'
    cache.mkdir(parents=True,exist_ok=True)
    selection=cache/'selected.json'
    try:
        with urlopen(manifest_url,timeout=30) as response:
            manifest=json.load(response)
    except (OSError,URLError):
        if not selection.exists():
            raise
        folder=cache/json.loads(selection.read_text())['folder']
        if not folder.is_dir() or not (folder/'roc.py').is_file():
            raise ValueError('Cached Worker is unavailable')
        return folder
    expected_url=manifest_url.rsplit('/',1)[0]+'/native-worker.zip'
    sha=manifest.get('sha256','')
    if (manifest.get('authority')!=AUTHORITY or manifest.get('workflow_version',0)<52
            or manifest.get('url')!=expected_url or len(sha)!=64
            or any(c not in '0123456789abcdef' for c in sha)):
        raise ValueError('Invalid work Worker manifest')
    if selection.exists():
        current=json.loads(selection.read_text())
        folder=cache/current['folder']
        if current['sha256']==sha and (folder/'roc.py').is_file():
            return folder  # Keep task edits and unsent drafts in this version intact.
    with urlopen(manifest['url'],timeout=120) as response:
        raw=response.read()
    if hashlib.sha256(raw).hexdigest()!=sha:
        raise ValueError('Worker ZIP hash mismatch; nothing installed')
    folder=cache/(sha[:12]+'-'+uuid.uuid4().hex[:8])
    with zipfile.ZipFile(io.BytesIO(raw)) as archive:
        names=archive.namelist()
        if len({n.casefold() for n in names})!=len(names) or not {'roc.py','roconstruct-package.json'}<=set(names):
            raise ValueError('Invalid Worker archive entries')
        for entry in archive.infolist():
            if ('\\' in entry.filename or not (folder/entry.filename).resolve().is_relative_to(folder.resolve())
                    or entry.external_attr>>16&0o170000==0o120000):
                raise ValueError('Unsafe Worker archive path')
        marker=json.loads(archive.read('roconstruct-package.json'))
        if marker.get('authority')!=AUTHORITY:
            raise ValueError('Worker authority mismatch')
        folder.mkdir()
        archive.extractall(folder)
    temporary=selection.with_suffix('.tmp')
    temporary.write_text(json.dumps(dict(folder=folder.name,sha256=sha)))
    temporary.replace(selection)
    return folder


def launch(args,root):
    folder=prepare(root)
    print('Worker workspace: '+str(folder),file=sys.stderr)
    return subprocess.call([sys.executable,str(folder/'roc.py'),*args],cwd=folder)
