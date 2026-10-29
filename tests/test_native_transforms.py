from types import SimpleNamespace
import json

import pytest

from roc import native_transforms as transforms, native_search, native_sweep, match, setup


def test_map_types_come_from_declared_map_not_guessed_pair():
    source = 'void A::f(){ map.insert(std::pair<int, float>(n, value)); }'
    assert not list(transforms.method_variants(source, modes=['map-value-type']))
    rows = list(transforms.method_variants(source, context='std::map<int, float> map;', modes=['map-value-type']))
    assert len(rows) == 2
    assert any('pair<const int, float>' in candidate for _, candidate, _ in rows)
    assert any('rocMapEntry' in candidate for _, candidate, _ in rows)
    for _, candidate, edits in rows:
        assert native_sweep.apply_edits(source, edits) == candidate
    assert not list(transforms.method_variants(source, context='std::map<long, float> map;', modes=['map-value-type']))


def test_temporary_and_scope_trials_ignore_comments_strings_and_references():
    source = 'void A::f(){ Vec t = a*b; consume(t); after(); const char* s = "return a*b*c;"; }'
    rows = list(transforms.method_variants(source))
    assert any(mode.startswith('temporary-inline') and 'consume((a*b))' in candidate for mode, candidate, _ in rows)
    assert any(mode.startswith('scope-lifetime') and '{ Vec t' in candidate for mode, candidate, _ in rows)
    assert all('"return a*b*c;"' in candidate for _, candidate, _ in rows)
    escaped = 'void A::f(){ Vec t = a*b; consume(&t); after(); }'
    assert not list(transforms.method_variants(escaped, modes=['temporary-inline']))


def test_grouping_and_named_return_use_real_declared_type_only():
    source = 'G3D::Vector3 A::f(){ return a*b*c; }'
    rows = list(transforms.method_variants(source, modes=['expression-grouping', 'temporary-name']))
    assert len(rows) == 3
    assert any('G3D::Vector3 rocExpression' in candidate for _, candidate, _ in rows)
    assert any('(a * b) * c' in candidate for _, candidate, _ in rows)
    assert any('a * (b * c)' in candidate for _, candidate, _ in rows)


def test_immediate_trials_require_unique_source_literal():
    rows = {'addr': dict(symbol='?f@A@RBX@@', immediates=[dict(value=25, compiled_value=24)])}
    source = 'int A::f(){ return 24; }'
    assert 'return 25' in list(transforms.immediate_variants(source, rows))[0][1]
    assert not list(transforms.immediate_variants('int A::f(){ return 24+24; }', rows))


def test_real_call_and_template_trials_require_target_and_evidence():
    source = 'int A::f(){return realHelper();}'
    fact = dict(file='App/A.cpp', kind='visible-callee', target='00500000', evidence='callee source receipt',
                edits=[['return realHelper();', 'return realHelper()+0;']])
    assert list(transforms.proven_variants(source, [fact], 'App/A.cpp'))
    assert not list(transforms.proven_variants(source, [dict(fact, evidence='')], 'App/A.cpp'))


def test_sibling_discovery_renames_identifiers_but_preserves_literals_and_keywords():
    original = 'A::f(){return value+3;}'
    winner = dict(file='App/A.cpp', edits=[[original, original.replace('+3', '+4')]])
    texts = {'App/A.cpp': original, 'App/B.cpp': 'B::g(){return amount+3;}', 'App/C.cpp': 'C::g(){return amount+7;}'}
    rows = list(transforms.sibling_variants(texts, winner, original))
    assert len(rows) == 1 and rows[0][0] == 'App/B.cpp'
    assert 'return amount+4' in rows[0][2]


@pytest.mark.skipif(21022 not in setup.compilers(), reason='historical compiler unavailable')
def test_generated_cpp_trials_compile_under_real_msvc():
    source = '''#include <map>
namespace RBX {
std::map<int,float> map;
class A { public: float f(); };
float A::f(){ float t = 1.0f*2.0f; map.insert(std::pair<int,float>(1,t)); return t; }
}'''
    rows = list(transforms.method_variants(source))
    assert rows
    for _, candidate, _ in rows:
        assert match.compile_text('2008-06', candidate, flags='/O2 /GS- /EHsc /MD', build=21022)


def test_missing_native_profile_reports_each_client_without_reusing_2008_inputs(tmp_path, monkeypatch):
    monkeypatch.setattr(native_sweep, 'ROOT', tmp_path)
    result = native_search.client_profile({}, '2012-06', tmp_path/'out', 4, 2, lambda _: None)
    assert result['blocker'] == 'missing-native-profile'
    assert result['client'] == '2012-06' and result['new_verified'] == 0
    assert all('2012-06' in path for path in result['missing'])


def test_automatic_model_prepass_fixes_proven_immediate_without_a_model_request(tmp_path, monkeypatch):
    from roc import providers
    symbol = '?f@A@RBX@@QAEHXZ'
    monkeypatch.setattr(providers, 'generate', lambda *args: pytest.fail('Free exact must not call model'))
    monkeypatch.setattr(native_sweep, 'ownership_candidates', lambda data, hits: {h['addr']: [h['addr']] for h in hits})
    monkeypatch.setattr(native_search, 'diagnose', lambda data, symbols: {'a': dict(score=80,
        frame_ok=True, calls_ok=True, data_exact=b'25' in data, symbol=symbol, blocker='wrong-immediate',
        recipes=['target-immediate'], immediates=[dict(value=25,compiled_value=24)])})
    def compile(source, rel, label):
        obj = tmp_path/(native_sweep.integration.digest([source,label])+'.obj')
        obj.write_text(source)
        return dict(file=rel, mode=label, ok=True, object=str(obj), error=None)
    matcher = SimpleNamespace(scan=lambda data: [dict(addr='a', symbol=symbol)] if b'25' in data else [])
    proposals, _ = native_sweep.model_discovery(dict(llm='codex:default', automatic_prepass=True,
        keep_partials=True, transform_modes=[], scoped_modes=[]), {'App/A.cpp':'int A::f(){return 24;}'},
        {'a'}, set(), {'a':dict(unit='RBX::A')}, matcher, tmp_path, 1, lambda _:None, compile,
        {'a':dict(symbol=symbol,score=80)})
    assert proposals and proposals[0]['witnesses'][0]['addr'] == 'a'


def test_exact_visible_callee_is_discovered_from_actual_call_and_available_native_source(monkeypatch):
    texts={'App/A.cpp':'int A::f(){return B::helper();}', 'App/B.cpp':'int B::helper(){return 2;}'}
    names={'a':dict(symbol='?f@A@RBX@@',score=70), '00500010':dict(symbol='?helper@B@RBX@@',score=100)}
    monkeypatch.setattr(match,'target',lambda *args:(b'body',[],None))
    monkeypatch.setattr(match,'disasm',lambda *args:['call 0x500010'])
    rows=transforms.callee_facts(texts,{'App/A.cpp':['a']},names,{'00500010':dict(unit='RBX::B')})
    assert len(rows)==1 and 'inline int B::helper' in rows[0]['edits'][0][1]
    names['00500010']['score']=99
    assert not transforms.callee_facts(texts,{'App/A.cpp':['a']},names,{'00500010':dict(unit='RBX::B')})


def test_template_emission_requires_real_factory_signature():
    source='namespace RBX { void A::f(){p->ServiceProvider::create<RunService>();} }'
    context='class ServiceProvider { template<class T> T* create() const; };'
    rows=list(transforms.template_variants(source,context))
    assert len(rows)==1 and 'RunService* ServiceProvider::create<RunService>() const;' in rows[0][1]
    assert not list(transforms.template_variants(source,context.replace('T* create()', 'int create(int x)')))
