import json
from pathlib import Path

import pytest

from roc import integration, integration_audit, integration_verify


def result(addresses):
    return dict(report=dict(linked=True, test_exit=0, owned_addrs=addresses),
                milestones={name:dict(exit=0,passed=True) for name in ('M2','M4a','M5')},
                base=dict(mismatch=[],checked=0),size=dict(rows=[]),distinct=len(addresses))


def prepare(tmp_path,monkeypatch):
    for name in ('roc','tools','clients'):
        (tmp_path/name).mkdir()
    (tmp_path/'roc.py').write_text('# current entrypoint')
    integration.atomic_json(tmp_path/'rebuild/2008-06/patches/rbxgs-client.json',{})
    integration.atomic_json(tmp_path/'integration-result.json',result(['00401000']))
    monkeypatch.setattr(integration_verify,'snapshot',lambda source,folder,link:folder.mkdir(parents=True))
    monkeypatch.setattr(integration_verify,'input_hash',lambda *a,**k:'same')
    monkeypatch.setattr(integration_verify,'other_module_owned',lambda *a:set())
    return dict(overlay={},revision='accepted')


def test_audit_failure_preserves_completed_build_and_lost_ownership(tmp_path,monkeypatch):
    base=prepare(tmp_path,monkeypatch)
    monkeypatch.setattr(integration_verify,'verify_build',lambda *a:result([]))
    with pytest.raises(ValueError,match='ownership'):
        integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None)
    receipt=json.loads(next((tmp_path/'work/integration-audit').glob('*/audit-receipt.json')).read_text())
    assert receipt['ownership']['uncovered']==['00401000']
    assert not receipt['passed'] and not receipt['grants_credit']
    assert (Path(receipt['snapshot'])/'audit-result.json').exists()


def test_audit_success_never_grants_credit(tmp_path,monkeypatch):
    base=prepare(tmp_path,monkeypatch)
    monkeypatch.setattr(integration_verify,'verify_build',lambda *a:result(['00401000']))
    receipt=integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None)
    assert receipt['passed'] and receipt['unchanged_owned']==['00401000']
    assert not receipt['accepted'] and not receipt['grants_credit'] and not receipt['source_changes']


def test_audit_copies_current_profiles_and_tests_but_freezes_accepted_overlays(tmp_path,monkeypatch):
    base=prepare(tmp_path,monkeypatch)
    integration.atomic_json(tmp_path/'rebuild/2008-06/modules/rbxgs-app.json',dict(force_verified=True))
    test=tmp_path/'rebuild/2008-06/tests/rbxgs_app.cpp'
    test.parent.mkdir();test.write_text('#include "force_verified.h"')
    def verify(folder,log):
        assert json.loads((folder/'rebuild/2008-06/modules/rbxgs-app.json').read_text())['force_verified']
        assert (folder/'rebuild/2008-06/tests/rbxgs_app.cpp').read_text()==test.read_text()
        assert not (folder/'rebuild/2008-06/patches/rbxgs-client.json').exists()
        return result(['00401000'])
    monkeypatch.setattr(integration_verify,'verify_build',verify)
    assert integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None)['passed']


def credit_database(root,addresses):
    import sqlite3
    (root/'work').mkdir(exist_ok=True)
    with sqlite3.connect(root/'work/server.db') as db:
        db.execute('CREATE TABLE integration_credit(client TEXT,addr TEXT)')
        db.executemany('INSERT INTO integration_credit VALUES (?,?)',[('2008-06',a) for a in addresses])


def test_current_profile_reports_legacy_loss_but_requires_every_accepted_body(tmp_path,monkeypatch):
    base=prepare(tmp_path,monkeypatch)
    credit_database(tmp_path,['00401000'])
    after=result([]);after['report']['module']='RbxgsApp'
    monkeypatch.setattr(integration_verify,'verify_build',lambda *a:after)
    with pytest.raises(ValueError,match='Accepted native bodies missing'):
        integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None,current_profile=True)


def test_current_profile_inventory_correction_is_explicit_and_preserves_abi(tmp_path,monkeypatch):
    base=prepare(tmp_path,monkeypatch)
    credit_database(tmp_path,[])
    after=result([]);after['report']['module']='RbxgsApp'
    monkeypatch.setattr(integration_verify,'verify_build',lambda *a:after)
    receipt=integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None,current_profile=True)
    assert receipt['mode']=='current-profile' and receipt['passed']
    assert not receipt['legacy_inventory_reproduced'] and not receipt['grants_credit']
    assert receipt['ownership']['uncovered']==['00401000']
    monkeypatch.setattr(integration_verify,'check_abi',lambda *a:(_ for _ in ()).throw(ValueError('ABI regressed')))
    with pytest.raises(ValueError,match='ABI regressed'):
        integration_audit.audit(tmp_path,base,tmp_path,log=lambda *a:None,current_profile=True)
