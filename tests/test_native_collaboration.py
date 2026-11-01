import json
import sqlite3
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import integration,native_collaboration as client,native_collaboration_host as host,native_recovery as recovery,server

REL='rebuild/2008-06/native-classes/A.cpp'
BEFORE='int A::f(){return 1;}\nint A::g(){return 2;}\n'
AFTER=BEFORE.replace('return 1;','return 3;')


@pytest.fixture
def service(tmp_path,monkeypatch):
    root=tmp_path/'host';p=root/REL;p.parent.mkdir(parents=True);p.write_text(BEFORE)
    headers=root/'rebuild/2008-06/native-headers';headers.mkdir();(headers/'A.h').write_text('struct A{int f();int g();};')
    store=SimpleNamespace(db=sqlite3.connect(tmp_path/'db',check_same_thread=False),lock=threading.Lock())
    promotions=SimpleNamespace(root=root,store=store)
    monkeypatch.setattr(recovery,'nominations',lambda *a:[dict(file=REL,method='A::f',addr='00400000')])
    result=host.Host(promotions)
    yield result
    result.stop.set();result.wake.set();store.db.close()


def claim(service,user='Colin',worker='pc1'):
    task=service.catalog()['tasks'][0]
    return service.claim(user,dict(target=task['target'],signature=task['signature'],worker=worker))


def body(lease,**extra):return dict(lease=lease['lease'],worker=lease['worker'],**extra)


def test_ten_pcs_claim_one_method_only_once(service):
    with ThreadPoolExecutor(max_workers=10) as pool:
        replies=list(pool.map(lambda n:claim(service,worker='pc'+str(n)),range(10)))
    assert sum(r['claimed'] for r in replies)==1
    assert not service.catalog()['tasks'][0]['available']


def test_ten_distinct_methods_cross_pc_no_duplicates(service,monkeypatch):
    p=service.root/REL;p.write_text('\n'.join('int A::f%d(){return %d;}'%(n,n) for n in range(10)))
    monkeypatch.setattr(recovery,'nominations',lambda *a:[dict(file=REL,method='A::f%d'%n,addr='%08x'%(0x400000+n)) for n in range(10)])
    tasks=service.catalog()['tasks']
    def take(pair):
        n,t=pair;return service.claim('Colin',dict(target=t['target'],signature=t['signature'],worker='pc'+str(n%2)))
    with ThreadPoolExecutor(max_workers=10) as pool:replies=list(pool.map(take,enumerate(tasks)))
    assert len({r['lease'] for r in replies})==10 and all(r['claimed'] for r in replies)


def test_expired_lease_replaced_and_old_worker_fenced(service):
    old=claim(service)
    with service.store.lock,service.store.db as db:db.execute('UPDATE native_method_leases SET expires=0')
    fresh=claim(service,worker='pc2');assert fresh['claimed'] and fresh['lease']!=old['lease']
    for operation in (lambda:service.renew('Colin',body(old)),lambda:service.submit('Colin',body(old,model='terra',candidate=AFTER))):
        with pytest.raises(ValueError,match='expired'):operation()
    with pytest.raises(ValueError):service.renew('Someone',body(fresh))
    assert service.renew('Colin',body(fresh))['renewed']
    assert service.renew('Colin',body(fresh),release=True)['released']
    assert claim(service)['claimed']


def test_changed_catalog_rejects_stale_assignment(service):
    task=service.catalog()['tasks'][0]
    (service.root/'rebuild/2008-06/native-headers/A.h').write_text('struct A{int f();int g();int other();};')
    with pytest.raises(ValueError,match='changed target'):
        service.claim('Colin',dict(target=task['target'],signature=task['signature'],worker='pc'))


def test_upload_idempotent_private_lease_and_body_only_inbox(service):
    lease=claim(service)
    with pytest.raises(ValueError):service.submit('Colin',body(lease,model='terra',candidate=AFTER+'int A::other(){return 4;}'))
    response=service.submit('Colin',body(lease,model='terra',candidate=AFTER))
    assert response['state']=='queued' and response['exact_credits']==0
    assert service.submit('Colin',body(lease,model='terra',candidate=AFTER))['job']==response['job']
    with pytest.raises(ValueError):service.submit('Colin',dict(body(lease,model='terra',candidate=AFTER),worker='wrongpc'))
    assert not claim(service,worker='pc2')['claimed']
    event=json.loads((service.root/'work/agent-inbox/events.jsonl').read_text().splitlines()[-1])
    assert event['verified'] is False and event['kind']=='native-recovery-upload'
    assert (service.root/'work/agent-inbox'/event['source']).read_text()==AFTER


def test_host_failure_retains_source_and_restart_resumes_queue(service,monkeypatch):
    lease=claim(service);response=service.submit('Colin',body(lease,model='terra',candidate=AFTER))
    job=service.take();assert service.status(response['job'])['state']=='verifying'
    resumed=host.Host(service.promotions)
    again=resumed.take();assert again[0]==job[0]
    monkeypatch.setattr(resumed,'verify',lambda *a:(_ for _ in ()).throw(ValueError('wrong imported callee')))
    result=resumed.process(again)
    assert result['receipt']['state']=='retained' and (service.root/REL).read_text()==BEFORE
    assert claim(service,worker='pc2')['claimed']


def test_host_independent_merge_preserves_other_method_and_ignores_client_proof(service,monkeypatch):
    from roc import native_sweep as sweep,worker,match,native_refs
    lease=claim(service);response=service.submit('Colin',body(lease,model='terra',candidate=AFTER,proof={'ok':True}))
    p=service.root/REL;p.write_text(BEFORE.replace('return 2;','return 77;'))
    class Api:
        server='http://localhost:8765'
        def __init__(self,*a):pass
        def close(self):pass
    monkeypatch.setattr(worker,'Api',Api)
    monkeypatch.setattr(sweep,'native_context',lambda *a:SimpleNamespace())
    monkeypatch.setattr(sweep,'Matcher',lambda *a:None)
    monkeypatch.setattr(match,'_functions',lambda *a:{})
    monkeypatch.setattr(native_refs,'import_checks',lambda *a:[])
    service.promotions.baseline=lambda:{'revision':'base'}
    def compile(root,rel,*a,**kw):
        text=(root/rel).read_text();obj=root/'proof.obj';obj.write_bytes(b'host object')
        return dict(ok=True,error='',target_exact='return 3;' in text,losses=[],hits=[],object=str(obj),symbol='?f@A@@QAEHXZ')
    monkeypatch.setattr(recovery,'compile_probe',compile)
    monkeypatch.setattr(recovery,'stage_submission',lambda *a,**kw:dict(state='pending-mapping'))
    result=service.process(service.take());assert result['receipt']['state']=='merged'
    assert p.read_text()==AFTER.replace('return 2;','return 77;')
    assert not service.catalog()['tasks'][0]['available']
    assert service.status(response['job'])['exact_credits']==0


def test_snapshot_new_files_preserves_local_edits_and_rejects_escape(tmp_path):
    p=tmp_path/REL;p.parent.mkdir(parents=True);p.write_text('local editor')
    header='rebuild/2008-06/native-headers/New.h'
    client.seed_missing(tmp_path,{REL:'host source',header:'struct New{};'})
    assert p.read_text()=='local editor' and (tmp_path/header).exists()
    for rel in ('../outside.cpp','AGENTS.md','rebuild/2008-06/native-classes/../../../../outside.cpp'):
        with pytest.raises(ValueError):client.seed_missing(tmp_path,{rel:'escape'})


def test_recovery_webhook_reports_only_host_merges_zero_credit(service,monkeypatch):
    from roc import integration_notify,reports
    calls=[]
    monkeypatch.setattr(integration_notify,'server_mines_webhook',lambda:'https://example.invalid/webhook')
    monkeypatch.setattr(reports,'_post',lambda url,payload:calls.append(payload))
    record=dict(user='Colin',model='terra',task=dict(addr='00400000',method='A::f'))
    row=dict(job='job',record=record,receipt=dict(state='already-exact'))
    service.notify([row]);assert not calls
    row['receipt']=dict(state='merged',merge=dict(state='merged'))
    service.notify([row]);assert len(calls)==1 and '0 integration credits' in calls[0]['embeds'][0]['description']


def test_http_two_pcs_share_real_server_lease_routes(service):
    service.promotions.recovery=service
    handler=server.make_handler(service.store,None,{},integration=service.promotions)
    http=ThreadingHTTPServer(('127.0.0.1',0),handler)
    thread=threading.Thread(target=http.serve_forever,daemon=True);thread.start()
    a=client.Remote('http://127.0.0.1:'+str(http.server_port),'Colin',identity='pc1')
    b=client.Remote(a.api.server,'Colin',identity='pc2')
    try:
        task=a.call('catalog')['tasks'][0];lease=a.claim(task)
        assert lease['claimed'] and not b.claim(task)['claimed']
        assert a.renew(lease)['renewed']
        job=a.submit(lease,dict(model='terra',candidate=service.root/REL),check_only=True)
        assert a.status(job['job'])['state']=='queued'
    finally:a.close();b.close();http.shutdown();http.server_close();thread.join()


def test_controller_two_pcs_host_recheck_and_restart_without_extra_ai(service,tmp_path,monkeypatch):
    from roc import native_sweep as sweep,gui_worker,match,native_refs
    service.promotions.recovery=service
    service.promotions.baseline=lambda:dict(revision='base',features=dict(native_recovery_collaboration=1))
    service.promotions.status=lambda *a:dict(jobs=[])
    context=SimpleNamespace(names={},by_addr={},includes=[])
    monkeypatch.setattr(sweep,'model_evidence',lambda *a:dict(target_asm=['fixture assembly']))
    monkeypatch.setattr(sweep,'native_context',lambda *a:context)
    monkeypatch.setattr(sweep,'Matcher',lambda *a:None)
    monkeypatch.setattr(match,'_functions',lambda *a:{})
    monkeypatch.setattr(native_refs,'import_checks',lambda *a:[])
    monkeypatch.setattr(recovery,'stage_submission',lambda *a,**kw:dict(state='pending-mapping'))
    def target(data,*a):return dict(target_exact=b'return 3;' in data,symbol='?f@A@@QAEHXZ',diff='fixture diff')
    monkeypatch.setattr(recovery,'target_proof',target)
    def compile(root,rel,*a,**kw):
        text=(root/rel).read_text();obj=root/'proof.obj';obj.write_text(text)
        return dict(ok=True,error='',target_exact='return 3;' in text,losses=[],hits=[],object=str(obj),symbol='?f@A@@QAEHXZ')
    monkeypatch.setattr(recovery,'compile_probe',compile)
    calls=[]
    def codex(folder,*a):
        task=json.loads((folder/'task.json').read_text());p=folder/task['file'];p.write_text(p.read_text().replace('return 1;','return 3;'));calls.append(task['method'])
        return dict(input_tokens=10,output_tokens=2,cancelled=False,usage_reported=True)
    monkeypatch.setattr(recovery,'run_codex',codex)
    handler=server.make_handler(service.store,None,{},integration=service.promotions)
    http=ThreadingHTTPServer(('127.0.0.1',0),handler);thread=threading.Thread(target=http.serve_forever,daemon=True);thread.start()
    url='http://127.0.0.1:'+str(http.server_port)
    config=dict(gui_worker.DEFAULTS,workers=1,model='codex:gpt-6.1-terra',user='Colin',server=url,cloud_allowed=True,max_cloud_requests=1)
    def run(pc):
        shared=tmp_path/pc;p=shared/REL;p.parent.mkdir(parents=True,exist_ok=True)
        if not p.exists():p.write_text(BEFORE.replace('return 2;','return 77;'))
        monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT',str(shared));monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT',str(tmp_path/(pc+'-proofs')))
        control=gui_worker.Control(config,lambda *a,**kw:None)
        return recovery.run(config,control,lambda *a,**kw:None)
    try:
        first=run('pc1');assert first['recovered']==1 and first['merged']==1 and first['remote_submitted']==1
        second=run('pc2');assert second['attempted']==0 and calls==['A::f']
        assert 'return 77;' in (tmp_path/'pc1'/REL).read_text()
        result=service.process(service.take());assert result['receipt']['state']=='merged'
        assert (service.root/REL).read_text()==AFTER
        resumed=run('pc1');assert resumed['host_merged']==1 and calls==['A::f']
    finally:http.shutdown();http.server_close();thread.join()


def test_public_inline_header_body_only_fields_and_signature_protected():
    before='class A{int secret(){return 0;} public: int f() const {return value;} int value;};'
    after=before.replace('return value;','return value+1;')
    assert recovery.method_change(before,after,'A::f')
    with pytest.raises(ValueError):recovery.method_change(before,after.replace('int value;','int padding;'),'A::f')
    with pytest.raises(ValueError):recovery.method_change(before,after.replace('f() const','f()'),'A::f')
    with pytest.raises(ValueError):recovery.method_change(before,before.replace('return 0;','return 1;'),'A::secret')


def test_generated_header_consumer_emits_real_inline_method(service,monkeypatch,tmp_path):
    from roc import match,setup,native_sweep as sweep
    if 21022 not in setup.compilers():pytest.skip('Historical MSVC not installed')
    header='rebuild/2008-06/native-headers/A.h'
    (service.root/header).write_text('class A { public: int f(){return 17;} };')
    names=service.root/'rebuild/2008-06/out/native-names.json';names.parent.mkdir(parents=True);names.write_text(json.dumps({'00400000':{'symbol':'?f@A@@QAEHXZ'}}))
    monkeypatch.setattr(recovery,'nominations',lambda *a:[dict(file=header,method='A::f',addr='00400000')])
    catalog=service.catalog();task=catalog['tasks'][0]
    assert task['translation_unit'].split('/')[-1].startswith('NativeRecovery')
    folder=tmp_path/'probe'
    client.seed_missing(folder,catalog['files'])
    ctx=SimpleNamespace(defines='',flags=sweep.FLAGS)
    class Matcher:
        def scan(self,obj):return []
    result=recovery.compile_probe(folder,header,ctx,Matcher(),set(),'A::f',translation_unit=task['translation_unit'])
    assert result['ok'],result['error']
    assert any(symbol.startswith('?f@A@@') for symbol,_,_ in match.coff_functions(Path(result['object']).read_bytes()))
