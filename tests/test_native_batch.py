import hashlib
from pathlib import Path
from types import SimpleNamespace
import pytest
from roc import native_batch, native_sweep


def fixture(tmp_path, count=4):
    text='\n'.join('int A::f%d(){return %d;}'%(n,n) for n in range(count))
    candidates=[dict(method='A::f%d'%n,targets=['%08x'%n],edits=[['A::f%d(){return %d;}'%(n,n),'A::f%d(){return %d;}'%(n,100+n)]]) for n in range(count)]
    compiled=[]
    def compile(source,label):
        compiled.append(source)
        path=tmp_path/(label+'.obj');path.write_text(source)
        return dict(ok='BROKEN' not in source,object=str(path),source_sha256=hashlib.sha256(source.encode()).hexdigest(),error='compile error' if 'BROKEN' in source else None)
    def scan(data):
        text=data.decode()
        result=[{'addr':'keeper','symbol':'keep'}] if 'LOSE_KEEPER' not in text else []
        return result+[{'addr':'%08x'%n,'symbol':'f%d'%n} for n in range(count) if 'return %d;'%(100+n) in text]
    return text,candidates,compile,SimpleNamespace(scan=scan),compiled


def test_twenty_worker_methods_share_one_compile_and_one_consistent_proof(tmp_path):
    text,candidates,compile,matcher,compiled=fixture(tmp_path,20)
    proposal,trials=native_batch.prove('App/util/A.cpp',text,candidates,{'keeper'},compile,matcher,lambda _:None)
    assert len(compiled)==1 and len(proposal['witnesses'])==20
    assert native_sweep.apply_edits(text,proposal['edits'])==compiled[-1]
    assert proposal['proof']['source_sha256']==hashlib.sha256(compiled[-1].encode()).hexdigest()
    assert proposal['proof']['losses']==[]


@pytest.mark.parametrize('bad',['BROKEN','LOSE_KEEPER'])
def test_bad_worker_is_isolated_and_remaining_methods_reproved_together(tmp_path,bad):
    text,candidates,compile,matcher,compiled=fixture(tmp_path)
    candidates[1]['edits'][0][1]='A::f1(){return '+bad+';}'
    proposal,trials=native_batch.prove('App/util/A.cpp',text,candidates,{'keeper'},compile,matcher,lambda _:None)
    assert {h['addr'] for h in proposal['witnesses']}=={'00000000','00000002','00000003'}
    assert bad not in native_sweep.apply_edits(text,proposal['edits'])
    assert proposal['proof']['losses']==[]
    assert native_sweep.apply_edits(text,proposal['edits'])==Path(proposal['proof']['object']).read_text()
    failed = [r for r in trials if not r['ok']]
    if bad == 'BROKEN':
        assert failed and all(r['losses'] == [] and not r['comparison_complete'] for r in failed)
    else:
        assert any(r['losses'] == ['keeper'] and r['comparison_complete'] for r in trials)


def test_nonexact_neighbour_edits_are_removed_and_recompiled(tmp_path):
    text,candidates,compile,matcher,compiled=fixture(tmp_path)
    candidates[2]['edits'][0][1]='A::f2(){return 999;}'
    proposal,trials=native_batch.prove('App/util/A.cpp',text,candidates,{'keeper'},compile,matcher,lambda _:None)
    assert len(compiled)==2
    assert len(proposal['witnesses'])==3
    assert 'return 999;' not in native_sweep.apply_edits(text,proposal['edits'])


def test_batch_rejects_source_proof_mismatch(tmp_path):
    text,candidates,compile,matcher,compiled=fixture(tmp_path)
    def wrong(source,label):return dict(compile(source,label),source_sha256='wrong')
    with pytest.raises(ValueError,match='proof source'):
        native_batch.prove('App/util/A.cpp',text,candidates,{'keeper'},wrong,matcher,lambda _:None)


def test_batch_rejects_unrelated_method_and_signature_edits(tmp_path):
    text,candidates,*_=fixture(tmp_path)
    with pytest.raises(ValueError,match='outside'):
        native_batch.method_candidate(text,'A::f0',[['return 1;','return 101;']],['00000001'])
    with pytest.raises(ValueError,match='signature'):
        native_batch.method_candidate(text,'A::f0',[['f0()','f0(int x)']],['00000000'])


def test_invalid_worker_edits_do_not_block_valid_workers(tmp_path):
    text,candidates,compile,matcher,compiled=fixture(tmp_path)
    candidates[1]['edits'][0][1]+='\nvoid A::extra(){}'
    proposal,trials=native_batch.prove('App/util/A.cpp',text,candidates,{'keeper'},compile,matcher,lambda _:None)
    assert len(proposal['witnesses'])==3
    assert any(r.get('mode')=='batch-invalid' for r in trials)
    assert 'extra' not in compiled[-1]


def test_conflicting_alternative_is_tried_separately_then_compatible_proofs_merge(tmp_path):
    text,candidates,compile,matcher,compiled=fixture(tmp_path,2)
    wrong=dict(candidates[0],edits=[['A::f0(){return 0;}','A::f0(){return 999;}']])
    proposal,trials=native_batch.prove('App/util/A.cpp',text,[wrong,candidates[1],candidates[0]],{'keeper'},compile,matcher,lambda _:None)
    assert len(proposal['witnesses'])==2
    assert 'return 999;' not in native_sweep.apply_edits(text,proposal['edits'])
    assert native_sweep.apply_edits(text,proposal['edits'])==Path(proposal['proof']['object']).read_text()


def test_twenty_ai_workers_in_discovery_share_the_same_file_compile(tmp_path,monkeypatch):
    import re,threading
    from roc import providers
    text,candidates,compile,matcher,compiled=fixture(tmp_path,20)
    barrier=threading.Barrier(20)
    calls=[]
    names={'%08x'%n:{'symbol':'?f%d@A@RBX@@QAEHXZ'%n,'score':90} for n in range(20)}
    def reply(model,messages,options):
        token=re.search(r'Repair ONLY A::f(\d+)',messages[1]['content'])
        assert token
        n=int(token[1]);calls.append(n);barrier.wait(timeout=5)
        return SimpleNamespace(text='```cpp\nint A::f%d(){return %d;}\n```'%(n,100+n))
    monkeypatch.setattr(providers,'generate',reply)
    monkeypatch.setattr(native_sweep,'model_evidence',lambda addr,*args:{'addr':addr,'rebuilt_symbol':names[addr]['symbol']})
    monkeypatch.setattr(native_sweep,'body_diff',lambda *args:'target diff')
    proposals,trials=native_sweep.model_discovery({'llm':'codex:default','rounds':1,'generation':'method','compile_batch':20},
        {'App/util/A.cpp':text},set(names),{'keeper'}, {a:{'unit':'RBX::A','size':6} for a in names},matcher,tmp_path,20,
        lambda _:None,lambda source,rel,label:compile(source,label),names)
    assert len(calls)==20 and len(compiled)==2  # baseline + shared proposal
    assert len(proposals)==1 and len(proposals[0]['witnesses'])==20


@pytest.mark.parametrize('workers,fresh,old', [(20,7,13),(2,1,1)])
def test_short_batch_refills_idle_workers_with_untried_targets(tmp_path, monkeypatch, workers, fresh, old):
    import threading
    texts, names, rows = {}, {}, {}
    prior = []
    for i in range(fresh+old):
        cls = 'A%02d' % i
        rel = 'App/'+cls+'.cpp'
        texts[rel] = '\n'.join('int %s::f%d(){return 0;}' % (cls,n) for n in range(10))
        if i >= fresh:
            prior.append(rel)
        for n in range(10):
            addr = '%08x' % (i*16+n)
            names[addr] = dict(symbol='?f%d@%s@RBX@@QAEHXZ' % (n,cls),score=90)
            rows[addr] = dict(unit='RBX::'+cls,size=6)
    barrier, seen = threading.Barrier(workers), {}
    def proposal(rel, text, addrs, *args, **kwargs):
        seen[rel] = addrs[0]
        barrier.wait(timeout=5)
        return None, []
    monkeypatch.setattr(native_sweep, 'model_proposal', proposal)
    def compile(source, rel, label):
        path = tmp_path/(Path(rel).stem+'.obj')
        path.write_bytes(b'baseline')
        return dict(ok=True,object=str(path))
    _, records = native_sweep.model_discovery(dict(llm='codex:default',rounds=1,max_files=40,
        rolling_workers=True,exclude_files=prior,retry_targets=dict.fromkeys(prior,10),
        file_offsets=dict.fromkeys(prior,4)),texts,set(names),set(),rows,
        SimpleNamespace(scan=lambda _:[]),tmp_path,workers,lambda _:None,compile,names)
    assert len(seen) == workers
    assert all(int(addr,16)%16 == (4 if rel in prior else 0) for rel,addr in seen.items())
    assert all(r['pending_targets'] == 10 for r in records)


def test_cached_method_spans_do_not_leak_mutable_maps():
    text='int A::f(){return 1;}'
    first=native_sweep.methods(text);first.clear()
    assert 'A::f' in native_sweep.methods(text)
    changed='int A::f(){return 1000;}'
    assert native_sweep.methods(text)['A::f'] != native_sweep.methods(changed)['A::f']


def test_discovery_repair_context_uses_pending_targets_not_local_exacts(tmp_path, monkeypatch):
    text, candidates, compile, _, compiled = fixture(tmp_path, 4)
    names = {'%08x'%n: {'symbol':'?f%d@A@RBX@@QAEHXZ'%n,'score':100-n} for n in range(4)}
    seen = {}
    def excerpt(text, symbols):
        seen['symbols'] = symbols
        return 'pending source context'
    def proposal(rel, text, addrs, *args):
        seen['addrs'] = addrs
        assert args[-1] == 'pending source context'
        return None, []
    monkeypatch.setattr(native_sweep,'excerpt',excerpt)
    monkeypatch.setattr(native_sweep,'model_proposal',proposal)
    matcher = SimpleNamespace(scan=lambda _: [{'addr':'00000000'}])
    native_sweep.model_discovery({'llm':'codex:default','context':'methods'},
        {'App/util/A.cpp':text},set(names),set(),{a:{'unit':'RBX::A','size':6} for a in names},matcher,tmp_path,1,
        lambda _:None,lambda source,rel,label:compile(source,label),names)
    assert seen['addrs'] == ['00000001','00000002','00000003']
    assert seen['symbols'] == [names[a]['symbol'] for a in seen['addrs']]


def test_proposal_checkpoint_is_saved_before_slower_files_finish(tmp_path, monkeypatch):
    import json, threading
    from roc import integration
    checkpoint = threading.Event()
    atomic = integration.atomic_json
    def saving(path, value):
        atomic(path, value)
        if path.name == 'proposals.json':checkpoint.set()
    monkeypatch.setattr(integration,'atomic_json',saving)
    def propose(rel, text, *args):
        if rel.endswith('B.cpp'):
            assert checkpoint.wait(5)
            saved = json.loads((tmp_path/'proposals.json').read_text())
            assert saved[0]['base_revision'] == 'accepted-baseline'
            return None, []
        return dict(file=rel, edits=[['return 0;', 'return 10;']],
                    witnesses=[{'addr':'00000001','symbol':'?f@A@RBX@@QAEHXZ'}], proof={}), []
    monkeypatch.setattr(native_sweep,'model_proposal',propose)
    obj = tmp_path/'baseline.obj'
    obj.write_bytes(b'baseline')
    names = {'00000001':{'symbol':'?f@A@RBX@@QAEHXZ'},'00000002':{'symbol':'?f@B@RBX@@QAEHXZ'}}
    proposals, _ = native_sweep.model_discovery({'llm':'codex:default','base_revision':'accepted-baseline'},
        {'App/util/A.cpp':'int A::f(){return 0;}','App/util/B.cpp':'int B::f(){return 0;}'},
        set(names),set(),{'00000001':{'unit':'RBX::A'},'00000002':{'unit':'RBX::B'}},
        SimpleNamespace(scan=lambda _: []),tmp_path,2,lambda _:None,
        lambda *args:dict(ok=True,object=str(obj)),names)
    assert len(proposals) == 1
