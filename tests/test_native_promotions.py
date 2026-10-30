import json
from types import SimpleNamespace
import threading
import sqlite3

import pytest

from roc import integration, native_promotions as promotion


@pytest.fixture
def host(tmp_path):
    root = tmp_path
    folder = root/'rebuild/2008-06/manifests'
    folder.mkdir(parents=True)
    (folder/'functions.json').write_text(json.dumps([dict(addr='00500000', score=100)]))
    (folder/'abi-evidence.json').write_text(json.dumps({'RBX::Clothing': dict(alloc_sizes={'0x174': ['00500000']})}))
    db = sqlite3.connect(':memory:', check_same_thread=False)
    db.executescript(integration.SCHEMA)
    result = SimpleNamespace(root=root, directory=root/'work/integration',
        store=SimpleNamespace(lock=threading.RLock(), db=db), baseline=lambda: dict(revision='baseline'), wake=threading.Event())
    yield result
    db.close()


def packet():
    return dict(client='2008-06', base_revision='baseline', model='gpt-6.1-sol', targets=['00500000'],
        evidence='RTTI and constructor allocation evidence, source declaration recovered independently.',
        declarations=[dict(name='RBX::Clothing', size=0x174, header='App/include/Clothing.h', evidence='native RTTI/allocator')],
        patches={'App/include/Clothing.h': [['', 'namespace RBX { class Clothing {}; }']]})


def test_contributor_default_gate_stays_closed_while_owner_packet_is_quarantined(host):
    data = packet()
    with pytest.raises(ValueError, match='invented'):
        integration.validate_patches(data['patches'])
    with pytest.raises(ValueError, match='invented'):
        integration.validate_patches({'App/A.h': [['', 'class __declspec(novtable) Invented {};']]})
    result = promotion.receive(host, 'alice', data)
    assert result['state'] == 'needs-owner-review' and not result['verified']
    assert host.store.db.execute('SELECT COUNT(*) FROM integration_jobs').fetchone()[0] == 0


def test_owner_review_requires_exact_hash_and_queue_is_idempotent(host):
    identifier = promotion.receive(host, 'alice', packet())['id']
    with pytest.raises(ValueError, match='Review'):
        promotion.queue(host, identifier, 'not-reviewed')
    result = promotion.queue(host, identifier, identifier)
    assert result['state'] == 'queued' and not result['verified']
    assert promotion.queue(host, identifier, identifier)['id'] == result['id']
    assert host.wake.is_set()
    assert host.store.db.execute('SELECT COUNT(*) FROM integration_credit').fetchone()[0] == 0


def test_near_exact_source_draft_is_uploaded_without_queue_or_credit(host):
    data = packet()
    data.update(declarations=[], evidence='Local native score 98%; branch condition still differs.',
                patches={'App/Clothing.cpp': [['return 1;', 'return 2;']]})
    result = promotion.receive(host, 'alice', data)
    assert result['state'] == 'needs-owner-review'
    assert result['verified'] is False and result['credits'] == 0
    stored = host.store.db.execute('SELECT packet FROM integration_type_proposals WHERE id=?', (result['id'],)).fetchone()
    assert json.loads(stored[0]) == data
    assert host.store.db.execute('SELECT COUNT(*) FROM integration_jobs').fetchone()[0] == 0
    assert host.store.db.execute('SELECT COUNT(*) FROM integration_credit').fetchone()[0] == 0
    assert not host.wake.is_set()


def test_packet_rejects_unproven_abi_and_changed_baseline(host):
    data = packet()
    data['declarations'][0]['size'] = 400
    with pytest.raises(ValueError, match='allocation'):
        promotion.receive(host, 'alice', data)
    with pytest.raises(ValueError, match='baseline'):
        promotion.receive(host, 'alice', dict(packet(), base_revision='stale'))


def test_owner_packet_still_requires_all_layout_and_target_gates(host):
    identifier = promotion.receive(host, 'alice', packet())['id']
    job_id = promotion.queue(host, identifier, identifier)['id']
    job = dict(id=job_id, evidence='TYPE-PROMOTION:'+identifier)
    result = dict(size=dict(rows=[{'class':'Clothing','2008':0x174,'rbxgs':0x174}]),
                  report=dict(owned_addrs=['00500000']))
    promotion.check_result(host, job, result)
    result['size']['rows'][0]['rbxgs'] = 400
    with pytest.raises(ValueError, match='sizeof'):
        promotion.check_result(host, job, result)
    result['size']['rows'][0]['rbxgs'] = 0x174
    result['report']['owned_addrs'] = []
    with pytest.raises(ValueError, match='witness'):
        promotion.check_result(host, job, result)


def test_embedded_type_requires_matching_binary_sites_and_derivation(host, monkeypatch):
    from roc import match
    data = packet()
    data['declarations'][0].update(name='RBX::ContactManager', size=20,
        header='App/include/ContactManager.h', size_derivation='Constructor clears five pointers, next member begins at offset 20',
        binary_sites=[dict(address='00500000',bytes='aabbccddeeff0011')])
    data['patches'] = {'App/include/ContactManager.h': [['', 'namespace RBX { class ContactManager {}; }']]}
    monkeypatch.setattr(match, '_image', lambda client: (0x500000, bytes.fromhex('aabbccddeeff0011')))
    assert promotion.receive(host, 'alice', data)['state'] == 'needs-owner-review'
    data['declarations'][0]['binary_sites'][0]['bytes'] = '0011223344556677'
    with pytest.raises(ValueError, match='does not match'):
        promotion.receive(host, 'alice', data)


def test_promotions_stay_isolated_after_restart_and_report_final_state(host):
    identifier=promotion.receive(host,'alice',packet())['id']
    job_id=promotion.queue(host,identifier,identifier)['id']
    db=host.store.db
    db.execute("UPDATE integration_jobs SET phase='resuming' WHERE id=?",(job_id,))
    db.execute('INSERT INTO integration_jobs VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)',
        ('ordinary','[]','ordinary-digest','alice','gpt-6.1-sol','RBX::Other','baseline',
         json.dumps({'App/Other.cpp':[['a','b']]}),'ordinary evidence','queued','resuming',10**12,10**12,'{}'))
    db.commit()
    real=integration.Promotions(host.store,host.root)
    job=real.take()
    assert job['id']==job_id and 'members' not in job
    assert real.finish(job,dict(accepted=False,reason='probe failed'))
    assert db.execute('SELECT state FROM integration_type_proposals WHERE id=?',(identifier,)).fetchone()[0]=='rejected'
    assert promotion.queue(host,identifier,identifier)['retry']
