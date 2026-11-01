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
    patches=root/'rebuild/2008-06/patches';patches.mkdir()
    (patches/'make_rbxgs_client.py').write_text('# trusted fixture')
    (patches/'rbxgs-client.json').write_text('{}')
    promotions=integration.Promotions(store,root)
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


@pytest.mark.parametrize('cold_resume',[False,True])
@pytest.mark.parametrize('canonical_wait',[False,True])
def test_controller_two_pcs_host_recheck_and_restart_without_extra_ai(service,tmp_path,monkeypatch,cold_resume,canonical_wait):
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
    batches=[]
    if canonical_wait:
        monkeypatch.setattr(recovery,'stage_submission',lambda *a,**kw:dict(state='mapped',proposals='saved.json'))
        def submit(*a,**kw):
            batches.append(1)
            return dict(state='blocked',reason='Class held on another PC') if len(batches)==1 else dict(job='queued',submitted_addresses=['00400000'])
        monkeypatch.setattr(recovery,'submit_batch',submit)
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
    controls={}
    folders={}
    if cold_resume:
        original_submit=client.Remote.submit
        disconnected=[]
        def submit_once_offline(self,*args,**kwargs):
            if not disconnected:
                disconnected.append(True)
                raise OSError('Connection dropped before candidate upload')
            return original_submit(self,*args,**kwargs)
        monkeypatch.setattr(client.Remote,'submit',submit_once_offline)
    def run(pc):
        shared=tmp_path/pc;p=shared/REL;p.parent.mkdir(parents=True,exist_ok=True)
        if not p.exists():p.write_text(BEFORE.replace('return 2;','return 77;'))
        monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT',str(shared));monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT',str(tmp_path/folders.get(pc,pc+'-proofs')))
        control=controls.setdefault(pc,gui_worker.Control(config,lambda *a,**kw:None))
        return recovery.run(config,control,lambda *a,**kw:None)
    try:
        first=run('pc1');assert first['recovered']==1 and first['merged']==0
        if cold_resume:
            assert first['remote_submitted']==0 and first['pending']==1
            with service.store.lock,service.store.db as db:db.execute('UPDATE native_method_leases SET expires=0')
            folders['pc1']='pc1-cold-proof'
            first=run('pc1')
        assert first['remote_submitted']==1 and first['remote_pending']==1
        second=run('pc2');assert second['attempted']==0 and calls==['A::f']
        assert 'return 77;' in (tmp_path/'pc1'/REL).read_text()
        result=service.process(service.take());assert result['receipt']['state']=='merged'
        assert (service.root/REL).read_text()==AFTER
        resumed=run('pc1');assert resumed['host_merged']==1 and resumed['merged']==1 and resumed['remote_pending']==int(canonical_wait) and controls['pc1'].budget.requests==1 and calls==['A::f']
        if canonical_wait:
            retried=run('pc1');assert retried['host_merged']==0 and retried['submitted']==1 and retried['remote_pending']==0 and retried['integration_pending']==1
            assert len(batches)==2 and controls['pc1'].budget.requests==1 and calls==['A::f']
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


def test_upload_retry_after_replaced_completed_lease_returns_original_job(service):
    lease=claim(service);response=service.submit('Colin',body(lease,model='terra',candidate=AFTER))
    with service.store.lock,service.store.db as db:
        db.execute("UPDATE native_method_leases SET state='complete'")
    newer=claim(service,worker='pc2');assert newer['lease']!=lease['lease']
    retried=service.submit('Colin',body(lease,model='terra',candidate=AFTER))
    assert retried['job']==response['job']
    with pytest.raises(ValueError):service.renew('Colin',body(lease))
    assert service.renew('Colin',body(newer))['renewed']


def test_catalog_retries_only_observed_source_races(service,monkeypatch):
    calls=[]
    def snapshot():
        calls.append(1)
        if len(calls)==1:raise ValueError('Native inputs changed while publishing; refresh catalog')
        return {'revision':'fresh'}
    monkeypatch.setattr(service,'_catalog',snapshot)
    assert service.catalog()=={'revision':'fresh'} and len(calls)==2


def test_world_header_change_invalidates_recovery_signature(service):
    header=service.root/'rebuild/2008-06/native-world/App/include/World.h';header.parent.mkdir(parents=True);header.write_text('struct World { int value; };')
    task=service.catalog()['tasks'][0]
    header.write_text('struct World { int value; int next; };')
    assert service.catalog()['tasks'][0]['signature']!=task['signature']


def test_cross_pc_contributor_limit_waits_and_recovers_without_blocking_other_users(service,monkeypatch):
    (service.root/REL).write_text('\n'.join('int A::f%d(){return %d;}'%(n,n) for n in range(51)))
    monkeypatch.setattr(recovery,'nominations',lambda *a:[dict(file=REL,method='A::f%d'%n,addr='%08x'%(0x400000+n)) for n in range(51)])
    tasks=service.catalog()['tasks']
    def take(pair):
        n,t=pair
        return service.claim('Colin',dict(target=t['target'],signature=t['signature'],worker='pc'+str(n%2)))
    with ThreadPoolExecutor(max_workers=10) as pool:leases=list(pool.map(take,enumerate(tasks[:50])))
    assert len({r['lease'] for r in leases})==50
    t=tasks[50];request=dict(target=t['target'],signature=t['signature'],worker='pc3')
    assert service.claim('Colin',request)==dict(claimed=False,reason='contributor-limit')
    assert service.claim('Someone',request)['claimed']
    service.renew('Colin',body(leases[0]),release=True)
    assert take((52,tasks[0]))['claimed']


def test_recovery_maps_generated_accepted_methods_and_refreshes_changed_overlay(service):
    registry=service.promotions.overlay
    integration.atomic_json(registry,{'App/util/Generated.cpp':[['','int A::f(){return 1;}']]})
    task=service.catalog()['tasks'][0]
    assert task['integration_mapping']=='App/util/Generated.cpp'
    integration.atomic_json(registry,{'App/util/New.cpp':[['','int A::f(){return 1;}']]})
    assert service.catalog()['tasks'][0]['integration_mapping']=='App/util/New.cpp'


def test_recovery_prioritizes_unintegrated_work_without_changing_source_leases(service,monkeypatch):
    tree=service.root/'tools/rbxgs/Client/App/util';tree.mkdir(parents=True)
    (tree/'A.cpp').write_text(BEFORE)
    monkeypatch.setattr(recovery,'nominations',lambda *a:[dict(file=REL,method='A::f',addr='00400000'),dict(file=REL,method='A::g',addr='00400001')])
    before=service.catalog()['tasks'];signature=before[0]['signature']
    integration.atomic_json(service.promotions.directory/'progress-native.json',dict(addresses=['00400000']))
    tasks=service.catalog()['tasks']
    assert [t['addr'] for t in tasks]==['00400001','00400000']
    assert tasks[1]['integration_state']=='integrated' and tasks[1]['signature']==signature
    assert all(t['available'] for t in tasks)


def test_project_probe_headers_fence_tasks_without_replacing_canonical_sources(service):
    path=service.promotions.overlay
    integration.atomic_json(path,{'App/include/Stage.h':[['','struct GenuineStage {};']]})
    first=service.catalog();task=first['tasks'][0]
    assert first['probe_headers']=={'Stage.h':'struct GenuineStage {};'}
    integration.atomic_json(path,{'App/include/Stage.h':[['','struct RevisedStage {};']]})
    second=service.catalog()
    assert first['probe_revision']!=second['probe_revision']
    assert first['revision']==second['revision']
    assert task['signature']!=second['tasks'][0]['signature']


def test_probe_context_is_immutable_versioned_and_cannot_escape(tmp_path):
    headers={'v8world/Mechanism.h':'struct SimJob {};'}
    payload=dict(probe_headers=headers,probe_revision=integration.digest(headers))
    first=client.materialize_probe_headers(payload,tmp_path)
    assert (first/'v8world/Mechanism.h').read_text()=='struct SimJob {};'
    assert client.materialize_probe_headers(payload,tmp_path)==first
    newer={'v8world/Mechanism.h':'struct NewJob {};'}
    second=client.materialize_probe_headers(dict(probe_headers=newer,probe_revision=integration.digest(newer)),tmp_path)
    assert second!=first and (first/'v8world/Mechanism.h').read_text()=='struct SimJob {};'
    (first/'v8world/Mechanism.h').write_text('modified')
    with pytest.raises(ValueError,match='modified'):client.materialize_probe_headers(payload,tmp_path)
    for name in ('../escape.h','C:/escape.h','bad.py','a\\b.h'):
        bad={name:'contents'}
        with pytest.raises(ValueError):client.materialize_probe_headers(dict(probe_headers=bad,probe_revision=integration.digest(bad)),tmp_path)
