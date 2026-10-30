import hashlib
import io
import json
from pathlib import Path

import pytest

from roc import analyze, clients, libs, rebuild, rebuild_install, setup


def test_partial_worker_install_fetches_missing_binary_abi_evidence(tmp_path, monkeypatch):
    module = tmp_path / 'rebuild/2008-06/modules/rbxgs-app.json'
    module.parent.mkdir(parents=True)
    module.write_text('{"keep":"local recipe"}')
    content = json.dumps({'RBX::Fixture': {'confidence': 'observed', 'vtables': ['00800000']}}).encode()
    manifest = {'files': {'verification/manifests/abi-evidence.json': hashlib.sha256(content).hexdigest()}}
    monkeypatch.setattr(rebuild_install.urllib.request, 'urlopen', lambda url, **kw:
        io.BytesIO(json.dumps(manifest).encode() if url.endswith('/package.json') else content))
    rebuild_install.install(tmp_path)
    assert module.read_text() == '{"keep":"local recipe"}'
    assert (module.parents[1] / 'manifests/abi-evidence.json').read_bytes() == content


def test_missing_abi_hash_mismatch_installs_nothing(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild_install.urllib.request, 'urlopen', lambda url, **kw: io.BytesIO(
        json.dumps({'files': {'verification/manifests/abi-evidence.json': '0'*64}}).encode()
        if url.endswith('/package.json') else b'{}'))
    with pytest.raises(ValueError, match='hash mismatch'):
        rebuild_install.ensure_abi(tmp_path)
    assert not (tmp_path / 'rebuild/2008-06/manifests/abi-evidence.json').exists()


def test_existing_expected_abi_is_not_replaced_with_candidate_data(tmp_path, monkeypatch):
    path = tmp_path / 'rebuild/2008-06/manifests/abi-evidence.json'
    path.parent.mkdir(parents=True)
    content = b'{"Fixture":{"confidence":"candidate","vtables":[]}}'
    path.write_bytes(content)
    monkeypatch.setattr(rebuild_install.urllib.request, 'urlopen', lambda *a, **k: pytest.fail('Do not replace expected data'))
    with pytest.raises(ValueError, match='original-binary ABI evidence'):
        rebuild_install.ensure_abi(tmp_path)
    assert path.read_bytes() == content


def test_cold_prepare_generates_rtti_and_builds_dependencies_with_declared_profiles(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild_install, 'install', lambda *a: None)
    monkeypatch.setattr(clients, 'load', lambda: {'2008-06': {}})
    monkeypatch.setattr(clients, 'status', lambda *a: 'ok')
    monkeypatch.setattr(clients, 'exe_path', lambda *a: tmp_path / 'verified-original.exe')
    work = tmp_path / 'work/2008-06'
    def analysis(*args):
        work.mkdir(parents=True)
        (work / 'functions.jsonl').write_text('{}\n')
    def rtti(*args, **kw):
        (work / 'vtables.json').write_text('[{"class":"RBX::Fixture"}]')
    monkeypatch.setattr(analyze, 'analyze', analysis)
    monkeypatch.setattr(analyze, 'vtable_report', rtti)
    installed, requested = {21022: 'cl.exe'}, []
    monkeypatch.setattr(setup, 'compilers', lambda: installed)
    def install_profiles(only, assume_yes):
        requested.extend(only)
        installed.update({n: 'cl.exe' for n in only})
    monkeypatch.setattr(setup, 'install_compilers', install_profiles)
    monkeypatch.setattr(libs, 'winsdk_include', lambda: 'SDK')
    monkeypatch.setattr(rebuild, 'toolchain', lambda *a: {k: 'installed' for k in
        ('cl', 'link', 'lib', 'vc_include', 'sdk_include', 'sdk_lib', 'atlmfc_include')})
    specs = {'rbxgs-app': dict(name='RbxgsApp', depends=['g3d'], layers=[{'name':'core', 'cl':21022}]),
             'g3d': dict(name='G3D', depends=['zlib'], layers=[{'name':'core', 'cl':21022}], test='g3d-smoke'),
             'zlib': dict(name='Zlib', layers=[{'name':'core', 'cl':50727}])}
    monkeypatch.setattr(rebuild, 'load_module', lambda client, name: specs[name])
    built = []
    def build(client, name):
        assert 50727 in installed and (work / 'vtables.json').exists()
        built.append(name)
        out = tmp_path / 'rebuild/2008-06/out' / specs[name]['name']
        (out / 'linked').mkdir(parents=True)
        (out / 'linked/linked.lib').write_bytes(b'library')
        (out / 'report.json').write_text('{"linked": true, "test_exit": 0}')
        (out / 'layer-core').mkdir()
        (out / 'layer-core/errors.json').write_text('{}')
        return {'linked':True, 'test_exit':0}
    monkeypatch.setattr(rebuild, 'build_module', build)
    rebuild_install.prepare(log=lambda *a: None)
    assert requested == [50727] and built == ['zlib', 'g3d']
    assert not (tmp_path / 'rebuild/2008-06/out/RbxgsApp').exists()
