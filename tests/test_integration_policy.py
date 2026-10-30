import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import integration, integration_context, integration_policy as policy, native_adapt


def test_retry_budget_survives_restart_and_reopens_changed_inputs(tmp_path):
    path = tmp_path/'budget.json'
    request = dict(mode='model-request', response_received=True, model='small', target_addresses=['a'])
    for _ in range(3):
        budget = policy.AttemptBudget(path, 'headers/compiler/source-v1')
        budget.record([request])
    assert policy.AttemptBudget(path, 'headers/compiler/source-v1').blocked('a')
    assert not policy.AttemptBudget(path, 'headers/compiler/source-v2').blocked('a')
    assert not policy.AttemptBudget(path, 'headers/compiler/source-v1').blocked('unattempted')


def test_provider_failure_is_not_a_source_approach_and_improvement_reopens(tmp_path):
    budget = policy.AttemptBudget(tmp_path/'budget.json', 'same', limit=1)
    budget.record([dict(mode='model-request', target_addresses=['a'])])
    assert not budget.blocked('a')
    budget.record([dict(mode='batch-request', response_received=True, target_addresses=['a'])])
    assert budget.blocked('a')
    budget.targets['a']['best_score'] = 90
    budget.record([dict(ok=True, diagnostics={'a': dict(score=92)}, losses=[])])
    assert not budget.blocked('a')
    budget.record([], exact=['a'])
    assert 'a' not in budget.targets


def test_only_explicit_stronger_model_is_routed():
    assert policy.model_for_attempt('small', {}, 99) == 'small'
    options = dict(escalation_model='strong', escalate_after=2)
    assert [policy.model_for_attempt('small', options, n) for n in range(3)] == ['small', 'small', 'strong']
    with pytest.raises(ValueError):
        policy.model_for_attempt('small', dict(escalate_after=0), 0)


def test_measured_ranking_uses_finalized_jobs_only():
    jobs = [dict(unit='RBX::A', state='rejected', receipt=dict(verification_seconds=40)),
            dict(unit='RBX::B', state='accepted', receipt=dict(verification_seconds=5, credits=2)),
            dict(unit='RBX::A', state='queued', receipt=dict(credits=999))]
    history = policy.learned(jobs)
    rows = [dict(addr='a', size=30)]
    rank = lambda unit: integration_context.rank(rows, {}, ['native.h'], {}, history=history[unit])
    assert rank('RBX::B') < rank('RBX::A')
    assert history['RBX::B']['credits'] == 2 and history['RBX::A']['credits'] == 0


def test_usage_is_measured_and_missing_usage_remains_unknown():
    record = dict(mode='model-request', **policy.usage(SimpleNamespace(input_tokens=10, output_tokens=4, latency_s=2), 'small'))
    report = policy.local_metrics([record, dict(mode='batch-request', model='strong')])
    assert report['reported_tokens'] == 14 and not report['token_reporting_complete']
    assert report['model_usage']['strong']['responses_with_usage'] == 0
    assert report['compile_success_rate'] is None and not report['local_results_grant_credit']


def test_adapter_transplants_only_body_with_original_declaration():
    native = 'namespace RBX {\nint A::f(int x) { return x; }\nint A::keep(){return 7;}\n}'
    mined = 'namespace RBX { int A::f(int x) { return x + 1; } }'
    from roc.native_sweep import apply_edits
    edits = native_adapt.adapt(mined, native, 'A::f')
    assert apply_edits(native, edits) == native.replace('return x;', 'return x + 1;')


@pytest.mark.parametrize('mined,reason', [
    ('struct Padding {}; int A::f(){Padding p; return 1;}', 'Synthetic'),
    ('int A::f(){return *((char*)this+20);}', 'Raw offset'),
    ('int A::f(int x){return x;}', 'signature'),
    ('int A::f(){return 1;} int A::f(int x){return x;}', 'ambiguous')])
def test_adapter_rejects_unproven_adaptations(mined, reason):
    with pytest.raises(ValueError, match=reason):
        native_adapt.adapt(mined, 'int A::f(){return 0;}', 'A::f')


def test_qualified_native_types_ignore_comments_and_support_msvc_exports():
    text = 'namespace G3D { /* class Fake {}; */ class __declspec(novtable) A { struct Inner {}; }; }'
    names = native_adapt.declared_types(text)
    assert set(names) == {'G3D::A', 'G3D::A::Inner'}
    paths = {'G3D::A': {'Rendering/g3d/include/A.h'}}
    assert not native_adapt.eligible('G3D::A', 'a', {}, paths)
    assert native_adapt.eligible('G3D::A', 'a', {'a': dict(symbol='?f@A@G3D@@QAEHXZ')}, paths)
    assert not native_adapt.eligible('Ogre::A', 'a', {'a': dict(symbol='?f@A@G3D@@QAEHXZ')}, paths)


def test_ogre_dll_replay_does_not_become_native_source_layer(tmp_path):
    module = tmp_path/'rebuild/2008-06/modules/ogre.json'
    integration.atomic_json(module, dict(layers=[], verified=True))
    row = native_adapt.namespace_capabilities(tmp_path)['Ogre']
    assert row['standalone_module_native_layers'] == 0
    assert 'not a native source layer' in row['standalone_module_reason']



def test_foreign_class_reservation_skips_models_before_generation(tmp_path,monkeypatch):
    from roc import native_sweep, providers
    text='int A::f(){return 1;}'
    def compile(source,rel,label):
        obj=tmp_path/'baseline.obj';obj.write_bytes(b'fixture')
        return dict(ok=True,object=str(obj),error=None)
    monkeypatch.setattr(providers,'generate',lambda *a:pytest.fail('Foreign class must not spend model requests'))
    names={'00500000':dict(symbol='?f@A@RBX@@QAEHXZ',score=90)}
    proposals,records=native_sweep.model_discovery(
        dict(llm='small',rounds=3,reserve_file=lambda rel,addrs:False),
        {'App/A.cpp':text},set(names),set(),{'00500000':dict(unit='RBX::A',size=30)},
        SimpleNamespace(scan=lambda obj:[]),tmp_path,1,lambda *a:None,compile,names)
    assert not proposals and records[0]['blocker']=='class-lease-unavailable'


def test_new_cpp_keywords_do_not_enter_historical_adapter():
    with pytest.raises(ValueError,match='Historical'):
        native_adapt.adapt('int A::f(){constexpr int x=1;return x;}', 'int A::f(){return 0;}', 'A::f')


def test_submission_requires_advertised_authoritative_reference_gate():
    with pytest.raises(ValueError,match='restart'):
        integration.require_reference_gate(dict(features={}))
    integration.require_reference_gate(dict(features=dict(native_reference_gate=1)))
