from types import SimpleNamespace

from roc import native_sweep, providers


def block(old, new):
    return "<<<<<<< SEARCH\n%s\n=======\n%s\n>>>>>>> REPLACE\n" % (old, new)


def test_minimizer_keeps_called_helper_definition_but_drops_unused_helper(tmp_path):
    def compile_round(source, label):
        obj = tmp_path / (label + '.obj')
        obj.write_text(source)
        return {'ok': True, 'object': str(obj),
                'undefined_symbols': ['helper'] if 'call_helper' in source and 'define_helper' not in source else []}
    matcher = SimpleNamespace(scan=lambda data: [{'addr': '00000001'}] if b'call_helper' in data else [])
    edits = [['CALL', 'call_helper'], ['BODY', 'define_helper'], ['UNUSED', 'define_unused']]
    proposal = native_sweep.minimize('A.cpp', 'CALL BODY UNUSED', edits, {'00000001'}, set(),
                                      compile_round, matcher, 'helper', definitions={'helper', 'unused'})
    assert proposal['edits'] == edits[:2]


def test_model_proposal_feeds_back_until_new_exact_without_loss(tmp_path, monkeypatch):
    replies = iter([
        'not a block',
        block("return 1;", "return 2;"),   # compiles, loses owned 00000002
        "Fix:\r\n" + block("return 1;", "return 3;").replace("\n", "\r\n"),   # new exact 00000001, no loss
    ])
    seen = []
    monkeypatch.setattr(providers, "generate",
                        lambda model, messages, options: (seen.append(messages[-1]["content"]), SimpleNamespace(text=next(replies)))[1])
    hits = {"return 2;": [], "return 3;": ["00000001", "00000002"]}

    def compile_round(source, label):
        obj = tmp_path / (label + ".obj")
        obj.write_text(source)
        return {"ok": True, "object": str(obj), "mode": label, "error": None}

    matcher = SimpleNamespace(scan=lambda data: [{"addr": a, "symbol": "?f@A@@QAEHXZ"}
                                                 for key, addrs in hits.items() if key.encode() in data for a in addrs])
    proposal, trials = native_sweep.model_proposal(
        "App/v8datamodel/A.cpp", "int A::f() { return 1; }", ["00000001"], {"00000002"}, {"00000002"},
        "deepseek:x", 3, compile_round, matcher, lambda addr: {"addr": addr}, lambda *a: None)
    assert proposal["edits"] == [["return 1;", "return 3;"]]
    assert [w["addr"] for w in proposal["witnesses"]] == ["00000001"]
    assert "Rejected" in seen[1] and "Lost previously exact: ['00000002']" in seen[2]
    assert len([r for r in trials if r.get('mode') != 'model-request']) == 3


def test_apply_edits_requires_unique_anchor():
    assert native_sweep.apply_edits("a b a", [["b", "c"]]) == "a c a"
    for bad in ([["a", "x"]], [["z", "x"]], [], [["", "x"]]):
        try:
            native_sweep.apply_edits("a b a", bad)
        except ValueError:
            continue
        raise AssertionError(bad)


def test_model_proposal_keeps_only_edits_the_new_exact_needs(tmp_path, monkeypatch):
    reply = block("return 1;", "return 3;") + block("int g()", "int g2()") + block("int h()", "int h()")
    monkeypatch.setattr(providers, "generate", lambda model, messages, options: SimpleNamespace(text=reply))

    def compile_round(source, label):
        obj = tmp_path / (label + ".obj")
        obj.write_text(source)
        return {"ok": True, "object": str(obj), "mode": label, "error": None}

    matcher = SimpleNamespace(scan=lambda data: [{"addr": "00000001", "symbol": "?f@A@@QAEHXZ"}] if b"return 3;" in data else [])
    proposal, _ = native_sweep.model_proposal(
        "App/v8datamodel/A.cpp", "int A::f() { return 1; } int g() {} int h() {}", ["00000001"], set(), set(),
        "deepseek:x", 1, compile_round, matcher, lambda addr: {"addr": addr}, lambda *a: None)
    assert proposal["edits"] == [["return 1;", "return 3;"]]


def test_invented_types_rejected_before_compile_then_valid_proof_reused(tmp_path, monkeypatch):
    replies = iter([block('return 1;', 'struct Invented { int x; }; return 3;'), block('return 1;', 'return 3;')])
    feedback, compiled = [], []
    def generate(model, messages, options):
        feedback.append(messages[-1]['content'])
        return SimpleNamespace(text=next(replies))
    monkeypatch.setattr(providers, 'generate', generate)
    def compile(source, label):
        compiled.append(source)
        obj = tmp_path / 'valid.obj'
        obj.write_text(source)
        return {'ok':True, 'object':str(obj), 'error':None}
    matcher = SimpleNamespace(scan=lambda _: [{'addr':'00000001', 'symbol':'?f@A@RBX@@'}])
    proposal, _ = native_sweep.model_proposal('App/util/A.cpp', 'int A::f(){return 1;}', ['00000001'], set(), set(),
        'codex:default', 2, compile, matcher, lambda addr: {'addr':addr}, lambda *a: None)
    assert len(compiled) == 1 and 'Invented' not in compiled[0]
    assert 'invented snippet types' in feedback[1]
    assert proposal['edits'] == [['return 1;', 'return 3;']]



def test_model_escalation_provenance_matches_successful_writer(tmp_path,monkeypatch):
    calls=[]
    def generate(model,messages,settings):
        calls.append(model)
        return SimpleNamespace(text='invalid' if len(calls)==1 else block('return 1;','return 3;'),input_tokens=10,output_tokens=4)
    monkeypatch.setattr(providers,'generate',generate)
    def compile_round(source,label):
        obj=tmp_path/(label+'.obj');obj.write_text(source)
        return dict(ok=True,object=str(obj),error=None)
    matcher=SimpleNamespace(scan=lambda data:[dict(addr='00000001',symbol='?f@A@RBX@@QAEHXZ')] if b'return 3;' in data else [])
    proposal,records=native_sweep.model_proposal('App/A.cpp','int A::f(){return 1;}',['00000001'],set(),set(),
        'small',2,compile_round,matcher,lambda a:dict(addr=a),lambda *a:None,
        options=dict(escalation_model='strong',escalate_after=1))
    assert calls==['small','strong'] and proposal['models']==['strong']
    requests=[r for r in records if r.get('mode')=='model-request']
    assert [r['model'] for r in requests]==['small','strong']
    assert sum(r['input_tokens']+r['output_tokens'] for r in requests)==28



def test_no_improvement_budget_bounds_high_round_counts(tmp_path,monkeypatch):
    from roc.integration_policy import AttemptBudget
    budget=AttemptBudget(tmp_path/'budget.json','same',limit=3)
    calls=[]
    def generate(*args):
        calls.append(1)
        return SimpleNamespace(text='invalid',input_tokens=10,output_tokens=2)
    monkeypatch.setattr(providers,'generate',generate)
    proposal,records=native_sweep.model_proposal('App/A.cpp','int A::f(){return 1;}',['00000001'],set(),set(),
        'small',100,lambda *a:None,None,lambda a:dict(addr=a),lambda *a:None,
        options=dict(attempt_allowed=lambda addrs:any(not budget.blocked(a) for a in addrs), record_attempt=budget.record))
    assert proposal is None and len(calls)==3 and budget.blocked('00000001')
    budget.record(records)
    assert budget.targets['00000001']['failures']==3
