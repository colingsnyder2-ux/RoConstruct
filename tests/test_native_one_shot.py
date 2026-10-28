from types import SimpleNamespace
import pytest
from roc import native_sweep, providers


def test_one_shot_keeps_original_signature_and_neighbors():
    text = 'int A::f(int x) const { return x; }\nint A::g(){return 7;}'
    edits = native_sweep.method_edits(text, '```cpp\nint A::f(int x) const { return x+1; }\n```', 'A::f')
    assert native_sweep.apply_edits(text, edits) == text.replace('return x;', 'return x+1;')


@pytest.mark.parametrize('reply', [
    'int A::f(float x) const { return 2; }',
    'int A::f(int x) { return 2; }',
    'int A::f(int x) const { return 2; }\nvoid A::g(){}',
    'namespace A { int A::f(int x) const { return 2; } }',
    '#pragma float_control(precise,off)\nint A::f(int x) const { return 2; }',
])
def test_one_shot_rejects_signature_changes_and_extra_code(reply):
    with pytest.raises(ValueError):
        native_sweep.method_edits('int A::f(int x) const { return x; }', reply, 'A::f')


def test_auto_falls_back_to_anchored_repair_and_preserves_loss_gate(tmp_path, monkeypatch):
    replies = iter(['```cpp\nint A::f(){return 2;}\n```',
                    '```cpp\n<<<<<<< SEARCH\nreturn 1;\n=======\nreturn 3;\n>>>>>>> REPLACE\n```'])
    formats = []
    def generate(model, messages, options):
        formats.append(options['edit_blocks'])
        return SimpleNamespace(text=next(replies))
    monkeypatch.setattr(providers, 'generate', generate)
    def compile(source, label):
        p=tmp_path/(label+'.obj'); p.write_text(source)
        return {'ok': True, 'object': str(p), 'error': None}
    matcher=SimpleNamespace(scan=lambda obj: [{'addr':a} for a in
        (['00000001'] if b'return 2;' in obj else ['00000001','00000002'])])
    proposal,trials=native_sweep.model_proposal('App/util/A.cpp','int A::f(){return 1;}',['00000001'],
        {'00000002'},{'00000002'},'codex:default',2,compile,matcher,
        lambda a:{'addr':a,'rebuilt_symbol':'?f@A@RBX@@QAEHXZ'},lambda _:None,{'generation':'auto'})
    assert formats == [False, True]
    assert trials[0]['losses'] == ['00000002']
    assert proposal['edits'] == [['return 1;', 'return 3;']]


def test_one_shot_rejects_invented_types_before_compilation(monkeypatch):
    monkeypatch.setattr(providers,'generate',lambda *args:SimpleNamespace(
        text='```cpp\nint A::f(){ struct Padding { int a; }; return 2; }\n```'))
    def compile(*args):raise AssertionError('invalid proposal must not compile')
    proposal,trials=native_sweep.model_proposal('App/util/A.cpp','int A::f(){return 1;}',['00000001'],
        set(),set(),'codex:default',1,compile,None,
        lambda a:{'addr':a,'rebuilt_symbol':'?f@A@RBX@@QAEHXZ'},lambda _:None,{'generation':'method'})
    assert proposal is None and 'invented snippet types' in trials[0]['error']


def test_auto_compiler_slots_follow_cpu_without_twenty_compile_oversubscription(monkeypatch):
    monkeypatch.setattr(native_sweep.os,'cpu_count',lambda:20)
    assert native_sweep.resolve_compile_workers('auto',20)==8
    assert native_sweep.resolve_compile_workers('auto',2)==2
    assert native_sweep.resolve_compile_workers(20,20)==20
    monkeypatch.setattr(native_sweep.os,'cpu_count',lambda:4)
    assert native_sweep.resolve_compile_workers('auto',20)==2
    with pytest.raises(ValueError):native_sweep.resolve_compile_workers(0,20)


def test_locally_exact_targets_never_request_models_or_evidence(monkeypatch):
    from unittest.mock import Mock
    generate,evidence,compile=Mock(),Mock(),Mock()
    monkeypatch.setattr(providers,'generate',generate)
    assert native_sweep.model_proposal('A.cpp','void A::f(){}',['00000001'],{'00000001'},set(),
        'codex:default',3,compile,None,evidence,lambda _:None,{'generation':'auto'}) == (None,[])
    generate.assert_not_called();evidence.assert_not_called();compile.assert_not_called()


def test_identical_failed_candidates_do_not_repeat_compiles(tmp_path,monkeypatch):
    from unittest.mock import Mock
    reply='<<<<<<< SEARCH\nreturn 1;\n=======\nreturn 2;\n>>>>>>> REPLACE'
    monkeypatch.setattr(providers,'generate',lambda *args:SimpleNamespace(text=reply))
    obj=tmp_path/'object.obj';obj.write_bytes(b'not exact')
    compile=Mock(return_value={'ok':True,'object':str(obj),'error':None})
    proposal,trials=native_sweep.model_proposal('App/util/A.cpp','int A::f(){return 1;}',['00000001'],set(),set(),
        'codex:default',2,compile,SimpleNamespace(scan=lambda _:[]),lambda a:{'addr':a},lambda _:None)
    assert proposal is None and 'Repeated failed candidate' in trials[-1]['error']
    compile.assert_called_once()


def test_returned_ai_edits_compile_before_remaining_baselines(tmp_path,monkeypatch):
    import threading,time
    from unittest.mock import Mock
    files={f'App/file{n}.cpp':'void A::f(){}' for n in range(3)}
    monkeypatch.setattr(native_sweep,'target_files',lambda *args:{rel:['00400000'] for rel in files})
    obj=tmp_path/'object.obj';obj.write_bytes(b'object')
    order=[];started=[];all_started=threading.Event();proof_requested=threading.Event()
    def event(kind,**fields):
        if kind=='native_started':
            started.append(fields['file'])
            if len(started)==3:all_started.set()
    def compile(source,rel,label):
        order.append((rel,label))
        if len(order)==1:assert all_started.wait(2)
        elif len(order)==2 and label=='baseline':
            assert proof_requested.wait(2)
            time.sleep(.03)
        return {'ok':True,'object':str(obj)}
    def proposal(rel,text,addrs,baseline,owned,model,rounds,compile_round,*args):
        if rel==order[0][0]:
            proof_requested.set()
            compile_round('proof','model-candidate')
        return None,[]
    monkeypatch.setattr(native_sweep,'model_proposal',proposal)
    native_sweep.model_discovery({'llm':'codex:default','compile_workers':1,'provider_options':{'event':event}},
        files,{'00400000'},set(),{},SimpleNamespace(scan=lambda _:[]),tmp_path,3,lambda _:None,
        compile,{'00400000':{'symbol':'f'}})
    assert next(i for i,(_,label) in enumerate(order) if label=='model-candidate') <= 2
