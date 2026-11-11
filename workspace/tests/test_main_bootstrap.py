import importlib.util
import io
import hashlib
import json
from pathlib import Path
from urllib.error import URLError
import zipfile

import pytest

spec=importlib.util.spec_from_file_location('main_bootstrap',Path(__file__).resolve().parents[1]/'packaging/main_bootstrap.py')
b=importlib.util.module_from_spec(spec)
spec.loader.exec_module(b)


def payload(extra=None):
    raw=io.BytesIO()
    with zipfile.ZipFile(raw,'w') as z:
        z.writestr('roc.py','print("Worker ready")')
        z.writestr('roconstruct-package.json',json.dumps(dict(authority=b.AUTHORITY)))
        if extra:z.writestr(*extra)
    body=raw.getvalue()
    manifest=dict(authority=b.AUTHORITY,workflow_version=52,url=b.MANIFEST.rsplit('/',1)[0]+'/native-worker.zip',sha256=hashlib.sha256(body).hexdigest())
    return manifest,body


def test_blank_main_download_reuse_and_offline_preserve_drafts(tmp_path,monkeypatch):
    manifest,raw=payload()
    monkeypatch.setattr(b,'urlopen',lambda url,timeout:io.BytesIO(raw if url.endswith('.zip') else json.dumps(manifest).encode()))
    root=b.prepare(tmp_path)
    (root/'roc.py').write_text('saved task edits')
    assert b.prepare(tmp_path)==root and (root/'roc.py').read_text()=='saved task edits'
    def offline(*args,**kwargs):raise URLError('offline')
    monkeypatch.setattr(b,'urlopen',offline)
    assert b.prepare(tmp_path)==root and (root/'roc.py').read_text()=='saved task edits'


@pytest.mark.parametrize('corrupt,escape',[(True,False),(False,True)])
def test_bad_download_never_writes_outside_new_workspace(tmp_path,monkeypatch,corrupt,escape):
    manifest,raw=payload(('../escape.txt','unsafe') if escape else None)
    monkeypatch.setattr(b,'urlopen',lambda url,timeout:io.BytesIO((raw+b'bad' if corrupt else raw) if url.endswith('.zip') else json.dumps(manifest).encode()))
    with pytest.raises(ValueError):b.prepare(tmp_path)
    assert not (tmp_path/'local/escape.txt').exists()
    assert not (tmp_path/'local/workers/selected.json').exists()
