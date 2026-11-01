import json
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from types import SimpleNamespace
import subprocess
import sys
import threading
import time

import pytest

from roc import gui_worker, native_recovery as recovery

REL = 'rebuild/2008-06/native-classes/A.cpp'
BEFORE = 'int A::f(){return 1;}\nint A::g(){return 2;}\n'
AFTER = BEFORE.replace('return 1;', 'return 3;')


def source(root, text=BEFORE):
    path = root/REL
    path.parent.mkdir(parents=True,exist_ok=True)
    path.write_bytes(text.encode())
    return path


def good(root, rel):
    return dict(ok=True,target_exact=True,losses=[],hits=[])


def test_different_agent_method_preserved_and_receipt_backup_written(tmp_path):
    shared=tmp_path/'shared'; path=source(shared,BEFORE.replace('return 2;','return 44;'))
    result=recovery.merge(shared,tmp_path/'proof',REL,BEFORE,AFTER,'A::f',good,tmp_path/'receipt.json')
    assert result['state']=='merged'
    assert path.read_text() == AFTER.replace('return 2;','return 44;')
    assert (tmp_path/'receipt.before.cpp').read_text()==BEFORE.replace('return 2;','return 44;')


def test_same_method_conflict_never_overwrites(tmp_path):
    shared=tmp_path/'shared';path=source(shared,BEFORE.replace('return 1;','return 99;'))
    with pytest.raises(ValueError,match='Conflict'):
        recovery.merge(shared,tmp_path/'proof',REL,BEFORE,AFTER,'A::f',good,tmp_path/'receipt.json')
    assert 'return 99;' in path.read_text()


@pytest.mark.parametrize('failure',['compile','regression','header','source'])
def test_changed_inputs_or_failed_proof_preserve_live_file(tmp_path,failure):
    shared=tmp_path/'shared';path=source(shared)
    header=shared/'rebuild/2008-06/native-headers/A.h';header.parent.mkdir();header.write_text('// original')
    calls=[]
    def prove(root,rel):
        calls.append(True)
        if len(calls)==1:return dict(ok=True,hits=[dict(addr='existing')])
        if failure=='header':header.write_text('// owner changed header')
        if failure=='source':path.write_text(BEFORE.replace('return 2;','return 99;'))
        return dict(ok=failure!='compile',target_exact=True,losses=[],hits=[] if failure=='regression' else [dict(addr='existing')])
    with pytest.raises(ValueError):
        recovery.merge(shared,tmp_path/'proof',REL,BEFORE,AFTER,'A::f',prove,tmp_path/'receipt.json')
    assert 'return 3;' not in path.read_text()
    if failure=='header':assert header.read_text()=='// owner changed header'
    if failure=='source':assert 'return 99;' in path.read_text()


def test_crlf_preserved(tmp_path):
    shared=tmp_path/'shared';path=source(shared,BEFORE.replace('\n','\r\n'))
    recovery.merge(shared,tmp_path/'proof',REL,BEFORE,AFTER,'A::f',good,tmp_path/'receipt.json')
    assert path.read_bytes()==AFTER.replace('\n','\r\n').encode()


def test_extra_method_or_layout_changes_rejected():
    for candidate in (AFTER.replace('return 2;','return 4;'),AFTER+'struct Padding { int x; };'):
        with pytest.raises(ValueError):recovery.method_change(BEFORE,candidate,'A::f')


def test_ten_simultaneous_sessions_cannot_duplicate_method_claim(tmp_path):
    claims=recovery.Claims(tmp_path); barrier=threading.Barrier(10)
    def claim(_):
        barrier.wait();return claims.take('method','snapshot',{})
    with ThreadPoolExecutor(max_workers=10) as pool: owners=list(pool.map(claim,range(10)))
    assert len([x for x in owners if x])==1
    owner=next(x for x in owners if x)
    claims.update('method',owner,'recovered',{'proof':'saved'})
    first=claims.pending();assert first[0][2]['proof']=='saved'
    assert claims.pending()==[]
    claims.update(first[0][0],first[0][1],'merged',first[0][2])
    assert claims.take('method','snapshot',{}) is None
    assert claims.take('method','changed snapshot',{})


def test_cancelled_claim_can_resume_without_wait(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','s',{})
    claims.update('a',owner,'cancelled',{})
    assert claims.take('a','s',{})


def test_header_target_requires_consuming_cpp(tmp_path):
    root=tmp_path/'private';source(root)
    header=root/'rebuild/2008-06/native-headers/A.h';header.parent.mkdir();header.write_text('int A::f(){return 1;}')
    with pytest.raises(ValueError,match='consuming'):
        recovery.compile_probe(root,header.relative_to(root).as_posix(),None,None,{'00000001'},'A::f')
    for rel in ('../outside.cpp','tools/vendor.cpp','rebuild/2008-06/native-classes/../../../../outside.cpp'):
        with pytest.raises(ValueError):recovery.native_path(root,rel)


def test_file_probe_ipc_enforces_budget_without_network(tmp_path):
    calls=[];broker=recovery.ProbeServer(1,lambda:False)
    folder=tmp_path/'agent';folder.mkdir()
    directory=broker.add(folder,lambda:(calls.append(True) or dict(ok=True)),1)
    try:
        for n in range(2):
            p=directory/(str(n)+'.request');p.write_text('{}')
            end=time.monotonic()+3
            while not p.with_suffix('.json').exists() and time.monotonic()<end:time.sleep(.01)
            result=json.loads(p.with_suffix('.json').read_text())
            assert result['ok'] is (n==0)
        assert calls==[True]
    finally:broker.close()


def test_unmapped_native_method_stays_pending(tmp_path):
    candidate=source(tmp_path,AFTER)
    result=recovery.stage_submission(dict(candidate=str(candidate),task={'method':'A::f','addr':'00000001'}),
        SimpleNamespace(tree=tmp_path/'vendor',overlay=tmp_path/'overlay'),{'revision':'base'},tmp_path/'output',lambda _:None)
    assert result['state']=='pending-mapping'


def test_agent_config_requires_codex_and_no_dollar_budget():
    config=dict(lease_mode='native',native_generation='agent',workers=10,model='codex:gpt-6-luna',user='tester',
                server='localhost:8765',cloud_allowed=True)
    assert gui_worker.validate(config,check_model=False)['native_agent_checks']==6
    with pytest.raises(ValueError,match='signed-in codex'):
        gui_worker.validate(dict(config,model='openai:small'),check_model=False)
    with pytest.raises(ValueError,match='plan limits'):
        gui_worker.validate(dict(config,max_cloud_cost=1),check_model=False)


def test_ten_tool_agents_probe_and_merge_distinct_bodies_without_losing_neighbors(tmp_path,monkeypatch):
    import re
    from roc import native_sweep as sweep, match
    shared=tmp_path/'shared'; private=tmp_path/'controller'
    text='\n'.join('int A::f%d(){return %d;}'%(n,n) for n in range(10))+'\n'
    source(shared,text)
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT',str(shared));monkeypatch.setattr(recovery,'ROOT',private)
    monkeypatch.setenv('ROC_NATIVE_RECOVERY_OUTPUT',str(private/'work/native-recovery'))
    context=SimpleNamespace(names={},by_addr={},tree=tmp_path/'vendor',overlay=tmp_path/'overlay',includes=[])
    class Api:
        def __init__(self,*a):pass
        def call(self,path,*a,**kw):return {'revision':'base'}
        def close(self):pass
    monkeypatch.setattr(recovery.worker,'Api',Api)
    monkeypatch.setattr(sweep,'native_context',lambda *a:context)
    monkeypatch.setattr(sweep,'Matcher',lambda *a:None)
    monkeypatch.setattr(match,'_functions',lambda *a:{})
    monkeypatch.setattr(match,'coff_functions',lambda *a:[])
    assignments=[dict(file=REL,method='A::f%d'%n,addr='%08x'%n) for n in range(10)]
    monkeypatch.setattr(recovery,'nominations',lambda *a:assignments)
    monkeypatch.setattr(sweep,'model_evidence',lambda *a:{'asm':'genuine test fixture'})
    monkeypatch.setattr(recovery,'stage_submission',lambda *a,**kw:dict(state='pending-mapping'))
    active=peak=0;lock=threading.Lock()
    def compile(root,rel,ctx,matcher,addresses,method,baseline=None,**kw):
        nonlocal active,peak
        with lock:active+=1;peak=max(peak,active)
        try:
            time.sleep(.003)
            src=(root/rel).read_text();obj=root/'test.obj';obj.write_bytes(src.encode())
            found=[dict(addr='%08x'%n,symbol='?f%d@A@@QAEHXZ'%n) for n in range(10) if 'A::f%d(){return %d;}'%(n,n+100) in src]
            return dict(ok=True,error='',hits=found,object=str(obj),losses=sorted(set(baseline or ())-{h['addr'] for h in found}),
                        target_exact=bool(set(addresses)&{h['addr'] for h in found}))
        finally:
            with lock:active-=1
    monkeypatch.setattr(recovery,'compile_probe',compile)
    barrier=threading.Barrier(10);seen=[]
    def codex(folder,model,seconds,stopping,log):
        task=json.loads((folder/'task.json').read_text());n=int(task['addr'],16)
        seen.append(n);barrier.wait(timeout=10)
        path=folder/task['file'];path.write_text(path.read_text().replace('A::f%d(){return %d;}'%(n,n),'A::f%d(){return %d;}'%(n,n+100)))
        probe=subprocess.run([sys.executable,'check.py'],cwd=folder,capture_output=True,text=True,timeout=10)
        assert probe.returncode==0,probe.stderr
        assert json.loads(probe.stdout)['target_exact']
        return dict(input_tokens=10,output_tokens=10,cancelled=False)
    monkeypatch.setattr(recovery,'run_codex',codex)
    config={**gui_worker.DEFAULTS,**dict(lease_mode='native',native_generation='agent',model='codex:gpt-6-luna',
             workers=10,user='test',server='localhost:8765',cloud_allowed=True,native_compile_workers=2,max_cloud_requests=10)}
    control=gui_worker.Control(config,lambda *a,**kw:None)
    result=recovery.run(config,control,lambda *a,**kw:None)
    assert sorted(seen)==list(range(10))
    assert result['recovered']==10 and result['merged']==10 and result['conflicts']==0
    assert control.budget.requests==10 and peak<=2
    final=(shared/REL).read_text()
    assert all('A::f%d(){return %d;}'%(n,n+100) in final for n in range(10))
    assert len(list((private/'work/native-recovery/receipts').glob('*.json')))==10


def test_submission_adapter_uses_current_canonical_method_and_rechecks_before_export(tmp_path,monkeypatch):
    candidate=source(tmp_path/'candidate',AFTER)
    tree=tmp_path/'vendor';overlay=tmp_path/'overlay'
    path=tree/'App/util/A.cpp';path.parent.mkdir(parents=True);path.write_text(BEFORE)
    seen=[]
    def recheck(proposal,ctx,texts,out,revision,log,recover):
        seen.append(proposal)
        assert recover and revision=='fresh' and proposal['edits'][0][0] in BEFORE
        assert sweep.apply_edits(BEFORE,proposal['edits'])==AFTER
        return proposal
    from roc import native_sweep as sweep
    monkeypatch.setattr(sweep,'recheck_proposal',recheck)
    result=recovery.stage_submission(dict(candidate=str(candidate),task={'method':'A::f','addr':'00000001'}),
        SimpleNamespace(tree=tree,overlay=overlay),{'revision':'fresh'},tmp_path/'submission',lambda _:None)
    assert result['state']=='ready' and seen
    assert json.loads(Path(result['proposals']).read_text())[0]['base_revision']=='fresh'


def test_expired_merge_resumes_saved_proof_after_controller_restart(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','s',{})
    claims.update('a',owner,'recovered',dict(candidate='retained.cpp'))
    first=claims.pending()[0]
    with claims.connect() as db:db.execute('UPDATE tasks SET expires=0')
    restarted=recovery.Claims(tmp_path).pending()[0]
    assert restarted[0]==first[0] and restarted[1]!=first[1]
    assert restarted[2]['candidate']=='retained.cpp'


def test_stop_kills_only_the_active_agent_process(tmp_path,monkeypatch):
    spawn=subprocess.Popen
    processes=[]
    def start(argv,**kwargs):
        if 'workspace-write' not in argv: return spawn(argv,**kwargs)
        assert 'workspace-write' in argv and '--ignore-user-config' in argv
        process=spawn([sys.executable,'-u','-c','import sys,time;sys.stdin.readline();time.sleep(30)'],**kwargs)
        processes.append(process);return process
    monkeypatch.setattr(recovery.subprocess,'Popen',start)
    (tmp_path/'instructions.md').write_text('test')
    started=time.monotonic()
    result=recovery.run_codex(tmp_path,'codex:gpt-6-luna',30,lambda:time.monotonic()-started>.3,lambda _:None)
    assert result['cancelled'] and processes[0].poll() is not None


def test_gui_agent_mode_defers_full_dependency_build_and_routes_real_recovery(monkeypatch):
    from roc import integration, providers
    calls=[]
    config={**gui_worker.DEFAULTS,**dict(lease_mode='native',native_generation='agent',workers=10,
         model='codex:gpt-6-luna',user='tester',server='localhost:8765',cloud_allowed=True)}
    control=gui_worker.Control(config,lambda *a,**kw:None)
    monkeypatch.setattr(providers,'available',lambda _:True)
    monkeypatch.setattr('roc.rebuild_install.prepare',lambda **kw:calls.append(kw))
    monkeypatch.setattr(gui_worker.worker,'save_settings',lambda **kw:None)
    monkeypatch.setattr(integration,'command',lambda _:None)
    def run(current,ctl,emit):
        assert current['workers']==10 and ctl is control
        ctl.command({'action':'stop'})
        return dict(attempted=10,recovered=4,merged=3,conflicts=1,submitted=1,accepted=0,pending=2)
    monkeypatch.setattr(recovery,'run',run)
    events=[]
    gui_worker.native_loop(config,control,lambda event,**kw:events.append((event,kw)))
    assert calls[0]['build_dependencies'] is False
    assert next(row for kind,row in events if kind=='native_recovery')['merged']==3


def test_explicit_new_body_appends_without_replacing_other_agents_source(tmp_path):
    shared=tmp_path/'shared';source(shared,BEFORE+'// another agent note\n')
    added='\nint A::h(){return 17;}\n'
    recovery.merge(shared,tmp_path/'proof',REL,BEFORE,BEFORE+added,'A::h',good,tmp_path/'receipt.json',allow_add=True)
    assert (shared/REL).read_text()==BEFORE+'// another agent note\n'+added
    with pytest.raises(ValueError,match='Conflict'):
        recovery.merge(shared,tmp_path/'proof2',REL,BEFORE,BEFORE+added.replace('17','18'),'A::h',good,tmp_path/'receipt2.json',allow_add=True)


def test_historical_compiler_header_probe_checks_actual_consuming_tu(tmp_path):
    from roc import setup, native_sweep as sweep, match
    if 21022 not in setup.compilers(): pytest.skip('Historical MSVC not installed')
    unit=source(tmp_path,'#include "../native-headers/A.h"\nint use(A* a){return a->f();}\n')
    header=tmp_path/'rebuild/2008-06/native-headers/A.h';header.parent.mkdir()
    header.write_text('struct A { __declspec(noinline) int f(); };\nint A::f(){return 17;}\n')
    ctx=SimpleNamespace(defines='',flags=sweep.FLAGS)
    class Empty:
        def scan(self,data):return []
    first=recovery.compile_probe(tmp_path,header.relative_to(tmp_path).as_posix(),ctx,Empty(),{'00000001'},'A::f',translation_unit=REL)
    assert first['ok'],first['error']
    golden={n:(b,r) for n,b,r in match.coff_functions(Path(first['object']).read_bytes())}
    class Compare:
        def scan(self,data):
            return [dict(addr='00000001',symbol=n) for n,b,r in match.coff_functions(data)
                    if n.startswith('?f@A@@') and golden.get(n)==(b,r)]
    header.write_text(header.read_text().replace('17','18'))
    bad=recovery.compile_probe(tmp_path,header.relative_to(tmp_path).as_posix(),ctx,Compare(),{'00000001'},'A::f',translation_unit=REL)
    assert bad['ok'] and not bad['target_exact']
    header.write_text(header.read_text().replace('18','17'))
    passed=recovery.compile_probe(tmp_path,header.relative_to(tmp_path).as_posix(),ctx,Compare(),{'00000001'},'A::f',translation_unit=REL)
    assert passed['target_exact']
    assert Path(first['object']).exists() and Path(bad['object'])!=Path(first['object'])


def test_saved_drafts_do_not_trigger_new_agents_until_submission_enabled(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','old-input',{})
    claims.update('a',owner,'draft',dict(candidate='saved.cpp'))
    assert claims.take('a','new-header-input',{}) is None
    assert claims.pending()==[]
    restored=claims.pending(include_drafts=True)
    assert restored[0][2]['candidate']=='saved.cpp'


def test_saved_recovery_is_rechecked_instead_of_spending_another_agent(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','old-input',{})
    claims.update('a',owner,'recovered',dict(candidate='saved.cpp'))
    assert claims.take('a','changed-header',{}) is None
    assert claims.pending()[0][2]['candidate']=='saved.cpp'


def test_cancelled_assignment_retains_private_source_for_replay(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','input',{})
    claims.update('a',owner,'cancelled',dict(workspace='private-agent',original=BEFORE,task={'method':'A::f'}))
    next_owner=claims.take('a','input',{})
    saved=claims.record('a',next_owner)['resume']
    assert saved['workspace']=='private-agent' and saved['original']==BEFORE


def test_submission_batches_methods_in_one_canonical_file_and_one_preflight(tmp_path,monkeypatch):
    from roc import native_sweep as sweep
    records=[]
    for n in range(10):
        path=tmp_path/('proposal%d.json'%n)
        path.write_text(json.dumps([dict(file='App/util/A.cpp',edits=[['method%d old'%n,'method%d new'%n]],
            witnesses=[dict(addr='%08x'%n)],base_revision='base')]))
        records.append(dict(submission={'proposals':str(path)}))
    checks=[];submissions=[]
    def recheck(proposal,*a,**kw):checks.append(proposal);return proposal
    def run(spec,*a,**kw):submissions.append(spec);return dict(job='one-job')
    monkeypatch.setattr(sweep,'recheck_proposal',recheck);monkeypatch.setattr(sweep,'run',run)
    result=recovery.submit_batch(records,None,{'revision':'base'},tmp_path/'batch','server','codex:gpt-6-luna',lambda _:None)
    assert result['job']=='one-job' and len(checks)==1 and len(submissions)==1
    assert len(checks[0]['edits'])==10 and len(checks[0]['witnesses'])==10
    assert submissions[0]['native_sweep']['submit'] and submissions[0]['native_sweep']['apply']


def test_failed_submission_waits_for_changed_inputs_instead_of_rebuilding_forever(tmp_path):
    claims=recovery.Claims(tmp_path);owner=claims.take('a','input',{})
    claims.update('a',owner,'draft',dict(candidate='saved.cpp',blocked_signature='same-build-inputs'))
    assert claims.pending(include_drafts=True,input_signature='same-build-inputs')==[]
    assert claims.pending(include_drafts=True,input_signature='new-header-or-base')[0][2]['candidate']=='saved.cpp'
