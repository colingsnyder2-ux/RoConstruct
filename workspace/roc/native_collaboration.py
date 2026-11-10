"""Cross-PC method lease client. Contributor source stays reference data, never chat instructions."""
import json
import os
import re
import tempfile
import threading
import uuid
from pathlib import Path
from urllib.parse import urlencode

from roc import integration, worker

PREFIX = '/v1/integration/recovery/'


class Remote:
    def __init__(self, server, user, token=None, identity=None):
        self.api = worker.Api(server, token)
        self.user = user
        self.worker = identity or uuid.uuid4().hex
        self.lock = threading.Lock()

    def call(self, action, body=None):
        with self.lock:
            return self.api.call(PREFIX+action, dict(dict(user=self.user,worker=self.worker),**body) if body is not None else None)

    def snapshot(self, folder):
        from roc import native_recovery as recovery
        payload = self.call('catalog')
        files = payload['files']
        revision=payload.get('revision','')
        if not re.fullmatch('[0-9a-f]{64}',revision) or integration.digest(files)!=revision:
            raise ValueError('Invalid shared snapshot revision')
        folder=Path(folder)/revision
        payload['workspace']=str(folder)
        context=materialize_probe_headers(payload,folder/'context')
        if context:payload['probe_context']=str(context)
        canonical=materialize_canonical_headers(payload,folder/'canonical-context')
        if canonical:payload['canonical_context']=str(canonical)
        if not isinstance(files, dict) or len(files)>4096 or len(json.dumps(files).encode())>integration.MAX_OVERLAY_BYTES:
            raise ValueError('Invalid shared native snapshot size')
        if len({rel.casefold() for rel in files})!=len(files):raise ValueError('Case-colliding shared source paths')
        for rel, text in files.items():
            path = snapshot_path(folder, rel)
            if not isinstance(text,str): raise ValueError('Invalid shared source')
            path.parent.mkdir(parents=True,exist_ok=True)
            if not path.exists() or path.read_text(encoding='utf-8')!=text:
                path.write_text(text,encoding='utf-8')
        return payload

    def claim(self, task):
        from roc.native_recovery import INCLUDE_PROFILES
        return self.call('claim', dict(target=task['target'], signature=task['signature'],include_profiles=list(INCLUDE_PROFILES),method_selectors=['signature-v1']))

    def renew(self, lease):
        return self.call('renew',dict(lease=lease['lease'],worker=lease.get('worker',self.worker)))

    def release(self, lease, outcome='released'):
        return self.call('release',dict(lease=lease['lease'],outcome=outcome,worker=lease.get('worker',self.worker)))

    def submit(self, lease, record, check_only=False):
        return self.call('candidate',dict(lease=lease['lease'],worker=lease.get('worker',self.worker),model=record['model'],
            candidate=Path(record['candidate']).read_text(encoding='utf-8') if not check_only else None,
            check_only=check_only))

    def status(self, job):
        return self.call('status?'+urlencode(dict(id=job)))

    def close(self):
        self.api.close()


def materialize_canonical_headers(payload, directory):
    return materialize_probe_headers(dict(probe_headers=payload.get('canonical_headers',{}),
                                         probe_revision=payload.get('canonical_revision')),directory)


def materialize_probe_headers(payload, directory):
    """Separate immutable compiler fallback declarations from editable native source files."""
    headers=payload.get('probe_headers',{})
    if not isinstance(headers,dict) or len(headers)>2048 or len(json.dumps(headers).encode())>integration.MAX_OVERLAY_BYTES:
        raise ValueError('Invalid native probe header context')
    if not headers:return None
    revision=integration.digest(headers)
    if payload.get('probe_revision')!=revision or len({name.casefold() for name in headers})!=len(headers):
        raise ValueError('Invalid native probe header revision')
    directory=(Path(directory)/revision).resolve()
    if any(len(str(directory/name))>259 for name in headers):
        directory=(Path(os.environ.get('LOCALAPPDATA',tempfile.gettempdir()))/'RoConstruct/nc'/revision).resolve()
    for name,text in headers.items():
        relative=Path(name)
        if not isinstance(text,str) or '\\' in name or ':' in name or relative.is_absolute() or '..' in relative.parts or relative.suffix not in ('.h','.hpp','.inl'):
            raise ValueError('Invalid native probe header path')
        target=directory/relative
        if not target.resolve().is_relative_to(directory):raise ValueError('Native probe header escaped context')
        if len(str(target))>259:raise ValueError('Native header path exceeds the historical compiler limit: '+str(target))
        target.parent.mkdir(parents=True,exist_ok=True)
        if not target.exists():target.write_text(text,encoding='utf-8')
        elif target.read_text(encoding='utf-8')!=text:raise ValueError('Immutable native probe context was modified')
    return directory


def seed_missing(shared, files):
    """Publish new host files only. Never replace an existing local editor's bytes."""
    from roc import native_recovery as recovery
    for rel,text in files.items():
        path=snapshot_path(shared,rel)
        path.parent.mkdir(parents=True,exist_ok=True)
        try:
            with path.open('x',encoding='utf-8') as stream: stream.write(text)
        except FileExistsError:
            pass


def snapshot_path(root,rel):
    from roc import native_recovery as recovery
    if not isinstance(rel,str) or '\\' in rel or ':' in rel or '..' in Path(rel).parts:
        raise ValueError('Invalid snapshot source path')
    path=(Path(root)/rel).resolve()
    tests=(Path(root)/recovery.NATIVE/'tests').resolve()
    if path.parent==tests and path.name.startswith('Native') and path.suffix=='.cpp':return path
    return recovery.native_path(root,rel)
