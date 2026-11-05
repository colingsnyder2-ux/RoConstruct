from types import SimpleNamespace

from roc import native_repair as repair, native_sweep as sweep, integration


def test_repair_round_robin_covers_attempted_methods_and_rejects_losses(tmp_path, monkeypatch):
    text = 'int A::f(){return 0;}\nint A::g(){return 0;}'
    targets = {'a': '?f@A@RBX@@QAEHXZ', 'b': '?g@A@RBX@@QAEHXZ', 'x': 'unsupported'}
    def variants(source, method, *args):
        old = 'int '+method+'(){return 0;}'
        for n in (1, 2):
            new = old.replace('return 0;', 'return %d;' % n)
            yield 'test:'+method, source.replace(old, new), [[old, new]]
    monkeypatch.setattr(repair, 'variants', variants)
    seen = []
    def compile(source, label):
        path = tmp_path/(label+'.obj');path.write_text(source)
        seen.append(source)
        return dict(ok=True, object=str(path), diagnostics={})
    def scan(obj):
        source = obj.decode()
        # Every candidate makes a target exact, but loses an existing exact.
        addr = 'a' if 'f(){return 1;}' in source else 'b'
        return [dict(addr=addr, symbol=targets[addr])]
    proposal, rows = repair.run('App/A.cpp', text, targets, {'keeper'}, compile,
        SimpleNamespace(scan=scan), lambda _:None, rounds=1, limit=1)
    assert proposal is None
    coverage = rows[-1]
    assert coverage['trials_by_target'] == {'a':2, 'b':1, 'x':0}
    assert coverage['unsupported_targets'] == ['x']
    assert all(row['losses'] == ['keeper'] for row in rows[:-1])
    assert 'g(){return 1;}' in seen[1]


def test_repair_dedupes_previous_trials_and_respects_stop(tmp_path, monkeypatch):
    text = 'int A::f(){return 0;}'
    candidate = text.replace('return 0;', 'return 1;')
    monkeypatch.setattr(repair, 'variants', lambda *args:iter([('one', candidate, [[text, candidate]])]))
    def compile(*args):
        raise AssertionError('No duplicate/cancelled compilation')
    args = ('App/A.cpp', text, {'a':'?f@A@RBX@@QAEHXZ'}, set(), compile, None, lambda _:None)
    proposal, rows = repair.run(*args, seen=[integration.digest(candidate)])
    assert proposal is None and rows[-1]['deferred_targets'] == ['a']
    _, rows = repair.run(*args, before_trial=lambda:False)
    assert rows[-1]['stopped']


def test_repair_proves_exact_only_after_minimization(tmp_path, monkeypatch):
    text = 'int A::f(){return 0;}'
    source = text.replace('return 0;', 'return 1;')
    symbol = '?f@A@RBX@@QAEHXZ'
    monkeypatch.setattr(repair, 'variants', lambda *args:iter([('one', source, [[text, source]])]))
    def compile(candidate, label):
        obj = tmp_path/(label+'.obj');obj.write_text(candidate)
        return dict(ok=True,object=str(obj),defined_symbols=[symbol])
    matcher = SimpleNamespace(scan=lambda obj:[dict(addr='a',symbol=symbol)] if b'return 1;' in obj else [])
    proposal, rows = repair.run('App/A.cpp',text,{'a':symbol},set(),compile,matcher,lambda _:None)
    assert sweep.apply_edits(text,proposal['edits']) == source
    assert proposal['mode'] == 'repair' and proposal['proof']['losses'] == []
    assert rows[-1]['trials_by_target']['a'] == 1


def test_repair_variants_stay_inside_selected_method_and_restore_profiles():
    source = 'int A::f(){if (flag) return 1; else return 2;}\nint A::g(){return 3;}'
    rows = list(repair.variants(source,'A::f'))
    assert any(mode.startswith('ternary:') for mode, _, _ in rows)
    assert any(mode.startswith('scoped-fp:') for mode, _, _ in rows)
    for _, candidate, edits in rows:
        assert sweep.apply_edits(source,edits) == candidate
        assert 'int A::g(){return 3;}' in candidate


def test_discovery_runs_repair_after_unsuccessful_model_with_actual_targets(tmp_path, monkeypatch):
    symbol = '?f@A@RBX@@QAEHXZ'
    calls = []
    obj = tmp_path/'baseline.obj';obj.write_bytes(b'baseline')
    def model(*args, **kwargs):
        calls.append('model')
        return None, [dict(mode='model-request',target_addresses=['a'])]
    def run(rel, text, targets, *args, **kwargs):
        assert calls == ['model'] and targets == {'a':symbol}
        assert kwargs['rounds'] == 2 and kwargs['limit'] == 24
        calls.append('repair')
        return None, [dict(mode='repair-coverage',target_addresses=['a'])]
    monkeypatch.setattr(sweep,'model_proposal',model)
    monkeypatch.setattr(repair,'run',run)
    proposals, records = sweep.model_discovery(dict(llm='codex:default'),
        {'App/A.cpp':'int A::f(){return 0;}'},{'a'},set(),{'a':dict(unit='RBX::A',size=5)},
        SimpleNamespace(scan=lambda _:[]),tmp_path,1,lambda _:None,
        lambda *args:dict(ok=True,object=str(obj)),{'a':dict(symbol=symbol,score=90)})
    assert calls == ['model','repair'] and not proposals
    assert any(r.get('mode')=='repair-coverage' for r in records)


def test_auto_generation_accepts_verified_full_method_fallback(tmp_path, monkeypatch):
    from roc import providers
    replies = iter(['int A::f(){return 1;}', 'int A::f(){return 2;}'])
    monkeypatch.setattr(providers,'generate',lambda *args:SimpleNamespace(text='```cpp\n'+next(replies)+'\n```'))
    obj = tmp_path/'body.obj';obj.write_bytes(b'none')
    _, records = sweep.model_proposal('App/A.cpp','int A::f(){return 0;}',['a'],set(),set(),'codex:default',2,
        lambda *args:dict(ok=True,object=str(obj)),SimpleNamespace(scan=lambda _:[]),
        lambda _:dict(addr='a',rebuilt_symbol='?f@A@RBX@@QAEHXZ'),lambda _:None,options=dict(generation='auto'))
    assert [r['generation'] for r in records if r.get('comparison_complete')] == ['method','method-fallback']


def test_constructor_initializers_balanced_without_claiming_overloads_or_declarations():
    source = 'A::A() : Base<Thing>(nested(1,2)), value("{ignored}") { RBXASSERT(ok); }\nvoid A::next() {}'
    spans = sweep.methods(source)
    assert set(spans) == {'A::A','A::next'}
    assert source[slice(*spans['A::A'])].endswith('{ RBXASSERT(ok); }')
    assert any(mode.startswith('scoped-fp:') for mode,_,_ in repair.variants(source,'A::A'))
    assert 'A::A' not in sweep.methods(source+'\nA::A(int n) : value(n) {}')
    assert not sweep.methods('A::A() : bad;\nvoid B::other() {}').get('A::A')
