import hashlib
import io
import json
import subprocess
import zipfile

import pytest

from roc import findings_workspace as w
from roc.findings_transport import publish_files, publish


def git(root,*args):
    return subprocess.check_output(['git',*args],cwd=root).decode().strip()


def repos(tmp_path):
    root=tmp_path/'owner'
    root.mkdir()
    git(root,'init','-b','work')
    git(root,'config','user.name','Test')
    git(root,'config','user.email','test@example.invalid')
    for path,text in {'workspace/roc/native_drafts.py':'# uploader','workspace/docs/NATIVE_AGENT.md':'native prompt',
                      'workspace/docs/MATCHING_AGENT.md':'matching prompt','workspace/rebuild/2008-06/native-classes/Keep.cpp':'verified native'}.items():
        p=root/path;p.parent.mkdir(parents=True,exist_ok=True);p.write_text(text)
    (root/'.gitignore').write_text('local/\nwork/\n')
    git(root,'add','.')
    git(root,'commit','-m','initial')
    remote=tmp_path/'remote.git'
    git(tmp_path,'clone','--bare',str(root),str(remote))
    git(root,'remote','add','findings',str(remote))
    return root,remote


def test_committed_export_deterministic_and_remote_preserved(tmp_path):
    root,remote=repos(tmp_path)
    source=root/'workspace/rebuild/2008-06/native-classes/Keep.cpp'
    source.write_text('active worker unpublished dirty work')
    (root/'unrelated.txt').write_text('staged unrelated')
    git(root,'add','unrelated.txt')
    before=git(root,'status','--porcelain')
    revision,files=w.export(root,'work')
    _,again=w.export(root,'work')
    assert files==again
    assert 'workspace/rebuild/2008-06/native-classes/Keep.cpp' not in files
    manifest=json.loads(files['data/native-worker.json'])
    assert hashlib.sha256(files['data/native-worker.zip']).hexdigest()==manifest['sha256']
    with zipfile.ZipFile(io.BytesIO(files['data/native-worker.zip'])) as archive:
        assert archive.read('roc/native_drafts.py')==b'# uploader'
        assert json.loads(archive.read('roconstruct-package.json'))['revision']==revision
    publish_files(root,{'drafts/bundles/keep.json':b'{}','other/keep.txt':b'existing'},'other namespace')
    result=publish_files(root,files,'workspace')
    assert result['changed']
    assert git(remote,'show','work:other/keep.txt')=='existing'
    assert git(remote,'show','work:drafts/bundles/keep.json')=='{}'
    assert git(root,'status','--porcelain')==before
    assert not publish_files(root,files,'unchanged')['changed']
    assert source.read_text()=='active worker unpublished dirty work'


def test_full_legacy_publisher_keeps_draft_namespace(tmp_path,monkeypatch):
    root,remote=repos(tmp_path)
    publish_files(root,{'drafts/bundles/keep.json':b'{}','workspace/keep.cpp':b'keep'},'draft')
    p=root/'src/2008-06/a.cpp';p.parent.mkdir(parents=True);p.write_text('int f(){return 1;}')
    from roc import libs
    monkeypatch.setattr(libs,'generated_units',lambda:{})
    import shutil
    publish(root,shutil.which('git'))
    assert git(remote,'show','work:drafts/bundles/keep.json')=='{}'
    assert git(remote,'show','work:workspace/keep.cpp')=='keep'


def test_stale_source_export_refused(tmp_path):
    root,remote=repos(tmp_path)
    base=git(root,'rev-parse','HEAD')
    w.publish(root,'work')
    current=git(remote,'rev-parse','work')
    w.integrate(root,current,{'docs/NATIVE_AGENT.md':b'new prompt'},'new canonical prompt')
    w.publish(root)
    with pytest.raises(ValueError,match='advanced'):
        w.publish(root,base)


def test_findings_is_authoritative_and_native_integrations_preserve_local_work(tmp_path):
    root,remote=repos(tmp_path)
    base=git(remote,'rev-parse','work')
    local=root/'workspace/rebuild/2008-06/native-classes/Keep.cpp'
    local.write_text('active worker dirty source')
    (root/'staged.txt').write_text('unrelated staged work');git(root,'add','staged.txt')
    head=git(root,'rev-parse','HEAD');index=git(root,'ls-files','--stage')
    path='rebuild/2008-06/native-classes/Keep.cpp'
    accepted=w.integrate(root,base,{path:b'new reviewed native source'},'Reviewed native update')
    assert git(remote,'show','work:workspace/'+path)=='new reviewed native source'
    assert git(root,'rev-parse','HEAD')==head
    assert git(root,'ls-files','--stage')==index
    assert local.read_text()=='active worker dirty source'
    w.publish(root)
    raw=subprocess.check_output(['git','show','work:data/native-worker.zip'],cwd=remote)
    with zipfile.ZipFile(io.BytesIO(raw)) as archive:
        assert archive.read(path)==b'new reviewed native source'
    # Canonical source is retained even though local HEAD still contains the old implementation.
    assert git(remote,'show','work:workspace/'+path)=='new reviewed native source'
    with pytest.raises(ValueError,match='advanced'):
        w.integrate(root,base,{path:b'stale replacement'},'stale')
    current=git(remote,'rev-parse','work')
    with pytest.raises(ValueError,match='loses native'):
        w.integrate(root,current,{path:b''},'empty snapshot')
    assert git(remote,'rev-parse','work')==current
