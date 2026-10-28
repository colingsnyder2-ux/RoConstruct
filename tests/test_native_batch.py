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


def test_cached_method_spans_do_not_leak_mutable_maps():
    text='int A::f(){return 1;}'
    first=native_sweep.methods(text);first.clear()
    assert 'A::f' in native_sweep.methods(text)
    changed='int A::f(){return 1000;}'
    assert native_sweep.methods(text)['A::f'] != native_sweep.methods(changed)['A::f']
